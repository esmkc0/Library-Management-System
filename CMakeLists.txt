
cmake_minimum_required(VERSION 3.20)

project(LibraryManagementSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LibraryManagementSystem
        main.cpp
        Book.cpp
        Library.cpp
)
