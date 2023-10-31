cmake_minimum_required(VERSION 3.25)

project(EPI-C)

# Remove the line that sets SFML as it's not needed
find_package(SFML 2.5 COMPONENTS graphics window REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(EPI-C main.cpp createAnimationTextures.cpp createAnimationTextures.cpp)

# Link your target with SFML libraries
target_link_libraries(EPI-C sfml-graphics sfml-window)
