function SecretHandshake(decimal) {
    if (typeof decimal != 'number')
        throw Error('Handshake must be a number');  
    this.decimal = decimal;
    this.gestures = {
        "wink": "00001",
        "double blink": "00010",
        "close your eyes": "00100",
        "jump": "01000",
        "reverseOrder": "10000",
    }
    this.binary = decimal.toString(2).lpad('0',5);  
}

SecretHandshake.prototype.isPowerOfTwo = function() {
    for (var i = 0; i <= 4; i++) {
        if (this.decimal === Math.pow(2,i)) {
            return true;
        }
    }
    return false;
}

SecretHandshake.prototype.searchGesture = function(valueToFind) {
    var secret = [];
    for (var prop in this.gestures) {
        if (this.gestures[prop] === this.binary)
            secret.push(prop);
    }
    return secret;  
}

SecretHandshake.prototype.commands = function() {
    if (this.isPowerOfTwo()) {
        return this.searchGesture();
    } else {
        return this.decomposingFactors();
    }
}

SecretHandshake.prototype.searchKey = function(value) {
    for (prop in this.gestures) {
        if (this.gestures[prop] === value) return prop; 
    } 
} 

SecretHandshake.prototype.decomposingFactors = function() { 
    var secret = [], power, factor, valueToFind, gesture;
    var reverse = true;
    var lastIndex = this.binary.indexOf('1', 0);    
    while (lastIndex != -1) {       
        valueToFind = this.getValueToFind(lastIndex)
        if (valueToFind == this.gestures['reverseOrder']) reverse = false;      
        gesture = this.searchKey(valueToFind);
        if (gesture) secret.push(gesture);  
        lastIndex = this.binary.indexOf('1', lastIndex + 1);
    }
    if (reverse) secret.reverse();
    return secret;          
}

SecretHandshake.prototype.getValueToFind = function(lastIndex) {
    var power = this.binary.length - lastIndex - 1;
    var factor = Math.pow(2,power);
    return factor.toString(2).lpad('0',5);
}

String.prototype.lpad = function(padString, length) {
    var str = this;
    while (str.length < length)
        str = padString + str;
    return str;
}

module.exports = SecretHandshake;