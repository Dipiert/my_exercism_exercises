<?php

class Series {
    
    function __construct($serie) {
        if(preg_match('/[^\d]/',$serie)) throw new InvalidArgumentException;
        $this->serie = $serie;
    }

    function largestProduct($n) {   
        $serieLen = strlen($this->serie);
        if($n > $serieLen || $n < 0) throw new InvalidArgumentException;
        $product = 1;
        $largestProduct = 0;
        for($i = 0; $i <= $serieLen - $n; $i++) {
            $slice[$i] = array_slice(str_split($this->serie), $i, $n);
            $largestProduct = max(array_product($slice[$i]),$largestProduct);     
            $product = 1;
        }
        return $largestProduct;     
    }
}

