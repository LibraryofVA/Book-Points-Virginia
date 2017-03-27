<?php
function reader_overview (){
    $reader_id=arg(4);

    $reader_args=array($reader_id);

    $reader_view = views_get_view('readers');
    $reader_view->set_display('block_3');
    $reader_view->set_arguments($reader_args);
    $reader_view->pre_execute();
    $reader_view->execute();
	$reader_fname=$reader_view->result[0]->field_field_first_name[0]['raw']['value'];
	$reader_lname=$reader_view->result[0]->field_field_last_name[0]['raw']['value'];
	$parent_user=$reader_view->result[0]->users_field_data_field_parent_uid_name;
	$age=$reader_view->result[0]->field_field_age[0]['raw']['value'];
	$grade=$reader_view->result[0]->field_field_grade[0]['raw']['value'];
	$school=$reader_view->result[0]->field_field_reader_school[0]['rendered']['#markup'];
	$program_name=$reader_view->result[0]->eck_program_field_data_field_program_title;
	$program_units=$reader_view->result[0]->field_field_per_unit_label[0]['raw']['value'];

    $reader_badges_view = views_get_view('reader_badge_by_reader');
    $reader_badges_view->set_display('block');
    $reader_badges_view->set_arguments($reader_args);
    $reader_badges_view->pre_execute();
    $reader_badges_view->execute();

    $uris_array=array();

    foreach($reader_badges_view->result as $key=>$value){

        $uris_array[]=$value->field_field_badge_image[0]['raw']['uri'];

    }

    $reader_prizes_view = views_get_view('prize_per_reader');
    $reader_prizes_view->set_display('block');
    $reader_prizes_view->set_arguments($reader_args);
    $reader_prizes_view->pre_execute();
    $reader_prizes_view->execute();



    $allprizes=array();

    foreach($reader_prizes_view->result as $key=>$value){

        if (!empty($value->eck_prize_field_data_field_prize_reference_title)) {
            $prize_name=$value->eck_prize_field_data_field_prize_reference_title;
        }
        $prize_status=$value->field_field_status[0]['rendered']['#markup'];
        $prize_id=$value->id;


        $allprizes[]= array($prize_name, $prize_status, $prize_id) ;

    }


    $reader_tickets_view = views_get_view('tickets_by_reader');
    $reader_tickets_view->set_display('block');
    $reader_tickets_view->set_arguments($reader_args);
    $reader_tickets_view->pre_execute();
    $reader_tickets_view->execute();

    $alltickets=array();

    foreach($reader_tickets_view->result as $key=>$value){

        $alltickets[]=$value->eck_reader_ticket_title;

    }

    $reading_log_view = views_get_view('reading_log_by_reader');
    $reading_log_view->set_display('block');
    $reading_log_view->set_arguments($reader_args);
    $reading_log_view->pre_execute();
    $reading_log_view->execute();

    $allunits=array();

    foreach($reading_log_view->result as $key=>$value){

        $allunits[]=(int)$value->field_field_units_completed[0]['raw']['value'];

    }

    $current_units=array_sum($allunits);

    $reader_points_view = views_get_view('reader_points_for_reader');
    $reader_points_view->set_display('block');
    $reader_points_view->set_arguments($reader_args);
    $reader_points_view->pre_execute();
    $reader_points_view->execute();

    $allpoints=array();

    foreach($reader_points_view->result as $key=>$value){

        $allpoints[]=(int)$value->field_field_points[0]['raw']['value'];

    }

    $current_points=array_sum($allpoints);

    $output = '';
    $output .= "<div class=\"reader\">\n";
    $output .= t("Reader: ") . $reader_fname. " " . $reader_lname . " <span class='right-float'>" . $current_points . t("pts") . "</span>";
    $output .= "</div>\n";
    $output .= "<div class=\"parent_user\">";
    $output .= t("Parent User: ") . $parent_user;
    $output .= "</div>";
    $output .= "<div class=\"reader_ed_info\">";
    $output .= t("Age: ") . $age . t(" Grade: ") . $grade . t(" School: ") . $school;
    $output .= "</div>";
    $output .= "<div class=\"reader_update_panel\"><form action='/reader/reader/" . $reader_id . "/edit'>";
    $output .= "<input class='right-float' type='submit' value='Edit' />\n";
    $output .= "</form></div>";
    $output .= "" . $program_name . " <span class='right-float'>" . $current_units . " " . $program_units . t("Read") . "</span>";
    foreach ($allprizes as $key=>$value) {

        $title=$value[0];
        $status=$value[1];
        $id=$value[2];
    
        $output .= "<div class=\"prizes_panel\"><table><tr><td class='three-col-table'>Prize: " . $title . " </td><td class='three-col-table'>" . t("Status: ") . $status . "   </td><td class='three-col-table'>" . t("Claim Link:");

        if ($status=='Unclaimed') { 

        $output .= "<a href='/claim/" . $id ."/prize'>" . t("Claim") . "</a></td></tr></table></div>";
        }

        if ($status=='Claimed') { 

        $output .= "<a href='/unclaim/" . $id ."/prize'>" . t("Unclaim") . "</a></td></tr></table></div>";
        }
        
    }
    $output .= "<div class=\"add_activity_panel\">\n";
    $output .= "<form action='/reader/dashboard/program/activity/add/" . $reader_id . "'>\n";
    $output .= "<input class='right-float' type='submit' value='Enter' />\n";
    $output .= "</form>\n";
    $output .= "</div>\n";
    $output .= "<div class=\"panel badges-container\" id=\"drawing_ticket_panel\">\n";
    $output .= "<div class=\"panel-header\">\n";
    $output .= "<h3>" . t("Badges Earned") . "</h3>\n";
    $output .= "</div>\n";
    $output .= "<div class=\"panel-body\">\n";
    foreach($uris_array as $value) {
        $output .= "<div class='badge-small-div'><img src='" . file_create_url($value). "'></div>\n";
    }
    $output .= "</div>\n";  //close panel-body
    $output .= "</div>\n";  //close panel
    $output .= "<div class=\"panel badges-container\" id=\"tickets_earned_panel\">\n";
    $output .= "<div class=\"panel-header\">\n";
    $output .= "<h3>" . t("Drawing Tickets Earned") . "</h3>\n";
    $output .= "</div>\n";
    $output .= "<div class=\"panel-body\">\n";
    $output .= "<ul>\n";
    foreach ($alltickets as $key=>$value) {
        $output .= "<li>" . $value . "</li>\n";
    };
    $output .= "</ul>\n";
    $output .= "</div>\n";
    
    return $output;
}
?>
