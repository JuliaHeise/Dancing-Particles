#include "display.hpp"

//OpenGL Stuff
void initGLFW() {
	    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

GLFWwindow* createWindow() {
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
	return window;

}

void startDisplay(float vertices[], const char* str1, const char* str2){

  	///////////////////////////////////////////////////////////////
	/////////////////////  glfw  init/config  /////////////////////
	///////////////////////////////////////////////////////////////
	initGLFW();

	///////////////////////////////////////////////////////////////
	/////////////////////    create window    /////////////////////
	///////////////////////////////////////////////////////////////
	
	GLFWwindow* window = createWindow();
	Shader* shader = new Shader(window);
}