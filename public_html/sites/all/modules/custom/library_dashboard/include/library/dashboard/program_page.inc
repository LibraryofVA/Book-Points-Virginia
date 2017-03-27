<?php
function program_pages(){
    $output = '';
    $output .= "<div class=\"panel\" id=\"programs_panel\">";
    $output .= views_embed_view('programs');
    $output .= "</div>";
    return $output;

}