cmake_minimum_required(VERSION 3.10)
project(ToDoList LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(todo
    main.cpp
    Task.cpp
    TaskManager.cpp
)
