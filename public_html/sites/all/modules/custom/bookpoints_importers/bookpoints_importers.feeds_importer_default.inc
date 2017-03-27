<?php
/**
 * @file
 * bookpoints_importers.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function bookpoints_importers_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_activities';
  $feeds_importer->config = array(
    'name' => 'Import Activities',
    'description' => 'Bookpoints: Activity Importer (Admin Setup)',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'delete_uploaded_file' => FALSE,
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsEntityProcessorActivity',
      'config' => array(
        'values' => array(
          'id' => '',
          'title' => '',
          'uid' => '',
          'created' => NULL,
          'language' => 'und',
        ),
        'authorize' => TRUE,
        'mappings' => array(
          0 => array(
            'source' => 'import id',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'description',
            'target' => 'field_activity_description',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'points',
            'target' => 'field_activity_points',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '0',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'activity',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['import_activities'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_badges';
  $feeds_importer->config = array(
    'name' => 'Import Badges',
    'description' => 'Bookpoints: Badge Importer (Admin Setup)',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'delete_uploaded_file' => FALSE,
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsEntityProcessorBadge',
      'config' => array(
        'values' => array(
          'id' => '',
          'title' => '',
        ),
        'authorize' => TRUE,
        'mappings' => array(
          0 => array(
            'source' => 'import id',
            'target' => 'guid',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'description',
            'target' => 'field_badge_description',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'image url',
            'target' => 'field_badge_image:uri',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'message',
            'target' => 'field_badge_message',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'badge',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['import_badges'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_branches';
  $feeds_importer->config = array(
    'name' => 'Import Branches',
    'description' => 'Bookpoints: Branch Importer (Admin Setup)',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'delete_uploaded_file' => FALSE,
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsEntityProcessorBranch',
      'config' => array(
        'values' => array(
          'id' => '',
          'title' => '',
          'uid' => '',
          'created' => NULL,
        ),
        'authorize' => TRUE,
        'mappings' => array(
          0 => array(
            'source' => 'import id',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'name',
            'target' => 'title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'address',
            'target' => 'field_branch_address:thoroughfare',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'city',
            'target' => 'field_branch_address:locality',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'state',
            'target' => 'field_branch_address:administrative_area',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'zip',
            'target' => 'field_branch_address:postal_code',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'phone',
            'target' => 'field_branch_phone',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '0',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'branch',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['import_branches'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_prizes';
  $feeds_importer->config = array(
    'name' => 'Import Prizes',
    'description' => 'Bookpoints: Prize Importer (Admin Setup)',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'delete_uploaded_file' => FALSE,
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsEntityProcessorPrize',
      'config' => array(
        'values' => array(
          'id' => '',
          'title' => '',
          'uid' => '',
          'created' => NULL,
        ),
        'authorize' => TRUE,
        'mappings' => array(
          0 => array(
            'source' => 'import id',
            'target' => 'guid',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'description',
            'target' => 'field_prize_description',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'message',
            'target' => 'field_prize_message',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '0',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'prize',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['import_prizes'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_schools';
  $feeds_importer->config = array(
    'name' => 'Import Schools',
    'description' => 'Bookpoints: School Importer (Admin Setup)',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'delete_uploaded_file' => FALSE,
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsEntityProcessorSchool',
      'config' => array(
        'values' => array(
          'id' => '',
          'title' => '',
        ),
        'authorize' => TRUE,
        'mappings' => array(
          0 => array(
            'source' => 'import id',
            'target' => 'guid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'address',
            'target' => 'field_school_address_',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '0',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'school',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['import_schools'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_secret_codes';
  $feeds_importer->config = array(
    'name' => 'Import Secret Codes',
    'description' => 'Bookpoints: Secret Code Importer (Admin Setup)',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'delete_uploaded_file' => FALSE,
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsEntityProcessorActivity',
      'config' => array(
        'values' => array(
          'id' => '',
          'title' => '',
          'uid' => '',
          'created' => NULL,
          'language' => 'und',
        ),
        'authorize' => TRUE,
        'mappings' => array(
          0 => array(
            'source' => 'import id',
            'target' => 'guid',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'description',
            'target' => 'field_activity_description',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'points',
            'target' => 'field_activity_points',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'secret code',
            'target' => 'field_activity_code',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '0',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'secret_code',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['import_secret_codes'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_staff_accounts';
  $feeds_importer->config = array(
    'name' => 'Import Staff Accounts',
    'description' => 'Bookpoints: Staff Account Importer (Admin Setup)',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => 0,
        'allowed_extensions' => 'txt csv tsv xml opml',
        'delete_uploaded_file' => 1,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
          'private' => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'bundle' => 'user',
        'roles' => array(
          5 => '5',
          3 => 0,
          4 => 0,
        ),
        'update_existing' => '0',
        'status' => '1',
        'mappings' => array(
          0 => array(
            'source' => 'import id',
            'target' => 'field_library_card',
            'unique' => FALSE,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'name',
            'target' => 'name',
            'unique' => 0,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'mail',
            'target' => 'mail',
            'unique' => 1,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'created',
            'target' => 'created',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'first name',
            'target' => 'field_first_name',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'last name',
            'target' => 'field_last_name',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'defuse_mail' => 0,
        'insert_new' => '1',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => FALSE,
  );
  $export['import_staff_accounts'] = $feeds_importer;

  return $export;
}
