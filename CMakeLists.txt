cmake_minimum_required(VERSION 3.25)
project(SortAlgorithm)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(HPATH ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(LPATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(EPATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
                      ${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules)
set(SORTLIB sort)

add_subdirectory(sortAlg)
add_subdirectory(runit)
