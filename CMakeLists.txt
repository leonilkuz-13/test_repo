cmake_minimum_required(VERSION 3.10)
project(first_homework)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(MSVC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /W4")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic")
endif()

add_executable(fast_polynomial_calculation
            "src/Homework in C/1/fast polynomial calculation.c")

add_executable(incomplete_quotient
            "src/Homework in C/1/incomplete quotient.c")

add_executable(lucky_tickets
            "src/Homework in C/1/lucky tickets.c")

add_executable(permutation_array_segments
            "src/Homework in C/1/permutation array segments.c")

