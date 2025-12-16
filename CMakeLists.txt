cmake_minimum_required(VERSION 3.16)
project(third_homework)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(MSVC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /W4")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic")
endif()

add_executable(Substring_searach
                "src/homework_in_C_2/substring_search.c")

add_executable(Simple_bracket_balance
                "src/homework_in_C_2/simple_bracket_balance.c")

add_executable(The_number_zero_elements_in_the_array
                "src/homework_in_C_2/the_number_zero_elemets_in_the_array.c")

