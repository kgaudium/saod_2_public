//
// Created by Gaudium on 20.03.2024.
//
#include <iostream>
#include "Test.h"

int Test::Count = 0;

Test::Test() {
    Test::Count++;
    Test::index = Count;
    std::cout << "Test Default Constructor was called. " << Count << " instances. Index is " << index << std::endl;
}

Test::Test(int index) {
    Test::Count++;
    Test::index = index;
    std::cout << "Test Constructor was called. " << Count << " instances. Index is " << index << std::endl;
}

Test::~Test() {
    Test::Count--;
    std::cout << "Test Destructor was called. " << Count << " instances. Index is " << index << std::endl;
}

Test::Test(Test& other) {
    index = other.index + 1000;
    Test::Count++;
    std::cout << "Copy Constructor was called. " << Count << " instances. Original index is " << other.index << ". New index is " << index << std::endl;
}
