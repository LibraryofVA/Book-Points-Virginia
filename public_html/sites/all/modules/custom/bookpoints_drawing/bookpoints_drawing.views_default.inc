<?php
/**
 * @file
 * bookpoints_drawing.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function bookpoints_drawing_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'drawing';
  $view->description = 'Used to pick drawing winners';
  $view->tag = 'default';
  $view->base_table = 'eck_reader_ticket';
  $view->human_name = 'Drawing';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Manage Drawing Tickets';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'input_required';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Draw winner!';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['text_input_required'] = 'Filter your drawing tickets and click the "Draw winner" button to select a winner.  You can keep clicking to draw multiple winners.';
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'filtered_html';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'field_readers' => 'field_readers',
    'title' => 'title',
    'created' => 'created',
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
    'field_readers' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
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
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No drawing tickets have been earned yet that match this search.  ';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_readers_target_id']['id'] = 'field_readers_target_id';
  $handler->display->display_options['relationships']['field_readers_target_id']['table'] = 'field_data_field_readers';
  $handler->display->display_options['relationships']['field_readers_target_id']['field'] = 'field_readers_target_id';
  $handler->display->display_options['relationships']['field_readers_target_id']['label'] = 'READER entity referenced from field_readers';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_program_target_id']['id'] = 'field_program_target_id';
  $handler->display->display_options['relationships']['field_program_target_id']['table'] = 'field_data_field_program';
  $handler->display->display_options['relationships']['field_program_target_id']['field'] = 'field_program_target_id';
  $handler->display->display_options['relationships']['field_program_target_id']['relationship'] = 'field_readers_target_id';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_readers_user']['id'] = 'reverse_field_readers_user';
  $handler->display->display_options['relationships']['reverse_field_readers_user']['table'] = 'eck_reader';
  $handler->display->display_options['relationships']['reverse_field_readers_user']['field'] = 'reverse_field_readers_user';
  $handler->display->display_options['relationships']['reverse_field_readers_user']['relationship'] = 'field_readers_target_id';
  $handler->display->display_options['relationships']['reverse_field_readers_user']['label'] = 'USER referencing Reader from field_readers';
  /* Field: Reader Ticket: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reader_ticket';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Reader Ticket: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_reader_ticket';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Earned';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Field: Readers */
  $handler->display->display_options['fields']['field_readers']['id'] = 'field_readers';
  $handler->display->display_options['fields']['field_readers']['table'] = 'field_data_field_readers';
  $handler->display->display_options['fields']['field_readers']['field'] = 'field_readers';
  $handler->display->display_options['fields']['field_readers']['label'] = 'Reader';
  $handler->display->display_options['fields']['field_readers']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_readers']['delta_offset'] = '0';
  /* Field: Program: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_program';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['fields']['title']['label'] = 'Program';
  /* Field: User: Favorite Branch */
  $handler->display->display_options['fields']['field_favorite_branch']['id'] = 'field_favorite_branch';
  $handler->display->display_options['fields']['field_favorite_branch']['table'] = 'field_data_field_favorite_branch';
  $handler->display->display_options['fields']['field_favorite_branch']['field'] = 'field_favorite_branch';
  $handler->display->display_options['fields']['field_favorite_branch']['relationship'] = 'reverse_field_readers_user';
  $handler->display->display_options['fields']['field_favorite_branch']['label'] = 'Branch';
  $handler->display->display_options['fields']['field_favorite_branch']['settings'] = array(
    'link' => 0,
  );
  /* Filter criterion: Reader Ticket: reader_ticket type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_reader_ticket';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'reader_ticket' => 'reader_ticket',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Date: Date (eck_reader_ticket) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'eck_reader_ticket';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Date Earned';
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
    'eck_reader_ticket.created' => 'eck_reader_ticket.created',
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
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['relationship'] = 'reverse_field_readers_user';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['operator_id'] = 'field_favorite_branch_target_id_op';
  $handler->display->display_options['filters']['field_favorite_branch_target_id']['expose']['label'] = 'Branch';
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

  /* Display: winner */
  $handler = $view->new_display('page', 'winner', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Draw a Winner!';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'field_readers' => 'field_readers',
    'title' => 'title',
    'created' => 'created',
    'field_favorite_branch' => 'field_favorite_branch',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
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
    'title' => array(
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
    'field_favorite_branch' => array(
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
  $handler->display->display_options['header']['area']['content'] = '<a href="/library/dashboard/drawing/manage_tickets">Manage Tickets</a>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['path'] = 'library/dashboard/drawing';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Manage Drawings';
  $handler->display->display_options['menu']['name'] = 'menu-library-menu1';

  /* Display: manage */
  $handler = $view->new_display('page', 'manage', 'page_2');
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  $handler->display->display_options['header']['result']['content'] = 'Displaying @start - @end of @total tickets for this search.';
  $handler->display->display_options['path'] = 'library/dashboard/drawing/manage_tickets';
  $export['drawing'] = $view;

  return $export;
}
