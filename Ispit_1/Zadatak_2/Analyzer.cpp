#include <Analyzer.h>

Analyzer::Analyzer(){

}

void Analyzer::PoissonCI(double CL, int n){
    

    double lambda_plus = 50;
    double lambda_minus = 0;
    double sum_up;
    double sum_down;
    double increment = 0.001;
    int r = 0;

    while(sum_up <= (1 - CL)){
        sum_up = 0;

        for(r = 0; r <= n; r++){
            sum_up += TMath::Poisson(r, lambda_plus);
            
            
        }
        //cout << sum_up << "\n";
        lambda_plus -= increment;

    }

    while(sum_down <= (1 - CL)){
        sum_down = 0;
        for(r = n; r <= n + 1000; r++){ //n+1000 kao da ide u beskonacnost
            sum_down += TMath::Poisson(r, lambda_minus);
            
        }
        lambda_minus += increment;
        if(n == n + 1000)
            break;
        //cout << sum_down  << "\n";

    }

    cout << "lamdba_minus = " << lambda_minus << "\n";
    cout << "lambda_plus = " << lambda_plus << "\n";






}