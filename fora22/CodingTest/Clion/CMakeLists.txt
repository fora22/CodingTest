cmake_minimum_required(VERSION 3.17)
project(CodingTest)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-fexec-charset=CP949") # 한글 출력
add_executable(CodingTest main.cpp)