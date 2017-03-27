<?php
function add_drawing_ticket_pages(){
    $output = '';
    $output .= "<div class=\"panel\" id=\"drawing_ticket_panel\">";
    $output .= "<div class=\"panel-header\">";
    $output .= "<h3>" . t("Drawing Ticket") . "</h3>";
    $output .= "</div>";
    $output .= "<div class=\"panel-body\">";
    $output .= views_embed_view('drawing_ticket');
    $output .= "</div>";  //close panel-body
    $output .= "</div>";  //close panel
    $bundle_name = 'drawing_ticket';
    $entity_type_name = 'drawing_ticket';
    module_load_include('inc', 'eck', 'eck.entity');
    $form = eck__entity__add($entity_type_name, $bundle_name);
    $output .= drupal_render($form);
    return $output;
}