import java.util.HashSet;
import java.util.Set;

public class PangramChecker {

    public boolean isPangram(String input) {
        final Set<Character> set = new HashSet<Character>();
        final int cantLetters = 26; 
        char[] letters = sanitize(input).toCharArray();
        for(char letter: letters){
           set.add(letter);
        }
        return cantLetters == set.size();
    }

    private String sanitize(String input) {
       return input.toLowerCase().replaceAll("[^a-z]", "");
    }
}

