<?php
function manage_prizes_page(){
    $output = '';
    $output .= "<div class=\"panel\" id=\"prize_by_program_panel\">";
    $output .= "<form action='/library/dashboard/branches/program/prize/add'>\n";
    $output .= "<input class='button-float' type='submit' value='Add Prize' />\n";
    $output .= "</form>\n";
    $output .= views_embed_view('prize_by_program');
    $output .= "</div>";
    return $output;
}
?>