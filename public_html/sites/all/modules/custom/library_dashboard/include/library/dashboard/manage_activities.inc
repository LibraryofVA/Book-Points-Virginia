<?php
function manage_activities(){
	$output = '';
  	$output .= "<div>";
  $output .= "<form action='/library/dashboard/activities/program/activity/add'>
    <input class='button-float' type='submit' value='" . t('Add Activity') . "' />
</form>";
 $output .= views_embed_view('activities_view', 'block_1');
 $output .= "<br>";
 $output .= "</div>";
	return $output;

}