#include "particle.hpp"
Particle::Particle(){
    _col->zero();
    _dir = new std::stack<float3>();
    _pos->zero();
    _vel->zero();

}
Particle::Particle(float3* position, float3* velocity, Directions* directions){
    Particle::_col = directions->getColour();
    Particle::_dir = directions->getStack();
    Particle::_pos = position;
    Particle::_vel = velocity;
}
Particle::~Particle(){
    delete(Particle::_col);
    delete(Particle::_dir);
    delete(Particle::_pos);
    delete(Particle::_vel);
}
Particle Particle::operator=(Particle p){
    Particle* s = new Particle();
    s->_col = p._col;
    s->_dir = p._dir;
    s->_pos = p._pos;
    s->_vel = p._vel;
    return *s;
}
void Particle::update(){
    *_pos += _dir->top();
    Particle::_dir->pop();
} 