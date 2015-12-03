<?php
/**
 * @file
 * toolkit_fields.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function toolkit_fields_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_validation" && $api == "default_field_validation_rules") {
    return array("version" => "2");
  }
}
