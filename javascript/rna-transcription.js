var DnaTranscriber = function(){}

DnaTranscriber.prototype.isValidInput = function(DNAStrand){
  if (new RegExp('[^CGATU]').test(DNAStrand)) throw new Error('Invalid input');
}

DnaTranscriber.prototype.toRna = function(DNAStrand){
  this.isValidInput(DNAStrand);
  return DNAStrand.split('').map(function(nucleotide){
    switch(nucleotide){
      case 'C': return 'G'; break;
      case 'G': return 'C'; break;
      case 'A': return 'U'; break;
      case 'T': return 'A'; break;    
    }
  }).join('');
}

module.exports = DnaTranscriber;

