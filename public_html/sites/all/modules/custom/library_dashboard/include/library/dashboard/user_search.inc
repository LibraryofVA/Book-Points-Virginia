<?php
function user_search(){
    $output = '';
    $output .= "<div class=\"panel\" id=\"user_search_panel\">";
    $output .= views_embed_view('user_search');
    $output .= "</div>";
    return $output;
}
?>