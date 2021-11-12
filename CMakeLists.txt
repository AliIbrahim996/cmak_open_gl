cmake_minimum_required(VERSION 3.20)

set(CMAKE_GENERATOR_PLATFORM win32)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SAFESEH:NO")
project(Demo)

add_executable(${PROJECT_NAME} demo.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(${PROJECT_NAME} 
    "${CMAKE_CURRENT_SOURCE_DIR}/lib/GLUT32.lib" "${CMAKE_CURRENT_SOURCE_DIR}/lib/GLAUX.LIB")