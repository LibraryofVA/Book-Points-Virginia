<?php
function activity_log_page(){

	$activity_view = views_get_view('activity_log_page');
    $activity_view->set_display('block');
    // $activity_view->set_arguments($reader_args);
    $activity_view->pre_execute();
    $activity_view->execute();
	//dsm($activity_view);
	$output = '';
  $output .= "<div class=\"panel\" id=\"activity_log_panel\">";
  $output .= "<div class=\"panel-header\">";
  $output .= "<h3>Activity Log</h3>";
 	$output .= "</div>";
 	$output .= "<div class=\"panel-body\">";

 	foreach ($activity_view->result as $key => $value) {
 		//dsm($value);
    $output .= "<div class=\"log-entry\">";
    $output .= "<div class=\"entry-title\">";
 		$output .= render($value->field_field_activity_log_title[0]['raw']['value']);
    $output .= "</div>";
    $output .= "<div class=\"entry-desc\">";
 		$output .= render($value->field_field_activity_log_description[0]['rendered']['#markup']);
    $output .= "</div>";
    $output .= "<div class=\"entry-ops\">";
 		$output .= l('Add New', 'reader/dashboard/activity_log_reference/add');
    $output .= "</div>";
    $output .= "</div>";
 	}

  $output .= "</div>";  //close panel-body
 	$output .= "</div>";  //close panel
	return $output;
}

function submit_activity_log(){
	$entity_type = 'contact';
  	$entity = entity_create($entity_type, array('type' => 'contact_simple'));
  	$wrapper = entity_metadata_wrapper($entity_type, $entity);
}

?>