<?php
function add_prize_pages(){
  $output = '';

  $bundle_name = 'prize';
    $entity_type_name = 'prize';
  module_load_include('inc', 'eck', 'eck.entity');
  $form = eck__entity__add($entity_type_name, $bundle_name);
  $output .= drupal_render($form);
  return $output;

}

