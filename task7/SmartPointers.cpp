//
// Created by Gaudium on 19.05.2024.
//
#include <iostream>
#include <memory>
#include "Test.h"

int main(){
    // Shared
//    std::shared_ptr<Test[]> sp (new Test[3]);
////    Не работает
////    std::shared_ptr<Test> sp2 (new Test[3], default delete<Test[]>());
//
//    sp.get()[0].Val = 10;
//    sp.get()[1].Val = 20;
//    sp.get()[2].Val = 30;
//
//    for (int i = 0; i < 3; i++){
//        std::cout << sp.get()[i].Val << std::endl;
//    }

    // Unique
    std::unique_ptr<Test[]> up (new Test[3]);

    up[0].Val = 100;
    up[1].Val = 200;
    up[2].Val = 300;

    for (int i = 0; i < 3; i++){
        std::cout << up[i].Val << std::endl;
    }

    std::cout << "---------" << std::endl;
    up = std::make_unique<Test[]>(2);
    std::cout << "---------" << std::endl;
}
