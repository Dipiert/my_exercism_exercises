<?php

class Bob
{

   private $answers = [ "shout" => "Whoa, chill out!",
                        "ask" => "Sure.",
                        "silent" => "Fine. Be that way!",
                        "genericAnswer" => "Whatever."
                      ];

   function respondTo($say)
   {
      $say = trim($say);
      if ($this->isShouting($say)) return $this->answers["shout"];
      if ($this->isAsking($say)) return $this->answers["ask"];
      if ($this->isSilent($say)) return $this->answers["silent"]; 
      return $this->answers["genericAnswer"];
   }

   function isShouting($say)
   {  
      if (!mb_check_encoding($say, 'ASCII')) 
         $say = $this->toASCII($say);      
      return ctype_upper(preg_replace('/[^a-z]+/i', "", $say));
   }

   function isAsking($say)
   {
      return substr($say, -1) === "?";
   }

   function toASCII($str)
   {
        $nonASCII = 'ŠŒŽšœžŸ¥µÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖØÙÚÛÜÝßàáâãäåæçèéêëìíîïðñòóôõöøùúûüýÿ';
        $ASCIIRepresentation = 'SOZsozYYuAAAAAAACEEEEIIIIDNOOOOOOUUUUYsaaaaaaaceeeeiiiionoooooouuuuyy';
        return strtr(utf8_decode($str), utf8_decode($nonASCII), $ASCIIRepresentation);
   }

   function isSilent($say)
   {
      $whiteSpaces = ['\u000b', '\u00a0', '\u2002', '\n', '\r', '\t'];
      $say = str_replace($whiteSpaces, '', $say);
      return empty($say);
   }

}

