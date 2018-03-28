#ifndef HEADER1
#define HEADER1
#include "header.hpp"
#include "directions.hpp"
class Particle{
    public:
        //ctor & dtor & copytor
        Particle();
        Particle(float3* position, float3* velocity, Directions* directions);
        ~Particle();
        Particle operator=(Particle p);

        //methods
        void update();

        //getter
        float3* getColour(){ return _col; }
        float3* getPos(){ return _pos; }   
        float3* getVel(){ return _vel; }  
        std::stack<float3>* getStack(){ return _dir; }
        
    private:
        float3* _col;
        float3* _pos;
        float3* _vel;
        std::stack<float3>* _dir;
};

#endif