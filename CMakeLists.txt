cmake_minimum_required(VERSION 3.17)
project(os_lab_4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(_1 SHARED src/realize1.cpp)
add_library(_2 SHARED src/realize2.cpp)

add_executable(stat static.cpp)
add_executable(dyn dynamic.cpp)

target_link_libraries(stat PRIVATE _2)
