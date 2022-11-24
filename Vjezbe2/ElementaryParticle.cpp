#include <iostream>
#include "ElementaryParticle.h"

int main(){
    ElementaryParticle HiggsBoson("Higgs Boson", 125.18, true);
	ElementaryParticle TopQuark("Top Quark", 173, false);
	ElementaryParticle ZBoson("Z boson", 91.1, true);

    HiggsBoson.printInfo();
    return 0;
}