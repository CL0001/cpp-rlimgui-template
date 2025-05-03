cmake_minimum_required(VERSION 3.30)

project("YourProjectName" VERSION 0.1.0 DESCRIPTION "Your Project Description" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory("${CMAKE_SOURCE_DIR}/third_party/iamgui")
add_subdirectory("${CMAKE_SOURCE_DIR}/third_party/raylib")

file(GLOB_RECURSE HEADERS "${CMAKE_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

if (MSVC)
    foreach(flag_var CMAKE_C_FLAGS_RELEASE CMAKE_CXX_FLAGS_RELEASE)
        string(REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
    endforeach()

    set_target_properties(${PROJECT_NAME} PROPERTIES
        LINK_FLAGS "/SUBSYSTEM:WINDOWS"
        LINK_OPTIONS "/ENTRY:mainCRTStartup"
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "-mwindows")
endif()

target_include_directories(${PROJECT_NAME} PUBLIC
    "${CMAKE_SOURCE_DIR}/include"
    "${CMAKE_SOURCE_DIR}/third_party/raylib/src"
    "${CMAKE_SOURCE_DIR}/third_party/iamgui"
)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib iamgui)

if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="assets/")
else()
    target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_SOURCE_DIR}/assets/")
endif()
