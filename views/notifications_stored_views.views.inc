<?php
/**
 * @file
 */

/**
 * Implementation of hook_views_data_alter().
 */
function notifications_stored_views_views_data_alter(&$data) {
  // Node.
  if (!empty($data['node']['nid'])) {
    $data['node']['nid_in'] = array(
      'title' => t('Nid (in)'),
      'help' => t('Nid in a list.'),
      'real field' => 'nid',
      'filter' => array(
        'handler' => 'notifications_stored_views_handler_filter_in_operator',
      ),
    );
  }

  // MN data.
  if (!empty($data['feeds_data_syndication']['id'])) {
    $data['feeds_data_syndication']['id_in'] = array(
      'title' => t('Id (in)'),
      'help' => t('Id in a list.'),
      'real field' => 'id',
      'filter' => array(
        'handler' => 'notifications_stored_views_handler_filter_in_operator',
      ),
    );
  }
}

/**
 * Implementation of hook_views_handlers().
 */
function notifications_stored_views_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'notifications_stored_views') . '/views',
    ),
    'handlers' => array(
      'notifications_stored_views_handler_filter_in_operator' => array(
        'parent' => 'views_handler_filter_in_operator',
      ),
    ),
  );
}

/**
 * Implementation of hook_views_plugins().
 */
function notifications_stored_views_views_plugins() {
  $plugins = array(
    'style' => array(
      'notifications_stored_views' => array(
        'title' => t('Notifications stored views'),
        'help' => t('.'),
        'handler' => 'notifications_stored_views_plugin_style',
        'theme' => 'notifications_stored_views_view_style',
        'uses row plugin' => TRUE,
        'uses grouping' => FALSE,
        'uses options' => TRUE,
        'type' => 'normal',
        'parent' => 'parent',
        'path' => drupal_get_path('module', 'notifications_stored_views') . '/views',
        'theme path' => drupal_get_path('module', 'notifications_stored_views') . '/theme',
      ),
    ),
    'row' => array(
      'notifications_stored_views' => array(
        'title' => t('Notifications stored views'),
        'help' => t('.'),
        'handler' => 'notifications_stored_views_plugin_row',
        'theme' => 'notifications_stored_views_view_row',
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
        'parent' => 'parent',
        'path' => drupal_get_path('module', 'notifications_stored_views') . '/views',
        'theme path' => drupal_get_path('module', 'notifications_stored_views') . '/theme',
      ),
    ),
  );

  return $plugins;
}

/**
 * Themes.
 */

/**
 * @see function template_preprocess_views_view_unformatted().
 */
function template_preprocess_notifications_stored_views_view_style(&$vars) {
}

/**
 * @see function template_preprocess_views_view_fields().
 */
function template_preprocess_notifications_stored_views_view_row(&$vars) {
  $view = $vars['view'];

  $vars['fields'] = array();
  foreach ($view->field as $id => $field) {
    $field_output = $view->style_plugin->get_field($view->row_index, $id);
    $vars['fields'][$id] = (string)$field_output;
  }
}
