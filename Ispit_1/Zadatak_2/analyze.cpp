#include <Analyzer.h>

int main(){
    Analyzer *analyze = new Analyzer();
    //cout << TMath::Poisson(5, 2.5);
    analyze -> PoissonCI(0.95, 4); //(CL, n)


}