<?php
/**
 * @file
 * bp_reports13.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function bp_reports13_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'report_base_activity_logs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_activity_log';
  $view->human_name = 'Report Base - Activity Logs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Report Base - Activity Logs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'title' => 'title',
    'title_1' => 'title_1',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = 'id';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
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
  $handler->display->display_options['header']['area']['content'] = 'This report displays a list of activities/codes and the number of times each was claimed.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_readers_target_id']['id'] = 'field_readers_target_id';
  $handler->display->display_options['relationships']['field_readers_target_id']['table'] = 'field_data_field_readers';
  $handler->display->display_options['relationships']['field_readers_target_id']['field'] = 'field_readers_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_secret_code_reference_target_id']['id'] = 'field_secret_code_reference_target_id';
  $handler->display->display_options['relationships']['field_secret_code_reference_target_id']['table'] = 'field_data_field_secret_code_reference';
  $handler->display->display_options['relationships']['field_secret_code_reference_target_id']['field'] = 'field_secret_code_reference_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_activity_reference_target_id']['id'] = 'field_activity_reference_target_id';
  $handler->display->display_options['relationships']['field_activity_reference_target_id']['table'] = 'field_data_field_activity_reference';
  $handler->display->display_options['relationships']['field_activity_reference_target_id']['field'] = 'field_activity_reference_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['id'] = 'field_parent_uid_target_id';
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['table'] = 'field_data_field_parent_uid';
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['field'] = 'field_parent_uid_target_id';
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['relationship'] = 'field_readers_target_id';
  /* Field: COUNT(Activity Log: Id) */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_activity_log';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['group_type'] = 'count';
  $handler->display->display_options['fields']['id']['label'] = '#';
  /* Field: Activity: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_activity';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_secret_code_reference_target_id';
  $handler->display->display_options['fields']['title']['label'] = 'Code Title (hidden)';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  /* Field: Activity: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'eck_activity';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_activity_reference_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Activity Title (hidden)';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Activity/Code:';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[title][title_1]';
  /* Filter criterion: Activity: Title */
  $handler->display->display_options['filters']['title_1']['id'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['table'] = 'eck_activity';
  $handler->display->display_options['filters']['title_1']['field'] = 'title';
  $handler->display->display_options['filters']['title_1']['relationship'] = 'field_activity_reference_target_id';
  $handler->display->display_options['filters']['title_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_1']['group'] = 1;
  $handler->display->display_options['filters']['title_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_1']['expose']['operator_id'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['label'] = 'Activity:';
  $handler->display->display_options['filters']['title_1']['expose']['description'] = '(type name of activity)';
  $handler->display->display_options['filters']['title_1']['expose']['operator'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['identifier'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Activity: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'eck_activity';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_secret_code_reference_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Code:';
  $handler->display->display_options['filters']['title']['expose']['description'] = '(type name of code activity)';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Field: Program (field_program) */
  $handler->display->display_options['filters']['field_program_target_id']['id'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['table'] = 'field_data_field_program';
  $handler->display->display_options['filters']['field_program_target_id']['field'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['relationship'] = 'field_readers_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_target_id']['expose']['operator_id'] = 'field_program_target_id_op';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['label'] = 'Program';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['operator'] = 'field_program_target_id_op';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['identifier'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: User: Favorite Branch (field_favorite_branch) */
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['id'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['table'] = 'field_data_field_favorite_branch';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['field'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['relationship'] = 'field_parent_uid_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['operator_id'] = 'field_favorite_branch_target_id_op';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['label'] = 'Branch';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['operator'] = 'field_favorite_branch_target_id_op';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['identifier'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'library/reports/activities/base';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Report Base - Activity Logs';
  $handler->display->display_options['menu']['name'] = 'menu-reports-menu';
  $export['report_base_activity_logs'] = $view;

  $view = new view();
  $view->name = 'report_base_badges_earned';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_reader_badge';
  $view->human_name = 'Report Base - Badges Earned';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Report Base - Badges Earned';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_program',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'field_reader_badge' => 'field_reader_badge',
    'field_program' => 'field_program',
  );
  $handler->display->display_options['style_options']['default'] = 'id';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_reader_badge' => array(
      'sortable' => 1,
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
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_readers_target_id']['id'] = 'field_readers_target_id';
  $handler->display->display_options['relationships']['field_readers_target_id']['table'] = 'field_data_field_readers';
  $handler->display->display_options['relationships']['field_readers_target_id']['field'] = 'field_readers_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reader_badge_target_id']['id'] = 'field_reader_badge_target_id';
  $handler->display->display_options['relationships']['field_reader_badge_target_id']['table'] = 'field_data_field_reader_badge';
  $handler->display->display_options['relationships']['field_reader_badge_target_id']['field'] = 'field_reader_badge_target_id';
  /* Field: COUNT(Reader Badge: Id) */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reader_badge';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['group_type'] = 'count';
  $handler->display->display_options['fields']['id']['label'] = '#';
  /* Field: Field: Reader Badge */
  $handler->display->display_options['fields']['field_reader_badge']['id'] = 'field_reader_badge';
  $handler->display->display_options['fields']['field_reader_badge']['table'] = 'field_data_field_reader_badge';
  $handler->display->display_options['fields']['field_reader_badge']['field'] = 'field_reader_badge';
  $handler->display->display_options['fields']['field_reader_badge']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field: Program */
  $handler->display->display_options['fields']['field_program']['id'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['table'] = 'field_data_field_program';
  $handler->display->display_options['fields']['field_program']['field'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['relationship'] = 'field_readers_target_id';
  $handler->display->display_options['fields']['field_program']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_program']['delta_offset'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Badges Earned by Program';
  $handler->display->display_options['path'] = 'library/reports/badges/base';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Badges Earned by Program';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['name'] = 'menu-reports-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Badges Reports';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'menu-reports-menu';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Badge Winners';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'field_reader_badge' => 'field_reader_badge',
    'field_program' => 'field_program',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
  );
  $handler->display->display_options['style_options']['default'] = 'field_reader_badge';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_reader_badge' => array(
      'sortable' => 1,
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
    'field_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Reader Badge: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reader_badge';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = 'Earned Badge Ref #';
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Field: Reader Badge */
  $handler->display->display_options['fields']['field_reader_badge']['id'] = 'field_reader_badge';
  $handler->display->display_options['fields']['field_reader_badge']['table'] = 'field_data_field_reader_badge';
  $handler->display->display_options['fields']['field_reader_badge']['field'] = 'field_reader_badge';
  $handler->display->display_options['fields']['field_reader_badge']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field: Program */
  $handler->display->display_options['fields']['field_program']['id'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['table'] = 'field_data_field_program';
  $handler->display->display_options['fields']['field_program']['field'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['relationship'] = 'field_readers_target_id';
  $handler->display->display_options['fields']['field_program']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_program']['delta_offset'] = '0';
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
  /* Field: Reader: Link */
  $handler->display->display_options['fields']['view_link']['id'] = 'view_link';
  $handler->display->display_options['fields']['view_link']['table'] = 'eck_reader';
  $handler->display->display_options['fields']['view_link']['field'] = 'view_link';
  $handler->display->display_options['fields']['view_link']['relationship'] = 'field_readers_target_id';
  $handler->display->display_options['fields']['view_link']['label'] = 'View Reader';
  $handler->display->display_options['fields']['view_link']['text'] = 'view reader';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Field: Program (field_program) */
  $handler->display->display_options['filters']['field_program_target_id']['id'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['table'] = 'field_data_field_program';
  $handler->display->display_options['filters']['field_program_target_id']['field'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['relationship'] = 'field_readers_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_target_id']['expose']['operator_id'] = 'field_program_target_id_op';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['label'] = 'Program';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['description'] = ' (use ctrl-click or cmd-click to select multiple)';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['operator'] = 'field_program_target_id_op';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['identifier'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_program_target_id']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Badge Name';
  $handler->display->display_options['filters']['title']['expose']['description'] = '(enter badge name exactly)';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['path'] = 'library/reports/badges/winners';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Readers\' Badges';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Page 2 */
  $handler = $view->new_display('page', 'Page 2', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Badges - Total Earned';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'field_reader_badge' => 'field_reader_badge',
  );
  $handler->display->display_options['style_options']['default'] = 'id';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_reader_badge' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(Reader Badge: Id) */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reader_badge';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['group_type'] = 'count';
  $handler->display->display_options['fields']['id']['label'] = '#';
  /* Field: Field: Reader Badge */
  $handler->display->display_options['fields']['field_reader_badge']['id'] = 'field_reader_badge';
  $handler->display->display_options['fields']['field_reader_badge']['table'] = 'field_data_field_reader_badge';
  $handler->display->display_options['fields']['field_reader_badge']['field'] = 'field_reader_badge';
  $handler->display->display_options['fields']['field_reader_badge']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['path'] = 'library/reports/badges/totals';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Badge Totals';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-reports-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['report_base_badges_earned'] = $view;

  $view = new view();
  $view->name = 'report_base_points';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_reader';
  $view->human_name = 'Report Base - Points';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Readers\' Points';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'This is a list of users and their total points.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['id'] = 'field_parent_uid_target_id';
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['table'] = 'field_data_field_parent_uid';
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['field'] = 'field_parent_uid_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_favorite_branch_target_id']['id'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['relationships']['field_favorite_branch_target_id']['table'] = 'field_data_field_favorite_branch';
  $handler->display->display_options['relationships']['field_favorite_branch_target_id']['field'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['relationships']['field_favorite_branch_target_id']['relationship'] = 'field_parent_uid_target_id';
  /* Field: Reader: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reader';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Reader: Current Points */
  $handler->display->display_options['fields']['field_current_points']['id'] = 'field_current_points';
  $handler->display->display_options['fields']['field_current_points']['table'] = 'field_data_field_current_points';
  $handler->display->display_options['fields']['field_current_points']['field'] = 'field_current_points';
  $handler->display->display_options['fields']['field_current_points']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  /* Field: Reader: Link */
  $handler->display->display_options['fields']['view_link']['id'] = 'view_link';
  $handler->display->display_options['fields']['view_link']['table'] = 'eck_reader';
  $handler->display->display_options['fields']['view_link']['field'] = 'view_link';
  $handler->display->display_options['fields']['view_link']['label'] = 'View Reader';
  $handler->display->display_options['fields']['view_link']['text'] = 'View Reader';
  /* Field: Reader: Parent UID */
  $handler->display->display_options['fields']['field_parent_uid']['id'] = 'field_parent_uid';
  $handler->display->display_options['fields']['field_parent_uid']['table'] = 'field_data_field_parent_uid';
  $handler->display->display_options['fields']['field_parent_uid']['field'] = 'field_parent_uid';
  $handler->display->display_options['fields']['field_parent_uid']['label'] = 'Parent';
  $handler->display->display_options['fields']['field_parent_uid']['settings'] = array(
    'link' => 1,
  );
  /* Field: Field: Program */
  $handler->display->display_options['fields']['field_program']['id'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['table'] = 'field_data_field_program';
  $handler->display->display_options['fields']['field_program']['field'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_program']['delta_offset'] = '0';
  /* Field: Branch: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_branch';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['fields']['title']['label'] = 'Branch';
  /* Sort criterion: Reader: Current Points (field_current_points) */
  $handler->display->display_options['sorts']['field_current_points_value']['id'] = 'field_current_points_value';
  $handler->display->display_options['sorts']['field_current_points_value']['table'] = 'field_data_field_current_points';
  $handler->display->display_options['sorts']['field_current_points_value']['field'] = 'field_current_points_value';
  $handler->display->display_options['sorts']['field_current_points_value']['order'] = 'DESC';
  /* Filter criterion: Field: Program (field_program) */
  $handler->display->display_options['filters']['field_program_target_id']['id'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['table'] = 'field_data_field_program';
  $handler->display->display_options['filters']['field_program_target_id']['field'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_program_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_target_id']['expose']['operator_id'] = 'field_program_target_id_op';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['label'] = 'Program';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['operator'] = 'field_program_target_id_op';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['identifier'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_program_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: User: Favorite Branch (field_favorite_branch) */
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['id'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['table'] = 'field_data_field_favorite_branch';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['field'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['relationship'] = 'field_parent_uid_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['operator_id'] = 'field_favorite_branch_target_id_op';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['label'] = 'Favorite Branch';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['operator'] = 'field_favorite_branch_target_id_op';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['identifier'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'library/reports/points-base';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Report Base - Points';
  $handler->display->display_options['menu']['name'] = 'menu-reports-menu';
  $export['report_base_points'] = $view;

  $view = new view();
  $view->name = 'report_base_prizes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_reader_prize';
  $view->human_name = 'Report Base - Prizes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Report Base - Prizes';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_readers_target_id']['id'] = 'field_readers_target_id';
  $handler->display->display_options['relationships']['field_readers_target_id']['table'] = 'field_data_field_readers';
  $handler->display->display_options['relationships']['field_readers_target_id']['field'] = 'field_readers_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_prize_reference_target_id']['id'] = 'field_prize_reference_target_id';
  $handler->display->display_options['relationships']['field_prize_reference_target_id']['table'] = 'field_data_field_prize_reference';
  $handler->display->display_options['relationships']['field_prize_reference_target_id']['field'] = 'field_prize_reference_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['id'] = 'field_parent_uid_target_id';
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['table'] = 'field_data_field_parent_uid';
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['field'] = 'field_parent_uid_target_id';
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['relationship'] = 'field_readers_target_id';
  /* Field: Reader Prize: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reader_prize';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['group_type'] = 'count';
  $handler->display->display_options['fields']['id']['label'] = 'Prize Win Ref. #';
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Prize: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_prize';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_prize_reference_target_id';
  $handler->display->display_options['fields']['title']['label'] = 'Prize';
  /* Field: User: Favorite Branch */
  $handler->display->display_options['fields']['field_favorite_branch']['id'] = 'field_favorite_branch';
  $handler->display->display_options['fields']['field_favorite_branch']['table'] = 'field_data_field_favorite_branch';
  $handler->display->display_options['fields']['field_favorite_branch']['field'] = 'field_favorite_branch';
  $handler->display->display_options['fields']['field_favorite_branch']['relationship'] = 'field_parent_uid_target_id';
  $handler->display->display_options['fields']['field_favorite_branch']['label'] = 'Branch';
  $handler->display->display_options['fields']['field_favorite_branch']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field: Program Reference */
  $handler->display->display_options['fields']['field_program_reference']['id'] = 'field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['table'] = 'field_data_field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['field'] = 'field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_program_reference']['delta_offset'] = '0';
  /* Field: Reader Prize: Status */
  $handler->display->display_options['fields']['field_status']['id'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['table'] = 'field_data_field_status';
  $handler->display->display_options['fields']['field_status']['field'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['label'] = 'Claim Status';
  /* Filter criterion: Prize: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'eck_prize';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_prize_reference_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Prize';
  $handler->display->display_options['filters']['title']['expose']['description'] = '(type name of prize)';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: User: Favorite Branch (field_favorite_branch) */
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['id'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['table'] = 'field_data_field_favorite_branch';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['field'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['relationship'] = 'field_parent_uid_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['operator_id'] = 'field_favorite_branch_target_id_op';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['label'] = 'Branch';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['operator'] = 'field_favorite_branch_target_id_op';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['identifier'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Field: Program (field_program) */
  $handler->display->display_options['filters']['field_program_target_id']['id'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['table'] = 'field_data_field_program';
  $handler->display->display_options['filters']['field_program_target_id']['field'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['relationship'] = 'field_readers_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_target_id']['expose']['operator_id'] = 'field_program_target_id_op';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['label'] = 'Program';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['operator'] = 'field_program_target_id_op';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['identifier'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Reader Prize: Status (field_status) */
  $handler->display->display_options['filters']['field_status_value']['id'] = 'field_status_value';
  $handler->display->display_options['filters']['field_status_value']['table'] = 'field_data_field_status';
  $handler->display->display_options['filters']['field_status_value']['field'] = 'field_status_value';
  $handler->display->display_options['filters']['field_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_status_value']['expose']['operator_id'] = 'field_status_value_op';
  $handler->display->display_options['filters']['field_status_value']['expose']['label'] = 'Prize Status';
  $handler->display->display_options['filters']['field_status_value']['expose']['description'] = '(use ctrl-click or cmd-click to select multiple)';
  $handler->display->display_options['filters']['field_status_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_status_value']['expose']['operator'] = 'field_status_value_op';
  $handler->display->display_options['filters']['field_status_value']['expose']['identifier'] = 'field_status_value';
  $handler->display->display_options['filters']['field_status_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'library/reports/prizes/base';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Report Base - Prizes';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['name'] = 'menu-reports-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Prize Reports';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'menu-reports-menu';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Prize Winners';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Reader Prize: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reader_prize';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = 'Prize Win Ref. #';
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Prize: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_prize';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_prize_reference_target_id';
  $handler->display->display_options['fields']['title']['label'] = 'Prize';
  /* Field: Reader Prize: Status */
  $handler->display->display_options['fields']['field_status']['id'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['table'] = 'field_data_field_status';
  $handler->display->display_options['fields']['field_status']['field'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['label'] = 'Claim Status';
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
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_parent_uid_target_id';
  /* Field: User: Favorite Branch */
  $handler->display->display_options['fields']['field_favorite_branch']['id'] = 'field_favorite_branch';
  $handler->display->display_options['fields']['field_favorite_branch']['table'] = 'field_data_field_favorite_branch';
  $handler->display->display_options['fields']['field_favorite_branch']['field'] = 'field_favorite_branch';
  $handler->display->display_options['fields']['field_favorite_branch']['relationship'] = 'field_parent_uid_target_id';
  $handler->display->display_options['fields']['field_favorite_branch']['label'] = 'Branch';
  $handler->display->display_options['fields']['field_favorite_branch']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field: Program Reference */
  $handler->display->display_options['fields']['field_program_reference']['id'] = 'field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['table'] = 'field_data_field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['field'] = 'field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_program_reference']['delta_offset'] = '0';
  $handler->display->display_options['path'] = 'library/reports/prizes/readers';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Prize Winners';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Page 2 */
  $handler = $view->new_display('page', 'Page 2', 'page_2');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'title' => 'title',
    'field_favorite_branch' => 'field_favorite_branch',
    'field_program_reference' => 'field_program_reference',
    'field_status' => 'field_status',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'field_favorite_branch' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'field_program_reference' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'field_status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
  );
  $handler->display->display_options['style_options']['column_aggregation']['totals_per_page'] = '1';
  $handler->display->display_options['style_options']['column_aggregation']['totals_row_position'] = array(
    1 => 0,
    2 => '2',
  );
  $handler->display->display_options['style_options']['column_aggregation']['precision'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'library/reports/prizes/summary';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Prize Summary';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Prize Reports';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'menu-reports-menu';
  $export['report_base_prizes'] = $view;

  $view = new view();
  $view->name = 'report_base_readers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_reader';
  $view->human_name = 'Report Base - Readers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Report Base - Readers';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'field_favorite_branch' => 'field_favorite_branch',
    'field_program' => 'field_program',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'field_favorite_branch' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'field_program' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
  );
  $handler->display->display_options['style_options']['column_aggregation']['totals_per_page'] = '1';
  $handler->display->display_options['style_options']['column_aggregation']['totals_row_position'] = array(
    1 => 0,
    2 => '2',
  );
  $handler->display->display_options['style_options']['column_aggregation']['precision'] = '2';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reader_school_target_id']['id'] = 'field_reader_school_target_id';
  $handler->display->display_options['relationships']['field_reader_school_target_id']['table'] = 'field_data_field_reader_school';
  $handler->display->display_options['relationships']['field_reader_school_target_id']['field'] = 'field_reader_school_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_program_target_id']['id'] = 'field_program_target_id';
  $handler->display->display_options['relationships']['field_program_target_id']['table'] = 'field_data_field_program';
  $handler->display->display_options['relationships']['field_program_target_id']['field'] = 'field_program_target_id';
  /* Field: Reader: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reader';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Field: Program */
  $handler->display->display_options['fields']['field_program']['id'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['table'] = 'field_data_field_program';
  $handler->display->display_options['fields']['field_program']['field'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_program']['delta_offset'] = '0';
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
  /* Field: Reader: Current Points */
  $handler->display->display_options['fields']['field_current_points']['id'] = 'field_current_points';
  $handler->display->display_options['fields']['field_current_points']['table'] = 'field_data_field_current_points';
  $handler->display->display_options['fields']['field_current_points']['field'] = 'field_current_points';
  $handler->display->display_options['fields']['field_current_points']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Filter criterion: Reader: Age (field_age) */
  $handler->display->display_options['filters']['field_age_value']['id'] = 'field_age_value';
  $handler->display->display_options['filters']['field_age_value']['table'] = 'field_data_field_age';
  $handler->display->display_options['filters']['field_age_value']['field'] = 'field_age_value';
  $handler->display->display_options['filters']['field_age_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_age_value']['group'] = 1;
  $handler->display->display_options['filters']['field_age_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_age_value']['expose']['operator_id'] = 'field_age_value_op';
  $handler->display->display_options['filters']['field_age_value']['expose']['label'] = 'Age';
  $handler->display->display_options['filters']['field_age_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_age_value']['expose']['operator'] = 'field_age_value_op';
  $handler->display->display_options['filters']['field_age_value']['expose']['identifier'] = 'field_age_value';
  $handler->display->display_options['filters']['field_age_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Reader: Grade (field_grade) */
  $handler->display->display_options['filters']['field_grade_value']['id'] = 'field_grade_value';
  $handler->display->display_options['filters']['field_grade_value']['table'] = 'field_data_field_grade';
  $handler->display->display_options['filters']['field_grade_value']['field'] = 'field_grade_value';
  $handler->display->display_options['filters']['field_grade_value']['group'] = 1;
  $handler->display->display_options['filters']['field_grade_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_grade_value']['expose']['operator_id'] = 'field_grade_value_op';
  $handler->display->display_options['filters']['field_grade_value']['expose']['label'] = 'Grade';
  $handler->display->display_options['filters']['field_grade_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_grade_value']['expose']['operator'] = 'field_grade_value_op';
  $handler->display->display_options['filters']['field_grade_value']['expose']['identifier'] = 'field_grade_value';
  $handler->display->display_options['filters']['field_grade_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_grade_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: School: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'eck_school';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_reader_school_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'School';
  $handler->display->display_options['filters']['title']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: User: Favorite Branch (field_favorite_branch) */
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['id'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['table'] = 'field_data_field_favorite_branch';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['field'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['relationship'] = 'field_parent_uid_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['operator_id'] = 'field_favorite_branch_target_id_op';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['label'] = 'Favorite Branch';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['operator'] = 'field_favorite_branch_target_id_op';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['identifier'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Base */
  $handler = $view->new_display('page', 'Base', 'page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'field_program' => 'field_program',
    'field_age' => 'field_age',
    'field_grade' => 'field_grade',
    'field_reader_school' => 'field_reader_school',
    'field_current_points' => 'field_current_points',
  );
  $handler->display->display_options['style_options']['default'] = 'id';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 1,
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
    'field_age' => array(
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
    'field_reader_school' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_current_points' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
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
  $handler->display->display_options['header']['area']['content'] = 'This report can be used to build a list of Readers based on certain criteria.  Use the orange "CSV" button at the bottom of the page to export your Reader list.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reader_school_target_id']['id'] = 'field_reader_school_target_id';
  $handler->display->display_options['relationships']['field_reader_school_target_id']['table'] = 'field_data_field_reader_school';
  $handler->display->display_options['relationships']['field_reader_school_target_id']['field'] = 'field_reader_school_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_program_target_id']['id'] = 'field_program_target_id';
  $handler->display->display_options['relationships']['field_program_target_id']['table'] = 'field_data_field_program';
  $handler->display->display_options['relationships']['field_program_target_id']['field'] = 'field_program_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['id'] = 'field_parent_uid_target_id';
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['table'] = 'field_data_field_parent_uid';
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['field'] = 'field_parent_uid_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Reader: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reader';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = 'Reader ID';
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Field: Program */
  $handler->display->display_options['fields']['field_program']['id'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['table'] = 'field_data_field_program';
  $handler->display->display_options['fields']['field_program']['field'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_program']['delta_offset'] = '0';
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
  $handler->display->display_options['fields']['field_reader_school']['label'] = 'School';
  $handler->display->display_options['fields']['field_reader_school']['settings'] = array(
    'link' => 0,
  );
  /* Field: User: Favorite Branch */
  $handler->display->display_options['fields']['field_favorite_branch']['id'] = 'field_favorite_branch';
  $handler->display->display_options['fields']['field_favorite_branch']['table'] = 'field_data_field_favorite_branch';
  $handler->display->display_options['fields']['field_favorite_branch']['field'] = 'field_favorite_branch';
  $handler->display->display_options['fields']['field_favorite_branch']['relationship'] = 'field_parent_uid_target_id';
  $handler->display->display_options['fields']['field_favorite_branch']['label'] = 'Branch';
  $handler->display->display_options['fields']['field_favorite_branch']['settings'] = array(
    'link' => 0,
  );
  /* Field: Reader: Current Points */
  $handler->display->display_options['fields']['field_current_points']['id'] = 'field_current_points';
  $handler->display->display_options['fields']['field_current_points']['table'] = 'field_data_field_current_points';
  $handler->display->display_options['fields']['field_current_points']['field'] = 'field_current_points';
  $handler->display->display_options['fields']['field_current_points']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = 'Reader First';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = 'Reader Last';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name_1']['id'] = 'field_first_name_1';
  $handler->display->display_options['fields']['field_first_name_1']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name_1']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name_1']['relationship'] = 'field_parent_uid_target_id';
  $handler->display->display_options['fields']['field_first_name_1']['label'] = 'Parent First';
  $handler->display->display_options['fields']['field_first_name_1']['exclude'] = TRUE;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name_1']['id'] = 'field_last_name_1';
  $handler->display->display_options['fields']['field_last_name_1']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name_1']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name_1']['label'] = 'Parent Last';
  $handler->display->display_options['fields']['field_last_name_1']['exclude'] = TRUE;
  /* Field: Reader: Link */
  $handler->display->display_options['fields']['view_link']['id'] = 'view_link';
  $handler->display->display_options['fields']['view_link']['table'] = 'eck_reader';
  $handler->display->display_options['fields']['view_link']['field'] = 'view_link';
  $handler->display->display_options['fields']['view_link']['label'] = 'Reader';
  $handler->display->display_options['fields']['view_link']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_link']['alter']['text'] = '[field_first_name] [field_last_name]';
  $handler->display->display_options['fields']['view_link']['alter']['make_link'] = TRUE;
  /* Field: User: Link */
  $handler->display->display_options['fields']['view_user']['id'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['table'] = 'users';
  $handler->display->display_options['fields']['view_user']['field'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['relationship'] = 'field_parent_uid_target_id';
  $handler->display->display_options['fields']['view_user']['label'] = 'Parent User';
  $handler->display->display_options['fields']['view_user']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_user']['alter']['text'] = '[field_first_name_1] [field_last_name_1]';
  $handler->display->display_options['fields']['view_user']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['view_user']['alter']['path'] = '[view_user]';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Reader: Age (field_age) */
  $handler->display->display_options['filters']['field_age_value']['id'] = 'field_age_value';
  $handler->display->display_options['filters']['field_age_value']['table'] = 'field_data_field_age';
  $handler->display->display_options['filters']['field_age_value']['field'] = 'field_age_value';
  $handler->display->display_options['filters']['field_age_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_age_value']['group'] = 1;
  $handler->display->display_options['filters']['field_age_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_age_value']['expose']['operator_id'] = 'field_age_value_op';
  $handler->display->display_options['filters']['field_age_value']['expose']['label'] = 'Age';
  $handler->display->display_options['filters']['field_age_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_age_value']['expose']['operator'] = 'field_age_value_op';
  $handler->display->display_options['filters']['field_age_value']['expose']['identifier'] = 'field_age_value';
  $handler->display->display_options['filters']['field_age_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Reader: Grade (field_grade) */
  $handler->display->display_options['filters']['field_grade_value']['id'] = 'field_grade_value';
  $handler->display->display_options['filters']['field_grade_value']['table'] = 'field_data_field_grade';
  $handler->display->display_options['filters']['field_grade_value']['field'] = 'field_grade_value';
  $handler->display->display_options['filters']['field_grade_value']['group'] = 1;
  $handler->display->display_options['filters']['field_grade_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_grade_value']['expose']['operator_id'] = 'field_grade_value_op';
  $handler->display->display_options['filters']['field_grade_value']['expose']['label'] = 'Grade';
  $handler->display->display_options['filters']['field_grade_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_grade_value']['expose']['operator'] = 'field_grade_value_op';
  $handler->display->display_options['filters']['field_grade_value']['expose']['identifier'] = 'field_grade_value';
  $handler->display->display_options['filters']['field_grade_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_grade_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: School: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'eck_school';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_reader_school_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'School';
  $handler->display->display_options['filters']['title']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: User: Favorite Branch (field_favorite_branch) */
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['id'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['table'] = 'field_data_field_favorite_branch';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['field'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['relationship'] = 'field_parent_uid_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['operator_id'] = 'field_favorite_branch_target_id_op';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['label'] = 'Favorite Branch';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['operator'] = 'field_favorite_branch_target_id_op';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['identifier'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Reader: Current Points (field_current_points) */
  $handler->display->display_options['filters']['field_current_points_value']['id'] = 'field_current_points_value';
  $handler->display->display_options['filters']['field_current_points_value']['table'] = 'field_data_field_current_points';
  $handler->display->display_options['filters']['field_current_points_value']['field'] = 'field_current_points_value';
  $handler->display->display_options['filters']['field_current_points_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_current_points_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_current_points_value']['expose']['operator_id'] = 'field_current_points_value_op';
  $handler->display->display_options['filters']['field_current_points_value']['expose']['label'] = 'Current Points';
  $handler->display->display_options['filters']['field_current_points_value']['expose']['description'] = '(enter # of points without comma, e.g., 5000)';
  $handler->display->display_options['filters']['field_current_points_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_current_points_value']['expose']['operator'] = 'field_current_points_value_op';
  $handler->display->display_options['filters']['field_current_points_value']['expose']['identifier'] = 'field_current_points_value';
  $handler->display->display_options['filters']['field_current_points_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Field: Program (field_program) */
  $handler->display->display_options['filters']['field_program_target_id']['id'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['table'] = 'field_data_field_program';
  $handler->display->display_options['filters']['field_program_target_id']['field'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_target_id']['expose']['operator_id'] = 'field_program_target_id_op';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['label'] = 'Program';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['description'] = '(use ctrl-click or cmd-click to select multiple)';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['operator'] = 'field_program_target_id_op';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['identifier'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_program_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['path'] = 'library/reports/readers/base';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Reader Reports';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Reader Reports';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'menu-reports-menu';

  /* Display: Age */
  $handler = $view->new_display('page', 'Age', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Readers Report: Age Breakdown';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_program' => 'field_program',
    'field_age' => 'field_age',
    'id' => 'id',
  );
  $handler->display->display_options['style_options']['default'] = 'field_age';
  $handler->display->display_options['style_options']['info'] = array(
    'field_program' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_age' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'id' => array(
      'sortable' => 1,
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
  $handler->display->display_options['header']['area']['content'] = 'This report provides a breakdown of Readers by Age.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Program */
  $handler->display->display_options['fields']['field_program']['id'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['table'] = 'field_data_field_program';
  $handler->display->display_options['fields']['field_program']['field'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_program']['delta_offset'] = '0';
  /* Field: Reader: Age */
  $handler->display->display_options['fields']['field_age']['id'] = 'field_age';
  $handler->display->display_options['fields']['field_age']['table'] = 'field_data_field_age';
  $handler->display->display_options['fields']['field_age']['field'] = 'field_age';
  $handler->display->display_options['fields']['field_age']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Reader: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reader';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['group_type'] = 'count';
  $handler->display->display_options['fields']['id']['label'] = '# of Readers';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Reader: Age (field_age) */
  $handler->display->display_options['filters']['field_age_value']['id'] = 'field_age_value';
  $handler->display->display_options['filters']['field_age_value']['table'] = 'field_data_field_age';
  $handler->display->display_options['filters']['field_age_value']['field'] = 'field_age_value';
  $handler->display->display_options['filters']['field_age_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_age_value']['group'] = 1;
  $handler->display->display_options['filters']['field_age_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_age_value']['expose']['operator_id'] = 'field_age_value_op';
  $handler->display->display_options['filters']['field_age_value']['expose']['label'] = 'Age';
  $handler->display->display_options['filters']['field_age_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_age_value']['expose']['operator'] = 'field_age_value_op';
  $handler->display->display_options['filters']['field_age_value']['expose']['identifier'] = 'field_age_value';
  $handler->display->display_options['filters']['field_age_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Field: Program (field_program) */
  $handler->display->display_options['filters']['field_program_target_id']['id'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['table'] = 'field_data_field_program';
  $handler->display->display_options['filters']['field_program_target_id']['field'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_program_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_target_id']['expose']['operator_id'] = 'field_program_target_id_op';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['label'] = 'Program';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['description'] = '(use ctrl-click or cmd-click to select multiple)';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['operator'] = 'field_program_target_id_op';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['identifier'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_program_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['path'] = 'library/reports/readers/age';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Age';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Grade */
  $handler = $view->new_display('page', 'Grade', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Readers Report: Grade';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_program' => 'field_program',
    'field_age' => 'field_age',
    'id' => 'id',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_program' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_age' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'id' => array(
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
  $handler->display->display_options['header']['area']['content'] = 'This report provides a breakdown of Readers by Grade';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Program */
  $handler->display->display_options['fields']['field_program']['id'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['table'] = 'field_data_field_program';
  $handler->display->display_options['fields']['field_program']['field'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_program']['delta_offset'] = '0';
  /* Field: Reader: Grade */
  $handler->display->display_options['fields']['field_grade']['id'] = 'field_grade';
  $handler->display->display_options['fields']['field_grade']['table'] = 'field_data_field_grade';
  $handler->display->display_options['fields']['field_grade']['field'] = 'field_grade';
  /* Field: Reader: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reader';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['group_type'] = 'count';
  $handler->display->display_options['fields']['id']['label'] = '# of Readers';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Field: Program (field_program) */
  $handler->display->display_options['filters']['field_program_target_id']['id'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['table'] = 'field_data_field_program';
  $handler->display->display_options['filters']['field_program_target_id']['field'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_target_id']['expose']['operator_id'] = 'field_program_target_id_op';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['label'] = 'Program';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['description'] = '(use ctrl-click or cmd-click to select multiple)';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['operator'] = 'field_program_target_id_op';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['identifier'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_program_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Reader: Grade (field_grade) */
  $handler->display->display_options['filters']['field_grade_value']['id'] = 'field_grade_value';
  $handler->display->display_options['filters']['field_grade_value']['table'] = 'field_data_field_grade';
  $handler->display->display_options['filters']['field_grade_value']['field'] = 'field_grade_value';
  $handler->display->display_options['filters']['field_grade_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_grade_value']['expose']['operator_id'] = 'field_grade_value_op';
  $handler->display->display_options['filters']['field_grade_value']['expose']['label'] = 'Grade';
  $handler->display->display_options['filters']['field_grade_value']['expose']['description'] = '(use ctrl-click or cmd-click to select multiple)';
  $handler->display->display_options['filters']['field_grade_value']['expose']['operator'] = 'field_grade_value_op';
  $handler->display->display_options['filters']['field_grade_value']['expose']['identifier'] = 'field_grade_value';
  $handler->display->display_options['filters']['field_grade_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_grade_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['path'] = 'library/reports/readers/grade';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Grade';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: School */
  $handler = $view->new_display('page', 'School', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Readers - School';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'This report provides a breakdown of Readers by School.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Program */
  $handler->display->display_options['fields']['field_program']['id'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['table'] = 'field_data_field_program';
  $handler->display->display_options['fields']['field_program']['field'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_program']['delta_offset'] = '0';
  /* Field: Reader: Reader School */
  $handler->display->display_options['fields']['field_reader_school']['id'] = 'field_reader_school';
  $handler->display->display_options['fields']['field_reader_school']['table'] = 'field_data_field_reader_school';
  $handler->display->display_options['fields']['field_reader_school']['field'] = 'field_reader_school';
  $handler->display->display_options['fields']['field_reader_school']['settings'] = array(
    'link' => 0,
  );
  /* Field: Reader: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reader';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['group_type'] = 'count';
  $handler->display->display_options['fields']['id']['label'] = '# of Readers';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Reader: Age (field_age) */
  $handler->display->display_options['filters']['field_age_value']['id'] = 'field_age_value';
  $handler->display->display_options['filters']['field_age_value']['table'] = 'field_data_field_age';
  $handler->display->display_options['filters']['field_age_value']['field'] = 'field_age_value';
  $handler->display->display_options['filters']['field_age_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_age_value']['group'] = 1;
  $handler->display->display_options['filters']['field_age_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_age_value']['expose']['operator_id'] = 'field_age_value_op';
  $handler->display->display_options['filters']['field_age_value']['expose']['label'] = 'Age';
  $handler->display->display_options['filters']['field_age_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_age_value']['expose']['operator'] = 'field_age_value_op';
  $handler->display->display_options['filters']['field_age_value']['expose']['identifier'] = 'field_age_value';
  $handler->display->display_options['filters']['field_age_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Reader: Grade (field_grade) */
  $handler->display->display_options['filters']['field_grade_value']['id'] = 'field_grade_value';
  $handler->display->display_options['filters']['field_grade_value']['table'] = 'field_data_field_grade';
  $handler->display->display_options['filters']['field_grade_value']['field'] = 'field_grade_value';
  $handler->display->display_options['filters']['field_grade_value']['group'] = 1;
  $handler->display->display_options['filters']['field_grade_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_grade_value']['expose']['operator_id'] = 'field_grade_value_op';
  $handler->display->display_options['filters']['field_grade_value']['expose']['label'] = 'Grade';
  $handler->display->display_options['filters']['field_grade_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_grade_value']['expose']['operator'] = 'field_grade_value_op';
  $handler->display->display_options['filters']['field_grade_value']['expose']['identifier'] = 'field_grade_value';
  $handler->display->display_options['filters']['field_grade_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_grade_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: School: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'eck_school';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_reader_school_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'School';
  $handler->display->display_options['filters']['title']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Program: Title */
  $handler->display->display_options['filters']['title_1']['id'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['table'] = 'eck_program';
  $handler->display->display_options['filters']['title_1']['field'] = 'title';
  $handler->display->display_options['filters']['title_1']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['filters']['title_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_1']['expose']['operator_id'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['label'] = 'Program';
  $handler->display->display_options['filters']['title_1']['expose']['operator'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['identifier'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Field: Program (field_program) */
  $handler->display->display_options['filters']['field_program_target_id']['id'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['table'] = 'field_data_field_program';
  $handler->display->display_options['filters']['field_program_target_id']['field'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_target_id']['expose']['operator_id'] = 'field_program_target_id_op';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['label'] = 'Program';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['description'] = '(use ctrl-click or cmd-click to select multiples)';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['operator'] = 'field_program_target_id_op';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['identifier'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_program_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['path'] = 'library/reports/readers/school';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'School';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Branch */
  $handler = $view->new_display('page', 'Branch', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Report - Readers by Branch';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'This report provides a breakdown of Readers by parent User account\'s Favorite Branch.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['id'] = 'field_parent_uid_target_id';
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['table'] = 'field_data_field_parent_uid';
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['field'] = 'field_parent_uid_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_favorite_branch_target_id']['id'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['relationships']['field_favorite_branch_target_id']['table'] = 'field_data_field_favorite_branch';
  $handler->display->display_options['relationships']['field_favorite_branch_target_id']['field'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['relationships']['field_favorite_branch_target_id']['relationship'] = 'field_parent_uid_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_program_target_id']['id'] = 'field_program_target_id';
  $handler->display->display_options['relationships']['field_program_target_id']['table'] = 'field_data_field_program';
  $handler->display->display_options['relationships']['field_program_target_id']['field'] = 'field_program_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Reader: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reader';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['group_type'] = 'count';
  $handler->display->display_options['fields']['id']['label'] = '# of Readers';
  /* Field: User: Favorite Branch */
  $handler->display->display_options['fields']['field_favorite_branch']['id'] = 'field_favorite_branch';
  $handler->display->display_options['fields']['field_favorite_branch']['table'] = 'field_data_field_favorite_branch';
  $handler->display->display_options['fields']['field_favorite_branch']['field'] = 'field_favorite_branch';
  $handler->display->display_options['fields']['field_favorite_branch']['relationship'] = 'field_parent_uid_target_id';
  $handler->display->display_options['fields']['field_favorite_branch']['label'] = 'Branch';
  $handler->display->display_options['fields']['field_favorite_branch']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field: Program */
  $handler->display->display_options['fields']['field_program']['id'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['table'] = 'field_data_field_program';
  $handler->display->display_options['fields']['field_program']['field'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_program']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Favorite Branch (field_favorite_branch) */
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['id'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['table'] = 'field_data_field_favorite_branch';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['field'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['relationship'] = 'field_parent_uid_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['operator_id'] = 'field_favorite_branch_target_id_op';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['label'] = 'Branch';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['description'] = '(use ctrl-click or cmd-click to select multiple)';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['operator'] = 'field_favorite_branch_target_id_op';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['identifier'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Field: Program (field_program) */
  $handler->display->display_options['filters']['field_program_target_id']['id'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['table'] = 'field_data_field_program';
  $handler->display->display_options['filters']['field_program_target_id']['field'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_program_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_target_id']['expose']['operator_id'] = 'field_program_target_id_op';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['label'] = 'Program';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['description'] = '(use ctrl-click or cmd-click to select multiple)';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['operator'] = 'field_program_target_id_op';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['identifier'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_program_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['path'] = 'library/reports/readers/branch';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'By Branch';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Reader Reports';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'menu-reports-menu';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reader_school_target_id']['id'] = 'field_reader_school_target_id';
  $handler->display->display_options['relationships']['field_reader_school_target_id']['table'] = 'field_data_field_reader_school';
  $handler->display->display_options['relationships']['field_reader_school_target_id']['field'] = 'field_reader_school_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_program_target_id']['id'] = 'field_program_target_id';
  $handler->display->display_options['relationships']['field_program_target_id']['table'] = 'field_data_field_program';
  $handler->display->display_options['relationships']['field_program_target_id']['field'] = 'field_program_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['id'] = 'field_parent_uid_target_id';
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['table'] = 'field_data_field_parent_uid';
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['field'] = 'field_parent_uid_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Reader: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reader';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = 'Reader Id';
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Field: Program */
  $handler->display->display_options['fields']['field_program']['id'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['table'] = 'field_data_field_program';
  $handler->display->display_options['fields']['field_program']['field'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_program']['delta_offset'] = '0';
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
  /* Field: Reader: Current Points */
  $handler->display->display_options['fields']['field_current_points']['id'] = 'field_current_points';
  $handler->display->display_options['fields']['field_current_points']['table'] = 'field_data_field_current_points';
  $handler->display->display_options['fields']['field_current_points']['field'] = 'field_current_points';
  $handler->display->display_options['fields']['field_current_points']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: User: Favorite Branch */
  $handler->display->display_options['fields']['field_favorite_branch']['id'] = 'field_favorite_branch';
  $handler->display->display_options['fields']['field_favorite_branch']['table'] = 'field_data_field_favorite_branch';
  $handler->display->display_options['fields']['field_favorite_branch']['field'] = 'field_favorite_branch';
  $handler->display->display_options['fields']['field_favorite_branch']['relationship'] = 'field_parent_uid_target_id';
  $handler->display->display_options['fields']['field_favorite_branch']['label'] = 'Branch';
  $handler->display->display_options['fields']['field_favorite_branch']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['path'] = 'library/reports/readers/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
    'page_1' => 0,
    'page_2' => 0,
    'page_3' => 0,
    'page_4' => 0,
  );
  $export['report_base_readers'] = $view;

  $view = new view();
  $view->name = 'report_base_reading';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_reading_log';
  $view->human_name = 'Report Base - Reading';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Report Base - Reading';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Field: Reading Log: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reading_log';
  $handler->display->display_options['fields']['id']['field'] = 'id';
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
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_program_reference']['delta_offset'] = '0';
  /* Field: Field: Units Completed */
  $handler->display->display_options['fields']['field_units_completed']['id'] = 'field_units_completed';
  $handler->display->display_options['fields']['field_units_completed']['table'] = 'field_data_field_units_completed';
  $handler->display->display_options['fields']['field_units_completed']['field'] = 'field_units_completed';
  $handler->display->display_options['fields']['field_units_completed']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Field: Unit Type */
  $handler->display->display_options['fields']['field_unit_type']['id'] = 'field_unit_type';
  $handler->display->display_options['fields']['field_unit_type']['table'] = 'field_data_field_unit_type';
  $handler->display->display_options['fields']['field_unit_type']['field'] = 'field_unit_type';
  /* Filter criterion: Date: Date (eck_reading_log) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'eck_reading_log';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Date Logged';
  $handler->display->display_options['filters']['date_filter']['expose']['description'] = 'End date is NOT included in Search, e.g., for the first week of July, use End Date of 07/08/2017, NOT 07/07.';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-0:+0';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'eck_reading_log.created' => 'eck_reading_log.created',
  );
  $handler->display->display_options['filters']['date_filter']['date_method'] = 'AND';

  /* Display: Base */
  $handler = $view->new_display('page', 'Base', 'page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'id' => 'id',
    'created' => 'created',
    'field_program_reference' => 'field_program_reference',
    'field_units_completed' => 'field_units_completed',
    'field_unit_type' => 'field_unit_type',
  );
  $handler->display->display_options['style_options']['default'] = 'id';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_program_reference' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_units_completed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_unit_type' => array(
      'sortable' => 1,
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
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Reading Log */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'eck_reading_log';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Select';
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
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
  );
  /* Field: Reading Log: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reading_log';
  $handler->display->display_options['fields']['id']['field'] = 'id';
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
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_program_reference']['delta_offset'] = '0';
  /* Field: Field: Units Completed */
  $handler->display->display_options['fields']['field_units_completed']['id'] = 'field_units_completed';
  $handler->display->display_options['fields']['field_units_completed']['table'] = 'field_data_field_units_completed';
  $handler->display->display_options['fields']['field_units_completed']['field'] = 'field_units_completed';
  $handler->display->display_options['fields']['field_units_completed']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Field: Unit Type */
  $handler->display->display_options['fields']['field_unit_type']['id'] = 'field_unit_type';
  $handler->display->display_options['fields']['field_unit_type']['table'] = 'field_data_field_unit_type';
  $handler->display->display_options['fields']['field_unit_type']['field'] = 'field_unit_type';
  $handler->display->display_options['path'] = 'library/reports/reading/base';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Reading Report - Base';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-library-menu1';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Reading Reports';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'menu-reports-menu';

  /* Display: Summary */
  $handler = $view->new_display('page', 'Summary', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Report - Reading Summary';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Program Reference */
  $handler->display->display_options['fields']['field_program_reference']['id'] = 'field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['table'] = 'field_data_field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['field'] = 'field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_program_reference']['delta_offset'] = '0';
  /* Field: Field: Units Completed */
  $handler->display->display_options['fields']['field_units_completed']['id'] = 'field_units_completed';
  $handler->display->display_options['fields']['field_units_completed']['table'] = 'field_data_field_units_completed';
  $handler->display->display_options['fields']['field_units_completed']['field'] = 'field_units_completed';
  $handler->display->display_options['fields']['field_units_completed']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_units_completed']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Field: Unit Type */
  $handler->display->display_options['fields']['field_unit_type']['id'] = 'field_unit_type';
  $handler->display->display_options['fields']['field_unit_type']['table'] = 'field_data_field_unit_type';
  $handler->display->display_options['fields']['field_unit_type']['field'] = 'field_unit_type';
  $handler->display->display_options['path'] = 'library/reports/reading/summary';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Summary';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 1;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Base Export */
  $handler = $view->new_display('views_data_export', 'Base Export', 'views_data_export_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Report Base - Reading Log Export';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['path'] = 'library/reports/reading/base/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
    'page_1' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['segment_size'] = '100';

  /* Display: Summary by Branch */
  $handler = $view->new_display('page', 'Summary by Branch', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Report - Reading Summary by Branch';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
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
  $handler->display->display_options['relationships']['field_favorite_branch_target_id']['id'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['relationships']['field_favorite_branch_target_id']['table'] = 'field_data_field_favorite_branch';
  $handler->display->display_options['relationships']['field_favorite_branch_target_id']['field'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['relationships']['field_favorite_branch_target_id']['relationship'] = 'field_parent_uid_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Program Reference */
  $handler->display->display_options['fields']['field_program_reference']['id'] = 'field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['table'] = 'field_data_field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['field'] = 'field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_program_reference']['delta_offset'] = '0';
  /* Field: Field: Units Completed */
  $handler->display->display_options['fields']['field_units_completed']['id'] = 'field_units_completed';
  $handler->display->display_options['fields']['field_units_completed']['table'] = 'field_data_field_units_completed';
  $handler->display->display_options['fields']['field_units_completed']['field'] = 'field_units_completed';
  $handler->display->display_options['fields']['field_units_completed']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_units_completed']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Field: Unit Type */
  $handler->display->display_options['fields']['field_unit_type']['id'] = 'field_unit_type';
  $handler->display->display_options['fields']['field_unit_type']['table'] = 'field_data_field_unit_type';
  $handler->display->display_options['fields']['field_unit_type']['field'] = 'field_unit_type';
  /* Field: User: Favorite Branch */
  $handler->display->display_options['fields']['field_favorite_branch']['id'] = 'field_favorite_branch';
  $handler->display->display_options['fields']['field_favorite_branch']['table'] = 'field_data_field_favorite_branch';
  $handler->display->display_options['fields']['field_favorite_branch']['field'] = 'field_favorite_branch';
  $handler->display->display_options['fields']['field_favorite_branch']['relationship'] = 'field_parent_uid_target_id';
  $handler->display->display_options['fields']['field_favorite_branch']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Date: Date (eck_reading_log) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'eck_reading_log';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Date Logged';
  $handler->display->display_options['filters']['date_filter']['expose']['description'] = 'End date is NOT included in Search, e.g., for the first week of July, use End Date of 07/08/2017, NOT 07/07.';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-0:+0';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'eck_reading_log.created' => 'eck_reading_log.created',
  );
  $handler->display->display_options['filters']['date_filter']['date_method'] = 'AND';
  /* Filter criterion: User: Favorite Branch (field_favorite_branch) */
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['id'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['table'] = 'field_data_field_favorite_branch';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['field'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['relationship'] = 'field_parent_uid_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['operator_id'] = 'field_favorite_branch_target_id_op';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['label'] = 'Branch';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['description'] = ' (use ctrl-click or cmd-click to select multiple)';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['operator'] = 'field_favorite_branch_target_id_op';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['identifier'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Field: Program (field_program) */
  $handler->display->display_options['filters']['field_program_target_id']['id'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['table'] = 'field_data_field_program';
  $handler->display->display_options['filters']['field_program_target_id']['field'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['relationship'] = 'field_readers_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_program_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_target_id']['expose']['operator_id'] = 'field_program_target_id_op';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['label'] = 'Program';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['description'] = '(use ctrl-click or cmd-click to select multiple)';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['operator'] = 'field_program_target_id_op';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['identifier'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_program_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['path'] = 'library/reports/reading/summary-branch';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Summary by Branch';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 1;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Readers */
  $handler = $view->new_display('page', 'Readers', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Top Readers';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_program_reference' => 'field_program_reference',
    'field_units_completed' => 'field_units_completed',
    'field_unit_type' => 'field_unit_type',
    'field_readers' => 'field_readers',
  );
  $handler->display->display_options['style_options']['default'] = 'field_units_completed';
  $handler->display->display_options['style_options']['info'] = array(
    'field_program_reference' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_units_completed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_unit_type' => array(
      'sortable' => 1,
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
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_program_reference_target_id']['id'] = 'field_program_reference_target_id';
  $handler->display->display_options['relationships']['field_program_reference_target_id']['table'] = 'field_data_field_program_reference';
  $handler->display->display_options['relationships']['field_program_reference_target_id']['field'] = 'field_program_reference_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Program Reference */
  $handler->display->display_options['fields']['field_program_reference']['id'] = 'field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['table'] = 'field_data_field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['field'] = 'field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_program_reference']['delta_offset'] = '0';
  /* Field: Field: Units Completed */
  $handler->display->display_options['fields']['field_units_completed']['id'] = 'field_units_completed';
  $handler->display->display_options['fields']['field_units_completed']['table'] = 'field_data_field_units_completed';
  $handler->display->display_options['fields']['field_units_completed']['field'] = 'field_units_completed';
  $handler->display->display_options['fields']['field_units_completed']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_units_completed']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Field: Unit Type */
  $handler->display->display_options['fields']['field_unit_type']['id'] = 'field_unit_type';
  $handler->display->display_options['fields']['field_unit_type']['table'] = 'field_data_field_unit_type';
  $handler->display->display_options['fields']['field_unit_type']['field'] = 'field_unit_type';
  /* Field: Field: Readers */
  $handler->display->display_options['fields']['field_readers']['id'] = 'field_readers';
  $handler->display->display_options['fields']['field_readers']['table'] = 'field_data_field_readers';
  $handler->display->display_options['fields']['field_readers']['field'] = 'field_readers';
  $handler->display->display_options['fields']['field_readers']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_readers']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Date: Date (eck_reading_log) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'eck_reading_log';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Date Logged';
  $handler->display->display_options['filters']['date_filter']['expose']['description'] = 'End date is NOT included in Search, e.g., for the first week of July, use End Date of 07/08/2017, NOT 07/07.';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-0:+0';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'eck_reading_log.created' => 'eck_reading_log.created',
  );
  $handler->display->display_options['filters']['date_filter']['date_method'] = 'AND';
  /* Filter criterion: Program: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'eck_program';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_program_reference_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Program';
  $handler->display->display_options['filters']['title']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['path'] = 'library/reports/reading/readers';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Reading Report - Top Readers';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-library-menu1';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Reading Reports';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'menu-library-menu1';
  $export['report_base_reading'] = $view;

  $view = new view();
  $view->name = 'report_base_user_emails';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Report Base - User Emails';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Report Base - User Emails';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_readers_target_id']['id'] = 'field_readers_target_id';
  $handler->display->display_options['relationships']['field_readers_target_id']['table'] = 'field_data_field_readers';
  $handler->display->display_options['relationships']['field_readers_target_id']['field'] = 'field_readers_target_id';
  $handler->display->display_options['relationships']['field_readers_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_program_target_id']['id'] = 'field_program_target_id';
  $handler->display->display_options['relationships']['field_program_target_id']['table'] = 'field_data_field_program';
  $handler->display->display_options['relationships']['field_program_target_id']['field'] = 'field_program_target_id';
  $handler->display->display_options['relationships']['field_program_target_id']['relationship'] = 'field_readers_target_id';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: Field: Program */
  $handler->display->display_options['fields']['field_program']['id'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['table'] = 'field_data_field_program';
  $handler->display->display_options['fields']['field_program']['field'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['relationship'] = 'field_readers_target_id';
  $handler->display->display_options['fields']['field_program']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_program']['delta_offset'] = '0';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['operator'] = 'not';
  $handler->display->display_options['filters']['rid']['value'] = array(
    3 => '3',
    5 => '5',
  );
  /* Filter criterion: Field: Program (field_program) */
  $handler->display->display_options['filters']['field_program_target_id']['id'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['table'] = 'field_data_field_program';
  $handler->display->display_options['filters']['field_program_target_id']['field'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['relationship'] = 'field_readers_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_target_id']['expose']['operator_id'] = 'field_program_target_id_op';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['label'] = 'Program';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_program_target_id']['expose']['operator'] = 'field_program_target_id_op';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['identifier'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_program_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'library/report/users/emails';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Patron Email List';
  $handler->display->display_options['menu']['weight'] = '40';
  $handler->display->display_options['menu']['name'] = 'menu-reports-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['path'] = 'library/reports/users/emails/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $export['report_base_user_emails'] = $view;

  $view = new view();
  $view->name = 'test_signup_readers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_reader';
  $view->human_name = 'Report Base - Signup: Readers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Signups Report - Readers';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_favorite_branch',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'field_program' => 'field_program',
    'created' => 'created',
    'field_favorite_branch' => 'field_favorite_branch',
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
    'field_program' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_favorite_branch' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
  $handler->display->display_options['header']['area']['content'] = 'Use this report to find the number of <strong>READERS</strong> whose parent-Users signed up on a particular day or in a particular period.  <em>Note: be careful with date ranges, think of the end date as "up to but not including" -- e.g., to find everyone who signed up the first week of June, you\'d search for "IN BETWEEN 06/01/2017 and 06/08/2017"</em>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['id'] = 'field_parent_uid_target_id';
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['table'] = 'field_data_field_parent_uid';
  $handler->display->display_options['relationships']['field_parent_uid_target_id']['field'] = 'field_parent_uid_target_id';
  /* Field: COUNT(Reader: Id) */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reader';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['group_type'] = 'count';
  $handler->display->display_options['fields']['id']['label'] = '#';
  /* Field: Field: Program */
  $handler->display->display_options['fields']['field_program']['id'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['table'] = 'field_data_field_program';
  $handler->display->display_options['fields']['field_program']['field'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_program']['delta_offset'] = '0';
  /* Field: User: Favorite Branch */
  $handler->display->display_options['fields']['field_favorite_branch']['id'] = 'field_favorite_branch';
  $handler->display->display_options['fields']['field_favorite_branch']['table'] = 'field_data_field_favorite_branch';
  $handler->display->display_options['fields']['field_favorite_branch']['field'] = 'field_favorite_branch';
  $handler->display->display_options['fields']['field_favorite_branch']['relationship'] = 'field_parent_uid_target_id';
  $handler->display->display_options['fields']['field_favorite_branch']['label'] = 'Branch';
  $handler->display->display_options['fields']['field_favorite_branch']['settings'] = array(
    'link' => 0,
  );
  /* Filter criterion: Date: Date (users) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'users';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['relationship'] = 'field_parent_uid_target_id';
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Date (signup)';
  $handler->display->display_options['filters']['date_filter']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-0:+0';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'users.created' => 'users.created',
  );
  /* Filter criterion: Field: Program (field_program) */
  $handler->display->display_options['filters']['field_program_target_id']['id'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['table'] = 'field_data_field_program';
  $handler->display->display_options['filters']['field_program_target_id']['field'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_target_id']['expose']['operator_id'] = 'field_program_target_id_op';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['label'] = 'Program';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['operator'] = 'field_program_target_id_op';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['identifier'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_program_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: User: Favorite Branch (field_favorite_branch) */
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['id'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['table'] = 'field_data_field_favorite_branch';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['field'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['relationship'] = 'field_parent_uid_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['operator_id'] = 'field_favorite_branch_target_id_op';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['label'] = 'Favorite Branch';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['operator'] = 'field_favorite_branch_target_id_op';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['identifier'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'library/reports/signups/readers';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Signup Reports - Readers';
  $handler->display->display_options['menu']['weight'] = '';
  $handler->display->display_options['menu']['name'] = 'menu-reports-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['test_signup_readers'] = $view;

  $view = new view();
  $view->name = 'test_signup_users';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Report Base - Signup: Users';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Signups Report - Users';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'Use this report to find the number of <strong>USERS</strong> who signed up on a particular day or in a particular period.  <em>Note: be careful with date ranges, think of the end date as "up to but not including" -- e.g., to find everyone who signed up the first week of June, you\'d search for "IN BETWEEN 06/01/2017 and 06/08/2017"</em>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  /* Field: COUNT(User: Uid) */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['group_type'] = 'count';
  $handler->display->display_options['fields']['uid']['label'] = '#';
  /* Field: User: Favorite Branch */
  $handler->display->display_options['fields']['field_favorite_branch']['id'] = 'field_favorite_branch';
  $handler->display->display_options['fields']['field_favorite_branch']['table'] = 'field_data_field_favorite_branch';
  $handler->display->display_options['fields']['field_favorite_branch']['field'] = 'field_favorite_branch';
  $handler->display->display_options['fields']['field_favorite_branch']['settings'] = array(
    'link' => 0,
  );
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Date: Date (users) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'users';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Date Registered';
  $handler->display->display_options['filters']['date_filter']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-0:+0';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'users.created' => 'users.created',
  );
  /* Filter criterion: User: Favorite Branch (field_favorite_branch) */
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['id'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['table'] = 'field_data_field_favorite_branch';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['field'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['operator_id'] = 'field_favorite_branch_target_id_op';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['label'] = 'Favorite Branch';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['operator'] = 'field_favorite_branch_target_id_op';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['identifier'] = 'field_favorite_branch_target_id';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    4 => '4',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'library/reports/signups/users';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Signup Reports - Users';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-reports-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['test_signup_users'] = $view;

  return $export;
}
