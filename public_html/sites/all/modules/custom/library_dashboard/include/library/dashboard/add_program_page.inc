<?php
function add_program_pages(){
	$output = '';
	$bundle_name = 'program';
  	$entity_type_name = 'program';
	module_load_include('inc', 'eck', 'eck.entity');
	$form = eck__entity__add($entity_type_name, $bundle_name);
	$output .= drupal_render($form);
  return $output;
}
?>