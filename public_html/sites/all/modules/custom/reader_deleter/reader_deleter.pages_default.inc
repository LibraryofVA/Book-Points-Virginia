<?php
/**
 * @file
 * reader_deleter.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function reader_deleter_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'reader_deleter';
  $page->task = 'page';
  $page->admin_title = 'Reader Deleter';
  $page->admin_description = '';
  $page->path = 'library/admin/reader-deleter';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 3,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_reader_deleter__panel';
  $handler->task = 'page';
  $handler->subtask = 'reader_deleter';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'one';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'one_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'e7df437f-8a75-4217-b731-4308189639f7';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_reader_deleter__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-90cee120-cfe5-4d4f-a35d-f982244cdf65';
  $pane->panel = 'one_main';
  $pane->type = 'views';
  $pane->subtype = 'reader_deleter';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '90cee120-cfe5-4d4f-a35d-f982244cdf65';
  $display->content['new-90cee120-cfe5-4d4f-a35d-f982244cdf65'] = $pane;
  $display->panels['one_main'][0] = 'new-90cee120-cfe5-4d4f-a35d-f982244cdf65';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-90cee120-cfe5-4d4f-a35d-f982244cdf65';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['reader_deleter'] = $page;

  return $pages;

}
