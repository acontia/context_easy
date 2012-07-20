DESCRIPTION
===========

  Context Easy provides a hook to create easily simple custom Context conditions
  and reactions.

  Normally creating custom conditions and reactions involves implementing
  hook_context_plugins() and hook_context_registry(), writing condition and
  reaction plugin classes and add in Drupal integration points.

  With Context Easy you just need to implement hook_context_easy() and everything
  else will be automatically done for you.

EXAMPLE
=======

  The following example would provide one condition and one reaction:

  /**
   * Implements hook_context_easy().
   *
   * @return
   * An array of Context conditions and reactions.
   * The corresponding array value is an associative array that may contain the
   * following key-value pairs:
   *   - "title": Required. The untranslated title of the condition/reaction.
   *   - "description": The untranslated description of the condition/reaction.
   *   - "type": Required. It must be either "conditon" or "reaction"
   *   - "function": Required. The function to call. If type is "condition", the
   *     function should return TRUE for an active context or FALSE for an
   *     inactive Context.
   */
  function YOURMODULE_context_easy() {
    $contexts['randomize'] = array(
      'type' => 'condition',
      'title' => 'Random',
      'description' => 'Set this context randomly (with a probability of 50%)',
      'function' => 'check_random',
    );
      
    $contexts['show_date'] = array(
      'type' => 'reaction',
      'title' => 'Shows current date',
      'description' => 'Show the current date as a message',
      'function' => 'show_current_date',
    );
    
    return $contexts;  
  }

  Make sure you have defined the functions specified in the hook definition:

  /**
   * If this function returns TRUE the condition will be active
   */
  function check_random() {
    return rand(0, 1);
  }

  function show_current_date() {
    drupal_set_message(date('c'));
  }



NOTES
=====

  - If you need to provide more advanced functionality, like adding options to the
    condition or reaction, you should probably check the Context documentation
    (http://drupal.org/project/context) and write a proper plugin, which gives you
    more flexibility.
  - All the conditions and reactions provided using Context Easy will be executed
    on hook_init().
  - Similar functionality is provided by the module Context PHP. The main
    difference is that Context Easy doesn't store code in the database.

