cmake_minimum_required(VERSION 3.13)
project(erpc_example)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1) # clangd

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_BUILD_TYPE Release)

INCLUDE_DIRECTORIES("/usr/local/include/erpc")

add_executable(client client.c c_example_client.cpp example_client.cpp example_interface.cpp)
add_executable(server server.c c_example_server.cpp example_server.cpp example_interface.cpp)

target_link_libraries(client erpc)
target_link_libraries(server erpc)
