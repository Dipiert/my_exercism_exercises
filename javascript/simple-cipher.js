var Cipher = function(key) {
    this.key = (key === undefined) ? this.generateRandomKey(100) : key; 
    this.isValidKey();  
    this.shift = this.getShift();   
}

Cipher.prototype.generateRandomKey = function(length){
    var possibles = "abcdefghijklmnopqrstuvwxyz";
    var key = '';
    for(var i = 0; i < length; i++)
        key += possibles.charAt(Math.floor(Math.random * possibles.length));
    return key;
}

Cipher.prototype.isValidKey = function() {
    if (this.key === this.key.toUpperCase()) throw Error('Bad key');
    if (isFinite(String(this.key))) throw Error('Bad key');
    if (this.key == '') throw Error('Bad key');
}

Cipher.prototype.getShift = function() {
    var shift = [];
    for (var i = 0; i < this.key.length; i++)
        shift.push(this.key[i].charCodeAt() - 'a'.charCodeAt());    
    return shift;
}

Cipher.prototype.encode = function(plaintext) {
    if(this.key.length < plaintext.length) throw new Error('The text is longer than the key');
    var charCodes;
    plaintext = plaintext.toLowerCase();
    charCodes = this.getCharcodeRepresentation(plaintext);
    charCodes = this.shiftCharCodes(charCodes);
    return this.getStringRepresentation(charCodes);
}

Cipher.prototype.getCharcodeRepresentation = function(plaintext) {
    var charCodes = [];
    for (var i = 0; i < plaintext.length; i++)
        charCodes.push(plaintext[i].charCodeAt());
    return charCodes;
}

Cipher.prototype.shiftCharCodes = function(charCodes) {
    for (var i = 0; i < charCodes.length; i++) {
        charCodes[i] += (charCodes[i] + this.shift[i] > 'z'.charCodeAt()) ?
            this.shift[i] - ('z'.charCodeAt() + 1) + 'a'.charCodeAt() 
        :   this.shift[i];
    }
    return charCodes;
}

Cipher.prototype.getStringRepresentation = function(charCodes) {
    var string = '';
    for (var i = 0; i < charCodes.length; i++)
        string += String.fromCharCode(charCodes[i]);
    return string;
}

Cipher.prototype.decode = function(encoded) {
    if(this.key.length < encoded.length) throw new Error('The encoded text is longer than the key');
    var plaintext;
    var charCodes = this.getCharcodeRepresentation(encoded);
    charCodes = this.unshiftCharCodes(charCodes);
    return this.getStringRepresentation(charCodes);
}

Cipher.prototype.unshiftCharCodes = function(charCodes) {
    for (var i = 0; i < charCodes.length; i++){
        charCodes[i] -= (charCodes[i] - this.shift[i] < 'a'.charCodeAt()) ? 
            this.shift[i] + 'z'.charCodeAt() + 1 - 'a'.charCodeAt() 
        :   this.shift[i]; 
    }
    return charCodes;
}

module.exports = Cipher;

