#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>


class ElementaryParticle {
	private:
	 std::string name;
	 float mass;
	 bool isBoson;

     
	
    public:
	    ElementaryParticle(std::string x, float y, bool z);
		ElementaryParticle();
        void printInfo();
		float E;
		float px;
		float py;
		float pz;
		void setMomentum(float, float, float);
		float transversalMomentum();
		void bosonDecay(ElementaryParticle*, ElementaryParticle*);
		std::string getName();
	
};