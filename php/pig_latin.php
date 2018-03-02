<?php

function translate($str) {
    $consonantSounds = ['y', 'x', 'thr', 'th', 'squ', 'sch', 'r', 'qu', 'q', 'p', 'k', 'f', 'ch'];
    $vowelSounds = ['yt','xr','u','o','i','e','a'];
    $found = false;
    $words = [];
    $strs = explode(" ", $str);
    for($j = 0; $j < count($strs); $j++){
        $word = $strs[$j];  
        for($i = 0; $i < count($vowelSounds) && !$found; $i++){
            if(strrpos($word, $vowelSounds[$i]) === 0) {
                $word .= 'ay';
                $found = true;
            }           
        }
        for($i = 0; $i < count($consonantSounds) && !$found; $i++) {
            if(strrpos($word, $consonantSounds[$i]) === 0) {
                $word .= $consonantSounds[$i] . 'ay';
                $word = substr($word, strlen($consonantSounds[$i]));
                $found = true;
            }               
        }   
        $found = false;
        array_push($words, $word);
    }
    $words = implode(" ", $words);
    return $words;
}

