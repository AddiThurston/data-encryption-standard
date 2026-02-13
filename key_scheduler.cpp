// Group: Addison Thurston and William Kraus
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

    //Convert to left and right halves
    string l = permutedKey.substr(0,28);
    string r = permutedKey.substr(28);

    // 16 rounds of subkey generation
    for (int i = 0; i < 16; i++) {
        // every round has at least one left shift
        l = shift_left(l);
        r = shift_left(r);

        // check for the rounds that we need 2 left shifts
        if (i != 0 && i != 1 && i != 8 && i != 15) {
            l = shift_left(l);
            r = shift_left(r);
	    }
        //Combine blocks and use PC2 to permute the key
        string shiftedKey = l + r;
        string subKey(48,' ');
        for(size_t j = 0; j < 48; j++){
            subKey[j] = shiftedKey[PC2[j]-1];
        }

        sub_keys.push_back(subKey);
    }

    return sub_keys;
}