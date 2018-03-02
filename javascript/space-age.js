var SpaceAge = function(seconds) {
    this.seconds = seconds;
    this.earthDays = this.seconds/(60*60*24*365.25);
}

SpaceAge.prototype.onEarth = function() {
    return this.earthDays.toFixed(2)/1;
}

SpaceAge.prototype.onMercury = function() {
    return (this.earthDays/0.2408467).toFixed(2)/1;
}

SpaceAge.prototype.onVenus = function() {
    return (this.earthDays/0.61519726).toFixed(2)/1;
}

SpaceAge.prototype.onMars = function() {
    return (this.earthDays/1.8808158).toFixed(2)/1;
}

SpaceAge.prototype.onJupiter = function() {
    return (this.earthDays/11.862615).toFixed(2)/1;
}

SpaceAge.prototype.onSaturn = function() {
    return (this.earthDays/29.447498).toFixed(2)/1;
}

SpaceAge.prototype.onUranus = function() {
    return (this.earthDays/84.016846).toFixed(2)/1;
}

SpaceAge.prototype.onNeptune = function() {
    return (this.earthDays/164.79132).toFixed(2)/1;
}

module.exports = SpaceAge;

