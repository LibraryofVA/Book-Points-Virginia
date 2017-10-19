<?php
/**
 * @file
 * quiz_rewards_bundle.features.inc
 */

/**
 * Implements hook_node_info().
 */
function quiz_rewards_bundle_node_info() {
  $items = array(
    'quiz_award' => array(
      'name' => t('Quiz Award'),
      'base' => 'node_content',
      'description' => t('These landing pages are used to award prizes/badges for patrons that complete the Reading Challenges.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
