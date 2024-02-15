//
// Created by Gaudium on 15.02.2024.
//
#include <iostream>

using namespace std;

void Rotate(int a[], int n, bool clockwise=false);

int main(){
    int a[5] {1,2,3,4,5};

    for (int i=0; i<5; i++)
        cout << a[i] << " ";
    cout << endl;

    for(int* p = a; p-a<5; p++)
        cout << *p << ' ';
    cout << endl;

//    Rotate(a, 5);
    Rotate(a, 5, true);
    Rotate(a, 5);
    Rotate(a, 5);
    Rotate(a, 5, true);
}

void Rotate(int a[], int n, bool clockwise){

    int x;

    switch (clockwise) {
        case false: // против часовой
            x = a[0];
            for (int i = 1; i<n; i++)
                a[i-1] = a[i];
            a[n-1] = x;
            break;

        case true: // по часовой
            x = a[n-1];
            for (int i = n; i>-1; i--)
                a[i] = a[i-1];
            a[0] = x;
            break;
    }


//    for (int* pa = a+1; pa-a < n-1; pa++){
//        cout << *pa << '_';
//        *(a) = *pa;
//
//    }
//    cout << endl;



    for (int i=0; i<n; i++)
        cout << a[i] << " ";
    cout << endl;
}