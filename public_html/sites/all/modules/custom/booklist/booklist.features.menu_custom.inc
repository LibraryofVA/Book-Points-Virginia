<?php
/**
 * @file
 * booklist.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function booklist_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-library-menu1.
  $menus['menu-library-menu1'] = array(
    'menu_name' => 'menu-library-menu1',
    'title' => 'Library menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Library menu');
  t('Main menu');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');

  return $menus;
}
