#include "ZeeAnalyzer.h"
#include <stdlib.h> 
#include "JetTree.h"
#include <TFile.h>
//C++ includes
//json includes
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <TTree.h>
#include <TSystem.h>
//ROOT includes
#include "TH1F.h"

using namespace std;
using json = nlohmann::json;


// Function to load and parse the JSON file
std::map<int, std::vector<std::pair<int, int>>> loadJson(const std::string& filename) {
    std::ifstream file(filename);
    json j;
    file >> j;

    std::map<int, std::vector<std::pair<int, int>>> runLuminosityRanges;
    
    for (auto& [run, luminosityBlocks] : j.items()) {
        int runNumber = std::stoi(run);
        std::vector<std::pair<int, int>> ranges;
        
        for (const auto& range : luminosityBlocks) {
            ranges.emplace_back(range[0], range[1]);
        }
        
        runLuminosityRanges[runNumber] = ranges;
    }

    return runLuminosityRanges;
}


double ZeeAnalyzer::getTriggerEff3D( TH2F *triggerEffHist_Xbb0p0To0p9, 
				     TH2F *triggerEffHist_Xbb0p9To0p95, 
				     TH2F *triggerEffHist_Xbb0p95To0p98, 
				     TH2F *triggerEffHist_Xbb0p98To1p0, 
				     double pt, double mass, double PNetXbb ) {
  double result = 0.0;
  double tmpMass = 0;
  double tmpPt = 0;
  double tmpPNetXbb = 0;
  TH2F* trigEffHist = 0;
  if (PNetXbb < 0.9) {
    trigEffHist = triggerEffHist_Xbb0p0To0p9;
  } else if (PNetXbb < 0.95) {
    trigEffHist = triggerEffHist_Xbb0p9To0p95;    
  } else if (PNetXbb < 0.98) {
    trigEffHist = triggerEffHist_Xbb0p95To0p98;    
  } else {
    trigEffHist = triggerEffHist_Xbb0p98To1p0;    
  }
  
  if (trigEffHist) {
    // constrain to histogram bounds
    if( mass > trigEffHist->GetXaxis()->GetXmax() * 0.999 ) {
      tmpMass = trigEffHist->GetXaxis()->GetXmax() * 0.999;
    } else if ( mass < 0 ) {
      tmpMass = 0.001;
      //cout << "Warning: mass=" << mass << " is negative and unphysical\n";
    } else {
      tmpMass = mass;
    }
    
    if( pt > trigEffHist->GetYaxis()->GetXmax() * 0.999 ) {
      tmpPt = trigEffHist->GetYaxis()->GetXmax() * 0.999;
    } else if (pt < 0) {
      tmpPt = 0.001;
      cout << "Warning: pt=" << pt << " is negative and unphysical\n";
    } else {
      tmpPt = pt;
    }
    
    result = trigEffHist->GetBinContent(
					trigEffHist->GetXaxis()->FindFixBin( tmpMass ),
					trigEffHist->GetYaxis()->FindFixBin( tmpPt )
					);  
  } else {
    std::cout << "Error: expected a histogram, got a null pointer" << std::endl;
    return 0;
  }
  //cout << "mass = " << mass << " , pt = " << pt << " : trigEff = " << result << "\n";

  return result; 
}




double ZeeAnalyzer::getTriggerEff( TH2F *trigEffHist , double pt, double mass ) {
  double result = 0.0;
  double tmpMass = 0;
  double tmpPt = 0;

  if (trigEffHist) {
      // constrain to histogram bounds
      if( mass > trigEffHist->GetXaxis()->GetXmax() * 0.999 ) {
	tmpMass = trigEffHist->GetXaxis()->GetXmax() * 0.999;
      } else if ( mass < 0 ) {
	tmpMass = 0.001;
	//cout << "Warning: mass=" << mass << " is negative and unphysical\n";
      } else {
	tmpMass = mass;
      }

      if( pt > trigEffHist->GetYaxis()->GetXmax() * 0.999 ) {
	tmpPt = trigEffHist->GetYaxis()->GetXmax() * 0.999;
      } else if (pt < 0) {
	tmpPt = 0.001;
	cout << "Warning: pt=" << pt << " is negative and unphysical\n";
      } else {
	tmpPt = pt;
      }

      result = trigEffHist->GetBinContent(
				 trigEffHist->GetXaxis()->FindFixBin( tmpMass ),
				 trigEffHist->GetYaxis()->FindFixBin( tmpPt )
				 );  
         
  } else {
    std::cout << "Error: expected a histogram, got a null pointer" << std::endl;
    return 0;
  }
  
  //cout << "mass = " << mass << " , pt = " << pt << " : trigEff = " << result << "\n";

  return result; 
}

/*

//Jet Energy Corrections
double ZeeAnalyzer::JetEnergyCorrectionFactor( double jetRawPt, double jetEta, double jetPhi, double jetE,
						 double rho, double jetArea,
						 int run,
						 std::vector<std::pair<int,int> > JetCorrectionsIOV,
						 std::vector<FactorizedJetCorrector*> jetcorrector,
						 int jetCorrectionLevel,
						 bool printDebug) {

  int foundIndex = -1;
  for (unsigned int i=0; i<JetCorrectionsIOV.size(); i++) {
    if (run >= JetCorrectionsIOV[i].first && run <= JetCorrectionsIOV[i].second) {
      foundIndex = i;
    }
  }
  if (foundIndex == -1) {
    //cout << "Warning: run = " << run << " was not found in any valid IOV range. use default index = 0 for Jet energy corrections. \n";
    foundIndex = 0;
  }

  if (!jetcorrector[foundIndex]) {
    cout << "WWARNING: Jet corrector pointer is null. Returning JEC = 0. \n";
    return 0;
  }

  jetcorrector[foundIndex]->setJetEta(jetEta);
  jetcorrector[foundIndex]->setJetPt(jetRawPt);
  jetcorrector[foundIndex]->setJetPhi(jetPhi);
  jetcorrector[foundIndex]->setJetE(jetE);
  jetcorrector[foundIndex]->setRho(rho);
  jetcorrector[foundIndex]->setJetA(jetArea);

  std::vector<float> corrections;
  corrections = jetcorrector[foundIndex]->getSubCorrections();

  if (printDebug) cout << "Computing Jet Energy Corrections for jet with raw momentum: " << jetRawPt << " " << jetEta << " " << jetPhi << "\n";

  double cumulativeCorrection = 1.0;
  for (UInt_t j=0; j<corrections.size(); ++j) {

    //only correct up to the required level. if -1, then do all correction levels
    if (jetCorrectionLevel >= 0 && int(j) > jetCorrectionLevel) continue;

    double currentCorrection = corrections.at(j)/cumulativeCorrection;
    cumulativeCorrection = corrections.at(j);
    if (printDebug) cout << "Correction Level " << j << " : current correction = " << currentCorrection << " , cumulative correction = " << cumulativeCorrection << "\n";
  }
  if (printDebug) cout << "Final Cumulative Correction: " << cumulativeCorrection << "\n";

  return cumulativeCorrection;

}

//Jet Energy Corrections
double ZeeAnalyzer::JetEnergyCorrectionFactor( double jetRawPt, double jetEta, double jetPhi, double jetE,
						 double rho, double jetArea,
						 FactorizedJetCorrector *jetcorrector,
						 int jetCorrectionLevel,
						 bool printDebug) {
  if (!jetcorrector) {
    cout << "WWARNING: Jet corrector pointer is null. Returning JEC = 0. \n";
    return 0;
  }

  jetcorrector->setJetEta(jetEta);
  jetcorrector->setJetPt(jetRawPt);
  jetcorrector->setJetPhi(jetPhi);
  jetcorrector->setJetE(jetE);
  jetcorrector->setRho(rho);
  jetcorrector->setJetA(jetArea);

  std::vector<float> corrections;
  corrections = jetcorrector->getSubCorrections();

  if (printDebug) cout << "Computing Jet Energy Corrections for jet with raw momentum: " << jetRawPt << " " << jetEta << " " << jetPhi << "\n";

  double cumulativeCorrection = 1.0;
  for (UInt_t j=0; j<corrections.size(); ++j) {

    //only correct up to the required level. if -1, then do all correction levels
    if (jetCorrectionLevel >= 0 && int(j) > jetCorrectionLevel) continue;

    double currentCorrection = corrections.at(j)/cumulativeCorrection;
    cumulativeCorrection = corrections.at(j);
    if (printDebug) cout << "Correction Level " << j << " : current correction = " << currentCorrection << " , cumulative correction = " << cumulativeCorrection << "\n";
  }
  if (printDebug) cout << "Final Cumulative Correction: " << cumulativeCorrection << "\n";

  return cumulativeCorrection;

}

*/

struct Photon {
    double pt;
    double eta;
    double phi;
    double mva;
    int iPhiOriY;
    int iEtaOriX;
    double pfRelIso03_chg_quadratic;
    double pfRelIso03_all_quadratic;
    double r9;
    double energyErr;
    double energyRaw;
    bool bT;  //be True
};


// Define a Jet structure to hold the information for each jet
struct Jet {
    double pt;
    double btag_score;
    bool bT;    // Default value set to "false"
    double mass;
    double eta;
    double phi;
    double PtRes;
    double PtCorr;
    double PtCorrNeutrino;
};

// Function to calculate invariant mass of a jet pair
double calculateInvariantMass(const Jet& jet1, const Jet& jet2) {
    // Assuming jets' energy and momentum components
    TLorentzVector JetV1;
    TLorentzVector JetV2;
    JetV1.SetPtEtaPhiM(jet1.pt, jet1.eta, jet1.phi, jet1.mass);
    JetV2.SetPtEtaPhiM(jet2.pt, jet2.eta, jet2.phi, jet2.mass);
    double invariantMass = (JetV1+JetV2).M();
    return invariantMass;
}


void processPhoton(std::vector<Photon>& photons){
    std::sort(photons.begin(), photons.end(), [](const Photon& a, const Photon& b) {
        return a.pt > b.pt;
    });

    struct PhotonPair {
        int photon1_index;
        int photon2_index;
        double pt_sum;
    };

    std::vector<PhotonPair> photon_pairs;

    for (size_t i = 0; i < photons.size(); ++i) {
        for (size_t j = i + 1; j < photons.size(); ++j) {
            TLorentzVector phoV1;
            TLorentzVector phoV2;
            phoV1.SetPtEtaPhiM(photons[i].pt, photons[i].eta, photons[i].phi, 0);
            phoV2.SetPtEtaPhiM(photons[j].pt, photons[j].eta, photons[j].phi, 0);
		
            double pT = (phoV1 +phoV2).Pt();
	    if (photons[i].pt>35){
              photon_pairs.push_back({(int)i, (int)j, pT});
	    }
        }
    }
    if (photon_pairs.empty()) return;

    // Find the photon pair with the highest pT sum
    auto best_pair = *std::max_element(photon_pairs.begin(), photon_pairs.end(), [](const PhotonPair& a, const PhotonPair& b) {
        return a.pt_sum < b.pt_sum;
    });
    // Set the bT flag for the photon be selected
    photons[best_pair.photon1_index].bT = true;
    photons[best_pair.photon2_index].bT = true;
}


// Function to process jets, find b-jets, and modify b-T flag
void processJets(std::vector<Jet>& jets) {
    // Sort jets by pT (from largest to smallest)
    std::sort(jets.begin(), jets.end(), [](const Jet& a, const Jet& b) {
        return a.pt > b.pt;
    });

    struct JetPair {
        int jet1_index;
        int jet2_index;
        double invariant_mass;
        double btag_sum;
    };
    
    std::vector<JetPair> valid_pairs;

    // Select all possible jet pairs and filter by invariant mass window (70, 190)
    for (size_t i = 0; i < jets.size(); ++i) {
        for (size_t j = i + 1; j < jets.size(); ++j) {
            double mass = calculateInvariantMass(jets[i], jets[j]);
            if (mass >= 35 && mass <= 190 && fabs(jets[i].eta)<2.5 && fabs(jets[j].eta)<2.5) {
                valid_pairs.push_back({(int)i, (int)j, mass, jets[i].btag_score + jets[j].btag_score});
            }
        }
    }

    // If no valid pairs found, return early
    if (valid_pairs.empty()) return;

    // Find the jet pair with the highest b-tag score sum
    auto best_pair = *std::max_element(valid_pairs.begin(), valid_pairs.end(), [](const JetPair& a, const JetPair& b) {
        return a.btag_sum < b.btag_sum;
    });

    // Set the bT flag for the jets in the best pair
    jets[best_pair.jet1_index].bT = true;
    jets[best_pair.jet2_index].bT = true;
}



