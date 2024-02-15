//
// Created by Gaudium on 15.02.2024.
//
#include <iostream>
#include <format>

#include "utils.h"

using namespace std;

int main(){
    int a=3, b=5;

    Swap(a, b);

    cout << format("a={} b={}", a, b) << endl;
}