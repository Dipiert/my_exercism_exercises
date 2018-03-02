<?php

function distance($a, $b)
{
   $distance = 0;
   verifyLength($a,$b);   
   for($i = 0; $i < strlen($a); $i++)   
      if($b[$i] !== $a[$i])      
         $distance++;   
   return $distance;
}

function verifyLength($a,$b)
{
   if (strlen($a) !== strlen($b))
      throw new InvalidArgumentException('DNA strands must be of equal length.');
}

