#include <iostream>
#include <string>
class ElementaryParticle {
	public:
	 std::string name;
	 float mass;
	 bool isBoson;
	
	//konstruktor
	ElementaryParticle(std::string x, float y, bool z){
		name = x;
		mass = y;
		isBoson = z;


	}

	//funkcija ispisa
	void printInfo(){
		std::cout << "name: " << name << "\nmass(GeV/c2): " << mass << "\nIs boson? " << isBoson << "\n";
	}	
	
};


int main(){
	ElementaryParticle HiggsBoson("Higgs Boson", 125.18, true);
	ElementaryParticle TopQuark("Top Quark", 173, false);
	ElementaryParticle ZBoson("Z boson", 91.1, true);

	//pointer na klasu
	ElementaryParticle *ptrParticle;
	ptrParticle = &ZBoson;

	HiggsBoson.printInfo(); 	
	TopQuark.printInfo();

	// ispis informacija preko pointer
	std::cout << "name: " << ptrParticle -> name  
	<< "\nmass: " << ptrParticle -> mass 
	<< "\nIs Boson?" << ptrParticle -> isBoson << "\n";
}
