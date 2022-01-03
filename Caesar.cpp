#include <iostream>

using namespace std;

const string alphabet = "abcdefghijklmnopqrstuvwxyz";

string encrypt(string msg, int shift) {
    string res;

    for (int i = 0; i < msg.length(); i++) {
        int idx = alphabet.find(msg[i]);
        int newIdx = (idx + shift) % 26;
        char replaceChar = alphabet[newIdx];
        res.push_back(replaceChar);
    }
    return res;
}

string decrypt(string cipher, int shift) {
    string res;

    for (int i = 0; i < cipher.length(); i++) {
        int idx = alphabet.find(cipher[i]);
        int newIdx = (idx - shift) % 26;
        if (newIdx < 0) {
            newIdx += alphabet.length();
        }
        char replaceChar = alphabet[newIdx];
        res.push_back(replaceChar);
    }

    return res;
}

int main() {
    string message;

    cout << "Enter the string to encrypt: ";
    cin >> message;

    cout << "\nEncrypting....\n";
    cout << "\nEncrypted text: " << encrypt(message, 3);
    cout << "\nDecrypted text: " << decrypt(encrypt(message, 3), 3);
}
