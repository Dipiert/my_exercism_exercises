<?php

function squareOfSums($n) {
   return pow(($n * ($n + 1) / 2),2);
}

function sumOfSquares($n) {
    return pow($n,3)/3 + pow($n,2)/2 + $n/6;
}

function difference($n) {
   return squareOfSums($n) - sumOfSquares($n);
}

