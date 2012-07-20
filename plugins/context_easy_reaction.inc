<?php

/*
class context_easy_reaction_context_easy_test_reaction extends context_reaction {
  // @todo Check why we need to define this class (even commented!!) to get the plugin
  // loaded
}
*/


$context_easys = context_easy_get_contexts();

$classes_definitions = '';

foreach ($context_easys as $key => $context_easy) {

  $type = $context_easy['type'];

  if ($type == 'reaction') {

    $class_name = 'context_easy_reaction_' . $key;
    $function = $context_easy['function'];

    $classes_definitions .= ('
    class ' . $class_name . ' extends context_reaction {
      
      function options_form($context) {
        return array("' . $class_name . '" => array("#type" => "value", "#value" => TRUE));
      }

      function options_form_submit($values) {
        return array("' . $class_name . '" => 1);
      }
      
      function execute() {
        $contexts = context_active_contexts();
        foreach ($contexts as $context) {
          if (!empty($context->reactions["' . $class_name . '"])) {
            ' . $function . '();
          }
        }
      }
    }');
  
  }

}

eval($classes_definitions);

