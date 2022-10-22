#include "ElementaryParticle.h"
#include <iostream>

ElementaryParticle::ElementaryParticle(std::string x, float y, bool z){
    this -> name = x;
    this -> mass = y;
    this -> isBoson = z;
}

void ElementaryParticle::printInfo(){
    std::cout << "name: " << this -> name << "\nmass(GeV/c2): " << this -> mass << "\nIs boson? " << this -> isBoson << "\n";

}