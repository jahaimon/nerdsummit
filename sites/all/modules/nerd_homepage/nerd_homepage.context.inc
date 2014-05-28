<?php
/**
 * @file
 * nerd_homepage.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function nerd_homepage_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'login_register_form_display';
  $context->description = 'Login/Register Form Display';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
      ),
    ),
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'nerd_homepage-login-registration-block' => array(
          'module' => 'nerd_homepage',
          'delta' => 'login-registration-block',
          'region' => 'highlighted',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Login/Register Form Display');
  $export['login_register_form_display'] = $context;

  return $export;
}