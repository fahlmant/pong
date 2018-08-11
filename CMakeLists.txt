cmake_minimum_required (VERSION 2.6)
project (pong)

include_directories(include)
find_package(SFML 2.5 COMPONENTS system graphics audio REQUIRED)
file(GLOB SOURCES "src/*.cpp")

add_executable(pong ${SOURCES})
target_link_libraries(pong sfml-graphics sfml-audio)
