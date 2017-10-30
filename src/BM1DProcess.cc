#include "BM1DProcess.hh"

BM1DProcess::BM1DProcess(Int_t nP) : 
nSteps (nP), p0(0.5), p1(0.3), mean(0), sigma(1), limit_min(100), limit_max(180)
{
randomGenerator = new TRandom();
randomGaussGenerator = new TRandom();

}

BM1DProcess::BM1DProcess(Int_t nP, Double_t mean_init, Double_t sigma_init) : 
  nSteps (nP), p0(0.5), p1(0.3), mean(mean_init), sigma(sigma_init), limit_min(30), limit_max(100)
{
	randomGenerator = new TRandom();
	randomGaussGenerator = new TRandom();
}

BM1DProcess::~BM1DProcess()
{
	
}

void BM1DProcess::Init(){
  t.push_back(0.0);  //let's start at t=0, x=0, you can change it if you want, please use Set methods
	x.push_back(0.0);
	randomGenerator->SetSeed(0);
	randomGaussGenerator->SetSeed(0);
	mean=0.1;
	sigma=10;
}

void BM1DProcess::SetP0(Double_t p0_new){p0 = p0_new;}
void BM1DProcess::SetP1(Double_t p1_new){p1 = p1_new;}
void BM1DProcess::SetSigma(Double_t sigma_new){sigma=sigma_new;}
void BM1DProcess::SetMean(Double_t mean_new){mean=mean_new;}
void BM1DProcess::SetGeneratorSeed(Int_t seed_new){randomGenerator->SetSeed(seed_new);}
void BM1DProcess::SetGaussGeneratorSeed(Int_t seed_new){randomGaussGenerator->SetSeed(seed_new);}

void BM1DProcess::MultipleRun()
{

}

void BM1DProcess::Run(){
  for (Int_t i = 1;i < nSteps;i++)
    {
			if(limit_min<x[i-1] && x[i-1]<limit_max)
			{
				SetSigma(1);
			}
			else if(limit_min<x[i-1] && x[i-1]>limit_max)
			{
				SetSigma(10);
			}

			rand1 = randomGenerator->Uniform();
			rand2 = randomGaussGenerator->Gaus(mean,sigma);

			if(rand1 < p0) 
			{  //step in time, but no step in x
	  		t.push_back(t[i-1] + 1);
	  		x.push_back(x[i-1]);
			}
			else 
			{
	  		t.push_back(t[i-1]+1);
	  		x.push_back(x[i-1]+rand2); //rand2 determines the step direction
			}
		}
}
