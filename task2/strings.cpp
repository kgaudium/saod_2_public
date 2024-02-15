//
// Created by Gaudium on 15.02.2024.
//
#include <iostream>
#include <format>
#include <cstring>

#include "utils.h"

using namespace std;



int main(){
    char str[] = "Hello!";

    cout << format("len: {}, sizeof: {}, str: {}", strlen(str), sizeof(str), str) << endl;

    char t[32];
//    for (char *pd = t, *ps = str; *pd++ = *ps++;);

    string_copy(t, str);
    cout << format("t: {}, len: {}, compare to str: {}", t, len(t), compare(t, str)) << endl;
}
