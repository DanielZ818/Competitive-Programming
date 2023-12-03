cmake_minimum_required(VERSION 3.25)
project(cs)

set(CMAKE_CXX_STANDARD 23)

configure_file(input.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_executable(
        Competitive-Programming
        )
