cmake_minimum_required(VERSION 3.18)

project(simple_cxx_example)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)


find_package(RDKit REQUIRED)
find_package(Boost COMPONENTS timer system REQUIRED)
add_executable(find_mcs find_mcs.cpp)
target_link_libraries(find_mcs RDKit::FileParsers RDKit::FMCS
   Boost::timer)
