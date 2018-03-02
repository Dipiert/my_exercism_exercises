<?php

function isPangram($str){
   if(empty($str)) return false;
   $str = strtolower($str);
   $letters = getLetters();
   for($i = 0; $i < strlen($str); $i++)
      $letters[$str[$i]] = 1;	
   return array_sum($letters) == count($letters);
}	

function getLetters(){	
   foreach(range('a','z') as $letter)
      $arr[$letter] = 0;
   return $arr;
}

