<?php 

function galecia_reader_dashboard_theme($existing, $type, $theme, $path) {
    return array(
        'radios_before_element' => array(
                'render element' => 'element',
                'function' => 'bookpoints_custom_radios_before_element'
            ),

        'radio_before_element' => array(
                'render element' => 'element',
                'function' => 'bookpoints_custom_radio_before_element'
            ),
  );
}

function reading_activity_form($form, &$form_state){

        $stars_options=array(
            'Five'=>t('Five'),
            'Four'=>t('Four'),
            'Three'=>t('Three'),
            'Two'=>t('Two'),
            'One'=>t('One'),
            );

  		$form['book']=array(
        '#type' => 'textfield',
        '#placeholder' => t('Enter Title'),
        );

        $form['author']=array(
        '#type' => 'textfield',
        '#placeholder' => t('Enter Author(s) (optional)'),
        );

  		$form['units']=array(
        '#type' => 'textfield',
        '#placeholder' => t('Enter a number'),
        );

        $form['stars']=array(
        '#type' => 'radios',
        '#options' => $stars_options,
        '#title' => t('Rate this book!'),
        '#description' => t(''),
        '#theme' => 'radios_before_element',
        );

        $form['program_id']=array(
        '#type' => 'hidden',
        );

  		$form['profile_id']=array(
        '#type' => 'hidden',
        );

        $form['unit_type']=array(
        '#type' => 'hidden',
        );


	  	$form['submit'] = array(
	    '#type' => 'submit',
	    '#value' => 'Submit',
	  );

	  	return $form;

}

 function reading_activity_form_validate($form, $form_state) {


    if ($form_state['input']['unit_type'] == 'Points Per Book') {

        if(empty($form_state['input']['book'])) {
            form_set_error('book', t('You must enter a book title!'));
        }

    }

    if (!empty($form_state['values']['units'])) {


    $input=$form_state['values']['units'];

    }

        if (!is_numeric($input)) {
            form_set_error('units', t('You must enter a number'));
        }
  
}


	function reading_activity_form_submit($form, &$form_state) {

        $results=$form_state['values'];

        $units=$results['units'];

        $program_id=array($results['program_id']);

        $profile_id=$results['profile_id'];

        $entity_type='reading_log';
        $entity = entity_create($entity_type, array('type' => 'reading_log'));
        $wrapper = entity_metadata_wrapper($entity_type, $entity);
        $wrapper->field_book_title = $results['book'];
        $wrapper->field_author = $results['author'];
        $wrapper->field_stars = $results['stars'];
        $wrapper->title = $results['book'];
        $wrapper->field_unit_type = $results['unit_type'];
        $wrapper->field_units_completed = $results['units'];
        $wrapper->field_readers->set(array($results['profile_id']));
        $wrapper->field_program_reference->set($program_id);
        // $points_earned=points_getter($units, $program_id);
        // $wrapper->field_points_earned = $points_earned;
        // profile_updater($points_earned, $profile_id, $program_id );

        $wrapper->save();

        // drupal_set_message("Congratulations! You earned " . $points_earned . " points! You can enter another activity or navigate back to the dashboard." );

	
	}

    // function points_getter($units, $program) {

    //     $program_load=entity_load_single('program', $program);

    //     $points=$program_load->field_per_unit_point_value['und'][0]['value'];

    //     $points_earned=$points * $units;

    //     return $points_earned;


    // }

    // function profile_updater($points_earned, $profile_id, $program_id) {

    //     $reader_load=entity_load_single('reader', $profile_id);

    //     $current_points=$reader_load->field_points['und'][0]['value'];

    //     $updated_points=$current_points + $points_earned;

    //     $reader_load->field_points['und'][0]['value']=$updated_points;

    //     $reader_load->save();

    //     $program_load=entity_load_single('program', $program_id);

    //     level_updater($profile_id, $program_id);

    // }


    //     function level_updater($profile_id, $program_id){

    //     $program_load=entity_load_single('program', $program_id);

    //     $level=entity_load('level');

    //     $matching_levels=array();

    //     foreach ($level as $key => $value) {
    //         if ($value->field_program_reference['und'][0]['target_id'] == $program_id) {
    //             $matching_levels[]=$value;
    //         }
    //     }


    //     $reader_load=entity_load_single('reader', $profile_id);

    //     $current_points=$reader_load->field_points['und'][0]['value'];


    //     foreach ($matching_levels as $level => $contents) {

    //         if($current_points >= $contents->field_point_threshold['und'][0]['value']) {

    //             $current_level_badge=$contents->field_level_badge['und'][0]['tid'];

    //             $badge_term = taxonomy_term_load($current_level_badge);
    //             $badge_name = $badge_term->name;

    //             $current_level=$contents->id;



    //         }
    //     }

    //     if ($reader_load->field_level['und'][0]['target_id']!=$current_level) {

    //     $reader_load->field_level['und'][0]['target_id']=$current_level;

    //     drupal_set_message("Congratulations! You increased your level." );

    //     }

    //     if ($reader_load->field_my_badges['und'][0]['tid']!=$current_level_badge) {
    //         // dsm($reader_load);

    //         // array_push($reader_load->field_all_badges, $reader_load->field_my_badges['und'][0]['tid']);

    //     if (!empty($reader_load->field_all_badges)) { 

    //     $count=count($reader_load->field_all_badges['und']);
    //     }else {
    //         $count=0;
    //     }

    //     $reader_load->field_all_badges['und'][$count]['tid']=$reader_load->field_my_badges['und'][0]['tid'];

    //     $reader_load->field_my_badges['und'][0]['tid']=$current_level_badge;

    //     drupal_set_message("Congratulations! You earned the " . $badge_name . " badge!");

    //     }

    //     $reader_load->save();


    // }


 ?>
