//
// Created by Gaudium on 20.03.2024.
//
#include <iostream>
#include "Test.h"

void foo(Test t){
    std::cout << "Foo is running for object with index " << t.index << std::endl;

};

//Test* globalTest = new Test(1);

int main(){
    std::cout << "Main started" << std::endl;


//    Test* testArray = new Test[4]{(10),(11),(12),(13)};
//    Test::Count = 0;
//    foo(*globalTest);
//    auto test = Test(2);

//    delete[] testArray;

//    delete globalTest;


//    Child child {20};
//
//    Aggregate aggregate {};

//    AggregateT<Test> aggrTest {};

    AggregateT<Child> aggrChild {};

    std::cout << "Main ended" << std::endl;
}