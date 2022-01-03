import java.util.*;

class RailFence {
    int depth;

    String Encryption(String plainText, int depth) throws Exception {
        int r = depth, len = plainText.length();
        int c = len / depth;
        char mat[][] = new char[r][c];
        int k = 0;
        String cipherText = "";

        for (int i = 0; i < c; i++) {
            for (int j = 0; j < r; j++) {
                if (k != len)
                    mat[j][i] = plainText.charAt(k++);
                else
                    mat[j][i] = 'X';
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cipherText += mat[i][j];
            }
        }
        return cipherText;
    }

    String Decryption(String cipherText, int depth) throws Exception {
        int r = depth, len = cipherText.length();
        int c = len / depth;
        char mat[][] = new char[r][c];
        int k = 0;
        String plainText = "";

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                mat[i][j] = cipherText.charAt(k++);
            }
        }
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < r; j++) {
                plainText += mat[j][i];
            }
        }
        return plainText;
    }
}

public class RailfenceCipher {
    public static void main(String args[]) throws Exception {
        RailFence rf = new RailFence();
        Scanner sc = new Scanner(System.in);
        int depth;
        String plainText, cipherText, decryptedText;

        System.out.print("Enter plain text: ");
        plainText = sc.nextLine();

        System.out.print("Enter depth for Encryption: ");
        depth = sc.nextInt();

        cipherText = rf.Encryption(plainText, depth);
        System.out.println("Encrypted text is:\n" + cipherText);

        decryptedText = rf.Decryption(cipherText, depth);
        System.out.println("Decrypted text is:\n" + decryptedText);
        sc.close();
    }
}
