public class Hamming {
   private char[] leftStrand;
   private char[] rightStrand;

    Hamming(String leftStrand, String rightStrand) {
       this.leftStrand = leftStrand.toCharArray();
       this.rightStrand = rightStrand.toCharArray();
       isEqualLength();
    }

    private void isEqualLength() {
       if (leftStrand.length != rightStrand.length)
       throw new IllegalArgumentException("leftStrand and rightStrand must be of equal length.");
    }

    int getHammingDistance() {
       int distance = 0;       
       for(int i = 0; i < leftStrand.length; i++)
          if (leftStrand[i] != rightStrand[i])
             distance++;
       return distance;
    }
}

