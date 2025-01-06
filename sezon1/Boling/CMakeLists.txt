cmake_minimum_required(VERSION 3.14)
project(Booling)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(FLAGS -Wall -Wextra -Wpedantic -Werror)

Include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.7.1 # or a later release
    )
    
    FetchContent_MakeAvailable(Catch2)
    
add_executable(${PROJECT_NAME}-ut src/test.cpp src/Player.cpp src/Game.cpp)
target_link_libraries(${PROJECT_NAME}-ut PRIVATE Catch2::Catch2WithMain)
target_compile_options(${PROJECT_NAME}-ut PRIVATE ${FLAGS})

add_executable(${PROJECT_NAME} src/main.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})