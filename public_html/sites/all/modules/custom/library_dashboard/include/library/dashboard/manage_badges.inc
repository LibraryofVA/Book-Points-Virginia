<?php
function manage_badges(){
    $output = '';
    $output .= "<div class=\"panel\" id=\"badge_view_panel\">";
    $output .= "<form action='/library/dashboard/branches/program/badge/add'>\n";
    $output .= "<input class='button-float' type='submit' value='Add Badge' />\n";
    $output .= "</form>\n";
    $output .= views_embed_view('badge_view');
    $output .= "</div>";
    return $output;
}