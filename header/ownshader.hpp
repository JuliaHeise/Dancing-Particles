#ifndef HEADER3
#define HEADER3
#include "header.hpp"
#include "model.hpp"

GLFWwindow* createWindow();
void initGLFW();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

////////////////////////////////////////////////////////////////
/////////////////////   SHADER PROGRAMME   /////////////////////
////////////////////////////////////////////////////////////////

class Shader {
public:
	//ctor + dtor
	Shader();
	Shader(GLFWwindow* window, Model<4,2>* model);
	~Shader();

	//methods to work with
	void setMat4(const std::string &name, const glm::mat4 &mat) const;

	// fixed methods - do not change
	void initShader();
	void close(unsigned int VAO, unsigned int VBO);


	//getter
	GLFWwindow* Shader::getwindow() { return window; };
	int getID() { return shaderProgram; };



private:
	int shaderProgram;
	GLFWwindow* window;

	//Shadercodes - Work with!!
	const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0"; 
	const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";
};

#endif