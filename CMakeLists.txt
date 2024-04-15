# Версия cmake
cmake_minimum_required(VERSION 3.24)
# Имя проекта
project(LR12)

# Версия С++
set(CMAKE_CXX_STANDARD 17)

# Добавление в проект lib, bin
add_subdirectory(lib)
add_subdirectory(bin)


enable_testing()
add_subdirectory(tests)