//
// Created by Gaudium on 16.02.2024.
//
#include <iostream>

#include "Complex.hpp"


int main()
{
    Complex c = Complex(16, 337);
    std::cout << "c:               " << c << std::endl;

    // #5
    std::cout << "c+c:             " << c+c << std::endl;
    std::cout << "c-c:             " << c-c << std::endl;
    std::cout << "c*c:             " << c*c << std::endl;
    std::cout << "c/c:             " << c/c << std::endl;
    std::cout << "c.Conjugate():   " << c.Conjugate() << std::endl;

    // #6
    std::cout << "c.Mod():         " << c.Mod() << std::endl;
    std::cout << "c.Arg():         " << c.Arg() << std::endl << std::endl;

    // #7
    Complex cArray[4] = {1, 2, Complex(2,3)};

    for (Complex i : cArray)
        std::cout << i << " ";
    std::cout << std::endl;

    // #8
    Complex* pc = new Complex(1,2);

    std::cout << *pc << std::endl;
    std::cout << pc->Re << " " << pc->Im << std::endl;
    delete pc;

    Complex *cNewArray = new Complex[3] {1, 2, Complex(4,5)};

    std::cout << cNewArray[1].Re << (cNewArray+1)->Re << std::endl;

    delete[] cNewArray;
}