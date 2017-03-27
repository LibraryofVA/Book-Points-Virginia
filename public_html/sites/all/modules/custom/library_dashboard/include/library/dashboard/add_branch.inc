<?php
function add_branch_page(){
	$output = '';
	$bundle_name = 'branch';
  	$entity_type_name = 'branch';
	module_load_include('inc', 'eck', 'eck.entity');
	$form = eck__entity__add($entity_type_name, $bundle_name);
	$output .= drupal_render($form);
  return $output;
}
?>