<?php

function from($date){
   $newDate = clone $date;
   return $newDate->setTimestamp($date->getTimestamp() + 1000000000);
}

