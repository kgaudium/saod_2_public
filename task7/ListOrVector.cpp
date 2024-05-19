//
// Created by Gaudium on 19.05.2024.
//
#include <iostream>
#include <chrono>
#include <list>
#include <vector>


int main(){
    int N = 20000000;  // Element count
    int M = 200;  // Operation count
    int k = 0;

    std::list<int> lst;

    auto startList = std::chrono::steady_clock::now();
    for (int i = 0; i < N; lst.push_back(i++)) {}
    for (int i = 0; i < M; i++){
        lst.push_front(i);
        k++;
        lst.pop_front();
        k++;
    }
    auto stopList = std::chrono::steady_clock::now();

    std::cout << lst.front() << std::endl;

    auto dtList = std::chrono::duration_cast<std::chrono::microseconds>(stopList - startList);
    std::cout << "k is: " << k << " M is: " << M << std::endl;
    std::cout << "Time: " << dtList << std::endl;


    N = 200;  // Element count
    M = 200;  // Operation count
    k = 0;
    std::vector<int> vector;

    auto startVector = std::chrono::steady_clock::now();
    for (int i = 0; i < N; vector.push_back(i++)) {}
    for (int i = 0; i < M; i++){
        vector.insert(vector.begin(), i);
        k++;
        vector.erase(vector.begin());
        k++;
    }
    auto stopVector = std::chrono::steady_clock::now();

    std::cout << lst.front() << std::endl;

    auto dtVector = std::chrono::duration_cast<std::chrono::microseconds>(stopVector - startVector);
    std::cout << "k is: " << k << " M is: " << M << std::endl;
    std::cout << "Time: " << dtVector << std::endl;
}