<?php

/**
 * Returns the render array for the form.
 */
function reader_switch_form($form, &$form_state) {

global $user;

$current_user=$user->uid;

$user_details=galecia_reader_dashboard_check_registration($current_user);

foreach ($user_details as $key => $value) {
 
    $current_reader=$user_details[$key];
}





$args=array($current_user);

$view = views_get_view('readers');
$view->set_display("block");
$view->set_arguments($args);
$view->pre_execute();
$view->execute();

$readers=array();

foreach ($view->result as $key => $value) {

    $readers[$value->id]=$value->field_field_first_name[0]['raw']['value'];

}
  
  $form['reader']=array(
        '#type' => 'select',
        '#title' => t('Who is reading?'),
        '#options' => $readers,
        '#description' => t('Select a Reader')
        );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit'
  );


  return $form;

}

function reader_switch_form_validate($form, &$form_state) {
    }

function reader_switch_form_submit($form, &$form_state) {

    global $user;

    $current_user=$user->uid;

    $selected=$form_state['values']['reader'];

    $user_to_update=user_load($current_user);

    $user_to_update->field_current_reader['und'][0]['target_id']=$selected;

    field_attach_update('user', $user_to_update);

    
    drupal_set_message(t('Switched to a new reader'));
}
