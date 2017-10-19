<?php
/**
 * @file
 * badge_remover.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function badge_remover_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'badges_of_readers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_reader_badge';
  $view->human_name = 'Badges of Readers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Badges of Readers';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Reader Badge: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reader_badge';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Field: Readers */
  $handler->display->display_options['fields']['field_readers']['id'] = 'field_readers';
  $handler->display->display_options['fields']['field_readers']['table'] = 'field_data_field_readers';
  $handler->display->display_options['fields']['field_readers']['field'] = 'field_readers';
  $handler->display->display_options['fields']['field_readers']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_readers']['delta_offset'] = '0';
  /* Field: Reader Badge: Delete link */
  $handler->display->display_options['fields']['delete_link']['id'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['table'] = 'eck_reader_badge';
  $handler->display->display_options['fields']['delete_link']['field'] = 'delete_link';
  /* Field: Reader Badge: Rendered Reader Badge */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_reader_badge';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'full';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Filter criterion: Field: Readers (field_readers) */
  $handler->display->display_options['filters']['field_readers_target_id']['id'] = 'field_readers_target_id';
  $handler->display->display_options['filters']['field_readers_target_id']['table'] = 'field_data_field_readers';
  $handler->display->display_options['filters']['field_readers_target_id']['field'] = 'field_readers_target_id';
  $handler->display->display_options['filters']['field_readers_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_readers_target_id']['expose']['operator_id'] = 'field_readers_target_id_op';
  $handler->display->display_options['filters']['field_readers_target_id']['expose']['label'] = 'Readers';
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
  $handler->display->display_options['path'] = 'library/admin/badges-of-readers';
  $export['badges_of_readers'] = $view;

  return $export;
}
