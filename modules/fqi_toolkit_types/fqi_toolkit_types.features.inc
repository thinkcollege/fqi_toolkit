<?php
/**
 * @file
 * fqi_toolkit_types.features.inc
 */

/**
 * Implements hook_node_info().
 */
function fqi_toolkit_types_node_info() {
  $items = array(
    'facilitators_guide_home' => array(
      'name' => t('Facilitators Guide home'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'unit_home' => array(
      'name' => t('Unit Home'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
