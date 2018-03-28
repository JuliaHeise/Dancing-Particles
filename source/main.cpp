#include <iostream>
#include "header.hpp"
#include "directions.hpp"
#include "ownshader.hpp"
#include "particle.hpp"

// global settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

//OpenGL Zeugs
void initGLFW() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

GLFWwindow* createWindow() {
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Dancing Particles", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	return window;

}

int main(){
	///////////////////////////////////////////////////////////////
	/////////////////////  glfw  init/config  /////////////////////
	///////////////////////////////////////////////////////////////
	initGLFW();
	///////////////////////////////////////////////////////////////
	/////////////////////    create window    /////////////////////
	///////////////////////////////////////////////////////////////
	GLFWwindow* window = createWindow();
	Shader* shader = new Shader(SCR_WIDTH, SCR_HEIGHT, window);
	shader->initShader();
	window = shader->getwindow();
	int shaderProgram = shader->getID();
	
	
	float vertices[] = {
		-0.5f, -0.5f, 0.0f, // left  
		0.5f, -0.5f, 0.0f, // right 
		0.0f,  0.5f, 0.0f  // top   
	};
	///////////////////////////////////////////////////////////////
	/////////////////////     use  buffer     /////////////////////
	///////////////////////////////////////////////////////////////

	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	///////////////////////////////////////////////////////////////
	/////////////////////    start   draw     /////////////////////
	///////////////////////////////////////////////////////////////

	glUseProgram(shaderProgram);
	///////////////////////////////////////////////////////////////
	/////////////////////     render  loop    /////////////////////
	///////////////////////////////////////////////////////////////
	while (!glfwWindowShouldClose(window)){
		shader->draw(VAO, VBO, window);
	}
	shader->close(VAO, VBO);
	std::cout << "DANCE!" << std::endl;
	getchar();
    return 0;
}