//
// Created by Gaudium on 22.02.2024.
//
#include "LinkedList.h"
#include <iostream>
#include <chrono>

int main(){
    LinkedList<char> lst{};

    std :: cout << "privet " << std :: endl ;

    std::cout << lst.empty() << std::endl;
    lst.print();
    lst.push_back('c');
    lst.push_front('g');
    lst.print();
    lst.clear();
    lst.print();
    lst.insert(0,'o');
    lst.print();
    lst.insert(0,'z');
    lst.print();
    lst.remove_at(0);
    lst.print();
    std::cout << lst.front() << std::endl;
    lst[lst.size()-1]='j';
    lst.print();

    std::cout << lst[lst.size()-1] << std::endl;

//    for (int i = 30; i<30+3; i++, lst.push_front(i))
//    {}
//
//    auto lst2 = lst;
//
//    lst.print();

//    std::cout << "Filled!" << std::endl;
//
//    const auto start{std::chrono::steady_clock::now()};
//
//    lst.clear();
//
//    const auto end{std::chrono::steady_clock::now()};
//    const std::chrono::duration<double> elapsed_seconds{end - start};
//
//    std::cout << "\nElapsed time: " << elapsed_seconds.count() << '\n';


    std :: cout << std :: boolalpha << lst.empty() << std :: endl ;

    for ( int i = 0; i < 5; i ++)
        lst . push_back ( char ( 'a' + i ) ) ;

    lst.print() ;

    for ( int i = 0; i < 5; i ++)
        lst . insert (0 , char ( 'z' - i ) ) ;

    lst.print() ;

    for ( size_t i = 0; i != lst . size () ; i ++)
        lst [ i ] = char ( 'a' + i ) ;

    lst.print() ;

    lst . pop_back () ;
    lst . pop_front () ;

    lst.print() ;

    lst . remove_at (5) ;
    lst . insert (3 , 'o') ;

    lst.print() ;

    lst . clear () ;

    lst . push_back ( 'q') ;
    lst . push_back ( 'w') ;

    std :: cout << lst . size () << ' ' << std :: boolalpha << lst . empty () << std :: endl ;
}