cmake_minimum_required(VERSION 3.16)
project(test_singly_linked_list)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(MSVC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /W4")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic")
endif()

add_library(Singly_linked_list STATIC 
    src/singly_linked_list/code/singly_linked_list.c
)

add_executable(Test_runner 
    src/singly_linked_list/tests/test_singly_list.c
)

target_link_libraries(Test_runner Singly_linked_list)

target_include_directories(Test_runner PRIVATE src/singly_linked_list/code)

target_include_directories(Singly_linked_list PUBLIC src/singly_linked_list/code)