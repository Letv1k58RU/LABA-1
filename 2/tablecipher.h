#pragma once
#include <string>
#include <locale>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
class tablecipher {
private:
    int st;
public:
    tablecipher(int key);
    tablecipher() = delete;
    string encrypt(string text);
    string decrypt(string text);
};