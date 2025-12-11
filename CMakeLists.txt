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
            "src/homework_in_C/1/fast_polynomial_calculation.c")

add_executable(incomplete_quotient
            "src/homework_in_C/1/incomplete_quotient.c")

add_executable(lucky_tickets
            "src/homework_in_C/1/lucky_tickets.c")

add_executable(permutation_array_segments
            "src/homework_in_C/1/permutation_array_segments.c")

