<?php

class Robot {
   private $name;
   static private $generatedNames = [];

   function __construct() {             
      $this->name = $this->setName();
   }

   function getName() {
      return $this->name;
   }

   function setName() {
      return $this->getUniqueName();
   }

   function getUniqueName() {
      while(1) {
         $randomStr = $this->generateCandidate();
         if (! in_array($randomStr, Robot::$generatedNames)) {
            $cantRobots = count(Robot::$generatedNames);
            Robot::$generatedNames[$cantRobots] = $randomStr;
            return $this->name = $randomStr;                      
         }  
      }
   }

   function generateCandidate() {
      $randomStr = $this->generateLetters(2) . $this->generateNumbers(3);
      if (! Robot::$generatedNames) Robot::$generatedNames[0] = $randomStr;  
      return $randomStr;
   }

   function reset() {
      $this->name = $this->setName();
   }

   function generateLetters($cant) {
      $letters = '';
      for($i = 0; $i < $cant; $i++)
         $letters .= (mt_rand(0,1) >= .5)? chr(mt_rand(65,90)) : chr(mt_rand(97,122));
      return $letters;
   }

   function generateNumbers($cant) {
      $numbers = '';
      for($i = 0; $i < $cant; $i++) $numbers .= mt_rand(0,9);
      return $numbers;
   }
}

