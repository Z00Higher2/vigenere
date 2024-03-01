// Author: Zuhayer Tashin
// Course: CSCI-135
// Instructor: Tong Yi
// Assignment: Lab 6B
// Write a program vigenere.cpp. It should contain a function encryptVigenere implementing this cipher:
// string encryptVigenere(string plaintext, string keyword);
// You may assume that the keyword contains only lowercase alphabetic characters a - z.

#include <iostream>
#include <cctype>
using namespace std;

char shiftChar(char c, int kshift) {
    if(int(c) >= 65 && int(c) <= 90) { 
        c += kshift; 
        if(c > 90) { 
            c -= 26; 
            return c;
        }
        return c;
    } else if(int(c) >= 97 && int(c) <= 122) { 
        int a = int(c) + kshift; 
        if(a > 122) {
            a -= 26; 
            c = a;
            return c;
        }
        c = a; 
        return c;
    }
    return c;
}

string encryptVigenere(string plaintext, string keyword) {
    char c, keyc;
    int n;
    for(int i = 0; i < plaintext.length(); i++) { 
        if(n > keyword.size() - 1) { 
            n = 0;
        }
        c = plaintext[i]; 
        keyc = keyword[n]; 
        int kshift = (int(keyc) - 97); 
        if(isalpha(c) == 0) {  
            plaintext[i] = shiftChar(c, 0);
        } else {
            plaintext[i] = shiftChar(c, kshift); 
            n++; 
        }
    }
    return plaintext;
}

int main() {
    string plaintext, kshift;

    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    cout << "Enter keyword: ";
    cin >> kshift;

    cout << "Ciphertext: " << encryptVigenere(plaintext, kshift);

    return 0;
}