#ifndef DEF_ZeeAnalyzer
#define DEF_ZeeAnalyzer

#include "EventAnalyzer.h"
#include "TH2F.h"
#include "FactorizedJetCorrector.h"
#include "JetCorrectorParameters.h"
#include "JetCorrectionUncertainty.h"

class ZeeAnalyzer: public EventAnalyzer {
    public: 
        ZeeAnalyzer(TTree *tree=0): EventAnalyzer(tree) { }
        void Analyze(bool isData, int option, string outputFileName, string label, string pileupWeightName);
	double getTriggerEff( TH2F *trigEffHist , double pt, double mass );
	double getTriggerEff3D( TH2F *triggerEffHist_Xbb0p0To0p9, 
				TH2F *triggerEffHist_Xbb0p9To0p95, 
				TH2F *triggerEffHist_Xbb0p95To0p98, 
				TH2F *triggerEffHist_Xbb0p98To1p0, 
				double pt, double mass, double PNetXbb );
        double JetEnergyCorrectionFactor( double jetRawPt, double jetEta, double jetPhi, double jetE,
					  double rho, double jetArea,
					  FactorizedJetCorrector *jetcorrector,
					  int jetCorrectionLevel = -1,
					  bool printDebug = false);
        double JetEnergyCorrectionFactor( double jetRawPt, double jetEta, double jetPhi, double jetE,
					  double rho, double jetArea,
					  int run,
					  std::vector<std::pair<int,int> > JetCorrectionsIOV,
					  std::vector<FactorizedJetCorrector*> jetcorrector,
					  int jetCorrectionLevel = -1,
					  bool printDebug = false);
};

#endif
