cmake_minimum_required(VERSION 3.25)
project(cs)

set(CMAKE_CXX_STANDARD 23)

configure_file(input.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_executable(
        cs
#        Problems/bfs/dwite07c3p5.cpp
#        "Problems/CSEC/CSES Tree Distances I .cpp"
#        Problems/bfs/hci16oversleep.cpp
        Problems/dfs/btoi04p1.cpp)
