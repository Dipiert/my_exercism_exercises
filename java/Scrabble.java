import java.util.Map;
import java.util.HashMap;

class Scrabble {
   private Map < Character, Integer > word;
   private Map < Character, Integer > values;

   Scrabble(String word) {
      this.word = new HashMap < Character, Integer > ();
      this.values = new HashMap < Character, Integer > ();
      setLetters(word);
      setValues();
   }

   private void setLetters(String word) {
      char[] arr_str = word.toUpperCase().toCharArray();
      Integer cant;
      for (char letter: arr_str)
         if (this.word.containsKey(letter)) {
            cant = this.word.get(letter);
            this.word.put(letter, ++cant);
         }
      else
         this.word.put(letter, 1);
   }

   private void setValues() {
      putValues("AEIOULNRST".toCharArray(), 1);
      putValues("DG".toCharArray(), 2);
      putValues("BCMP".toCharArray(), 3);
      putValues("FHVWY".toCharArray(), 4);
      putValues("K".toCharArray(), 5);
      putValues("JX".toCharArray(), 8);
      putValues("QZ".toCharArray(), 10);
   }

   private void putValues(char[] letters, int value) {
      for (int i = 0; i < letters.length; i++)
         values.put(letters[i], value);
   }

   int getScore() {
      int score = 0;
      for (Map.Entry < Character, Integer > entry: word.entrySet())
         score += values.get(entry.getKey()) * entry.getValue();
      return score;
   }
   
}

