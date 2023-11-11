cmake_minimum_required(VERSION 3.26)
project(assignment_c C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(assignment_c
#        assignment.c
        assignmentGeneric.c
        genericLinkedList.c
        genericLinkedList.h
#        linkedList.c
#        linkedList.h
#        Question1.c
#        tests.c
#        tests.h
        testsGeneric.c
        testsGeneric.h)
