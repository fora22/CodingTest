cmake_minimum_required(VERSION 3.17)
project(foraStack_Linked_List)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-fexec-charset=CP949") # 한글 출력
add_executable(foraStack_Linked_List main.cpp foraStackLinkedList.cpp foraStackLinkedList.h)