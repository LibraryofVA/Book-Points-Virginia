<?php
/**
 * @file
 * booklist.features.inc
 */

/**
 * Implements hook_views_api().
 */
function booklist_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function booklist_node_info() {
  $items = array(
    'book_list' => array(
      'name' => t('Book List'),
      'base' => 'node_content',
      'description' => t('A book list is a collection of books that can be displayed in a variety of formats.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
