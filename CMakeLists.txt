cmake_minimum_required(VERSION 3.16)
project(mls)

set(CMAKE_CXX_STANDARD 20)


link_directories(/usr/local/lib)

add_executable(${PROJECT_NAME}
        main.cpp
		MLS.h
		MLS.cpp
#		MLS_mbed.cpp
#		MLS_mbed.h
)