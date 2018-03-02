public class RnaTranscription {

   public String transcribe(String dnaStrand) {
      char[] transcription = dnaStrand.toCharArray();
      for (int i = 0; i < transcription.length; i++) {
         transcription[i] = getRnaComplement(transcription[i]);
      }
      return new String(transcription);
   }

   private char getRnaComplement(char dnaNucleotide) {
      switch (dnaNucleotide) {
         case 'C':
            return 'G';
         case 'G':
            return 'C';
         case 'T':
            return 'A';
         case 'A':
            return 'U';
      }
      return dnaNucleotide;
   }
  
}

