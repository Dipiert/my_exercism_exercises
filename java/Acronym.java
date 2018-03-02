import java.util.regex.Pattern;
import java.util.regex.Matcher;

class Acronym {
   private String phrase;

    Acronym(String phrase) {
        this.phrase = phrase;
    }

    String get() {
       return concatenateGroups(Pattern.compile("\\b([a-zA-Z])")
                                       .matcher(phrase))
                                       .toUpperCase();
    }

    String concatenateGroups(Matcher matcher){
       StringBuilder str = new StringBuilder();
       while(matcher.find())
          str.append(matcher.group());
       return str.toString();
    }
}

