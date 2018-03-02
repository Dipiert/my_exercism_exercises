"use strict";

class primeFactors {
   static for(num) {
      var factors = [];
      var i = 2;
      while (i <= num) {
         if (num % i == 0) {
            factors.push(i);
            num = num / i;	
         }
         else
            i++;         
       }
       return factors;
    }
};

module.exports = primeFactors;

