#include "modAlphaCipher.h"
#include "modAlphaCipher.cpp"
#include <iostream>
using namespace std;
void check(const wstring& Text, const wstring& key)
{
    wstring cipherText;
    wstring decryptedText;
    modAlphaCipher cipher(key);
    cipherText = cipher.encrypt(Text);
    decryptedText = cipher.decrypt(cipherText);
    wcout << L"Ключ=" << key << endl;
    wcout << Text << endl;
    wcout << cipherText << endl;
    wcout << decryptedText << endl;
    if(Text == decryptedText)
        wcout << L"ОК\n";
    else
	 	wcout << L"Плохо\n";
}
int main(int argc, char** argv)
{
	std::locale loc("ru_RU.UTF-8");
	std::locale::global(loc);
    check(L"ПРИВЕТ", L"АЛЕКСЕЙ");
    check(L"ЭТОЛАБАПЕРВАЯ", L"БЕЛОВ");
    return 0;
}
