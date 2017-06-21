<?php
/**
 * @file
 * reader_deleter.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function reader_deleter_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'reader_deleter';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_reader';
  $view->human_name = 'Reader Deleter';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Reader Deletion Page';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'field_first_name' => 'field_first_name',
    'field_age' => 'field_age',
    'field_school' => 'field_school',
    'field_grade' => 'field_grade',
    'field_program' => 'field_program',
    'field_level' => 'field_level',
    'field_points' => 'field_points',
    'field_my_badges' => 'field_my_badges',
    'field_my_prizes' => 'field_my_prizes',
    'edit_link' => 'edit_link',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_age' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_school' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_grade' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_program' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_level' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_points' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_my_badges' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_my_prizes' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<strong>Be careful!  This page allows you to DELETE READERS.  There is NO "undo" capability so be very sure about proceeding.</strong>
Check boxes and click "DELETE READER" button to delete several at once.  Otherwise, search for a specific Reader and click the "delete" link in their row.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['id'] = 'field_parent_uid_target_id';
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['table'] = 'field_data_field_parent_uid';
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['field'] = 'field_parent_uid_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_program_target_id']['id'] = 'field_program_target_id';
  $handler->display->display_options['relationships']['field_program_target_id']['table'] = 'field_data_field_program';
  $handler->display->display_options['relationships']['field_program_target_id']['field'] = 'field_program_target_id';
  /* Field: Reader: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reader';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = 'Name';
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_parent_uid_target_id';
  $handler->display->display_options['fields']['name']['label'] = 'Parent';
  /* Field: Reader: Edit link */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'eck_reader';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  /* Contextual filter: Reader: Id */
  $handler->display->display_options['arguments']['id']['id'] = 'id';
  $handler->display->display_options['arguments']['id']['table'] = 'eck_reader';
  $handler->display->display_options['arguments']['id']['field'] = 'id';
  $handler->display->display_options['arguments']['id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['id']['validate']['fail'] = 'empty';
  /* Filter criterion: Reader: reader type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_reader';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'reader' => 'reader',
  );
  /* Filter criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['filters']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['filters']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator_id'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['label'] = 'First Name';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['identifier'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['filters']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['filters']['field_last_name_value']['field'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator_id'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['label'] = 'Last Name';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['identifier'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Reader */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'eck_reader';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'DELETE SELECTED',
    ),
  );
  /* Field: Reader: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reader';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_parent_uid_target_id';
  $handler->display->display_options['fields']['name']['label'] = 'Parent';
  /* Field: Reader: Delete link */
  $handler->display->display_options['fields']['delete_link']['id'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['table'] = 'eck_reader';
  $handler->display->display_options['fields']['delete_link']['field'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['text'] = 'DELETE (careful!)';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Reader: Parent UID (field_parent_uid) */
  $handler->display->display_options['arguments']['field_parent_uid_target_id']['id'] = 'field_parent_uid_target_id';
  $handler->display->display_options['arguments']['field_parent_uid_target_id']['table'] = 'field_data_field_parent_uid';
  $handler->display->display_options['arguments']['field_parent_uid_target_id']['field'] = 'field_parent_uid_target_id';
  $handler->display->display_options['arguments']['field_parent_uid_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_parent_uid_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_parent_uid_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_parent_uid_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_parent_uid_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_parent_uid_target_id']['validate']['fail'] = 'empty';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Reader: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reader';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = 'Name';
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_parent_uid_target_id';
  $handler->display->display_options['fields']['name']['label'] = 'Parent';
  /* Field: Reader: Edit link */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'eck_reader';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';

  /* Display: Block 2 */
  $handler = $view->new_display('block', 'Block 2', 'block_2');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Reader: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reader';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = 'Name';
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_parent_uid_target_id';
  $handler->display->display_options['fields']['name']['label'] = 'Parent';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Reader: Parent UID (field_parent_uid) */
  $handler->display->display_options['arguments']['field_parent_uid_target_id']['id'] = 'field_parent_uid_target_id';
  $handler->display->display_options['arguments']['field_parent_uid_target_id']['table'] = 'field_data_field_parent_uid';
  $handler->display->display_options['arguments']['field_parent_uid_target_id']['field'] = 'field_parent_uid_target_id';
  $handler->display->display_options['arguments']['field_parent_uid_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_parent_uid_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_parent_uid_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_parent_uid_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_parent_uid_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_parent_uid_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_parent_uid_target_id']['validate']['fail'] = 'empty';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Reader: reader type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_reader';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'reader' => 'reader',
  );

  /* Display: Block 3 */
  $handler = $view->new_display('block', 'Block 3', 'block_3');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['id'] = 'field_parent_uid_target_id';
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['table'] = 'field_data_field_parent_uid';
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['field'] = 'field_parent_uid_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_program_target_id']['id'] = 'field_program_target_id';
  $handler->display->display_options['relationships']['field_program_target_id']['table'] = 'field_data_field_program';
  $handler->display->display_options['relationships']['field_program_target_id']['field'] = 'field_program_target_id';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_readers_reader_badge']['id'] = 'reverse_field_readers_reader_badge';
  $handler->display->display_options['relationships']['reverse_field_readers_reader_badge']['table'] = 'eck_reader';
  $handler->display->display_options['relationships']['reverse_field_readers_reader_badge']['field'] = 'reverse_field_readers_reader_badge';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Reader: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reader';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = 'Name';
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_parent_uid_target_id';
  $handler->display->display_options['fields']['name']['label'] = 'Parent';
  /* Field: Reader: Edit link */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'eck_reader';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  /* Field: Reader: Age */
  $handler->display->display_options['fields']['field_age']['id'] = 'field_age';
  $handler->display->display_options['fields']['field_age']['table'] = 'field_data_field_age';
  $handler->display->display_options['fields']['field_age']['field'] = 'field_age';
  $handler->display->display_options['fields']['field_age']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Reader: Grade */
  $handler->display->display_options['fields']['field_grade']['id'] = 'field_grade';
  $handler->display->display_options['fields']['field_grade']['table'] = 'field_data_field_grade';
  $handler->display->display_options['fields']['field_grade']['field'] = 'field_grade';
  /* Field: Reader: Reader School */
  $handler->display->display_options['fields']['field_reader_school']['id'] = 'field_reader_school';
  $handler->display->display_options['fields']['field_reader_school']['table'] = 'field_data_field_reader_school';
  $handler->display->display_options['fields']['field_reader_school']['field'] = 'field_reader_school';
  $handler->display->display_options['fields']['field_reader_school']['settings'] = array(
    'link' => 0,
  );
  /* Field: Program: Per Unit Label */
  $handler->display->display_options['fields']['field_per_unit_label']['id'] = 'field_per_unit_label';
  $handler->display->display_options['fields']['field_per_unit_label']['table'] = 'field_data_field_per_unit_label';
  $handler->display->display_options['fields']['field_per_unit_label']['field'] = 'field_per_unit_label';
  $handler->display->display_options['fields']['field_per_unit_label']['relationship'] = 'field_program_target_id';
  /* Field: Program: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_program';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Reader: reader type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_reader';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'reader' => 'reader',
  );
  $export['reader_deleter'] = $view;

  return $export;
}
