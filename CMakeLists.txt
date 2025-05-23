#Make minimu version
cmake_minimum_required(VERSION 2.8)

#set project name
project(cplusplus_standard_project)

# gtest_discover_tests() can find it
enable_testing()

# set c++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)   
#set(CMAKE_CXX_EXTENSIONS OFF)  
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  add_compile_options(-fmodules-ts)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  add_compile_options(-fmodules)
endif()


# set static
#set(CMAKE_EXE_LINKER_FLAGS "-static")
set(MY_HOME_DIR $ENV{HOME})

#set debug
set(CMAKE_BUILD_TYPE Debug)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")

set(CMAKE_IGNORE_PATH "/usr/include" "/usr/local/include" "/usr/local/lib")

#set release + debug infor
#set(CMAKE_BUILD_TYPE RelWithDebInfo)
#add source file, cpp file add to parameter SOURCES
file(GLOB_RECURSE SOURCES "src/*.cpp")

# executable file
add_executable(cplusplus_standard_program ${SOURCES})


# header folder
target_include_directories(cplusplus_standard_program BEFORE PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
)

#lib path

# libraries
#set(CMAKE_IGNORE_PATH /usr/lib /usr/local/lib)

target_link_libraries(cplusplus_standard_program PRIVATE
  pthread
  m
  z
  stdc++
)

add_subdirectory(tests)


message("Library path: ${CMAKE_SOURCE_DIR}/lib")
