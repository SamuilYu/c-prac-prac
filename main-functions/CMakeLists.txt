cmake_minimum_required(VERSION 3.17)

project(MainFunctions)

include(CheckCXXCompilerFlag)


set(CMAKE_CXX_STANDARD 17)

function(enable_cxx_compiler_flag_if_supported flag)
    string(FIND "${CMAKE_CXX_FLAGS}" "${flag}" flag_already_set)
    if(flag_already_set EQUAL -1)
        check_cxx_compiler_flag("${flag}" flag_supported)
        if(flag_supported)
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flag}" PARENT_SCOPE)
        endif()
        unset(flag_supported CACHE)
    endif()
endfunction()

enable_cxx_compiler_flag_if_supported("-Wall")
enable_cxx_compiler_flag_if_supported("-std=c++17")
enable_cxx_compiler_flag_if_supported("-pthread")
enable_cxx_compiler_flag_if_supported("-O3")

add_subdirectory(Google_tests)
file(GLOB SOURCES MainFunctions/*.cpp ArithmeticFunctions/*.cpp)
add_executable(${PROJECT_NAME} main.cpp ${SOURCES})
