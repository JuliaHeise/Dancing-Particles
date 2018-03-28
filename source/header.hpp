#ifndef ALLHEADER
#define ALLHEADER

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stack>

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