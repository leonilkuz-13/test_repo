cmake_minimum_required(VERSION 3.10)
project(optimal_sort)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(MSVC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /W4")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic")
endif()

add_executable(optimal_sort
            src/optimal_sort/Optimal_sort.c
            src/optimal_sort/Quick_sort.c)

target_include_directories(optimal_sort PRIVATE 
    src/optimal_sort
)