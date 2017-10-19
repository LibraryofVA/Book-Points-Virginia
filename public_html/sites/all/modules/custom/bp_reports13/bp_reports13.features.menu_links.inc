<?php
/**
 * @file
 * bp_reports13.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function bp_reports13_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-reports-menu_patron-email-list:library/report/users/emails.
  $menu_links['menu-reports-menu_patron-email-list:library/report/users/emails'] = array(
    'menu_name' => 'menu-reports-menu',
    'link_path' => 'library/report/users/emails',
    'router_path' => 'library/report/users/emails',
    'link_title' => 'Patron Email List',
    'options' => array(
      'identifier' => 'menu-reports-menu_patron-email-list:library/report/users/emails',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 40,
    'customized' => 0,
  );
  // Exported menu link: menu-reports-menu_reader-reports:library/reports/readers.
  $menu_links['menu-reports-menu_reader-reports:library/reports/readers'] = array(
    'menu_name' => 'menu-reports-menu',
    'link_path' => 'library/reports/readers',
    'router_path' => 'library/reports/readers',
    'link_title' => 'Reader Reports',
    'options' => array(
      'identifier' => 'menu-reports-menu_reader-reports:library/reports/readers',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: menu-reports-menu_reading-reports:library/reports/reading.
  $menu_links['menu-reports-menu_reading-reports:library/reports/reading'] = array(
    'menu_name' => 'menu-reports-menu',
    'link_path' => 'library/reports/reading',
    'router_path' => 'library/reports/reading',
    'link_title' => 'Reading Reports',
    'options' => array(
      'identifier' => 'menu-reports-menu_reading-reports:library/reports/reading',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Patron Email List');
  t('Reader Reports');
  t('Reading Reports');

  return $menu_links;
}
