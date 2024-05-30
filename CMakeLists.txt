cmake_minimum_required(VERSION 3.27)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_C_COMPILER "gcc")

project(saod_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(task1)

add_subdirectory(task2)

add_subdirectory(task3)

add_subdirectory(task4)

# When works in one compiler doesn't work in another...
#add_subdirectory(task5)

add_subdirectory(task6a)

# #$?&!
#add_subdirectory(task6)

add_subdirectory(task7)

add_subdirectory(task8)

add_subdirectory(linked_list)

add_subdirectory(inheritance)

add_subdirectory(trie)
