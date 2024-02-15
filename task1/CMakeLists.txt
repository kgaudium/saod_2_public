add_executable(t1_problem1 problem1.cpp
        utils.cpp)

add_library(utils utils.cpp utils.h)

add_executable(t1_problem2 problem2.cpp)

target_link_libraries(t1_problem2 utils)