#include "key_utils.h"
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

string shift_left(string sub_key){
    // write code from here
    sub_key = sub_key.substr(1) + sub_key[0];   // shifting left is simple
    return sub_key;
}

vector<string> key_gen(string key){
    vector<string> sub_keys;
    //write code from here

    // use PC1 to permute the initial key
    string permutedKey(56,' ');
    for (size_t i = 0; i < 56; i++) {
        permutedKey[i] = key[PC1[i]-1];
    }
    cout << permutedKey << endl;


    for (int i = 0; i < 16; i++) {
        
    }
    return sub_keys;
}
