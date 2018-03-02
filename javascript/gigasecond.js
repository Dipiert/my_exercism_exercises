var Gigasecond = function(time) {
   this.time = time.getTime();
}

Gigasecond.prototype.date = function(){
   return new Date(this.time + Math.pow(10,12));
}
module.exports = Gigasecond;

