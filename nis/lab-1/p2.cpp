#include<bits/stdc++.h>
using namespace std;

string str, key_str;
int key[26];
string str2;
string user_str;
string t;

void shuffle_array(int arr[], int n)
{

    // To obtain a time-based seed
    unsigned seed = 0;

    // Shuffling our array using random_shuffle
    
    random_shuffle(arr, arr + n);
    
    // Printing our array
    // for (int i = 0; i < n; ++i)
    //     cout << arr[i] << " ";
    // cout << endl;
}

void encryption() {
    str2 = user_str;
    for(int i=0; i < str2.length(); i++) {
        //str2[i] = ((str[i] + key ) % 26) + 65  ;
        int temp = str2[i] - 65;
        str2[i] = key[temp];  
    }
    cout << str2 << "\n";
}

void decryption() {
    t = str2;
    str2 = "";
    
    for(int i=0; i < t.length(); i++) {
        
        
        
        int j = 0;
        while(t[i] != key[j]) {
            
            j++;
        }
        //cout << j << endl;
        
        t[i] = str[j];
        //cout << t[0] ;
    }
    cout << t << "\n";
}

int main() {


    //suffle key
    for(int i=0; i<26; i++) {
        key[i] = i+1;
    }
    int n = sizeof(key) / sizeof(key[0]);
    shuffle_array(key, n);
    // for(int i=0; i<26; i++) {
    //     cout << key[i] << endl;
    // }
    for(int i=0; i<26; i++) {
        key[i] = key[i] + 64;
        key_str[i] = key[i];
        //cout << key_str[i] << endl;
    }

    
    
    //str array done
    for(int i=0; i<26; i++) {
        str[i] = 65 + i;
       // cout << str[i] << endl;
    }

    
    cin >> user_str;
    transform(user_str.begin(), user_str.end(), user_str.begin(), ::toupper);

    encryption();
    decryption();


    
    return 0;
}