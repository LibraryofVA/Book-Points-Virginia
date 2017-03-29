<?php

/**
 * @file
 * Template.php - process theme data for your sub-theme.
 * 
 * Rename each function and instance of "bookpoints_custom" to match
 * your subthemes name, e.g. if you name your theme "bookpoints_custom" then the function
 * name will be "bookpoints_custom_preprocess_hook". Tip - you can search/replace
 * on "bookpoints_custom".
 */


/**
 * Override or insert variables for the html template.
 */
/* -- Delete this line if you want to use this function
function bookpoints_custom_preprocess_html(&$vars) {
}
function bookpoints_custom_process_html(&$vars) {
}
// */


/**
 * Override or insert variables for the page templates.
 */
/* -- Delete this line if you want to use these functions
function bookpoints_custom_preprocess_page(&$vars) {
}
function bookpoints_custom_process_page(&$vars) {
}
// */


/**
 * Override or insert variables into the node templates.
 */
/* -- Delete this line if you want to use these functions
function bookpoints_custom_preprocess_node(&$vars) {
}
function bookpoints_custom_process_node(&$vars) {
}
// */


/**
 * Override or insert variables into the comment templates.
 */
/* -- Delete this line if you want to use these functions
function bookpoints_custom_preprocess_comment(&$vars) {
}
function bookpoints_custom_process_comment(&$vars) {
}
// */


/**
 * Override or insert variables into the block templates.
 */
/* -- Delete this line if you want to use these functions
function bookpoints_custom_preprocess_block(&$vars) {
}
function bookpoints_custom_process_block(&$vars) {
}
// */

// function bookpoints_custom_theme(&$existing, $type, $theme, $path){
//   $hooks = array();
//    // Make user-register.tpl.php available
//   $hooks['user_register_form'] = array (
//      'render element' => 'form',
//      'path' => drupal_get_path('theme','bookpoints_custom'),
//      'template' => 'user-register',
//      'preprocess functions' => array('bookpoints_custom_preprocess_user_register_form'),
//   );
//   return $hooks;
// }

// function bookpoints_custom_preprocess_user_register_form(&$vars) {
//   $args = func_get_args();
//   array_shift($args);
//   $form_state['build_info']['args'] = $args; 
//   $vars['form'] = drupal_build_form('user_register_form', $form_state['build_info']['args']);
// }

function bookpoints_custom_form_alter(&$form, &$form_state, $form_id) {
	//krumo($form_id);
  $function = "bookpoints_custom_{$form_id}_submit";
  if (function_exists($function))
    $form['#submit'][] = $function;
}

function bookpoints_custom_user_register_form_submit($form, &$form_state) {
  $form_state['redirect'] = 'galecia_profile_builder/wizard_form';
}


function bookpoints_custom_preprocess_block(&$variables) { 

 
if ($variables['block']->delta === '2') {
   drupal_add_js(drupal_get_path('module', 'galecia_reader_dashboard') . '/js/reader_selector_block.js');
 }

}

function bookpoints_custom_preprocess_page(&$variables) { 
 
  $path = current_path();
  if ($path == 'galecia_profile_builder/wizard_form') {
    drupal_add_js(drupal_get_path('theme', 'bookpoints_custom') . '/js/custom.js');
  }
  if ($path == 'family_profile_builder/wizard_form') {
    drupal_add_js(drupal_get_path('theme', 'bookpoints_custom') . '/js/custom-family.js');
  }
  if ($path == 'group_profile_builder/wizard_form') {
    drupal_add_js(drupal_get_path('theme', 'bookpoints_custom') . '/js/custom-group.js');
  }
  if ($path == 'reader-dashboard') {
    drupal_add_js(drupal_get_path('theme', 'bookpoints_custom') . '/js/activity_button.js');
  }
}


