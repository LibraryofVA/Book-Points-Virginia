<?php
/**
 * @file
 * book_logs.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function book_logs_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'book_logs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_reading_log';
  $view->human_name = 'Book Logs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Book Log';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_readers',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'created' => 'created',
    'field_readers' => 'field_readers',
    'field_book_title' => 'field_book_title',
    'field_author' => 'field_author',
    'field_stars' => 'field_stars',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_readers' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_book_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_author' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_stars' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_readers_target_id']['id'] = 'field_readers_target_id';
  $handler->display->display_options['relationships']['field_readers_target_id']['table'] = 'field_data_field_readers';
  $handler->display->display_options['relationships']['field_readers_target_id']['field'] = 'field_readers_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['id'] = 'field_parent_uid_target_id';
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['table'] = 'field_data_field_parent_uid';
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['field'] = 'field_parent_uid_target_id';
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['relationship'] = 'field_readers_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_program_reference_target_id']['id'] = 'field_program_reference_target_id';
  $handler->display->display_options['relationships']['field_program_reference_target_id']['table'] = 'field_data_field_program_reference';
  $handler->display->display_options['relationships']['field_program_reference_target_id']['field'] = 'field_program_reference_target_id';
  /* Field: Field: Unit Type */
  $handler->display->display_options['fields']['field_unit_type']['id'] = 'field_unit_type';
  $handler->display->display_options['fields']['field_unit_type']['table'] = 'field_data_field_unit_type';
  $handler->display->display_options['fields']['field_unit_type']['field'] = 'field_unit_type';
  $handler->display->display_options['fields']['field_unit_type']['exclude'] = TRUE;
  /* Field: Field: Units Completed */
  $handler->display->display_options['fields']['field_units_completed']['id'] = 'field_units_completed';
  $handler->display->display_options['fields']['field_units_completed']['table'] = 'field_data_field_units_completed';
  $handler->display->display_options['fields']['field_units_completed']['field'] = 'field_units_completed';
  $handler->display->display_options['fields']['field_units_completed']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_units_completed']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Reading Log: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_reading_log';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Field: Readers */
  $handler->display->display_options['fields']['field_readers']['id'] = 'field_readers';
  $handler->display->display_options['fields']['field_readers']['table'] = 'field_data_field_readers';
  $handler->display->display_options['fields']['field_readers']['field'] = 'field_readers';
  $handler->display->display_options['fields']['field_readers']['label'] = 'Reader';
  $handler->display->display_options['fields']['field_readers']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_readers']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_readers']['delta_offset'] = '0';
  /* Field: Field: Book Title */
  $handler->display->display_options['fields']['field_book_title']['id'] = 'field_book_title';
  $handler->display->display_options['fields']['field_book_title']['table'] = 'field_data_field_book_title';
  $handler->display->display_options['fields']['field_book_title']['field'] = 'field_book_title';
  /* Field: Field: Author */
  $handler->display->display_options['fields']['field_author']['id'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['table'] = 'field_data_field_author';
  $handler->display->display_options['fields']['field_author']['field'] = 'field_author';
  /* Field: Field: Stars */
  $handler->display->display_options['fields']['field_stars']['id'] = 'field_stars';
  $handler->display->display_options['fields']['field_stars']['table'] = 'field_data_field_stars';
  $handler->display->display_options['fields']['field_stars']['field'] = 'field_stars';
  /* Field: Program: Per Unit Label */
  $handler->display->display_options['fields']['field_per_unit_label']['id'] = 'field_per_unit_label';
  $handler->display->display_options['fields']['field_per_unit_label']['table'] = 'field_data_field_per_unit_label';
  $handler->display->display_options['fields']['field_per_unit_label']['field'] = 'field_per_unit_label';
  $handler->display->display_options['fields']['field_per_unit_label']['relationship'] = 'field_program_reference_target_id';
  $handler->display->display_options['fields']['field_per_unit_label']['label'] = '';
  $handler->display->display_options['fields']['field_per_unit_label']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_per_unit_label']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Entry';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_units_completed] [field_per_unit_label](s)';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'field_parent_uid_target_id';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'my/book-log';
  $export['book_logs'] = $view;

  return $export;
}
