<?php
function manage_secret_codes(){
	$output = '';
  	$output .= "<div>";
  $output .= "<form action='/library/dashboard/secret_codes/program/secret_code/add'>
    <input class='button-float' type='submit' value='" .t('Add Secret Code') . "' />
</form>";
 $output .= views_embed_view('secret_codes_view', 'block_1');
 $output .= "<br>";
 $output .= "</div>";
	return $output;

}