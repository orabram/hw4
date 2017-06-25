cmake_minimum_required(VERSION 3.7)
project(hw4)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp Company.h EscapeRoomWrapper.h Enigma.h
        EscapeRoomWrapper.cpp Exceptions.h Enigma.cpp)
add_executable(hw4 ${SOURCE_FILES})