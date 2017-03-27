<?php 

 $form=drupal_get_form('reader_switch_form');

global $user;

$current_user=user_load($user->uid);

$current_reader=$current_user->field_current_reader['und'][0]['target_id'];

$args_array=array($user->uid);


$view = views_get_view('readers');
$view->set_display('block_2');
$view->set_arguments($args_array);
$view->pre_execute();
$view->execute();


$readers_array=array();

foreach ($view->result as $key=>$value) {

$readers_array[]=$value->id;
}

echo drupal_render($form);

?>

<div id="left-panel-content">
<h2 class="centered-text">Current Reader</h2>
   <div id="tab-container">
      <ul>
        <?php 
        $i=0;
          foreach ($readers_array as $key=>$value) {

            $selected='';

            if ($value==$current_reader) {
              $selected='selected-tab';
            }
            $i++;
            if ($i>4){
              $i=1;
            }
            $entity=entity_load_single('reader', $value);
             echo "<li class='color-". $i ." reader-element " . $selected . "' data-reader-id=" . $value .">" . $entity->field_first_name['und'][0]['value']. "</li>";
          } ?>
      </ul>
      <div class='add-reader'>
      <a href='/reader/dashboard/profile/add'>Add Reader</a>
      </div>
   </div>
</div>