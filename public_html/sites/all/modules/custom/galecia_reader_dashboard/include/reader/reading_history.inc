<?php 

function reader_history(){
	global $user;
	$current_user=$user->uid;

	$user_details= galecia_reader_dashboard_check_registration($current_user);

	foreach ($user_details as $key => $value) {
 
    	$current_reader=$user_details[$key];
	}

	$entity=entity_load_single('reader', $current_reader);

	$name=$entity->field_first_name['und'][0]['value'];

	$total_points=$entity->field_points['und'][0]['value'];

	$program=$entity->field_program['und'][0]['target_id'];

	$program_entity=entity_load_single('program', $program);

	$program_name=$program_entity->title;

	$level=$entity->field_level['und'][0]['target_id'];

	$level_entity=entity_load_single('level', $level);

	$level_title=$level_entity->title;

	$current_badge=$entity->field_my_badges['und'][0]['tid'];

	$badge_term=taxonomy_term_load($current_badge);

	$recent_prize=$entity->field_my_prizes['und'][0]['tid'];

	$prize_term=taxonomy_term_load($recent_prize);

	$output = "";
	$output .= "<div class=\"reader-history-panel\">";
    $output .= "<div class=\"reader-history-title\">";
	$output .= "<h3>" . t("Reader History for ") . $name ."</h3>";
	$output .= "</div>";
	$output .= "<div class=\"reader-history-body\">";
	$output .= "<div class=\"reader-name-level\">" . $name . t(" is at level ") . $level_title . t(" in the ") . $program_name .t(" program") . "</div>";
	$output .= "<div class=\"reader-history-badge\">";
	$output .= "<h4>" . t("Current Badge:") . "</h4>";
	$output .= "<img src='" .file_create_url($badge_term->field_badge_image['und'][0]['uri']) . "'></div>";
	$output .= "</div>";
	$output .= "<div class=\"reader-history-list\">";
	$output .= "<h3>" . t("Books read") . "</h3>";
	$output .= views_embed_view('reader_logs','block', $current_reader);
	$output .= "</div>"; //close reader-history-list
	$output .= "</div>"; //close reader-history-body
	$output .= "</div>"; //close reader-history-panel
	return $output;
}
 ?>
