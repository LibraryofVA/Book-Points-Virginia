<?php 

global $user;
global $language ;
$lang_name = $language->language ;

$current_user=user_load($user->uid);

$current_reader=$current_user->field_current_reader['und'][0]['target_id']
;

$entity=entity_load_single('reader', $current_reader);

$current_reader_fname=$entity->field_first_name['und'][0]['value'];

  $form=drupal_get_form('reading_activity_form');

?>     

<div>

<h2 class='centered-text'>Track Your Reading</h2>

   <?php print drupal_render($form); ?>
</div>
