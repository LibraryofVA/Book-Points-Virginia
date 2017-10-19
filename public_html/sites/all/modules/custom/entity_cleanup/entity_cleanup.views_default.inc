<?php
/**
 * @file
 * entity_cleanup.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function entity_cleanup_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'cleanup_activity_log';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_activity_log';
  $view->human_name = 'Cleanup - Activity Log';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Cleanup - Activity Log';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_readers_target_id']['id'] = 'field_readers_target_id';
  $handler->display->display_options['relationships']['field_readers_target_id']['table'] = 'field_data_field_readers';
  $handler->display->display_options['relationships']['field_readers_target_id']['field'] = 'field_readers_target_id';
  /* Field: Bulk operations: Activity Log */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'eck_activity_log';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Activity Log: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_activity_log';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Activity Log: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_activity_log';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Field: Points Earned */
  $handler->display->display_options['fields']['field_points_earned']['id'] = 'field_points_earned';
  $handler->display->display_options['fields']['field_points_earned']['table'] = 'field_data_field_points_earned';
  $handler->display->display_options['fields']['field_points_earned']['field'] = 'field_points_earned';
  $handler->display->display_options['fields']['field_points_earned']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Field: Readers */
  $handler->display->display_options['fields']['field_readers']['id'] = 'field_readers';
  $handler->display->display_options['fields']['field_readers']['table'] = 'field_data_field_readers';
  $handler->display->display_options['fields']['field_readers']['field'] = 'field_readers';
  $handler->display->display_options['fields']['field_readers']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_readers']['delta_offset'] = '0';
  /* Field: Activity Log: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_activity_log';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Activity Instance';
  /* Filter criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['filters']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['filters']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['relationship'] = 'field_readers_target_id';
  $handler->display->display_options['filters']['field_first_name_value']['operator'] = 'contains';
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
  $handler->display->display_options['filters']['field_last_name_value']['relationship'] = 'field_readers_target_id';
  $handler->display->display_options['filters']['field_last_name_value']['operator'] = 'contains';
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
  /* Filter criterion: Activity Log: Created */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'eck_activity_log';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = 'between';
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Created';
  $handler->display->display_options['filters']['created']['expose']['description'] = 'Use YYYY-MM-DD format for dates.';
  $handler->display->display_options['filters']['created']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'library/admin/cleanup-activity-log';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Cleanup - Activities Claimed';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-admin---cleanup';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['cleanup_activity_log'] = $view;

  $view = new view();
  $view->name = 'cleanup_reader_badge';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_reader_badge';
  $view->human_name = 'Cleanup - Reader Badge';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Cleanup - Reader Badge';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_readers_target_id']['id'] = 'field_readers_target_id';
  $handler->display->display_options['relationships']['field_readers_target_id']['table'] = 'field_data_field_readers';
  $handler->display->display_options['relationships']['field_readers_target_id']['field'] = 'field_readers_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reader_badge_target_id']['id'] = 'field_reader_badge_target_id';
  $handler->display->display_options['relationships']['field_reader_badge_target_id']['table'] = 'field_data_field_reader_badge';
  $handler->display->display_options['relationships']['field_reader_badge_target_id']['field'] = 'field_reader_badge_target_id';
  /* Field: Bulk operations: Reader Badge */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'eck_reader_badge';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Reader Badge: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reader_badge';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'field_readers_target_id';
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'field_readers_target_id';
  /* Field: Field: Readers */
  $handler->display->display_options['fields']['field_readers']['id'] = 'field_readers';
  $handler->display->display_options['fields']['field_readers']['table'] = 'field_data_field_readers';
  $handler->display->display_options['fields']['field_readers']['field'] = 'field_readers';
  $handler->display->display_options['fields']['field_readers']['label'] = 'Link to Reader profile';
  $handler->display->display_options['fields']['field_readers']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_readers']['delta_offset'] = '0';
  /* Field: Field: Reader Badge */
  $handler->display->display_options['fields']['field_reader_badge']['id'] = 'field_reader_badge';
  $handler->display->display_options['fields']['field_reader_badge']['table'] = 'field_data_field_reader_badge';
  $handler->display->display_options['fields']['field_reader_badge']['field'] = 'field_reader_badge';
  $handler->display->display_options['fields']['field_reader_badge']['settings'] = array(
    'link' => 0,
  );
  /* Filter criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['filters']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['filters']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['relationship'] = 'field_readers_target_id';
  $handler->display->display_options['filters']['field_first_name_value']['operator'] = 'contains';
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
  $handler->display->display_options['filters']['field_last_name_value']['relationship'] = 'field_readers_target_id';
  $handler->display->display_options['filters']['field_last_name_value']['operator'] = 'contains';
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
  /* Filter criterion: Badge: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'eck_badge';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_reader_badge_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Badge name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'library/admin/cleanup-reader-badge';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Cleanup - Reader Badge';
  $handler->display->display_options['menu']['name'] = 'menu-admin---cleanup';
  $export['cleanup_reader_badge'] = $view;

  $view = new view();
  $view->name = 'cleanup_reader_prizes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_reader_prize';
  $view->human_name = 'Cleanup - Reader Prizes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Cleanup - Reader Prizes';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_current_reader_prizes_reader']['id'] = 'reverse_field_current_reader_prizes_reader';
  $handler->display->display_options['relationships']['reverse_field_current_reader_prizes_reader']['table'] = 'eck_reader_prize';
  $handler->display->display_options['relationships']['reverse_field_current_reader_prizes_reader']['field'] = 'reverse_field_current_reader_prizes_reader';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_prize_reference_target_id']['id'] = 'field_prize_reference_target_id';
  $handler->display->display_options['relationships']['field_prize_reference_target_id']['table'] = 'field_data_field_prize_reference';
  $handler->display->display_options['relationships']['field_prize_reference_target_id']['field'] = 'field_prize_reference_target_id';
  /* Field: Bulk operations: Reader Prize */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'eck_reader_prize';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Reader Prize: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reader_prize';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Reader Prize: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_reader_prize';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Field: Readers */
  $handler->display->display_options['fields']['field_readers']['id'] = 'field_readers';
  $handler->display->display_options['fields']['field_readers']['table'] = 'field_data_field_readers';
  $handler->display->display_options['fields']['field_readers']['field'] = 'field_readers';
  $handler->display->display_options['fields']['field_readers']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_readers']['delta_offset'] = '0';
  /* Field: Field: Prize Reference */
  $handler->display->display_options['fields']['field_prize_reference']['id'] = 'field_prize_reference';
  $handler->display->display_options['fields']['field_prize_reference']['table'] = 'field_data_field_prize_reference';
  $handler->display->display_options['fields']['field_prize_reference']['field'] = 'field_prize_reference';
  $handler->display->display_options['fields']['field_prize_reference']['settings'] = array(
    'link' => 1,
  );
  /* Filter criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['filters']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['filters']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['relationship'] = 'reverse_field_current_reader_prizes_reader';
  $handler->display->display_options['filters']['field_first_name_value']['group'] = 1;
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
  $handler->display->display_options['filters']['field_last_name_value']['relationship'] = 'reverse_field_current_reader_prizes_reader';
  $handler->display->display_options['filters']['field_last_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_last_name_value']['group'] = 1;
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
  /* Filter criterion: Reader Prize: Created */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'eck_reader_prize';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = 'between';
  $handler->display->display_options['filters']['created']['group'] = 1;
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Earned';
  $handler->display->display_options['filters']['created']['expose']['description'] = 'enter date in YYYY-MM-DD format.';
  $handler->display->display_options['filters']['created']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_label'] = 'choose date criteria';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Prize: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'eck_prize';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_prize_reference_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Prize';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'library/admin/cleanup-reader-prizes';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Cleanup - Reader Prizes';
  $handler->display->display_options['menu']['name'] = 'menu-admin---cleanup';
  $export['cleanup_reader_prizes'] = $view;

  $view = new view();
  $view->name = 'cleanup_reading_log';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_reading_log';
  $view->human_name = 'Cleanup - Reading Log';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Cleanup - Reading Log';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_readers_target_id']['id'] = 'field_readers_target_id';
  $handler->display->display_options['relationships']['field_readers_target_id']['table'] = 'field_data_field_readers';
  $handler->display->display_options['relationships']['field_readers_target_id']['field'] = 'field_readers_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_program_reference_target_id']['id'] = 'field_program_reference_target_id';
  $handler->display->display_options['relationships']['field_program_reference_target_id']['table'] = 'field_data_field_program_reference';
  $handler->display->display_options['relationships']['field_program_reference_target_id']['field'] = 'field_program_reference_target_id';
  /* Field: Bulk operations: Reading Log */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'eck_reading_log';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Reading Log: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reading_log';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Field: Readers */
  $handler->display->display_options['fields']['field_readers']['id'] = 'field_readers';
  $handler->display->display_options['fields']['field_readers']['table'] = 'field_data_field_readers';
  $handler->display->display_options['fields']['field_readers']['field'] = 'field_readers';
  $handler->display->display_options['fields']['field_readers']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_readers']['delta_offset'] = '0';
  /* Field: Reading Log: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_reading_log';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Field: Program Reference */
  $handler->display->display_options['fields']['field_program_reference']['id'] = 'field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['table'] = 'field_data_field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['field'] = 'field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_program_reference']['delta_offset'] = '0';
  /* Field: Field: Unit Type */
  $handler->display->display_options['fields']['field_unit_type']['id'] = 'field_unit_type';
  $handler->display->display_options['fields']['field_unit_type']['table'] = 'field_data_field_unit_type';
  $handler->display->display_options['fields']['field_unit_type']['field'] = 'field_unit_type';
  /* Field: Field: Units Completed */
  $handler->display->display_options['fields']['field_units_completed']['id'] = 'field_units_completed';
  $handler->display->display_options['fields']['field_units_completed']['table'] = 'field_data_field_units_completed';
  $handler->display->display_options['fields']['field_units_completed']['field'] = 'field_units_completed';
  $handler->display->display_options['fields']['field_units_completed']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Filter criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['filters']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['filters']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['relationship'] = 'field_readers_target_id';
  $handler->display->display_options['filters']['field_first_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_first_name_value']['group'] = 1;
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
  $handler->display->display_options['filters']['field_last_name_value']['relationship'] = 'field_readers_target_id';
  $handler->display->display_options['filters']['field_last_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_last_name_value']['group'] = 1;
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
  /* Filter criterion: Reading Log: Created */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'eck_reading_log';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = 'between';
  $handler->display->display_options['filters']['created']['group'] = 1;
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Created';
  $handler->display->display_options['filters']['created']['expose']['description'] = 'Use YYYY-MM-DD format for dates.';
  $handler->display->display_options['filters']['created']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Program: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'eck_program';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_program_reference_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Program';
  $handler->display->display_options['filters']['title']['expose']['description'] = '(text field, e.g. "Kids" or "Adults")';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'library/admin/cleanup-reading-log';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Cleanup - Reading Log Entries';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-admin---cleanup';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['cleanup_reading_log'] = $view;

  $view = new view();
  $view->name = 'orphans_activity_log';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_activity_log';
  $view->human_name = 'Orphans - Activity Log';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Orphans - Activity Log';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_readers_target_id']['id'] = 'field_readers_target_id';
  $handler->display->display_options['relationships']['field_readers_target_id']['table'] = 'field_data_field_readers';
  $handler->display->display_options['relationships']['field_readers_target_id']['field'] = 'field_readers_target_id';
  /* Field: Bulk operations: Activity Log */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'eck_activity_log';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Activity Log: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_activity_log';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Activity Log: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_activity_log';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Field: Points Earned */
  $handler->display->display_options['fields']['field_points_earned']['id'] = 'field_points_earned';
  $handler->display->display_options['fields']['field_points_earned']['table'] = 'field_data_field_points_earned';
  $handler->display->display_options['fields']['field_points_earned']['field'] = 'field_points_earned';
  $handler->display->display_options['fields']['field_points_earned']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Field: Readers */
  $handler->display->display_options['fields']['field_readers']['id'] = 'field_readers';
  $handler->display->display_options['fields']['field_readers']['table'] = 'field_data_field_readers';
  $handler->display->display_options['fields']['field_readers']['field'] = 'field_readers';
  $handler->display->display_options['fields']['field_readers']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_readers']['delta_offset'] = '0';
  /* Field: Activity Log: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_activity_log';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Activity Instance';
  /* Filter criterion: Field: Readers (field_readers) */
  $handler->display->display_options['filters']['field_readers_target_id']['id'] = 'field_readers_target_id';
  $handler->display->display_options['filters']['field_readers_target_id']['table'] = 'field_data_field_readers';
  $handler->display->display_options['filters']['field_readers_target_id']['field'] = 'field_readers_target_id';
  $handler->display->display_options['filters']['field_readers_target_id']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_readers_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_readers_target_id']['expose']['operator_id'] = 'field_readers_target_id_op';
  $handler->display->display_options['filters']['field_readers_target_id']['expose']['label'] = 'Readers (field_readers)';
  $handler->display->display_options['filters']['field_readers_target_id']['expose']['description'] = '(admin only!)';
  $handler->display->display_options['filters']['field_readers_target_id']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_readers_target_id']['expose']['operator'] = 'field_readers_target_id_op';
  $handler->display->display_options['filters']['field_readers_target_id']['expose']['identifier'] = 'field_readers_target_id';
  $handler->display->display_options['filters']['field_readers_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'library/admin/orphans-activity-log';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Orphans - Activities Claimed';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-admin---cleanup';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['orphans_activity_log'] = $view;

  $view = new view();
  $view->name = 'orphans_reader_badge';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_reader_badge';
  $view->human_name = 'Orphans - Reader Badge';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Orphans - Reader Badge';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_readers_target_id']['id'] = 'field_readers_target_id';
  $handler->display->display_options['relationships']['field_readers_target_id']['table'] = 'field_data_field_readers';
  $handler->display->display_options['relationships']['field_readers_target_id']['field'] = 'field_readers_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reader_badge_target_id']['id'] = 'field_reader_badge_target_id';
  $handler->display->display_options['relationships']['field_reader_badge_target_id']['table'] = 'field_data_field_reader_badge';
  $handler->display->display_options['relationships']['field_reader_badge_target_id']['field'] = 'field_reader_badge_target_id';
  /* Field: Bulk operations: Reader Badge */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'eck_reader_badge';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Reader Badge: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reader_badge';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'field_readers_target_id';
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'field_readers_target_id';
  /* Field: Field: Readers */
  $handler->display->display_options['fields']['field_readers']['id'] = 'field_readers';
  $handler->display->display_options['fields']['field_readers']['table'] = 'field_data_field_readers';
  $handler->display->display_options['fields']['field_readers']['field'] = 'field_readers';
  $handler->display->display_options['fields']['field_readers']['label'] = 'Link to Reader profile';
  $handler->display->display_options['fields']['field_readers']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_readers']['delta_offset'] = '0';
  /* Field: Field: Reader Badge */
  $handler->display->display_options['fields']['field_reader_badge']['id'] = 'field_reader_badge';
  $handler->display->display_options['fields']['field_reader_badge']['table'] = 'field_data_field_reader_badge';
  $handler->display->display_options['fields']['field_reader_badge']['field'] = 'field_reader_badge';
  $handler->display->display_options['fields']['field_reader_badge']['settings'] = array(
    'link' => 0,
  );
  /* Filter criterion: Field: Readers (field_readers) */
  $handler->display->display_options['filters']['field_readers_target_id']['id'] = 'field_readers_target_id';
  $handler->display->display_options['filters']['field_readers_target_id']['table'] = 'field_data_field_readers';
  $handler->display->display_options['filters']['field_readers_target_id']['field'] = 'field_readers_target_id';
  $handler->display->display_options['filters']['field_readers_target_id']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_readers_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_readers_target_id']['expose']['operator_id'] = 'field_readers_target_id_op';
  $handler->display->display_options['filters']['field_readers_target_id']['expose']['label'] = 'Readers (field_readers)';
  $handler->display->display_options['filters']['field_readers_target_id']['expose']['description'] = '(admin only!)';
  $handler->display->display_options['filters']['field_readers_target_id']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_readers_target_id']['expose']['operator'] = 'field_readers_target_id_op';
  $handler->display->display_options['filters']['field_readers_target_id']['expose']['identifier'] = 'field_readers_target_id';
  $handler->display->display_options['filters']['field_readers_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'library/admin/orphans-reader-badge';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Orphans - Reader Badge';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-admin---cleanup';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['orphans_reader_badge'] = $view;

  $view = new view();
  $view->name = 'orphans_reader_prizes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_reader_prize';
  $view->human_name = 'Orphans - Reader Prizes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Orphans - Reader Prizes';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_current_reader_prizes_reader']['id'] = 'reverse_field_current_reader_prizes_reader';
  $handler->display->display_options['relationships']['reverse_field_current_reader_prizes_reader']['table'] = 'eck_reader_prize';
  $handler->display->display_options['relationships']['reverse_field_current_reader_prizes_reader']['field'] = 'reverse_field_current_reader_prizes_reader';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_prize_reference_target_id']['id'] = 'field_prize_reference_target_id';
  $handler->display->display_options['relationships']['field_prize_reference_target_id']['table'] = 'field_data_field_prize_reference';
  $handler->display->display_options['relationships']['field_prize_reference_target_id']['field'] = 'field_prize_reference_target_id';
  /* Field: Bulk operations: Reader Prize */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'eck_reader_prize';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Reader Prize: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reader_prize';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Reader Prize: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_reader_prize';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Field: Readers */
  $handler->display->display_options['fields']['field_readers']['id'] = 'field_readers';
  $handler->display->display_options['fields']['field_readers']['table'] = 'field_data_field_readers';
  $handler->display->display_options['fields']['field_readers']['field'] = 'field_readers';
  $handler->display->display_options['fields']['field_readers']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_readers']['delta_offset'] = '0';
  /* Field: Field: Prize Reference */
  $handler->display->display_options['fields']['field_prize_reference']['id'] = 'field_prize_reference';
  $handler->display->display_options['fields']['field_prize_reference']['table'] = 'field_data_field_prize_reference';
  $handler->display->display_options['fields']['field_prize_reference']['field'] = 'field_prize_reference';
  $handler->display->display_options['fields']['field_prize_reference']['settings'] = array(
    'link' => 1,
  );
  /* Filter criterion: Field: Readers (field_readers) */
  $handler->display->display_options['filters']['field_readers_target_id']['id'] = 'field_readers_target_id';
  $handler->display->display_options['filters']['field_readers_target_id']['table'] = 'field_data_field_readers';
  $handler->display->display_options['filters']['field_readers_target_id']['field'] = 'field_readers_target_id';
  $handler->display->display_options['filters']['field_readers_target_id']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_readers_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_readers_target_id']['expose']['operator_id'] = 'field_readers_target_id_op';
  $handler->display->display_options['filters']['field_readers_target_id']['expose']['label'] = 'Readers (field_readers)';
  $handler->display->display_options['filters']['field_readers_target_id']['expose']['description'] = '(admin only!)';
  $handler->display->display_options['filters']['field_readers_target_id']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_readers_target_id']['expose']['operator'] = 'field_readers_target_id_op';
  $handler->display->display_options['filters']['field_readers_target_id']['expose']['identifier'] = 'field_readers_target_id';
  $handler->display->display_options['filters']['field_readers_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'library/admin/orphans-reader-prizes';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Orphans - Reader Prizes';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-admin---cleanup';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['orphans_reader_prizes'] = $view;

  $view = new view();
  $view->name = 'orphans_reading_log';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_reading_log';
  $view->human_name = 'Orphans - Reading Log';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Orphans - Reading Log';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_readers_target_id']['id'] = 'field_readers_target_id';
  $handler->display->display_options['relationships']['field_readers_target_id']['table'] = 'field_data_field_readers';
  $handler->display->display_options['relationships']['field_readers_target_id']['field'] = 'field_readers_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_program_reference_target_id']['id'] = 'field_program_reference_target_id';
  $handler->display->display_options['relationships']['field_program_reference_target_id']['table'] = 'field_data_field_program_reference';
  $handler->display->display_options['relationships']['field_program_reference_target_id']['field'] = 'field_program_reference_target_id';
  /* Field: Bulk operations: Reading Log */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'eck_reading_log';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Reading Log: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reading_log';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Field: Readers */
  $handler->display->display_options['fields']['field_readers']['id'] = 'field_readers';
  $handler->display->display_options['fields']['field_readers']['table'] = 'field_data_field_readers';
  $handler->display->display_options['fields']['field_readers']['field'] = 'field_readers';
  $handler->display->display_options['fields']['field_readers']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_readers']['delta_offset'] = '0';
  /* Field: Reading Log: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_reading_log';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Field: Program Reference */
  $handler->display->display_options['fields']['field_program_reference']['id'] = 'field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['table'] = 'field_data_field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['field'] = 'field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_program_reference']['delta_offset'] = '0';
  /* Field: Field: Unit Type */
  $handler->display->display_options['fields']['field_unit_type']['id'] = 'field_unit_type';
  $handler->display->display_options['fields']['field_unit_type']['table'] = 'field_data_field_unit_type';
  $handler->display->display_options['fields']['field_unit_type']['field'] = 'field_unit_type';
  /* Field: Field: Units Completed */
  $handler->display->display_options['fields']['field_units_completed']['id'] = 'field_units_completed';
  $handler->display->display_options['fields']['field_units_completed']['table'] = 'field_data_field_units_completed';
  $handler->display->display_options['fields']['field_units_completed']['field'] = 'field_units_completed';
  $handler->display->display_options['fields']['field_units_completed']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Filter criterion: Field: Readers (field_readers) */
  $handler->display->display_options['filters']['field_readers_target_id']['id'] = 'field_readers_target_id';
  $handler->display->display_options['filters']['field_readers_target_id']['table'] = 'field_data_field_readers';
  $handler->display->display_options['filters']['field_readers_target_id']['field'] = 'field_readers_target_id';
  $handler->display->display_options['filters']['field_readers_target_id']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_readers_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_readers_target_id']['expose']['operator_id'] = 'field_readers_target_id_op';
  $handler->display->display_options['filters']['field_readers_target_id']['expose']['label'] = 'Readers (field_readers)';
  $handler->display->display_options['filters']['field_readers_target_id']['expose']['description'] = '(admin only!)';
  $handler->display->display_options['filters']['field_readers_target_id']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_readers_target_id']['expose']['operator'] = 'field_readers_target_id_op';
  $handler->display->display_options['filters']['field_readers_target_id']['expose']['identifier'] = 'field_readers_target_id';
  $handler->display->display_options['filters']['field_readers_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'library/admin/orphans-reading-log';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Orphans - Reading Log Entries';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-admin---cleanup';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['orphans_reading_log'] = $view;

  return $export;
}
