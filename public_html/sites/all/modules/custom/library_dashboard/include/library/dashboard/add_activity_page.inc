<?php
function add_activity_pages(){
  $output = '';
  $bundle_name = 'activity';
    $entity_type_name = 'activity';
  module_load_include('inc', 'eck', 'eck.entity');
  $form = eck__entity__add($entity_type_name, $bundle_name);
  $output .= drupal_render($form);
  return $output;
}
?>