<?php
function branches_page(){
    $output = '';
    $output .= "<div class=\"panel\" id=\"branches_panel\">";
    $output .= views_embed_view('branches');
    $output .= "</div>";
    return $output;
}
?>