<?php
/**
 * @file
 * entity_cleanup.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function entity_cleanup_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-admin---cleanup_cleanup---activities-claimed:library/admin/cleanup-activity-log.
  $menu_links['menu-admin---cleanup_cleanup---activities-claimed:library/admin/cleanup-activity-log'] = array(
    'menu_name' => 'menu-admin---cleanup',
    'link_path' => 'library/admin/cleanup-activity-log',
    'router_path' => 'library/admin/cleanup-activity-log',
    'link_title' => 'Cleanup - Activities Claimed',
    'options' => array(
      'identifier' => 'menu-admin---cleanup_cleanup---activities-claimed:library/admin/cleanup-activity-log',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: menu-admin---cleanup_cleanup---reader-badge:library/admin/cleanup-reader-badge.
  $menu_links['menu-admin---cleanup_cleanup---reader-badge:library/admin/cleanup-reader-badge'] = array(
    'menu_name' => 'menu-admin---cleanup',
    'link_path' => 'library/admin/cleanup-reader-badge',
    'router_path' => 'library/admin/cleanup-reader-badge',
    'link_title' => 'Cleanup - Reader Badge',
    'options' => array(
      'identifier' => 'menu-admin---cleanup_cleanup---reader-badge:library/admin/cleanup-reader-badge',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: menu-admin---cleanup_cleanup---reader-prizes:library/admin/cleanup-reader-prizes.
  $menu_links['menu-admin---cleanup_cleanup---reader-prizes:library/admin/cleanup-reader-prizes'] = array(
    'menu_name' => 'menu-admin---cleanup',
    'link_path' => 'library/admin/cleanup-reader-prizes',
    'router_path' => 'library/admin/cleanup-reader-prizes',
    'link_title' => 'Cleanup - Reader Prizes',
    'options' => array(
      'identifier' => 'menu-admin---cleanup_cleanup---reader-prizes:library/admin/cleanup-reader-prizes',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: menu-admin---cleanup_cleanup---reading-log-entries:library/admin/cleanup-reading-log.
  $menu_links['menu-admin---cleanup_cleanup---reading-log-entries:library/admin/cleanup-reading-log'] = array(
    'menu_name' => 'menu-admin---cleanup',
    'link_path' => 'library/admin/cleanup-reading-log',
    'router_path' => 'library/admin/cleanup-reading-log',
    'link_title' => 'Cleanup - Reading Log Entries',
    'options' => array(
      'identifier' => 'menu-admin---cleanup_cleanup---reading-log-entries:library/admin/cleanup-reading-log',
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
  t('Cleanup - Activities Claimed');
  t('Cleanup - Reader Badge');
  t('Cleanup - Reader Prizes');
  t('Cleanup - Reading Log Entries');

  return $menu_links;
}
