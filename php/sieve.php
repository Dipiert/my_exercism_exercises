<?php

function sieve($limit) {
    $result = [];
    $factors = 0;   
    if ($limit < 2) return [];  
    for($i = 2; $i <= $limit; $i++) {
        for($j = 2; $j <= $i && $factors <= 1; $j++) if($i % $j == 0) $factors++;               
        if ($factors == 1) array_push($result, $i);     
        $factors = 0;
    }
    return $result;
}

