#ifndef SHADER1
#define SHADER1
#include "header.hpp"


////////////////////////////////////////////////////////////////
/////////////////////   SHADER PROGRAMME   /////////////////////
////////////////////////////////////////////////////////////////

class Shader {
public:
	//ctor + dtor
	Shader();
	Shader(GLFWwindow* window);
	~Shader();

	//methods to work with
	void setMat4(const std::string &name, const glm::mat4 &mat) const;
	void drawCircle();

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
	"uniform vec4 ourColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = ourColor;\n"
    "}\n\0";
};

void processInput(GLFWwindow* window);
void initGLFW();
GLFWwindow* createWindow();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

#endif