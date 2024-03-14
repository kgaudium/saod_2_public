add_executable(list_test list_test.cpp)

add_library(linked_list LinkedList.h)
set_target_properties(linked_list PROPERTIES LINKER_LANGUAGE CXX)

add_library(list_node ListNode.h)
set_target_properties(list_node PROPERTIES LINKER_LANGUAGE CXX)


target_link_libraries(list_test linked_list)