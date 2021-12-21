#include<bits/stdc++.h>
using namespace std;

string str, plane;
int key=0;

string encryption(string str) {
    for(int i=0; i < str.length(); i++) {
        str[i] = ((str[i] - 65 + key ) % 26) + 65  ;
    }
    return str;
}
string decryption(string str, int key) {
    for(int i=0; i < str.length(); i++) {
        str[i] = (((str[i] - 65) - key) %26) + 65  ;
    }
    return str; 
}
void cryptoanalysis(string str) {
    int local_key = 1;
    string temp = str;
    for(int i=1; i<26; i++) {
       std::cout << decryption(str,i) << endl;
    }
}

int main() {
    cin >> str;
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    plane = str;
    while(1) {
        cout << "please enter key (1-26) : ";
        cin >> key;
        if(key <= 26) break; 
    }
    string enc = encryption(plane);
    cout << "Encryption: " << enc << endl;
    cout << " decrypt: " << decryption(enc, key) << endl;
    cryptoanalysis(enc);
    return 0;
}