<?php
/**
 * @file
 * toolkit_fields.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function toolkit_fields_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Teacher validation code';
  $rule->name = 'teach_validation';
  $rule->field_name = 'field_teacher_verification';
  $rule->col = 'value';
  $rule->entity_type = 'user';
  $rule->bundle = 'user';
  $rule->validator = 'field_validation_pcre_validator';
  $rule->settings = array(
    'data' => '/^587210(.*?)$/',
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      3 => 0,
      4 => 0,
    ),
    'errors' => 0,
  );
  $rule->error_message = 'Wrong teacher validation code';
  $export['teach_validation'] = $rule;

  return $export;
}
