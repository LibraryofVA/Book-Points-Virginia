<?php
/**
 * @file
 * booklist.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function booklist_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_book-lists:book-lists.
  $menu_links['main-menu_book-lists:book-lists'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'book-lists',
    'router_path' => 'book-lists',
    'link_title' => 'Book Lists',
    'options' => array(
      'identifier' => 'main-menu_book-lists:book-lists',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: menu-library-menu1_book-lists:library/manage-book-lists.
  $menu_links['menu-library-menu1_book-lists:library/manage-book-lists'] = array(
    'menu_name' => 'menu-library-menu1',
    'link_path' => 'library/manage-book-lists',
    'router_path' => 'library/manage-book-lists',
    'link_title' => 'Book Lists',
    'options' => array(
      'identifier' => 'menu-library-menu1_book-lists:library/manage-book-lists',
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
  t('Book Lists');

  return $menu_links;
}
