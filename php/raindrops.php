<?php 

function raindrops($number) {
   $ret = '';
   $num2char = [3 => 'i', 5 => 'a', 7 => 'o'];
   foreach ($num2char as $key => $value)
      if ($number % $key == 0) $ret .= 'Pl' . $value . 'ng';   
   return $ret ?:"$number";
}

