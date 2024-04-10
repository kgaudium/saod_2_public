//
// Created by Gaudium on 20.03.2024.
//

#ifndef SAOD_2_TEST_H
#define SAOD_2_TEST_H


class Test{
public:
    static int Count;
    int index;

    Test();
    Test(int index);
    ~Test();

    Test(Test& other);
};

class Child : public Test {
public:
    Child() : Test(){
        std::cout << "Child Constructor was called. " << Count << " instances. Index is " << index << std::endl;
    }

    Child(int index) : Test(index){
        std::cout << "Child Constructor was called. " << Count << " instances. Index is " << index << std::endl;
    }

    ~Child(){
        std::cout << "Child Destructor was called. " << Count << " instances. Index is " << index << std::endl;
    }
};

class Aggregate {
public:
    Test objTest;

    Aggregate() : objTest(Test::Count + 1){
        std::cout << "Aggregate Constructor was called. Test index is " << objTest.index << std::endl;
    }

    ~Aggregate(){
        std::cout << "Aggregate Destructor was called. Test index was " << objTest.index << std::endl;
    }
};

template <typename T>
class AggregateT{
public:
    T objTest;

    AggregateT(){
        std::cout << "Aggregate Constructor was called. Test index is " << objTest.index << std::endl;
    }

    ~AggregateT(){
        std::cout << "Aggregate Destructor was called. Test index was " << objTest.index << std::endl;
    }
};

#endif //SAOD_2_TEST_H
