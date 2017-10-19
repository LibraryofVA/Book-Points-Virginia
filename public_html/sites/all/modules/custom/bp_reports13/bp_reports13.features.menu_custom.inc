<?php
/**
 * @file
 * bp_reports13.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function bp_reports13_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-reports-menu.
  $menus['menu-reports-menu'] = array(
    'menu_name' => 'menu-reports-menu',
    'title' => 'Reports Menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Reports Menu');

  return $menus;
}
