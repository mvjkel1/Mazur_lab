cmake_minimum_required(VERSION 3.0.0)
project(Mazur_lab_01 VERSION 0.1.0)

include(CTest)
enable_testing()

# add_executable(Mazur_lab_01 main.cpp)
add_executable(Mazur_lab_01 main2.cpp)
set(CMAKE_CXX_STANDARD 20)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
