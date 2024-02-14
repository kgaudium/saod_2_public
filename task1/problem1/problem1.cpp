//
// Created by Gaudium on 08.02.2024.
//
#include <iostream>
#include <format>

using namespace std;
int main()
{
    cout << "Hello World!" << endl;

    int x, y;
    cout << "x:";
    cin >> x;
    cout << "y:";
    cin >> y;
    cout << format("{} + {} = {}", x, y, x+y) << endl;
    cout << format("{} - {} = {}", x, y, x-y) << endl;
    cout << format("{} * {} = {}", x, y, x*y) << endl;
    cout << format("{} / {} = {}", x, y, x/y) << endl;
    cout << format("{} % {} = {}", x, y, x%y) << endl;
    cout << format("{} | {} = {}", x, y, x|y) << endl;
    cout << format("{} & {} = {}", x, y, x&y) << endl;
    cout << format("{} ^ {} = {}", x, y, x^y) << endl;
    cout << format("{} << {} = {}", x, y, x<<y) << endl;
    cout << format("{} >> {} = {}", x, y, x>>y) << endl;
}
