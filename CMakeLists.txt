cmake_minimum_required(VERSION 3.20)

project(
    VectorAlgebraProject
    VERSION 1.0.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Поиск pybind11 в системе
find_package(pybind11 REQUIRED)

# Создаем модуль из файла main.cpp
pybind11_add_module(vector_algebra src/main.cpp)
