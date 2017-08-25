<?php

/**
 * Implementation of hook_rules_action_info().
 */
function distributeurs_rules_action_info() {
    $items = array();

    $items['distributeurs_relationship_save_distributeur_relationship'] = array(
        'label' => t('Save distributeur relationship to profile'),
        'group' => t('Distributeurs'),
        'parameter' => array(
            'user' => array(
                'type' => 'user',
                'label' => t('User that is logged in.'),
            ),
            'overwrite' => array(
                'type' => 'boolean',
                'label' => t('Overwrite Distributeur Relationship'),
                'description' => t('If checked, any existing value will be overwritten with this distributeur.'),
                'default value' => FALSE,
            ),
        ),
    );
    $items['distributeurs_commission_distributeur'] = array(
        'label' => t('Commission Speciale Distributeur'),
        'group' => t('Distributeurs'),
        'parameter' => array(
            'entity' => array(
                'type' => 'entity',
                'label' => t('Entity to update'),
                'wrapped' => FALSE,

            ),
            'commission_type' => array(
                'type' => 'text',
                'label' => t('Commission type'),
                'options list' => 'distributeurs_commission_types_options_list',
            ),
            'percentage' => array(
                'type' => 'decimal',
                'label' => t('Pourcentage'),
                'description' => 'Montant du Pourcentage',
            ),
            'user' => array(
                'type' => 'user',
                'label' => t('Distributeur account'),
            ),
        ),
    );
    $items['distributeurs_remise_bon_achat'] = array(
        'label' => t('Utiliser le compte Distributeur comme un bon d\'achat.'),
        'group' => t('Distributeurs'),
        'parameter' => array(
            'entity' => array(
                'label' => t('Entity'),
                'type' => 'entity',
                'wrapped' => TRUE,
            ),
            'commerce_discount' => array(
                'label' => t('Distributeur Discount'),
                'type' => 'token',
                'options list' => 'commerce_discount_entity_list',
            ),
        ),
    );
    $items['distributeurs_bon_achat_used'] = array(
        'label' => t('Prélever le montant de la Remise Bon achat dans le compte Distributeur'),
        'group' => t('Distributeurs'),
        'parameter' => array(
            'entity' => array(
                'label' => t('Order'),
                'type' => 'entity',
                'wrapped' => FALSE,
            ),
            'user' => array(
                'type' => 'user',
                'label' => t('Distributeur account'),
            ),
        ),
    );


    return $items;
}

/**
 * save distributeur relationship from the field code ambassadeur or code vendeur
 */
function distributeurs_relationship_save_distributeur_relationship($user, $overwrite = FALSE){
    $ambassadeur = $user->field_code_ambassadeur['und'][0];
    $vendeur = taxonomy_term_load($user->field_code_vendeur['und'][0]['target_id']);

    //dpm($vendeur);
    if (!empty($vendeur)) {
        $relationship = $vendeur->name;
    }
    else {
        $relationship = $ambassadeur;
    }


    //Faire une recherche pour trouver le distributeur ID en fonction du code ambassadeur ou vendeur .
    // Et obtenir le uid en retour
    $query = db_select('field_data_field_distributeur_id', 'u')
        ->condition('u.field_distributeur_id_value', $relationship)
        ->fields('u', array('entity_id'));
    $result = $query->execute()->fetchAssoc();

    //dpm($result);
    if($result) {
        if ($overwrite) {
            $user->field_distributeur_reference['und'][0]['target_id'] = $result;
            //dpm($user);
            user_save($user);
        }
        elseif (empty($user->field_distributeur_reference['und'][0]['target_id'])) {
            $user->field_distributeur_reference['und'][0]['target_id'] = $result;
            //dpm($user);
            user_save($user);
        }
    }
    else {
        drupal_set_message(t('Le code ambassadeur renseigné ne correspond à aucun distributeur enregistré. Veuillez prendre contact avec votre praticien référent pour obtenir un code ambassadeur valide.'), 'warning');
    }

}

function distributeurs_commission_distributeur($order, $commission_type, $percentage, $user) {
    /************AJOUT COMMISSION CUSTOMISE ******/
    $commission_info = commerce_affiliate_commission_type_load($commission_type);
    $currency_code = commerce_default_currency();

    $components = $order->commerce_order_total['und'][0]['data']['components'];
    $amount = 0;
    foreach ($components as $key => $component) {
        if($component['name'] == 'base_price'){
            $amount += $component['price']['amount'];
        }
        if (preg_match('/expedition/i', $component['name'])){
            $amount -= $component['price']['amount'];
        }

    }
    $amount = $amount * $percentage /100;

    $values = array(
        'type' => $commission_type,
        'parent_entity_type' => $order->type,
        'parent_entity_id' => $order->order_id,
        'affiliate_uid' => $user->uid,
        'campaign_id' => 1,
    );

    $commission = entity_create('commerce_affiliate_commission', $values);
    $langcode = field_language('commerce_affiliate_commission', $commission, 'commerce_affiliate_amount');

    $commission_wrapper = entity_metadata_wrapper('commerce_affiliate_commission', $commission);
    $commission_wrapper->commerce_affiliate_amount->amount = $amount;
    $commission_wrapper->commerce_affiliate_amount->currency_code = $currency_code;
    entity_save('commerce_affiliate_commission', $commission);

    /************AJOUT MONTANT COMMISSION DANS COMPTE DISTRIBUTEUR ******/
    if(isset($commission->commerce_affiliate_amount['und'][0]['amount'])){
        $amount_com = $commission->commerce_affiliate_amount['und'][0]['amount'];
    }
    else {
        $amount_com = 0;
    }
    if(isset($user->field_bon_achat_distributeur['und'][0]['amount'])){
        $bon_achat = $user->field_bon_achat_distributeur['und'][0]['amount'];
    }
    else {
        $bon_achat = 0;
    }


    $user->field_bon_achat_distributeur['und'][0]['amount'] = $bon_achat + $amount_com;
    if(!isset($user->field_bon_achat_distributeur['und'][0]['currency_code'])){
        $user->field_bon_achat_distributeur['und'][0]['currency_code'] = 'EUR';
    }
    user_save($user);
}


