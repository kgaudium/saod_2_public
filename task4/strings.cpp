//
// Created by Gaudium on 22.02.2024.
//
#include <iostream>
#include <cstring>
#include "Str.h"

using std::cout, std::endl;
void Test(Str s){};


int main(){
    Str s("ghi");

    cout << s << " length: " << std::strlen(s) << endl;
    Test(s);
    cout << s << " length: " << std::strlen(s) << endl;

    Str t = "def";
    t = s = t;

    cout << t << " t length: " << std::strlen(t) << endl;
    cout << s << " s length: " << std::strlen(s) << endl;

    s += t + "abc";
    cout << s << " s length: " << std::strlen(s) << endl;
    Str c = s + t;
    cout << c << " c length: " << std::strlen(c) << endl;
}

