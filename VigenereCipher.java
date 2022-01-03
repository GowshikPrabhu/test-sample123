import java.util.*;

public class VigenereCipher {
    static String encode(String text, final String key) {
        String res = "";
        text = text.toUpperCase();
        for (int i = 0, j = 0; i < text.length(); i++) {
            char c = text.charAt(i);
            if (c < 'A' || c > 'Z') {
                continue;
            }
            res += (char) ((c + key.charAt(j) - 2 * 'A') % 26 + 'A');
            j = ++j % key.length();
        }
        return res;
    }

    static String decode(String text, final String key) {
        String res = "";
        text = text.toUpperCase();
        for (int i = 0, j = 0; i < text.length(); i++) {
            char c = text.charAt(i);
            if (c < 'A' || c > 'Z') {
                continue;
            }
            res += (char) ((c - key.charAt(j) + 26) % 26 + 'A');
            j = ++j % key.length();
        }
        return res;
    }

    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the string for encryption: ");
        String message = new String();
        message = sc.nextLine();
        System.out.print("Enter the key for encryption: ");
        String key = new String();
        key = sc.nextLine();
        key = key.toUpperCase();
        System.out.println("Input message : " + message);
        String enc = encode(message, key);
        System.out.println("Encoded message : " + enc);
        System.out.println("Decoded message : " + decode(enc, key));
        sc.close();
    }
}