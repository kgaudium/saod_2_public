# problem 1
add_executable(t2_pointer pointer.cpp)


# problem 2
add_executable(t2_swap swap.cpp)
add_library(t2_utils utils.cpp)

target_link_libraries(t2_swap t2_utils)


# problem3
add_executable(t2_arrays arrays.cpp)


# problem4
add_executable(t2_strings strings.cpp)

add_library(t2_utils2 utils.cpp)

target_link_libraries(t2_strings t2_utils2)