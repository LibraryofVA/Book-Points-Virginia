<?php
/**
 * @file
 * booklist.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function booklist_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'book_lists';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Book Lists';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Book Lists';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Books (field_booklist_books) */
  $handler->display->display_options['relationships']['field_booklist_books_value']['id'] = 'field_booklist_books_value';
  $handler->display->display_options['relationships']['field_booklist_books_value']['table'] = 'field_data_field_booklist_books';
  $handler->display->display_options['relationships']['field_booklist_books_value']['field'] = 'field_booklist_books_value';
  $handler->display->display_options['relationships']['field_booklist_books_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_booklist_books_value']['delta'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Cover Image */
  $handler->display->display_options['fields']['field_bl_b_image']['id'] = 'field_bl_b_image';
  $handler->display->display_options['fields']['field_bl_b_image']['table'] = 'field_data_field_bl_b_image';
  $handler->display->display_options['fields']['field_bl_b_image']['field'] = 'field_bl_b_image';
  $handler->display->display_options['fields']['field_bl_b_image']['relationship'] = 'field_booklist_books_value';
  $handler->display->display_options['fields']['field_bl_b_image']['label'] = '';
  $handler->display->display_options['fields']['field_bl_b_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bl_b_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_bl_b_image']['settings'] = array(
    'image_style' => '',
    'image_link' => 'content',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'book_list' => 'book_list',
  );

  /* Display: Book Lists (reader) */
  $handler = $view->new_display('page', 'Book Lists (reader)', 'page');
  $handler->display->display_options['path'] = 'book-lists';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Book Lists';
  $handler->display->display_options['menu']['name'] = 'main-menu';

  /* Display: Manage Book Lists */
  $handler = $view->new_display('page', 'Manage Book Lists', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Manage Book Lists';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_bl_b_image' => 'field_bl_b_image',
    'body' => 'body',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_bl_b_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
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
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<a href="/node/add/book-list">Add a new book list</a>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Books (field_booklist_books) */
  $handler->display->display_options['relationships']['field_booklist_books_value']['id'] = 'field_booklist_books_value';
  $handler->display->display_options['relationships']['field_booklist_books_value']['table'] = 'field_data_field_booklist_books';
  $handler->display->display_options['relationships']['field_booklist_books_value']['field'] = 'field_booklist_books_value';
  $handler->display->display_options['relationships']['field_booklist_books_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_booklist_books_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Cover Image */
  $handler->display->display_options['fields']['field_bl_b_image']['id'] = 'field_bl_b_image';
  $handler->display->display_options['fields']['field_bl_b_image']['table'] = 'field_data_field_bl_b_image';
  $handler->display->display_options['fields']['field_bl_b_image']['field'] = 'field_bl_b_image';
  $handler->display->display_options['fields']['field_bl_b_image']['relationship'] = 'field_booklist_books_value';
  $handler->display->display_options['fields']['field_bl_b_image']['label'] = '';
  $handler->display->display_options['fields']['field_bl_b_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bl_b_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_bl_b_image']['settings'] = array(
    'image_style' => '',
    'image_link' => 'content',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['text'] = 'edit';
  $handler->display->display_options['path'] = 'library/manage-book-lists';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Manage Book Lists';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-library-menu1';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['book_lists'] = $view;

  return $export;
}
