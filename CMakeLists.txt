# Project definition
cmake_minimum_required(VERSION 3.1)
project(Dancing_Particles)

# Source files
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/source")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libraries")
set(INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/includes")
set(SOURCES 	
	"${SRC_DIR}/main.cpp" 
	"${SRC_DIR}/directions.hpp"
	"${SRC_DIR}/particle.hpp"
	"${SRC_DIR}/header.hpp"
    "${SRC_DIR}/shader.hpp"
)
add_executable(${PROJECT_NAME} ${SOURCES})
