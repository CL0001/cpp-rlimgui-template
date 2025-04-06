cmake_minimum_required(VERSION 3.16)

project("YourProjectName" VERSION 0.1.0 DESCRIPTION "Your Project Description" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory("${CMAKE_SOURCE_DIR}/third_party/iamgui")
add_subdirectory("${CMAKE_SOURCE_DIR}/third_party/raylib")

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/source/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
    "${CMAKE_SOURCE_DIR}/headers"
    "${CMAKE_SOURCE_DIR}/third_party/raylib/src"
    "${CMAKE_SOURCE_DIR}/third_party/iamgui"
)

target_compile_definitions(${PROJECT_NAME} PUBLIC RESOURCES_PATH="${CMAKE_SOURCE_DIR}/assets")

target_link_libraries(${PROJECT_NAME} PRIVATE raylib iamgui)

# Checks if OSX and links appropriate frameworks (only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()

# Optional for future packaging
# install(DIRECTORY assets/ DESTINATION share/${PROJECT_NAME}/assets)