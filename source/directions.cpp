#include "directions.hpp"

Directions::Directions(){
    _col->zero();
    *_size = 20;
}
Directions::~Directions(){
    delete(_col);
}
Directions::Directions(Directions* a){
    _col = a->_col;
    _size = a->_size;
}