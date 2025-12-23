cmake_minimum_required(VERSION 3.10)
project(stack)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(MSVC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /W4")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic")
endif()

add_library(stack STATIC src/stack/stack.c)
target_include_directories(stack PUBLIC src/stack)

add_executable(bracket_balance
            src/stack/balanced_bracket.c)

add_executable(marshalling_yard
            src/stack/marshalling_yard.c)   

target_link_libraries(bracket_balance stack)
target_link_libraries(marshalling_yard stack)