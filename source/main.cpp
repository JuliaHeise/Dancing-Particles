#include <iostream>
#include "header.hpp"
#include "directions.hpp"
#include "ownshader.hpp"
#include "particle.hpp"

int main(){
 	///////////////////////////////////////////////////////////////
	/////////////////////  glfw  init/config  /////////////////////
	///////////////////////////////////////////////////////////////
	initGLFW();
	std::cout << "init finished" << std::endl;

	///////////////////////////////////////////////////////////////
	/////////////////////    create window    /////////////////////
	///////////////////////////////////////////////////////////////
	
	GLFWwindow* window = createWindow();
	std::cout << "creatwindow" << std::endl;

	Model<4,2>* model = new Model<4,2>();
	std::cout << *(model->vertices) << std::endl;
	std::cout << model->vertices << std::endl;
	Shader* shader = new Shader(window, model);

	std::cout << "DANCE!" << std::endl;
	delete(model);
	delete(shader);
    return 0;
}