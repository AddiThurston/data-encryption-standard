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
    cout <<"56 bit permutation: "<< permutedKey << endl;

    //Convert to left and right blocks
    string leftBlock = permutedKey.substr(0,28);
    string rightBlock = permutedKey.substr(28,28);

    //Left shift blocks
    for (int i = 0; i < 16; i++) {
        if(i == 0 || i == 1 || i == 8 || i == 15){
		leftBlock = shift_left(leftBlock);
		rightBlock = shift_left(rightBlock);
	}
	else{
		for(int j = 0; j < 2; j++){
		    leftBlock = shift_left(leftBlock);
		    rightBlock = shift_left(rightBlock);
		}
	}
	//Combine blocks and execute PC-2
	string shiftedKey = leftBlock + rightBlock;
	string pc2key(48,' ');
	for(size_t j = 0; j < 48; j++){
		pc2key[j] = shiftedKey[PC2[j]-1];
	}
	sub_keys.push_back(pc2key);
    }

    for(int i = 0; i < sub_keys.size(); i++){
	cout << "Subkey round "<< i <<": "<<sub_keys[i]<<endl;
    }
    return sub_keys;
}

int main(){

	string key = "0001001100110100010101110111100110011011101111001101111111110001";
	key_gen(key);

	return 0;
}
