<?php
/**
 * Implementation of hook_default_page_manager_pages().
 */
/*
function espace_pro_default_page_manager_pages() {
    $files = file_scan_directory(drupal_get_path('module', 'espace_pro'). '/pages', '.inc');
    foreach ($files as $absolute => $file) {
        require $absolute;
        if (isset($page)) {
            $pages[$file->name] = $page;
        }
    }
    return $pages;
}
*/