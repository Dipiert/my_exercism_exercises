<?php

function detectAnagrams(string $word, array $list) : array {
    $word = mb_strtolower($word); 
    return array_values(
              array_filter(
                 array_map(
                    function($s) use($word){
                       $_s = mb_strtolower($s);
                       if($word != $_s && count_chars($word, 1) == count_chars($_s, 1)) return $s;
                    }, $list
                 )
              )
            );
}

