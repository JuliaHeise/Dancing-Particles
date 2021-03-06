# Project definition
cmake_minimum_required(VERSION 3.1)
project(Dancing_Particles)

find_package(OpenGL REQUIRED)

# Source files
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/source")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libraries")
set(INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/includes")
set(HD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/header")
set(HEADER
	"${HD_DIR}/directions.hpp"
	"${HD_DIR}/particle.hpp"
	"${HD_DIR}/myOpenGL.hpp"
)
set(SOURCES 	
	"${SRC_DIR}/header.hpp"
	"${SRC_DIR}/main.cpp" 
	"${SRC_DIR}/myOpenGL.cpp"
	"${SRC_DIR}/particle.cpp"
	"${SRC_DIR}/directions.cpp"
	"${SRC_DIR}/glad.c"
)
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADER})
target_include_directories(${PROJECT_NAME} PRIVATE "${SRC_DIR}")
#set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

# GLFW
set(GLFW_DIR "${LIB_DIR}/glfw")
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")
add_subdirectory("${GLFW_DIR}")
target_link_libraries(${PROJECT_NAME} "glfw" "${GLFW_LIBRARIES}")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLFW_DIR}/include")
target_compile_definitions(${PROJECT_NAME} PRIVATE "GLFW_INCLUDE_NONE")

include_directories(
	${INC_DIR}/glm
	${INC_DIR}/glad
	${GLFW_DIR}/include
	${HD_DIR}
)
