cmake_minimum_required(VERSION 3.20)

project(
    VectorAlgebraProject
    VERSION 1.0.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Поиск компонентов Python
find_package(Python COMPONENTS Interpreter Development REQUIRED)

# Получение директории pybind11 через модуль Python
execute_process(
    COMMAND "${Python_EXECUTABLE}" -c "import pybind11; print(pybind11.get_cmake_dir())"
    OUTPUT_VARIABLE pybind11_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Подключение pybind11
find_package(pybind11 REQUIRED)

# Сборка модуля с универсальным путем к исходнику
pybind11_add_module(vector_algebra ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
