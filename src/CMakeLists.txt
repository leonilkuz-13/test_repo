cmake_minimum_required(VERSION 3.10)
project(balanced-bracket C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(MSVC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /W4")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic")
endif()

add_executable(balanced-bracket
                stack/stack.c
                stack/balanced_bracket.c)
