var Pangram = function (sentence) {
   this.sentence = sentence;
   this.letters = new Set();
   this.cantLetters = 26;
}

Pangram.prototype.isPangram = function(){
   if(this.sentence === undefined)
      return false;   
   this.sanitize(this.sentence)
       .split('')
       .forEach(letter => this.letters.add(letter)); 
   return this.letters.size == this.cantLetters;

}

Pangram.prototype.sanitize = function(sentence){
   return sentence.toLowerCase().replace(/[^a-z]/g, "");
}

module.exports = Pangram;

