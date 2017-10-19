<?php
/**
 * @file
 * entity_cleanup.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function entity_cleanup_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-admin---cleanup.
  $menus['menu-admin---cleanup'] = array(
    'menu_name' => 'menu-admin---cleanup',
    'title' => 'Admin - Cleanup',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Admin - Cleanup');

  return $menus;
}
