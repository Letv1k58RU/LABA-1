#include "tablecipher.h"
tablecipher::tablecipher(int key) { 
    st = key;
    }
string tablecipher::encrypt(string text)
{
    string text1;
    for(char c:text) {
    if (c != ' ') { text1 += c; }
        }
    text = text1;
    int s = text.length();
    int str = ceil(double(s) / st);
    char tab[str][st];
    string res;
    int index = 0;
    for(int a = 0; a < str; ++a) {
        for(int b = 0; b < st; ++b) {
            tab[a][b] = text[index];
            index++;
        }
    }
    for(int i = st - 1; i >= 0; --i) {
        for(int j = 0; j < str; ++j) {
            if(tab[i][j] != ' ') {
                res += tab[j][i];
            }
        }
    }
    return res;
}
string tablecipher::decrypt(string text)
{
    string text1;
    for(char c:text) {
    if (c != ' ') { text1 += c; }
        }
    text = text1;
    int s = text.length();
    int p = s;
    string res;
    int str = ceil(double(s) / st);
    char tab[str][st];
    for (int x = 0; x < s; x++) {
        if (p%st != 0) {
        p++;
    } else {
        break;
    }
    }
    int n = p-s;
    int h = str - 1;
    int z = 0;
    for (int j = st - 1; j >= 0; --j) {
            if (z < n) {
            tab[h][j] = ' ';
            z++;
            } else {
                break;
            }
    }
    int index = 0;
    for (int i = st - 1; i >= 0; --i) {
        for (int j = 0; j < str; ++j) {
            if (index < s and tab[j][i] != ' ') {
                tab[j][i] = text[index];
                index++;
            }
            }
        }
    for (int a = 0; a < str; ++a) {
        for (int b = 0; b < st; ++b) {
            if (tab[a][b] != ' ') {
                res += tab[a][b];
            }
        }
    }
    return res;
}