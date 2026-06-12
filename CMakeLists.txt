cmake_minimum_required(VERSION 3.28)

project(sfml_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sfml_test
    # src/main.cpp
    # src/lesson2.cpp
    # src/lesson3.cpp
    # src/lesson5.cpp
    # src/lesson6.cpp
    # src/lesson7.cpp
    # src/lesson8.cpp
    # src/lesson9.cpp
    # src/lesson10.cpp
    # src/lesson11.cpp
    src/lesson12.cpp
)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System Audio)

target_link_libraries(sfml_test PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
    SFML::Audio
)