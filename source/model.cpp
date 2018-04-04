#include "model.hpp"
#include <iostream>
//standard Ctor
template<>
Model<4,2>::Model() : numPoints(4), numTriangles(2), 
    vertices((float[12]) {
         0.5f,  0.5f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 
    }),
    indices((unsigned int[6]){  // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    }){}
}
//overwritten ctor
template <int P, int T>
Model<P,T>::Model(const float* ver, const int* idx): numPoints(P), numTriangles(T){
   // for(int i = 0; i < 3*P; i++)
}

//copy ctor
template <int P, int T>
Model<P,T>::Model(const Model<P,T> &m): numPoints(P), numTriangles(T){
    vertices = m.vertices;
    indices = m.indices;
    numPoints = P;
    numTriangles = T;
}

//dtor
template <int P, int T>
Model<P, T>::~Model(){
}
template <>
Model<4,2>::~Model(){
}