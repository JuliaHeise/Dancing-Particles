#ifndef HEADER3
#define HEADER3
#include "header.hpp"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include <iostream>

////////////////////////////////////////////////////////////////
/////////////////////   SHADER PROGRAMME   /////////////////////
////////////////////////////////////////////////////////////////

class Shader {
public:
	Shader();
	Shader(const unsigned int width,const unsigned int height, GLFWwindow* window);
	void initShader();
	~Shader();
	void draw(unsigned int VAO, unsigned int VBO, GLFWwindow* window);
	void close(unsigned int VAO, unsigned int VBO);
	void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	void processInput(GLFWwindow *window);
	void setMat4(const std::string &name, const glm::mat4 &mat) const;

	GLFWwindow* Shader::getwindow() { return window; };

	int getID() { return shaderProgram; };

private:
	int SCR_WIDTH;
	int SCR_HEIGHT;
	int shaderProgram;
	GLFWwindow* window;

	const char *vertexShaderSource = "#version 330 core\n"
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
	const char *fragmentShaderSource = "#version 330 core\n"
		"in vec4 vertexColor;\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vertexColor;\n"
		"}\n\0";
};

#endif