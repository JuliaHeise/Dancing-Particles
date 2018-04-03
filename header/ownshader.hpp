#ifndef HEADER3
#define HEADER3
#include "header.hpp"

////////////////////////////////////////////////////////////////
/////////////////////   SHADER PROGRAMME   /////////////////////
////////////////////////////////////////////////////////////////

class Shader {
public:
	//ctor + dtor
	Shader();
	Shader(GLFWwindow* window, const char* str1, const char* str2);
	~Shader();

	//methods to work with
	void setMat4(const std::string &name, const glm::mat4 &mat) const;
	void draw(unsigned int VAO, unsigned int VBO, GLFWwindow* window);

	// fixed methods - do not change
	void initShader();
	void close(unsigned int VAO, unsigned int VBO);
	void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	void processInput(GLFWwindow *window);

	//getter
	GLFWwindow* Shader::getwindow() { return window; };
	int getID() { return shaderProgram; };



private:
	int shaderProgram;
	GLFWwindow* window;

	//Shadercodes - Work with!!
	const char *vertexShaderSource;
	const char *fragmentShaderSource;
};

#endif