function bookpoints_custom_programs_radio_before_element($variables) {

  if ($variables['element']['#name']=='program') {

  $path = drupal_get_path('theme', 'bookpoints_custom');
    $element = $variables['element'];
    $program = entity_load_single('program', $element['#return_value']);
    $description = $program->field_program_description['und'][0]['value'];

  _form_set_class($element, array('form-radio'));
  $options = "<div class='program-blocks'>";
  $options .= "<div><input class='program-buttons' type='button' value='" . $element['#title']. "' name='" . $element['#title'] . "' id='forclick" . $element['#id'] . "'>";
  $options .= '<input ';
  $options .= 'type="radio" ';
  $options .= 'name="program"';
  $options .= 'id="' . $element['#id'] . '" ';
  $options .= 'value="' . $element['#return_value'] . '" ';
  $options .= drupal_attributes($element['#attributes']) . ' />';
  $options .= "</div>";
  $options .= "<div class='program-description'>" . $description . "</div></div>";
  unset($element['#title']);
  return $options;
}


}

function bookpoints_custom_programs_radios_before_element($variables){
  if ($variables['element']['#name']=='program') {
  $element = $variables['element'];
   $attributes = array();
   if (isset($element['#id'])) {
     $attributes['id'] = $element['#id'];
   }
   $attributes['class'][] = 'form-radios';
   if (!empty($element['#attributes']['class'])) {
     $attributes['class'] = array_merge($attributes['class'], $element['#attributes']['class']);
   }
   if (isset($element['#attributes']['title'])) {
     $attributes['title'] = $element['#attributes']['title'];
   }
   $html = '<div' . drupal_attributes($attributes) . '>';
   if(!empty($element['#options'])){
     foreach($element['#options'] as $key => $val){
       $html .= theme('program_radio_before_element', $element[$key]);
     }
   }
   $html .= '</div>';
 return $html;
}
}

function bookpoints_custom_radio_before_element($variables) {
  
  $path = drupal_get_path('theme', 'bookpoints_custom');
    $element = $variables['element'];
  _form_set_class($element, array('form-radios'));
  // $checkbox = '<div class="card star-radio-card test selected_star">';
  // $checkbox .= '<div class="content">';
  $checkbox = "";
  $checkbox .= '<input ';
  $checkbox .= 'type="radio" ';
  $checkbox .= 'class="stars" ';
  $checkbox .= 'name="' . $element['#name'] . '" ';
  $checkbox .= 'id="' . $element['#id'] . '" ';
  $checkbox .= 'value="' . $element['#return_value'] . '" ';
  // if ($element['#return_value'] == $element['#default_value']) {
    $checkbox .= $element['#value'] ? ' checked="checked" ' : ' ';
  // }else {
  //   $checkbox .= $element['#value'] ? ' ' : ' ';
  // }\
  // $element['#attributes']= array("test");
  $checkbox .= drupal_attributes($element['#attributes']) . ' />';
  // $checkbox .= '</div></div>';
  $checkbox .= "<label class=\"stars\" for=\"" . $element['#id']. "\">" . $element['#title']. "</label>";
  //unset($element['#title']);
  return $checkbox;
}
function bookpoints_custom_radios_before_element($variables){
  /* Uncomment the below line to dump array values */
  $element = $variables['element'];
   $attributes = array();
   if (isset($element['#id'])) {
     //$attributes['id'] = $element['#id'];
   }
   $attributes['class'][] = 'form-radios col-xs-12';
   if (!empty($element['#attributes']['class'])) {
     $attributes['class'] = array_merge($attributes['class'], $element['#attributes']['class']);
   }
   if (isset($element['#attributes']['title'])) {
     $attributes['title'] = $element['#attributes']['title'];
   }
   $html = '<div' . drupal_attributes($attributes) . '>';
   if(!empty($element['#options'])){
     foreach($element['#options'] as $key => $val){
       $html .= theme('radio_before_element', $element[$key]);
     }
   }
   $html .= '</div>';
 return $html;
}
