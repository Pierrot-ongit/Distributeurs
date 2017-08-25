<?php

/**
 * @file
 * Default rule configurations for Distributeur Relationship.
 */

function distributeurs_default_rules_configuration() {
    $rules = array();

    $rules_create_distributeur_relation = '{ "rules_create_distributeur_relation" : {
    "LABEL" : "Distributeur relation",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "REQUIRES" : [ "rules", "distributeurs" ],
    "ON" : { "user_login" : [], "user_update" : [] },
    "IF" : [
      { "OR" : [
          { "NOT data_is_empty" : { "data" : [ "account:field-code-ambassadeur" ] } },
          { "NOT data_is_empty" : { "data" : [ "account:field-code-vendeur:name" ] } }
        ]
      }
    ],
    "DO" : [
      { "distributeurs_relationship_save_distributeur_relationship" : { "user" : [ "account" ], "overwrite" : "0" } }
    ]
  }
}';
    /*
     * TODO
     * Rajouter la régle custom pour les orders commissions, et désactiver la régle orginale
     */
    $rules_commission_distributeur = '
{ "rules_commission_distributeur" : {
    "LABEL" : "Commission Distributeur",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "REQUIRES" : [ "rules", "distributeurs", "commerce_checkout" ],
    "ON" : { "commerce_checkout_complete" : [] },
    "IF" : [
      { "NOT data_is_empty" : { "data" : [ "commerce-order:owner:field-distributeur-reference" ] } },
      { "entity_has_field" : {
          "entity" : [ "commerce-order:owner:field-distributeur-reference" ],
          "field" : "field_bon_achat_distributeur"
        }
      }
    ],
    "DO" : [
      { "distributeurs_commission_distributeur" : {
          "entity" : [ "commerce-order" ],
          "commission_type" : "commerce_order",
          "percentage" : "20",
          "user" : [ "commerce-order:owner:field-distributeur-reference" ]
        }
      }
    ]
  }
}
    ';


$rules_bon_achat_distributeur_used = '
{ "rules_bon_achat_distributeur_used" : {
    "LABEL" : "bon achat distributeur utilis\u00e9",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "REQUIRES" : [ "commerce_coupon", "distributeurs", "commerce_checkout" ],
    "ON" : { "commerce_checkout_complete" : [] },
    "IF" : [
      { "commerce_coupon_discount_coupon_codes_exist_on_order" : {
          "commerce_order" : [ "commerce_order" ],
          "commerce_discount" : "discount_remise_distributeurs_bon_achat"
        }
      }
    ],
    "DO" : [
      { "distributeurs_bon_achat_used" : { "entity" : [ "commerce-order" ], "user" : [ "commerce-order:owner" ] } }
    ]
  }
}
';


    $rules['rules_create_distributeur_relation'] = rules_import($rules_create_distributeur_relation);
    $rules['rules_commission_distributeur'] = rules_import($rules_commission_distributeur);
    $rules['rules_bon_achat_distributeur_used'] = rules_import($rules_bon_achat_distributeur_used);

    // RULES DISCOUNT. PROBABLEMENT FAUX!
   /*
    $rules['discount_remise_distributeurs_bon_achat'] =rules_import($discount_remise_distributeurs_bon_achat);
    $rules['discount_remise_prix_distributeurs'] =rules_import($discount_remise_prix_distributeurs);
*/
    return $rules;
}

/**
 * DISCOUNT RULES A IMPORTER MANUELLEMENT DANS
 *  votresite/admin/commerce/discounts/import
 */
function distributeurs_discounts() {
    $discount_remise_distributeurs_bon_achat = '
{
  "name" : "discount_remise_distributeurs_bon_achat",
  "label" : "Remise distributeurs bon achat",
  "type" : "order_discount",
  "status" : "1",
  "component_title" : "Remise distributeurs bon achat",
  "sort_order" : "10",
  "commerce_discount_offer" : { "type" : "distributeurs_remise_bon_achat", "rdf_mapping" : [] },
  "commerce_compatibility_strategy" : { "und" : [ { "value" : "any" } ] },
  "commerce_compatibility_selection" : [],
  "commerce_discount_date" : [],
  "inline_conditions" : { "und" : [
      {
        "condition_name" : "commerce_discount_extra_order_user_has_role",
        "condition_settings" : {
          "roles" : { "distributeur" : "distributeur" },
          "condition_logic_operator" : null
        },
        "condition_negate" : 0
      }
    ]
  },
  "discount_usage_per_person" : [],
  "discount_usage_limit" : [],
  "rdf_mapping" : []
}
 ';

    $discount_remise_prix_distributeurs = '
{
  "name" : "discount_remise_prix_distributeurs",
  "label" : "Remise prix distributeurs",
  "type" : "order_discount",
  "status" : "1",
  "component_title" : "Remise prix distributeurs",
  "sort_order" : "10",
  "commerce_discount_offer" : {
    "type" : "percentage",
    "commerce_percentage" : { "und" : [ { "value" : "20.00" } ] },
    "rdf_mapping" : []
  },
  "commerce_compatibility_strategy" : { "und" : [ { "value" : "any" } ] },
  "commerce_compatibility_selection" : [],
  "commerce_discount_date" : [],
  "inline_conditions" : { "und" : [
      {
        "condition_name" : "commerce_discount_extra_order_user_has_role",
        "condition_settings" : {
          "roles" : { "distributeur" : "distributeur" },
          "condition_logic_operator" : null
        },
        "condition_negate" : 0
      }
    ]
  },
  "discount_usage_per_person" : [],
  "discount_usage_limit" : [],
  "rdf_mapping" : []
}
 ';
}