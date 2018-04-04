#ifndef DISPLAY
#define DISPLAY
#include "header.hpp"
#include "ownshader.hpp"

//OpenGL Stuff
void initGLFW();
GLFWwindow* createWindow();
void startDisplay(float vertices[], const char* str1, const char* str2);

#endif