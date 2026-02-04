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
    for (int i = 0; i < 16; i++) {
        
    }
    return sub_keys;
}
