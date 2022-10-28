#include <iostream>
#include "ElementaryParticle.h"
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <unistd.h>

int main(){
    float px, py, pz;
    srand((unsigned) time(NULL));

    ElementaryParticle HiggsBoson("Higgs Boson", 125.18, true);
	ElementaryParticle TopQuark("Top Quark", 173, false);
	ElementaryParticle ZBoson("Z boson", 91.1, true);

    
    // ElementaryParticle *decayParticle_1 = new ElementaryParticle();
    // ElementaryParticle *decayParticle_2 = new ElementaryParticle();
    


    //std::cout << "Unesite kolicine gibanja: \n";
    //std::cin >> px >> py >> pz;


    //HiggsBoson.setMomentum(px, py, pz);

    //HiggsBoson.printInfo();

    //std::cout << HiggsBoson.transversalMomentum() << "\n";

    //HiggsBoson.bosonDecay(decayParticle_1, decayParticle_2);

    //decayParticle_1  -> printInfo();
    //decayParticle_2 -> printInfo();

    //10000 higgsovih bozona
    
    //otvaranje filea za pisanje
    std::ofstream outfile;
    outfile.open("Analysis.txt", std::ios_base::app);
    outfile << "Higgsov bozon" << "\t\t\t\t\t\t\t" << "Cestica 1"<< "\t\t\t\t\t\t\t" << "cetverovektor" <<"\t\t\t\t\t\t\t"  
    <<"Cestica 2"  << "\t\t\t\t\t\t\t" << "cetverovektor\n";
    for(int i = 0; i < 10000; i++){
        float random1 = rand()%200 - 100;
        float random2 = rand()%200 - 100;
        float random3 = rand()%200 - 100;
        HiggsBoson.setMomentum(random1, random2, random3);
        ElementaryParticle *decayParticle_1 = new ElementaryParticle();
        ElementaryParticle *decayParticle_2 = new ElementaryParticle();        

        HiggsBoson.bosonDecay(decayParticle_1, decayParticle_2);
        outfile << HiggsBoson.E << "," <<  HiggsBoson.px << "," << HiggsBoson.py << "," << HiggsBoson.pz << "\t\t\t\t\t\t\t"
        << decayParticle_1 -> getName() << "\t\t\t\t\t\t\t"
        << decayParticle_1 -> E << "," 
        << decayParticle_1 -> px << ", " << decayParticle_1 -> py << ", " << decayParticle_1 -> pz << "\t\t\t\t\t\t\t"
        << decayParticle_2 -> getName() << "\t\t\t\t\t\t\t"
        << decayParticle_2 -> E << "," 
        << decayParticle_2 -> px << "," << decayParticle_2 -> py << "," << decayParticle_2 -> pz << "\n";
        

    }
    outfile.close();

    
    return 0;
}