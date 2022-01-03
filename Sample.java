import java.util.ArrayList;

public class Sample {
    public static ArrayList<String> makePairs(String plainText) {
        int countRepeat = 0, len = plainText.length();
        for (int i = 0; i < len - 1; i++) {
            char cur = plainText.charAt(i);
            char next = plainText.charAt(i + 1);
            if (cur == next && cur != ' ')
                countRepeat++;
        }
        ArrayList<String> pairs = new ArrayList<String>();
        for (int i = 0; i < len - 1; i++) {
            char cur = plainText.charAt(i);
            char next = plainText.charAt(i + 1);
            if (cur == ' ' || next == ' ')
                continue;
            if (cur != next) {
                pairs.add(plainText.substring(i, i + 2));
                i++;
            } else {
                pairs.add(new StringBuilder().append(cur).append("x").toString());
            }
        }
        return pairs;
    }

    public static void main(String[] args) {
    }
}
