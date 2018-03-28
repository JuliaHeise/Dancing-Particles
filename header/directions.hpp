#ifndef HEADER2
#define HEADER2
#include "header.hpp"

class Directions{
    public:
        //ctor & dtor & copytor
        Directions();
        ~Directions();
        Directions(Directions* a);

        //getter
        std::stack<float3>* getStack(){ return _dirs; }
        float3* getColour(){ return _col; }
        int* getSize(){ return _size; }

    private:
        float3* _col;
        int* _size;
        std::stack<float3>* _dirs;
};

#endif