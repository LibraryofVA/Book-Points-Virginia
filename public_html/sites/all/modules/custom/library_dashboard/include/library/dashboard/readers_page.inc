<?php
function reader_page(){
    $output = '';
    $output .= "<div class=\"panel\" id=\"readers_panel\">";
    $output .= views_embed_view('readers', 'block');
    $output .= "</div>";
    return $output;
}
?>