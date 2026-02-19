#include "DES.h"
#include "permutation.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string encryption(string plaintext, vector<string> keys) {
    string initialPermutation(64, ' ');
    for (size_t i = 0; i < 64; i++) {
        initialPermutation[i] = plaintext[IP[i]-1];
    }
    string l = initialPermutation.substr(0,32);
    string r = initialPermutation.substr(32);

    for (int round = 0; round < 16; round++) {
        string tempL = l;   // store the initial left half to use it in xor later
        l = r;  // the left half becomes the old right half
        // then, we just do the order of operations in the chart
        r = expansion(r);
        r = XOR(r, keys[round], 48);
        r = sBox(r);
        r = pBox(r);
        r = XOR(r, tempL, 32);
    }

    // permute the final combo of r+l
    string combo = r+l;
    string finalPermutation(64, ' ');
    for (size_t i = 0; i < 64; i++) {
        finalPermutation[i] = combo[FP[i]-1];
    }
    return finalPermutation;
}

string decryption(string encrypted, vector<string> keys) {
    string initialPermutation(64, ' ');
    for (size_t i = 0; i < 64; i++){
        initialPermutation[i] = encrypted[IP[i]-1];
    }
    string l = initialPermutation.substr(0,32);
    string r = initialPermutation.substr(32);

    for (int round = 15; round >= 0; round--){
        string tempL = l;
        l = r;
        r = expansion(r);
        r = XOR(r, keys[round], 48);
        r = sBox(r);
        r = pBox(r);
        r = XOR(r, tempL, 32);
    }

    string combo = r+l;
    string finalPermutation(64, ' ');
    for (size_t i = 0; i < 64; i++) {
        finalPermutation[i] = combo[FP[i]-1];
    }

    return finalPermutation;
}
