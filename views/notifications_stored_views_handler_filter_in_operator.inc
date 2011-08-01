<?php

/**
 * .
 */
class notifications_stored_views_handler_filter_in_operator extends views_handler_filter_in_operator {

  function get_value_options() {
    return array();
  }

  function value_form(&$form, &$form_state) {
    parent::value_form($form, $form_state);

    $form['value'] = array(
      '#type' => 'textfield',
      '#title' => $form['value']['#title'],
      '#default_value' => implode(',', $form['value']['#default_value']),
      '#prefix' => $form['value']['#prefix'],
      '#suffix' => $form['value']['#suffix'],
    );
  }

  function value_submit($form, &$form_state) {
    $form_state['values']['options']['value'] = array_unique(array_filter(array_map('intval', array_map('trim', explode(',', $form_state['values']['options']['value'])))));
  }
}
