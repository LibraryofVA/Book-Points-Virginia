<?php 

module_load_include('inc', 'galecia_reader_dashboard', 'include/reader/reader_switch');

function reader_dashboard(){
	global $user;
	$current_user=$user->uid;

	$user_details=galecia_reader_dashboard_check_registration($current_user);

	foreach ($user_details as $key => $value) {
 
		$current_reader=$user_details[$key];
	}

	$readers_by_uid=views_embed_view('readers','block',$current_reader);

	$output = "";
	$output .= "<div class=\"reader-switcher-wrapper\">";
	$reader_switch=drupal_get_form('reader_switch_form');
	$output .= drupal_render($reader_switch);
	$output .= "</div>";
	$output .= "<div class=\"current-reader\">";
	$output .= "<h3>" . t("Current Reader") . "</h3>";
	$output .= views_embed_view('readers', 'block_1', $current_reader);
	$output .= "</div>";
	$output .= "<div class=\"all-readers\">";
	$output .= "<h3>" . t("All Readers") . "</h3>";
	$output .= views_embed_view('readers', 'block', $current_user);
	$output .= "</div>";
	return $output;
}
 ?>
