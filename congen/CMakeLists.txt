cmake_minimum_required(VERSION 3.18)

project(simple_cxx_example)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


find_package(RDKit REQUIRED)
find_package(Boost COMPONENTS timer system REQUIRED)
add_executable(confgen confgen.cpp)
target_link_libraries(confgen 
   RDKit::FileParsers 
   RDKit::DistGeomHelpers 
   RDKit::ForceFieldHelpers 
   RDKit::SmilesParse
   Boost::timer
   )
