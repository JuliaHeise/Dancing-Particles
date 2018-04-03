#include <iostream>
#include "header.hpp"
#include "display.hpp"
#include "directions.hpp"
#include "ownshader.hpp"
#include "particle.hpp"

int main(){

	float vertices[] = {
		-0.5f, -0.5f, 0.0f, // left  
		0.5f, -0.5f, 0.0f, // right 
		0.0f,  0.5f, 0.0f  // top   
	};

	const char* str1 = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"out vec4 vertexColor;\n"
		"uniform mat4 model;\n"
		"uniform mat4 view;\n"
		"uniform mat4 projection;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = projection* view * model * vec4(aPos, 1.0f);\n"
		"	vertexColor = vec4(0.0f, 0.5+aPos.z*0.5, 0.0, 1.0);\n"
		"}\0";
	
	const char* str2 = "#version 330 core\n"
		"in vec4 vertexColor;\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vertexColor;\n"
		"}\n\0";

	startDisplay(vertices, str1, str2);
	std::cout << "DANCE!" << std::endl;
    return 0;
}