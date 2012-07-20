<?php

$context_easys = context_easy_get_contexts();

$classes_definitions = '';

foreach ($context_easys as $key => $context_easy) {

  $type = $context_easy['type'];

  if ($type == 'condition') {

    $class_name = 'context_easy_condition_' . $key;
    $function = $context_easy['function'];

    $classes_definitions .= ('
    class ' . $class_name . ' extends context_condition {
      
      function condition_values() {
        return array(1 => t("Active"));
      }
      
      function execute() {
        // kpr($this->get_contexts());
        foreach ($this->get_contexts() as $context) {
          if (' . $function . '()) {
            $this->condition_met($context);
          }
        }
      }
    }');
  
  }

}

eval($classes_definitions);

