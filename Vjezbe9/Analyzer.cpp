#include <Analyzer.h>

Analyzer::Analyzer(){

}

void Analyzer::LifeTimeFit(){
    gStyle -> SetOptStat(0);
    HistoLifeTime = new TH1F("Lifetime", "Lifetime", 24, 0., 10.);
    file = new TFile("/home/public/data/Lifetime/Lifetime.root"); //inicijalizacija file na zadani root file

    tree = (TTree*)file -> Get("Tree"); //inicijalzacija TTree objekta na podatke iz root-a

    tree -> SetBranchAddress("t", &t); //postavljanje branchova na odgovarajucu vrijednost

    

    nentries = tree -> GetEntries();

    for(i=0;i<nentries;i++)
    {
        tree->GetEntry(i);
        HistoLifeTime->Fill(t);
        sum+=t;
        
    }

    //float min = HistoLifeTime -> GetMinimum();
    //float max = HistoLifeTime -> GetMaximum();

    //cout << "min" << min << "max" << max;

    exp = new TF1("exp", "[0]/[1]*exp(-x/[1])", 0., 10.);

    exp -> SetParName(0, "C");
    exp -> SetParName(1, "Tau");
    exp -> SetParameter(0, 100.); //normalizacija
    exp -> SetParameter(1, 1.); // srednje vrijeme

    HistoLifeTime -> Fit(exp, "L");

    canvas1  = new TCanvas("canvas1", "canvas1", 600, 400);

    HistoLifeTime -> GetXaxis() -> SetTitle("t/s");
    HistoLifeTime -> GetYaxis() -> SetTitle("N");

    HistoLifeTime -> Draw();

    canvas1 -> SaveAs("HistoLifeTimeFit.png");

    cout << "tau = " << exp -> GetParameter(1) << "±" << exp -> GetParError(1) << "\n";

    C = exp -> GetParameter(0);
    cout << "C = " << C << "\n";
    

    mean=sum/nentries;
    error=mean/sqrt(nentries); //standard error

    cout << "Analiticki: tau = " << mean << "±" << error << "\n";
    

    delete exp;

    Likelihood = new TF1("Likelihood", "([0]/x)*exp(-1.0/x)", 0.1, 10.);
    Likelihood -> SetParameter(0, C);

    canvas2 = new TCanvas("canvas2", "canvas2", 600, 400);
    Likelihood -> GetXaxis() -> SetTitle("#tau");
    Likelihood -> GetYaxis() -> SetTitle("L(#tau)");

    Likelihood -> SetTitle("Likelihood function for t = 1s");
    Likelihood -> Draw();
    canvas2 -> SaveAs("Likelihood.png"); 

    delete Likelihood;

    logLikelihood = new TF1("logLikelihood", "-2.*[0]*log(1./x) + 2.*([1]/x)", 0.1, 5.);
    logLikelihood -> SetParameter(0, nentries);
    logLikelihood -> SetParameter(1, sum);

    canvas3 = new TCanvas("canvas3", "canvas3", 600, 400);

    logLikelihood -> GetXaxis() -> SetTitle("#tau");
    logLikelihood -> GetYaxis() -> SetTitle("-2ln(#tau)");

    logLikelihood -> SetTitle("-2ln(#tau)");

    logLikelihood -> Draw();
    
    canvas3 -> SaveAs("logLikelihood.png");

    tau_graph = logLikelihood -> GetMinimumX();
    Float_t err_dn = tau_graph - logLikelihood -> GetX(logLikelihood -> GetMinimum(0.1, 5) + 1, 0.1, tau_graph); //-2lnL=lnL_min+1
    Float_t err_up = logLikelihood -> GetX(logLikelihood -> GetMinimum(0.1, 5) + 1,tau_graph, 5) - tau_graph; //-2lnL=lnL_min+1

    cout << "Graficki tau = " << tau_graph << " + " << err_up << " - " << err_dn << "\n" ;  //??????

    delete logLikelihood;


}