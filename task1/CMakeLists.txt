add_executable(problem1 problem1/problem1.cpp
        problem2/utils.cpp)

add_library(utils problem2/utils.cpp problem2/utils.h)

add_executable(problem2 problem2/problem2.cpp)

target_link_libraries(problem2 utils)