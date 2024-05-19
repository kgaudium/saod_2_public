//
// Created by Gaudium on 19.05.2024.
//

#ifndef SAOD_2_TEST_H
#define SAOD_2_TEST_H
#include <iostream>

class Test{
public:
    int Val;
    Test(){
        this->Val = 0;
        std::cout << "Test constructor called" << std::endl;
    }

    ~Test(){
        std::cout << "Test destructor called" << std::endl;
    }
};
#endif //SAOD_2_TEST_H
