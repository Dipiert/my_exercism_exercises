var Binary = function(strNum) {
   this.strNum = strNum;
   this.base = 2;
}

Binary.prototype.toDecimal = function() {
   if (! this.isAValidBinary()) return 0;
   var arrNum = this.strNum.split('');
   var arrDec = [];
   for(var i = 0; i < arrNum.length; i++)
      arrDec[i] = arrNum[i]*Math.pow(this.base,arrNum.length-i-1);	
   return arrDec.reduce((a, b) => a + b, 0);
};

Binary.prototype.isAValidBinary = function() {
   return ! /[^01]+/.test(this.strNum);
}

module.exports = Binary;

