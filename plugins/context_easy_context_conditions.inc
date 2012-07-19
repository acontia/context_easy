<?php
/////////////////////////// CLASSES MANUALLY DEFINED //////////////////////////
/*
class context_easy_condition_odd_minute extends context_condition {
    
    function condition_values() {
      return array(1 => t("Active"));
    }
    
    function execute() {
      $contexts = $this->get_contexts();
      kpr($contexts);
      foreach ($this->get_contexts() as $context) {
        if (example_ce_check_odd()) {
          $this->condition_met($context);
        }
      }

    }
}

class context_easy_condition_even_minute extends context_condition {
    
    function condition_values() {
      return array(1 => t("Active"));
    }
    
    function execute() {
      $contexts = $this->get_contexts();
      kpr($contexts);
      foreach ($this->get_contexts() as $context) {
        if (example_ce_check_even()) {
          $this->condition_met($context);
        }
      }

    }
}

*/




/////////////////////////// CLASSES AUTO DEFINED //////////////////////////

$context_easys = context_easy_get_contexts();

$classes_definitions = '';

foreach ($context_easys as $key => $context_easy) {

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


// kpr($classes_definitions);
eval($classes_definitions);


// kpr(get_declared_classes());





