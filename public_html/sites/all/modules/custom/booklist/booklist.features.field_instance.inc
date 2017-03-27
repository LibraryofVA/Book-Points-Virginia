<?php
/**
 * @file
 * booklist.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function booklist_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'field_collection_item-field_booklist_books-field_bl_b_author'.
  $field_instances['field_collection_item-field_booklist_books-field_bl_b_author'] = array(
    'bundle' => 'field_booklist_books',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the author of the book.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_bl_b_author',
    'label' => 'Book Author',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_booklist_books-field_bl_b_image'.
  $field_instances['field_collection_item-field_booklist_books-field_bl_b_image'] = array(
    'bundle' => 'field_booklist_books',
    'deleted' => 0,
    'description' => 'Upload an image of the book\'s cover',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_bl_b_image',
    'label' => 'Cover Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'book_list_covers',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_booklist_books-field_bl_b_link'.
  $field_instances['field_collection_item-field_booklist_books-field_bl_b_link'] = array(
    'bundle' => 'field_booklist_books',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter a link to your ILS or online catalog entry for this book.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => NULL,
        'settings' => array(),
        'type' => NULL,
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_bl_b_link',
    'label' => 'Catalog Link',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'value',
      'title_label_use_field_label' => 1,
      'title_maxlength' => 128,
      'title_value' => 'Reserve this book!',
      'url' => 'optional',
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => NULL,
      'settings' => array(),
      'type' => NULL,
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_booklist_books-field_bl_b_title'.
  $field_instances['field_collection_item-field_booklist_books-field_bl_b_title'] = array(
    'bundle' => 'field_booklist_books',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the title of the book',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_bl_b_title',
    'label' => 'Book Title',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-book_list-body'.
  $field_instances['node-book_list-body'] = array(
    'bundle' => 'book_list',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => FALSE,
    'settings' => array(
      'display_summary' => TRUE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'node-book_list-field_booklist_books'.
  $field_instances['node-book_list-field_booklist_books'] = array(
    'bundle' => 'book_list',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter your books using this form.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Add',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_booklist_books',
    'label' => 'Books',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 32,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body');
  t('Book Author');
  t('Book Title');
  t('Books');
  t('Catalog Link');
  t('Cover Image');
  t('Enter a link to your ILS or online catalog entry for this book.');
  t('Enter the author of the book.');
  t('Enter the title of the book');
  t('Enter your books using this form.');
  t('Upload an image of the book\'s cover');

  return $field_instances;
}
