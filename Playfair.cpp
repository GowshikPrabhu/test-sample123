#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const string alphabet = "abcdefghijklmnopqrstuvwxyz";

string cleanWords(string word) {
    string res;
    vector<char> vec;

    for (int i = 0; i < word.length(); i++) {
        if (word[i] == ' ') {
            continue;
        }
        if (find(vec.begin(), vec.end(), word[i]) == vec.end()) {
            if (word[i] == 'j') {
                if (find(vec.begin(), vec.end(), 'i') == vec.end()) {
                    vec.push_back('i');
                }
            }
            else {
                vec.push_back(word[i]);
            }
        }
    }

    for (int i = 0; i < vec.size(); i++) {
        res.push_back(vec[i]);
    }

    return res;
}

string formatMsg(string msg) {
    string temp;
    for (int i = 0; i < msg.length(); i++) {
        if (msg[i] == 'j') {
            temp.push_back('i');
        }
        else if (msg[i] == ' ') {
            continue;
        }
        else {
            temp.push_back(msg[i]);
        }
    }

    string fmtMsg;
    for (int i = 0; i < temp.length(); i += 2) {
        if (i + 1 >= temp.length()) {
            fmtMsg.push_back(temp[i]);
            fmtMsg.push_back('x');
        }
        else {
            if (temp[i] != temp[i + 1]) {
                fmtMsg.push_back(temp[i]);
                fmtMsg.push_back(temp[i + 1]);
            }
            else {
                fmtMsg.push_back(temp[i]);
                fmtMsg.push_back('x');
                --i;
            }
        }
    }

    return fmtMsg;
}

string findPos(vector<vector<char>> m, char x) {
    string res;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (m[i][j] == x) {
                res.push_back('0' + i);
                res.push_back('0' + j);
            }
        }
    }
    return res;
}

void encrypt(string msg, string key) {
    string fmtKey = cleanWords(key);
    string allChars = fmtKey + alphabet;
    string finalWords = cleanWords(allChars);
    vector<vector<char>> matrix;
    int k = 0;
    for (int i = 0; i < 5; i++) {
        vector<char> temp;
        for (int j = 0; j < 5; j++) {
            temp.push_back(finalWords[k]);
            k++;
        }
        matrix.push_back(temp);
    }

    cout << "\n=============\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "=============\n";

    string pt = formatMsg(msg);
    for (int i = 0; i < pt.length(); i += 2) {
        cout << pt[i] << pt[i + 1] << " ";
    }

    string fnlString;
    for (int i = 0; i < pt.length(); i += 2) {
        string char1Pos = findPos(matrix, pt[i]);
        string char2Pos = findPos(matrix, pt[i + 1]);
        int char1[] = { char1Pos[0] - '0', char1Pos[1] - '0' };
        int char2[] = { char2Pos[0] - '0', char2Pos[1] - '0' };

        if (char1[0] == char2[0]) {
            fnlString.push_back(matrix[char1[0]][(char1[1] + 1) % 5]);
            fnlString.push_back(matrix[char2[0]][(char2[1] + 1) % 5]);
        }
        else if (char1[1] == char2[1]) {
            fnlString.push_back(matrix[(char1[0] + 1) % 5][char1[1]]);
            fnlString.push_back(matrix[(char2[0] + 1) % 5][char2[1]]);
        }
        else {
            fnlString.push_back(matrix[char1[0]][char2[1]]);
            fnlString.push_back(matrix[char2[0]][char1[1]]);
        }
    }
    cout << "\n";
    for (int i = 0; i < fnlString.length(); i += 2) {
        cout << fnlString[i] << fnlString[i + 1] << " ";
    }

    return;
}


int main() {
    string msg;
    string key;

    cout << "Enter the string to encrypt: ";
    getline(cin, msg);
    cout << "Enter the key: ";
    cin >> key;
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    transform(msg.begin(), msg.end(), msg.begin(), ::tolower);

    cout << "\nEncrypting....\n";
    encrypt(msg, key);
    cout << "\n";

    return 0;
}
