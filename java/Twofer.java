public class Twofer {
    public String twofer(String name) { 
        StringBuilder sb = new StringBuilder("One for ");
        sb.append((name == null)? "you" : name);
        return sb.append(", one for me.").toString();
    }
}

