add_executable(classes classes.cpp)

add_library(complex Complex.hpp)
set_target_properties(complex PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(classes complex)

