#include "ElementaryParticle.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

std::string ElementaryParticle::getName(){
    return this -> name;
}

ElementaryParticle::ElementaryParticle(std::string x, float y, bool z){
    this -> name = x;
    this -> mass = y;
    this -> isBoson = z;
}

ElementaryParticle::ElementaryParticle(){
    this -> name;
    this -> mass;
    this -> isBoson;
}

void ElementaryParticle::printInfo(){
    std::cout << "name: " << this -> name << "\n" 
    << "Four vector: (" << this -> E << ", " <<  this -> px << ", " << this -> py << ", " << this -> pz << ")\n";

}

void ElementaryParticle::setMomentum(float px, float py, float pz){
    this -> px = px;
    this -> py = py;
    this -> pz = pz;
    this -> E = sqrt(sqrt(pow(px, 2) + pow(py, 2) + pow(pz, 2)) +  pow(this -> mass, 2));
}

float ElementaryParticle::transversalMomentum(){
    return sqrt(pow(this -> px, 2) + pow(this -> py, 2));
}

void ElementaryParticle::bosonDecay(ElementaryParticle* decayParticle_1, ElementaryParticle* decayParticle_2){
    
    //provjera jeli cestica bozon
    if(this -> isBoson == false){
        std::cout << "The decay is not possible";
        return;
    }


    //odredivanje na koje cestice se raspada bozon i njezina masa
    srand((unsigned) time(NULL));
    float random = rand()%100;
    float mass;
    std::cout << "Random number: " << random << "\n";
    if(random <= 21.4){
        decayParticle_1 -> name = "W Boson";
        decayParticle_2 -> name = "W Boson";
        mass = 80.4;
    }
    else if (random > 21.4 && random <= 27.8){
        decayParticle_1 -> name = "Tau Lepton";
        decayParticle_2 -> name = "Tau Lepton";
        mass = 1.776;
    }
    else if (random > 27.8 && random <= 29.4){
        decayParticle_1 -> name = "Z Boson";
        decayParticle_2 -> name = "Z Boson";
        mass = 91.1;
    }
    else 
        decayParticle_1 -> name = "B quark";
        decayParticle_2 -> name = "B quark";
        mass = 4.2;

    //podjela kolicine gibanja na dvije cestice
    float random2 = (float)(rand()%100)/100;
    decayParticle_1 -> px = (this -> px)*random2;
    decayParticle_2 -> px = (this -> px) - decayParticle_1 -> px;

    random2 = (float)(rand()%100)/100;
    decayParticle_1 -> py = (this -> py)*random2;
    decayParticle_2 -> py = (this -> py) - decayParticle_1 -> py;

    random2 = (float)(rand()%100)/100;

    decayParticle_1 -> pz = (this -> pz)*random2;
    decayParticle_2 -> pz = (this -> pz) - decayParticle_1 -> pz;
    

    //postavljanje Energija
    decayParticle_1 -> E = sqrt(sqrt(pow(decayParticle_1 -> px, 2) + pow(decayParticle_1 -> py, 2) + pow(decayParticle_1 -> pz, 2))
     +  pow(mass, 2));
    decayParticle_2 -> E = sqrt(sqrt(pow(decayParticle_2 -> px, 2) + pow(decayParticle_2 -> py, 2) + pow(decayParticle_2 -> pz, 2))
     +  pow(mass, 2));


}