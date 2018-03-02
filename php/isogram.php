<?php

function isIsogram($word) {
    return (! preg_match('/([a-záéíóú]).*?\1/u', strtolower($word))); 
}

