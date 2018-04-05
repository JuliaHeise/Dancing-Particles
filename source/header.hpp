#ifndef ALLHEADER
#define ALLHEADER

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <stack>
#include <iostream>

// global settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
const float PI = glm::pi<float>();

template<int numPoints>
struct Modell{
    float vertices[numPoints*3+3];
    unsigned int indices[numPoints*3];
    void computeCircle(){
        int idx = 2;
        vertices[0] = 0.0f;
        vertices[1] = 0.0f;
        vertices[2] = 0.0f;
        for (float i = 0.0f; i < 2*PI; i += (2.0f/numPoints)*PI){
            vertices[++idx] = 0.5f * cos(i);
            vertices[++idx] = 0.5f * sin(i);
            vertices[++idx] = 0;
            if(idx == numPoints*3+2) break;        
        }
        int count = 2;
        for (int n = 0; n < numPoints*3; n += 3){
            indices[n] = 0;
            indices[n+1] = count-1;
            if(n+2 == numPoints*3-1) indices[n+2] = 1;
            else indices[n+2] = count;
            count++;
        }
    };
};

struct float3{
    float x;
    float y;
    float z;
    void operator=(const float3 &b){
        x = b.x;
        y = b.y;
        z = b.z;
    };
    void operator+=(const float3 &b){
        x += b.x;
        y += b.y;
        z += b.z;        
    }
    void zero(){
        x = 0;
        y = 0;
        z = 0;
    };
};

#endif