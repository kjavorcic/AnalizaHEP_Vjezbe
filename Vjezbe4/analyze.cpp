#include <iostream>
#include "Analyzer.h"
#include <TString.h>
int main(){
    Analyzer *analysis;
    analysis = new Analyzer();

    analysis -> ReadTxtFile("Analysis.txt");
    analysis -> ConvertTxtToRootFile("Anaylsis.txt", "Analysis.root");


    analysis -> ~Analyzer();


    return 0;
}