<?php

function toRna($dnaStrand){
    $dnaArr = str_split($dnaStrand);
    $rnaArr = array_map('getRnaComplement', $dnaArr);
    return implode($rnaArr);
}

function getRnaComplement($nucleotide){
    switch ($nucleotide) {
        case 'G': return 'C';
        case 'C': return 'G';
        case 'T': return 'A';
        case 'A': return 'U';
    }
}

