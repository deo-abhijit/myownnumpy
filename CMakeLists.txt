cmake_minimum_required(VERSION 3.4...3.18)
project(AbhijitsOwnNumpy)
add_subdirectory(pybind11)
pybind11_add_module(abhijits_numpy cpp_code/array.cpp)