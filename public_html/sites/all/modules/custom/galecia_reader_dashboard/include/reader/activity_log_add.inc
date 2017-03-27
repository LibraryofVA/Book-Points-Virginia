<?php
function activity_log_add_page(){
	$output = '';
	$bundle_name = 'activity_log_reference';
  	$entity_type_name = 'activity_log_reference';
	module_load_include('inc', 'eck', 'eck.entity');
	$form = eck__entity__add($entity_type_name, $bundle_name);
	$output .= drupal_render($form);
  return $output;
}
?>