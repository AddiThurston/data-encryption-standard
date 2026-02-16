#include "DES.h"
#include "permutation.h"
#include "des_utils.h"
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
        string expanded(48, ' ');
        for (size_t i = 0; i < 48; i++) {
            expanded[i] = r[E[i]-1];
        }
        expanded = XOR(expanded, keys[round], 48);
        l = r;
    }
    return l+r;
}

string decryption(string encrypted, vector<string> keys) {
    return "";
}
