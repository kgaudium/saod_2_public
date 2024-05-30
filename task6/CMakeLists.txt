set(CMAKE_CXX_STANDARD 23)

add_executable(KMP KMP.cpp
        PF.h
        resource.h
        stdafx.cpp
        stdafx.h
        targetver.h
        KMP_StateMachine.h
)

# Add the PF library
add_library(PF SHARED IMPORTED)

# Set the properties for the imported library
set_target_properties(PF PROPERTIES
        IMPORTED_LOCATION_RELEASE "lib/PF.dll"   # Path to PF.dll for Release
        IMPORTED_IMPLIB_RELEASE "/PF.lib"      # Path to PF.lib for Release
        IMPORTED_LOCATION_DEBUG "lib/PF.dll"      # Path to PF.dll for Debug
        IMPORTED_IMPLIB_DEBUG "PF.lib"        # Path to PF.lib for Debug
#        INTERFACE_INCLUDE_DIRECTORIES "/."
        LINKER_LANGUAGE CXX
)

# Link the executable with the PF library
target_link_libraries(KMP PF)

# Ensure the PF.dll is copied to the output directory
add_custom_command(TARGET KMP POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/lib/PF.dll"
        $<TARGET_FILE_DIR:KMP>
)


#add_library(PF lib/PF.dll)
#set_target_properties(PF PROPERTIES LINKER_LANGUAGE CXX)
#
#target_link_libraries(KMP PF)
