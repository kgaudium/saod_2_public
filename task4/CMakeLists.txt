add_executable(strings strings.cpp)

add_library(str Str.h)
set_target_properties(str PROPERTIES LINKER_LANGUAGE CXX)
