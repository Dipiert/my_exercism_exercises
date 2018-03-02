var Bob = function() {};

Bob.prototype.hey = function(phrase) {
   phrase = phrase.trim();
   if (phrase === phrase.toUpperCase() && new RegExp('[a-zA-Z]').test(phrase))
      return "Whoa, chill out!";		
   if (phrase.endsWith("?"))
      return "Sure.";	
   if (phrase === '')
      return "Fine. Be that way!";
   else return "Whatever.";
}

module.exports = Bob;

