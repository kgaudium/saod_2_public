add_executable(t1_problem1 problem1/problem1.cpp
        problem2/utils.cpp)

add_library(utils problem2/utils.cpp problem2/utils.h)

add_executable(t1_problem2 problem2/problem2.cpp)

target_link_libraries(t1_problem2 utils)