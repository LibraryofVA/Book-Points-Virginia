<?php
function add_badge_pages(){
  $output = '';
  $bundle_name = 'badge';
    $entity_type_name = 'badge';
  module_load_include('inc', 'eck', 'eck.entity');
  $form = eck__entity__add($entity_type_name, $bundle_name);
  $output .= drupal_render($form);
  return $output;
}
?>