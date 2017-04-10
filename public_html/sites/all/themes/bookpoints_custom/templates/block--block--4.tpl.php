<?php

global $user;

$current_user=user_load($user->uid);

$loaded_user=user_load($user->uid);

$current_loaded_reader_id=$loaded_user->field_current_reader['und'][0]['target_id'];

$current_loaded_reader=entity_load_single('reader', $current_loaded_reader_id);


$args=array($current_loaded_reader->field_program['und'][0]['target_id']);

$value = array($current_user->field_current_reader['und'][0]['target_id']);
$view = views_get_view('reader_points_for_reader');
$view->set_display('block');
$view->set_arguments($value);
$view->pre_execute();
$view->execute();


$view2 = views_get_view('activities_view');
$view2->set_display('block');
$view2->set_arguments($args);
$view2->pre_execute();
$view2->execute();

$allpoints=array();

foreach($view->result as $key=>$value){

	$allpoints[]=(int)$value->field_field_points[0]['raw']['value'];

}

$current_points=array_sum($allpoints);

$code_form=drupal_get_form('code_search_form');

?>
<div>
	<div>
	  <h2 style='text-align:center'><?php echo $current_points; ?> pts</h2>
	  <br>
	</div>
	<div>
	<?php 
		if(empty($current_loaded_reader->field_quiz_status['und'][0]['value'])) {
			if($current_loaded_reader->field_grade['und'][0]['value'] == 'Third') {
				echo ('<h6>Challenge yourself!</h6><a href="/quiz31">Take the reading challenge!</a>');
			}
			if($current_loaded_reader->field_grade['und'][0]['value'] == 'Fifth') {
				echo ('<h6>Challenge yourself!</h6><a href="/quiz51">Take the reading challenge!</a>');
			}
		} else {
			if(($current_loaded_reader->field_quiz_status['und'][0]['value'] == 'pre-done') && (strtotime("15 July 2017") < time())) {
				if($current_loaded_reader->field_grade['und'][0]['value'] == 'Third') {
					echo ('<h6>Challenge yourself!</h6><a href="/quiz32">Take a new reading challenge!</a>');
				}
				if($current_loaded_reader->field_grade['und'][0]['value'] == 'Fifth') {
					echo ('<h6>Challenge yourself!</h6><a href="/quiz52">Take a new reading challenge!</a>');
				}
			}
		}
	?>
	</div>
	<div>
	<?php print drupal_render($code_form); ?>
	</div> 
	<?php 

		$claimed_array=array();

        if(!empty($current_loaded_reader->field_claimed_activities)) {
        
        	

            foreach($current_loaded_reader->field_claimed_activities['und'] as $key => $value) {

            	$claimed_array[]=$value['target_id'];

            }
        }


	foreach($view2->result as $key=>$value) { 
	  $id=$value->id;
	  if (!in_array($id, $claimed_array)) {
		$title=$value->eck_activity_title;
		$description=$value->field_field_activity_description[0]['rendered']['#markup'];
		$status=t('Claim');
		$enabled='';
		$str="<div><h6>". $title ."</h6><div>";
		$str.= $description;
		$str.= "</div><button class='activity-button' name='" . $status . " id='act_button" . $id . "' data-reader='" . $current_loaded_reader_id . "' data-activity='" . $id . "' value='" . $status . "'" . $enabled .">" .$status . "</button>";
		$str.= "</div><br><div id='ajax-target'></div>";
		echo $str;
	  }
	}
	?>
</div>  