<?php
/**
 * @file
 * quiz_rewards_bundle.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function quiz_rewards_bundle_default_rules_configuration() {
  $items = array();
  $items['rules_quiz_completed_badges_and_points'] = entity_import('rules_config', '{ "rules_quiz_completed_badges_and_points" : {
      "LABEL" : "Quiz Completed - Badges and Points",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "bookpoints", "ebadge" ],
      "REQUIRES" : [ "rules", "userpoints_rules", "flag" ],
      "ON" : { "flag_flagged_claim" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "flagged-node" ],
            "type" : "node",
            "bundle" : { "value" : { "quiz_award" : "quiz_award" } }
          }
        }
      ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "flagging-user" ],
            "points" : [ "flagged-node:field-points-awarded" ],
            "tid" : "8",
            "entity" : [ "flagged-node" ],
            "description" : "Claimed Activity: [flagged-node:title]",
            "operation" : "Claimed",
            "display" : "1",
            "moderate" : "default"
          }
        },
        { "list_add" : {
            "list" : [ "flagging-user:field-my-ebadges" ],
            "item" : [ "flagged-node:field-ebadge-awarded" ],
            "unique" : "1",
            "pos" : "start"
          }
        }
      ]
    }
  }');
  return $items;
}
