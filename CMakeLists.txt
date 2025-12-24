cmake_minimum_required(VERSION 3.10)
project(list)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(MSVC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /W4")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic")
endif()

add_executable(sorting_list
            src/singly_linked_list/singly_linked_list.c
            src/singly_linked_list/sorted_list.c)
            
add_executable(sicarians
            src/sicarians/doubly_linked_list.c
            src/sicarians/sicarians.c)   