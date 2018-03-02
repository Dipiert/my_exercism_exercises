var Year = function(input) {
   this.value = input;
};

Year.prototype.isLeap = function() {
if (this.value % 4 === 0)
    if (this.value % 100 !== 0 || (this.value % 100 === 0 && this.value % 400 === 0))
        return true;
return false;
}

module.exports = Year;

