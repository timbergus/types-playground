cmake_minimum_required(VERSION 3.28.3)
project(types-playground VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -Werror -Wpedantic)

file(GLOB_RECURSE CPP_FILES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/src/apps/*.cpp)

add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/main.cpp ${CPP_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src/include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