void ZeeAnalyzer::Analyze(bool isData, int Option, int cutConfig, string outputfilename, string year, string pileupWeightName)
{ 
    cout << "Initializing..." << endl;

    //----------------------------------------
    //Load auxiliary information
    //----------------------------------------  
    TH2F *triggerEffHist = 0;    
    TH2F *triggerEffHist_Xbb0p0To0p9 = 0;    
    TH2F *triggerEffHist_Xbb0p9To0p95 = 0;    
    TH2F *triggerEffHist_Xbb0p95To0p98 = 0;    
    TH2F *triggerEffHist_Xbb0p98To1p0 = 0;    
    TH2F *triggerEffMCHist = 0;    
    TH2F *triggerEffMCHist_Xbb0p0To0p9 = 0;    
    TH2F *triggerEffMCHist_Xbb0p9To0p95 = 0;    
    TH2F *triggerEffMCHist_Xbb0p95To0p98 = 0;    
    TH2F *triggerEffMCHist_Xbb0p98To1p0 = 0;    

    TH1F *pileupWeightHist = 0;
    TH1F *pileupWeightUpHist = 0;
    TH1F *pileupWeightDownHist = 0;
    
    string CMSSWDir = std::getenv("CMSSW_BASE");
    
    if (!isData) {
      string triggerEffFilename = "";
      string triggerEffMCFilename = "";
      if (year == "2016") {
	triggerEffFilename = CMSSWDir + "/src/HHToBBGG-Run3/data/JetHTTriggerEfficiency_2016.root";
	triggerEffMCFilename = CMSSWDir + "/src/HHToBBGG-Run3/data/JetHTTriggerEfficiency_Summer16.root";
      } else if (year == "2017") {
	triggerEffFilename = CMSSWDir + "/src/HHToBBGG-Run3/data/JetHTTriggerEfficiency_2017.root";
	triggerEffMCFilename = CMSSWDir + "/src/HHToBBGG-Run3/data/JetHTTriggerEfficiency_Fall17.root";
      } else if (year == "2018") {
	triggerEffFilename = CMSSWDir + "/src/HHToBBGG-Run3/data/JetHTTriggerEfficiency_2018.root";
	triggerEffMCFilename = CMSSWDir + "/src/HHToBBGG-Run3/data/JetHTTriggerEfficiency_Fall18.root";
      } else if (year == "2022" || year == "2022EE" || year == "2023" || year == "2023BPix" || year == "2024" || year == "2025"){
        triggerEffFilename = CMSSWDir + "/src/HHToBBGG-Run3/data/JetHTTriggerEfficiency_2018.root";
        triggerEffMCFilename = CMSSWDir + "/src/HHToBBGG-Run3/data/JetHTTriggerEfficiency_Fall18.root";
      }

        else {
	cout << "[ZeeAnalyzer] Warning: year " << year << " is not supported. \n";
      }
      TFile *triggerEffFile = new TFile(triggerEffFilename.c_str(),"READ");
      TFile *triggerEffMCFile = new TFile(triggerEffMCFilename.c_str(),"READ");

      if (!triggerEffFile) {
	cout << "Warning : triggerEffFile " << triggerEffFilename << " could not be opened.\n";
      } else {
	cout << "Opened triggerEffFile " << triggerEffFilename << "\n";
      }
      if (triggerEffFile) {
	triggerEffHist = (TH2F*)triggerEffFile->Get("efficiency_ptmass");  
	triggerEffHist_Xbb0p0To0p9 = (TH2F*)triggerEffFile->Get("efficiency_ptmass_Xbb0p0To0p9");  
	triggerEffHist_Xbb0p9To0p95 = (TH2F*)triggerEffFile->Get("efficiency_ptmass_Xbb0p9To0p95");  
	triggerEffHist_Xbb0p95To0p98 = (TH2F*)triggerEffFile->Get("efficiency_ptmass_Xbb0p95To0p98");  
	triggerEffHist_Xbb0p98To1p0 = (TH2F*)triggerEffFile->Get("efficiency_ptmass_Xbb0p98To1p0");    
      } else {
	cout << "Warning : could not open file " << triggerEffFilename << "\n";
      }
      if (triggerEffHist) cout << "Found triggerEffHist in file " << triggerEffFilename << "\n";
      if (triggerEffHist_Xbb0p0To0p9) cout << "Found triggerEffHist_Xbb0p0To0p9 in file " << triggerEffFilename << "\n";
      if (triggerEffHist_Xbb0p9To0p95) cout << "Found triggerEffHist_Xbb0p9To0p95 in file " << triggerEffFilename << "\n";
      if (triggerEffHist_Xbb0p95To0p98) cout << "Found triggerEffHist_Xbb0p95To0p98 in file " << triggerEffFilename << "\n";
      if (triggerEffHist_Xbb0p98To1p0) cout << "Found triggerEffHist_Xbb0p98To1p0 in file " << triggerEffFilename << "\n";

      if (!triggerEffMCFile) {
	cout << "Warning : triggerEffMCFile " << triggerEffMCFilename << " could not be opened.\n";
      } else {
	cout << "Opened triggerEffMCFile " << triggerEffMCFilename << "\n";
      }
      if (triggerEffMCFile) {
	triggerEffMCHist = (TH2F*)triggerEffMCFile->Get("efficiency_ptmass");    
	triggerEffMCHist_Xbb0p0To0p9 = (TH2F*)triggerEffMCFile->Get("efficiency_ptmass_Xbb0p0To0p9");  
	triggerEffMCHist_Xbb0p9To0p95 = (TH2F*)triggerEffMCFile->Get("efficiency_ptmass_Xbb0p9To0p95");  
	triggerEffMCHist_Xbb0p95To0p98 = (TH2F*)triggerEffMCFile->Get("efficiency_ptmass_Xbb0p95To0p98");  
	triggerEffMCHist_Xbb0p98To1p0 = (TH2F*)triggerEffMCFile->Get("efficiency_ptmass_Xbb0p98To1p0");    
      } else {
	cout << "Warning : could not open file " << triggerEffMCFilename << "\n";
      }
      if (triggerEffMCHist) cout << "Found triggerEffMCHist in file " << triggerEffMCFilename << "\n";
      if (triggerEffMCHist_Xbb0p0To0p9) cout << "Found triggerEffMCHist_Xbb0p0To0p9 in file " << triggerEffMCFilename << "\n";
      if (triggerEffMCHist_Xbb0p9To0p95) cout << "Found triggerEffMCHist_Xbb0p9To0p95 in file " << triggerEffMCFilename << "\n";
      if (triggerEffMCHist_Xbb0p95To0p98) cout << "Found triggerEffMCHist_Xbb0p95To0p98 in file " << triggerEffMCFilename << "\n";
      if (triggerEffMCHist_Xbb0p98To1p0) cout << "Found triggerEffMCHist_Xbb0p98To1p0 in file " << triggerEffMCFilename << "\n";
 
      string pileupWeightFilename = "";
      if (year == "2022") {
	pileupWeightFilename = CMSSWDir + "/src/HHToBBGG-Run3/data/PileupWeights/PileupReweight_Summer22.root";
      } else if (year == "2022EE") {
	pileupWeightFilename = CMSSWDir + "/src/HHToBBGG-Run3/data/PileupWeights/PileupReweight_Summer22EE.root";
      } else if (year == "2023") {
	pileupWeightFilename = CMSSWDir + "/src/HHToBBGG-Run3/data/PileupWeights/PileupReweight_Summer23.root";
      } else if (year == "2023BPix") {
	pileupWeightFilename = CMSSWDir + "/src/HHToBBGG-Run3/data/PileupWeights/PileupReweight_Summer23BPix.root";
      } else if (year == "2024") {
	pileupWeightFilename = CMSSWDir + "/src/HHToBBGG-Run3/data/PileupWeights/PileupReweight_Summer23.root";
      } else if (year == "2025") {
	pileupWeightFilename = CMSSWDir + "/src/HHToBBGG-Run3/data/PileupWeights/PileupReweight_Summer23.root";
      }



      TFile *pileupWeightFile = new TFile(pileupWeightFilename.c_str(),"READ");
      if (!pileupWeightFile) {
	cout << "Warning : pileupWeightFile " << pileupWeightFile << " could not be opened.\n";  
      } else {
	cout << "Opened pileupWeightFile " << pileupWeightFilename << "\n"; 
      }
      string pileupWeightHistname = "PUWeight_" + pileupWeightName + "_" + year;
      if (pileupWeightFile) {
	pileupWeightHist = (TH1F*)(pileupWeightFile->Get("npu_nominal"));
	pileupWeightHist->SetDirectory(0);
	pileupWeightUpHist = (TH1F*)(pileupWeightFile->Get("npu_up"));
	pileupWeightUpHist->SetDirectory(0);
	pileupWeightDownHist = (TH1F*)(pileupWeightFile->Get("npu_down"));
	pileupWeightDownHist->SetDirectory(0);
      } 
      if (pileupWeightHist) {
	cout << "Found pileupWeightHist " << pileupWeightHistname << "in file " << pileupWeightFilename << "\n";
      } else {
	cout << "Warning :  could not find pileupWeightHist named " 
	     << pileupWeightHistname 
	     << " in file " << pileupWeightFilename << "\n";
      }
      if (pileupWeightUpHist) {
	cout << "Found pileupWeightUpHist " << pileupWeightHistname+"_SysUp" << "in file " << pileupWeightFilename << "\n";
      } else {
	cout << "Warning :  could not find pileupWeightUpHist named " 
	     << pileupWeightHistname +"_SysUp"
	     << " in file " << pileupWeightFilename << "\n";
      }
      if (pileupWeightDownHist) {
	cout << "Found pileupWeightDownHist " << pileupWeightHistname+"_SysDown" << "in file " << pileupWeightFilename << "\n";
      } else {
	cout << "Warning :  could not find pileupWeightDownHist named " 
	     << pileupWeightHistname +"_SysDown"
	     << " in file " << pileupWeightFilename << "\n";
      }
      pileupWeightFile->Close();
      pileupWeightHist->Print();
    
    }

    //----------------------------------------
    //Jet Mass Scale: https://github.com/cms-nanoAOD/nanoAOD-tools/blob/a4b3c03ca5d8f4b8fbebc145ddcd605c7553d767/python/postprocessing/modules/jme/jetmetHelperRun2.py#L45-L58
    //----------------------------------------
    float* jmsValues;//{nominal, down, up}
    if(year == "2016")
      {
	float tmp_jms[] = {1.00, 0.9906, 1.0094};
	jmsValues = tmp_jms;
      }
    else if(year == "2017")
      {
	//float tmp_jms[] = {0.982, 0.978, 0.986};
	float tmp_jms[] = {1.0016, 0.978, 0.986}; //Tuned to our Top control region
	jmsValues = tmp_jms;
      }
    else if(year == "2018")
      {
	float tmp_jms[] = {0.997, 0.993, 1.001};
	jmsValues = tmp_jms;
      }
    else if(year == "2022" || year == "2022EE")
      {
	float tmp_jms[] = {0.997, 0.993, 1.001};
	jmsValues = tmp_jms;
      }
    else if(year == "2023" || year == "2023BPix")
      {
	float tmp_jms[] = {0.997, 0.993, 1.001};
	jmsValues = tmp_jms;
      }
    else if(year == "2024" || year == "2025")
      {
	float tmp_jms[] = {0.997, 0.993, 1.001};
	jmsValues = tmp_jms;
      }      
    else
      {
	std::cout << "year is not acceptable! Use: 2016, 2017, 2018" << std::endl;
	exit(EXIT_FAILURE);
      }

    //----------------------------------------
    //Jet Mass Resolution: https://github.com/cms-nanoAOD/nanoAOD-tools/blob/a4b3c03ca5d8f4b8fbebc145ddcd605c7553d767/python/postprocessing/modules/jme/jetmetHelperRun2.py#L45-L58
    //----------------------------------------
    float* jmrValues;//{nominal, down, up}
    if(year == "2016")
      {
	//float tmp_jmr[] = {1.00, 1.0, 1.2};
	float tmp_jmr[] = {1.00, 1.0, 1.09}; //Tuned to our Top control region
	jmrValues = tmp_jmr;
      }
    else if(year == "2017")
      {
	//float tmp_jmr[] = {1.09, 1.04, 1.14};
	float tmp_jmr[] = {1.03, 1.00, 1.07};  //Tuned to our Top control region
        jmrValues = tmp_jmr;
      }
    else if(year == "2018")
      {
	//float tmp_jmr[] = {1.24, 1.20, 1.28};
	float tmp_jmr[] = {1.065, 1.031, 1.099}; //Tuned to our Top control region
        jmrValues = tmp_jmr;
      } 
    else if(year == "2022" || year == "2022EE")
      {
	//float tmp_jmr[] = {1.24, 1.20, 1.28};
	float tmp_jmr[] = {1.065, 1.031, 1.099}; //Tuned to our Top control region
        jmrValues = tmp_jmr;
      }
    else if(year == "2023" || year == "2023BPix")
      {
	//float tmp_jmr[] = {1.24, 1.20, 1.28};
        float tmp_jmr[] = {1.065, 1.031, 1.099}; //Tuned to our Top control region
	jmrValues = tmp_jmr;
      }
    else if(year == "2024"|| year == "2025" )
      {
	//float tmp_jmr[] = {1.24, 1.20, 1.28};
        float tmp_jmr[] = {1.065, 1.031, 1.099}; //Tuned to our Top control region
	jmrValues = tmp_jmr;
      }
    else
      {
	std::cout << "year is not acceptable! Use: 2016, 2017, 2018" << std::endl;
	exit(EXIT_FAILURE);
      }


    //----------------------------------------
    //---jet energy scale and uncertainty
    //----------------------------------------
/*
    std::vector<FactorizedJetCorrector*> JetCorrector = std::vector<FactorizedJetCorrector*>();
    std::vector<std::pair<int,int> > JetCorrectorIOV = std::vector<std::pair<int,int> >();
    std::vector<std::vector<JetCorrectorParameters> > correctionParameters = std::vector<std::vector<JetCorrectorParameters> >();
    std::vector<std::pair<int,int> > JetCorrectionsIOV = std::vector<std::pair<int,int> >();
      
    string jecPathname = CMSSWDir + "/src/HHToBBGG-Run3/data/JEC/Summer22_22Sep2023_RunCD_V2_DATA/";
    std::vector<JetCorrectorParameters> correctionParametersTemp = std::vector<JetCorrectorParameters> ();
    correctionParametersTemp.push_back(JetCorrectorParameters(
                  Form("%s/Summer22_22Sep2023_RunCD_V2_DATA_L1FastJet_AK4PFchs.txt", jecPathname.c_str())));
    correctionParametersTemp.push_back(JetCorrectorParameters(
                  Form("%s/Summer22_22Sep2023_RunCD_V2_DATA_L2Relative_AK4PFchs.txt", jecPathname.c_str())));
    correctionParametersTemp.push_back(JetCorrectorParameters(
                  Form("%s/Summer22_22Sep2023_RunCD_V2_DATA_L3Absolute_AK4PFchs.txt", jecPathname.c_str())));
    correctionParametersTemp.push_back(JetCorrectorParameters(
                  Form("%s/Summer22_22Sep2023_RunCD_V2_DATA_L2L3Residual_AK4PFchs.txt", jecPathname.c_str())));

    FactorizedJetCorrector *JetCorrectorTemp = new FactorizedJetCorrector(correctionParametersTemp);
    correctionParameters.push_back(correctionParametersTemp);
    JetCorrector.push_back( JetCorrectorTemp );
    JetCorrectionsIOV.push_back( std::pair<int,int>( 0, 99999999 ));    

    cout << Form("%s/Summer22_22Sep2023_RunCD_V2_DATA_L1FastJet_AK4PFchs.txt", jecPathname.c_str()) << "\n";
  */  
    
    string JECUncertaintyFile = "";
    if (year == "2016") {
      JECUncertaintyFile = CMSSWDir + "/src/HHToBBGG-Run3/data/JEC/Summer16_07Aug2017_V11_MC/Summer16_07Aug2017_V11_MC_Uncertainty_AK8PFPuppi.txt";
    } else if (year == "2017") {
      JECUncertaintyFile = CMSSWDir + "/src/HHToBBGG-Run3/data/JEC/Fall17_17Nov2017_V32_MC/Fall17_17Nov2017_V32_MC_Uncertainty_AK8PFPuppi.txt";
    } else if (year == "2018") {
     JECUncertaintyFile = CMSSWDir + "/src/HHToBBGG-Run3/data/JEC/Autumn18_V19_MC/Autumn18_V19_MC_Uncertainty_AK8PFPuppi.txt";
    } else if (year == "2022" or year == "2022EE") {
     JECUncertaintyFile = CMSSWDir + "/src/HHToBBGG-Run3/data/JEC/Autumn18_V19_MC/Autumn18_V19_MC_Uncertainty_AK8PFPuppi.txt";
    }
    JetCorrectionUncertainty *jecUnc = new JetCorrectionUncertainty(JECUncertaintyFile.c_str());
    
    //----------------------------------------
    //Output file
    //----------------------------------------  
    string outfilename = outputfilename;
    if (outfilename == "") outfilename = "HHTo2B2GNtuple.root";
    TFile *outFile = new TFile(outfilename.c_str(), "RECREATE");    
 
    //histogram containing total number of processed events (for normalization)
    TH1F *NEvents = new TH1F("NEvents", "NEvents", 1, 1, 2);

    //output TTree
    TTree *outputTree = new TTree("tree", "");

    //histogram with jet cutflow
    TH1F* jetCutflow = new TH1F("jetCutflow", "Jet Selection Cutflow;Selection Step;Events", 6, 0, 6);
    jetCutflow->GetXaxis()->SetBinLabel(1, "All Events");
    jetCutflow->GetXaxis()->SetBinLabel(2, "pT>25 GeV ");
    jetCutflow->GetXaxis()->SetBinLabel(3, "Eta < 2.5");
    jetCutflow->GetXaxis()->SetBinLabel(4, "Delta r > 0.4");
    jetCutflow->GetXaxis()->SetBinLabel(5, "Dijet mass in 70-190 GeV");


    
 
    //------------------------
    //declare branch variables
    //------------------------  
    float weight = 0;
    float triggerEffWeight = 0;
    float triggerEff3DWeight = 0;
    float triggerEffMCWeight = 0;
    float triggerEffMC3DWeight = 0;
    float pileupWeight = 0;
    float pileupWeightUp = 0;
    float pileupWeightDown = 0;
    float totalWeight = 0;
//----------b Quark---
    float genbQuark1_Pt = -99;
    float genbQuark1_Eta = -99;
    float genbQuark1_Phi = -99;
    float genbQuark2_Pt = -99;
    float genbQuark2_Eta = -99;
    float genbQuark2_Phi = -99;
    //to bb Higgs 
    float tobbHiggs_Pt = -99;
    float tobbHiggs_Eta = -99;
    float tobbHiggs_Phi = -99;
    float tobbHiggs_Mass = -99;
    float toggHiggs_Pt = -99;
    float toggHiggs_Eta = -99;
    float toggHiggs_Phi = -99;
    float toggHiggs_Mass = -99;
//--------------------------
//---------gen B-Jets-------
    float GenBJet1_Pt = -99;
    float GenBJet1_Eta = -99;
    float GenBJet1_Phi = -99;
    float GenBJet1_Mass = -99;
    float GenBJet2_Pt = -99;
    float GenBJet2_Eta = -99;
    float GenBJet2_Phi = -99;
    float GenBJet2_Mass = -99;
    float GenBJet3_Pt = -99;
    float GenBJet3_Eta = -99;
    float GenBJet3_Phi = -99;
    float GenBJet3_Mass = -99;
    float GenBJet4_Pt = -99;
    float GenBJet4_Eta = -99;
    float GenBJet4_Phi = -99;
    float GenBJet4_Mass = -99;
    float GenBJet5_Pt = -99;
    float GenBJet5_Eta = -99;
    float GenBJet5_Phi = -99;
    float GenBJet5_Mass = -99;

//-------------------------    
    float genHiggs1Pt = -1;
    float genHiggs1Eta = -1;
    float genHiggs1Phi = -1;
    float genHiggs2Pt = -1;
    float genHiggs2Eta = -1;
    float genHiggs2Phi = -1;
    float genPhoton1Pt = -1;
    float genPhoton1Eta = -1;
    float genPhoton1Phi = -1;    
    float genPhoton2Pt = -1;
    float genPhoton2Eta = -1;
    float genPhoton2Phi = -1;    
    int genPho1_Idx = -1;
    int genPho2_Idx = -1;
    float genHH_pt = -99;
    float genHH_eta = -99;
    float genHH_phi = -99;
    float genHH_mass = -99;
//----------------GenFatJet-------
    float FatJetMatch_Pt = -99;
    float FatJetMatch_Eta = -99;
    float FatJetMatch_Phi = -99;
    float FatJetMatch_Mass = -99;
    float FatJetMatch_corrMass = -99;
    float FatJetMatch_PNet = -99;
 //   float FatJetMatch_Flav = -99;

    float FatJetClose1_Pt = -99;
    float FatJetClose1_Eta = -99;
    float FatJetClose1_Phi = -99;
    float FatJetClose1_Mass = -99;
 //   float FatJetClose1_Flav = -99;
    
    float FatJetClose2_Pt = -99;
    float FatJetClose2_Eta = -99;
    float FatJetClose2_Phi = -99;
    float FatJetClose2_Mass = -99;
 //   float FatJetClose2_Flav = -99;

//-------------------------------
    float genWPt = -1;
    float genWEta = -1;
    float genWPhi = -1;
    float genZPt = -1;
    float genZEta = -1;
    float genZPhi = -1;
    float genTop1Mass = -1;
    float genTop1Pt = -1;
    float genTop1Eta = -1;
    float genTop1Phi = -1;   
    float genTop2Mass = -1;
    float genTop2Pt = -1;
    float genTop2Eta = -1;
    float genTop2Phi = -1;   
    float genMTT = -1;
    float genLeptonPt = -1;
    float genLeptonEta = -1;
    float genLeptonPhi = -1;
    int   genLeptonId = 0;
    int   genLeptonMotherId = 0;
// Reco_FatJet -------------------
 //   float RecoFatJetCan_Pt = -99;
 //   float RecoFatJetCan_Eta = -99;
//    float RecoFatJetCan_Phi = -99;
//    float RecoFatJetCan_MS = -99;
//    float RecoFatJetCan_PNet = -99;
 //   float RecoFatJetCan_DDB = -99;
    
 //   float RecoFatJetClose1_Pt = -99;
 //   float RecoFatJetClose1_Eta = -99;
 //   float RecoFatJetClose1_Phi = -99;
 //   float RecoFatJetClose1_MS = -99;
 //   float RecoFatJetClose1_PNet = -99;
 //   float RecoFatJetClose1_DDB = -99;

 //   float RecoFatJetClose2_Pt = -99;
 //   float RecoFatJetClose2_Eta = -99;
 //   float RecoFatJetClose2_Phi = -99;
 //   float RecoFatJetClose2_MS = -99;
 //   float RecoFatJetClose2_PNet = -99;
 //   float RecoFatJetClose2_DDB = -99;
//--------------------------------------
    int NJets = 0;
//   float MET = -99;
    float METPt = -99;
    float METPhi = -99;
    float METsumEt = -99;
    float METEta = 0; 

    float fatJet1Pt = -99;
    float fatJet1Pt_JES_Up   = -99;
    float fatJet1Pt_JES_Down = -99;
    float fatJet1Eta = -99;
    float fatJet1Phi = -99;
    float fatJet1Mass = -99;
    float fatJet1MassSD      = -99;
    float fatJet1MassSD_UnCorrected  = -99;
    float fatJet1MassSD_JMS_Up       = -99;//jet mass scale up
    float fatJet1MassSD_JMS_Down     = -99;//jet mass scale down
    float fatJet1MassSD_JMR_Up       = -99;//jet mass resolution up
    float fatJet1MassSD_JMR_Down     = -99;//jet mass resolution down
    float fatJet1DDBTagger = -99;
    float fatJet1PNetXbb = -99;
    float fatJet1PNetXcc = -99;
    float fatJet1PNetXqq = -99;
    float fatJet1PNetQCD = -99;
    int   fatJet1GenMatchIndex = -99;
    float fatJet1Tau3OverTau2 = -99;
    float fatJet1_n2b1 = -99; 
    bool fatJet1HasMuon = 0;
    bool fatJet1HasElectron = 0;
    bool fatJet1HasBJetCSVLoose = 0;
    bool fatJet1HasBJetCSVMedium = 0;
    bool fatJet1HasBJetCSVTight = 0;
    bool fatJet1OppositeHemisphereHasBJet = 0;
    float fatJet2Pt = -99;
    float fatJet2Pt_JES_Up   = -99;
    float fatJet2Pt_JES_Down = -99;
    float fatJet2Eta = -99;
    float fatJet2Phi = -99;
    float fatJet2Mass = -99;
    float fatJet2MassSD = -99;
    float fatJet2MassSD_UnCorrected  = -99;
    float fatJet2MassSD_JMS_Up       = -99;//jet mass scale up
    float fatJet2MassSD_JMS_Down     = -99;//jet mass scale down
    float fatJet2MassSD_JMR_Up       = -99;//jet mass resolution up
    float fatJet2MassSD_JMR_Down     = -99;//jet mass resolution down
    float fatJet2DDBTagger = -99;
    float fatJet2PNetXbb = -99;
    float fatJet2PNetXcc = -99;
    float fatJet2PNetXqq = -99;
    float fatJet2PNetQCD = -99;
    int   fatJet2GenMatchIndex = -99;
    float fatJet2Tau3OverTau2 = -99;
    bool fatJet2HasMuon = 0;
    bool fatJet2HasElectron = 0;
    bool fatJet2HasBJetCSVLoose = 0;
    bool fatJet2HasBJetCSVMedium = 0;
    bool fatJet2HasBJetCSVTight = 0;
    float fatJet3Pt = -99;
    float fatJet3Pt_JES_Up   = -99;
    float fatJet3Pt_JES_Down = -99;
    float fatJet3Eta = -99;
    float fatJet3Phi = -99;
    float fatJet3Mass = -99;
    float fatJet3MassSD = -99;
    float fatJet3MassSD_UnCorrected  = -99;
    float fatJet3MassSD_JMS_Up       = -99;//jet mass scale up
    float fatJet3MassSD_JMS_Down     = -99;//jet mass scale down
    float fatJet3MassSD_JMR_Up       = -99;//jet mass resolution up
    float fatJet3MassSD_JMR_Down     = -99;//jet mass resolution down
    float fatJet3DDBTagger = -99;
    float fatJet3PNetXbb = -99;
    float fatJet3PNetXcc = -99;
    float fatJet3PNetXqq = -99;
    float fatJet3PNetQCD = -99;
    float fatJet3Tau3OverTau2 = -99;
    bool fatJet3HasMuon = 0;
    bool fatJet3HasElectron = 0;
    bool fatJet3HasBJetCSVLoose = 0;
    bool fatJet3HasBJetCSVMedium = 0;
    bool fatJet3HasBJetCSVTight = 0;
    float hh_pt = -99;
    float hh_eta = -99;
    float hh_phi = -99;
    float hh_mass = -99;        
    float hh_pt_JESUp = -99;
    float hh_pt_JESDown = -99;
    float hh_pt_JMSUp = -99;
    float hh_pt_JMSDown = -99;
    float hh_pt_JMRUp = -99;
    float hh_pt_JMRDown = -99;
    float hh_eta_JESUp = -99;
    float hh_eta_JESDown = -99;
    float hh_eta_JMSUp = -99;
    float hh_eta_JMSDown = -99;
    float hh_eta_JMRUp = -99;
    float hh_eta_JMRDown = -99;
    float hh_mass_JESUp = -99;
    float hh_mass_JESDown = -99;
    float hh_mass_JMSUp = -99;
    float hh_mass_JMSDown = -99;
    float hh_mass_JMRUp = -99;
    float hh_mass_JMRDown = -99;    
    float fatJet1PtOverMHH = -99;
    float fatJet1PtOverMHH_JESUp = -99;
    float fatJet1PtOverMHH_JESDown = -99;
    float fatJet1PtOverMHH_JMSUp = -99;
    float fatJet1PtOverMHH_JMSDown = -99;
    float fatJet1PtOverMHH_JMRUp = -99;
    float fatJet1PtOverMHH_JMRDown = -99;
    float fatJet1PtOverMSD = -99;
    float fatJet2PtOverMHH = -99;
    float fatJet2PtOverMHH_JESUp = -99;
    float fatJet2PtOverMHH_JESDown = -99;
    float fatJet2PtOverMHH_JMSUp = -99;
    float fatJet2PtOverMHH_JMSDown = -99;
    float fatJet2PtOverMHH_JMRUp = -99;
    float fatJet2PtOverMHH_JMRDown = -99;
    float fatJet2PtOverMSD = -99;
    float deltaEta_j1j2 = -99;
    float deltaPhi_j1j2 = -99;
    float deltaR_j1j2 = -99;    
    float ptj2_over_ptj1 = -99;
    float mj2_over_mj1 = -99;
    
    float lep1Pt = -99;
    float lep1Eta = -99;
    float lep1Phi = -99;
    int   lep1Id = 0;
    float lep2Pt = -99;
    float lep2Eta = -99;
    float lep2Phi = -99;
    int   lep2Id = 0;
    float lep1mva = -99;
    float lep2mva = -99;
    
    float Muon_1Pt = -99;
    float Muon_1Eta = -99;
    float Muon_1Phi = -99;
    int   Muon_1Id = 0;
    float Muon_2Pt = -99;
    float Muon_2Eta = -99;
    float Muon_2Phi = -99;
    int   Muon_2Id = 0;
    float Muon_1mva = -99;
    float Muon_2mva = -99;

    float Ele_1Pt = -99;
    float Ele_1Eta = -99;
    float Ele_1Phi = -99;
    int   Ele_1Id = 0;
    float Ele_2Pt = -99;
    float Ele_2Eta = -99;
    float Ele_2Phi = -99;
    int   Ele_2Id = 0;
    float Ele_1mva = -99;
    float Ele_2mva = -99;

    float pho1Pt = -99;
    float pho1Eta = -99;
    float pho1Phi = -99;
    float pho1_mvaID = -99;
    bool pho1_electronVeto = -99;
// ------ new added bool value -----------
    bool pho1r9 = 0;
    bool pho2r9 = 0;
    bool pho1_ChIOvEt = 0;
    bool pho2_ChIOvEt = 0;
    bool pho1_ChI = 0;
    bool pho2_ChI = 0;
    float pho1_hoe = 0;
    float pho2_hoe = 0;
    float pho1ChIso = -99;
    float pho2ChIso = -99;
    float pho1R9 = -99;
    float pho2R9=-99;
    int  pho1_seediPhiOriY = -99;
    int pho1_seediEtaOriX = -99;
    int  pho2_seediPhiOriY = -99;
    int pho2_seediEtaOriX = -99;

    float pho1_pfRelIso03_all_quadratic = -99;
    float pho2_pfRelIso03_all_quadratic = -99;

    int pho1QCD_realMatched = 0;
    int pho2QCD_realMatched = 0; 
    float Matched_genpho1Pt = -99;
    float Matched_genpho2Pt = -99;
    int  pho1genId = -99;
    int  pho2genId = -99;
//------------------
    float pho2Pt = -99;
    float pho2Eta = -99;
    float pho2Phi = -99;
    float pho2_mvaID = -99;
    bool pho2_electronVeto = -99;
// ------
    float b_jet1Pt = -99;
    float b_jet1Eta = -99;
    float b_jet1Phi = -99;
    float b_jet1Mass = -99;
    float b_jet1PNet = -99;
    float b_jet1PtRes = -99;
    float b_jet1PtCorr = -99;
    float b_jet1PtCorrNeutrino = -99;

    float b_jet2Pt = -99;
    float b_jet2Eta = -99;
    float b_jet2Phi = -99;
    float b_jet2Mass = -99;
    float b_jet2PNet = -99;
    float b_jet2PtRes = -99;
    float b_jet2PtCorr = -99;
    float b_jet2PtCorrNeutrino = -99;
//-------    
    float jet1Pt = -99;
    float jet1Eta = -99;
    float jet1Phi = -99;
    float jet1Mass = -99;
    float jet1PNet = -99;
    float jet1DeepFlavB = -99;
    int jet1Flav = -1;

    float jet2Pt = -99;
    float jet2Eta = -99;
    float jet2Phi = -99;
    float jet2Mass = -99;
    float jet2PNet = -99;
    float jet2DeepFlavB = -99;
    int jet2Flav = -1;
    
    float jet3Pt = -99;
    float jet3Eta = -99;
    float jet3Phi = -99;
    float jet3Mass = -99;
    float jet3PNet = -99;
    float jet3DeepFlavB = -99;
    int jet3Flav = -1;

    float jet4Pt = -99;
    float jet4Eta = -99;
    float jet4Phi = -99;
    float jet4Mass = -99;
    float jet4PNet = -99;
    float jet4DeepFlavB = -99;
    int jet4Flav = -1;

    float jet5Pt = -99;
    float jet5Eta = -99;
    float jet5Phi = -99;
    float jet5Mass = -99;
    float jet5PNet = -99;
    float jet5DeepFlavB = -99;
    int jet5Flav = -1;

    float jet6Pt = -99;
    float jet6Eta = -99;
    float jet6Phi = -99;
    float jet6Mass = -99;
    float jet6PNet = -99;

    // Add jets_mass and DiJets Mass
    float Dijets_Mass = -99;
    float DijetsCan_Mass = -99;
    float Dijetsall_Mass = -99;
    //variables for overlap removal with VBF HH->4b boosted analysis
    int isVBFtag = 0;
    float dijetmass = -99;
    float vbfjet1Pt = -99;
    float vbfjet1Eta = -99;
    float vbfjet1Phi = -99;
    float vbfjet1Mass = -99;
    float vbfjet2Pt = -99;
    float vbfjet2Eta = -99;
    float vbfjet2Phi = -99;
    float vbfjet2Mass = -99;
    float vbffatJet1Pt = -99;
    float vbffatJet1Eta = -99;
    float vbffatJet1Phi = -99;
    float vbffatJet1PNetXbb = -99;
    float vbffatJet2Pt = -99;
    float vbffatJet2Eta = -99;
    float vbffatJet2Phi = -99;
    float vbffatJet2PNetXbb = -99;
    // add b taggers
    
    int nSigBjets = 0;
    float Jet_PNetSignal[5];
    float Jet_DeepJetSignal[5];
    float Jet_bmatchPt[5];   
    float Jet_bmatchEta[5];
    int Jet_bmatchFlav[5];
    int nBkgjets = 0;
    float Jet_PNetBkg[5];   
    float Jet_DeepJetBkg[5];
    float Jet_nobmatchPt[5];    
    float Jet_nobmatchEta[5];
    int Jet_nobmatchFlav[5];
    int nBkgFatjets = 0;
    float FatJet_PNetBkg[3];
    float FatJet_DDBBkg[3];
    float FatJet_nobmatchPt[3];
    float FatJet_nobmatchEta[3];
    float FatJet_nobmatchM[3];
   // Add GenJet
    float genJetEta[500];
    float genJetPhi[500];
    float genJetMass[500];
    float genJetPt[500];
    int genJetPartonFlavor[500];
    // Add GenFatJet
    float genJetAK8Eta[100];
    float genJetAK8Phi[100];
    float genJetAK8Mass[100];
    float genJetAK8Pt[100];
    int genJetAK8PartonFlavor[100]; 
    // Add Jet and FatJet
    float JetEta[500];
    float JetPhi[500];
    float JetPt[500];
    int JetFlavour[500];    
    float FatJetEta[100];
    float FatJetPhi[100];
    float FatJetPt[100];
    float FatJetPNet[100];
    float FatJetMass[100];
    int FatJetBHadrons[100];
    float FatJetM_nosoftdrop[100];
    float FatJetPNetMasscorr[100];

    // some float
    float Margin = 1.0;
    float margin1 = 0.4;
    float margin2 = 0.4;  
    int FatJetMatch_idx = -1;
   // int GenFatJetClose1_idx = -1;
   // int GenFatJetClose2_idx = -1;
    int Number_FatJetMatch = 0;
    int last1Idx = -1;
    int last2Idx = -1;
    int GenBJet1_idx = -1;
    int GenBJet2_idx = -1;
    int GenBJet3_idx = -1;
    int GenBJet4_idx = -1;
//    int GenBJet5_idx = -1;
    int CloseBQuark = 0;
    int Farjet = 1;
    float BquarkR = -99;
    float DeltaR_HH = -99;

    //float TestPt1 = -99;
    //float TestPt2 = -99;
    //float TestDeltaR1 = -99;
    float FatJetDeltaR = -99;
    
    float Diphoton_Mass = -99;
    float Diphoton_Pt = -99;
    float Diphoton_Eta = -99;
    float Diphoton_Phi = -99;

    float GenHmass = -99;
    // Higgs DNA selections
    bool pho1_r9_ScEta=false;
    bool pho2_r9_ScEta=false; 
    // --BDT variables
    float pho1_energyErr = -99;
    float pho1_energyRaw = -99;
    float pho2_energyErr = -99;
    float pho2_energyRaw = -99;
    float Dijetsall_Pt = -99;
    float Dijetsall_Eta = -99;
    float Dijetsall_Phi = -99;
    float M_jjgg = -99;
    float jet1PtRes = -99;
    float jet1PtCorr = -99;
    float jet1PtCorrNeutrino = -99;
    float jet2PtRes = -99;
    float jet2PtCorr = -99;
    float jet2PtCorrNeutrino = -99;
    float rho = -99;
    float minR_jg = -99;
    float otherR_jg = -99;

    float DeltaPhi_j1MET = -99;
    float DeltaPhi_j2MET = -99;
    float leadB_leadLep = -99;
    float leadB_subleadLep = -99;
    float subleadB_leadLep = -99;
    float subleadB_subleadLep = -99;

    float chi_t0sq = -99;
    float chi_t1sq = -99;
    //------------------------
    //set branches on big tree
    //------------------------    
    outputTree->Branch("weight", &weight, "weight/F");
    outputTree->Branch("genMTT", &genMTT, "genMTT/F");

    if (Option != 100) {
      outputTree->Branch("triggerEffWeight", &triggerEffWeight, "triggerEffWeight/F");
      outputTree->Branch("triggerEff3DWeight", &triggerEff3DWeight, "triggerEff3DWeight/F");
      outputTree->Branch("triggerEffMCWeight", &triggerEffMCWeight, "triggerEffMCWeight/F");
      outputTree->Branch("triggerEffMC3DWeight", &triggerEffMC3DWeight, "triggerEffMC3DWeight/F");

      float triggerEff3DWeight = 0;
      float triggerEffMCWeight = 0;
      float triggerEffMC3DWeight = 0;
      
      outputTree->Branch("pileupWeight", &pileupWeight, "pileupWeight/F");
      outputTree->Branch("pileupWeightUp", &pileupWeightUp, "pileupWeightUp/F");
      outputTree->Branch("pileupWeightDown", &pileupWeightDown, "pileupWeightDown/F");
      outputTree->Branch("totalWeight", &totalWeight, "totalWeight/F");
      outputTree->Branch("run", &run, "run/i");
      outputTree->Branch("lumi", &luminosityBlock, "lumi/i");
      outputTree->Branch("event", &event, "event/l");
      outputTree->Branch("npu", &Pileup_nTrueInt, "npu/F");
      outputTree->Branch("rho", &fixedGridRhoFastjetAll, "rho/F");

      outputTree->Branch("NJets", &NJets, "NJets/I");
      outputTree->Branch("METPt", &METPt, "METPt/F");
      outputTree->Branch("METPhi", &METPhi, "METPhi/F");
      outputTree->Branch("METsumEt", &METsumEt, "METsumEt/F");
      outputTree->Branch("METEta", &METEta, "METEta/F");
      // test FatJet_PNet  
      outputTree->Branch("fatJet1Pt", &fatJet1Pt, "fatJet1Pt/F");
      outputTree->Branch("fatJet1Pt_JES_Up", &fatJet1Pt_JES_Up, "fatJet1Pt_JES_Up/F");
      outputTree->Branch("fatJet1Pt_JES_Down", &fatJet1Pt_JES_Down, "fatJet1Pt_JES_Down/F");
      outputTree->Branch("fatJet1Eta", &fatJet1Eta, "fatJet1Eta/F");
      outputTree->Branch("fatJet1Phi", &fatJet1Phi, "fatJet1Phi/F");
      outputTree->Branch("fatJet1Mass", &fatJet1Mass, "fatJet1Mass/F");
      outputTree->Branch("fatJet1MassSD", &fatJet1MassSD, "fatJet1MassSD/F");
      outputTree->Branch("fatJet1MassSD_UnCorrected", &fatJet1MassSD_UnCorrected, "fatJet1MassSD_UnCorrected/F");
      outputTree->Branch("fatJet1MassSD_JMS_Up", &fatJet1MassSD_JMS_Up, "fatJet1MassSD_JMS_Up/F");
      outputTree->Branch("fatJet1MassSD_JMS_Down", &fatJet1MassSD_JMS_Down, "fatJet1MassSD_JMS_Down/F");
      outputTree->Branch("fatJet1MassSD_JMR_Up", &fatJet1MassSD_JMR_Up, "fatJet1MassSD_JMR_Up/F");
      outputTree->Branch("fatJet1MassSD_JMR_Down", &fatJet1MassSD_JMR_Down, "fatJet1MassSD_JMR_Down/F");
      outputTree->Branch("fatJet1DDBTagger", &fatJet1DDBTagger, "fatJet1DDBTagger/F");
      outputTree->Branch("fatJet1PNetXbb", &fatJet1PNetXbb, "fatJet1PNetXbb/F");
      outputTree->Branch("fatJet1PNetXcc", &fatJet1PNetXcc, "fatJet1PNetXcc/F");
      outputTree->Branch("fatJet1PNetXqq", &fatJet1PNetXqq, "fatJet1PNetXqq/F");
      outputTree->Branch("fatJet1PNetQCD", &fatJet1PNetQCD, "fatJet1PNetQCD/F");
      outputTree->Branch("fatJet1GenMatchIndex", &fatJet1GenMatchIndex, "fatJet1GenMatchIndex/I");
      outputTree->Branch("fatJet1Tau3OverTau2", &fatJet1Tau3OverTau2, "fatJet1Tau3OverTau2/F");
      outputTree->Branch("fatJet1_n2b1", &fatJet1_n2b1, "fatJet1_n2b1/F");
      outputTree->Branch("fatJet1HasMuon", &fatJet1HasMuon, "fatJet1HasMuon/O");
      outputTree->Branch("fatJet1HasElectron", &fatJet1HasElectron, "fatJet1HasElectron/O");
      outputTree->Branch("fatJet1HasBJetCSVLoose", &fatJet1HasBJetCSVLoose, "fatJet1HasBJetCSVLoose/O");
      outputTree->Branch("fatJet1HasBJetCSVMedium", &fatJet1HasBJetCSVMedium, "fatJet1HasBJetCSVMedium/O");
      outputTree->Branch("fatJet1HasBJetCSVTight", &fatJet1HasBJetCSVTight, "fatJet1HasBJetCSVTight/O");
      outputTree->Branch("fatJet1OppositeHemisphereHasBJet", &fatJet1OppositeHemisphereHasBJet, "fatJet1OppositeHemisphereHasBJet/O");
 
      //for phase-space overlap removal with VBFHH->4b boosted analysis
      //small R VBF jets
      outputTree->Branch("isVBFtag", &isVBFtag, "isVBFtag/I");
      outputTree->Branch("dijetmass", &dijetmass, "dijetmass/F");
      outputTree->Branch("vbfjet1Pt", &vbfjet1Pt, "vbfjet1Pt/F");
      outputTree->Branch("vbfjet1Eta", &vbfjet1Eta, "vbfjet1Eta/F");
      outputTree->Branch("vbfjet1Phi", &vbfjet1Phi, "vbfjet1Phi/F");
      outputTree->Branch("vbfjet1Mass", &vbfjet1Mass, "vbfjet1Mass/F");
      outputTree->Branch("vbfjet2Pt", &vbfjet2Pt, "vbfjet2Pt/F");
      outputTree->Branch("vbfjet2Eta", &vbfjet2Eta, "vbfjet2Eta/F");
      outputTree->Branch("vbfjet2Phi", &vbfjet2Phi, "vbfjet2Phi/F");
      outputTree->Branch("vbfjet2Mass", &vbfjet2Mass, "vbfjet2Mass/F");
      //leading and subleading AK8jets
      outputTree->Branch("vbffatJet1PNetXbb", &vbffatJet1PNetXbb, "vbffatJet1PNetXbb/F");
      outputTree->Branch("vbffatJet1Pt", &vbffatJet1Pt, "vbffatJet1Pt/F");
      outputTree->Branch("vbffatJet1Eta", &vbffatJet1Eta, "vbffatJet1Eta/F");
      outputTree->Branch("vbffatJet1Phi", &vbffatJet1Phi, "vbffatJet1Phi/F");
      outputTree->Branch("vbffatJet2PNetXbb", &vbffatJet2PNetXbb, "vbffatJet2PNetXbb/F");
      outputTree->Branch("vbffatJet2Pt", &vbffatJet2Pt, "vbffatJet2Pt/F");
      outputTree->Branch("vbffatJet2Eta", &vbffatJet2Eta, "vbffatJet2Eta/F");
      outputTree->Branch("vbffatJet2Phi", &vbffatJet2Phi, "vbffatJet2Phi/F");
    }

    if ((Option == 0 or Option ==1) && (!isData)) {
      outputTree->Branch("genPhoton1Pt", &genPhoton1Pt, "genPhoton1Pt/F");
      outputTree->Branch("genPhoton1Eta", &genPhoton1Eta, "genPhoton1Eta/F");
      outputTree->Branch("genPhoton1Phi", &genPhoton1Phi, "genPhoton1Phi/F");
      outputTree->Branch("genPhoton2Pt", &genPhoton2Pt, "genPhoton2Pt/F");
      outputTree->Branch("genPhoton2Eta", &genPhoton2Eta, "genPhoton2Eta/F");
      outputTree->Branch("genPhoton2Phi", &genPhoton2Phi, "genPhoton2Phi/F");
    }
      outputTree->Branch("b_jet1Pt", &b_jet1Pt, "b_jet1Pt/F");
      outputTree->Branch("b_jet1Eta", &b_jet1Eta, "b_jet1Eta/F");
      outputTree->Branch("b_jet1Phi", &b_jet1Phi, "b_jet1Phi/F");
      outputTree->Branch("b_jet1PNet", &b_jet1PNet, "b_jet1PNet/F");
      outputTree->Branch("b_jet1Mass", &b_jet1Mass, "b_jet1Mass/F");
      outputTree->Branch("b_jet1PtRes", &b_jet1PtRes, "b_jet1PtRes/F");
      outputTree->Branch("b_jet1PtCorr", &b_jet1PtCorr, "b_jet1PtCorr/F");
      outputTree->Branch("b_jet1PtCorrNeutrino", &b_jet1PtCorrNeutrino, "b_jet1PtCorrNeutrino/F");
      
      outputTree->Branch("b_jet2Pt", &b_jet2Pt, "b_jet2Pt/F");
      outputTree->Branch("b_jet2Eta", &b_jet2Eta, "b_jet2Eta/F");
      outputTree->Branch("b_jet2Phi", &b_jet2Phi, "b_jet2Phi/F");
      outputTree->Branch("b_jet2PNet", &b_jet2PNet, "b_jet2PNet/F");
      outputTree->Branch("b_jet2Mass", &b_jet2Mass, "b_jet2Mass/F");
      outputTree->Branch("b_jet2PtRes", &b_jet2PtRes, "b_jet2PtRes/F");
      outputTree->Branch("b_jet2PtCorr", &b_jet2PtCorr, "b_jet2PtCorr/F");
      outputTree->Branch("b_jet2PtCorrNeutrino", &b_jet2PtCorrNeutrino, "b_jet2PtCorrNeutrino/F");

      outputTree->Branch("jet1Pt", &jet1Pt, "jet1Pt/F");
      outputTree->Branch("jet1Eta", &jet1Eta, "jet1Eta/F");
      outputTree->Branch("jet1Phi", &jet1Phi, "jet1Phi/F");
      outputTree->Branch("jet1PNet", &jet1PNet, "jet1PNet/F");
      outputTree->Branch("jet1Mass", &jet1Mass, "jet1Mass/F");
      outputTree->Branch("jet1DeepFlavB", &jet1DeepFlavB, "jet1DeepFlavB/F");
      outputTree->Branch("jet1Flav", &jet1Flav, "jet1Flav/I");
   //   outputTree->Branch("jet1DeepJetBTag", &jet1DeepJetBTag, "jet1DeepJetBTag/F");      
      outputTree->Branch("jet2Pt", &jet2Pt, "jet2Pt/F");
      outputTree->Branch("jet2Eta", &jet2Eta, "jet2Eta/F");
      outputTree->Branch("jet2Phi", &jet2Phi, "jet2Phi/F");
      outputTree->Branch("jet2PNet", &jet2PNet, "jet2PNet/F");
      outputTree->Branch("jet2Mass", &jet2Mass, "jet2Mass/F");
      outputTree->Branch("jet2DeepFlavB", &jet2DeepFlavB, "jet2DeepFlavB/F");
      outputTree->Branch("jet2Flav", &jet2Flav, "jet2Flav/I");
   //  outputTree->Branch("jet2DeepJetBTag", &jet2DeepJetBTag, "jet2DeepJetBTag/F"); 
      outputTree->Branch("jet1PtRes", &jet1PtRes, "jet1PtRes/F");
      outputTree->Branch("jet1PtCorr", &jet1PtCorr, "jet1PtCorr/F");
      outputTree->Branch("jet1PtCorrNeutrino", &jet1PtCorrNeutrino, " jet1PtCorrNeutrino/F");
      outputTree->Branch("jet2PtRes", &jet2PtRes, "jet2PtRes/F");
      outputTree->Branch("jet2PtCorr", &jet2PtCorr, "jet2PtCorr/F");
      outputTree->Branch("jet2PtCorrNeutrino", &jet2PtCorrNeutrino, " jet2PtCorrNeutrino/F");

      outputTree->Branch("jet3Pt", &jet3Pt, "jet3Pt/F");
      outputTree->Branch("jet3Eta", &jet3Eta, "jet3Eta/F");
      outputTree->Branch("jet3Phi", &jet3Phi, "jet3Phi/F");
      outputTree->Branch("jet3PNet", &jet3PNet, "jet3PNet/F");
      outputTree->Branch("jet3Mass", &jet3Mass, "jet3Mass/F");
      outputTree->Branch("jet3DeepFlavB", &jet3DeepFlavB, "jet3DeepFlavB/F");
      outputTree->Branch("jet3Flav", &jet3Flav, "jet3Flav/I");
   //  outputTree->Branch("jet3DeepJetBTag", &jet3DeepJetBTag, "jet3DeepJetBTag/F");      
      outputTree->Branch("jet4Pt", &jet4Pt, "jet4Pt/F");
      outputTree->Branch("jet4Eta", &jet4Eta, "jet4Eta/F");
      outputTree->Branch("jet4Phi", &jet4Phi, "jet4Phi/F");
      outputTree->Branch("jet4PNet", &jet4PNet, "jet4PNet/F");
      outputTree->Branch("jet4Mass", &jet4Mass, "jet4Mass/F");
      outputTree->Branch("jet4DeepFlavB", &jet4DeepFlavB, "jet4DeepFlavB/F");
      outputTree->Branch("jet4Flav", &jet4Flav, "jet4Flav/I");
   //   outputTree->Branch("jet4DeepJetBTag", &jet4DeepJetBTag, "jet4DeepJetBTag/F");    
      outputTree->Branch("jet5Pt", &jet5Pt, "jet5Pt/F");
      outputTree->Branch("jet5Eta", &jet5Eta, "jet5Eta/F");
      outputTree->Branch("jet5Phi", &jet5Phi, "jet5Phi/F");
      outputTree->Branch("jet5PNet", &jet5PNet, "jet5PNet/F");
      outputTree->Branch("jet5Mass", &jet5Mass, "jet5Mass/F");

      outputTree->Branch("jet6Pt", &jet6Pt, "jet6Pt/F");
      outputTree->Branch("jet6Eta", &jet6Eta, "jet6Eta/F");
      outputTree->Branch("jet6Phi", &jet6Phi, "jet6Phi/F");
      outputTree->Branch("jet6PNet", &jet6PNet, "jet6PNet/F");
      outputTree->Branch("jet6Mass", &jet6Mass, "jet6Mass/F");
   //   outputTree->Branch("jet5DeepFlavB", &jet5DeepFlavB, "jet5DeepFlavB/F");
   //   outputTree->Branch("jet5Flav", &jet5Flav, "jet5Flav/I");
    //  outputTree->Branch("Dijets_Mass", &Dijets_Mass, "Dijets_Mass/F");  
    //  outputTree->Branch("DijetsCan_Mass", &DijetsCan_Mass, "DijetsCan_Mass/F");
      outputTree->Branch("Dijetsall_Mass", &Dijetsall_Mass, "Dijetsall_Mass/F");


    if (Option != 20 && Option != 100 && (!isData)){
      outputTree->Branch("genbQuark1_Pt", &genbQuark1_Pt, "genbQuark1_Pt/F");
      outputTree->Branch("genbQuark1_Eta", &genbQuark1_Eta, "genbQuark1_Eta/F");
      outputTree->Branch("genbQuark1_Phi", &genbQuark1_Phi, "genbQuark1_Phi/F");
      outputTree->Branch("genbQuark2_Pt", &genbQuark2_Pt, "genbQuark2_Pt/F");
      outputTree->Branch("genbQuark2_Eta", &genbQuark2_Eta, "genbQuark2_Eta/F");
      outputTree->Branch("genbQuark2_Phi", &genbQuark2_Phi, "genbQuark2_Phi/F");
      outputTree->Branch("BquarkR", &BquarkR, "BquarkR/F");
      outputTree->Branch("GenBJet1_Pt", &GenBJet1_Pt , "GenBJet1_Pt/F");
      outputTree->Branch("GenBJet1_Eta", &GenBJet1_Eta , "GenBJet1_Eta/F");
      outputTree->Branch("GenBJet1_Phi", &GenBJet1_Phi , "GenBJet1_Phi/F");
      outputTree->Branch("GenBJet2_Pt", &GenBJet2_Pt , "GenBJet2_Pt/F");
      outputTree->Branch("GenBJet2_Eta", &GenBJet2_Eta , "GenBJet2_Eta/F");
      outputTree->Branch("GenBJet2_Phi", &GenBJet2_Phi , "GenBJet2_Phi/F");
      outputTree->Branch("GenBJet3_Pt", &GenBJet3_Pt , "GenBJet3_Pt/F");
      outputTree->Branch("GenBJet3_Eta", &GenBJet3_Eta , "GenBJet3_Eta/F");
      outputTree->Branch("GenBJet3_Phi", &GenBJet3_Phi , "GenBJet3_Phi/F");
      outputTree->Branch("GenBJet4_Pt", &GenBJet4_Pt , "GenBJet4_Pt/F");
      outputTree->Branch("GenBJet4_Eta", &GenBJet4_Eta , "GenBJet4_Eta/F");
      outputTree->Branch("GenBJet4_Phi", &GenBJet4_Phi , "GenBJet4_Phi/F");
      outputTree->Branch("GenBJet1_idx", &GenBJet1_idx , "GenBJet1_idx/I");
      outputTree->Branch("GenBJet2_idx", &GenBJet2_idx , "GenBJet2_idx/I");
      outputTree->Branch("GenBJet3_idx", &GenBJet3_idx , "GenBJet3_idx/I");
      outputTree->Branch("GenBJet4_idx", &GenBJet4_idx , "GenBJet4_idx/I");
      
      outputTree->Branch("tobbHiggs_Pt", &tobbHiggs_Pt, "tobbHiggs_Pt/F");
      outputTree->Branch("tobbHiggs_Eta", &tobbHiggs_Eta, "tobbHiggs_Eta/F");
      outputTree->Branch("tobbHiggs_Phi", &tobbHiggs_Phi, "tobbHiggs_Phi/F");
      outputTree->Branch("tobbHiggs_Mass", &tobbHiggs_Mass, "tobbHiggs_Mass/F");
      outputTree->Branch("toggHiggs_Pt", &toggHiggs_Pt, "toggHiggs_Pt/F"); 
      outputTree->Branch("toggHiggs_Eta", &toggHiggs_Eta, "toggHiggs_Eta/F");    
      outputTree->Branch("toggHiggs_Phi", &toggHiggs_Phi, "toggHiggs_Phi/F");
      outputTree->Branch("toggHiggs_Mass", &toggHiggs_Mass, "toggHiggs_Mass/F");

      outputTree->Branch("FatJetMatch_Pt", &FatJetMatch_Pt, "FatJetMatch_Pt/F");
      outputTree->Branch("FatJetMatch_Eta", &FatJetMatch_Eta, "FatJetMatch_Eta/F");
      outputTree->Branch("FatJetMatch_Phi", &FatJetMatch_Phi, "FatJetMatch_Phi/F");
      outputTree->Branch("FatJetMatch_Mass", &FatJetMatch_Mass, "FatJetMatch_Mass/F");
      outputTree->Branch("FatJetMatch_PNet", &FatJetMatch_PNet, "FatJetMatch_PNet/F");
      outputTree->Branch("FatJetMatch_corrMass", &FatJetMatch_corrMass, "FatJetMatch_corrMass/F");

      outputTree->Branch("FatJetClose1_Pt", &FatJetClose1_Pt, "FatJetClose1_Pt/F");
      outputTree->Branch("FatJetClose1_Eta", &FatJetClose1_Eta, "FatJetClose1_Eta/F");
      outputTree->Branch("FatJetClose1_Phi", &FatJetClose1_Phi, "FatJetClose1_Phi/F");
      outputTree->Branch("FatJetClose1_Mass", &FatJetClose1_Mass, "FatJetClose1_Mass/F");
      //outputTree->Branch("GenFatJetClose1_Flav", &GenFatJetClose1_Flav, "GenFatJetClose1_Flav/F");
      outputTree->Branch("FatJetClose2_Pt", &FatJetClose2_Pt, "FatJetClose2_Pt/F");
      outputTree->Branch("FatJetClose2_Eta", &FatJetClose2_Eta, "FatJetClose2_Eta/F");
      outputTree->Branch("FatJetClose2_Phi", &FatJetClose2_Phi, "FatJetClose2_Phi/F");
      outputTree->Branch("FatJetClose2_Mass", &FatJetClose2_Mass, "FatJetClose2_Mass/F");
      //outputTree->Branch("GenFatJetClose2_Flav", &GenFatJetClose2_Flav, "GenFatJetClose2_Flav/F");
    //  outputTree->Branch("RecoFatJetCan_Pt", &RecoFatJetCan_Pt, "RecoFatJetCan_Pt/F");
    //  outputTree->Branch("RecoFatJetCan_Eta", &RecoFatJetCan_Eta, "RecoFatJetCan_Eta/F");
    //  outputTree->Branch("RecoFatJetCan_Phi", &RecoFatJetCan_Phi, "RecoFatJetCan_Phi/F");
    //  outputTree->Branch("RecoFatJetCan_MS", &RecoFatJetCan_MS, "RecoFatJetCan_MS/F");
   //   outputTree->Branch("RecoFatJetCan_PNet", &RecoFatJetCan_PNet, "RecoFatJetCan_PNet/F");
    //  outputTree->Branch("RecoFatJetCan_DDB", &RecoFatJetCan_DDB, "RecoFatJetCan_DDB/F");
    //  outputTree->Branch("RecoFatJetClose1_Pt", &RecoFatJetClose1_Pt, "RecoFatJetClose1_Pt/F");
    //  outputTree->Branch("RecoFatJetClose1_Eta", &RecoFatJetClose1_Eta, "RecoFatJetClose1_Eta/F");
    //  outputTree->Branch("RecoFatJetClose1_Phi", &RecoFatJetClose1_Phi, "RecoFatJetClose1_Phi/F");
    //  outputTree->Branch("RecoFatJetClose1_MS", &RecoFatJetClose1_MS, "RecoFatJetClose1_MS/F");
    //  outputTree->Branch("RecoFatJetClose1_PNet", &RecoFatJetClose1_PNet, "RecoFatJetClose1_PNet/F");
    //  outputTree->Branch("RecoFatJetClose1_DDB", &RecoFatJetClose1_DDB, "RecoFatJetClose1_DDB/F");
    //  outputTree->Branch("RecoFatJetClose2_Pt", &RecoFatJetClose2_Pt, "RecoFatJetClose2_Pt/F");
    //  outputTree->Branch("RecoFatJetClose2_Eta", &RecoFatJetClose2_Eta, "RecoFatJetClose2_Eta/F");
    //  outputTree->Branch("RecoFatJetClose2_Phi", &RecoFatJetClose2_Phi, "RecoFatJetClose2_Phi/F");
    //  outputTree->Branch("RecoFatJetClose2_MS", &RecoFatJetClose2_MS, "RecoFatJetClose2_MS/F");
    //  outputTree->Branch("RecoFatJetClose2_PNet", &RecoFatJetClose2_PNet, "RecoFatJetClose2_PNet/F");
    //  outputTree->Branch("RecoFatJetClose2_DDB", &RecoFatJetClose2_DDB, "RecoFatJetClose2_DDB/F");
      outputTree->Branch("genHiggs1Pt", &genHiggs1Pt, "genHiggs1Pt/F");
      outputTree->Branch("genHiggs1Eta", &genHiggs1Eta, "genHiggs1Eta/F");
      outputTree->Branch("genHiggs1Phi", &genHiggs1Phi, "genHiggs1Phi/F");
      outputTree->Branch("genHiggs2Pt", &genHiggs2Pt, "genHiggs2Pt/F");
      outputTree->Branch("genHiggs2Eta", &genHiggs2Eta, "genHiggs2Eta/F");
      outputTree->Branch("genHiggs2Phi", &genHiggs2Phi, "genHiggs2Phi/F");
      outputTree->Branch("genHH_pt",      &genHH_pt,     "genHH_pt/F");
      outputTree->Branch("genHH_eta",     &genHH_eta,    "genHH_eta/F");
      outputTree->Branch("genHH_phi",     &genHH_phi,    "genHH_phi/F");
      outputTree->Branch("genHH_mass",    &genHH_mass,   "genHH_mass/F");
      outputTree->Branch("genLeptonId", &genLeptonId, "genLeptonId/I");
      outputTree->Branch("genLeptonMotherId", &genLeptonMotherId, "genLeptonMotherId/I");
      outputTree->Branch("genLeptonPt", &genLeptonPt, "genLeptonPt/F");
      outputTree->Branch("genLeptonEta", &genLeptonEta, "genLeptonEta/F");
      outputTree->Branch("genLeptonPhi", &genLeptonPhi, "genLeptonPhi/F");
      }
      outputTree->Branch("fatJet2Pt", &fatJet2Pt, "fatJet2Pt/F");
      outputTree->Branch("fatJet2Pt_JES_Up", &fatJet2Pt_JES_Up, "fatJet2Pt_JES_Up/F");
      outputTree->Branch("fatJet2Pt_JES_Down", &fatJet2Pt_JES_Down, "fatJet2Pt_JES_Down/F");
      outputTree->Branch("fatJet2Eta", &fatJet2Eta, "fatJet2Eta/F");
      outputTree->Branch("fatJet2Phi", &fatJet2Phi, "fatJet2Phi/F");
      outputTree->Branch("fatJet2Mass", &fatJet2Mass, "fatJet2Mass/F");
      outputTree->Branch("fatJet2MassSD", &fatJet2MassSD, "fatJet2MassSD/F");
      outputTree->Branch("fatJet2MassSD_UnCorrected", &fatJet2MassSD_UnCorrected, "fatJet2MassSD_UnCorrected/F");
      outputTree->Branch("fatJet2MassSD_JMS_Up", &fatJet2MassSD_JMS_Up, "fatJet2MassSD_JMS_Up/F");
      outputTree->Branch("fatJet2MassSD_JMS_Down", &fatJet2MassSD_JMS_Down, "fatJet2MassSD_JMS_Down/F");
      outputTree->Branch("fatJet2MassSD_JMR_Up", &fatJet2MassSD_JMR_Up, "fatJet2MassSD_JMR_Up/F");
      outputTree->Branch("fatJet2MassSD_JMR_Down", &fatJet2MassSD_JMR_Down, "fatJet2MassSD_JMR_Down/F");
      outputTree->Branch("fatJet2DDBTagger", &fatJet2DDBTagger, "fatJet2DDBTagger/F");
      outputTree->Branch("fatJet2PNetXbb", &fatJet2PNetXbb, "fatJet2PNetXbb/F");
      outputTree->Branch("fatJet2PNetXcc", &fatJet2PNetXcc, "fatJet2PNetXcc/F");
      outputTree->Branch("fatJet2PNetXqq", &fatJet2PNetXqq, "fatJet2PNetXqq/F");
      outputTree->Branch("fatJet2PNetQCD", &fatJet2PNetQCD, "fatJet2PNetQCD/F");
      outputTree->Branch("fatJet2GenMatchIndex", &fatJet2GenMatchIndex, "fatJet2GenMatchIndex/I");
      outputTree->Branch("fatJet2Tau3OverTau2", &fatJet2Tau3OverTau2, "fatJet2Tau3OverTau2/F");
      outputTree->Branch("fatJet2HasMuon", &fatJet2HasMuon, "fatJet2HasMuon/O");
      outputTree->Branch("fatJet2HasElectron", &fatJet2HasElectron, "fatJet2HasElectron/O");
      outputTree->Branch("fatJet2HasBJetCSVLoose", &fatJet2HasBJetCSVLoose, "fatJet2HasBJetCSVLoose/O");
      outputTree->Branch("fatJet2HasBJetCSVMedium", &fatJet2HasBJetCSVMedium, "fatJet2HasBJetCSVMedium/O");
      outputTree->Branch("fatJet2HasBJetCSVTight", &fatJet2HasBJetCSVTight, "fatJet2HasBJetCSVTight/O");
      outputTree->Branch("fatJet3Pt", &fatJet3Pt, "fatJet3Pt/F");
      // outputTree->Branch("fatJet3Pt_JES_Up", &fatJet3Pt_JES_Up, "fatJet3Pt_JES_Up/F");
      // outputTree->Branch("fatJet3Pt_JES_Down", &fatJet3Pt_JES_Down, "fatJet3Pt_JES_Down/F");
      outputTree->Branch("fatJet3Eta", &fatJet3Eta, "fatJet3Eta/F");
      outputTree->Branch("fatJet3Phi", &fatJet3Phi, "fatJet3Phi/F");
      outputTree->Branch("fatJet3Mass", &fatJet3Mass, "fatJet3Mass/F");
      outputTree->Branch("fatJet3MassSD", &fatJet3MassSD, "fatJet3MassSD/F");
      // outputTree->Branch("fatJet3MassSD_UnCorrected", &fatJet3MassSD_UnCorrected, "fatJet3MassSD_UnCorrected/F");
      // outputTree->Branch("fatJet3MassSD_JMS_Up", &fatJet3MassSD_JMS_Up, "fatJet3MassSD_JMS_Up/F");
      // outputTree->Branch("fatJet3MassSD_JMS_Down", &fatJet3MassSD_JMS_Down, "fatJet3MassSD_JMS_Down/F");
      // outputTree->Branch("fatJet3MassSD_JMR_Up", &fatJet3MassSD_JMR_Up, "fatJet3MassSD_JMR_Up/F");
      // outputTree->Branch("fatJet3MassSD_JMR_Down", &fatJet3MassSD_JMR_Down, "fatJet3MassSD_JMR_Down/F");
      outputTree->Branch("fatJet3DDBTagger", &fatJet3DDBTagger, "fatJet3DDBTagger/F");
      outputTree->Branch("fatJet3PNetXbb", &fatJet3PNetXbb, "fatJet3PNetXbb/F");
      outputTree->Branch("fatJet3PNetXcc", &fatJet3PNetXcc, "fatJet3PNetXcc/F");
      outputTree->Branch("fatJet3PNetXqq", &fatJet3PNetXqq, "fatJet3PNetXqq/F");
      outputTree->Branch("fatJet3PNetQCD", &fatJet3PNetQCD, "fatJet3PNetQCD/F");
      outputTree->Branch("fatJet3Tau3OverTau2", &fatJet3Tau3OverTau2, "fatJet3Tau3OverTau2/F");
      outputTree->Branch("fatJet3HasMuon", &fatJet3HasMuon, "fatJet3HasMuon/O");
      outputTree->Branch("fatJet3HasElectron", &fatJet3HasElectron, "fatJet3HasElectron/O");
      outputTree->Branch("fatJet3HasBJetCSVLoose", &fatJet3HasBJetCSVLoose, "fatJet3HasBJetCSVLoose/O");
      outputTree->Branch("fatJet3HasBJetCSVMedium", &fatJet3HasBJetCSVMedium, "fatJet3HasBJetCSVMedium/O");
      outputTree->Branch("fatJet3HasBJetCSVTight", &fatJet3HasBJetCSVTight, "fatJet3HasBJetCSVTight/O");
      outputTree->Branch("hh_pt",      &hh_pt,     "hh_pt/F");
      outputTree->Branch("hh_eta",     &hh_eta,    "hh_eta/F");
      outputTree->Branch("hh_phi",     &hh_phi,    "hh_phi/F");
      outputTree->Branch("hh_mass",    &hh_mass,   "hh_mass/F");
      outputTree->Branch("hh_pt_JESUp",      &hh_pt_JESUp,     "hh_pt_JESUp/F");
      outputTree->Branch("hh_pt_JESDown",    &hh_pt_JESDown,   "hh_pt_JESDown/F");
      outputTree->Branch("hh_pt_JMSUp",      &hh_pt_JMSUp,     "hh_pt_JMSUp/F");
      outputTree->Branch("hh_pt_JMSDown",    &hh_pt_JMSDown,   "hh_pt_JMSDown/F");
      outputTree->Branch("hh_pt_JMRUp",      &hh_pt_JMRUp,     "hh_pt_JMRUp/F");
      outputTree->Branch("hh_pt_JMRDown",    &hh_pt_JMRDown,   "hh_pt_JMRDown/F");
      outputTree->Branch("hh_eta_JESUp",      &hh_eta_JESUp,     "hh_eta_JESUp/F");
      outputTree->Branch("hh_eta_JESDown",    &hh_eta_JESDown,   "hh_eta_JESDown/F");
      outputTree->Branch("hh_eta_JMSUp",      &hh_eta_JMSUp,     "hh_eta_JMSUp/F");
      outputTree->Branch("hh_eta_JMSDown",    &hh_eta_JMSDown,   "hh_eta_JMSDown/F");
      outputTree->Branch("hh_eta_JMRUp",      &hh_eta_JMRUp,     "hh_eta_JMRUp/F");
      outputTree->Branch("hh_eta_JMRDown",    &hh_eta_JMRDown,   "hh_eta_JMRDown/F");
      outputTree->Branch("hh_mass_JESUp",      &hh_mass_JESUp,     "hh_mass_JESUp/F");
      outputTree->Branch("hh_mass_JESDown",    &hh_mass_JESDown,   "hh_mass_JESDown/F");
      outputTree->Branch("hh_mass_JMSUp",      &hh_mass_JMSUp,     "hh_mass_JMSUp/F");
      outputTree->Branch("hh_mass_JMSDown",    &hh_mass_JMSDown,   "hh_mass_JMSDown/F");
      outputTree->Branch("hh_mass_JMRUp",      &hh_mass_JMRUp,     "hh_mass_JMRUp/F");
      outputTree->Branch("hh_mass_JMRDown",    &hh_mass_JMRDown,   "hh_mass_JMRDown/F");
      outputTree->Branch("fatJet1PtOverMHH",    &fatJet1PtOverMHH,   "fatJet1PtOverMHH/F");
      outputTree->Branch("fatJet1PtOverMHH_JESUp",    &fatJet1PtOverMHH_JESUp,   "fatJet1PtOverMHH_JESUp/F");
      outputTree->Branch("fatJet1PtOverMHH_JESDown",  &fatJet1PtOverMHH_JESDown, "fatJet1PtOverMHH_JESDown/F");
      outputTree->Branch("fatJet1PtOverMHH_JMSUp",    &fatJet1PtOverMHH_JMSUp,   "fatJet1PtOverMHH_JMSUp/F");
      outputTree->Branch("fatJet1PtOverMHH_JMSDown",  &fatJet1PtOverMHH_JMSDown, "fatJet1PtOverMHH_JMSDown/F");
      outputTree->Branch("fatJet1PtOverMHH_JMRUp",    &fatJet1PtOverMHH_JMRUp,   "fatJet1PtOverMHH_JMRUp/F");
      outputTree->Branch("fatJet1PtOverMHH_JMRDown",  &fatJet1PtOverMHH_JMRDown, "fatJet1PtOverMHH_JMRDown/F");
      outputTree->Branch("fatJet1PtOverMSD",    &fatJet1PtOverMSD,   "fatJet1PtOverMSD/F");
      outputTree->Branch("fatJet2PtOverMHH",    &fatJet2PtOverMHH,   "fatJet2PtOverMHH/F");
      outputTree->Branch("fatJet2PtOverMHH_JESUp",    &fatJet2PtOverMHH_JESUp,   "fatJet2PtOverMHH_JESUp/F");
      outputTree->Branch("fatJet2PtOverMHH_JESDown",  &fatJet2PtOverMHH_JESDown, "fatJet2PtOverMHH_JESDown/F");
      outputTree->Branch("fatJet2PtOverMHH_JMSUp",    &fatJet2PtOverMHH_JMSUp,   "fatJet2PtOverMHH_JMSUp/F");
      outputTree->Branch("fatJet2PtOverMHH_JMSDown",  &fatJet2PtOverMHH_JMSDown, "fatJet2PtOverMHH_JMSDown/F");
      outputTree->Branch("fatJet2PtOverMHH_JMRUp",    &fatJet2PtOverMHH_JMRUp,   "fatJet2PtOverMHH_JMRUp/F");
      outputTree->Branch("fatJet2PtOverMHH_JMRDown",  &fatJet2PtOverMHH_JMRDown, "fatJet2PtOverMHH_JMRDown/F");
      outputTree->Branch("fatJet2PtOverMSD",    &fatJet2PtOverMSD,   "fatJet2PtOverMSD/F");
      outputTree->Branch("deltaEta_j1j2",    &deltaEta_j1j2,   "deltaEta_j1j2/F");
      outputTree->Branch("deltaPhi_j1j2",    &deltaPhi_j1j2,   "deltaPhi_j1j2/F");
      outputTree->Branch("deltaR_j1j2",    &deltaR_j1j2,   "deltaR_j1j2/F");
      outputTree->Branch("ptj2_over_ptj1",    &ptj2_over_ptj1,   "ptj2_over_ptj1/F");
      outputTree->Branch("mj2_over_mj1",    &mj2_over_mj1,   "mj2_over_mj1/F");
      outputTree->Branch("lep1Pt", &lep1Pt, "lep1Pt/F");
      outputTree->Branch("lep1Eta", &lep1Eta, "lep1Eta/F");
      outputTree->Branch("lep1Phi", &lep1Phi, "lep1Phi/F");
      outputTree->Branch("lep1Id", &lep1Id, "lep1Id/I");
      outputTree->Branch("lep2Pt", &lep2Pt, "lep2Pt/F");
      outputTree->Branch("lep2Eta", &lep2Eta, "lep2Eta/F");
      outputTree->Branch("lep2Phi", &lep2Phi, "lep2Phi/F");
      outputTree->Branch("lep2Id", &lep2Id, "lep2Id/I");
      outputTree->Branch("lep1mva", &lep1mva, "lep1mva/F");
      outputTree->Branch("lep2mva", &lep2mva, "lep2mva/F");

      outputTree->Branch("Muon_1Pt", &Muon_1Pt, "Muon_1Pt/F");
      outputTree->Branch("Muon_1Eta", &Muon_1Eta, "Muon_1Eta/F");
      outputTree->Branch("Muon_1Phi", &Muon_1Phi, "Muon_1Phi/F");
      outputTree->Branch("Muon_1Id", &Muon_1Id, "Muon_1Id/I");
      outputTree->Branch("Muon_2Pt", &Muon_2Pt, "Muon_2Pt/F");
      outputTree->Branch("Muon_2Eta", &Muon_2Eta, "Muon_2Eta/F");
      outputTree->Branch("Muon_2Phi", &Muon_2Phi, "Muon_2Phi/F");
      outputTree->Branch("Muon_2Id", &Muon_2Id, "Muon_2Id/I");
      outputTree->Branch("Muon_1mva", &Muon_1mva, "Muon_1mva/F");
      outputTree->Branch("Muon_2mva", &Muon_2mva, "Muon_2mva/F");

      outputTree->Branch("Ele_1Pt", &Ele_1Pt, "Ele_1Pt/F");
      outputTree->Branch("Ele_1Eta", &Ele_1Eta, "Ele_1Eta/F");
      outputTree->Branch("Ele_1Phi", &Ele_1Phi, "Ele_1Phi/F");
      outputTree->Branch("Ele_1Id", &Ele_1Id, "Ele_1Id/I");
      outputTree->Branch("Ele_2Pt", &Ele_2Pt, "Ele_2Pt/F");
      outputTree->Branch("Ele_2Eta", &Ele_2Eta, "Ele_2Eta/F");
      outputTree->Branch("Ele_2Phi", &Ele_2Phi, "Ele_2Phi/F");
      outputTree->Branch("Ele_2Id", &Ele_2Id, "Ele_2Id/I");
      outputTree->Branch("Ele_1mva", &Ele_1mva, "Ele_1mva/F");
      outputTree->Branch("Ele_2mva", &Ele_2mva, "Ele_2mva/F");
      //outputTree->Branch("nBTaggedJets", &nBTaggedJets, "nBTaggedJets/I");      
     

   // if (Option == 0 || Option == 20 || Option == 21) {
   //   outputTree->Branch("genWPt", &genWPt, "genWPt/F");
   //   outputTree->Branch("genWEta", &genWEta, "genWEta/F");
   //   outputTree->Branch("genWPhi", &genWPhi, "genWPhi/F");
   //   outputTree->Branch("genZPt", &genZPt, "genZPt/F");
   //   outputTree->Branch("genZEta", &genZEta, "genZEta/F");
   //   outputTree->Branch("genZPhi", &genZPhi, "genZPhi/F");
  // }

    if (Option == 0 || Option == 20 || Option == 21 || Option == 1) {
      outputTree->Branch("pho1Pt", &pho1Pt, "pho1Pt/F");
      outputTree->Branch("pho1Eta", &pho1Eta, "pho1Eta/F");
      outputTree->Branch("pho1Phi", &pho1Phi, "pho1Phi/F");
      outputTree->Branch("pho2Pt", &pho2Pt, "pho2Pt/F");
      outputTree->Branch("pho2Eta", &pho2Eta, "pho2Eta/F");
      outputTree->Branch("pho2Phi", &pho2Phi, "pho2Phi/F");
      outputTree->Branch("Diphoton_Mass",&Diphoton_Mass,"Diphoton_Mass/F");  
      outputTree->Branch("pho1r9", &pho1r9, "pho1r9/O");
      outputTree->Branch("pho1_ChIOvEt",&pho1_ChIOvEt, "pho1_ChIOvEt/O" );
      outputTree->Branch("pho1_ChI", &pho1_ChI, "pho1_ChI/O");
      outputTree->Branch("pho1_hoe", &pho1_hoe, "pho1_hoe/F");
      outputTree->Branch("pho1_mvaID", &pho1_mvaID, "pho1_mvaID/F");
      outputTree->Branch("pho1_electronVeto", &pho1_electronVeto, "pho1_electronVeto/O");
      outputTree->Branch("pho2r9", &pho2r9, "pho2r9/O");
      outputTree->Branch("pho2_ChIOvEt",&pho2_ChIOvEt, "pho2_ChIOvEt/O" );
      outputTree->Branch("pho2_ChI", &pho2_ChI, "pho2_ChI/O");
      outputTree->Branch("pho2_hoe", &pho2_hoe, "pho2_hoe/F");
      outputTree->Branch("pho2_mvaID", &pho2_mvaID, "pho2_mvaID/F");
      outputTree->Branch("pho2_electronVeto", &pho2_electronVeto, "pho2_electronVeto/O");
      outputTree->Branch("pho1_seediPhiOriY", &pho1_seediPhiOriY, "pho1_seediPhiOriY/I");
      outputTree->Branch("pho1_seediEtaOriX", &pho1_seediEtaOriX, "pho1_seediEtaOriX/I");
      outputTree->Branch("pho2_seediPhiOriY", &pho2_seediPhiOriY, "pho2_seediPhiOriY/I");
      outputTree->Branch("pho2_seediEtaOriX", &pho2_seediEtaOriX, "pho2_seediEtaOriX/I");
      outputTree->Branch("pho1_r9_ScEta", &pho1_r9_ScEta, "pho1_r9_ScEta/O");
      outputTree->Branch("pho2_r9_ScEta", &pho2_r9_ScEta, "pho2_r9_ScEta/O");
      outputTree->Branch("pho1R9", &pho1R9, "pho1R9/F");
      outputTree->Branch("pho2R9", &pho2R9, "pho2R9/F");
      outputTree->Branch("pho1ChIso", &pho1ChIso, "pho1ChIso/F");
      outputTree->Branch("pho2ChIso", &pho2ChIso, "pho2ChIso/F");
      outputTree->Branch("pho1QCD_realMatched", &pho1QCD_realMatched, "pho1QCD_realMatched/I");
      outputTree->Branch("pho2QCD_realMatched", &pho2QCD_realMatched, "pho2QCD_realMatched/I");
      outputTree->Branch("Matched_genpho1Pt", &Matched_genpho1Pt, "Matched_genpho1Pt/F");
      outputTree->Branch("Matched_genpho2Pt", &Matched_genpho2Pt, "Matched_genpho2Pt/F");
      outputTree->Branch("pho1genId", &pho1genId, "pho1genId/I"); 
      outputTree->Branch("pho2genId", &pho2genId, "pho2genId/I");
      outputTree->Branch("pho1_pfRelIso03_all_quadratic", &pho1_pfRelIso03_all_quadratic, "pho1_pfRelIso03_all_quadratic/F");
      outputTree->Branch("pho2_pfRelIso03_all_quadratic", &pho2_pfRelIso03_all_quadratic, "pho2_pfRelIso03_all_quadratic/F");


    }
    if (Option == 0 || Option == 1){ // BDT variables + ttHKiller Variables
      outputTree->Branch("pho1_energyErr", &pho1_energyErr, "pho1_energyErr/F");
      outputTree->Branch("pho1_energyRaw", &pho1_energyRaw, "pho1_energyRaw/F");
      outputTree->Branch("pho2_energyErr", &pho2_energyErr, "pho2_energyErr/F");
      outputTree->Branch("pho2_energyRaw", &pho2_energyRaw, "pho2_energyRaw/F");
      outputTree->Branch("Diphoton_Pt", &Diphoton_Pt, "Diphoton_Pt/F");
      outputTree->Branch("Diphoton_Eta", &Diphoton_Eta, "Diphoton_Eta/F");
      outputTree->Branch("Diphoton_Phi", &Diphoton_Phi, "Diphoton_Phi/F");
      outputTree->Branch("Dijetsall_Pt", &Dijetsall_Pt, "Dijetsall_Pt/F");
      outputTree->Branch("Dijetsall_Eta", &Dijetsall_Eta, "Dijetsall_Eta/F");
      outputTree->Branch("Dijetsall_Phi", &Dijetsall_Phi, "Dijetsall_Phi/F");
      outputTree->Branch("M_jjgg", &M_jjgg, "M_jjgg/F");
      outputTree->Branch("rho", &rho, "rho/F");
      outputTree->Branch("minR_jg", &minR_jg, "minR_jg/F");
      outputTree->Branch("otherR_jg", &otherR_jg, "otherR_jg/F");
      // ttH
      outputTree->Branch("DeltaPhi_j1MET", &DeltaPhi_j1MET, "DeltaPhi_j1MET/F");
      outputTree->Branch("DeltaPhi_j2MET", &DeltaPhi_j2MET, "DeltaPhi_j2MET/F");
      
      outputTree->Branch("leadB_leadLep", &leadB_leadLep, "leadB_leadLep/F");
      outputTree->Branch("leadB_subleadLep", &leadB_subleadLep, "leadB_subleadLep/F");
      outputTree->Branch("subleadB_leadLep", &subleadB_leadLep, "subleadB_leadLep/F");
      outputTree->Branch("subleadB_subleadLep", &subleadB_subleadLep, "subleadB_subleadLep/F");

      outputTree->Branch("chi_t0sq", &chi_t0sq, "chi_t0sq/F");
      outputTree->Branch("chi_t1sq", &chi_t1sq, "chi_t1sq/F");

      }
      

    if (Option != 100) {
      //outputTree->Branch("HLT_Ele27_WPTight_Gsf", &HLT_Ele27_WPTight_Gsf, "HLT_Ele27_WPTight_Gsf/O");
      //outputTree->Branch("HLT_Ele28_WPTight_Gsf", &HLT_Ele28_WPTight_Gsf, "HLT_Ele28_WPTight_Gsf/O");
      //outputTree->Branch("HLT_Ele30_WPTight_Gsf", &HLT_Ele30_WPTight_Gsf, "HLT_Ele30_WPTight_Gsf/O");
      //outputTree->Branch("HLT_Ele32_WPTight_Gsf", &HLT_Ele32_WPTight_Gsf, "HLT_Ele32_WPTight_Gsf/O");
      //outputTree->Branch("HLT_Ele35_WPTight_Gsf", &HLT_Ele35_WPTight_Gsf, "HLT_Ele35_WPTight_Gsf/O");
      //outputTree->Branch("HLT_Ele38_WPTight_Gsf", &HLT_Ele38_WPTight_Gsf, "HLT_Ele38_WPTight_Gsf/O");
      //outputTree->Branch("HLT_Ele40_WPTight_Gsf", &HLT_Ele40_WPTight_Gsf, "HLT_Ele40_WPTight_Gsf/O");
      //outputTree->Branch("HLT_IsoMu20", &HLT_IsoMu20, "HLT_IsoMu20/O");
      //outputTree->Branch("HLT_IsoMu24", &HLT_IsoMu24, "HLT_IsoMu24/O");
      //outputTree->Branch("HLT_IsoMu24_eta2p1", &HLT_IsoMu24_eta2p1, "HLT_IsoMu24_eta2p1/O");
      //outputTree->Branch("HLT_IsoMu27", &HLT_IsoMu27, "HLT_IsoMu27/O");
      //outputTree->Branch("HLT_IsoMu30", &HLT_IsoMu30, "HLT_IsoMu30/O");
      //outputTree->Branch("HLT_Mu50", &HLT_Mu50, "HLT_Mu50/O");
      //outputTree->Branch("HLT_Mu55", &HLT_Mu55, "HLT_Mu55/O");
      //outputTree->Branch("HLT_Photon175",                                      &HLT_Photon175,                         "HLT_Photon175/O");
      //outputTree->Branch("HLT_PFHT780",                                        &HLT_PFHT780,                                       "HLT_PFHT780/O");
      //outputTree->Branch("HLT_PFHT890",                                        &HLT_PFHT890,                                       "HLT_PFHT890/O");
      //outputTree->Branch("HLT_PFHT1050",                                        &HLT_PFHT1050,                                       "HLT_PFHT1050/O");
      //outputTree->Branch("HLT_AK8PFJet360_TrimMass30",                          &HLT_AK8PFJet360_TrimMass30,                         "HLT_AK8PFJet360_TrimMass30/O");
      //outputTree->Branch("HLT_AK8PFJet380_TrimMass30",                          &HLT_AK8PFJet380_TrimMass30,                         "HLT_AK8PFJet380_TrimMass30/O");
      //outputTree->Branch("HLT_AK8PFJet400_TrimMass30",                          &HLT_AK8PFJet400_TrimMass30,                         "HLT_AK8PFJet400_TrimMass30/O");
      //outputTree->Branch("HLT_AK8PFJet420_TrimMass30",                          &HLT_AK8PFJet420_TrimMass30,                         "HLT_AK8PFJet420_TrimMass30/O");
      //outputTree->Branch("HLT_AK8PFHT750_TrimMass50",                           &HLT_AK8PFHT750_TrimMass50,                          "HLT_AK8PFHT750_TrimMass50/O");
      //outputTree->Branch("HLT_AK8PFHT800_TrimMass50",                           &HLT_AK8PFHT800_TrimMass50,                          "HLT_AK8PFHT800_TrimMass50/O");
      //outputTree->Branch("HLT_AK8PFHT850_TrimMass50",                           &HLT_AK8PFHT850_TrimMass50,                          "HLT_AK8PFHT850_TrimMass50/O");
      //outputTree->Branch("HLT_AK8PFHT900_TrimMass50",                           &HLT_AK8PFHT900_TrimMass50,                          "HLT_AK8PFHT900_TrimMass50/O");
      
      
      //outputTree->Branch("HLT_AK8PFHT700_TrimR0p1PT0p03Mass50",                 &HLT_AK8PFHT700_TrimR0p1PT0p03Mass50,                "HLT_AK8PFHT700_TrimR0p1PT0p03Mass50/O");
      // outputTree->Branch("HLT_PFHT650_WideJetMJJ950DEtaJJ1p5",                  &HLT_PFHT650_WideJetMJJ950DEtaJJ1p5,                 "HLT_PFHT650_WideJetMJJ950DEtaJJ1p5/O");
      // outputTree->Branch("HLT_PFHT650_WideJetMJJ900DEtaJJ1p5",                  &HLT_PFHT650_WideJetMJJ900DEtaJJ1p5,                  "HLT_PFHT650_WideJetMJJ900DEtaJJ1p5/O");
      

      //outputTree->Branch("HLT_PFJet450",                                        &HLT_PFJet450,                                       "HLT_PFJet450/O");
      //outputTree->Branch("HLT_PFJet500",                                        &HLT_PFJet500,                                       "HLT_PFJet500/O");
      //outputTree->Branch("HLT_PFJet550",                                        &HLT_PFJet550,                                       "HLT_PFJet550/O");
      //outputTree->Branch("HLT_AK8PFJet400",                                     &HLT_AK8PFJet400,                                    "HLT_AK8PFJet400/O");
      //outputTree->Branch("HLT_AK8PFJet450",                                     &HLT_AK8PFJet450,                                    "HLT_AK8PFJet450/O");
      //outputTree->Branch("HLT_AK8PFJet500",                                     &HLT_AK8PFJet500,                                    "HLT_AK8PFJet500/O");
      //outputTree->Branch("HLT_AK8PFJet550",                                     &HLT_AK8PFJet550,                                    "HLT_AK8PFJet550/O");
      //outputTree->Branch("HLT_AK8PFJet330_TrimMass30_PFAK8BTagDeepCSV_p17",     &HLT_AK8PFJet330_TrimMass30_PFAK8BTagDeepCSV_p17,    "HLT_AK8PFJet330_TrimMass30_PFAK8BTagDeepCSV_p17/O");
      //outputTree->Branch("HLT_AK8PFJet330_TrimMass30_PFAK8BTagDeepCSV_p1",      &HLT_AK8PFJet330_TrimMass30_PFAK8BTagDeepCSV_p1,     "HLT_AK8PFJet330_TrimMass30_PFAK8BTagDeepCSV_p1/O");
      //outputTree->Branch("HLT_AK8PFJet330_PFAK8BTagCSV_p17",                    &HLT_AK8PFJet330_PFAK8BTagCSV_p17,                   "HLT_AK8PFJet330_PFAK8BTagCSV_p17/O");
      //outputTree->Branch("HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_p02",  &HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_p02, "HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_p02/O");
      //outputTree->Branch("HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_np2",  &HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_np2, "HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_np2/O");
      //outputTree->Branch("HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_np4",  &HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_np4, "HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_np4/O"); 
      //outputTree->Branch("HLT_AK8DiPFJet300_200_TrimMass30_BTagCSV_p20",        &HLT_AK8DiPFJet300_200_TrimMass30_BTagCSV_p20,       "HLT_AK8DiPFJet300_200_TrimMass30_BTagCSV_p20/O");
      //outputTree->Branch("HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p087",       &HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p087,      "HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p087/O");
      //outputTree->Branch("HLT_AK8DiPFJet300_200_TrimMass30_BTagCSV_p087",       &HLT_AK8DiPFJet300_200_TrimMass30_BTagCSV_p087,      "HLT_AK8DiPFJet300_200_TrimMass30_BTagCSV_p087/O");
      //outputTree->Branch("HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20",     &HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20,    "HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20/O");
      //outputTree->Branch("HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20",        &HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20,       "HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20/O");
      //outputTree->Branch("HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20",        &HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20,       "HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20/O");
      outputTree->Branch("HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90",  &HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90,"HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90/O");
      outputTree->Branch("HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95",  &HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95,"HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95/O");
    
    }

    if ((Option == 0 or Option == 1) && (!isData) ) {
      outputTree->Branch("nGenJet", &nGenJet, "nGenJet/I");
      outputTree->Branch("GenJet_eta", &genJetEta, "GenJet_eta[nGenJet]/F");
      outputTree->Branch("GenJet_phi", &genJetPhi, "GenJet_phi[nGenJet]/F");
      outputTree->Branch("GenJet_pt", &genJetPt, "GenJet_pt[nGenJet]/F");
      outputTree->Branch("GenJet_mass", &genJetMass, "GenJet_mass[nGenJet]/F");
      outputTree->Branch("GenHmass", &GenHmass, "GenHmass/F");
      outputTree->Branch("GenJet_partonFlavour", &genJetPartonFlavor, "GenJet_partonFlavour[nGenJet]/I");
      outputTree->Branch("nGenJetAK8", &nGenJetAK8, "nGenJetAK8/I");
      outputTree->Branch("GenJetAK8_eta", &genJetAK8Eta, "GenJetAK8_eta[nGenJetAK8]/F");
      outputTree->Branch("GenJetAK8_phi", &genJetAK8Phi, "GenJetAK8_phi[nGenJetAK8]/F");
      outputTree->Branch("GenJetAK8_pt", &genJetAK8Pt, "GenJetAK8_pt[nGenJetAK8]/F");
      outputTree->Branch("GenJetAK8_mass", &genJetAK8Mass, "GenJetAK8_mass[nGenJetAK8]/F");
      outputTree->Branch("GenJetAK8_partonFlavour", &genJetAK8PartonFlavor, "GenJetAK8_partonFlavour[nGenJetAK8]/I");
      
      outputTree->Branch("nFatJet", &nFatJet, "nFatJet/I");
      outputTree->Branch("FatJet_eta", &FatJetEta, "FatJet_eta[nFatJet]/F");
      outputTree->Branch("FatJet_phi", &FatJetPhi, "FatJet_phi[nFatJet]/F");  
      outputTree->Branch("FatJet_pt", &FatJetPt, "FatJet_pt[nFatJet]/F");
      outputTree->Branch("FatJet_particleNet_XbbVsQCD", &FatJetPNet, "FatJet_particleNet_XbbVsQCD[nFatJet]/F");
      outputTree->Branch("FatJet_msoftdrop", &FatJetMass, "FatJet_msoftdrop[nFatJet]/F");
      outputTree->Branch("FatJet_nBHadrons", &FatJetBHadrons, "FatJet_nBHadrons[nFatJet]/I");
      
      outputTree->Branch("FatJet_mass", &FatJetM_nosoftdrop, "FatJet_mass[nFatJet]/F");
      outputTree->Branch("FatJet_particleNet_massCorr", &FatJetPNetMasscorr, "FatJet_particleNet_massCorr[nFatJet]/F");

      outputTree->Branch("nJet", &nJet, "nJet/I");
      outputTree->Branch("Jet_eta", &JetEta, "Jet_eta[nJet]/F"); 
      outputTree->Branch("Jet_phi", &JetPhi, "Jet_phi[nJet]/F");
      outputTree->Branch("Jet_pt", &JetPt, "Jet_pt[nJet]/F");
      outputTree->Branch("Jet_partonFlavour", &JetFlavour, "Jet_partonFlavour[nJet]/I");

      outputTree->Branch("nSigBjets", &nSigBjets, "nSigBjets/I");   
      outputTree->Branch("Jet_PNetSignal", &Jet_PNetSignal , "Jet_PNetSignal[5]/F");
      outputTree->Branch("Jet_DeepJetSignal", &Jet_DeepJetSignal , "Jet_DeepJetSignal[5]/F");
      outputTree->Branch("Jet_bmatchPt", &Jet_bmatchPt, "Jet_bmatchPt[5]/F");
      outputTree->Branch("Jet_bmatchEta", &Jet_bmatchEta, "Jet_bmatchEta[5]/F");
      outputTree->Branch("Jet_bmatchFlav", &Jet_bmatchFlav, "Jet_bmatchFlav[5]/F");

      outputTree->Branch("nBkgjets", &nBkgjets, "nBkgjets/I");
      outputTree->Branch("Jet_nobmatchPt", &Jet_nobmatchPt, "Jet_nobmatchPt[5]/F");
      outputTree->Branch("Jet_nobmatchEta", &Jet_nobmatchEta, "Jet_nobmatchEta[5]/F");
      outputTree->Branch("Jet_nobmatchFlav", &Jet_nobmatchFlav, "Jet_nobmatchFlav[5]/F");
      outputTree->Branch("Jet_PNetBkg", &Jet_PNetBkg , "Jet_PNetBkg[5]/F");
      outputTree->Branch("Jet_DeepJetBkg", &Jet_DeepJetBkg , "Jet_DeepJetBkg[5]/F");    

      outputTree->Branch("nBkgFatjets", &nBkgFatjets,"nBkgFatjets/I");
      outputTree->Branch("FatJet_PNetBkg", &FatJet_PNetBkg , "FatJet_PNetBkg[3]/F");
      outputTree->Branch("FatJet_DDBBkg", &FatJet_DDBBkg , "FatJet_DDBBkg[3]/F");
      outputTree->Branch("FatJet_nobmatchPt", &FatJet_nobmatchPt, "FatJet_nobmatchPt[3]/F");
      outputTree->Branch("FatJet_nobmatchEta", &FatJet_nobmatchEta, "FatJet_nobmatchEta[3]/F");
      outputTree->Branch("FatJet_nobmatchM", &FatJet_nobmatchM, "FatJet_nobmatchM[3]/F");
      
      //outputTree->Branch("TestPt1", &TestPt1, "TestPt1/F");
      //outputTree->Branch("TestPt2", &TestPt2, "TestPt2/F");
      //outputTree->Branch("TestDeltaR1", &TestDeltaR1, "TestDeltaR1/F");
      outputTree->Branch("FatJetDeltaR", &FatJetDeltaR, "FatJetDeltaR/F");
      outputTree->Branch("DeltaR_HH", &DeltaR_HH, "DeltaR_HH/F");
     }


    cout << "Run With Option = " << Option << "\n";
    
    if (Option == 0) cout << "Option = 0 : No Cuts \n";
    if (Option == 2) cout << "Option = 2 : Select FatJets with pT > 200 GeV and PNetXbb > 0.8 only\n";
    if (Option == 5) cout << "Option = 5 : Select Events with FatJet1 pT > 200 GeV and PNetXbb > 0.8 only\n";
    if (Option == 10) cout << "Option = 10 : Select FatJets with pT > 200 GeV and tau3/tau2 < 0.54 only\n";
    if (Option == 20) cout << "Option = 20 : Select FatJets with pT > 200 GeV and MassSD>50, but only save Jet1 info\n";
    if (Option == 21) cout << "Option = 21 : Select FatJets with pT > 200 GeV and MassSD>50, but save all info\n";
    if (Option == 100) cout << "Option = 100 : No Cuts, save only genMTT \n";

    //-------------------------------
    //random number generator for JMR
    //-------------------------------
    TRandom3* rnd = new TRandom3(1);

    UInt_t NoPass_N = 0; 
    UInt_t NEventsFilled = 0;
    std::string Golden_jsonFile; 

    // Load JSON file
    if (year == "2024" ) {
        Golden_jsonFile = CMSSWDir + "/src/HHToBBGG-Run3/data/Run3_2024_Golden.json";
    }
    if (year == "2025" ) {
        Golden_jsonFile = CMSSWDir + "/src/HHToBBGG-Run3/data/Run3_2025_Golden_391658_393461.json";
    }
    else {
        Golden_jsonFile = CMSSWDir + "/src/HHToBBGG-Run3/data/Run3_2022_2023_Golden.json";
    }
    auto runLuminosityRanges = loadJson(Golden_jsonFile);

    std::cout << "[INFO] Loaded JSON with " << runLuminosityRanges.size() << " runs." << std::endl;

    //begin loop
    if (fChain == 0) return;
    UInt_t nentries = fChain->GetEntries();
    Long64_t nbytes = 0, nb = 0;



    cout << "nentries = " << nentries << "\n";
    for (UInt_t jentry=0; jentry<nentries;jentry++) {
      //begin event
      
      if(jentry % 1000 == 0) cout << "Processing entry " << jentry << endl;
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0){ 
        cout << "Entry<0 " << endl;   
        break;
      }
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // Check if the current run is in the JSON data
      auto runIt = runLuminosityRanges.find(run);
      bool isInRange = false;

      if (isData && runIt != runLuminosityRanges.end()) {
          // Check if the luminosity block is within any of the ranges for this run
          for (const auto& [start, end] : runIt->second) {
              if (luminosityBlock >= start && luminosityBlock <= end) {
                  isInRange = true;
                  break;
              }
          }
      }
      /*
      if (isData) {
          std::cout << "Checking run: " << run << ", lumi: " << luminosityBlock << std::endl;

          if (runIt == runLuminosityRanges.end()) {
              std::cout << "Run not found in JSON!" << std::endl;
          } else if (!isInRange) {
              std::cout << "Run found, but lumi " << luminosityBlock << " not in range." << std::endl;
          } else {
              std::cout << "Event is in JSON." << std::endl;
          }
      }
      */    
            
   //   cout << isInRange << endl;
      if(isData && !isInRange) {
          NoPass_N++;
	  continue;
      }

      //Use the non-normalized version because some samples have non-equal genWeights
      weight = genWeight;
      NEvents->SetBinContent( 1, NEvents->GetBinContent(1) + weight);

      //reset tree variables
      genHiggs1Pt = -99.0;
      genHiggs1Eta = -99.0;
      genHiggs1Phi = -99.0;
      genHiggs2Pt = -99.0;
      genHiggs2Eta = -99.0;
      genHiggs2Phi = -99.0;
      genHH_pt = -99;
      genHH_eta = -99;
      genHH_phi = -99;
      genHH_mass = -99;   
      genWPt = -99.0;
      genWEta = -99.0;
      genWPhi = -99.0;
      genZPt = -99.0;
      genZEta = -99.0;
      genZPhi = -99.0;
      genTop1Pt = -99.0;
      genTop1Mass = -99.0;
      genTop1Eta = -99.0;
      genTop1Phi = -99.0;
      genTop2Pt = -99.0;
      genTop2Mass = -99.0;
      genTop2Eta = -99.0;
      genTop2Phi = -99.0;
      genMTT = -99;
      genLeptonId = 0;
      genLeptonMotherId = 0;
      genLeptonPt = -99.0;
      genLeptonEta = -99.0;
      genLeptonPhi = -99.0;
      genPhoton1Pt = -99.0;
      genPhoton1Eta = -99.0;
      genPhoton1Phi = -99.0;
      genPho1_Idx = -99;
      genPhoton2Pt = -99.0;
      genPhoton2Eta = -99.0;
      genPhoton2Phi = -99.0;
      genPho2_Idx = -99;
      NJets = 0;

      fatJet1Pt          = -99.0;
      fatJet1Pt_JES_Up   = -99.0;
      fatJet1Pt_JES_Down = -99.0;
      fatJet1Eta = -99.0;
      fatJet1Phi = -99.0;
      fatJet1Mass = -99.0;
      fatJet1MassSD      = -99.0;
      fatJet1MassSD_UnCorrected = -99.0;
      fatJet1MassSD_JMS_Up      = -99.0;
      fatJet1MassSD_JMS_Down    = -99.0;
      fatJet1MassSD_JMR_Up      = -99.0;
      fatJet1MassSD_JMR_Down    = -99.0;
      fatJet1DDBTagger = -99.0;
      fatJet1PNetXbb = -99;
      fatJet1PNetXcc = -99;
      fatJet1PNetXqq = -99;
      fatJet1PNetQCD = -99;
      fatJet1GenMatchIndex = -99.0;
      fatJet1Tau3OverTau2 = -99;
      fatJet1_n2b1 = -99; 
      fatJet1HasMuon = 0;
      fatJet1HasElectron = 0;
      fatJet1HasBJetCSVLoose = 0;
      fatJet1HasBJetCSVMedium = 0;
      fatJet1HasBJetCSVTight = 0;      
      fatJet1OppositeHemisphereHasBJet = 0;
      fatJet2Pt = -99.0;
      fatJet2Pt_JES_Up   = -99.0;
      fatJet2Pt_JES_Down = -99.0;
      fatJet2Eta = -99.0;
      fatJet2Phi = -99.0;
      fatJet2Mass = -99.0;
      fatJet2MassSD = -99.0;
      fatJet2MassSD_UnCorrected = -99.0;
      fatJet2MassSD_JMS_Up      = -99.0;
      fatJet2MassSD_JMS_Down    = -99.0;
      fatJet2MassSD_JMR_Up      = -99.0;
      fatJet2MassSD_JMR_Down    = -99.0;
      fatJet2DDBTagger = -99.0;
      fatJet2PNetXbb = -99;
      fatJet2PNetXcc = -99;
      fatJet2PNetXqq = -99;
      fatJet2PNetQCD = -99;
      fatJet2GenMatchIndex = -99.0;
      fatJet2Tau3OverTau2 = -99;
      fatJet2HasMuon = 0;
      fatJet2HasElectron = 0;
      fatJet2HasBJetCSVLoose = 0;
      fatJet2HasBJetCSVMedium = 0;
      fatJet2HasBJetCSVTight = 0;
      fatJet3Pt = -99.0;
      fatJet2Pt_JES_Up   = -99.0;
      fatJet2Pt_JES_Down = -99.0;
      fatJet3Eta = -99.0;
      fatJet3Phi = -99.0;
      fatJet3Mass = -99.0;
      fatJet3MassSD = -99.0;
      fatJet3MassSD_UnCorrected = -99.0;
      fatJet3MassSD_JMS_Up      = -99.0;
      fatJet3MassSD_JMS_Down    = -99.0;
      fatJet3MassSD_JMR_Up      = -99.0;
      fatJet3MassSD_JMR_Down    = -99.0;
      fatJet3DDBTagger = -99.0;
      fatJet3PNetXbb = -99;
      fatJet3PNetXcc = -99;
      fatJet3PNetXqq = -99;
      fatJet3PNetQCD = -99;
      fatJet3Tau3OverTau2 = -99;
      fatJet3HasMuon = 0;
      fatJet3HasElectron = 0;
      fatJet3HasBJetCSVLoose = 0;
      fatJet3HasBJetCSVMedium = 0;
      fatJet3HasBJetCSVTight = 0;
      hh_pt = -99;
      hh_eta = -99;
      hh_phi = -99;
      hh_mass = -99;
      hh_pt_JESUp = -99;
      hh_pt_JESDown = -99;
      hh_pt_JMSUp = -99;
      hh_pt_JMSDown = -99;
      hh_pt_JMRUp = -99;
      hh_pt_JMRDown = -99;
      hh_eta_JESUp = -99;
      hh_eta_JESDown = -99;
      hh_eta_JMSUp = -99;
      hh_eta_JMSDown = -99;
      hh_eta_JMRUp = -99;
      hh_eta_JMRDown = -99;
      hh_mass_JESUp = -99;
      hh_mass_JESDown = -99;
      hh_mass_JMSUp = -99;
      hh_mass_JMSDown = -99;
      hh_mass_JMRUp = -99;
      hh_mass_JMRDown = -99;  
      fatJet1PtOverMHH = -99;
      fatJet1PtOverMHH_JESUp = -99;
      fatJet1PtOverMHH_JESDown = -99;
      fatJet1PtOverMHH_JMSUp = -99;
      fatJet1PtOverMHH_JMSDown = -99;
      fatJet1PtOverMHH_JMRUp = -99;
      fatJet1PtOverMHH_JMRDown = -99;
      fatJet1PtOverMSD = -99;
      fatJet2PtOverMHH = -99;
      fatJet2PtOverMHH_JESUp = -99;
      fatJet2PtOverMHH_JESDown = -99;
      fatJet2PtOverMHH_JMSUp = -99;
      fatJet2PtOverMHH_JMSDown = -99;
      fatJet2PtOverMHH_JMRUp = -99;
      fatJet2PtOverMHH_JMRDown = -99;
      fatJet2PtOverMSD = -99;
      deltaEta_j1j2 = -99;
      deltaPhi_j1j2 = -99;
      deltaR_j1j2 = -99;    
      ptj2_over_ptj1 = -99;
      mj2_over_mj1 = -99;
      lep1Pt = -99;
      lep1Eta = -99;
      lep1Phi = -99;
      lep1Id = 0;
      lep2Pt = -99;
      lep2Eta = -99;
      lep2Phi = -99;
      lep2Id = 0;
      lep1mva = -99;
      lep2mva = -99;

      Muon_1Pt = -99;
      Muon_1Eta = -99;
      Muon_1Phi = -99;
      Muon_1Id = 0;
      Muon_2Pt = -99;
      Muon_2Eta = -99;
      Muon_2Phi = -99;
      Muon_2Id = 0;
      Muon_1mva = -99;
      Muon_2mva = -99;

      Ele_1Pt = -99;
      Ele_1Eta = -99;
      Ele_1Phi = -99;
      Ele_1Id = 0;
      Ele_2Pt = -99;
      Ele_2Eta = -99;
      Ele_2Phi = -99;
      Ele_2Id = 0;
      Ele_1mva = -99;
      Ele_2mva = -99;

      pho1Pt = -99;
      pho1Eta = -99;
      pho1Phi = -99;
      pho2Pt = -99;
      pho2Eta = -99;
      pho2Phi = -99;
      
      b_jet1Pt = -99;
      b_jet1Eta = -99;
      b_jet1Phi = -99;
      b_jet1Mass = -99;
      b_jet1PNet = -99;
      b_jet1PtRes = -99;
      b_jet1PtCorr = -99;
      b_jet1PtCorrNeutrino = -99;

      b_jet2Pt = -99;
      b_jet2Eta = -99;
      b_jet2Phi = -99;
      b_jet2Mass = -99;
      b_jet2PNet = -99;
      b_jet2PtRes = -99;
      b_jet2PtCorr = -99;
      b_jet2PtCorrNeutrino = -99;
       
      jet1Pt = -99;
      jet1Eta = -99;
      jet1Phi = -99;
      jet1Mass = -99;
      jet1PNet = -99;
      jet1DeepFlavB = -99;
      jet1Flav = -99;
      jet2Pt = -99;
      jet2Eta = -99;
      jet2Phi = -99;
      jet2Mass = -99;
      jet2PNet = -99;
      jet2DeepFlavB = -99;
      jet2Flav = -99;
      jet3Pt = -99;
      jet3Eta = -99;
      jet3Phi = -99;
      jet3Mass = -99;
      jet3PNet = -99;
      jet3DeepFlavB = -99;
      jet3Flav = -99;
      jet4Pt = -99;
      jet4Eta = -99;
      jet4Phi = -99;
      jet4Mass = -99;
      jet4PNet = -99;
      jet4DeepFlavB = -99;
      jet4Flav = -99;
      jet5Pt = -99;
      jet5Eta = -99;
      jet5Phi = -99;
      jet5Mass = -99;
      jet5PNet = -99;
      jet5DeepFlavB = -99;
      jet5Flav = -99;
      jet6Pt = -99;
      jet6Eta = -99;
      jet6Phi = -99;
      jet6Mass = -99;
      jet6PNet = -99;
      // add jet Mass & Dijet_mass
      Dijets_Mass = -99; 
      DijetsCan_Mass = -99;
      Dijetsall_Mass = -99;
      //variables for overlap removal with VBF HH->4b boosted analysis
      isVBFtag = 0;
      dijetmass = -99;
      vbfjet1Pt = -99;
      vbfjet1Eta = -99;
      vbfjet1Phi = -99;
      vbfjet1Mass = -99;
      vbfjet2Pt = -99;
      vbfjet2Eta = -99;
      vbfjet2Phi = -99;
      vbfjet2Mass = -99;
      vbffatJet1Pt = -99;
      vbffatJet1Eta = -99;
      vbffatJet1Phi = -99;
      vbffatJet1PNetXbb = -99;
      vbffatJet2Pt = -99;
      vbffatJet2Eta = -99;
      vbffatJet2Phi = -99;
      vbffatJet2PNetXbb = -99;
      // Testing FatJet_PNet     
      Diphoton_Mass = -99;
      GenHmass = -99;  
      nSigBjets = 0;
      nBkgFatjets = 0;
      nBkgjets = 0; 
      //tobbHiggs
      tobbHiggs_Pt = -99;
      tobbHiggs_Eta = -99;
      tobbHiggs_Phi = -99;
      tobbHiggs_Mass = -99;
      toggHiggs_Pt = -99;
      toggHiggs_Eta = -99;
      toggHiggs_Phi = -99;
      toggHiggs_Mass = -99;
      // gen b-quark
      genbQuark1_Pt = -99;
      genbQuark1_Eta = -99;
      genbQuark1_Phi = -99;
      genbQuark2_Pt = -99;
      genbQuark2_Eta = -99;
      genbQuark2_Phi = -99;
      // gen B-jet
      GenBJet1_Pt = -99;
      GenBJet1_Eta = -99;
      GenBJet1_Phi = -99;
      GenBJet1_Mass = -99;
      GenBJet2_Pt = -99;
      GenBJet2_Eta = -99;
      GenBJet2_Phi = -99;
      GenBJet2_Mass = -99;
      GenBJet3_Pt = -99;
      GenBJet3_Eta = -99;
      GenBJet3_Phi = -99;
      GenBJet3_Mass = -99;
      GenBJet4_Pt = -99;
      GenBJet4_Eta = -99;
      GenBJet4_Phi = -99;
      GenBJet4_Mass = -99;
      GenBJet5_Pt = -99;
      GenBJet5_Eta = -99;
      GenBJet5_Phi = -99;
      GenBJet5_Mass = -99;
      // GenFatJet
      FatJetMatch_Pt = -99;
      FatJetMatch_Eta = -99;
      FatJetMatch_Phi = -99;
      FatJetMatch_Mass = -99;
      FatJetMatch_corrMass = -99;
      FatJetMatch_PNet = -99;
      //FatJetMatch_Flav = -99;
      FatJetClose1_Pt = -99;
      FatJetClose1_Eta = -99;
      FatJetClose1_Phi = -99;
      FatJetClose1_Mass = -99;
     // FatJetClose1_Flav = -99;
      FatJetClose2_Pt = -99;
      FatJetClose2_Eta = -99;
      FatJetClose2_Phi = -99;
      FatJetClose2_Mass = -99;
     // GenFatJetClose2_Flav = -99;
      // RecoFatJet
      // added new phos
      pho1r9 = 0;
      pho1_ChIOvEt = 0;
      pho1_ChI = 0;
      pho1_hoe = 0;
      pho1_mvaID = -99;    
      pho1_electronVeto = 0;
      
      pho1R9=-99;
      pho2R9=-99;
      pho1ChIso=-99;
      pho2ChIso=-99;
      pho1QCD_realMatched = 0;
      pho2QCD_realMatched = 0;
      Matched_genpho1Pt = -99;
      Matched_genpho2Pt = -99;
      pho1genId = -99;
      pho2genId = -99;


      pho2r9 = 0;
      pho2_ChIOvEt = 0;
      pho2_ChI = 0;
      pho2_hoe = 0;
      pho2_mvaID = -99;
      pho2_electronVeto = 0;
      pho1_seediEtaOriX = -999;
      pho2_seediEtaOriX = -999;
      pho1_seediPhiOriY = -999;
      pho2_seediPhiOriY = -999;
      BquarkR = - 99;
      FatJetDeltaR = -99;
      DeltaR_HH = -99;
      //Higgs DNA variable
      pho1_r9_ScEta = 0;
      pho2_r9_ScEta = 0;
      
      // BDT variables
      pho1_energyErr = -99;
      pho1_energyRaw = -99;
      pho2_energyErr = -99;
      pho2_energyRaw = -99;
      pho1_pfRelIso03_all_quadratic = -99;
      pho2_pfRelIso03_all_quadratic = -99;
      
      
      Dijetsall_Pt = -99;
      Dijetsall_Eta = -99;
      Dijetsall_Phi = -99;
      Diphoton_Pt = -99;
      Diphoton_Eta = -99;
      Diphoton_Phi = -99;
      M_jjgg = -99;
      jet1PtRes = -99;
      jet2PtRes = -99;
      jet1PtCorr = -99;
      jet1PtCorrNeutrino = -99;
      jet2PtCorr = -99;
      jet2PtCorrNeutrino = -99;
      rho = -99;
      minR_jg = -99;
      otherR_jg = -99;
      DeltaPhi_j1MET = -99;
      DeltaPhi_j2MET = -99;
      leadB_leadLep = -99;
      leadB_subleadLep = -99;
      subleadB_leadLep = -99;
      subleadB_subleadLep = -99;
      chi_t0sq = -99;
      chi_t1sq = -99;

      for (int i = 0; i < 3; i++){
        FatJet_PNetBkg[i] = -99;
        FatJet_DDBBkg[i] = -99;
        FatJet_nobmatchPt[i] = -99;
        FatJet_nobmatchEta[i] = -99;  
        FatJet_nobmatchM[i] = -99;
      }      
      for (int i = 0; i < 5; i++){
        Jet_PNetBkg[i] = -99;
        Jet_DeepJetBkg[i] = -99;
        Jet_nobmatchPt[i] = -99;
        Jet_nobmatchEta[i] = -99;
        Jet_nobmatchFlav[i] = -1;
      }
      for (int i = 0; i < 5 ; i++){
        Jet_PNetSignal[i] = -99;
        Jet_DeepJetSignal[i] = -99;
        Jet_bmatchPt[i] = -99;
        Jet_bmatchEta[i] = -99;
        Jet_bmatchFlav[i] = -1;
      }

      if (!isData){
        for(int i = 0; i < nGenJet; i++){ 
          genJetEta[i] = -999;
          genJetPhi[i] = -999;
 	  genJetPt[i] = -999;
 	  genJetMass[i] = -999;
 	  genJetPartonFlavor[i] = -999;
        }
        for(int i = 0; i < nGenJetAK8; i++) {
          genJetAK8Eta[i] = -999;
          genJetAK8Phi[i] = -999;
          genJetAK8Pt[i] = -999;
          genJetAK8Mass[i] = -999;
          genJetAK8PartonFlavor[i] = -999;
        }
      }
      for(int i = 0; i < nFatJet; i++){
          FatJetEta[i]=-999;
          FatJetPhi[i]=-999;
          FatJetPt[i]=-999;
          FatJetPNet[i]=-999;
          FatJetMass[i]=-999;
          FatJetBHadrons[i]=-999;
          FatJetM_nosoftdrop[i]=-999;
          FatJetPNetMasscorr[i]=-999;
        }
      for(int i = 0; i < nJet; i++){
          JetEta[i]=-999;
          JetPhi[i]=-999;
          JetPt[i] =-999;
          JetFlavour[i] = -999;
        }
        
         
      //------------------------------
      //----Event variables------------
      //------------------------------
      METPt = PuppiMET_pt;
      METEta = 0.0;
      METPhi = PuppiMET_phi;
      METsumEt = PuppiMET_sumEt;
      //------------------------------
      //----gen-jets------------
      //------------------------------
      if(!isData){
        for(int i = 0; i < nGenJet; i++) {
          genJetEta[i] = GenJet_eta[i];
          genJetPhi[i] = GenJet_phi[i];
 	  genJetPt[i] = GenJet_pt[i];
 	  genJetMass[i] = GenJet_mass[i];
 	  genJetPartonFlavor[i] = GenJet_partonFlavour[i];
        }
        for(int i = 0; i < nGenJetAK8; i++) {
          genJetAK8Eta[i] = GenJetAK8_eta[i];
          genJetAK8Phi[i] = GenJetAK8_phi[i];
          genJetAK8Pt[i] = GenJetAK8_pt[i];
          genJetAK8Mass[i] = GenJetAK8_mass[i];
          genJetAK8PartonFlavor[i] = GenJetAK8_partonFlavour[i];
        }
      }
        //std::cout << nFatJet << std::endl;
      for(int i = 0; i < nFatJet; i++){
          FatJetEta[i] = FatJet_eta[i];
          FatJetPhi[i] = FatJet_phi[i];
          FatJetPt[i] = FatJet_pt[i];
          FatJetPNet[i] = FatJet_particleNet_XbbVsQCD[i];
          FatJetMass[i] = FatJet_msoftdrop[i];
          FatJetBHadrons[i] = FatJet_nBHadrons[i];
          FatJetM_nosoftdrop[i]=FatJet_mass[i];
          FatJetPNetMasscorr[i]=FatJet_particleNet_massCorr[i];
        }
      for(int i = 0; i < nJet; i++){
          JetEta[i] = Jet_eta[i];
          JetPhi[i] = Jet_phi[i];
          JetPt[i] = Jet_pt[i];
          JetFlavour[i] = Jet_partonFlavour[i];
        }
      //------------------------------
      //----find gen-higgs------------
      //------------------------------
      int current_mIndex = -1;
      std::vector< TLorentzVector > genHiggsVector;
      if (!isData) {
	for(int i = 0; i < nGenPart; i++) {
          if ( abs(GenPart_pdgId[i]) == 5 && GenPart_pdgId[GenPart_genPartIdxMother[i]] == 23 && GenPart_status[GenPart_genPartIdxMother[i]]==62 ){
            if (genbQuark1_Pt < 0){
              genbQuark1_Pt = GenPart_pt[i];
              genbQuark1_Eta = GenPart_eta[i];
              genbQuark1_Phi = GenPart_phi[i];
            } else if (genbQuark2_Pt < 0){
              genbQuark2_Pt = GenPart_pt[i];
              genbQuark2_Eta = GenPart_eta[i];    
              genbQuark2_Phi = GenPart_phi[i];
            } 
            if (genbQuark2_Pt>0 && genbQuark1_Pt>0){
              BquarkR=deltaR(genbQuark2_Eta, genbQuark2_Phi, genbQuark1_Eta, genbQuark1_Phi);
            }
              
            if (tobbHiggs_Pt<0){
              tobbHiggs_Pt = GenPart_pt[GenPart_genPartIdxMother[i]];
              tobbHiggs_Eta = GenPart_eta[GenPart_genPartIdxMother[i]];
              tobbHiggs_Phi = GenPart_phi[GenPart_genPartIdxMother[i]];
              tobbHiggs_Mass = GenPart_mass[GenPart_genPartIdxMother[i]];
            }
          }
	  if( (abs(GenPart_pdgId[i]) == 5 || GenPart_pdgId[i]==22) && GenPart_pdgId[GenPart_genPartIdxMother[i]] == 25 && current_mIndex != GenPart_genPartIdxMother[i] && GenPart_status[GenPart_genPartIdxMother[i]]==62){
	    TLorentzVector h;
	    h.SetPtEtaPhiM( GenPart_pt[GenPart_genPartIdxMother[i]], GenPart_eta[GenPart_genPartIdxMother[i]], GenPart_phi[GenPart_genPartIdxMother[i]], GenPart_mass[GenPart_genPartIdxMother[i]] );
	    genHiggsVector.push_back(h);
	    current_mIndex = GenPart_genPartIdxMother[i];
	  }

	  if ( (abs(GenPart_pdgId[i]) == 11 || abs(GenPart_pdgId[i]) == 13)
	       && GenPart_pt[i] > 10
	       && (abs(GenPart_pdgId[GenPart_genPartIdxMother[i]]) == 23 || abs(GenPart_pdgId[GenPart_genPartIdxMother[i]]) == 24 || abs(GenPart_pdgId[GenPart_genPartIdxMother[i]]) == 15)
	       && GenPart_pt[i] > genLeptonPt 
	       ) {
	    genLeptonId = GenPart_pdgId[i];
	    genLeptonMotherId = GenPart_pdgId[GenPart_genPartIdxMother[i]];
	    genLeptonPt = GenPart_pt[i];
	    genLeptonEta = GenPart_eta[i];
	    genLeptonPhi = GenPart_phi[i];	    
	  }

	  if ( GenPart_pdgId[i] == 22 && GenPart_pdgId[GenPart_genPartIdxMother[i]] == 25 && GenPart_status[GenPart_genPartIdxMother[i]]==62 ) {
            if (genPhoton1Pt < 0) {
	      genPhoton1Pt = GenPart_pt[i];
	      genPhoton1Eta = GenPart_eta[i];
	      genPhoton1Phi = GenPart_phi[i];
              genPho1_Idx = i;
	    } else if (genPhoton2Pt < 0) {
	      genPhoton2Pt = GenPart_pt[i];
	      genPhoton2Eta = GenPart_eta[i];
	      genPhoton2Phi = GenPart_phi[i];
              genPho2_Idx = i;
            }

	    if (toggHiggs_Pt<0){    
              toggHiggs_Pt = GenPart_pt[GenPart_genPartIdxMother[i]];   
              toggHiggs_Eta = GenPart_eta[GenPart_genPartIdxMother[i]];         
              toggHiggs_Phi = GenPart_phi[GenPart_genPartIdxMother[i]];      
              toggHiggs_Mass = GenPart_mass[GenPart_genPartIdxMother[i]];  
	    }  
	  }

	  if ( abs(GenPart_pdgId[i]) == 23 
	       && GenPart_status[i] == 62 
	       ) {
	    genZPt = GenPart_pt[i];
	    genZEta = GenPart_eta[i];
	    genZPhi = GenPart_phi[i];
	  }

	  if ( abs(GenPart_pdgId[i]) == 24
	       && GenPart_status[i] == 62
	       ) {
	    genWPt = GenPart_pt[i];
	    genWEta = GenPart_eta[i];
	    genWPhi = GenPart_phi[i];
	  }

	  if ( GenPart_pdgId[i] == 6 
	       && GenPart_status[i] == 22 
	       ) {
	    genTop1Mass = GenPart_mass[i];
	    genTop1Pt = GenPart_pt[i];
	    genTop1Eta = GenPart_eta[i];
	    genTop1Phi = GenPart_phi[i];	   
	  }
	  if ( GenPart_pdgId[i] == -6 
	       && GenPart_status[i] == 22 
	       ) {
	    genTop2Mass = GenPart_mass[i];
	    genTop2Pt = GenPart_pt[i];
	    genTop2Eta = GenPart_eta[i];
	    genTop2Phi = GenPart_phi[i];	   
	  }
	  TLorentzVector Top1Vector;
	  Top1Vector.SetPtEtaPhiM( genTop1Pt, genTop1Eta, genTop1Phi, genTop1Mass );
	  TLorentzVector Top2Vector;
	  Top2Vector.SetPtEtaPhiM( genTop2Pt, genTop2Eta, genTop2Phi, genTop2Mass );
	  genMTT = (Top1Vector+Top2Vector).M();

	}

	if(genHiggsVector.size() >= 1) {
	  //filling tree_out variables
	  genHiggs1Pt = genHiggsVector[0].Pt();
	  genHiggs1Eta = genHiggsVector[0].Eta();
	  genHiggs1Phi = genHiggsVector[0].Phi();
	  //
	  if(genHiggsVector.size() >= 2) {
	    genHiggs2Pt = genHiggsVector[1].Pt();
	    genHiggs2Eta = genHiggsVector[1].Eta();
	    genHiggs2Phi = genHiggsVector[1].Phi();	
	  }
	}

	//gen level
	if(genHiggsVector.size() > 1) { 
	  genHH_pt = (genHiggsVector[0]+genHiggsVector[1]).Pt();
	  genHH_eta = (genHiggsVector[0]+genHiggsVector[1]).Eta();
	  genHH_phi = (genHiggsVector[0]+genHiggsVector[1]).Phi();
	  genHH_mass= (genHiggsVector[0]+genHiggsVector[1]).M();
	}
      DeltaR_HH = deltaR(tobbHiggs_Eta, tobbHiggs_Phi, toggHiggs_Eta, toggHiggs_Phi);	
      } //end if !data
      //-------------------------------------------------------------
      //---match FatJet to Higgs Boson (In MC)-----------------------
      //-------------------------------------------------------------
      Margin = 1.2;
      FatJetMatch_idx = -1;
     // FatJetClose1_idx = -1;
     // FatJetClose2_idx = -1;
      Number_FatJetMatch = 0;
      if (!isData){
        for (int i = 0; i < nFatJet; i++ ){
          if (FatJet_pt[i]<250) continue;
          if (deltaR(FatJet_eta[i], FatJet_phi[i], tobbHiggs_Eta, tobbHiggs_Phi) < Margin){
            Margin = deltaR(FatJet_eta[i], FatJet_phi[i], tobbHiggs_Eta, tobbHiggs_Phi);
            FatJetMatch_Pt = FatJet_pt[i];
            FatJetMatch_Eta = FatJet_eta[i];
            FatJetMatch_Phi = FatJet_phi[i];
            FatJetMatch_Mass = FatJet_msoftdrop[i];
            FatJetMatch_corrMass = FatJet_mass[i]*FatJet_particleNet_massCorr[i];
            FatJetMatch_PNet = FatJet_particleNet_XbbVsQCD[i];
            FatJetDeltaR = Margin;
            FatJetMatch_idx = i;
            Number_FatJetMatch++;
          }
        //  if ((FatJet_msoftdrop[i]>130)&&(FatJet_pt[i]>250)){
         //   if (TestPt1<0){
          //   TestPt1=FatJet_msoftdrop[i];
          //    TestDeltaR1 = deltaR(FatJet_eta[i], FatJet_phi[i], tobbHiggs_Eta, tobbHiggs_Phi); 
          //  }else if(TestPt2<0){
           //   TestPt2=FatJet_msoftdrop[i];
           //   TestDeltaR2 = deltaR(FatJet_eta[i], FatJet_phi[i], tobbHiggs_Eta, tobbHiggs_Phi);
           // }
        //  }
          if (Number_FatJetMatch==2){
            FatJetClose1_Pt = FatJet_pt[last1Idx];
            FatJetClose1_Eta = FatJet_eta[last1Idx]; 
            FatJetClose1_Phi = FatJet_phi[last1Idx];
            FatJetClose1_Mass = FatJet_msoftdrop[last1Idx];
            //FatJetClose1_Flav= GenJetAK8_partonFlavour[last1Idx];
          //  FatJetClose1_idx = last1Idx;
          }
          if (Number_FatJetMatch==3){
            FatJetClose2_Pt = FatJet_pt[last2Idx];
            FatJetClose2_Eta = FatJet_eta[last2Idx];
            FatJetClose2_Phi = FatJet_phi[last2Idx];
            FatJetClose2_Mass = FatJet_msoftdrop[last2Idx];
            //FatJetClose2_Flav= GenJetAK8_partonFlavour[last2Idx];
           // FatJetClose2_idx = last2Idx;
          }
          
          if (FatJetMatch_idx == i && Number_FatJetMatch==1) {
            last1Idx = FatJetMatch_idx;
          }
          if (FatJetMatch_idx == i && Number_FatJetMatch==2) {
            last2Idx = FatJetMatch_idx;
          }
        }
        //for (int i=0; i<nFatJet; i++){
         // if (GenFatJetMatch_idx!=-1 && FatJet_genJetAK8Idx[i]==GenFatJetMatch_idx){
          //  RecoFatJetCan_Pt = FatJet_pt[i];
           // RecoFatJetCan_Eta = FatJet_eta[i];
          //  RecoFatJetCan_Phi = FatJet_phi[i];
          //  RecoFatJetCan_MS = FatJet_msoftdrop[i];
          //  RecoFatJetCan_PNet = FatJet_particleNet_XbbVsQCD[i];
          //  RecoFatJetCan_DDB = FatJet_btagDDBvLV2[i];
         // } else if (GenFatJetClose1_idx!=-1 && FatJet_genJetAK8Idx[i]==GenFatJetClose1_idx){
         //   RecoFatJetClose1_Pt = FatJet_pt[i];
         //   RecoFatJetClose1_Eta = FatJet_eta[i];
         //   RecoFatJetClose1_Phi = FatJet_phi[i];
         //   RecoFatJetClose1_MS = FatJet_msoftdrop[i];
          //  RecoFatJetClose1_PNet = FatJet_particleNet_XbbVsQCD[i];
         //   RecoFatJetClose1_DDB = FatJet_btagDDBvLV2[i];
         // } else if (GenFatJetClose2_idx!=-1 && FatJet_genJetAK8Idx[i]==GenFatJetClose2_idx){
         //   RecoFatJetClose2_Pt = FatJet_pt[i];
         //   RecoFatJetClose2_Eta = FatJet_eta[i];
         //   RecoFatJetClose2_Phi = FatJet_phi[i];
         //   RecoFatJetClose2_MS = FatJet_msoftdrop[i];
         //   RecoFatJetClose2_PNet = FatJet_particleNet_XbbVsQCD[i];
         //   RecoFatJetClose2_DDB = FatJet_btagDDBvLV2[i];
         // } else if (nBkgFatjets<3){  //not coming from Higgs
         //   FatJet_nobmatchPt[nBkgFatjets] = FatJet_pt[i];                         
         //   FatJet_nobmatchEta[nBkgFatjets] = FatJet_eta[i];  
         //   FatJet_nobmatchM[nBkgFatjets] = FatJet_msoftdrop[i];    
         //   FatJet_PNetBkg[nBkgFatjets] = FatJet_particleNet_XbbVsQCD[i];  
         //   FatJet_DDBBkg[nBkgFatjets] = FatJet_btagDDBvLV2[i];                    
         //   nBkgFatjets++; 
         // }
        //} 
      }//end if Data

      //-------------------------------------------------------------
      //--- define random numbers for jet mass smearing correction
      //-------------------------------------------------------------
      double corr_fatJet1_mass_JMRUp = rnd->Gaus( 0.0, jmrValues[2] - 1.0 );
      double corr_fatJet1_mass = (fmax(jmrValues[0] - 1.0,0.0))/(jmrValues[2] - 1.0) * corr_fatJet1_mass_JMRUp;
      double corr_fatJet1_mass_JMRDown = (fmax(jmrValues[1] - 1.0,0.0))/(jmrValues[2] - 1.0) * corr_fatJet1_mass_JMRUp;
      double corr_fatJet2_mass_JMRUp = rnd->Gaus( 0.0, jmrValues[2] - 1.0 );
      double corr_fatJet2_mass = (fmax(jmrValues[0] - 1.0,0.0))/(jmrValues[2] - 1.0) * corr_fatJet2_mass_JMRUp;
      double corr_fatJet2_mass_JMRDown = (fmax(jmrValues[1] - 1.0,0.0))/(jmrValues[2] - 1.0) * corr_fatJet2_mass_JMRUp;
      double corr_fatJet3_mass_JMRUp = rnd->Gaus( 0.0, jmrValues[2] - 1.0 );
      double corr_fatJet3_mass = (fmax(jmrValues[0] - 1.0,0.0))/(jmrValues[2] - 1.0) * corr_fatJet3_mass_JMRUp;
      double corr_fatJet3_mass_JMRDown = (fmax(jmrValues[1] - 1.0,0.0))/(jmrValues[2] - 1.0) * corr_fatJet3_mass_JMRUp;
      //------------------------------------------------------
      //Match Reco Photon
      
      
      
      
      //------------------------------------------------------   
      //----------Find Photons    
      //------------------------------------------------------
      double EA1_EB1 = 0.102056;
      double EA2_EB1 = -0.000398112;
      double EA1_EB2 = 0.0820317;
      double EA2_EB2 = -0.000286224;
      double EA1_EE1 = 0.0564915;
      double EA2_EE1 = -0.000248591;
      double EA1_EE2 = 0.0428606;
      double EA2_EE2 = -0.000171541;
      double EA1_EE3 = 0.0395282;
      double EA2_EE3 = -0.000121398;
      double EA1_EE4 = 0.0369761;
      double EA2_EE4 = -8.10369e-05;
      double EA1_EE5 = 0.0369417;
      double EA2_EE5 = -2.76885e-05;
      double max_pho_iso_EB_low_r9 = 4.0;
      double max_pho_iso_EE_low_r9 = 4.0;
      rho = Rho_fixedGridRhoAll;
      bool pass_phoIso_rho_corr_EB = false;
      bool pass_phoIso_rho_corr_EE = false;
      double max_sieie_EB_low_r9 = 0.015;
      double max_sieie_EE_low_r9 = 0.035;
      double min_full5x5_r9_EB_high_r9 = 0.85;
      double min_full5x5_r9_EE_high_r9 = 0.9;
      double min_full5x5_r9_EB_low_r9 = 0.5;
      double min_full5x5_r9_EE_low_r9 = 0.8;
      bool isEB_high_r9 = false;
      bool isEB_low_r9 = false;
      bool isEE_high_r9 = false;
      bool isEE_low_r9 = false;
      bool pho_r9 = false;
      bool pho_ScEta = false;
      bool passPhotonSelection = true;

      std::vector< TLorentzVector > recoPhotonVector;  
      std::vector<Photon> photons;   

      for(unsigned int i = 0; i < nPhoton; i++ ) {  
        /*
        // boolean definitions for the photon passing corrected photon isolation requirements in the EE and EB region
        pass_phoIso_rho_corr_EB = (
            (fabs(Photon_eta[i]) > 0.0 && fabs(Photon_eta[i]) < 1.0) &&
            (
                Photon_pfPhoIso03[i]
                - (rho * EA1_EB1)
                - (rho * rho * EA2_EB1)
                < max_pho_iso_EB_low_r9
            )
        ) || (
            (fabs(Photon_eta[i]) > 1.0 && fabs(Photon_eta[i]) < 1.4442) &&
            (
                Photon_pfPhoIso03[i]
                - (rho * EA1_EB2)
                - (rho * rho * EA2_EB2)
                < max_pho_iso_EB_low_r9
            )
        );
        pass_phoIso_rho_corr_EE = (
            (fabs(Photon_eta[i]) > 1.566 && fabs(Photon_eta[i]) < 2.0) &&
            (
                Photon_pfPhoIso03[i]
                - (rho * EA1_EE1)
                - (rho * rho * EA2_EE1)
                < max_pho_iso_EE_low_r9
            )
        ) || (
            (fabs(Photon_eta[i]) > 2.0 && fabs(Photon_eta[i]) < 2.2) &&
            (
                Photon_pfPhoIso03[i]
                - (rho * EA1_EE2)
                - (rho * rho * EA2_EE2)
                < max_pho_iso_EE_low_r9
            )
        ) || (
            (fabs(Photon_eta[i]) > 2.2 && fabs(Photon_eta[i]) < 2.3) &&
            (
                Photon_pfPhoIso03[i]
                - (rho * EA1_EE3)
                - (rho * rho * EA2_EE3)
                < max_pho_iso_EE_low_r9
            )
        ) || (
            (fabs(Photon_eta[i]) > 2.3 && fabs(Photon_eta[i]) < 2.4) &&
            (
                Photon_pfPhoIso03[i]
                - (rho * EA1_EE4)
                - (rho * rho * EA2_EE4)
                < max_pho_iso_EE_low_r9
            )
        ) || (
            (fabs(Photon_eta[i]) > 2.4 && fabs(Photon_eta[i]) < 2.5) &&
            (
                Photon_pfPhoIso03[i]
                - (rho * EA1_EE5)
                - (rho * rho * EA2_EE5)
                < max_pho_iso_EE_low_r9
            )
        );
        isEB_high_r9 = ((Photon_isScEtaEB[i]) && (Photon_r9[i] > min_full5x5_r9_EB_high_r9));
        isEE_high_r9 = ((Photon_isScEtaEE[i]) && (Photon_r9[i] > min_full5x5_r9_EE_high_r9));
        isEB_low_r9 = (
          (Photon_isScEtaEB[i])
          && (Photon_r9[i] > min_full5x5_r9_EB_low_r9)
          && (Photon_r9[i] < min_full5x5_r9_EB_high_r9)
          && (Photon_trkSumPtHollowConeDR03[i] < 6.0)
          && (Photon_sieie[i] < max_sieie_EB_low_r9)
          && (pass_phoIso_rho_corr_EB)
        );
        isEE_low_r9 = (
          (Photon_isScEtaEE[i])
          && (Photon_r9[i] > min_full5x5_r9_EE_low_r9)
          && (Photon_r9[i] < min_full5x5_r9_EE_high_r9)
          && (Photon_trkSumPtHollowConeDR03[i] < 6.0)
          && (Photon_sieie[i] < max_sieie_EE_low_r9)
          && (pass_phoIso_rho_corr_EE)
        );
        pho_r9 = (isEE_low_r9 || isEE_high_r9 || isEB_low_r9 || isEB_high_r9);
        pho_ScEta = (Photon_isScEtaEB[i] || Photon_isScEtaEE[i]);  

        // The selections are applied here based on the "cutConfig"

        if (Photon_electronVeto[i]) passPhotonSelection = false;
        if (cutConfig >= 1){
          if (Photon_pt[i] <= 25) passPhotonSelection = false;
        }
        if (cutConfig >= 2){
          if (fabs(Photon_eta[i]) >= 2.5) passPhotonSelection = false;
        }
        if (cutConfig >= 3){
          if (Photon_r9[i] < 0.8 && Photon_pfRelIso03_chg_quadratic[i] > 0.3 && Photon_pfRelIso03_chg_quadratic[i]*Photon_pt[i]>20) passPhotonSelection = false;
        }
        if (cutConfig >= 4){
          if (Photon_hoe[i] > 0.08) passPhotonSelection = false;
        }
        if (cutConfig >= 5){
          if (Photon_mvaID[i] <= -0.9) passPhotonSelection = false;
        }
        if (cutConfig >= 6){
          if (!(pho_r9&&pho_ScEta)) passPhotonSelection = false;
        }
        if (!passPhotonSelection) continue;
        photons.push_back({Photon_pt[i],Photon_eta[i],Photon_phi[i],Photon_mvaID[i],Photon_seediPhiOriY[i],Photon_seediEtaOriX[i],Photon_pfRelIso03_chg_quadratic[i], Photon_pfRelIso03_all_quadratic[i], Photon_r9[i], Photon_energyErr[i], Photon_energyRaw[i], false});

        */
        if (Photon_pt[i] <= 25) continue;   
        if (fabs(Photon_eta[i]) >= 2.5) continue;  
            // if (fabs(Photon_eta[i]) > 1.442 && fabs(Photon_eta[i]) < 1.566) continue;       
         
       // add preselections 
        if (Photon_r9[i] < 0.8 && Photon_pfRelIso03_chg_quadratic[i] > 0.3 && Photon_pfRelIso03_chg_quadratic[i]*Photon_pt[i]>20) continue;
        if (Photon_hoe[i] > 0.08) continue;
        if (Photon_mvaID[i] <= -0.9) continue;
        if (Photon_electronVeto[i]) continue; // inverted veto to select photons that are electrons
        pass_phoIso_rho_corr_EB = (
            ((fabs(Photon_eta[i]) > 0.0) && (fabs(Photon_eta[i]) < 1.0))
            && (
                Photon_pfPhoIso03[i] - (rho * EA1_EB1) - (rho * rho * EA2_EB1)
                < max_pho_iso_EB_low_r9
            )
        ) || (
            ((fabs(Photon_eta[i]) > 1.0) && (fabs(Photon_eta[i]) < 1.4442))
            && (
                Photon_pfPhoIso03[i] - (rho * EA1_EB2) - (rho * rho * EA2_EB2)
                < max_pho_iso_EB_low_r9
            )
        );
	pass_phoIso_rho_corr_EE = (
            (
                ((fabs(Photon_eta[i]) > 1.566) && (fabs(Photon_eta[i]) < 2.0))
                && (
                    Photon_pfPhoIso03[i]
                    - (rho * EA1_EE1)
                    - (rho * rho * EA2_EE1)
                    < max_pho_iso_EE_low_r9
                )
            )
            || (
                ((fabs(Photon_eta[i]) > 2.0) && (fabs(Photon_eta[i]) < 2.2))
                && (
                    Photon_pfPhoIso03[i]
                    - (rho * EA1_EE2)
                    - (rho * rho * EA2_EE2)
                    < max_pho_iso_EE_low_r9
                )
            )
            || (
                ((fabs(Photon_eta[i]) > 2.2) && (fabs(Photon_eta[i]) < 2.3))
                && (
                    Photon_pfPhoIso03[i]
                    - (rho * EA1_EE3)
                    - (rho * rho * EA2_EE3)
                    < max_pho_iso_EE_low_r9
                )
            )
            || (
                ((fabs(Photon_eta[i]) > 2.3) && (fabs(Photon_eta[i]) < 2.4))
                && (
                    Photon_pfPhoIso03[i]
                    - (rho * EA1_EE4)
                    - (rho * rho * EA2_EE4)
                    < max_pho_iso_EE_low_r9
                )
            )
            || (
                ((fabs(Photon_eta[i]) > 2.4) && (fabs(Photon_eta[i]) < 2.5))
                && (
                    Photon_pfPhoIso03[i]
                    - (rho * EA1_EE5)
                    - (rho * rho * EA2_EE5)
                    < max_pho_iso_EE_low_r9
                )
            )
        );
        isEB_high_r9 = ((Photon_isScEtaEB[i]) && (Photon_r9[i] > min_full5x5_r9_EB_high_r9));
	isEE_high_r9 = ((Photon_isScEtaEE[i]) && (Photon_r9[i] > min_full5x5_r9_EE_high_r9));
        isEB_low_r9 = (
         (Photon_isScEtaEB[i])
         && (Photon_r9[i] > min_full5x5_r9_EB_low_r9)
         && (Photon_r9[i] < min_full5x5_r9_EB_high_r9)
         && (Photon_trkSumPtHollowConeDR03[i] < 6.0)
         && (Photon_sieie[i] < max_sieie_EB_low_r9)
         && (pass_phoIso_rho_corr_EB)
        );
        isEE_low_r9 = (
         (Photon_isScEtaEE[i])
         && (Photon_r9[i] > min_full5x5_r9_EE_low_r9)
         && (Photon_r9[i] < min_full5x5_r9_EE_high_r9)
         && (Photon_trkSumPtHollowConeDR03[i] < 6.0)
         && (Photon_sieie[i] < max_sieie_EE_low_r9)
         && (pass_phoIso_rho_corr_EE)
        );

        pho_r9 = (isEE_low_r9 || isEE_high_r9 || isEB_low_r9 || isEB_high_r9);
	pho_ScEta = (Photon_isScEtaEB[i] || Photon_isScEtaEE[i]);


        if (!(pho_r9&&pho_ScEta)) continue;
	
        // Only for Fake-Fake samples, 
	// Remove this for other samlpes 
//	for (int k=0; k<nGenPart; k++){
  //          if (GenPart_pdgId[k]==22 && deltaR(Photon_eta[i], Photon_phi[i], GenPart_eta[k], GenPart_phi[k]) < 0.1 && (0.85*GenPart_pt[k]<Photon_pt[i]) && (GenPart_pt[k]*1.05>Photon_pt[i])){
    //          pho1QCD_realMatched = 1;
  //          }
//	}
     //   if (pho1QCD_realMatched == 1) continue;


	photons.push_back({Photon_pt[i],Photon_eta[i],Photon_phi[i],Photon_mvaID[i],Photon_seediPhiOriY[i],Photon_seediEtaOriX[i],Photon_pfRelIso03_chg_quadratic[i], Photon_pfRelIso03_all_quadratic[i], Photon_r9[i], Photon_energyErr[i], Photon_energyRaw[i], false});
      

      } // end Photon loop  
	
      processPhoton(photons);

      for (int i=0; i<photons.size(); i++){
        
	if (photons.size()==1 || (photons[i].bT==true && photons[i].pt>pho1Pt)){
	
	  pho1Pt = photons[i].pt;
          pho1Eta = photons[i].eta;
          pho1Phi = photons[i].phi;
          pho1R9 = photons[i].r9;
          pho1ChIso = photons[i].pfRelIso03_chg_quadratic;
          pho1_mvaID = photons[i].mva;
          pho1_energyErr = photons[i].energyErr;
          pho1_energyRaw = photons[i].energyRaw;
          pho1_seediPhiOriY = photons[i].iPhiOriY;
          pho1_seediEtaOriX = photons[i].iEtaOriX;
          pho1_pfRelIso03_all_quadratic = photons[i].pfRelIso03_all_quadratic;
	
	}else if(photons[i].bT==true) {
	  pho2Pt = photons[i].pt;
          pho2Eta = photons[i].eta;
          pho2Phi = photons[i].phi;
          pho2R9 = photons[i].r9;
          pho2ChIso = photons[i].pfRelIso03_chg_quadratic;
          pho2_mvaID = photons[i].mva;
          pho2_energyErr = photons[i].energyErr;
          pho2_energyRaw = photons[i].energyRaw;
          pho2_seediPhiOriY = photons[i].iPhiOriY;
          pho2_seediEtaOriX = photons[i].iEtaOriX;
          pho2_pfRelIso03_all_quadratic = photons[i].pfRelIso03_all_quadratic;
	}
      }
	
      if (!isData) {
          for (int i=0; i<nGenPart; i++){
            if (GenPart_pdgId[i]==22 && deltaR(pho1Eta,pho1Phi, GenPart_eta[i], GenPart_phi[i]) < 0.1 && (0.85*GenPart_pt[i]<pho1Pt) && (GenPart_pt[i]*1.1>pho1Pt)){
	      Matched_genpho1Pt = GenPart_pt[i];
              pho1QCD_realMatched = 1;
	    }  
	    if (GenPart_pdgId[i]==22 && deltaR(pho2Eta,pho2Phi, GenPart_eta[i], GenPart_phi[i]) < 0.1 && (0.85*GenPart_pt[i]<pho2Pt) && (GenPart_pt[i]*1.1>pho2Pt)){
	      Matched_genpho2Pt = GenPart_pt[i];
	      pho2QCD_realMatched = 1;
	    }
          }
      }

      TLorentzVector g1;
      TLorentzVector g2;
      if (pho1Pt>0 && pho2Pt>0){
        g1.SetPtEtaPhiM(pho1Pt,pho1Eta,pho1Phi,0);
        g2.SetPtEtaPhiM(pho2Pt,pho2Eta,pho2Phi,0);
        Diphoton_Mass = (g1+g2).M();
        Diphoton_Pt = (g1+g2).Pt();
        Diphoton_Eta = (g1+g2).Eta();
	Diphoton_Phi = (g1+g2).Phi();
      }
      //------------------------------
      //-------find fatJet------------
      //------------------------------
      vector<int> selectedFatJetIndices;

      for(unsigned int i = 0; i < nFatJet; i++ ) {       
        //Hbb fat jet pre-selection
        if (FatJet_pt[i] < 250) continue;
        if (deltaR(FatJet_eta[i], FatJet_phi[i], pho1Eta, pho1Phi) < 0.8) continue;
        if (deltaR(FatJet_eta[i], FatJet_phi[i], pho2Eta, pho2Phi) < 0.8) continue;
	if (fabs(FatJet_eta[i])>=4.7) continue; 
     // if (FatJet_particleNet_XbbVsQCD[i]<0.4) continue;
        if (Option == 10) {
          if (!(FatJet_tau3[i] / FatJet_tau2[i] < 0.54 )) continue; 
        }
        selectedFatJetIndices.push_back(i);
      }      


      //------------------------------------------------------
      //----------select the two H candidates with largest Xbb
      //------------------------------------------------------
      int fatJet1Index = -1;
      int fatJet2Index = -1;
      double tmpfatJet1Pt = -999;
      double tmpfatJet2Pt = -999;
      double tmpfatJet1Tagger = -999;
      double tmpfatJet2Tagger = -999;
        
      int vbffatJet1Index = -1;
      int vbffatJet2Index = -1;
      double tmpvbffatJet1Pt = -999;
      double tmpvbffatJet2Pt = -999;
        
      if (Option <= 10) {
	for(unsigned int i = 0; i < selectedFatJetIndices.size(); i++ ) {
          double fatJetTagger = 0;
          fatJetTagger = FatJet_particleNet_XbbVsQCD[selectedFatJetIndices[i]];
	  if (fatJetTagger > tmpfatJet1Tagger) {
	    tmpfatJet2Tagger = tmpfatJet1Tagger;
	    fatJet2Index = fatJet1Index;	  
	    tmpfatJet1Tagger = fatJetTagger;
	    fatJet1Index = selectedFatJetIndices[i];
	  } else if (fatJetTagger > tmpfatJet2Tagger) {
	    tmpfatJet2Tagger = fatJetTagger;
	    fatJet2Index = selectedFatJetIndices[i];
	  }
        
          //fat jet used in the VBF HH->4b analysis
//	  if (FatJet_pt[selectedFatJetIndices[i]] > tmpvbffatJet1Pt) {
//	    tmpvbffatJet2Pt = vbffatJet1Pt;
//	    vbffatJet2Index = vbffatJet1Index;	  
//	    tmpvbffatJet1Pt = FatJet_pt[selectedFatJetIndices[i]];
//	    vbffatJet1Index = selectedFatJetIndices[i];
//	  } else if ( FatJet_pt[selectedFatJetIndices[i]] > tmpvbffatJet2Pt ) {
//	    tmpvbffatJet2Pt = FatJet_pt[selectedFatJetIndices[i]];
//	    vbffatJet2Index = selectedFatJetIndices[i];
//	  } 
	}
       // vbffatJet1Pt = FatJet_pt[vbffatJet1Index];
       // vbffatJet1Eta = FatJet_eta[vbffatJet1Index];
       // vbffatJet1Phi = FatJet_phi[vbffatJet1Index];
       // vbffatJet1PNetXbb = FatJet_particleNet_XbbVsQCD[vbffatJet1Index];
       // vbffatJet2PNetXbb = FatJet_particleNet_XbbVsQCD[vbffatJet2Index];
       // vbffatJet2Pt = FatJet_pt[vbffatJet2Index];
       // vbffatJet2Eta = FatJet_eta[vbffatJet2Index];
       // vbffatJet2Phi = FatJet_phi[vbffatJet2Index];

      } else if (Option == 20 || Option == 21) {
	for(unsigned int i = 0; i < selectedFatJetIndices.size(); i++ ) {
	  if (FatJet_pt[selectedFatJetIndices[i]] > tmpfatJet1Pt) {
	    tmpfatJet2Pt = fatJet1Pt;
	    fatJet2Index = fatJet1Index;	  
	    tmpfatJet1Pt = FatJet_pt[selectedFatJetIndices[i]];
	    fatJet1Index = selectedFatJetIndices[i];
	  } else if ( FatJet_pt[selectedFatJetIndices[i]] > tmpfatJet2Pt ) {
	    tmpfatJet2Pt = FatJet_pt[selectedFatJetIndices[i]];
	    fatJet2Index = selectedFatJetIndices[i];
	  }
	}
      }

      


      //------------------------------------------------------
      //----------look for presence of a third AK8 jet
      //------------------------------------------------------
      int fatJet3Index = -1;
      //double tmpfatJet3Pt = -999;
      double tmpfatJet3Tagger = -999;
      for(unsigned int i = 0; i < nFatJet; i++ ) {  
        double fatJetTagger = 0;
	fatJetTagger = FatJet_particleNet_XbbVsQCD[i];
        if (deltaR(FatJet_eta[i], FatJet_phi[i], pho1Eta, pho1Phi) < 0.8) continue;
        if (deltaR(FatJet_eta[i], FatJet_phi[i], pho2Eta, pho2Phi) < 0.8) continue;
        if (fabs(FatJet_eta[i])>=4.7) continue;
	//Hbb fat jet pre-selection
	if (FatJet_pt[i] < 250) continue;
	if (i == fatJet1Index || i == fatJet2Index) continue;
	if (fatJetTagger > tmpfatJet3Tagger) {
	  fatJet3Index = i;
	  //tmpfatJet3Pt = FatJet_pt[i];
	  tmpfatJet3Tagger = fatJetTagger;
	}
      }

      //------------------------------------------------------
      //----------Fill higgs candidate information
      //------------------------------------------------------
   
      fatJet1Pt = FatJet_pt[fatJet1Index];
      fatJet1Eta = FatJet_eta[fatJet1Index];
      fatJet1Phi                = FatJet_phi[fatJet1Index];
      fatJet1Mass               = FatJet_mass[fatJet1Index];
      fatJet1MassSD_UnCorrected = FatJet_msoftdrop[fatJet1Index];
      fatJet1MassSD = jmsValues[0]*fatJet1MassSD_UnCorrected;//correct, mass scale and resolution, for resolution subtract 1.0 from width

      //For MC apply jet energy and mass corrections
      if (!isData){
//	jecUnc->setJetEta(fatJet1Eta);
//	jecUnc->setJetPt(fatJet1Pt);
//	double unc = jecUnc->getUncertainty(true);
//	fatJet1Pt_JES_Up   = fatJet1Pt*(1+unc);
//	fatJet1Pt_JES_Down = fatJet1Pt/(1+unc);
	fatJet1MassSD             = ( 1.0 + corr_fatJet1_mass )*jmsValues[0]*fatJet1MassSD_UnCorrected;//correct, mass scale and resolution, for resolution subtract 1.0 from width
	fatJet1MassSD_JMS_Down    = (jmsValues[1]/jmsValues[0])*fatJet1MassSD;//jet mass scale down
	fatJet1MassSD_JMS_Up      = (jmsValues[2]/jmsValues[0])*fatJet1MassSD;//jrt mass scale up
	fatJet1MassSD_JMR_Down    = ( 1.0 + corr_fatJet1_mass_JMRDown )*jmsValues[0]*fatJet1MassSD_UnCorrected;//jet mass resolution down -- wrt scale corrected value -- for resolution subtract 1.0 from width
	fatJet1MassSD_JMR_Up      = ( 1.0 + corr_fatJet1_mass_JMRUp )*jmsValues[0]*fatJet1MassSD_UnCorrected;//jrt mass resolution up -- wrt to scale corrected value -- for resolution subtract 1.0 from width
      }
      fatJet1DDBTagger = FatJet_btagDDBvLV2[fatJet1Index];
      fatJet1PNetXbb = FatJet_particleNet_XbbVsQCD[fatJet1Index];
      fatJet1PNetXcc = FatJet_particleNet_XccVsQCD[fatJet1Index];
      fatJet1PNetXqq = FatJet_particleNet_XqqVsQCD[fatJet1Index];
      fatJet1PNetQCD = FatJet_particleNet_QCD[fatJet1Index];
      fatJet1Tau3OverTau2 = FatJet_tau3[fatJet1Index] /  FatJet_tau2[fatJet1Index];
      fatJet1_n2b1 = FatJet_n2b1[fatJet1Index];


      //****************************************
      //Define Higgs Jet TLorentzVectors
      //****************************************
      TLorentzVector Higgs1Jet;
      Higgs1Jet.SetPtEtaPhiM(fatJet1Pt,fatJet1Eta,fatJet1Phi,fatJet1MassSD_UnCorrected);
      float Higgs1MinDR = 999.;
      int Higgs1_match_idx = -1;
      for( int j = 0; j < genHiggsVector.size(); j++) {
	if(Higgs1Jet.DeltaR(genHiggsVector[j]) < Higgs1MinDR) {
	  Higgs1MinDR = Higgs1Jet.DeltaR(genHiggsVector[j]);
	  Higgs1_match_idx = j;
	}
      }
      if(Higgs1MinDR < 0.4) {
	fatJet1GenMatchIndex = Higgs1_match_idx;
      }
      TLorentzVector Higgs1Jet_JESUp;
      Higgs1Jet_JESUp.SetPtEtaPhiM(fatJet1Pt_JES_Up,fatJet1Eta,fatJet1Phi,fatJet1MassSD);
      TLorentzVector Higgs1Jet_JESDown;
      Higgs1Jet_JESDown.SetPtEtaPhiM(fatJet1Pt_JES_Down,fatJet1Eta,fatJet1Phi,fatJet1MassSD);
      TLorentzVector Higgs1Jet_JMSUp;
      Higgs1Jet_JMSUp.SetPtEtaPhiM(fatJet1Pt,fatJet1Eta,fatJet1Phi,fatJet1MassSD_JMS_Up);
      TLorentzVector Higgs1Jet_JMSDown;
      Higgs1Jet_JMSDown.SetPtEtaPhiM(fatJet1Pt,fatJet1Eta,fatJet1Phi,fatJet1MassSD_JMS_Down);
      TLorentzVector Higgs1Jet_JMRUp;
      Higgs1Jet_JMRUp.SetPtEtaPhiM(fatJet1Pt,fatJet1Eta,fatJet1Phi,fatJet1MassSD_JMR_Up);
      TLorentzVector Higgs1Jet_JMRDown;
      Higgs1Jet_JMRDown.SetPtEtaPhiM(fatJet1Pt,fatJet1Eta,fatJet1Phi,fatJet1MassSD_JMR_Down);


      //find any bjets in opposite hemisphere as fatJet1
      double btagMediumCut = -1;
      //if (year == "2016") btagMediumCut = 0.3033;
      //else if (year == "2017") btagMediumCut = 0.3033 ;
      //else if (year == "2018") btagMediumCut = 0.2770 ;
      if (year == "2022" || year == "2022EE") btagMediumCut = 0.2605 ;
      for(unsigned int q = 0; q < nJet; q++ ) {       
	if (Jet_pt[q] > 25 && Jet_btagPNetB[q] > btagMediumCut && 
	    deltaPhi(fatJet1Phi, Jet_phi[q]) > 2.5
	    ) {
	  fatJet1OppositeHemisphereHasBJet = true;
	  break;
	}
      }
	

      //find muon inside jet
      for(unsigned int q = 0; q < nMuon; q++ ) {       
	if (Muon_pt[q] > 30 && Muon_looseId[q] && 
	    deltaR(fatJet1Eta , fatJet1Phi, Muon_eta[q], Muon_phi[q]) < 1.0
	    ) {
	  fatJet1HasMuon = true;
	  break;
	}
      }
      //find electron inside jet
      for(unsigned int q = 0; q < nElectron; q++ ) {       
	if (Electron_pt[q] > 30 && Electron_mvaNoIso_WP90[q] && 
	    deltaR(fatJet1Eta , fatJet1Phi, Electron_eta[q], Electron_phi[q]) < 1.0
	    ) {
	  fatJet1HasElectron = true;
	  break;
	}
      }
      //find loose b-tagged jet inside jet
      for(unsigned int q = 0; q < nJet; q++ ) {       
	if (Jet_btagPNetB[q] > 0.0521 && 
	    deltaR(fatJet1Eta , fatJet1Phi, Jet_eta[q], Jet_phi[q]) < 1.0
	    ) {
	  fatJet1HasBJetCSVLoose = true;
	  break;
	}
      }
     //find medium b-tagged jet inside jet
      for(unsigned int q = 0; q < nJet; q++ ) {       
	if (Jet_btagPNetB[q] > 0.3033 && 
	    deltaR(fatJet1Eta , fatJet1Phi, Jet_eta[q], Jet_phi[q]) < 1.0
	    ) {
	  fatJet1HasBJetCSVMedium = true;
	  break;
	}
      }
      //find tight b-tagged jet inside jet
      for(unsigned int q = 0; q < nJet; q++ ) {       
	if (Jet_btagPNetB[q] > 0.7489 && 
	    deltaR(fatJet1Eta , fatJet1Phi, Jet_eta[q], Jet_phi[q]) < 1.0
	    ) {
	  fatJet1HasBJetCSVTight = true;
	  break;
	}
      }



      fatJet2Pt = FatJet_pt[fatJet2Index];
      fatJet2Eta = FatJet_eta[fatJet2Index];
      fatJet2Phi                = FatJet_phi[fatJet2Index];
      fatJet2Mass               = FatJet_mass[fatJet2Index];
      fatJet2MassSD_UnCorrected = FatJet_msoftdrop[fatJet2Index];
      fatJet2MassSD             = jmsValues[0]*fatJet2MassSD_UnCorrected;//correct, mass scale and resolution, for resolution subtract 1.0 from width

     //For MC apply jet energy and mass corrections
      if ( !isData ) {
//	jecUnc->setJetEta(fatJet2Eta);
//	jecUnc->setJetPt(fatJet2Pt);
//	double unc                = jecUnc->getUncertainty(true);
//	fatJet2Pt_JES_Up   = fatJet2Pt*(1+unc);
//	fatJet2Pt_JES_Down = fatJet2Pt/(1+unc);
        fatJet2MassSD             = ( 1.0 + corr_fatJet2_mass )*jmsValues[0]*fatJet2MassSD_UnCorrected;//correct, mass scale and resolution, for resolution subtract 1.0 from width
	fatJet2MassSD_JMS_Down    = (jmsValues[1]/jmsValues[0])*fatJet2MassSD;//jet mass scale down
	fatJet2MassSD_JMS_Up      = (jmsValues[2]/jmsValues[0])*fatJet2MassSD;//jrt mass scale up
	fatJet2MassSD_JMR_Down    = ( 1.0 + corr_fatJet2_mass_JMRDown )*jmsValues[0]*fatJet2MassSD_UnCorrected;//jet mass resolution down -- wrt scale corrected value -- for resolution subtract 1.0 from width
	fatJet2MassSD_JMR_Up      = ( 1.0 + corr_fatJet2_mass_JMRUp )*jmsValues[0]*fatJet2MassSD_UnCorrected;//jrt mass resolution up -- wrt to scale corrected value -- for resolution subtract 1.0 from width
      }
     
      fatJet2DDBTagger = FatJet_btagDDBvLV2[fatJet2Index];
      fatJet2PNetXbb = FatJet_particleNet_XbbVsQCD[fatJet2Index];
      fatJet2PNetXcc = FatJet_particleNet_XccVsQCD[fatJet2Index];
      fatJet2PNetXqq = FatJet_particleNet_XqqVsQCD[fatJet2Index];
      fatJet2PNetQCD = FatJet_particleNet_QCD[fatJet2Index]; 
      fatJet2Tau3OverTau2 = FatJet_tau3[fatJet2Index] /  FatJet_tau2[fatJet2Index];
    
      TLorentzVector Higgs2Jet;
      Higgs2Jet.SetPtEtaPhiM(FatJet_pt[fatJet2Index],FatJet_eta[fatJet2Index],FatJet_phi[fatJet2Index],FatJet_msoftdrop[fatJet2Index]);
      float Higgs2MinDR = 999.;
      int Higgs2_match_idx = -1;
      for( int j = 0; j < genHiggsVector.size(); j++) {
	if(Higgs2Jet.DeltaR(genHiggsVector[j]) < Higgs2MinDR) {
	  Higgs2MinDR = Higgs2Jet.DeltaR(genHiggsVector[j]);
	  Higgs2_match_idx = j;
	}
      }
      if(Higgs2MinDR < 0.4) {
	fatJet2GenMatchIndex = Higgs2_match_idx;
      }
      TLorentzVector Higgs2Jet_JESUp;
      Higgs2Jet_JESUp.SetPtEtaPhiM(fatJet2Pt_JES_Up,fatJet2Eta,fatJet2Phi,fatJet2MassSD);
      TLorentzVector Higgs2Jet_JESDown;
      Higgs2Jet_JESDown.SetPtEtaPhiM(fatJet2Pt_JES_Down,fatJet2Eta,fatJet2Phi,fatJet2MassSD);
      TLorentzVector Higgs2Jet_JMSUp;
      Higgs2Jet_JMSUp.SetPtEtaPhiM(fatJet2Pt,fatJet2Eta,fatJet2Phi,fatJet2MassSD_JMS_Up);
      TLorentzVector Higgs2Jet_JMSDown;
      Higgs2Jet_JMSDown.SetPtEtaPhiM(fatJet2Pt,fatJet2Eta,fatJet2Phi,fatJet2MassSD_JMS_Down);
      TLorentzVector Higgs2Jet_JMRUp;
      Higgs2Jet_JMRUp.SetPtEtaPhiM(fatJet2Pt,fatJet2Eta,fatJet2Phi,fatJet2MassSD_JMR_Up);
      TLorentzVector Higgs2Jet_JMRDown;
      Higgs2Jet_JMRDown.SetPtEtaPhiM(fatJet2Pt,fatJet2Eta,fatJet2Phi,fatJet2MassSD_JMR_Down);

       
      //find muon inside jet
      for(unsigned int q = 0; q < nMuon; q++ ) {       
	if (Muon_pt[q] > 30 && Muon_looseId[q] && 
	    deltaR(fatJet2Eta , fatJet2Phi, Muon_eta[q], Muon_phi[q]) < 1.0
	    ) {
	  fatJet2HasMuon = true;
	  break;
	}
      }
      //find electron inside jet
      for(unsigned int q = 0; q < nElectron; q++ ) {       
	if (Electron_pt[q] > 30 && Electron_mvaNoIso_WP90[q] && 
	    deltaR(fatJet2Eta , fatJet2Phi, Electron_eta[q], Electron_phi[q]) < 1.0
	    ) {
	  fatJet2HasElectron = true;
	  break;
	}
      }
      //find loose b-tagged jet inside jet
      for(unsigned int q = 0; q < nJet; q++ ) {       
	if (Jet_btagPNetB[q] > 0.0521 && 
	    deltaR(fatJet2Eta , fatJet2Phi, Jet_eta[q], Jet_phi[q]) < 1.0
	    ) {
	  fatJet2HasBJetCSVLoose = true;
	  break;
	}
      }
      //find medium b-tagged jet inside jet
      for(unsigned int q = 0; q < nJet; q++ ) {       
	if (Jet_btagPNetB[q] > 0.3033 && 
	    deltaR(fatJet2Eta , fatJet2Phi, Jet_eta[q], Jet_phi[q]) < 1.0
	    ) {
	  fatJet2HasBJetCSVMedium = true;
	  break;
	}
      }
      //find tight b-tagged jet inside jet
      for(unsigned int q = 0; q < nJet; q++ ) {       
	if (Jet_btagPNetB[q] > 0.7489 && 
	    deltaR(fatJet2Eta , fatJet2Phi, Jet_eta[q], Jet_phi[q]) < 1.0
	    ) {
	  fatJet2HasBJetCSVTight = true;
	  break;
	}
      }


      //------------------------------------------------------
      //----------Fill Jet 3 information
      //------------------------------------------------------
      fatJet3Pt = FatJet_pt[fatJet3Index];
      fatJet3Eta = FatJet_eta[fatJet3Index];
      fatJet3Phi                = FatJet_phi[fatJet3Index];
      fatJet3Mass               = FatJet_mass[fatJet3Index];
      fatJet3MassSD_UnCorrected = FatJet_msoftdrop[fatJet3Index];
      fatJet3MassSD             = jmsValues[0]*fatJet3MassSD_UnCorrected;//correct, mass scale and resolution, for resolution subtract 1.0 from width
      if ( !isData ) {
  //        jecUnc->setJetEta(fatJet3Eta);
    //      jecUnc->setJetPt(fatJet3Pt);
     //     double unc                = jecUnc->getUncertainty(true);
     //     fatJet3Pt_JES_Up   = fatJet3Pt*(1+unc);
     //     fatJet3Pt_JES_Down = fatJet3Pt/(1+unc);
	  fatJet3MassSD             = ( 1.0 + corr_fatJet3_mass )*jmsValues[0]*fatJet3MassSD_UnCorrected;//correct, mass scale and resolution, for resolution subtract 1.0 from width
	  fatJet3MassSD_JMS_Down    = (jmsValues[1]/jmsValues[0])*fatJet3MassSD;//jet mass scale down
	  fatJet3MassSD_JMS_Up      = (jmsValues[2]/jmsValues[0])*fatJet3MassSD;//jrt mass scale up
	  fatJet3MassSD_JMR_Down    = ( 1.0 + corr_fatJet3_mass_JMRDown )*jmsValues[0]*fatJet3MassSD_UnCorrected;//jet mass resolution down -- wrt scale corrected value -- for resolution subtract 1.0 from width
	  fatJet3MassSD_JMR_Up      = ( 1.0 + corr_fatJet3_mass_JMRUp )*jmsValues[0]*fatJet3MassSD_UnCorrected;//jrt mass resolution up -- wrt to scale corrected value -- for resolution subtract 1.0 from width
      }
      fatJet3DDBTagger = FatJet_btagDDBvLV2[fatJet3Index];
      fatJet3PNetXbb = FatJet_particleNet_XbbVsQCD[fatJet3Index];
      fatJet3PNetXcc = FatJet_particleNet_XccVsQCD[fatJet3Index];
      fatJet3PNetXqq = FatJet_particleNet_XqqVsQCD[fatJet3Index];
  
      fatJet3PNetQCD = FatJet_particleNet_QCD[fatJet3Index];
      fatJet3Tau3OverTau2 = FatJet_tau3[fatJet3Index] /  FatJet_tau2[fatJet3Index];
      //find muon inside jet
      for(unsigned int q = 0; q < nMuon; q++ ) {       
	if (Muon_pt[q] > 30 && Muon_looseId[q] && 
	    deltaR(fatJet3Eta , fatJet3Phi, Muon_eta[q], Muon_phi[q]) < 1.0
	    ) {
	  fatJet3HasMuon = true;
	  break;
	}
      }
      //find electron inside jet
      for(unsigned int q = 0; q < nElectron; q++ ) {       
	if (Electron_pt[q] > 30 && Electron_mvaNoIso_WP90[q] && 
	    deltaR(fatJet3Eta , fatJet3Phi, Electron_eta[q], Electron_phi[q]) < 1.0
	    ) {
	  fatJet3HasElectron = true;
	  break;
	}
      }
      //find loose b-tagged jet inside jet
      for(unsigned int q = 0; q < nJet; q++ ) {       
	if (Jet_btagPNetB[q] > 0.0521 && 
	    deltaR(fatJet3Eta , fatJet3Phi, Jet_eta[q], Jet_phi[q]) < 1.0
	    ) {
	  fatJet3HasBJetCSVLoose = true;
	  break;
	}
      }
     //find medium b-tagged jet inside jet
      for(unsigned int q = 0; q < nJet; q++ ) {       
	if (Jet_btagPNetB[q] > 0.3033 && 
	    deltaR(fatJet3Eta , fatJet3Phi, Jet_eta[q], Jet_phi[q]) < 1.0
	    ) {
	  fatJet3HasBJetCSVMedium = true;
	  break;
	}
      }
      //find tight b-tagged jet inside jet
      for(unsigned int q = 0; q < nJet; q++ ) {       
	if (Jet_btagPNetB[q] > 0.7489 && 
	    deltaR(fatJet3Eta , fatJet3Phi, Jet_eta[q], Jet_phi[q]) < 1.0
	    ) {
	  fatJet3HasBJetCSVTight = true;
	  break;
	}
      }


      //------------------------------------------------------
      //----------Fill hh candidate information
      //------------------------------------------------------
      hh_pt = (Higgs1Jet+Higgs2Jet).Pt();
      hh_eta = (Higgs1Jet+Higgs2Jet).Eta();
      hh_phi = (Higgs1Jet+Higgs2Jet).Phi();
      hh_mass = (Higgs1Jet+Higgs2Jet).M();     
      fatJet1PtOverMHH = fatJet1Pt / hh_mass;
      fatJet1PtOverMSD = fatJet1Pt / fatJet1MassSD;
      fatJet2PtOverMHH = fatJet2Pt / hh_mass;
      fatJet2PtOverMSD = fatJet2Pt / fatJet1MassSD;

      if ( !isData ) {
	hh_pt_JESUp = (Higgs1Jet_JESUp+Higgs2Jet_JESUp).Pt();
	hh_pt_JESDown = (Higgs1Jet_JESDown+Higgs2Jet_JESDown).Pt();
	hh_pt_JMSUp = (Higgs1Jet_JMSUp+Higgs2Jet_JMSUp).Pt();
	hh_pt_JMSDown = (Higgs1Jet_JMSDown+Higgs2Jet_JMSDown).Pt();
	hh_pt_JMRUp = (Higgs1Jet_JMRUp+Higgs2Jet_JMRUp).Pt();
	hh_pt_JMRDown = (Higgs1Jet_JMRDown+Higgs2Jet_JMRDown).Pt();
	hh_eta_JESUp = (Higgs1Jet_JESUp+Higgs2Jet_JESUp).Eta();
	hh_eta_JESDown = (Higgs1Jet_JESDown+Higgs2Jet_JESDown).Eta();
	hh_eta_JMSUp = (Higgs1Jet_JMSUp+Higgs2Jet_JMSUp).Eta();
	hh_eta_JMSDown = (Higgs1Jet_JMSDown+Higgs2Jet_JMSDown).Eta();
	hh_eta_JMRUp = (Higgs1Jet_JMRUp+Higgs2Jet_JMRUp).Eta();
	hh_eta_JMRDown = (Higgs1Jet_JMRDown+Higgs2Jet_JMRDown).Eta();
	hh_mass_JESUp = (Higgs1Jet_JESUp+Higgs2Jet_JESUp).M();
	hh_mass_JESDown = (Higgs1Jet_JESDown+Higgs2Jet_JESDown).M();
	hh_mass_JMSUp = (Higgs1Jet_JMSUp+Higgs2Jet_JMSUp).M();
	hh_mass_JMSDown = (Higgs1Jet_JMSDown+Higgs2Jet_JMSDown).M();
	hh_mass_JMRUp = (Higgs1Jet_JMRUp+Higgs2Jet_JMRUp).M();
	hh_mass_JMRDown = (Higgs1Jet_JMRDown+Higgs2Jet_JMRDown).M();  
	fatJet1PtOverMHH_JESUp = fatJet1Pt_JES_Up / hh_mass_JESUp;
	fatJet1PtOverMHH_JESDown = fatJet1Pt_JES_Down / hh_mass_JESDown;
	fatJet1PtOverMHH_JMSUp = fatJet1Pt / hh_mass_JMSUp;
	fatJet1PtOverMHH_JMSDown = fatJet1Pt / hh_mass_JMSDown;
	fatJet1PtOverMHH_JMRUp = fatJet1Pt / hh_mass_JMRUp;
	fatJet1PtOverMHH_JMRDown = fatJet1Pt / hh_mass_JMRDown;
	fatJet2PtOverMHH_JESUp = fatJet2Pt_JES_Up / hh_mass_JESUp;
	fatJet2PtOverMHH_JESDown = fatJet2Pt_JES_Down / hh_mass_JESDown;
	fatJet2PtOverMHH_JMSUp = fatJet2Pt / hh_mass_JMSUp;
	fatJet2PtOverMHH_JMSDown = fatJet2Pt / hh_mass_JMSDown;
	fatJet2PtOverMHH_JMRUp = fatJet2Pt / hh_mass_JMRUp;
	fatJet2PtOverMHH_JMRDown = fatJet2Pt / hh_mass_JMRDown;	
      }

      deltaEta_j1j2 = fabs(fatJet1Eta - fatJet2Eta);
      deltaPhi_j1j2 = deltaPhi(fatJet1Phi, fatJet2Phi);
      deltaR_j1j2 = deltaR(fatJet1Eta, fatJet1Phi, fatJet2Eta, fatJet2Phi);
      ptj2_over_ptj1 = fatJet2Pt / fatJet1Pt;
      mj2_over_mj1 = fatJet2MassSD / fatJet1MassSD;             

      //------------------------------------------------------
      //----------Find Leptons
      //------------------------------------------------------     
      for(unsigned int i = 0; i < nMuon; i++ ) {       

	if (Muon_pt[i] <= 10) continue;
	if (fabs(Muon_eta[i]) >= 2.4) continue;
//if (Muon_miniPFRelIso_all[i] > 0.2) continue;
	if (!Muon_mediumId[i]) continue;
        if (deltaR(Muon_eta[i], Muon_phi[i], pho1Eta, pho1Phi)<=0.2) continue;
	if (deltaR(Muon_eta[i], Muon_phi[i], pho2Eta, pho2Phi)<=0.2) continue;
	//if (deltaR(Muon_eta[i], Muon_phi[i], Diphoton_Eta, Diphoton_Pt)<=0.2) continue;

	if (lep1Id == 0) {
	  lep1Pt = Muon_pt[i];
	  lep1Eta = Muon_eta[i];
	  lep1Phi = Muon_phi[i];
	  lep1Id = Muon_charge[i] * (13);
	  lep1mva = Muon_mvaMuID[i];
	} else if (Muon_pt[i] > lep1Pt) {
	  lep2Pt = lep1Pt;
	  lep2Eta = lep1Eta;
	  lep2Phi = lep1Phi;
	  lep2Id = lep1Id;
	  lep2mva = lep1mva;

	  lep1Pt = Muon_pt[i];
	  lep1Eta = Muon_eta[i];
	  lep1Phi = Muon_phi[i];
	  lep1Id = Muon_charge[i] * (13);
	  lep1mva = Muon_mvaMuID[i];
	} else if (lep2Id == 0 || Muon_pt[i] > lep2Pt) {
	  lep2Pt = Muon_pt[i];
	  lep2Eta = Muon_eta[i];
	  lep2Phi = Muon_phi[i];
	  lep2Id = Muon_charge[i] * (13);
	  lep2mva = Muon_mvaMuID[i];
	} 
      } //loop over muons

      for(unsigned int i = 0; i < nElectron; i++ ) {       
        if (Electron_pt[i] <= 15) continue;
        if (fabs(Electron_eta[i]) >= 2.5) continue;
	if (!Electron_mvaIso_WP80[i]) continue;
        if (deltaR(Electron_eta[i], Electron_phi[i], pho1Eta, pho1Phi)<=0.2) continue;
        if (deltaR(Electron_eta[i], Electron_phi[i], pho2Eta, pho2Phi)<=0.2) continue;
	//if (deltaR(Electron_eta[i], Electron_phi[i], Diphoton_Eta, Diphoton_Pt)<=0.2) continue;
        //if (Electron_miniPFRelIso_all[i] > 0.2) continue;
        //if (!Electron_cutBased[i]) continue;
	if (lep1Id == 0) {
	  lep1Pt = Electron_pt[i];
	  lep1Eta = Electron_eta[i];
	  lep1Phi = Electron_phi[i];
	  lep1Id = Electron_charge[i] * (11);
	  lep1mva = Electron_mvaIso[i];
	} else if (Electron_pt[i] > lep1Pt) {
	  lep2Pt = lep1Pt;
	  lep2Eta = lep1Eta;
	  lep2Phi = lep1Phi;
	  lep2Id = lep1Id;
	  lep2mva = lep1mva;

	  lep1Pt = Electron_pt[i];
	  lep1Eta = Electron_eta[i];
	  lep1Phi = Electron_phi[i];
	  lep1Id = Electron_charge[i] * (11);
	  lep1mva = Electron_mvaIso[i];
	} else if (lep2Id == 0 || Electron_pt[i] > lep2Pt) {
	  lep2Pt = Electron_pt[i];
	  lep2Eta = Electron_eta[i];
	  lep2Phi = Electron_phi[i];
	  lep2Id = Electron_charge[i] * (11);
	  lep2mva = Electron_mvaIso[i];
	} 
      } //loop over electrons


    
      //*******************************
      //Count additional AK4 jets 
      //*******************************
      vector<int> vbfjets_index;
      vbfjets_index.clear();
      
      if (!isData){
        margin1 = 0.4;
        margin2 = 0.4;
        GenBJet1_idx = -1;
        GenBJet2_idx = -1;
        GenBJet3_idx = -1;
        GenBJet4_idx = -1;
        CloseBQuark = 0;
        for(int i = 0; i < nGenJet; i++) {
          // if (abs(GenJet_partonFlavour[i])!=5) continue;
          // if (deltaR(genbQuark1_Eta, genbQuark1_Phi, genbQuark2_Eta, genbQuark2_Phi) > 1.2){ 
            if (deltaR(GenJet_eta[i], GenJet_phi[i], genbQuark1_Eta, genbQuark1_Phi) < margin1){
              margin1 = deltaR(GenJet_eta[i], GenJet_phi[i], genbQuark1_Eta, genbQuark1_Phi);
              GenBJet1_Pt = GenJet_pt[i];
              GenBJet1_Eta = GenJet_eta[i];
              GenBJet1_Phi = GenJet_phi[i];
              GenBJet1_Mass = GenJet_mass[i];
              GenBJet1_idx = i;
            }else if (deltaR(GenJet_eta[i], GenJet_phi[i], genbQuark2_Eta, genbQuark2_Phi) < margin2){
              margin2 = deltaR(GenJet_eta[i], GenJet_phi[i], genbQuark2_Eta, genbQuark2_Phi);
              GenBJet2_Pt = GenJet_pt[i];
              GenBJet2_Eta = GenJet_eta[i];
              GenBJet2_Phi = GenJet_phi[i];
              GenBJet2_Mass = GenJet_mass[i];
              GenBJet2_idx = i;
            }
          // }else{
            // if (deltaR(GenJet_eta[i], GenJet_phi[i], tobbHiggs_Eta, tobbHiggs_Phi) < 1.6){
               // CloseBQuark++;
             // }
            // if (CloseBQuark == 1){
              // GenBJet3_Pt = GenJet_pt[i];
              // GenBJet3_Eta = GenJet_eta[i];
              // GenBJet3_Phi = GenJet_phi[i];
              // GenBJet3_Mass = GenJet_mass[i];
              // GenBJet3_idx = i;
            // }
            // if (CloseBQuark == 2){
              // GenBJet4_Pt = GenJet_pt[i];
              // GenBJet4_Eta = GenJet_eta[i];
              // GenBJet4_Phi = GenJet_phi[i];
              // GenBJet4_Mass = GenJet_mass[i];
              // GenBJet4_idx = i;
            // }
          // }
        }
      } //end !isData 

      std::vector<Jet> jets;
      /*
      jetCutflow->Fill(0);  
      if (nJet >= 2) {
          int ptPass = 0;
          int etaPass = 0;
          int dRPass = 0;
          for (int i = 0; i < nJet; i++) {
              bool passPt = Jet_pt[i] > 20;
              bool passEta = fabs(Jet_eta[i]) < 2.5;
              float dR1 = deltaR(Jet_eta[i], Jet_phi[i], pho1Eta, pho1Phi);
              float dR2 = deltaR(Jet_eta[i], Jet_phi[i], pho2Eta, pho2Phi);
              bool passDR = dR1 > 0.4 && dR2 > 0.4;
              if (passPt) ptPass++;
              if (passPt && passEta) etaPass++;
              if (passPt && passEta && passDR){
                dRPass++;
                jets.push_back({Jet_pt[i], Jet_btagPNetB[i], false, Jet_mass[i], Jet_eta[i], Jet_phi[i], Jet_PNetRegPtRawRes[i], Jet_PNetRegPtRawCorr[i], Jet_PNetRegPtRawCorrNeutrino[i]});                     
              }
          }
          if (ptPass >= 2) jetCutflow->Fill(1); 
          if (etaPass >= 2) jetCutflow->Fill(2);  
          if (dRPass >= 2)jetCutflow->Fill(3);  
      }
      std::sort(jets.begin(), jets.end(), [](const Jet& a, const Jet& b) {
          return a.pt > b.pt;
      });
      struct JetPair {
          int jet1_index;
          int jet2_index;
          double invariant_mass;
          double btag_sum;
      };
      std::vector<JetPair> valid_pairs;
      for (size_t i = 0; i < jets.size(); ++i) {
          for (size_t j = i + 1; j < jets.size(); ++j) {
              double mass = calculateInvariantMass(jets[i], jets[j]);
              if (mass >= 70 && mass <= 190 &&
                  fabs(jets[i].eta) < 2.5 && fabs(jets[j].eta) < 2.5) {
                  valid_pairs.push_back({(int)i, (int)j, mass, jets[i].btag_score + jets[j].btag_score});
              }
          }
      }
      if (!valid_pairs.empty()) {
          jetCutflow->Fill(4);  
      }
      */
    
       // Farjet = 1;
       // if (GenBJet1_idx != -1 && Jet_genJetIdx[i] == GenBJet1_idx){
       //   jet1Pt = Jet_pt[i];
       //   jet1Eta = Jet_eta[i];
      //    jet1Phi = Jet_phi[i];
      //    jet1Mass = Jet_mass[i];
      //    jet1PNet = Jet_btagPNetB[i];
      //    jet1DeepFlavB = Jet_btagDeepFlavB[i];
      //    jet1Flav = Jet_partonFlavour[i];
      //    Farjet = 0;
      //  } 
      //  if (GenBJet2_idx != -1 && Jet_genJetIdx[i] == GenBJet2_idx){
      //    jet2Pt = Jet_pt[i];
      //    jet2Eta = Jet_eta[i];
      //    jet2Phi = Jet_phi[i];
      //    jet2Mass = Jet_mass[i];
      //    jet2PNet = Jet_btagPNetB[i];
      //    jet2DeepFlavB = Jet_btagDeepFlavB[i];
      //    jet2Flav = Jet_partonFlavour[i];
       //   Farjet = 0;
      //  }
       // if (GenBJet3_idx != -1 && Jet_genJetIdx[i] == GenBJet3_idx){
        //  jet3Pt = Jet_pt[i];
        //  jet3Eta = Jet_eta[i];
        //  jet3Phi = Jet_phi[i];
        //  jet3Mass = Jet_mass[i];
        //  jet3PNet = Jet_btagPNetB[i];
        //  jet3DeepFlavB = Jet_btagDeepFlavB[i];
        //  jet3Flav = Jet_partonFlavour[i];
         // Farjet = 0;
       // }     
       // if ( GenBJet4_idx != -1 && Jet_genJetIdx[i] == GenBJet4_idx){
       //   jet4Pt = Jet_pt[i];
       //   jet4Eta = Jet_eta[i];
       //  jet4Phi = Jet_phi[i];
       //   jet4Mass = Jet_mass[i];
       //   jet4PNet = Jet_btagPNetB[i];
       //   jet4DeepFlavB = Jet_btagDeepFlavB[i];
       //   jet4Flav = Jet_partonFlavour[i];
       //   Farjet = 0;
       // }

	/*      
	double JEC = JetEnergyCorrectionFactor(Jet_pt[i], Jet_eta[i], Jet_phi[i],
					       sqrt( pow(Jet_mass[i],2) + pow(Jet_pt[i]*cosh(Jet_eta[i]),2)),
					       fixedGridRhoFastjetAll, Jet_area[i],
					       run,
					       JetCorrectorIOV,JetCorrector);
	double jetCorrPt = Jet_pt[i]*JEC;
	//use jetCorrPt from here on

	cout << "Jet " << i << " | " << Jet_pt[i] << " " << JEC << " " << jetCorrPt << " : " << Jet_eta[i] << " " << Jet_phi[i] << "\n";

	
	*/

      for(int i = 0; i < nJet; i++){     
        // Read the properties for each jet
        if(Jet_pt[i] > 20 && fabs(Jet_eta[i]) < 4.7 && deltaR(Jet_eta[i], Jet_phi[i], pho1Eta, pho1Phi) > 0.4 && deltaR(Jet_eta[i], Jet_phi[i], pho2Eta, pho2Phi) > 0.4){
        // Add the new jet to the list with default bT value as false
          jets.push_back({Jet_pt[i], Jet_btagPNetB[i], false, Jet_mass[i], Jet_eta[i], Jet_phi[i], Jet_PNetRegPtRawRes[i], Jet_PNetRegPtRawCorr[i], Jet_PNetRegPtRawCorrNeutrino[i]});
        }
      }    
      processJets(jets);

      NJets = jets.size();
      for (int l=0; l<jets.size(); l++){
	if (jets[l].bT == true && jets[l].pt>b_jet1Pt){
	    b_jet1Pt = jets[l].pt;
            b_jet1Eta = jets[l].eta;
            b_jet1Phi = jets[l].phi;
            b_jet1Mass = jets[l].mass;
            b_jet1PNet = jets[l].btag_score; 
            b_jet1PtRes = jets[l].PtRes;
            b_jet1PtCorr = jets[l].PtCorr;
            b_jet1PtCorrNeutrino = jets[l].PtCorrNeutrino;
	}else if (jets[l].bT == true){ 
	    b_jet2Pt = jets[l].pt;
            b_jet2Eta = jets[l].eta;
            b_jet2Phi = jets[l].phi;
            b_jet2Mass = jets[l].mass;
            b_jet2PNet = jets[l].btag_score;
            b_jet2PtRes = jets[l].PtRes;
            b_jet2PtCorr = jets[l].PtCorr;
            b_jet2PtCorrNeutrino = jets[l].PtCorrNeutrino;
         } 
       }
      //find AK4 jets for VBF HH->4b analysis
      //Pick a pair of opposite-η jets that maximizes mjj
      //pT>25 GeV, |η|<4.7, lepton cleaning (ΔR(j,e/μ)>0.4), AK8 jet cleaning (ΔR(j,AK8)>0.4),pass tight jet ID and medium pileup jet ID
      //Δη(jj) > 4.0 and mjjmax > 600 GeV, |ηtag jet|>1.5 for both jets
      for(int i=0; i <nJet; i++){   
	
	if (Jet_pt[i] > 30 && fabs(Jet_eta[i]) < 4.7
	    && deltaR(Jet_eta[i] , Jet_phi[i], vbffatJet1Eta, vbffatJet1Phi) > 1.2
	    && deltaR(Jet_eta[i] , Jet_phi[i], vbffatJet2Eta, vbffatJet2Phi) > 1.2
            && Jet_jetId[i] >= 2 && (Jet_pt[i] <50 ||Jet_pt[i] >50)){
          if (year == "2016"){
            if (Jet_jetId[i] < 3) continue;
          }
        
          bool islepoverlap = false;
          for(unsigned int j = 0; j < nMuon; j++ ) { 
	    if(Muon_pt[j]>5 && fabs(Muon_eta[j])<2.4 && abs(Muon_dxy[j]) < 0.05 and abs(Muon_dz[j]) < 0.2 && deltaR(Jet_eta[i] , Jet_phi[i], Muon_eta[j], Muon_phi[j]) < 0.4){
                  islepoverlap = true;
                  break;
              }
          }
          for(unsigned int j = 0; j < nElectron; j++ ) { 
	    if(Electron_pt[j]>7 && fabs(Electron_eta[j])<2.5 && abs(Electron_dxy[j]) < 0.05 and abs(Electron_dz[j]) < 0.2 && deltaR(Jet_eta[i] , Jet_phi[i], Electron_eta[j], Electron_phi[j]) < 0.4){
                  islepoverlap = true;
                  break;
              }
          }
          if(!islepoverlap) vbfjets_index.push_back(i);  
        }   
      
      } //loop over AK4 jets

      TLorentzVector b1_jet;
      TLorentzVector b2_jet;
      b1_jet.SetPtEtaPhiM( b_jet1Pt, b_jet1Eta, b_jet1Phi, b_jet1Mass);
      b2_jet.SetPtEtaPhiM( b_jet2Pt, b_jet2Eta, b_jet2Phi, b_jet2Mass);
      if (b_jet1Pt>0){
        DeltaPhi_j1MET = deltaPhi(b_jet1Phi, METPhi);
        if (lep1Pt>0) leadB_leadLep = deltaR(b_jet1Eta, b_jet1Phi, lep1Eta, lep1Phi);
        if (lep2Pt>0) leadB_subleadLep = deltaR(b_jet1Eta, b_jet1Phi, lep2Eta, lep2Phi);
      }
      if (b_jet2Pt>0){
        DeltaPhi_j2MET = deltaPhi(b_jet2Phi, METPhi);
        if (lep1Pt>0) subleadB_leadLep = deltaR(b_jet2Eta, b_jet2Phi, lep1Eta, lep1Phi);
        if (lep2Pt>0) subleadB_subleadLep = deltaR(b_jet2Eta, b_jet2Phi, lep2Eta, lep2Phi);
      }
      if (b_jet1Pt>0 && b_jet2Pt>0){
        Dijetsall_Mass = (b1_jet+b2_jet).M();
        Dijetsall_Pt = (b1_jet+b2_jet).Pt();
	Dijetsall_Eta = (b1_jet+b2_jet).Eta();
	Dijetsall_Phi = (b1_jet+b2_jet).Phi();
      }
       
      float minR_Wjets = 999;
      float dR = -1;
      int Nnb_jets = 0; //Number of non-b jets
      int minI = -1;
      int minJ = -1;
      float W_mass = -99;
      float W_pt = -99;
      float W_eta = -99;
      float W_phi = -99;
      float W_mass2 = -99;
      float W_pt2 = -99;
      float W_eta2 = -99;
      float W_phi2 = -99;
      float top1_Mass = -99;
      float top2_Mass = -99;
      int use_bjet1=-1;
      
      if (jets.size()>=2){
          for (int i = 0; i < jets.size(); ++i) {
	      if (jets[i].btag_score == true) continue; 
              for (int j = i + 1; j < jets.size(); ++j) {
                  if (jets[i].btag_score == true) continue;
		  dR = deltaR(jets[i].eta, jets[i].phi, jets[j].eta, jets[j].phi);
                  if (dR < minR_Wjets) {
                      minR_Wjets = dR;
                      minI = i;
                      minJ = j;
                  }
              }
          }
          TLorentzVector nonb_jet1;
          TLorentzVector nonb_jet2;
	  TLorentzVector W_boson;
          nonb_jet1.SetPtEtaPhiM(jets[minI].pt, jets[minI].eta, jets[minI].phi, jets[minI].mass);
	  nonb_jet2.SetPtEtaPhiM(jets[minJ].pt, jets[minJ].eta, jets[minJ].phi, jets[minJ].mass);
          W_boson = nonb_jet1+ nonb_jet2;
	  W_mass = W_boson.M(); 
          W_pt = W_boson.Pt();
          W_eta = W_boson.Eta();
	  W_phi = W_boson.Phi();
          if (b_jet2Pt>0){
              TLorentzVector top1;
              if (deltaR(W_eta, W_phi, b_jet1Eta, b_jet1Phi)< deltaR(W_eta, W_phi, b_jet2Eta, b_jet2Phi)){
	          top1 = W_boson + b1_jet;
       	          top1_Mass = top1.M();
                  use_bjet1 = 1;
	          
	      } else{
                  top1 = W_boson + b2_jet;
                  top1_Mass = top1.M();
	          use_bjet1 = 0;
	      }
	  } 
      
          chi_t0sq= pow((80.377-W_mass)/(0.1*80.377), 2)+pow((172.76-top1_Mass)/(0.1* 172.76),2);
      
      }


      dR = 0;
      minR_Wjets = 999;
      int minI_2 = -1;
      int minJ_2 = -1;

      if (jets.size()>=4){
          for (int i = 0; i < jets.size(); ++i) {
	      if (i==minI || jets[i].btag_score == true) continue;
              for (int j = i + 1; j < jets.size(); ++j) {
                  if (j==minJ || jets[j].btag_score == true) continue;
                  dR = deltaR(jets[i].eta, jets[i].phi, jets[j].eta, jets[j].phi);
                  if (dR < minR_Wjets) {
                      minR_Wjets = dR;
                      minI_2 = i;
                      minJ_2 = j;
                  }
              }
          }
          TLorentzVector nonb_jet3;
          TLorentzVector nonb_jet4;
          TLorentzVector W_boson2;
          nonb_jet3.SetPtEtaPhiM(jets[minI_2].pt, jets[minI_2].eta, jets[minI_2].phi, jets[minI_2].mass);
          nonb_jet4.SetPtEtaPhiM(jets[minJ_2].pt, jets[minJ_2].eta, jets[minJ_2].phi, jets[minJ_2].mass);
          W_boson2 = nonb_jet3+ nonb_jet4;
          W_mass2 = W_boson2.M();
          W_pt2 = W_boson2.Pt();
          W_eta2 = W_boson2.Eta();
          W_phi2 = W_boson2.Phi();
          TLorentzVector top2;	  
          if (use_bjet1==0){
              top2 = W_boson2 + b1_jet;
              top2_Mass = top2.M();
          } else if (use_bjet1==1){
	      top2 = W_boson2 + b2_jet;
              top2_Mass = top2.M();
	  }
            
          chi_t1sq = chi_t0sq + pow((80.377-W_mass2)/(0.1*80.377), 2)+pow((172.76-top2_Mass)/(0.1* 172.76),2); 
	  chi_t0sq = -99;
      }
      
      float R_j1g1 = 1.0;
      float R_j1g2 = 1.0;
      float R_j2g1 = 1.0;
      float R_j2g2 = 1.0;
      if (b_jet1Pt>0 && b_jet2Pt>0 && pho1Pt>0 && pho2Pt>0){
        M_jjgg = (b1_jet+b2_jet+g1+g2).M();
        R_j1g1 = deltaR(b_jet1Eta,b_jet1Phi,pho1Eta,pho1Phi);
	R_j1g2 = deltaR(b_jet1Eta,b_jet1Phi,pho2Eta,pho2Phi);
	R_j2g1 = deltaR(b_jet2Eta,b_jet2Phi,pho1Eta,pho1Phi);
	R_j2g2 = deltaR(b_jet2Eta,b_jet2Phi,pho2Eta,pho2Phi);
        minR_jg = min({R_j1g1,R_j1g2,R_j2g1,R_j2g2});
	if (R_j1g1==minR_jg) {
	    otherR_jg = R_j2g2;
	}else if (R_j1g2==minR_jg){
	    otherR_jg = R_j2g1;
	}else if (R_j2g1==minR_jg){
	    otherR_jg = R_j1g2;
	}else{
	    otherR_jg = R_j1g1;
	}
      } 
      
      //get the AK4 jets with the largest pt
      if(vbfjets_index.size()>1){
	vbfjet1Pt = Jet_pt[vbfjets_index[0]];
	vbfjet1Eta = Jet_eta[vbfjets_index[0]];
	vbfjet1Phi = Jet_phi[vbfjets_index[0]];
	vbfjet1Mass = Jet_mass[vbfjets_index[0]];
	vbfjet2Pt = Jet_pt[vbfjets_index[1]];
	vbfjet2Eta = Jet_eta[vbfjets_index[1]];
	vbfjet2Phi = Jet_phi[vbfjets_index[1]];
	vbfjet2Mass = Jet_mass[vbfjets_index[1]];
	isVBFtag = 0;
	TLorentzVector jet1,jet2;
	jet1.SetPtEtaPhiM(vbfjet1Pt,vbfjet1Eta,vbfjet1Phi,vbfjet1Mass);
	jet2.SetPtEtaPhiM(vbfjet2Pt,vbfjet2Eta,vbfjet2Phi,vbfjet2Mass);   
	dijetmass = (jet1 + jet2).M(); 
	if(dijetmass > 500. && fabs(vbfjet1Eta-vbfjet2Eta) > 4.) isVBFtag = 1;
      }
    
        
      //****************************************************
      //Fill Event - skim for events with two jets found
      //****************************************************
      if (
	  Option == 100 || 
	  Option == 0 || 
    (Option == 1 && pho1Pt>35 && pho2Pt>25)
	  ) {
	 

	//****************************************************
	//Compute trigger efficiency weight
	//****************************************************      
	if (triggerEffHist) {
	  triggerEffWeight = 1.0 - 
	    (1 - getTriggerEff( triggerEffHist , fatJet1Pt, fatJet1MassSD )) * 
	    (1 - getTriggerEff( triggerEffHist , fatJet2Pt, fatJet2MassSD ))
	    ;
	  triggerEff3DWeight = 1.0 - 
	    (1 - getTriggerEff3D( triggerEffHist_Xbb0p0To0p9, 
				  triggerEffHist_Xbb0p9To0p95, 
				  triggerEffHist_Xbb0p95To0p98, 
				  triggerEffHist_Xbb0p98To1p0, 
				  fatJet1Pt, fatJet1MassSD, fatJet1PNetXbb )) * 
	    (1 - getTriggerEff3D( triggerEffHist_Xbb0p0To0p9, 
				  triggerEffHist_Xbb0p9To0p95, 
				  triggerEffHist_Xbb0p95To0p98, 
				  triggerEffHist_Xbb0p98To1p0, 
				  fatJet2Pt, fatJet2MassSD, fatJet2PNetXbb ))
	    ;	

	  triggerEffMCWeight = 1.0 - 
	    (1 - getTriggerEff( triggerEffMCHist , fatJet1Pt, fatJet1MassSD )) * 
	    (1 - getTriggerEff( triggerEffMCHist , fatJet2Pt, fatJet2MassSD ))
	    ;
	  triggerEffMC3DWeight = 1.0 - 
	    (1 - getTriggerEff3D( triggerEffMCHist_Xbb0p0To0p9, 
				  triggerEffMCHist_Xbb0p9To0p95, 
				  triggerEffMCHist_Xbb0p95To0p98, 
				  triggerEffMCHist_Xbb0p98To1p0, 
				  fatJet1Pt, fatJet1MassSD, fatJet1PNetXbb )) * 
	    (1 - getTriggerEff3D( triggerEffMCHist_Xbb0p0To0p9, 
				  triggerEffMCHist_Xbb0p9To0p95, 
				  triggerEffMCHist_Xbb0p95To0p98, 
				  triggerEffMCHist_Xbb0p98To1p0, 
				  fatJet2Pt, fatJet2MassSD, fatJet2PNetXbb ))
	    ;	

	}
	
	//****************************************************
	//Compute pileupWeight
	//****************************************************      
	if (pileupWeightHist) {
	  pileupWeight = pileupWeightHist->GetBinContent( pileupWeightHist->GetXaxis()->FindFixBin(Pileup_nTrueInt));
	  pileupWeightUp = pileupWeightUpHist->GetBinContent( pileupWeightUpHist->GetXaxis()->FindFixBin(Pileup_nTrueInt));
	  pileupWeightDown = pileupWeightDownHist->GetBinContent( pileupWeightDownHist->GetXaxis()->FindFixBin(Pileup_nTrueInt));
	}

	//****************************************************
	//Compute totalWeight
	//****************************************************      
	totalWeight = weight * triggerEffWeight * pileupWeight;
 
        NEventsFilled++;            
        outputTree->Fill();
      }
    
    }//end of event loop
    
    cout << "Filled Total of " << NEventsFilled << " Events\n";
    cout << "No Pass :" << NoPass_N << " Events\n";
    cout << "Writing output trees..." << endl;
    outFile->Write();
    outFile->Close();
}
