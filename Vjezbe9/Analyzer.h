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
        void LifeTimeFit(); //fitanje funkcije


    private:
        TFile *file;        //preko Tfilea se otvara file
        TTree *tree;        //TTree objekt u kojeg ucitvamo sadrzaj root filea


        TH1F *HistoLifeTime; //objekt 1D histograma

        TCanvas *canvas1, *canvas2, *canvas3; //canvas objekti

        TF1 *exp, *Likelihood, *logLikelihood;   //objekt za formule, teorijski dio

        

        Float_t t, sum, mean, error, C, tau_graph;
        Int_t i, nentries;




};