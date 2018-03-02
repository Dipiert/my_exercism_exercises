<?php

function wordCount(string $phrase) : array {
   $phrase = prepareString($phrase);
   $words = explode(' ', $phrase);  

   array_walk($words, function ($word) use (&$result) {
      if (empty($result[$word])) {
         $result[$word] = 1;
      }
      else {
         $result[$word]++;
      }
   });

   return $result;
}

function prepareString(string $phrase) : string {
   $phrase = trim($phrase);
   $phrase = strtolower($phrase);
   $phrase = preg_replace('/[^a-z0-9\s]/', '', $phrase);
   $phrase = preg_replace('/(\v|\s)+/', ' ', $phrase);
   return $phrase;
}

