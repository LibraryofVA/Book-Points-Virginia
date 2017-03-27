<?php 
module_load_include('inc', 'galecia_reader_dashboard', 'include/reader/add_reading_log');

function log_add(){

	$output = "";
	$output .= "<div class=\"log-entry-form\">";
	$activity_form=drupal_get_form('reading_activity_form');
  	$output .= drupal_render($activity_form);
  	$output .= "</div>";

  	return $output;
	
}
 ?>