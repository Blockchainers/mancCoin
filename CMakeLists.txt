cmake_minimum_required(VERSION 2.6)
project(mancCoin)

set(CMAKE_BUILD_TYPE Debug)
set(GLOBAL_OUTPUT_PATH ${PROJECT_BINARY_DIR})
set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

include(CMakeLists-External.txt)

link_directories(${GLOBAL_OUTPUT_PATH})

include_directories("src/vendor")
include_directories(${rpclib_INCLUDE_DIRS})

file(GLOB SOURCES "src/*.cpp" "src/rpc/*.cpp")

add_executable(manccoin ${SOURCES})
add_dependencies(manccoin rpclib)

target_link_libraries(manccoin ${rpclib_OUT})
