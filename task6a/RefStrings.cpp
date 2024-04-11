//
// Created by Gaudium on 10.04.2024.
//
#include <iostream>
#include "Str.h"


int main(){
    Str string {"Hello world!"};

    string += "asd"; // string = Hello world!asd

    std::cout << string.rfind("", 20) << std::endl; // -1

    std::cout << string.rfind("o", 10) << std::endl; // 7

    std::cout << string.rfind("o", 7) << std::endl; // 4

    std::cout << string.rfind("llo", 4) << std::endl; // 2

    std::cout << string.rfind("H", 20) << std::endl; // 0
}