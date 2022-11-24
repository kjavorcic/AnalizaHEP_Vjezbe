#pragma once
#include <iostream>
#include <string>

class ElementaryParticle {
	private:
	 std::string name;
	 float mass;
	 bool isBoson;

     
	
    public:
	    ElementaryParticle(std::string x, float y, bool z);
        void printInfo();
	
};