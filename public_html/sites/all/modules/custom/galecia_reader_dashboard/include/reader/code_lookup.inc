<?php

/**
 * Returns the render array for the form.
 */
function code_search_form($form, &$form_state) {


  
  $form['codes']=array(
        '#type' => 'textfield',
        '#title' => t('Enter a secret code!')
        ,
        '#attributes' => array(
        'autocomplete' => 'off',
        ),
        );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit'
  );


  return $form;

}

function code_search_form_validate($form, &$form_state) {

global $user;

$current_user=$user->uid;

$loaded_user=user_load($user->uid);


$user_details=galecia_reader_dashboard_check_registration($current_user);

foreach ($user_details as $key => $value) {
 
    $current_reader=$user_details[$key];
}


$current_loaded_reader_id=$loaded_user->field_current_reader['und'][0]['target_id'];

$current_loaded_reader=entity_load_single('reader', $current_loaded_reader_id);




$args=array($current_loaded_reader->field_program['und'][0]['target_id']);

$view = views_get_view('secret_codes_view');
$view->set_display("block");
$view->set_arguments($args);
$view->pre_execute();
$view->execute();

$codes=array();

$valid=TRUE;


foreach ($view->result as $key => $value) {

    $codes[$value->id]=strtolower($value->field_field_activity_code[0]['raw']['value']);

}


    $valid_options=$codes;


    $input=strtolower($form_state['input']['codes']);

    $checked_input='';

    foreach($valid_options as $key => $value) {

       if($input==$value) {
        $checked_input=$key;
        $form_state['values']['codes']=array($current_loaded_reader_id, $checked_input);
       }

    }

    if (empty($checked_input)) {
        form_set_error('codes', 'Invalid entry');
    }

    if (!empty($checked_input)) {

        $loaded_code=entity_load_single('activity', $checked_input);

        $loaded_code_id=$loaded_code->id;


        if(!empty($current_loaded_reader->field_claimed_activities)) {
        
            foreach($current_loaded_reader->field_claimed_activities['und'] as $key => $value) {

                if ($value['target_id'] === $loaded_code_id) {

                    form_set_error('codes', t('You have already entered this code!'));
                    $valid=FALSE;
                }

            }

        }

        if ($valid==TRUE) {
        drupal_set_message(t('Valid entry'));
        }
    }
    }

function code_search_form_submit($form, &$form_state) {

    global $user;

    $submitted_code=$form_state['values']['codes'];

    $reader_id=(int)$submitted_code[0];

    $readers=entity_load_single('reader', $reader_id);

    $code_id=(int)$submitted_code[1];

    $loaded_code=entity_load_single('activity', $code_id);

    $activity_log = entity_create('activity_log', array('type' => 'activity_log'));

    $activity_points=(int)$loaded_code->field_activity_points['und'][0]['value'];

    $wrapper = entity_metadata_wrapper('activity_log', $activity_log);
                $wrapper->uid = $user->uid;
                $wrapper->title = $loaded_code->field_activity_code['und'][0]['value'] . 'code claim' . $reader_id;
         
                $wrapper->field_readers = array($reader_id);
                $wrapper->field_secret_code_reference = $code_id;

                if(!empty($loaded_code->field_activity_points)) {
                    $wrapper->field_points_earned = $activity_points;
                }
                if(!empty($loaded_code->field_reader_badge)) {
                    $wrapper->field_reader_badge = $loaded_code->field_reader_badge['und'][0]['target_id'];
                }

                $wrapper->save();

                $readers->field_claimed_activities['und'][]['target_id']=(array)$code_id;

                     entity_save('reader', $readers);

                       galecia_model_leveler($reader_id);

                       drupal_set_message(t('You added a code!'));

}
