cmake_minimum_required(VERSION 3.8)
project(cpp_minesweeper_bekor)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        .idea/minesweeper.iml
        .idea/misc.xml
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        .gitignore
        CMakeLists.txt
        main.cpp)

add_executable(cpp_minesweeper_bekor ${SOURCE_FILES})