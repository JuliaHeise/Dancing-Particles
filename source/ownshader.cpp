#include "ownshader.hpp"

	///////////////////////////////////////////////////////////////
	///////////////////// 	   Work With	  /////////////////////
	///////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------------//
void Shader::draw(unsigned int VAO, unsigned int VBO, GLFWwindow* window) {
	// input
	this->processInput(this->window);
	///////////////////////////////////////////////////////////////
	///////////////////// set backgroundcolor /////////////////////
	///////////////////////////////////////////////////////////////

	glClearColor(0.005f, 0.0f, 0.02f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);


	///////////////////////////////////////////////////////////////
	//////////////////// movement with matirx /////////////////////
	///////////////////////////////////////////////////////////////
	glUseProgram(shaderProgram);

	// render boxes
	glBindVertexArray(VAO);

	// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
	// -------------------------------------------------------------------------------
	glfwSwapBuffers(window);
	glfwPollEvents();
}
//-------------------------------------------------------------------------------------//

Shader::Shader() : shaderProgram(0) {
	/*glfwMakeContextCurrent(window);
	//glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	///////////////////////////////////////////////////////////////
	/////////////////////   glad func.loader  /////////////////////
	///////////////////////////////////////////////////////////////

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}
	initShader();*/
	std::cout << "Failed: not enough Shader-Input!" << std::endl;
}

Shader::Shader(GLFWwindow* window,const char* str1, const char* str2) : shaderProgram(0), window(window), 
vertexShaderSource(str1), fragmentShaderSource(str2) {

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);
	//glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	///////////////////////////////////////////////////////////////
	/////////////////////   glad func.loader  /////////////////////
	///////////////////////////////////////////////////////////////

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}
	initShader();
}
Shader::~Shader() {

	///////////////////////////////////////////////////////////////
	/////////////////////   shut down window  /////////////////////
	///////////////////////////////////////////////////////////////
	glfwTerminate();
}
void Shader::setMat4(const std::string &name, const glm::mat4 &mat) const{
	glUniformMatrix4fv(glGetUniformLocation(this->shaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void  Shader::initShader() {

	///////////////////////////////////////////////////////////////
	/////////////////////build/compile shader /////////////////////
	///////////////////////////////////////////////////////////////

	int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	// check for shader compile errors
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// fragment shader
	int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	// check for shader compile errors
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	///////////////////////////////////////////////////////////////
	/////////////////////     link  shader    /////////////////////
	///////////////////////////////////////////////////////////////

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	// check for linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::close(unsigned int VAO, unsigned int VBO) {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void Shader::processInput(GLFWwindow *window){
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void Shader::framebuffer_size_callback(GLFWwindow* window, int width, int height){
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}

