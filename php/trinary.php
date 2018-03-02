<?php

function toDecimal(string $number) : int {    
    if (preg_match('/[^0-2]/', $number)) return 0;
    $len = strlen($number);
    $result = 0;
    for($i = 0; $i < $len; $i++)
        $result += $number[$i] * (3**($len - $i - 1)); 
    return $result;
}

