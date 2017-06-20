<?php

global $user;

$current_user=user_load($user->uid);

$value = array($current_user->field_current_reader['und'][0]['target_id']);

$view2 = views_get_view('reader_badge_by_reader');
$view2->set_display('block');
$view2->set_arguments($value);
$view2->pre_execute();
$view2->execute();


foreach($view2->result as $key=>$value){

$uris_array[]=$value->field_field_badge_image[0]['raw']['uri'];

}

?>
<div id="view-badges-mobile" class="button">View Your Badges</div>
<div id="badges-box">

  <?php 

	if(!empty($uris_array)) {

	  	foreach($uris_array as $value) {

	  	print "<div class='badge-div'><img src='" . file_create_url($value). "'></div>";

	  	}

  	}
	?>

</div>
