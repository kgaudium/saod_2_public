//
// Created by Gaudium on 15.02.2024.
//

#include "utils.h"

void Swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void string_copy(char* d, char* s){
    for (char *pd = d, *ps = s; *pd++ = *ps++;);
}

int len(const char* s){
    int result = 0;
    for (; s[result] != '\0'; result++);
    return result;
}

int compare(const char* s, const char* t){
    return len(s) - len(t);
}