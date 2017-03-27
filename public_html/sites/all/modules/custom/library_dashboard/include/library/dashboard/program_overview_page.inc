<?php

function program_overview_page(){
    $output = '';
    $id=arg(4);
    $output .= "<div class=\"panel\" id=\"program_level_panel\">";
    $output .= "<form action='/library/dashboard/program/level/add/" . $id. "'>\n";
    $output .= "<input class='button-float' type='submit' value='Add Level' />\n";
    $output .= "</form>\n";
    $output .= views_embed_view('program_level');
    $output .= "</div>";
    return $output;
}