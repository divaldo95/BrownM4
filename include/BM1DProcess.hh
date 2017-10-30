#ifndef BM1DProcess_h
#define BM1DProcess_h 1

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

#include "TRandom.h"

class BM1DProcess {
public:
  BM1DProcess(Int_t n); //n is the number of steps
  BM1DProcess(Int_t n, Double_t mean, Double_t sigma); //n is the number of steps, mean and sigma are for Gauss
  ~BM1DProcess();
  
  void SetP0(Double_t p0_new);
  void SetP1(Double_t p1_new);
  void SetSigma(Double_t sigma_new);
  void SetMean(Double_t mean_new);

  void Init();
  void Run();
  
  std::vector<Double_t> GetT(){return t;}
  std::vector<Double_t> GetX(){return x;}

 private:
  Int_t nSteps;
  Double_t p0,p1,p2,p3,p4;
  Double_t mean,sigma;
  TRandom* randomGenerator;
  Double_t rand1,rand2;
  std::vector<Double_t> t;
  std::vector<Double_t> x;
};
  
#endif  
 