function distributeurs_remise_bon_achat(EntityDrupalWrapper $wrapper, $discount_name){
    // Set reference to the discount.
    // @todo: It doesn't work with the wrapper. // Euh si ca marche.
    $order = $wrapper->value();
    /*
    dpm('TEST INSIDE ACTION RULES REMISE DISTRIBUTEUR');
    dpm($wrapper->type());
    dpm($wrapper->getBundle());
    dpm($discount_name);
    dpm($order);
*/
    $user = user_load($order->uid);
    if (isset($user->field_bon_achat_distributeur['und'][0]['amount'])) {
        $bon_achat = $user->field_bon_achat_distributeur['und'][0]['amount'];
    } else {
        $bon_achat = 0;
    }

    $discount_wrapper = entity_metadata_wrapper('commerce_discount', $discount_name);
   /*
    dpm($discount_wrapper);
    dpm($discount_wrapper->commerce_discount_offer->distributeurs_remise_bon_achat->value());

    $discount_price = $discount_wrapper->commerce_discount_offer->distributeurs_remise_bon_achat->value();
    dpm('test after $discount_wrapper ? ');
*/
    $discount_price['amount'] = $bon_achat;
    $discount_price['amount'] = -$discount_price['amount'];
    $discount_price['currency_code'] = 'EUR';
    //dpm($discount_price);

    // Exit if the wrapper doesn't have a commerce_discounts property.
    if (!isset($wrapper->commerce_discounts)) {
        drupal_set_message('marche pas!');
        return;
    }


    // If the discount will bring the order to less than zero, set the
    // discount amount so that it stops at zero.
    $order_amount = $wrapper->commerce_order_total->amount->value();
    if (-$discount_price['amount'] > $order_amount) {
        $discount_price['amount'] = -$order_amount;
    }

    $delta = $wrapper->commerce_discounts->count();
    // dpm($delta);
    // dpm($discount_wrapper->discount_id->value());
    // dpm($order);
    $order->commerce_discounts[LANGUAGE_NONE][$delta]['target_id'] = $discount_wrapper->discount_id->value();


    // Modify the existing discount line item or add a new one if that fails.
    if (!commerce_discount_set_existing_line_item_price($wrapper, $discount_name, $discount_price)) {
        commerce_discount_add_line_item($wrapper, $discount_name, $discount_price);
    }

    // Update the total order price, for the next rules condition (if any).
    commerce_order_calculate_total($order);

    //dpm($order);
    //dpm('FIN avec order complet');
}

function distributeurs_bon_achat_used($order, $user) {
    dpm('RULES distributeurs_bon_achat_used');
    dpm($order);
    dpm($user);
    $components = $order->commerce_order_total['und'][0]['data']['components'];
    foreach ($components as $key => $component) {
        if($component['name'] =='discount_remise_distributeurs_bon_achat') {
            $discount = $component;
        }
    }
    if(!isset($discount)){
        drupal_set_message('La remise distributeurs_bon_achat n\'a pas été trouvée.','warning');
        return;
    }
    dpm($discount);
    // Normalement le montant de la remise ne peut être supérieur au montant du champ du compte distributeur
    // Mais on va quand même s'en assurer.
    $distributeur_account = $user->field_bon_achat_distributeur['und'][0]['amount'];
    if (-$discount['price']['amount'] > $distributeur_account) {
        $discount['price']['amount'] = -$distributeur_account;
    }

    $user->field_bon_achat_distributeur['und'][0]['amount'] =
        $user->field_bon_achat_distributeur['und'][0]['amount'] + $discount['price']['amount'];
    if(!isset($user->field_bon_achat_distributeur['und'][0]['currency_code'])){
        $user->field_bon_achat_distributeur['und'][0]['currency_code'] = 'EUR';
    }
    user_save($user);
    dpm($user);
}

function distributeurs_commission_types_options_list() {
    $commission_types = commerce_affiliate_commission_types();
    $options_list = array();
    if ($commission_types) {
        foreach ($commission_types as $commission_type => $value) {
            $options_list[$commission_type] = $value['name'];
        }
    }

    return $options_list;
}
