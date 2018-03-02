class Transcriptor {

  toRna(strand) {
    if (strand.match('[^CGAT]')) throw new Error('Invalid input DNA.');
    this.dnaRnaMap = {
      C: 'G',
      G: 'C',
      A: 'U',
      T: 'A',
    };
    return strand.split('')
                 .map(nucleotide => this.dnaRnaMap[nucleotide])
                 .join('');
  }

}

export default Transcriptor;

