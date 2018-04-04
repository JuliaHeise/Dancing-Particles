#include "model.hpp"
//standard Ctor
Model::Model(){
    float vertices[] = {
         0.5f,  0.5f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 
    };
    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };
}
//overwritten ctor
Model::Model(float ver[], int idx[]) : vertices(ver), indices(idx){}

//copy ctor
Model::Model(Model* m) : vertices(m->vertices), indices(m->indices){}

//dtor
Model::~Model(){}