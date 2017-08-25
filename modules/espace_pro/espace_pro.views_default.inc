<?php

/**
* Implements hook_views_default_views().
*/
function espace_professionnel_views_default_views()
{

    $views = array();

    $view_commission = view_commission();
    $view_espace_pro_clients = view_espace_pro_clients();
    $view_espace_pro_ventes = view_espace_pro_ventes();
    $view_distributeur_bon_achat = view_distributeur_bon_achat();

    $views[$view_commission->name] = $view_commission;
    $views[$view_espace_pro_clients->name] = $view_espace_pro_clients;
    $views[$view_espace_pro_ventes->name] = $view_espace_pro_ventes;
    $views[$view_distributeur_bon_achat->name] = $view_distributeur_bon_achat;

    return $views;
}

function view_commission(){
    $view = new view();
    $view->name = 'espaces_pro_commissions';
    $view->description = '';
    $view->tag = 'default';
    $view->base_table = 'commerce_affiliate_commission';
    $view->human_name = 'Commissions View';
    $view->core = 7;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

    /* Display: Master */
    $handler = $view->new_display('default', 'Master', 'default');
    $handler->display->display_options['title'] = 'Commissions Admin';
    $handler->display->display_options['use_more_always'] = FALSE;
    $handler->display->display_options['use_more_text'] = 'plus';
    $handler->display->display_options['group_by'] = TRUE;
    $handler->display->display_options['access']['type'] = 'perm';
    $handler->display->display_options['access']['perm'] = 'access espace professionnel';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
    $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
    $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
    $handler->display->display_options['pager']['type'] = 'none';
    $handler->display->display_options['pager']['options']['offset'] = '0';
    $handler->display->display_options['style_plugin'] = 'table';
    /* Relation: Affiliate Commission : Affiliate affiliate_uid */
    $handler->display->display_options['relationships']['affiliate']['id'] = 'affiliate';
    $handler->display->display_options['relationships']['affiliate']['table'] = 'commerce_affiliate_commission';
    $handler->display->display_options['relationships']['affiliate']['field'] = 'affiliate';
    $handler->display->display_options['relationships']['affiliate']['label'] = 'Utilisateur Distributeur';
    /* Champ: COUNT(Affiliate Commission : Commission ID) */
    $handler->display->display_options['fields']['commission_id']['id'] = 'commission_id';
    $handler->display->display_options['fields']['commission_id']['table'] = 'commerce_affiliate_commission';
    $handler->display->display_options['fields']['commission_id']['field'] = 'commission_id';
    $handler->display->display_options['fields']['commission_id']['group_type'] = 'count';
    /* Champ: Affiliate Commission : Date de création */
    $handler->display->display_options['fields']['created']['id'] = 'created';
    $handler->display->display_options['fields']['created']['table'] = 'commerce_affiliate_commission';
    $handler->display->display_options['fields']['created']['field'] = 'created';
    $handler->display->display_options['fields']['created']['date_format'] = 'long';
    $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
    $handler->display->display_options['fields']['created']['format_date_sql'] = 1;
    /* Champ: SUM(Affiliate Commission : Montant) */
    $handler->display->display_options['fields']['commerce_affiliate_amount']['id'] = 'commerce_affiliate_amount';
    $handler->display->display_options['fields']['commerce_affiliate_amount']['table'] = 'field_data_commerce_affiliate_amount';
    $handler->display->display_options['fields']['commerce_affiliate_amount']['field'] = 'commerce_affiliate_amount';
    $handler->display->display_options['fields']['commerce_affiliate_amount']['group_type'] = 'sum';
    $handler->display->display_options['fields']['commerce_affiliate_amount']['click_sort_column'] = 'amount';
    $handler->display->display_options['fields']['commerce_affiliate_amount']['settings'] = array(
        'calculation' => FALSE,
    );
    $handler->display->display_options['fields']['commerce_affiliate_amount']['group_column'] = 'amount';
    $handler->display->display_options['fields']['commerce_affiliate_amount']['group_columns'] = array(
        'currency_code' => 'currency_code',
    );
    /* Champ: Affiliate Commission : Affiliate affiliate_uid */
    $handler->display->display_options['fields']['affiliate_1']['id'] = 'affiliate_1';
    $handler->display->display_options['fields']['affiliate_1']['table'] = 'commerce_affiliate_commission';
    $handler->display->display_options['fields']['affiliate_1']['field'] = 'affiliate';
    $handler->display->display_options['fields']['affiliate_1']['label'] = 'Distributeur ID';
    $handler->display->display_options['fields']['affiliate_1']['separator'] = '';
    /* Champ: Affiliate Commission : Parent entity id */
    $handler->display->display_options['fields']['parent_entity_id']['id'] = 'parent_entity_id';
    $handler->display->display_options['fields']['parent_entity_id']['table'] = 'commerce_affiliate_commission';
    $handler->display->display_options['fields']['parent_entity_id']['field'] = 'parent_entity_id';
    $handler->display->display_options['fields']['parent_entity_id']['label'] = 'Numéro de Commande';
    $handler->display->display_options['fields']['parent_entity_id']['separator'] = '';
    /* Champ: Affiliate Commission : Affiliate affiliate_uid */
    $handler->display->display_options['fields']['affiliate']['id'] = 'affiliate';
    $handler->display->display_options['fields']['affiliate']['table'] = 'commerce_affiliate_commission';
    $handler->display->display_options['fields']['affiliate']['field'] = 'affiliate';
    $handler->display->display_options['fields']['affiliate']['label'] = 'Commission UID';
    $handler->display->display_options['fields']['affiliate']['exclude'] = TRUE;
    $handler->display->display_options['fields']['affiliate']['separator'] = '';
    /* Filtre contextuel: Affiliate Commission : Affiliate affiliate_uid */
    $handler->display->display_options['arguments']['affiliate']['id'] = 'affiliate';
    $handler->display->display_options['arguments']['affiliate']['table'] = 'commerce_affiliate_commission';
    $handler->display->display_options['arguments']['affiliate']['field'] = 'affiliate';
    $handler->display->display_options['arguments']['affiliate']['default_action'] = 'default';
    $handler->display->display_options['arguments']['affiliate']['exception']['title'] = 'Tout';
    $handler->display->display_options['arguments']['affiliate']['default_argument_type'] = 'current_user';
    $handler->display->display_options['arguments']['affiliate']['summary']['number_of_records'] = '0';
    $handler->display->display_options['arguments']['affiliate']['summary']['format'] = 'default_summary';
    $handler->display->display_options['arguments']['affiliate']['summary_options']['items_per_page'] = '25';
    /* Critère de filtrage: Affiliate Commission : Date de création */
    $handler->display->display_options['filters']['created']['id'] = 'created';
    $handler->display->display_options['filters']['created']['table'] = 'commerce_affiliate_commission';
    $handler->display->display_options['filters']['created']['field'] = 'created';
    $handler->display->display_options['filters']['created']['exposed'] = TRUE;
    $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
    $handler->display->display_options['filters']['created']['expose']['label'] = 'Date de création';
    $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
    $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
    $handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
        2 => '2',
        1 => 0,
        3 => 0,
        4 => 0,
        5 => 0,
    );

    /* Display: Commissions Admin */
    $handler = $view->new_display('page', 'Commissions Admin', 'page');
    $handler->display->display_options['display_description'] = 'Liste de toutes les commissions pour la gestion admin';
    $handler->display->display_options['defaults']['group_by'] = FALSE;
    $handler->display->display_options['defaults']['access'] = FALSE;
    $handler->display->display_options['access']['type'] = 'role';
    $handler->display->display_options['access']['role'] = array(
        3 => '3',
    );
    $handler->display->display_options['defaults']['style_plugin'] = FALSE;
    $handler->display->display_options['style_plugin'] = 'table';
    $handler->display->display_options['style_options']['columns'] = array(
        'commission_id' => 'commission_id',
        'created' => 'created',
        'commerce_affiliate_amount' => 'commerce_affiliate_amount',
        'affiliate_1' => 'affiliate_1',
        'field_nom' => 'field_nom',
        'field_prenom' => 'field_prenom',
        'parent_entity_id' => 'parent_entity_id',
        'affiliate' => 'affiliate',
    );
    $handler->display->display_options['style_options']['default'] = 'created';
    $handler->display->display_options['style_options']['info'] = array(
        'commission_id' => array(
            'sortable' => 0,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'created' => array(
            'sortable' => 1,
            'default_sort_order' => 'desc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'commerce_affiliate_amount' => array(
            'sortable' => 1,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'affiliate_1' => array(
            'sortable' => 1,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'field_nom' => array(
            'sortable' => 0,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'field_prenom' => array(
            'sortable' => 0,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'parent_entity_id' => array(
            'sortable' => 1,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'affiliate' => array(
            'sortable' => 0,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
    );
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['defaults']['row_plugin'] = FALSE;
    $handler->display->display_options['defaults']['row_options'] = FALSE;
    $handler->display->display_options['defaults']['arguments'] = FALSE;
    $handler->display->display_options['path'] = 'admin/commerce/reports/commissions';
    $handler->display->display_options['menu']['type'] = 'normal';
    $handler->display->display_options['menu']['title'] = 'Commissions';
    $handler->display->display_options['menu']['weight'] = '10';
    $handler->display->display_options['menu']['name'] = 'management';
    $handler->display->display_options['menu']['context'] = 0;
    $handler->display->display_options['menu']['context_only_inline'] = 0;

    /* Display: Commissions espace pro */
    $handler = $view->new_display('page', 'Commissions espace pro', 'page_1');
    $handler->display->display_options['defaults']['title'] = FALSE;
    $handler->display->display_options['title'] = 'Vos Commissions';
    $handler->display->display_options['defaults']['fields'] = FALSE;
    /* Champ: Affiliate Commission : Date de création */
    $handler->display->display_options['fields']['created']['id'] = 'created';
    $handler->display->display_options['fields']['created']['table'] = 'commerce_affiliate_commission';
    $handler->display->display_options['fields']['created']['field'] = 'created';
    $handler->display->display_options['fields']['created']['date_format'] = 'custom';
    $handler->display->display_options['fields']['created']['custom_date_format'] = 'F Y';
    $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
    $handler->display->display_options['fields']['created']['format_date_sql'] = 1;
    /* Champ: COUNT(Affiliate Commission : Commission ID) */
    $handler->display->display_options['fields']['commission_id']['id'] = 'commission_id';
    $handler->display->display_options['fields']['commission_id']['table'] = 'commerce_affiliate_commission';
    $handler->display->display_options['fields']['commission_id']['field'] = 'commission_id';
    $handler->display->display_options['fields']['commission_id']['group_type'] = 'count';
    $handler->display->display_options['fields']['commission_id']['label'] = 'Nombre de commissions';
    $handler->display->display_options['fields']['commission_id']['exclude'] = TRUE;
    /* Champ: SUM(Affiliate Commission : Montant) */
    $handler->display->display_options['fields']['commerce_affiliate_amount']['id'] = 'commerce_affiliate_amount';
    $handler->display->display_options['fields']['commerce_affiliate_amount']['table'] = 'field_data_commerce_affiliate_amount';
    $handler->display->display_options['fields']['commerce_affiliate_amount']['field'] = 'commerce_affiliate_amount';
    $handler->display->display_options['fields']['commerce_affiliate_amount']['group_type'] = 'sum';
    $handler->display->display_options['fields']['commerce_affiliate_amount']['click_sort_column'] = 'amount';
    $handler->display->display_options['fields']['commerce_affiliate_amount']['settings'] = array(
        'calculation' => FALSE,
    );
    $handler->display->display_options['fields']['commerce_affiliate_amount']['group_column'] = 'amount';
    $handler->display->display_options['fields']['commerce_affiliate_amount']['group_columns'] = array(
        'currency_code' => 'currency_code',
    );
    $handler->display->display_options['defaults']['filter_groups'] = FALSE;
    $handler->display->display_options['defaults']['filters'] = FALSE;
    $handler->display->display_options['path'] = 'espace-pro-commissions';
    $handler->display->display_options['menu']['title'] = 'Espace Professionnel Commissions';
    $handler->display->display_options['menu']['weight'] = '0';
    $handler->display->display_options['menu']['name'] = 'main-menu';
    $handler->display->display_options['menu']['context'] = 0;
    $handler->display->display_options['menu']['context_only_inline'] = 0;


    return $view;
}

function view_espace_pro_clients(){
    $view = new view();
    $view->name = 'espaces_pro_clients';
    $view->description = '';
    $view->tag = 'default';
    $view->base_table = 'users';
    $view->human_name = 'Espace pro Clients';
    $view->core = 7;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

    /* Display: Master */
    $handler = $view->new_display('default', 'Master', 'default');
    $handler->display->display_options['title'] = 'Vos Clients';
    $handler->display->display_options['use_more_always'] = FALSE;
    $handler->display->display_options['use_more_text'] = 'plus';
    $handler->display->display_options['group_by'] = TRUE;
    $handler->display->display_options['access']['type'] = 'perm';
    $handler->display->display_options['access']['perm'] = 'access espace professionnel';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
    $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
    $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
    $handler->display->display_options['pager']['type'] = 'none';
    $handler->display->display_options['style_plugin'] = 'table';
    /* Relation: Utilisateur : Commandes */
    $handler->display->display_options['relationships']['uid_commerce_orders']['id'] = 'uid_commerce_orders';
    $handler->display->display_options['relationships']['uid_commerce_orders']['table'] = 'users';
    $handler->display->display_options['relationships']['uid_commerce_orders']['field'] = 'uid_commerce_orders';
    $handler->display->display_options['relationships']['uid_commerce_orders']['label'] = 'Commandes';
    /* Relation: Entity Reference : Referenced Entity */
    $handler->display->display_options['relationships']['field_distributeur_reference_target_id']['id'] = 'field_distributeur_reference_target_id';
    $handler->display->display_options['relationships']['field_distributeur_reference_target_id']['table'] = 'field_data_field_distributeur_reference';
    $handler->display->display_options['relationships']['field_distributeur_reference_target_id']['field'] = 'field_distributeur_reference_target_id';
    /* Champ: Champ : Prénom */
    $handler->display->display_options['fields']['field_prenom']['id'] = 'field_prenom';
    $handler->display->display_options['fields']['field_prenom']['table'] = 'field_data_field_prenom';
    $handler->display->display_options['fields']['field_prenom']['field'] = 'field_prenom';
    /* Champ: Champ : Nom */
    $handler->display->display_options['fields']['field_nom']['id'] = 'field_nom';
    $handler->display->display_options['fields']['field_nom']['table'] = 'field_data_field_nom';
    $handler->display->display_options['fields']['field_nom']['field'] = 'field_nom';
    /* Champ: Utilisateur : Uid */
    $handler->display->display_options['fields']['uid']['id'] = 'uid';
    $handler->display->display_options['fields']['uid']['table'] = 'users';
    $handler->display->display_options['fields']['uid']['field'] = 'uid';
    $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
    /* Champ: Commande Drupal Commerce : Order total */
    $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
    $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
    $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
    $handler->display->display_options['fields']['commerce_order_total']['relationship'] = 'uid_commerce_orders';
    $handler->display->display_options['fields']['commerce_order_total']['label'] = 'Total des commandes';
    $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
    $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
        'calculation' => FALSE,
    );
    $handler->display->display_options['fields']['commerce_order_total']['group_column'] = 'entity_id';
    $handler->display->display_options['fields']['commerce_order_total']['group_columns'] = array(
        'amount' => 'amount',
    );
    /* Champ: COUNT(DISTINCT Commande Drupal Commerce : Identifiant (ID) de la commande) */
    $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
    $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
    $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
    $handler->display->display_options['fields']['order_id']['relationship'] = 'uid_commerce_orders';
    $handler->display->display_options['fields']['order_id']['group_type'] = 'count_distinct';
    $handler->display->display_options['fields']['order_id']['label'] = 'Nombre de commandes';
    $handler->display->display_options['fields']['order_id']['separator'] = '';
    /* Filtre contextuel: Utilisateur : Distributeur Reference (field_distributeur_reference) */
    $handler->display->display_options['arguments']['field_distributeur_reference_target_id']['id'] = 'field_distributeur_reference_target_id';
    $handler->display->display_options['arguments']['field_distributeur_reference_target_id']['table'] = 'field_data_field_distributeur_reference';
    $handler->display->display_options['arguments']['field_distributeur_reference_target_id']['field'] = 'field_distributeur_reference_target_id';
    $handler->display->display_options['arguments']['field_distributeur_reference_target_id']['default_action'] = 'default';
    $handler->display->display_options['arguments']['field_distributeur_reference_target_id']['exception']['title'] = 'Tout';
    $handler->display->display_options['arguments']['field_distributeur_reference_target_id']['default_argument_type'] = 'current_user';
    $handler->display->display_options['arguments']['field_distributeur_reference_target_id']['summary']['number_of_records'] = '0';
    $handler->display->display_options['arguments']['field_distributeur_reference_target_id']['summary']['format'] = 'default_summary';
    $handler->display->display_options['arguments']['field_distributeur_reference_target_id']['summary_options']['items_per_page'] = '25';
    /* Critère de filtrage: Utilisateur : Actif */
    $handler->display->display_options['filters']['status']['id'] = 'status';
    $handler->display->display_options['filters']['status']['table'] = 'users';
    $handler->display->display_options['filters']['status']['field'] = 'status';
    $handler->display->display_options['filters']['status']['value'] = '1';
    $handler->display->display_options['filters']['status']['group'] = 1;
    $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

    /* Display: Espace pro Clients */
    $handler = $view->new_display('page', 'Espace pro Clients', 'page');
    $handler->display->display_options['path'] = 'espace-pro-clients';

    return $view;
}

function view_espace_pro_ventes(){
    $view = new view();
    $view->name = 'espace_pro_ventes';
    $view->description = '';
    $view->tag = 'default';
    $view->base_table = 'commerce_order';
    $view->human_name = 'Espace pro Ventes';
    $view->core = 7;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

    /* Display: Master */
    $handler = $view->new_display('default', 'Master', 'default');
    $handler->display->display_options['title'] = 'Vos Ventes';
    $handler->display->display_options['use_more_always'] = FALSE;
    $handler->display->display_options['use_more_text'] = 'plus';
    $handler->display->display_options['group_by'] = TRUE;
    $handler->display->display_options['access']['type'] = 'perm';
    $handler->display->display_options['access']['perm'] = 'access espace professionnel';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['query']['options']['distinct'] = TRUE;
    $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
    $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
    $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
    $handler->display->display_options['pager']['type'] = 'none';
    $handler->display->display_options['style_plugin'] = 'table';
    /* Relation: Commande Drupal Commerce : Propriétaire */
    $handler->display->display_options['relationships']['uid']['id'] = 'uid';
    $handler->display->display_options['relationships']['uid']['table'] = 'commerce_order';
    $handler->display->display_options['relationships']['uid']['field'] = 'uid';
    /* Relation: Entity Reference : Referenced Entity */
    $handler->display->display_options['relationships']['field_distributeur_reference_target_id']['id'] = 'field_distributeur_reference_target_id';
    $handler->display->display_options['relationships']['field_distributeur_reference_target_id']['table'] = 'field_data_field_distributeur_reference';
    $handler->display->display_options['relationships']['field_distributeur_reference_target_id']['field'] = 'field_distributeur_reference_target_id';
    $handler->display->display_options['relationships']['field_distributeur_reference_target_id']['relationship'] = 'uid';
    $handler->display->display_options['relationships']['field_distributeur_reference_target_id']['label'] = 'Distributeur';
    /* Champ: Commande Drupal Commerce : Date de création */
    $handler->display->display_options['fields']['created']['id'] = 'created';
    $handler->display->display_options['fields']['created']['table'] = 'commerce_order';
    $handler->display->display_options['fields']['created']['field'] = 'created';
    $handler->display->display_options['fields']['created']['label'] = 'Date (par mois)';
    $handler->display->display_options['fields']['created']['date_format'] = 'custom';
    $handler->display->display_options['fields']['created']['custom_date_format'] = 'F Y';
    $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
    $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
    /* Champ: COUNT(Commande Drupal Commerce : Identifiant (ID) de la commande) */
    $handler->display->display_options['fields']['order_id_1']['id'] = 'order_id_1';
    $handler->display->display_options['fields']['order_id_1']['table'] = 'commerce_order';
    $handler->display->display_options['fields']['order_id_1']['field'] = 'order_id';
    $handler->display->display_options['fields']['order_id_1']['group_type'] = 'count';
    $handler->display->display_options['fields']['order_id_1']['label'] = 'Nombre de commandes';
    /* Champ: AVG(Commande Drupal Commerce : Order total) */
    $handler->display->display_options['fields']['commerce_order_total_1']['id'] = 'commerce_order_total_1';
    $handler->display->display_options['fields']['commerce_order_total_1']['table'] = 'field_data_commerce_order_total';
    $handler->display->display_options['fields']['commerce_order_total_1']['field'] = 'commerce_order_total';
    $handler->display->display_options['fields']['commerce_order_total_1']['group_type'] = 'avg';
    $handler->display->display_options['fields']['commerce_order_total_1']['label'] = 'Montant Moyen';
    $handler->display->display_options['fields']['commerce_order_total_1']['click_sort_column'] = 'amount';
    $handler->display->display_options['fields']['commerce_order_total_1']['settings'] = array(
        'calculation' => FALSE,
    );
    $handler->display->display_options['fields']['commerce_order_total_1']['group_column'] = 'amount';
    /* Champ: SUM(Commande Drupal Commerce : Order total) */
    $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
    $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
    $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
    $handler->display->display_options['fields']['commerce_order_total']['group_type'] = 'sum';
    $handler->display->display_options['fields']['commerce_order_total']['label'] = 'Montant Total';
    $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
    $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
        'calculation' => FALSE,
    );
    $handler->display->display_options['fields']['commerce_order_total']['group_column'] = 'amount';

    /* Display: Espace pro Ventes */
    $handler = $view->new_display('page', 'Espace pro Ventes', 'page');
    $handler->display->display_options['defaults']['arguments'] = FALSE;
    /* Filtre contextuel: Utilisateur : Distributeur Reference (field_distributeur_reference) */
    $handler->display->display_options['arguments']['field_distributeur_reference_target_id']['id'] = 'field_distributeur_reference_target_id';
    $handler->display->display_options['arguments']['field_distributeur_reference_target_id']['table'] = 'field_data_field_distributeur_reference';
    $handler->display->display_options['arguments']['field_distributeur_reference_target_id']['field'] = 'field_distributeur_reference_target_id';
    $handler->display->display_options['arguments']['field_distributeur_reference_target_id']['relationship'] = 'uid';
    $handler->display->display_options['arguments']['field_distributeur_reference_target_id']['default_action'] = 'default';
    $handler->display->display_options['arguments']['field_distributeur_reference_target_id']['exception']['title'] = 'Tout';
    $handler->display->display_options['arguments']['field_distributeur_reference_target_id']['default_argument_type'] = 'current_user';
    $handler->display->display_options['arguments']['field_distributeur_reference_target_id']['summary']['number_of_records'] = '0';
    $handler->display->display_options['arguments']['field_distributeur_reference_target_id']['summary']['format'] = 'default_summary';
    $handler->display->display_options['arguments']['field_distributeur_reference_target_id']['summary_options']['items_per_page'] = '25';
    $handler->display->display_options['path'] = 'espace-pro-ventes';


    return $view;
}

function view_distributeur_bon_achat(){
    $view = new view();
    $view->name = 'distributeurs_bon_achat';
    $view->description = '';
    $view->tag = 'default';
    $view->base_table = 'users';
    $view->human_name = 'Distributeurs bon achat';
    $view->core = 7;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

    /* Display: Master */
    $handler = $view->new_display('default', 'Master', 'default');
    $handler->display->display_options['title'] = 'Votre bon d\'achat distributeur Cellfood';
    $handler->display->display_options['use_more_always'] = FALSE;
    $handler->display->display_options['use_more_text'] = 'plus';
    $handler->display->display_options['access']['type'] = 'perm';
    $handler->display->display_options['access']['perm'] = 'access espace professionnel';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
    $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
    $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
    $handler->display->display_options['pager']['type'] = 'none';
    $handler->display->display_options['pager']['options']['offset'] = '0';
    $handler->display->display_options['style_plugin'] = 'default';
    $handler->display->display_options['row_plugin'] = 'fields';
    /* Champ: Utilisateur : Bon d'achat Distributeur */
    $handler->display->display_options['fields']['field_bon_achat_distributeur']['id'] = 'field_bon_achat_distributeur';
    $handler->display->display_options['fields']['field_bon_achat_distributeur']['table'] = 'field_data_field_bon_achat_distributeur';
    $handler->display->display_options['fields']['field_bon_achat_distributeur']['field'] = 'field_bon_achat_distributeur';
    $handler->display->display_options['fields']['field_bon_achat_distributeur']['label'] = '';
    $handler->display->display_options['fields']['field_bon_achat_distributeur']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_bon_achat_distributeur']['click_sort_column'] = 'amount';
    $handler->display->display_options['fields']['field_bon_achat_distributeur']['settings'] = array(
        'calculation' => FALSE,
    );
    /* Critère de tri: Utilisateur : Date de création */
    $handler->display->display_options['sorts']['created']['id'] = 'created';
    $handler->display->display_options['sorts']['created']['table'] = 'users';
    $handler->display->display_options['sorts']['created']['field'] = 'created';
    $handler->display->display_options['sorts']['created']['order'] = 'DESC';
    /* Filtre contextuel: Utilisateur : Uid */
    $handler->display->display_options['arguments']['uid']['id'] = 'uid';
    $handler->display->display_options['arguments']['uid']['table'] = 'users';
    $handler->display->display_options['arguments']['uid']['field'] = 'uid';
    $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
    $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Tout';
    $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
    $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
    $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
    $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
    /* Critère de filtrage: Utilisateur : Actif */
    $handler->display->display_options['filters']['status']['id'] = 'status';
    $handler->display->display_options['filters']['status']['table'] = 'users';
    $handler->display->display_options['filters']['status']['field'] = 'status';
    $handler->display->display_options['filters']['status']['value'] = '1';
    $handler->display->display_options['filters']['status']['group'] = 1;
    $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
    /* Critère de filtrage: Utilisateur : Rôles */
    $handler->display->display_options['filters']['rid']['id'] = 'rid';
    $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
    $handler->display->display_options['filters']['rid']['field'] = 'rid';
    $handler->display->display_options['filters']['rid']['value'] = array(
        5 => '5',
    );

    /* Display: Bon achat distributeur */
    $handler = $view->new_display('page', 'Bon achat distributeur', 'page');
    $handler->display->display_options['path'] = 'distributeurs-bon-achat';


    return $view;
}

function panel_espace_pro(){
    $page = new stdClass();
    $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
    $page->api_version = 1;
    $page->name = 'espace_professionnel';
    $page->task = 'page';
    $page->admin_title = 'espace professionnel';
    $page->admin_description = 'Espace Professionnel personalisé pour les comptes Distributeurs';
    $page->path = 'espace-professionnel-panel';
    $page->access = array(
        'plugins' => array(
            0 => array(
                'name' => 'role',
                'settings' => array(
                    'rids' => array(
                        0 => 5,
                    ),
                ),
                'context' => 'logged-in-user',
                'not' => FALSE,
            ),
        ),
        'logic' => 'and',
    );
    $page->menu = array(
        'type' => 'none',
        'title' => 'Espace Professionnel Panel',
        'name' => 'main-menu',
        'weight' => '0',
        'parent' => array(
            'type' => 'none',
            'title' => '',
            'name' => 'navigation',
            'weight' => '0',
        ),
    );
    $page->arguments = array();
    $page->conf = array(
        'admin_paths' => FALSE,
    );
    $page->default_handlers = array();
    $handler = new stdClass();
    $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
    $handler->api_version = 1;
    $handler->name = 'page_espace_professionnel__panel';
    $handler->task = 'page';
    $handler->subtask = 'espace_professionnel';
    $handler->handler = 'panel_context';
    $handler->weight = 0;
    $handler->conf = array(
        'title' => 'Panel general',
        'no_blocks' => 0,
        'pipeline' => 'standard',
        'body_classes_to_remove' => '',
        'body_classes_to_add' => '',
        'css_id' => 'espace-professionnel-panel',
        'css' => '',
        'contexts' => array(),
        'relationships' => array(),
        'name' => 'panel',
    );
    $display = new panels_display();
    $display->layout = 'flexible';
    $display->layout_settings = array(
        'items' => array(
            'canvas' => array(
                'type' => 'row',
                'contains' => 'column',
                'children' => array(
                    0 => 'main',
                ),
                'parent' => NULL,
            ),
            'main' => array(
                'type' => 'column',
                'width' => 100,
                'width_type' => '%',
                'children' => array(
                    0 => 'main-row',
                    1 => 1,
                ),
                'parent' => 'canvas',
            ),
            'main-row' => array(
                'type' => 'row',
                'contains' => 'region',
                'children' => array(
                    0 => 'left',
                    1 => 'right',
                ),
                'parent' => 'main',
            ),
            'left' => array(
                'type' => 'region',
                'title' => 'Left',
                'width' => '43.91277886785798',
                'width_type' => '%',
                'parent' => 'main-row',
                'class' => '',
                'hide_empty' => 0,
            ),
            'right' => array(
                'type' => 'region',
                'title' => 'Right',
                'width' => 56.08722113214202,
                'width_type' => '%',
                'parent' => 'main-row',
                'class' => '',
                'hide_empty' => 0,
            ),
            1 => array(
                'type' => 'row',
                'contains' => 'region',
                'children' => array(
                    0 => 'centre_commissions',
                    1 => 'right_bon_achat',
                ),
                'parent' => 'main',
                'class' => '',
                'hide_empty' => 0,
            ),
            'centre_commissions' => array(
                'type' => 'region',
                'title' => 'centre-commissions',
                'width' => '65.71509082238695',
                'width_type' => '%',
                'parent' => '1',
                'class' => '',
                'hide_empty' => 0,
            ),
            'right_bon_achat' => array(
                'type' => 'region',
                'title' => 'right-bon-achat',
                'width' => '34.284909177613045',
                'width_type' => '%',
                'parent' => '1',
                'class' => '',
                'hide_empty' => 0,
            ),
        ),
    );
    $display->panel_settings = array(
        'style_settings' => array(
            'default' => array(
                'corner_location' => 'panel',
            ),
            'center' => NULL,
            'left' => NULL,
            'right' => NULL,
            'centre_commissions' => NULL,
            'right_bon_achat' => NULL,
            'jhbjbn' => NULL,
        ),
        'style' => 'rounded_corners',
    );
    $display->cache = array();
    $display->title = 'Votre espace professionnel';
    $display->uuid = 'd6a38b1a-99c3-4f1f-8be9-15ace286f54d';
    $display->storage_type = 'page_manager';
    $display->storage_id = 'page_espace_professionnel__panel';
    $display->content = array();
    $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-86377a6e-0b87-4292-be50-8c3fe99ca651';
    $pane->panel = 'centre_commissions';
    $pane->type = 'views';
    $pane->subtype = 'espace_professionnel';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
        'override_pager_settings' => 0,
        'use_pager' => 1,
        'nodes_per_page' => '10',
        'pager_id' => '0',
        'offset' => '0',
        'more_link' => 0,
        'feed_icons' => 0,
        'panel_args' => 0,
        'link_to_view' => 0,
        'args' => '',
        'url' => '',
        'display' => 'page_1',
        'override_title' => 0,
        'override_title_text' => '',
        'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
        'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '86377a6e-0b87-4292-be50-8c3fe99ca651';
    $display->content['new-86377a6e-0b87-4292-be50-8c3fe99ca651'] = $pane;
    $display->panels['centre_commissions'][0] = 'new-86377a6e-0b87-4292-be50-8c3fe99ca651';
    $pane = new stdClass();
    $pane->pid = 'new-87e2a741-0f60-40b6-9104-0bca8f8f48ae';
    $pane->panel = 'left';
    $pane->type = 'views';
    $pane->subtype = 'espaces_pro_clients';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
        'override_pager_settings' => 0,
        'use_pager' => 0,
        'nodes_per_page' => '',
        'pager_id' => 0,
        'offset' => 0,
        'more_link' => 0,
        'feed_icons' => 0,
        'panel_args' => 0,
        'link_to_view' => 0,
        'args' => '',
        'url' => '',
        'display' => 'default',
        'override_title' => 0,
        'override_title_text' => '',
        'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
        'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '87e2a741-0f60-40b6-9104-0bca8f8f48ae';
    $display->content['new-87e2a741-0f60-40b6-9104-0bca8f8f48ae'] = $pane;
    $display->panels['left'][0] = 'new-87e2a741-0f60-40b6-9104-0bca8f8f48ae';
    $pane = new stdClass();
    $pane->pid = 'new-504fc328-c8b0-488d-b434-ca6cdf1bd5b1';
    $pane->panel = 'right';
    $pane->type = 'views';
    $pane->subtype = 'espace_pro_ventes';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
        'override_pager_settings' => 0,
        'use_pager' => 0,
        'nodes_per_page' => '',
        'pager_id' => '0',
        'offset' => '0',
        'more_link' => 0,
        'feed_icons' => 0,
        'panel_args' => 0,
        'link_to_view' => 0,
        'args' => '',
        'url' => '',
        'display' => 'page',
        'override_title' => 0,
        'override_title_text' => '',
        'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
        'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '504fc328-c8b0-488d-b434-ca6cdf1bd5b1';
    $display->content['new-504fc328-c8b0-488d-b434-ca6cdf1bd5b1'] = $pane;
    $display->panels['right'][0] = 'new-504fc328-c8b0-488d-b434-ca6cdf1bd5b1';
    $pane = new stdClass();
    $pane->pid = 'new-7f2e833f-6493-479f-982f-3a3574463c07';
    $pane->panel = 'right_bon_achat';
    $pane->type = 'views';
    $pane->subtype = 'distributeurs_bon_achat';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
        'override_pager_settings' => 0,
        'use_pager' => 0,
        'nodes_per_page' => '10',
        'pager_id' => '0',
        'offset' => '0',
        'more_link' => 0,
        'feed_icons' => 0,
        'panel_args' => 0,
        'link_to_view' => 0,
        'args' => '',
        'url' => '',
        'display' => 'default',
        'override_title' => 0,
        'override_title_text' => '',
        'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
        'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7f2e833f-6493-479f-982f-3a3574463c07';
    $display->content['new-7f2e833f-6493-479f-982f-3a3574463c07'] = $pane;
    $display->panels['right_bon_achat'][0] = 'new-7f2e833f-6493-479f-982f-3a3574463c07';
    $display->hide_title = PANELS_TITLE_FIXED;
    $display->title_pane = '0';
    $handler->conf['display'] = $display;
    $page->default_handlers[$handler->name] = $handler;

}