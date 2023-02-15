#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1F.h>
#include <TCanvas.h>
#include <TString.h>
#include <TLegend.h>
#include <TLorentzVector.h>
#include <THStack.h>
#include <TGraph.h>
#include <TH2F.h>
#include <TF1.h>
#include <TH1.h>
#include <TStyle.h>
#include <TMath.h>

#include <iostream>
#include <vector>

using namespace std;

class Analyzer{
    public:
        Analyzer();
        void PoissonCI(double, int);
        

    

};