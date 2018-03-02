<?php

function toRoman($num) {

$roman2decimalMap = [
        'M' => 1000,
        'CM' => 900,
        'D' => 500,
        'CD' => 400,
        'C' => 100,
        'XC' => 90,         
        'L' => 50,
        'XL' => 40,
        'X' => 10,
        'IX' => 9,
        'V' => 5,
        'IV' => 4,
        'I' => 1
];

$ret = '';
$remainder = $num;
while($remainder > 0){
    foreach ($roman2decimalMap as $roman => $decimal) {
        if($remainder < $decimal) continue;
        $ret .= $roman;
        $remainder -= $decimal; 
        break;
    }
}
return $ret;
}

