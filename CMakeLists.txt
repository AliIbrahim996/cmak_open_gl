cmake_minimum_required(VERSION 3.20)

# Set the platform to win32
set(CMAKE_GENERATOR_PLATFORM win32)

# Disable the safe image flag
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SAFESEH:NO")

# Define your project
project(Demo)

# Add your .cpp files 
add_executable(${PROJECT_NAME} demo.cpp)

# Include the required directories
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")


set(REQUIRED_LIB "${CMAKE_CURRENT_SOURCE_DIR}/lib/GLUT32.lib" "${CMAKE_CURRENT_SOURCE_DIR}/lib/GLAUX.LIB")
# Link your libraries
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIB})

# Move dlls to your executable directory
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${CMAKE_CURRENT_SOURCE_DIR}/system/GLUT32.DLL"
            $<TARGET_FILE_DIR:${PROJECT_NAME}>)