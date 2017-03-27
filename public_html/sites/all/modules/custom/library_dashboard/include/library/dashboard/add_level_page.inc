<?php
function add_levels_page(){
	$output = '';
	$bundle_name = 'level';
  	$entity_type_name = 'level';
	module_load_include('inc', 'eck', 'eck.entity');
	$form = eck__entity__add($entity_type_name, $bundle_name);
	$output .= drupal_render($form);
  return $output;
}
?>