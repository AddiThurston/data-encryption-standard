#include "DES.h"
#include <bitset>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// The blocks has been padded and is already a vector of binary string
// The key and IV are also binary strings

string CBC_encryption(vector<string> blocks, string key, string IV) {
    string encrypted;
    vector<string> keys = key_gen(key); // generate the keys we'll need

    for (size_t i = 0; i < blocks.size(); i++) {
        // xor the plaintext with the previous plaintext (or the iv)
        if (i == 0) blocks[i] = XOR(blocks[i], IV, blocks[i].length());
        else blocks[i] = XOR(blocks[i], blocks[i - 1], blocks[i].length());

        // encrypt the XORed block
        blocks[i] = encryption(blocks[i], keys);
        encrypted += blocks[i];
    }

    return encrypted;
}

string CBC_decryption(vector<string> blocks, string key, string IV) {
    string decrypted;
    string prev = IV;
    vector<string> keys = key_gen(key);


    for (size_t i = 0; i < blocks.size(); i++) {
	//Temp to save the cipher text
	string current = blocks[i];
	string plain = decryption(current, keys);
	plain = XOR(plain, prev, plain.length());

	decrypted += plain;
	//Update for next round
	prev = current;

    }

    return decrypted;
}
