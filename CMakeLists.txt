cmake_minimum_required(VERSION 3.24)
project(Chess3D)

set(CMAKE_CXX_STANDARD 17)

# Include the headers from the include folder
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add all the source files in the src folder to the executable
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_executable(Chess3D ${SOURCES}) # Create an executable using the source files
find_package(threepp CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
target_link_libraries(Chess3D PRIVATE threepp::threepp imgui::imgui)
