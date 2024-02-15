//
// Created by Gaudium on 14.02.2024.
//
#include <iostream>
#include <format>

using namespace std;
int main(){
    // problem1
    int x = 3;
    int* p = &x;

    cout << format("{} ({}) at address: ", x,*p) << p << endl;

    p++;
    cout << format("{} ({}) at address: ", x,*p) << p << endl;

    cout << p - &x << endl;

    // problem2
    typedef unsigned char byte;
    byte* pb = (byte*)--p;

    for (byte* pt = pb; pt - pb<sizeof(int); pt++)
        cout<<(int)*pt << ' ';

    cout << endl;
}