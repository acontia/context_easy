<?php
/*
class context_easy_reaction_ppppp extends context_condition{

}
*/

/////////////////////////// CLASSES AUTO DEFINED //////////////////////////

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
        ' . $function . '();
      }
    }');
  
  }

}

eval($classes_definitions);



