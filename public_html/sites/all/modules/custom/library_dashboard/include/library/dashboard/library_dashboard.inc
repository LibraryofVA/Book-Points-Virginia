<?php
function library_dashboard_page(){
	$output = '';
	//$entity_form = drupal_get_form('eck__entity__form_edit_program_program');
  	//dsm($entity_form);
 //  	$bundle_name = 'program';
 //  	$entity_type_name = 'program';
	// module_load_include('inc', 'eck', 'eck.entity');
	// $form = eck__entity__add($entity_type_name, $bundle_name);
	
	// $menu = menu_navigation_links('menu-library-menu');
 //  $output = "";
 //  $output .='<div class="region region-sidebar"><ul>
 //    			<li></li>';
	// 				foreach($menu as $menuLink): 
						
	// 		          $output .= '<li><a href="/' . $menuLink["href"] . '">' .$menuLink['title'] .'</a></li>';
 //            		endforeach; 
	// 				$output .= '</ul></div>';
  
$output .= t('WELCOME USER');
$output .= drupal_render($form);
  return $output;
  }
?>


