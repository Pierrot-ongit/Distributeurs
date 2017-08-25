<?php

$page = new stdClass();
$page->disabled = TRUE; /* Edit this to true to make a default page disabled initially */
$page->api_version = 1;
$page->name = 'espace_professionnel';
$page->task = 'page';
$page->admin_title = 'espace professionnel';
$page->admin_description = 'Espace Professionnel personalisé pour les comptes Distributeurs';
$page->path = 'espace-professionnel-cellfood';
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
    'type' => 'normal',
    'title' => 'Espace Professionnel Cellfood',
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
$pane->pid = 'new-ab102e8f-e3a3-4fd6-9598-e2f21a590dc9';
$pane->panel = 'centre_commissions';
$pane->type = 'views';
$pane->subtype = 'espace_professionnel';
$pane->shown = TRUE;
$pane->access = array();
$pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
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
$pane->uuid = 'ab102e8f-e3a3-4fd6-9598-e2f21a590dc9';
$display->content['new-ab102e8f-e3a3-4fd6-9598-e2f21a590dc9'] = $pane;
$display->panels['centre_commissions'][0] = 'new-ab102e8f-e3a3-4fd6-9598-e2f21a590dc9';
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
