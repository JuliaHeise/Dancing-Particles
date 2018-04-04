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
	shader->initShader();
	int shaderProgram = shader->getID();

    ///////////////////////////////////////////////////////////////
	/////////////////////      set Buffer     /////////////////////
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

	glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0); 

	///////////////////////////////////////////////////////////////
	/////////////////////    start   draw     /////////////////////
	///////////////////////////////////////////////////////////////
    //glUseProgram(shaderProgram);

	///////////////////////////////////////////////////////////////
	/////////////////////     render  loop    /////////////////////
	///////////////////////////////////////////////////////////////
	while (!glfwWindowShouldClose(window)){
		shader->draw(VAO, VBO);
	}
	shader->close(VAO, VBO);
}