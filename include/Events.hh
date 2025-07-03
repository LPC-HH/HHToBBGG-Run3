//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Mar 13 17:23:53 2020 by ROOT version 6.10/09
// from TTree Events/Events
// found on file: /mnt/hadoop/store/group/phys_exotica/privateProduction/NANOAOD/v1/GluGluToHHTo4B_node_SM_TuneCP5_PSWeights_13TeV-madgraph-pythia8/v1_RunIIAutumn18MiniAOD-102X_v15-v1/200312_210339/0000/RunIIAutumn18NanoAODv5_BulkGravTohhTohWWhbb_1.root
//////////////////////////////////////////////////////////

#ifndef Events_h
#define Events_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#define NFATJET 100
#define NSOFTACTIVITYJET 100
#define NJET 500
#define NCORRT1METJET 100
#define NSUBJET 200
#define NELECTRON 100
#define NPHOTON 100
#define NMUON 100
#define NTAU 100
#define NOTHERPV 10
#define NGENJETAK8 100
#define NSUBGENJETAK8 200
#define NGENJET 500
#define NGENVISTAU 50
#define NGENPART 500
#define NFSRPHOTON 20

#define NLHE 50
#define NSV  50
#define NTRIGOBJ 120

#define NPSWEIGHT 10
#define NLHEREWEIGHTINGWEIGHT 10
#define NGENDRESSEDLEPTON 10
#define NISOTRACK 50

#define NLHEPDFWEIGHT 200
#define NLHESCALEWEIGHT 20
#define TRY_SET_BRANCH(BRANCH, VAR, BRPTR) \
  if (fChain->GetBranch(BRANCH)) fChain->SetBranchAddress(BRANCH, VAR, BRPTR); 

// Header file for the classes stored in the TTree if any.

class Events {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain
   TTree          *tree_out;//output tree for hh
   std::string     fout_name;
   float           fatjet_pt_trh = 0.0;
// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UInt_t          run;
   UInt_t          luminosityBlock;
   ULong64_t       event;
   Float_t         HTXS_Higgs_pt;
   Float_t         HTXS_Higgs_y;
   Int_t           HTXS_stage1_1_cat_pTjet25GeV;
   Int_t           HTXS_stage1_1_cat_pTjet30GeV;
   Int_t           HTXS_stage1_1_fine_cat_pTjet25GeV;
   Int_t           HTXS_stage1_1_fine_cat_pTjet30GeV;
   Int_t           HTXS_stage_0;
   Int_t           HTXS_stage_1_pTjet25;
   Int_t           HTXS_stage_1_pTjet30;
   UChar_t         HTXS_njets25;
   UChar_t         HTXS_njets30;
   Float_t         btagWeight_CSVV2;
   Float_t         btagWeight_DeepCSVB;
   Float_t         CaloMET_phi;
   Float_t         CaloMET_pt;
   Float_t         CaloMET_sumEt;
   Float_t         ChsMET_phi;
   Float_t         ChsMET_pt;
   Float_t         ChsMET_sumEt;
   UInt_t          nCorrT1METJet;
   float* CorrT1METJet_area            = new float[NCORRT1METJET];   //[nCorrT1METJet]
   float* CorrT1METJet_eta             = new float[NCORRT1METJET];   //[nCorrT1METJet]
   float* CorrT1METJet_muonSubtrFactor = new float[NCORRT1METJET];   //[nCorrT1METJet]
   float* CorrT1METJet_phi             = new float[NCORRT1METJET];   //[nCorrT1METJet]
   float* CorrT1METJet_rawPt           = new float[NCORRT1METJET];   //[nCorrT1METJet]
   Int_t nAK15Puppi;
   float* AK15Puppi_ParticleNetMD_probQCD = new float[NFATJET];   //[nAK15Puppi]
   float* AK15Puppi_ParticleNetMD_probXbb = new float[NFATJET];   //[nAK15Puppi]
   float* AK15Puppi_ParticleNetMD_probXcc = new float[NFATJET];   //[nAK15Puppi]
   float* AK15Puppi_ParticleNetMD_probXqq = new float[NFATJET];   //[nAK15Puppi]
   float* AK15Puppi_area                  = new float[NFATJET];   //[nAK15Puppi]
   float* AK15Puppi_btagCSVV2             = new float[NFATJET];   //[nAK15Puppi]
   float* AK15Puppi_btagDeepB             = new float[NFATJET];   //[nAK15Puppi]
   float* AK15Puppi_btagJP                = new float[NFATJET];   //[nAK15Puppi]
   float* AK15Puppi_eta                   = new float[NFATJET];   //[nAK15Puppi]
   float* AK15Puppi_mass                  = new float[NFATJET];   //[nAK15Puppi]
   float* AK15Puppi_msoftdrop             = new float[NFATJET];   //[nAK15Puppi]
   float* AK15Puppi_phi                   = new float[NFATJET];   //[nAK15Puppi]
   float* AK15Puppi_pt                    = new float[NFATJET];   //[nAK15Puppi]
   float* AK15Puppi_rawFactor             = new float[NFATJET];   //[nAK15Puppi]
   float* AK15Puppi_tau1                  = new float[NFATJET];   //[nAK15Puppi]
   float* AK15Puppi_tau2                  = new float[NFATJET];   //[nAK15Puppi]
   float* AK15Puppi_tau3                  = new float[NFATJET];   //[nAK15Puppi]
   int*   AK15Puppi_jetId                 = new int[NFATJET];   //[nAK15Puppi]
   int*   AK15Puppi_nBHadrons             = new int[NFATJET];   //[nAK15Puppi]
   int*   AK15Puppi_nCHadrons             = new int[NFATJET];   //[nAK15Puppi]
   int*   AK15Puppi_nPFConstituents       = new int[NFATJET];   //[nAK15Puppi]
   int*   AK15Puppi_subJetIdx1            = new int[NFATJET];   //[nAK15Puppi]
   int*   AK15Puppi_subJetIdx2            = new int[NFATJET];   //[nAK15Puppi]
   int*   AK15Puppi_nPFCand               = new int[NFATJET];   //[nAK15Puppi]
   Int_t          nSubJet;
   float* SubJet_area      = new float[NSUBJET];   //[nSubJet]
   float* SubJet_btagCSVV2 = new float[NSUBJET];   //[nSubJet]
   float* SubJet_btagDeepB = new float[NSUBJET];   //[nSubJet]
   float* SubJet_eta       = new float[NSUBJET];   //[nSubJet]
   float* SubJet_mass      = new float[NSUBJET];   //[nSubJet]
   float* SubJet_phi       = new float[NSUBJET];   //[nSubJet]
   float* SubJet_pt        = new float[NSUBJET];   //[nSubJet]
   float* SubJet_rawFactor = new float[NSUBJET];   //[nSubJet]
   int* SubJet_nBHadrons   = new int[NSUBJET];   //[nSubJet]
   int* SubJet_nCHadrons   = new int[NSUBJET];   //[nSubJet]
   Int_t          nFatJet;
   float* FatJet_ParticleNetMD_probQCDb = new float[NFATJET];   //[nFatJet]
   float* FatJet_ParticleNetMD_probQCDbb = new float[NFATJET];   //[nFatJet]
   float* FatJet_ParticleNetMD_probQCDc = new float[NFATJET];   //[nFatJet]
   float* FatJet_ParticleNetMD_probQCDcc = new float[NFATJET];   //[nFatJet]
   float* FatJet_ParticleNetMD_probQCDothers = new float[NFATJET];   //[nFatJet]
   float* FatJet_ParticleNetMD_probXbb = new float[NFATJET];   //[nFatJet]
   float* FatJet_ParticleNetMD_probXcc = new float[NFATJET];   //[nFatJet]
   float* FatJet_ParticleNetMD_probXqq = new float[NFATJET];   //[nFatJet]
   float* FatJet_ParticleNetMass = new float[NFATJET];
   float* FatJet_particleNet_massCorr = new float[NFATJET];   //[nFatJet]
   float* FatJet_particleNetWithMass_HbbvsQCD = new float[NFATJET];
   float* FatJet_particleNetWithMass_HccvsQCD = new float[NFATJET];
   float* FatJet_particleNetWithMass_QCD = new float[NFATJET];
   float* FatJet_particleNet_QCD = new float[NFATJET];
   float* FatJet_particleNet_QCD0HF = new float[NFATJET];
   float* FatJet_particleNet_QCD1HF = new float[NFATJET];
   float* FatJet_particleNet_QCD2HF = new float[NFATJET];
   float* FatJet_particleNet_XbbVsQCD = new float[NFATJET];
   float* FatJet_particleNet_XccVsQCD = new float[NFATJET];
   float* FatJet_particleNet_XggVsQCD = new float[NFATJET];
   float* FatJet_particleNet_XqqVsQCD = new float[NFATJET];
   float* FatJet_LSmsoftdrop = new float[NFATJET];   //[nFatJet]
   float* FatJet_LSn2b1= new float[NFATJET];   //[nFatJet]
   float* FatJet_LSn3b1 = new float[NFATJET];   //[nFatJet]
   float* FatJet_LSpt = new float[NFATJET];   //[nFatJet]
   float* FatJet_LSrawmsoftdrop = new float[NFATJET];   //[nFatJet]
   float* FatJet_LSsubJet1btagDeepB = new float[NFATJET];   //[nFatJet]
   float* FatJet_LSsubJet2btagDeepB = new float[NFATJET];   //[nFatJet]
   float* FatJet_LStau1 = new float[NFATJET];   //[nFatJet]
   float* FatJet_LStau2 = new float[NFATJET];   //[nFatJet]
   float* FatJet_LStau3 = new float[NFATJET];   //[nFatJet]
   float* FatJet_LStau4 = new float[NFATJET];   //[nFatJet]
   float* FatJet_area = new float[NFATJET];   //[nFatJet]
   float* FatJet_btagDDBvL = new float[NFATJET];   //[nFatJet]
   float* FatJet_btagDDBvLV2 = new float[NFATJET];
   float* FatJet_btagDDCvBV2 = new float[NFATJET];   //[nFatJet]
   float* FatJet_btagDDCvLV2 = new float[NFATJET];   //[nFatJet]
   float* FatJet_btagDeepB = new float[NFATJET];
   float* FatJet_btagHbb = new float[NFATJET];   //[nFatJet]
   float* FatJet_dRLep = new float[NFATJET];   //[nFatJet]
   float* FatJet_deepTagHbb = new float[NFATJET];   //[nFatJet]
   float* FatJet_deepTagHcc = new float[NFATJET];   //[nFatJet]
   float* FatJet_deepTagHqqqq = new float[NFATJET];   //[nFatJet]
   float* FatJet_deepTagMDHbb = new float[NFATJET];   //[nFatJet]
   float* FatJet_deepTagMDHcc = new float[NFATJET];   //[nFatJet]
   float* FatJet_deepTagMDHqqqq = new float[NFATJET];   //[nFatJet]
   float* FatJet_deepTagMDQCDbb = new float[NFATJET];   //[nFatJet]
   float* FatJet_deepTagMDQCDcc = new float[NFATJET];   //[nFatJet]
   float* FatJet_deepTagMDWcq = new float[NFATJET];   //[nFatJet]
   float* FatJet_deepTagMDWqq = new float[NFATJET];   //[nFatJet]
   float* FatJet_deepTagMDZbb = new float[NFATJET];   //[nFatJet]
   float* FatJet_deepTagMDZcc = new float[NFATJET];   //[nFatJet]
   float* FatJet_deepTagMDZqq = new float[NFATJET];   //[nFatJet]
   float* FatJet_deepTagQCDbb = new float[NFATJET];   //[nFatJet]
   float* FatJet_deepTagQCDcc = new float[NFATJET];   //[nFatJet]
   float* FatJet_deepTagWcq = new float[NFATJET];   //[nFatJet]
   float* FatJet_deepTagWqq = new float[NFATJET];   //[nFatJet]
   float* FatJet_deepTagZbb = new float[NFATJET];   //[nFatJet]
   float* FatJet_deepTagZcc = new float[NFATJET];   //[nFatJet]
   float* FatJet_deepTagZqq = new float[NFATJET];   //[nFatJet]
   float* FatJet_deepTagMD_WvsQCD = new float[NFATJET];   //[nFatJet]
   float* FatJet_deepTagMD_ZvsQCD = new float[NFATJET];   //[nFatJet]
   float* FatJet_deepTag_WvsQCD = new float[NFATJET];   //[nFatJet]
   float* FatJet_deepTag_ZvsQCD = new float[NFATJET];   //[nFatJet]
   float* FatJet_eta = new float[NFATJET];   //[nFatJet]
   float* FatJet_lsf3 = new float[NFATJET];   //[nFatJet]
   float* FatJet_mass = new float[NFATJET];   //[nFatJet]
   float* FatJet_msoftdrop = new float[NFATJET];   //[nFatJet]
   float* FatJet_n2b1 = new float[NFATJET];   //[nFatJet]
   float* FatJet_n3b1 = new float[NFATJET];   //[nFatJet]
   float* FatJet_phi = new float[NFATJET];   //[nFatJet]
   float* FatJet_pt = new float[NFATJET];   //[nFatJet]
   float* FatJet_rawFactor = new float[NFATJET];   //[nFatJet]
   float* FatJet_rawmsoftdrop = new float[NFATJET];   //[nFatJet]
   float* FatJet_tau1 = new float[NFATJET];   //[nFatJet]
   float* FatJet_tau2 = new float[NFATJET];   //[nFatJet]
   float* FatJet_tau3 = new float[NFATJET];   //[nFatJet]
   float* FatJet_tau4 = new float[NFATJET];   //[nFatJet]
   short* FatJet_electronIdx3SJ = new short[NFATJET];   //[nFatJet]
   int* FatJet_idLep = new int[NFATJET];   //[nFatJet]
   unsigned char* FatJet_jetId = new unsigned char[NFATJET];   //[nFatJet]
   short* FatJet_muonIdx3SJ = new short[NFATJET];   //[nFatJet]
   unsigned char* FatJet_nBHadrons = new unsigned char[NFATJET];   //[nFatJet]
   unsigned char* FatJet_nCHadrons = new unsigned char[NFATJET];   //[nFatJet]
   unsigned char* FatJet_nConstituents = new unsigned char[NFATJET];   //[nFatJet]
   short* FatJet_subJetIdx1 = new short[NFATJET];   //[nFatJet]
   short* FatJet_subJetIdx2 = new short[NFATJET];   //[nFatJet]
   short* FatJet_genJetAK8Idx = new short[NFATJET];
   Int_t          nElectron;
   float* Electron_deltaEtaSC = new float[NELECTRON];   //[nElectron]
   float* Electron_dr03EcalRecHitSumEt = new float[NELECTRON];   //[nElectron]
   float* Electron_dr03HcalDepth1TowerSumEt = new float[NELECTRON];   //[nElectron]
   float* Electron_dr03TkSumPt = new float[NELECTRON];   //[nElectron]
   float* Electron_dr03TkSumPtHEEP = new float[NELECTRON];   //[nElectron]
   float* Electron_dxy = new float[NELECTRON];   //[nElectron]
   float* Electron_dxyErr = new float[NELECTRON];   //[nElectron]
   float* Electron_dz = new float[NELECTRON];   //[nElectron]
   float* Electron_dzErr = new float[NELECTRON];   //[nElectron]
   float* Electron_eCorr = new float[NELECTRON];   //[nElectron]
   float* Electron_eInvMinusPInv = new float[NELECTRON];   //[nElectron]
   float* Electron_energyErr = new float[NELECTRON];   //[nElectron]
   float* Electron_eta = new float[NELECTRON];   //[nElectron]
   float* Electron_hoe = new float[NELECTRON];   //[nElectron]
   float* Electron_ip3d = new float[NELECTRON];   //[nElectron]
   float* Electron_jetPtRelv2 = new float[NELECTRON];   //[nElectron]
   float* Electron_jetRelIso = new float[NELECTRON];   //[nElectron]
   float* Electron_mass = new float[NELECTRON];   //[nElectron]
   float* Electron_miniPFRelIso_all = new float[NELECTRON];   //[nElectron]
   float* Electron_miniPFRelIso_chg = new float[NELECTRON];   //[nElectron]
   float* Electron_mvaFall17V1Iso = new float[NELECTRON];   //[nElectron]
   float* Electron_mvaFall17V1noIso = new float[NELECTRON];   //[nElectron]
   float* Electron_mvaFall17V2Iso = new float[NELECTRON];   //[nElectron]
   float* Electron_mvaFall17V2noIso = new float[NELECTRON];   //[nElectron]
   float* Electron_pfRelIso03_all = new float[NELECTRON];   //[nElectron]
   float* Electron_pfRelIso03_chg = new float[NELECTRON];   //[nElectron]
   float* Electron_phi = new float[NELECTRON];   //[nElectron]
   float* Electron_pt = new float[NELECTRON];   //[nElectron]
   float* Electron_r9 = new float[NELECTRON];   //[nElectron]
   float* Electron_sieie = new float[NELECTRON];   //[nElectron]
   float* Electron_sip3d = new float[NELECTRON];   //[nElectron]
   float* Electron_mvaTTH = new float[NELECTRON];   //[nElectron]
   int* Electron_charge = new int[NELECTRON];   //[nElectron]
   int* Electron_cutBased = new int[NELECTRON];   //[nElectron]
   int* Electron_cutBased_Fall17_V1 = new int[NELECTRON];   //[nElectron]
   short* Electron_jetIdx = new short[NELECTRON];   //[nElectron]
   int* Electron_pdgId = new int[NELECTRON];   //[nElectron]
   int* Electron_photonIdx = new int[NELECTRON];   //[nElectron]
   int* Electron_tightCharge = new int[NELECTRON];   //[nElectron]
   int* Electron_vidNestedWPBitmap = new int[NELECTRON];   //[nElectron]
   int* Electron_vidNestedWPBitmapHEEP = new int[NELECTRON];   //[nElectron]
   bool* Electron_convVeto = new bool[NELECTRON];   //[nElectron]
   bool* Electron_cutBased_HEEP = new bool[NELECTRON];   //[nElectron]
   bool* Electron_isPFcand = new bool[NELECTRON];   //[nElectron]
   unsigned char* Electron_lostHits = new unsigned char[NELECTRON];   //[nElectron]
   bool* Electron_mvaFall17V1Iso_WP80 = new bool[NELECTRON];   //[nElectron]
   bool* Electron_mvaFall17V1Iso_WP90 = new bool[NELECTRON];   //[nElectron]
   bool* Electron_mvaFall17V1Iso_WPL = new bool[NELECTRON];   //[nElectron]
   float* Electron_mvaIso = new float[NELECTRON];
   bool* Electron_mvaNoIso_WP80 = new bool[NELECTRON];   //[nElectron]
   bool* Electron_mvaNoIso_WP90 = new bool[NELECTRON];   //[nElectron]
   bool* Electron_mvaFall17V1noIso_WPL = new bool[NELECTRON];   //[nElectron]
   bool* Electron_mvaIso_WP80 = new bool[NELECTRON];   //[nElectron]
   bool* Electron_mvaIso_WP90 = new bool[NELECTRON];   //[nElectron]
   bool* Electron_mvaFall17V2Iso_WPL = new bool[NELECTRON];   //[nElectron]
   bool* Electron_mvaFall17V1noIso_WP80 = new bool[NELECTRON];   //[nElectron]
   bool* Electron_mvaFall17V2noIso_WP80 = new bool[NELECTRON];   //[nElectron]
   bool* Electron_mvaFall17V2noIso_WP90 = new bool[NELECTRON];   //[nElectron]
   bool* Electron_mvaFall17V2noIso_WPL = new bool[NELECTRON];   //[nElectron]
   unsigned char* Electron_seedGain = new unsigned char[NELECTRON];   //[nElectron]
   short* Electron_genPartIdx = new short[NELECTRON];   //[nElectron]
   unsigned char* Electron_genPartFlav = new unsigned char[NELECTRON];   //[nElectron]
   unsigned char* Electron_cleanmask = new unsigned char[NELECTRON];   //[nElectron]
   Int_t          nFsrPhoton;
   float* FsrPhoton_dROverEt2 = new float[NFSRPHOTON];   //[nFsrPhoton]
   float* FsrPhoton_eta = new float[NFSRPHOTON];   //[nFsrPhoton]
   float* FsrPhoton_phi = new float[NFSRPHOTON];   //[nFsrPhoton]
   float* FsrPhoton_pt = new float[NFSRPHOTON];   //[nFsrPhoton]
   float* FsrPhoton_relIso03 = new float[NFSRPHOTON];   //[nFsrPhoton]
   int*   FsrPhoton_muonIdx = new int[NFSRPHOTON];   //[nFsrPhoton]
   Int_t          nGenJetAK8;
   float* GenJetAK8_eta = new float[NGENJETAK8];   //[nGenJetAK8]
   float* GenJetAK8_mass = new float[NGENJETAK8];   //[nGenJetAK8]
   float* GenJetAK8_phi = new float[NGENJETAK8];   //[nGenJetAK8]
   float* GenJetAK8_pt = new float[NGENJETAK8];   //[nGenJetAK8]
   short*   GenJetAK8_partonFlavour = new short[NGENJETAK8];   //[nGenJetAK8]
   unsigned char* GenJetAK8_hadronFlavour = new unsigned char[NGENJETAK8];   //[nGenJetAK8]
   Int_t          nGenJet;
   float* GenJet_eta = new float[NGENJET];   //[nGenJet]
   float* GenJet_mass = new float[NGENJET];   //[nGenJet]
   float* GenJet_phi = new float[NGENJET];   //[nGenJet]
   float* GenJet_pt = new float[NGENJET];   //[nGenJet]
   short*   GenJet_partonFlavour = new short[NGENJET];   //[nGenJet]
   unsigned char* GenJet_hadronFlavour = new unsigned char[NGENJET];   //[nGenJet]
   Int_t          nGenPart;
   float* GenPart_eta = new float[NGENPART];   //[nGenPart]
   float* GenPart_mass = new float[NGENPART];   //[nGenPart]
   float* GenPart_phi = new float[NGENPART];   //[nGenPart]
   float* GenPart_pt = new float[NGENPART];   //[nGenPart]
   short*  GenPart_genPartIdxMother = new short[NGENPART];   //[nGenPart]
   int*  GenPart_pdgId = new int[NGENPART];   //[nGenPart]
   int*  GenPart_status = new int[NGENPART];   //[nGenPart]
   unsigned short*  GenPart_statusFlags = new unsigned short[NGENPART];   //[nGenPart]
   Int_t          nSubGenJetAK8;
   float* SubGenJetAK8_eta = new float[NSUBGENJETAK8];   //[nSubGenJetAK8]
   float* SubGenJetAK8_mass = new float[NSUBGENJETAK8];   //[nSubGenJetAK8]
   float* SubGenJetAK8_phi = new float[NSUBGENJETAK8];   //[nSubGenJetAK8]
   float* SubGenJetAK8_pt = new float[NSUBGENJETAK8];   //[nSubGenJetAK8]
   Float_t         Generator_binvar;
   Float_t         Generator_scalePDF;
   Float_t         Generator_weight;
   Float_t         Generator_x1;
   Float_t         Generator_x2;
   Float_t         Generator_xpdf1;
   Float_t         Generator_xpdf2;
   Int_t           Generator_id1;
   Int_t           Generator_id2;
   Int_t          nGenVisTau;
   float* GenVisTau_eta = new float[NGENVISTAU];   //[nGenVisTau]
   float* GenVisTau_mass = new float[NGENVISTAU];   //[nGenVisTau]
   float* GenVisTau_phi = new float[NGENVISTAU];   //[nGenVisTau]
   float* GenVisTau_pt = new float[NGENVISTAU];   //[nGenVisTau]
   int*   GenVisTau_charge = new int[NGENVISTAU];   //[nGenVisTau]
   int*   GenVisTau_genPartIdxMother = new int[NGENVISTAU];   //[nGenVisTau]
   int*   GenVisTau_status = new int[NGENVISTAU];   //[nGenVisTau]
   Float_t         genWeight;
   Float_t         LHEWeight_originalXWGTUP;
   Int_t          nLHEPdfWeight;
   float* LHEPdfWeight         = new float[NLHEPDFWEIGHT];   //[nLHEPdfWeight]
   Int_t          nLHEReweightingWeight;
   float* LHEReweightingWeight = new float[NLHEREWEIGHTINGWEIGHT];   //[nLHEReweightingWeight]
   Int_t          nLHEScaleWeight;
   Float_t         LHEScaleWeight[9];   //[nLHEScaleWeight]
   Int_t          nPSWeight;
   float* PSWeight = new float[NPSWEIGHT];   //[nPSWeight]
   Int_t          nIsoTrack;
   float* IsoTrack_dxy = new float[NISOTRACK];   //[nIsoTrack]
   float* IsoTrack_dz = new float[NISOTRACK];   //[nIsoTrack]
   float* IsoTrack_eta = new float[NISOTRACK];   //[nIsoTrack]
   float* IsoTrack_pfRelIso03_all = new float[NISOTRACK];   //[nIsoTrack]
   float* IsoTrack_pfRelIso03_chg = new float[NISOTRACK];   //[nIsoTrack]
   float* IsoTrack_phi = new float[NISOTRACK];   //[nIsoTrack]
   float* IsoTrack_pt = new float[NISOTRACK];   //[nIsoTrack]
   float* IsoTrack_miniPFRelIso_all = new float[NISOTRACK];   //[nIsoTrack]
   float* IsoTrack_miniPFRelIso_chg = new float[NISOTRACK];   //[nIsoTrack]
   int*   IsoTrack_fromPV = new int[NISOTRACK];   //[nIsoTrack]
   int*   IsoTrack_pdgId = new int[NISOTRACK];   //[nIsoTrack]
   bool*  IsoTrack_isHighPurityTrack = new bool[NISOTRACK];   //[nIsoTrack]
   bool*  IsoTrack_isPFcand = new bool[NISOTRACK];   //[nIsoTrack]
   bool*  IsoTrack_isFromLostTrack = new bool[NISOTRACK];   //[nIsoTrack]
   Int_t          nJet;
   float* Jet_PNetRegPtRawCorr = new float[NJET];
   float* Jet_PNetRegPtRawCorrNeutrino = new float[NJET];
   float* Jet_PNetRegPtRawRes = new float[NJET];
   float* Jet_area = new float[NJET];   //[nJet]
   float* Jet_btagCMVA = new float[NJET];   //[nJet]
   float* Jet_btagCSVV2 = new float[NJET];   //[nJet]
   float* Jet_btagDeepB = new float[NJET];   //[nJet]
   float* Jet_btagDeepC = new float[NJET];   //[nJet]
   float* Jet_btagDeepFlavB = new float[NJET];   //[nJet]
   float* Jet_btagDeepFlavCvB = new float[NJET];   //[nJet]
   float* Jet_btagDeepFlavCvL = new float[NJET];
   float* Jet_btagDeepFlavQG = new float[NJET];
   float* Jet_btagPNetB = new float[NJET];
   float* Jet_btagPNetCvB = new float[NJET];
   float* Jet_btagPNetCvL= new float[NJET];
   float* Jet_btagPNetQvG= new float[NJET];
   float* Jet_btagPNetTauVJet= new float[NJET];
   float* Jet_btagRobustParTAK4B= new float[NJET];
   float* Jet_btagRobustParTAK4CvB= new float[NJET];
   float* Jet_btagRobustParTAK4CvL= new float[NJET];
   float* Jet_btagRobustParTAK4QG= new float[NJET];
   float* Jet_chEmEF = new float[NJET];   //[nJet]
   float* Jet_chHEF = new float[NJET];   //[nJet]
   float* Jet_eta = new float[NJET];   //[nJet]
   float* Jet_jercCHF = new float[NJET];   //[nJet]
   float* Jet_jercCHPUF = new float[NJET];   //[nJet]
   float* Jet_mass = new float[NJET];   //[nJet]
   float* Jet_muEF = new float[NJET];   //[nJet]
   float* Jet_muonSubtrFactor = new float[NJET];   //[nJet]
   float* Jet_neEmEF = new float[NJET];   //[nJet]
   float* Jet_neHEF = new float[NJET];   //[nJet]
   float* Jet_phi = new float[NJET];   //[nJet]
   float* Jet_pt = new float[NJET];   //[nJet]
   float* Jet_qgl = new float[NJET];   //[nJet]
   float* Jet_rawFactor = new float[NJET];   //[nJet]
   float* Jet_bRegCorr = new float[NJET];   //[nJet]
   float* Jet_bRegRes = new float[NJET];   //[nJet]
   short* Jet_electronIdx1 = new short[NJET];   //[nJet]
   short* Jet_electronIdx2 = new short[NJET];   //[nJet]
   unsigned char* Jet_jetId = new unsigned char[NJET];   //[nJet]
   short* Jet_muonIdx1 = new short[NJET];   //[nJet]
   short* Jet_muonIdx2 = new short[NJET];   //[nJet]
   unsigned char* Jet_nConstituents = new unsigned char[NJET];   //[nJet]
   unsigned char* Jet_nElectrons = new unsigned char[NJET];   //[nJet]
   unsigned char* Jet_nMuons = new unsigned char[NJET];   //[nJet]
   int* Jet_puId = new int[NJET];   //[nJet]
   short* Jet_genJetIdx = new short[NJET];   //[nJet]
   unsigned char* Jet_hadronFlavour = new unsigned char[NJET];   //[nJet]
   short* Jet_partonFlavour = new short[NJET];   //[nJet]
   unsigned char* Jet_cleanmask = new unsigned char[NJET];   //[nJet]
   Float_t         LHE_HT;
   Float_t         LHE_HTIncoming;
   Float_t         LHE_Vpt;
   UChar_t         LHE_Njets;
   UChar_t         LHE_Nb;
   UChar_t         LHE_Nc;
   UChar_t         LHE_Nuds;
   UChar_t         LHE_Nglu;
   UChar_t         LHE_NpNLO;
   UChar_t         LHE_NpLO;
   Int_t          nLHEPart;
   float* LHEPart_pt = new float[NLHE];   //[nLHEPart]
   float* LHEPart_eta = new float[NLHE];   //[nLHEPart]
   float* LHEPart_phi = new float[NLHE];   //[nLHEPart]
   float* LHEPart_mass = new float[NLHE];   //[nLHEPart]
   int*   LHEPart_pdgId = new int[NLHE];   //[nLHEPart]
   Float_t         GenMET_phi;
   Float_t         GenMET_pt;
   Float_t         MET_MetUnclustEnUpDeltaX;
   Float_t         MET_MetUnclustEnUpDeltaY;
   Float_t         MET_covXX;
   Float_t         MET_covXY;
   Float_t         MET_covYY;
   Float_t         MET_phi;
   Float_t         MET_pt;
   Float_t         MET_significance;
   Float_t         MET_sumEt;
   Int_t          nMuon;
   float* Muon_dxy= new float[NMUON];   //[nMuon]
   float* Muon_dxyErr = new float[NMUON];   //[nMuon]
   float* Muon_dz = new float[NMUON];   //[nMuon]
   float* Muon_dzErr = new float[NMUON];   //[nMuon]
   float* Muon_eta = new float[NMUON];   //[nMuon]
   float* Muon_ip3d = new float[NMUON];   //[nMuon]
   float* Muon_jetPtRelv2 = new float[NMUON];   //[nMuon]
   float* Muon_jetRelIso = new float[NMUON];   //[nMuon]
   float* Muon_mass = new float[NMUON];   //[nMuon]
   float* Muon_miniPFRelIso_all = new float[NMUON];   //[nMuon]
   float* Muon_miniPFRelIso_chg = new float[NMUON];   //[nMuon]
   float* Muon_pfRelIso03_all = new float[NMUON];   //[nMuon]
   float* Muon_pfRelIso03_chg = new float[NMUON];   //[nMuon]
   float* Muon_pfRelIso04_all = new float[NMUON];   //[nMuon]
   float* Muon_phi = new float[NMUON];   //[nMuon]
   float* Muon_pt = new float[NMUON];   //[nMuon]
   float* Muon_ptErr = new float[NMUON];   //[nMuon]
   float* Muon_segmentComp = new float[NMUON];   //[nMuon]
   float* Muon_sip3d = new float[NMUON];   //[nMuon]
   float* Muon_softMva = new float[NMUON];   //[nMuon]
   float* Muon_tkRelIso = new float[NMUON];   //[nMuon]
   float* Muon_tunepRelPt = new float[NMUON];   //[nMuon]
   float* Muon_mvaLowPt = new float[NMUON];   //[nMuon]
   float* Muon_mvaTTH = new float[NMUON];   //[nMuon]
   int*   Muon_charge = new int[NMUON];   //[nMuon]
   short*   Muon_jetIdx = new short[NMUON];   //[nMuon]
   int*   Muon_nStations = new int[NMUON];   //[nMuon]
   int*   Muon_nTrackerLayers = new int[NMUON];   //[nMuon]
   int*   Muon_pdgId = new int[NMUON];   //[nMuon]
   int*   Muon_tightCharge = new int[NMUON];   //[nMuon]
   short*   Muon_fsrPhotonIdx = new short[NMUON];   //[nMuon]
   short*   Muon_genPartIdx = new short[NMUON];   //[nMuon]
   bool*  Muon_inTimeMuon = new bool[NMUON];   //[nMuon]
   bool*  Muon_isGlobal = new bool[NMUON];   //[nMuon]
   bool*  Muon_isPFcand = new bool[NMUON];   //[nMuon]
   bool*  Muon_isTracker = new bool[NMUON];   //[nMuon]
   bool*  Muon_looseId = new bool[NMUON];   //[nMuon]
   bool*  Muon_mediumId = new bool[NMUON];   //[nMuon]
   bool*  Muon_mediumPromptId = new bool[NMUON];   //[nMuon]
   bool*  Muon_softId = new bool[NMUON];   //[nMuon]
   bool*  Muon_softMvaId = new bool[NMUON];   //[nMuon]
   bool*  Muon_tightId = new bool[NMUON];   //[nMuon]
   bool*  Muon_triggerIdLoose = new bool[NMUON];   //[nMuon]
   unsigned char* Muon_miniIsoId = new unsigned char[NMUON];   //[nMuon]
   unsigned char* Muon_multiIsoId = new unsigned char[NMUON];   //[nMuon]
   float* Muon_mvaMuID = new float[NMUON];   //[nMuon]
   unsigned char* Muon_pfIsoId = new unsigned char[NMUON];   //[nMuon]
   unsigned char* Muon_highPtId = new unsigned char[NMUON];   //[nMuon]
   unsigned char* Muon_cleanmask = new unsigned char[NMUON];   //[nMuon]
   unsigned char* Muon_tkIsoId = new unsigned char[NMUON];   //[nMuon]
   unsigned char* Muon_genPartFlav = new unsigned char[NMUON];   //[nMuon]
   Int_t          nPhoton;
   float* Photon_eCorr = new float[NPHOTON];   //[nPhoton]
   float* Photon_energyErr = new float[NPHOTON];   //[nPhoton]
   float* Photon_energyRaw = new float[NPHOTON];
   float* Photon_eta = new float[NPHOTON];   //[nPhoton]
   float* Photon_hoe = new float[NPHOTON];   //[nPhoton]
   float* Photon_mass = new float[NPHOTON];   //[nPhoton]
   float* Photon_mvaID = new float[NPHOTON];   //[nPhoton]
   float* Photon_mvaIDV1 = new float[NPHOTON];   //[nPhoton]
   int* Photon_seediPhiOriY = new int[NPHOTON];
   char* Photon_seediEtaOriX = new char[NPHOTON];
   float* Photon_pfChargedIso = new float[NPHOTON];
   float* Photon_pfChargedIsoPFPV = new float[NPHOTON];
   float* Photon_pfChargedIsoWorstVtx = new float[NPHOTON];
   float* Photon_pfPhoIso03 = new float[NPHOTON];
   float* Photon_pfRelIso03_all_quadratic = new float[NPHOTON];   //[nPhoton]
   float* Photon_pfRelIso03_chg_quadratic = new float[NPHOTON];   //[nPhoton]
   float* Photon_phi = new float[NPHOTON];   //[nPhoton]
   float* Photon_pt = new float[NPHOTON];   //[nPhoton]
   float* Photon_r9 = new float[NPHOTON];   //[nPhoton]
   float* Photon_sieie = new float[NPHOTON];   //[nPhoton]
   int*   Photon_charge = new int[NPHOTON];   //[nPhoton]
   int*   Photon_cutBasedBitmap = new int[NPHOTON];   //[nPhoton]
   int*   Photon_cutBasedV1Bitmap = new int[NPHOTON];   //[nPhoton]
   short*   Photon_electronIdx = new short[NPHOTON];   //[nPhoton]
   short*   Photon_jetIdx = new short[NPHOTON];   //[nPhoton]
   int*   Photon_pdgId = new int[NPHOTON];   //[nPhoton]
   int*   Photon_vidNestedWPBitmap = new int[NPHOTON];   //[nPhoton]
   short*   Photon_genPartIdx = new short[NPHOTON];   //[nPhoton]
   bool*  Photon_electronVeto = new bool[NPHOTON];   //[nPhoton]
   bool*  Photon_isScEtaEB = new bool[NPHOTON];   //[nPhoton]
   bool*  Photon_isScEtaEE = new bool[NPHOTON];   //[nPhoton]
   bool*  Photon_mvaID_WP80 = new bool[NPHOTON];   //[nPhoton]
   bool*  Photon_mvaID_WP90 = new bool[NPHOTON];   //[nPhoton]
   bool*  Photon_pixelSeed = new bool[NPHOTON];   //[nPhoton]
   float* Photon_trkSumPtHollowConeDR03 = new float[NPHOTON];
   unsigned char* Photon_seedGain = new unsigned char[NPHOTON];   //[nPhoton]
   unsigned char* Photon_genPartFlav = new unsigned char[NPHOTON];   //[nPhoton]
   unsigned char* Photon_cleanmask = new unsigned char[NPHOTON];   //[nPhoton]
   Float_t         Pileup_nTrueInt;
   Float_t         Pileup_pudensity;
   Float_t         Pileup_gpudensity;
   Int_t           Pileup_nPU;
   Int_t           Pileup_sumEOOT;
   Int_t           Pileup_sumLOOT;
   Float_t         PuppiMET_phi;
   Float_t         PuppiMET_pt;
   Float_t         PuppiMET_sumEt;
   Float_t         RawMET_phi;
   Float_t         RawMET_pt;
   Float_t         RawMET_sumEt;
   Float_t         fixedGridRhoFastjetAll;
   Float_t         fixedGridRhoFastjetCentral;
   Float_t         fixedGridRhoFastjetCentralCalo;
   Float_t         fixedGridRhoFastjetCentralChargedPileUp;
   Float_t         fixedGridRhoFastjetCentralNeutral;
   Int_t          nGenDressedLepton;
   float* GenDressedLepton_eta       = new float[NGENDRESSEDLEPTON];   //[nGenDressedLepton]
   float* GenDressedLepton_mass      = new float[NGENDRESSEDLEPTON];   //[nGenDressedLepton]
   float* GenDressedLepton_phi       = new float[NGENDRESSEDLEPTON];   //[nGenDressedLepton]
   float* GenDressedLepton_pt        = new float[NGENDRESSEDLEPTON];   //[nGenDressedLepton]
   int*   GenDressedLepton_pdgId     = new int[NGENDRESSEDLEPTON];   //[nGenDressedLepton]
   bool*  GenDressedLepton_hasTauAnc = new bool[NGENDRESSEDLEPTON];   //[nGenDressedLepton]
   Float_t        Rho_fixedGridRhoAll;


   Int_t          nSoftActivityJet;
   float* SoftActivityJet_eta = new float[NSOFTACTIVITYJET];   //[nSoftActivityJet]
   float* SoftActivityJet_phi = new float[NSOFTACTIVITYJET];   //[nSoftActivityJet]
   float* SoftActivityJet_pt  = new float[NSOFTACTIVITYJET];   //[nSoftActivityJet]
   Float_t         SoftActivityJetHT;
   Float_t         SoftActivityJetHT10;
   Float_t         SoftActivityJetHT2;
   Float_t         SoftActivityJetHT5;
   Int_t           SoftActivityJetNjets10;
   Int_t           SoftActivityJetNjets2;
   Int_t           SoftActivityJetNjets5;
   Int_t          nTau;
   float* Tau_chargedIso = new float[NTAU];   //[nTau]
   float* Tau_dxy = new float[NTAU];   //[nTau]
   float* Tau_dz = new float[NTAU];   //[nTau]
   float* Tau_eta = new float[NTAU];   //[nTau]
   float* Tau_leadTkDeltaEta = new float[NTAU];   //[nTau]
   float* Tau_leadTkDeltaPhi = new float[NTAU];   //[nTau]
   float* Tau_leadTkPtOverTauPt = new float[NTAU];   //[nTau]
   float* Tau_mass = new float[NTAU];   //[nTau]
   float* Tau_neutralIso = new float[NTAU];   //[nTau]
   float* Tau_phi = new float[NTAU];   //[nTau]
   float* Tau_photonsOutsideSignalCone = new float[NTAU];   //[nTau]
   float* Tau_pt = new float[NTAU];   //[nTau]
   float* Tau_puCorr = new float[NTAU];   //[nTau]
   float* Tau_rawAntiEle = new float[NTAU];   //[nTau]
   float* Tau_rawAntiEle2018 = new float[NTAU];   //[nTau]
   float* Tau_rawDeepTau2017v2p1VSe = new float[NTAU];   //[nTau]
   float* Tau_rawDeepTau2017v2p1VSjet = new float[NTAU];   //[nTau]
   float* Tau_rawDeepTau2017v2p1VSmu = new float[NTAU];   //[nTau]
   float* Tau_rawIso = new float[NTAU];   //[nTau]
   float* Tau_rawIsodR03 = new float[NTAU];   //[nTau]
   float* Tau_rawMVAnewDM2017v2 = new float[NTAU];   //[nTau]
   float* Tau_rawMVAoldDM = new float[NTAU];   //[nTau]
   float* Tau_rawMVAoldDM2017v1 = new float[NTAU];   //[nTau]
   float* Tau_rawMVAoldDM2017v2 = new float[NTAU];   //[nTau]
   float* Tau_rawMVAoldDMdR032017v2 = new float[NTAU];   //[nTau]
   int*   Tau_charge = new int[NTAU];   //[nTau]
   int*   Tau_decayMode = new int[NTAU];   //[nTau]
   int*   Tau_jetIdx = new int[NTAU];   //[nTau]
   int*   Tau_rawAntiEleCat = new int[NTAU];   //[nTau]
   int*   Tau_rawAntiEleCat2018 = new int[NTAU];   //[nTau]
   int*   Tau_genPartIdx = new int[NTAU];   //[nTau]
   bool*  Tau_idDecayMode = new bool[NTAU];   //[nTau]
   bool*  Tau_idDecayModeNewDMs = new bool[NTAU];   //[nTau]
   unsigned char* Tau_idAntiEle = new unsigned char[NTAU];   //[nTau]
   unsigned char* Tau_idAntiEle2018 = new unsigned char[NTAU];   //[nTau]
   unsigned char* Tau_idAntiMu = new unsigned char[NTAU];   //[nTau]
   unsigned char* Tau_idDeepTau2017v2p1VSe = new unsigned char[NTAU];   //[nTau]
   unsigned char* Tau_idDeepTau2017v2p1VSjet = new unsigned char[NTAU];   //[nTau]
   unsigned char* Tau_idDeepTau2017v2p1VSmu = new unsigned char[NTAU];   //[nTau]
   unsigned char* Tau_idMVAnewDM2017v2 = new unsigned char[NTAU];   //[nTau]
   unsigned char* Tau_idMVAoldDM = new unsigned char[NTAU];   //[nTau]
   unsigned char* Tau_idMVAoldDM2017v1 = new unsigned char[NTAU];   //[nTau]
   unsigned char* Tau_idMVAoldDM2017v2 = new unsigned char[NTAU];   //[nTau]
   unsigned char* Tau_idMVAoldDMdR032017v2 = new unsigned char[NTAU];   //[nTau]
   unsigned char* Tau_genPartFlav = new unsigned char[NTAU];   //[nTau]
   unsigned char* Tau_cleanmask = new unsigned char[NTAU];   //[nTau]
   Float_t         TkMET_phi;
   Float_t         TkMET_pt;
   Float_t         TkMET_sumEt;
   Int_t          nTrigObj;
   float* TrigObj_pt         = new float[NTRIGOBJ];   //[nTrigObj]
   float* TrigObj_eta        = new float[NTRIGOBJ];   //[nTrigObj]
   float* TrigObj_phi        = new float[NTRIGOBJ];   //[nTrigObj]
   float* TrigObj_l1pt       = new float[NTRIGOBJ];   //[nTrigObj]
   float* TrigObj_l1pt_2     = new float[NTRIGOBJ];   //[nTrigObj]
   float* TrigObj_l2pt       = new float[NTRIGOBJ];   //[nTrigObj]
   unsigned short*   TrigObj_id = new unsigned short[NTRIGOBJ];   //[nTrigObj]
   int*   TrigObj_l1iso      = new int[NTRIGOBJ];   //[nTrigObj]
   short*   TrigObj_l1charge   = new short[NTRIGOBJ];   //[nTrigObj]
   int*   TrigObj_filterBits = new int[NTRIGOBJ];   //[nTrigObj]
   Int_t           genTtbarId;
   Int_t          nOtherPV;
   float* OtherPV_z          = new float[NOTHERPV];   //[nOtherPV]
   Float_t         PV_ndof;
   Float_t         PV_x;
   Float_t         PV_y;
   Float_t         PV_z;
   Float_t         PV_chi2;
   Float_t         PV_score;
   Int_t           PV_npvs;
   Int_t           PV_npvsGood;
   Int_t          nSV;
   float* SV_dlen    = new float[NSV];   //[nSV]
   float* SV_dlenSig = new float[NSV];   //[nSV]
   float* SV_dxy     = new float[NSV];   //[nSV]
   float* SV_dxySig  = new float[NSV];   //[nSV]
   float* SV_pAngle  = new float[NSV];   //[nSV]
   float* SV_chi2    = new float[NSV];   //[nSV]
   float* SV_eta     = new float[NSV];   //[nSV]
   float* SV_mass    = new float[NSV];   //[nSV]
   float* SV_ndof    = new float[NSV];   //[nSV]
   float* SV_phi     = new float[NSV];   //[nSV]
   float* SV_pt      = new float[NSV];   //[nSV]
   float* SV_x       = new float[NSV];   //[nSV]
   float* SV_y       = new float[NSV];   //[nSV]
   float* SV_z       = new float[NSV];   //[nSV]
   Float_t         MET_fiducialGenPhi;
   Float_t         MET_fiducialGenPt;
   Bool_t          L1simulation_step;
   Bool_t          HLTriggerFirstPath;
   Bool_t          HLT_AK8PFJet360_TrimMass30;
     Bool_t          HLT_AK8PFJet380_TrimMass30;
   Bool_t          HLT_AK8PFJet400_TrimMass30;
   Bool_t          HLT_AK8PFJet420_TrimMass30;
   Bool_t          HLT_AK8PFJet380_SoftDropMass30;
   Bool_t          HLT_AK8PFJet400_SoftDropMass30;
   Bool_t          HLT_AK8PFJet425_SoftDropMass30;
   Bool_t          HLT_AK8PFJet450_SoftDropMass30;
   Bool_t          HLT_AK8DiPFJet250_250_SoftDropMass40;
   Bool_t          HLT_AK8DiPFJet250_250_SoftDropMass50;
   Bool_t          HLT_AK8DiPFJet260_260_SoftDropMass30;
   Bool_t          HLT_AK8DiPFJet260_260_SoftDropMass40;
   Bool_t          HLT_AK8DiPFJet270_270_SoftDropMass30;
   Bool_t          HLT_AK8DiPFJet280_280_SoftDropMass30;
   Bool_t          HLT_AK8DiPFJet290_290_SoftDropMass30;
   Bool_t          HLT_AK8PFJet220_SoftDropMass40;
   Bool_t          HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p50;
   Bool_t          HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p53;
   Bool_t          HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p55;
   Bool_t          HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p60;
   Bool_t          HLT_AK8PFJet230_SoftDropMass40_PNetBB0p06;
   Bool_t          HLT_AK8PFJet230_SoftDropMass40_PNetBB0p10;
   Bool_t          HLT_AK8PFJet230_SoftDropMass40_PNetTauTau0p03;
   Bool_t          HLT_AK8PFJet230_SoftDropMass40_PNetTauTau0p05;
   Bool_t          HLT_AK8PFJet250_SoftDropMass40_PNetBB0p06;
   Bool_t          HLT_AK8PFJet250_SoftDropMass40_PNetBB0p10;
   Bool_t          HLT_AK8PFJet250_SoftDropMass40_PNetTauTau0p03;
   Bool_t          HLT_AK8PFJet250_SoftDropMass40_PNetTauTau0p05;
   Bool_t          HLT_AK8PFJet275_SoftDropMass40_PNetBB0p06;
   Bool_t          HLT_AK8PFJet275_SoftDropMass40_PNetBB0p10;
   Bool_t          HLT_AK8PFJet275_SoftDropMass40_PNetTauTau0p03;
   Bool_t          HLT_AK8PFJet275_SoftDropMass40_PNetTauTau0p05;
   Bool_t          HLT_AK8PFJet400_MassSD30;
   Bool_t          HLT_AK8PFJet420_MassSD30;
   Bool_t          HLT_AK8PFJet450_MassSD30;
   Bool_t          HLT_AK8DiPFJet250_250_MassSD30;
   Bool_t          HLT_AK8DiPFJet250_250_MassSD50;
   Bool_t          HLT_AK8DiPFJet260_260_MassSD30;
   Bool_t          HLT_AK8DiPFJet270_270_MassSD30;
   Bool_t          HLT_AK8PFHT750_TrimMass50;
   Bool_t          HLT_AK8PFHT800_TrimMass50;
   Bool_t          HLT_AK8PFHT850_TrimMass50;
   Bool_t          HLT_AK8PFHT900_TrimMass50;
   Bool_t          HLT_CaloJet500_NoJetID;
   Bool_t          HLT_CaloJet550_NoJetID;
   Bool_t          HLT_DoubleMu5_Upsilon_DoubleEle3_CaloIdL_TrackIdL;
   Bool_t          HLT_DoubleMu3_DoubleEle7p5_CaloIdL_TrackIdL_Upsilon;
   Bool_t          HLT_Trimuon5_3p5_2_Upsilon_Muon;
   Bool_t          HLT_TrimuonOpen_5_3p5_2_Upsilon_Muon;
   Bool_t          HLT_DoubleEle25_CaloIdL_MW;
   Bool_t          HLT_DoubleEle27_CaloIdL_MW;
   Bool_t          HLT_DoubleEle33_CaloIdL_MW;
   Bool_t          HLT_DoubleEle24_eta2p1_WPTight_Gsf;
   Bool_t          HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_DZ_PFHT350;
   Bool_t          HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT350;
   Bool_t          HLT_Ele27_Ele37_CaloIdL_MW;
   Bool_t          HLT_Mu27_Ele37_CaloIdL_MW;
   Bool_t          HLT_Mu37_Ele27_CaloIdL_MW;
   Bool_t          HLT_Mu37_TkMu27;
   Bool_t          HLT_DoubleMu4_3_Bs;
   Bool_t          HLT_DoubleMu4_3_Jpsi;
   Bool_t          HLT_DoubleMu4_JpsiTrk_Displaced;
   Bool_t          HLT_DoubleMu4_LowMassNonResonantTrk_Displaced;
   Bool_t          HLT_DoubleMu3_Trk_Tau3mu;
   Bool_t          HLT_DoubleMu3_TkMu_DsTau3Mu;
   Bool_t          HLT_DoubleMu4_PsiPrimeTrk_Displaced;
   Bool_t          HLT_DoubleMu4_Mass3p8_DZ_PFHT350;
   Bool_t          HLT_Mu3_PFJet40;
   Bool_t          HLT_Mu7p5_L2Mu2_Jpsi;
   Bool_t          HLT_Mu7p5_L2Mu2_Upsilon;
   Bool_t          HLT_Mu7p5_Track2_Jpsi;
   Bool_t          HLT_Mu7p5_Track3p5_Jpsi;
   Bool_t          HLT_Mu7p5_Track7_Jpsi;
   Bool_t          HLT_Mu7p5_Track2_Upsilon;
   Bool_t          HLT_Mu7p5_Track3p5_Upsilon;
   Bool_t          HLT_Mu7p5_Track7_Upsilon;
   Bool_t          HLT_Mu3_L1SingleMu5orSingleMu7;
   Bool_t          HLT_DoublePhoton33_CaloIdL;
   Bool_t          HLT_DoublePhoton70;
   Bool_t          HLT_DoublePhoton85;
   Bool_t          HLT_Ele20_WPTight_Gsf;
   Bool_t          HLT_Ele15_WPLoose_Gsf;
   Bool_t          HLT_Ele17_WPLoose_Gsf;
   Bool_t          HLT_Ele20_WPLoose_Gsf;
   Bool_t          HLT_Ele20_eta2p1_WPLoose_Gsf;
   Bool_t          HLT_DiEle27_WPTightCaloOnly_L1DoubleEG;
   Bool_t          HLT_Ele27_WPTight_Gsf;
   Bool_t          HLT_Ele28_WPTight_Gsf;
   Bool_t          HLT_Ele30_WPTight_Gsf;
   Bool_t          HLT_Ele32_WPTight_Gsf;
   Bool_t          HLT_Ele35_WPTight_Gsf;
   Bool_t          HLT_Ele35_WPTight_Gsf_L1EGMT;
   Bool_t          HLT_Ele38_WPTight_Gsf;
   Bool_t          HLT_Ele40_WPTight_Gsf;
   Bool_t          HLT_Ele32_WPTight_Gsf_L1DoubleEG;
   Bool_t          HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_CrossL1;
   Bool_t          HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTauHPS30_eta2p1_CrossL1;
   Bool_t          HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTauHPS30_eta2p1_CrossL1;
   Bool_t          HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_TightID_CrossL1;
   Bool_t          HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTauHPS30_eta2p1_TightID_CrossL1;
   Bool_t          HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTauHPS30_eta2p1_TightID_CrossL1;
   Bool_t          HLT_HT450_Beamspot;
   Bool_t          HLT_HT300_Beamspot;
   Bool_t          HLT_ZeroBias_Beamspot;
   Bool_t          HLT_IsoMu20_eta2p1_LooseChargedIsoPFTauHPS27_eta2p1_CrossL1;
   Bool_t          HLT_IsoMu20_eta2p1_MediumChargedIsoPFTauHPS27_eta2p1_CrossL1;
   Bool_t          HLT_IsoMu20_eta2p1_TightChargedIsoPFTauHPS27_eta2p1_CrossL1;
   Bool_t          HLT_IsoMu20_eta2p1_LooseChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1;
   Bool_t          HLT_IsoMu20_eta2p1_MediumChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1;
   Bool_t          HLT_IsoMu20_eta2p1_TightChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_TightChargedIsoPFTauHPS35_Trk1_eta2p1_Reg_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_MediumChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_TightChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_MediumChargedIsoPFTauHPS35_Trk1_eta2p1_Reg_CrossL1;
   Bool_t          HLT_IsoMu27_LooseChargedIsoPFTauHPS20_Trk1_eta2p1_SingleL1;
   Bool_t          HLT_IsoMu27_MediumChargedIsoPFTauHPS20_Trk1_eta2p1_SingleL1;
   Bool_t          HLT_IsoMu27_TightChargedIsoPFTauHPS20_Trk1_eta2p1_SingleL1;
   Bool_t          HLT_IsoMu20;
   Bool_t          HLT_IsoMu24;
   Bool_t          HLT_IsoMu24_eta2p1;
   Bool_t          HLT_IsoMu27;
   Bool_t          HLT_IsoMu30;
   Bool_t          HLT_UncorrectedJetE30_NoBPTX;
   Bool_t          HLT_UncorrectedJetE30_NoBPTX3BX;
   Bool_t          HLT_UncorrectedJetE60_NoBPTX3BX;
   Bool_t          HLT_UncorrectedJetE70_NoBPTX3BX;
   Bool_t          HLT_L1SingleMu18;
   Bool_t          HLT_L1SingleMu25;
   Bool_t          HLT_L2Mu10;
   Bool_t          HLT_L2Mu10_NoVertex_NoBPTX3BX;
   Bool_t          HLT_L2Mu10_NoVertex_NoBPTX;
   Bool_t          HLT_L2Mu45_NoVertex_3Sta_NoBPTX3BX;
   Bool_t          HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX;
   Bool_t          HLT_L2Mu50;
   Bool_t          HLT_L2Mu23NoVtx_2Cha;
   Bool_t          HLT_L2Mu23NoVtx_2Cha_CosmicSeed;
   Bool_t          HLT_DoubleL2Mu30NoVtx_2Cha_CosmicSeed_Eta2p4;
   Bool_t          HLT_DoubleL2Mu30NoVtx_2Cha_Eta2p4;
   Bool_t          HLT_DoubleL2Mu50;
   Bool_t          HLT_DoubleL2Mu23NoVtx_2Cha_CosmicSeed;
   Bool_t          HLT_DoubleL2Mu23NoVtx_2Cha_CosmicSeed_NoL2Matched;
   Bool_t          HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed;
   Bool_t          HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed_NoL2Matched;
   Bool_t          HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed_Eta2p4;
   Bool_t          HLT_DoubleL2Mu23NoVtx_2Cha;
   Bool_t          HLT_DoubleL2Mu23NoVtx_2Cha_NoL2Matched;
   Bool_t          HLT_DoubleL2Mu25NoVtx_2Cha;
   Bool_t          HLT_DoubleL2Mu25NoVtx_2Cha_NoL2Matched;
   Bool_t          HLT_DoubleL2Mu25NoVtx_2Cha_Eta2p4;
   Bool_t          HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL;
   Bool_t          HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL;
   Bool_t          HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ;
   Bool_t          HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ;
   Bool_t          HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8;
   Bool_t          HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8;
   Bool_t          HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8;
   Bool_t          HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8;
   Bool_t          HLT_Mu25_TkMu0_Onia;
   Bool_t          HLT_Mu30_TkMu0_Psi;
   Bool_t          HLT_Mu30_TkMu0_Upsilon;
   Bool_t          HLT_Mu20_TkMu0_Phi;
   Bool_t          HLT_Mu25_TkMu0_Phi;
   Bool_t          HLT_Mu12;
   Bool_t          HLT_Mu15;
   Bool_t          HLT_Mu20;
   Bool_t          HLT_Mu27;
   Bool_t          HLT_Mu50;
   Bool_t          HLT_Mu55;
   Bool_t          HLT_OldMu100;
   Bool_t          HLT_TkMu100;
   Bool_t          HLT_DiPFJetAve40;
   Bool_t          HLT_DiPFJetAve60;
   Bool_t          HLT_DiPFJetAve80;
   Bool_t          HLT_DiPFJetAve140;
   Bool_t          HLT_DiPFJetAve200;
   Bool_t          HLT_DiPFJetAve260;
   Bool_t          HLT_DiPFJetAve320;
   Bool_t          HLT_DiPFJetAve400;
   Bool_t          HLT_DiPFJetAve500;
   Bool_t          HLT_DiPFJetAve60_HFJEC;
   Bool_t          HLT_DiPFJetAve80_HFJEC;
   Bool_t          HLT_DiPFJetAve100_HFJEC;
   Bool_t          HLT_DiPFJetAve160_HFJEC;
   Bool_t          HLT_DiPFJetAve220_HFJEC;
   Bool_t          HLT_DiPFJetAve300_HFJEC;
   Bool_t          HLT_AK8PFJet15;
   Bool_t          HLT_AK8PFJet25;
   Bool_t          HLT_AK8PFJet40;
   Bool_t          HLT_AK8PFJet60;
   Bool_t          HLT_AK8PFJet80;
   Bool_t          HLT_AK8PFJet140;
   Bool_t          HLT_AK8PFJet200;
   Bool_t          HLT_AK8PFJet260;
   Bool_t          HLT_AK8PFJet320;
   Bool_t          HLT_AK8PFJet400;
   Bool_t          HLT_AK8PFJet450;
   Bool_t          HLT_AK8PFJet500;
   Bool_t          HLT_AK8PFJet550;
   Bool_t          HLT_PFJet15;
   Bool_t          HLT_PFJet25;
   Bool_t          HLT_PFJet40;
   Bool_t          HLT_PFJet60;
   Bool_t          HLT_PFJet80;
   Bool_t          HLT_PFJet140;
   Bool_t          HLT_PFJet200;
   Bool_t          HLT_PFJet260;
   Bool_t          HLT_PFJet320;
   Bool_t          HLT_PFJet400;
   Bool_t          HLT_PFJet450;
   Bool_t          HLT_PFJet500;
   Bool_t          HLT_PFJet550;
   Bool_t          HLT_PFJetFwd15;
   Bool_t          HLT_PFJetFwd25;
   Bool_t          HLT_PFJetFwd40;
   Bool_t          HLT_PFJetFwd60;
   Bool_t          HLT_PFJetFwd80;
   Bool_t          HLT_PFJetFwd140;
   Bool_t          HLT_PFJetFwd200;
   Bool_t          HLT_PFJetFwd260;
   Bool_t          HLT_PFJetFwd320;
   Bool_t          HLT_PFJetFwd400;
   Bool_t          HLT_PFJetFwd450;
   Bool_t          HLT_PFJetFwd500;
   Bool_t          HLT_AK8PFJetFwd15;
   Bool_t          HLT_AK8PFJetFwd25;
   Bool_t          HLT_AK8PFJetFwd40;
   Bool_t          HLT_AK8PFJetFwd60;
   Bool_t          HLT_AK8PFJetFwd80;
   Bool_t          HLT_AK8PFJetFwd140;
   Bool_t          HLT_AK8PFJetFwd200;
   Bool_t          HLT_AK8PFJetFwd260;
   Bool_t          HLT_AK8PFJetFwd320;
   Bool_t          HLT_AK8PFJetFwd400;
   Bool_t          HLT_AK8PFJetFwd450;
   Bool_t          HLT_AK8PFJetFwd500;
   Bool_t          HLT_PFHT180;
   Bool_t          HLT_PFHT250;
   Bool_t          HLT_PFHT370;
   Bool_t          HLT_PFHT430;
   Bool_t          HLT_PFHT510;
   Bool_t          HLT_PFHT590;
   Bool_t          HLT_PFHT680;
   Bool_t          HLT_PFHT780;
   Bool_t          HLT_PFHT890;
   Bool_t          HLT_PFHT1050;
   Bool_t          HLT_PFHT500_PFMET100_PFMHT100_IDTight;
   Bool_t          HLT_PFHT500_PFMET110_PFMHT110_IDTight;
   Bool_t          HLT_PFHT700_PFMET85_PFMHT85_IDTight;
   Bool_t          HLT_PFHT700_PFMET95_PFMHT95_IDTight;
   Bool_t          HLT_PFHT800_PFMET75_PFMHT75_IDTight;
   Bool_t          HLT_PFHT800_PFMET85_PFMHT85_IDTight;
   Bool_t          HLT_PFMET110_PFMHT110_IDTight;
   Bool_t          HLT_PFMET120_PFMHT120_IDTight;
   Bool_t          HLT_PFMET130_PFMHT130_IDTight;
   Bool_t          HLT_PFMET140_PFMHT140_IDTight;
   Bool_t          HLT_PFMET100_PFMHT100_IDTight_CaloBTagDeepCSV_3p1;
   Bool_t          HLT_PFMET110_PFMHT110_IDTight_CaloBTagDeepCSV_3p1;
   Bool_t          HLT_PFMET120_PFMHT120_IDTight_CaloBTagDeepCSV_3p1;
   Bool_t          HLT_PFMET130_PFMHT130_IDTight_CaloBTagDeepCSV_3p1;
   Bool_t          HLT_PFMET140_PFMHT140_IDTight_CaloBTagDeepCSV_3p1;
   Bool_t          HLT_PFMET120_PFMHT120_IDTight_PFHT60;
   Bool_t          HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60;
   Bool_t          HLT_PFMETTypeOne120_PFMHT120_IDTight_PFHT60;
   Bool_t          HLT_PFMETTypeOne110_PFMHT110_IDTight;
   Bool_t          HLT_PFMETTypeOne120_PFMHT120_IDTight;
   Bool_t          HLT_PFMETTypeOne130_PFMHT130_IDTight;
   Bool_t          HLT_PFMETTypeOne140_PFMHT140_IDTight;
   Bool_t          HLT_PFMETNoMu110_PFMHTNoMu110_IDTight;
   Bool_t          HLT_PFMETNoMu120_PFMHTNoMu120_IDTight;
   Bool_t          HLT_PFMETNoMu130_PFMHTNoMu130_IDTight;
   Bool_t          HLT_PFMETNoMu140_PFMHTNoMu140_IDTight;
   Bool_t          HLT_MonoCentralPFJet80_PFMETNoMu110_PFMHTNoMu110_IDTight;
   Bool_t          HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight;
   Bool_t          HLT_MonoCentralPFJet80_PFMETNoMu130_PFMHTNoMu130_IDTight;
   Bool_t          HLT_MonoCentralPFJet80_PFMETNoMu140_PFMHTNoMu140_IDTight;
   Bool_t          HLT_L1ETMHadSeeds;
   Bool_t          HLT_CaloMHT90;
   Bool_t          HLT_CaloMET80_NotCleaned;
   Bool_t          HLT_CaloMET90_NotCleaned;
   Bool_t          HLT_CaloMET100_NotCleaned;
   Bool_t          HLT_CaloMET110_NotCleaned;
   Bool_t          HLT_CaloMET250_NotCleaned;
   Bool_t          HLT_CaloMET70_HBHECleaned;
   Bool_t          HLT_CaloMET80_HBHECleaned;
   Bool_t          HLT_CaloMET90_HBHECleaned;
   Bool_t          HLT_CaloMET100_HBHECleaned;
   Bool_t          HLT_CaloMET250_HBHECleaned;
   Bool_t          HLT_CaloMET300_HBHECleaned;
   Bool_t          HLT_CaloMET350_HBHECleaned;
   Bool_t          HLT_PFMET200_NotCleaned;
   Bool_t          HLT_PFMET200_HBHECleaned;
   Bool_t          HLT_PFMET250_HBHECleaned;
   Bool_t          HLT_PFMET300_HBHECleaned;
   Bool_t          HLT_PFMET200_HBHE_BeamHaloCleaned;
   Bool_t          HLT_PFMETTypeOne200_HBHE_BeamHaloCleaned;
   Bool_t          HLT_MET105_IsoTrk50;
   Bool_t          HLT_MET120_IsoTrk50;
   Bool_t          HLT_SingleJet30_Mu12_SinglePFJet40;
   Bool_t          HLT_Mu12_DoublePFJets40_CaloBTagDeepCSV_p71;
   Bool_t          HLT_Mu12_DoublePFJets100_CaloBTagDeepCSV_p71;
   Bool_t          HLT_Mu12_DoublePFJets200_CaloBTagDeepCSV_p71;
   Bool_t          HLT_Mu12_DoublePFJets350_CaloBTagDeepCSV_p71;
   Bool_t          HLT_Mu12_DoublePFJets40MaxDeta1p6_DoubleCaloBTagDeepCSV_p71;
   Bool_t          HLT_Mu12_DoublePFJets54MaxDeta1p6_DoubleCaloBTagDeepCSV_p71;
   Bool_t          HLT_Mu12_DoublePFJets62MaxDeta1p6_DoubleCaloBTagDeepCSV_p71;
   Bool_t          HLT_DoublePFJets40_CaloBTagDeepCSV_p71;
   Bool_t          HLT_DoublePFJets100_CaloBTagDeepCSV_p71;
   Bool_t          HLT_DoublePFJets200_CaloBTagDeepCSV_p71;
   Bool_t          HLT_DoublePFJets350_CaloBTagDeepCSV_p71;
   Bool_t          HLT_DoublePFJets116MaxDeta1p6_DoubleCaloBTagDeepCSV_p71;
   Bool_t          HLT_DoublePFJets128MaxDeta1p6_DoubleCaloBTagDeepCSV_p71;
   Bool_t          HLT_Photon300_NoHE;
   Bool_t          HLT_Mu8_TrkIsoVVL;
   Bool_t          HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ;
   Bool_t          HLT_Mu8_DiEle12_CaloIdL_TrackIdL;
   Bool_t          HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ;
   Bool_t          HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_CaloDiJet30;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBtagDeepCSV_1p5;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_CaloDiJet30_CaloBtagDeepCSV_1p5;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL;
   Bool_t          HLT_Mu17_TrkIsoVVL;
   Bool_t          HLT_Mu19_TrkIsoVVL;
   Bool_t          HLT_BTagMu_AK4DiJet20_Mu5;
   Bool_t          HLT_BTagMu_AK4DiJet40_Mu5;
   Bool_t          HLT_BTagMu_AK4DiJet70_Mu5;
   Bool_t          HLT_BTagMu_AK4DiJet110_Mu5;
   Bool_t          HLT_BTagMu_AK4DiJet170_Mu5;
   Bool_t          HLT_BTagMu_AK4Jet300_Mu5;
   Bool_t          HLT_BTagMu_AK8DiJet170_Mu5;
   Bool_t          HLT_BTagMu_AK8Jet170_DoubleMu5;
   Bool_t          HLT_BTagMu_AK8Jet300_Mu5;
   Bool_t          HLT_BTagMu_AK4DiJet20_Mu5_noalgo;
   Bool_t          HLT_BTagMu_AK4DiJet40_Mu5_noalgo;
   Bool_t          HLT_BTagMu_AK4DiJet70_Mu5_noalgo;
   Bool_t          HLT_BTagMu_AK4DiJet110_Mu5_noalgo;
   Bool_t          HLT_BTagMu_AK4DiJet170_Mu5_noalgo;
   Bool_t          HLT_BTagMu_AK4Jet300_Mu5_noalgo;
   Bool_t          HLT_BTagMu_AK8DiJet170_Mu5_noalgo;
   Bool_t          HLT_BTagMu_AK8Jet170_DoubleMu5_noalgo;
   Bool_t          HLT_BTagMu_AK8Jet300_Mu5_noalgo;
   Bool_t          HLT_Ele15_Ele8_CaloIdL_TrackIdL_IsoVL;
   Bool_t          HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;
   Bool_t          HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL;
   Bool_t          HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;
   Bool_t          HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL;
   Bool_t          HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL;
   Bool_t          HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ;
   Bool_t          HLT_Mu12_DoublePhoton20;
   Bool_t          HLT_TriplePhoton_20_20_20_CaloIdLV2;
   Bool_t          HLT_TriplePhoton_20_20_20_CaloIdLV2_R9IdVL;
   Bool_t          HLT_TriplePhoton_30_30_10_CaloIdLV2;
   Bool_t          HLT_TriplePhoton_30_30_10_CaloIdLV2_R9IdVL;
   Bool_t          HLT_TriplePhoton_35_35_5_CaloIdLV2_R9IdVL;
   Bool_t          HLT_Photon20;
   Bool_t          HLT_Photon33;
   Bool_t          HLT_Photon50;
   Bool_t          HLT_Photon75;
   Bool_t          HLT_Photon90;
   Bool_t          HLT_Photon120;
   Bool_t          HLT_Photon150;
   Bool_t          HLT_Photon175;
   Bool_t          HLT_Photon200;
   Bool_t          HLT_Photon100EB_TightID_TightIso;
   Bool_t          HLT_Photon110EB_TightID_TightIso;
   Bool_t          HLT_Photon120EB_TightID_TightIso;
   Bool_t          HLT_Photon100EBHE10;
   Bool_t          HLT_Photon100EEHE10;
   Bool_t          HLT_Photon100EE_TightID_TightIso;
   Bool_t          HLT_Photon50_R9Id90_HE10_IsoM;
   Bool_t          HLT_Photon75_R9Id90_HE10_IsoM;
   Bool_t          HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_CaloMJJ300_PFJetsMJJ400DEta3;
   Bool_t          HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_CaloMJJ400_PFJetsMJJ600DEta3;
   Bool_t          HLT_Photon90_R9Id90_HE10_IsoM;
   Bool_t          HLT_Photon120_R9Id90_HE10_IsoM;
   Bool_t          HLT_Photon165_R9Id90_HE10_IsoM;
   Bool_t          HLT_Photon90_CaloIdL_PFHT700;
   Bool_t          HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90;
   Bool_t          HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95;
   Bool_t          HLT_DiphotonMVA14p25_Mass90;
   Bool_t          HLT_DiphotonMVA14p25_Tight_Mass90;
   Bool_t          HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55;
   Bool_t          HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55;
   Bool_t          HLT_Photon35_TwoProngs35;
   Bool_t          HLT_IsoMu24_TwoProngs35;
   Bool_t          HLT_Dimuon0_Jpsi_L1_NoOS;
   Bool_t          HLT_Dimuon0_Jpsi_NoVertexing_NoOS;
   Bool_t          HLT_Dimuon0_Jpsi;
   Bool_t          HLT_Dimuon0_Jpsi_NoVertexing;
   Bool_t          HLT_Dimuon0_Jpsi_L1_4R_0er1p5R;
   Bool_t          HLT_Dimuon0_Jpsi_NoVertexing_L1_4R_0er1p5R;
   Bool_t          HLT_Dimuon0_Jpsi3p5_Muon2;
   Bool_t          HLT_Dimuon0_Upsilon_L1_4p5;
   Bool_t          HLT_Dimuon0_Upsilon_L1_5;
   Bool_t          HLT_Dimuon0_Upsilon_L1_4p5NoOS;
   Bool_t          HLT_Dimuon0_Upsilon_L1_4p5er2p0;
   Bool_t          HLT_Dimuon0_Upsilon_L1_4p5er2p0M;
   Bool_t          HLT_Dimuon0_Upsilon_NoVertexing;
   Bool_t          HLT_Dimuon0_Upsilon_L1_5M;
   Bool_t          HLT_Dimuon0_LowMass_L1_0er1p5R;
   Bool_t          HLT_Dimuon0_LowMass_L1_0er1p5;
   Bool_t          HLT_Dimuon0_LowMass;
   Bool_t          HLT_Dimuon0_LowMass_L1_4;
   Bool_t          HLT_Dimuon0_LowMass_L1_4R;
   Bool_t          HLT_Dimuon0_LowMass_L1_TM530;
   Bool_t          HLT_Dimuon0_Upsilon_Muon_L1_TM0;
   Bool_t          HLT_Dimuon0_Upsilon_Muon_NoL1Mass;
   Bool_t          HLT_TripleMu_5_3_3_Mass3p8_DZ;
   Bool_t          HLT_TripleMu_10_5_5_DZ;
   Bool_t          HLT_TripleMu_12_10_5;
   Bool_t          HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15;
   Bool_t          HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15_Charge1;
   Bool_t          HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15;
   Bool_t          HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15_Charge1;
   Bool_t          HLT_DoubleMu3_DZ_PFMET50_PFMHT60;
   Bool_t          HLT_DoubleMu3_DZ_PFMET70_PFMHT70;
   Bool_t          HLT_DoubleMu3_DZ_PFMET90_PFMHT90;
   Bool_t          HLT_DoubleMu3_Trk_Tau3mu_NoL1Mass;
   Bool_t          HLT_DoubleMu4_Jpsi_Displaced;
   Bool_t          HLT_DoubleMu4_Jpsi_NoVertexing;
   Bool_t          HLT_DoubleMu4_JpsiTrkTrk_Displaced;
   Bool_t          HLT_DoubleMu43NoFiltersNoVtx;
   Bool_t          HLT_DoubleMu48NoFiltersNoVtx;
   Bool_t          HLT_Mu43NoFiltersNoVtx_Photon43_CaloIdL;
   Bool_t          HLT_Mu48NoFiltersNoVtx_Photon48_CaloIdL;
   Bool_t          HLT_Mu38NoFiltersNoVtxDisplaced_Photon38_CaloIdL;
   Bool_t          HLT_Mu43NoFiltersNoVtxDisplaced_Photon43_CaloIdL;
   Bool_t          HLT_DoubleMu33NoFiltersNoVtxDisplaced;
   Bool_t          HLT_DoubleMu40NoFiltersNoVtxDisplaced;
   Bool_t          HLT_DoubleMu20_7_Mass0to30_L1_DM4;
   Bool_t          HLT_DoubleMu20_7_Mass0to30_L1_DM4EG;
   Bool_t          HLT_HT425;
   Bool_t          HLT_HT430_DisplacedDijet40_DisplacedTrack;
   Bool_t          HLT_HT500_DisplacedDijet40_DisplacedTrack;
   Bool_t          HLT_HT430_DisplacedDijet60_DisplacedTrack;
   Bool_t          HLT_HT400_DisplacedDijet40_DisplacedTrack;
   Bool_t          HLT_HT650_DisplacedDijet60_Inclusive;
   Bool_t          HLT_HT550_DisplacedDijet60_Inclusive;
   Bool_t          HLT_DiJet110_35_Mjj650_PFMET110;
   Bool_t          HLT_DiJet110_35_Mjj650_PFMET120;
   Bool_t          HLT_DiJet110_35_Mjj650_PFMET130;
   Bool_t          HLT_TripleJet110_35_35_Mjj650_PFMET110;
   Bool_t          HLT_TripleJet110_35_35_Mjj650_PFMET120;
   Bool_t          HLT_TripleJet110_35_35_Mjj650_PFMET130;
   Bool_t          HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned;
   Bool_t          HLT_Ele28_eta2p1_WPTight_Gsf_HT150;
   Bool_t          HLT_Ele28_HighEta_SC20_Mass55;
   Bool_t          HLT_DoubleMu20_7_Mass0to30_Photon23;
   Bool_t          HLT_Ele15_IsoVVVL_PFHT450_CaloBTagDeepCSV_4p5;
   Bool_t          HLT_Ele15_IsoVVVL_PFHT450_PFMET50;
   Bool_t          HLT_Ele15_IsoVVVL_PFHT450;
   Bool_t          HLT_Ele50_IsoVVVL_PFHT450;
   Bool_t          HLT_Ele15_IsoVVVL_PFHT600;
   Bool_t          HLT_Mu4_TrkIsoVVL_DiPFJet90_40_DEta3p5_MJJ750_HTT300_PFMETNoMu60;
   Bool_t          HLT_Mu8_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT300_PFMETNoMu60;
   Bool_t          HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60;
   Bool_t          HLT_Mu15_IsoVVVL_PFHT450_CaloBTagDeepCSV_4p5;
   Bool_t          HLT_Mu15_IsoVVVL_PFHT450_PFMET50;
   Bool_t          HLT_Mu15_IsoVVVL_PFHT450;
   Bool_t          HLT_Mu50_IsoVVVL_PFHT450;
   Bool_t          HLT_Mu15_IsoVVVL_PFHT600;
   Bool_t          HLT_Mu3er1p5_PFJet100er2p5_PFMET70_PFMHT70_IDTight;
   Bool_t          HLT_Mu3er1p5_PFJet100er2p5_PFMET80_PFMHT80_IDTight;
   Bool_t          HLT_Mu3er1p5_PFJet100er2p5_PFMET90_PFMHT90_IDTight;
   Bool_t          HLT_Mu3er1p5_PFJet100er2p5_PFMET100_PFMHT100_IDTight;
   Bool_t          HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu70_PFMHTNoMu70_IDTight;
   Bool_t          HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu80_PFMHTNoMu80_IDTight;
   Bool_t          HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu90_PFMHTNoMu90_IDTight;
   Bool_t          HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu100_PFMHTNoMu100_IDTight;
   Bool_t          HLT_Dimuon10_PsiPrime_Barrel_Seagulls;
   Bool_t          HLT_Dimuon20_Jpsi_Barrel_Seagulls;
   Bool_t          HLT_Dimuon12_Upsilon_y1p4;
   Bool_t          HLT_Dimuon14_Phi_Barrel_Seagulls;
   Bool_t          HLT_Dimuon18_PsiPrime;
   Bool_t          HLT_Dimuon25_Jpsi;
   Bool_t          HLT_Dimuon18_PsiPrime_noCorrL1;
   Bool_t          HLT_Dimuon24_Upsilon_noCorrL1;
   Bool_t          HLT_Dimuon24_Phi_noCorrL1;
   Bool_t          HLT_Dimuon25_Jpsi_noCorrL1;
   Bool_t          HLT_DiMu4_Ele9_CaloIdL_TrackIdL_DZ_Mass3p8;
   Bool_t          HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ;
   Bool_t          HLT_DiMu9_Ele9_CaloIdL_TrackIdL;
   Bool_t          HLT_DoubleIsoMu20_eta2p1;
   Bool_t          HLT_TrkMu12_DoubleTrkMu5NoFiltersNoVtx;
   Bool_t          HLT_TrkMu16_DoubleTrkMu6NoFiltersNoVtx;
   Bool_t          HLT_TrkMu17_DoubleTrkMu8NoFiltersNoVtx;
   Bool_t          HLT_Mu8;
   Bool_t          HLT_Mu17;
   Bool_t          HLT_Mu19;
   Bool_t          HLT_Mu17_Photon30_IsoCaloId;
   Bool_t          HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30;
   Bool_t          HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30;
   Bool_t          HLT_Ele15_CaloIdL_TrackIdL_IsoVL_PFJet30;
   Bool_t          HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30;
   Bool_t          HLT_Ele8_CaloIdM_TrackIdM_PFJet30;
   Bool_t          HLT_Ele17_CaloIdM_TrackIdM_PFJet30;
   Bool_t          HLT_Ele23_CaloIdM_TrackIdM_PFJet30;
   Bool_t          HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165;
   Bool_t          HLT_Ele115_CaloIdVT_GsfTrkIdT;
   Bool_t          HLT_Ele135_CaloIdVT_GsfTrkIdT;
   Bool_t          HLT_Ele145_CaloIdVT_GsfTrkIdT;
   Bool_t          HLT_Ele200_CaloIdVT_GsfTrkIdT;
   Bool_t          HLT_Ele250_CaloIdVT_GsfTrkIdT;
   Bool_t          HLT_Ele300_CaloIdVT_GsfTrkIdT;
   Bool_t          HLT_PFHT330PT30_QuadPFJet_75_60_45_40_TriplePFBTagDeepCSV_4p5;
   Bool_t          HLT_PFHT330PT30_QuadPFJet_75_60_45_40;
   Bool_t          HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94;
   Bool_t          HLT_PFHT400_SixPFJet32;
   Bool_t          HLT_PFHT450_SixPFJet36_PFBTagDeepCSV_1p59;
   Bool_t          HLT_PFHT450_SixPFJet36;
   Bool_t          HLT_PFHT350;
   Bool_t          HLT_PFHT350MinPFJet15;
   Bool_t          HLT_Photon60_R9Id90_CaloIdL_IsoL;
   Bool_t          HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL;
   Bool_t          HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL_PFHT350MinPFJet15;
   Bool_t          HLT_ECALHT800;
   Bool_t          HLT_DiSC30_18_EIso_AND_HE_Mass70;
   Bool_t          HLT_Physics;
   Bool_t          HLT_Physics_part0;
   Bool_t          HLT_Physics_part1;
   Bool_t          HLT_Physics_part2;
   Bool_t          HLT_Physics_part3;
   Bool_t          HLT_Physics_part4;
   Bool_t          HLT_Physics_part5;
   Bool_t          HLT_Physics_part6;
   Bool_t          HLT_Physics_part7;
   Bool_t          HLT_Random;
   Bool_t          HLT_ZeroBias;
   Bool_t          HLT_ZeroBias_Alignment;
   Bool_t          HLT_ZeroBias_part0;
   Bool_t          HLT_ZeroBias_part1;
   Bool_t          HLT_ZeroBias_part2;
   Bool_t          HLT_ZeroBias_part3;
   Bool_t          HLT_ZeroBias_part4;
   Bool_t          HLT_ZeroBias_part5;
   Bool_t          HLT_ZeroBias_part6;
   Bool_t          HLT_ZeroBias_part7;
   Bool_t          HLT_AK4CaloJet30;
   Bool_t          HLT_AK4CaloJet40;
   Bool_t          HLT_AK4CaloJet50;
   Bool_t          HLT_AK4CaloJet80;
   Bool_t          HLT_AK4CaloJet100;
   Bool_t          HLT_AK4CaloJet120;
   Bool_t          HLT_AK4PFJet30;
   Bool_t          HLT_AK4PFJet50;
   Bool_t          HLT_AK4PFJet80;
   Bool_t          HLT_AK4PFJet100;
   Bool_t          HLT_AK4PFJet120;
   Bool_t          HLT_SinglePhoton10_Eta3p1ForPPRef;
   Bool_t          HLT_SinglePhoton20_Eta3p1ForPPRef;
   Bool_t          HLT_SinglePhoton30_Eta3p1ForPPRef;
   Bool_t          HLT_Photon20_HoverELoose;
   Bool_t          HLT_Photon30_HoverELoose;
   Bool_t          HLT_EcalCalibration;
   Bool_t          HLT_HcalCalibration;
   Bool_t          HLT_L1UnpairedBunchBptxMinus;
   Bool_t          HLT_L1UnpairedBunchBptxPlus;
   Bool_t          HLT_L1NotBptxOR;
   Bool_t          HLT_L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142;
   Bool_t          HLT_CDC_L2cosmic_5_er1p0;
   Bool_t          HLT_CDC_L2cosmic_5p5_er1p0;
   Bool_t          HLT_HcalNZS;
   Bool_t          HLT_HcalPhiSym;
   Bool_t          HLT_HcalIsolatedbunch;
   Bool_t          HLT_IsoTrackHB;
   Bool_t          HLT_IsoTrackHE;
   Bool_t          HLT_ZeroBias_FirstCollisionAfterAbortGap;
   Bool_t          HLT_ZeroBias_IsolatedBunches;
   Bool_t          HLT_ZeroBias_FirstCollisionInTrain;
   Bool_t          HLT_ZeroBias_LastCollisionInTrain;
   Bool_t          HLT_ZeroBias_FirstBXAfterTrain;
   Bool_t          HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr;
   Bool_t          HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90;
   Bool_t          HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100;
   Bool_t          HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET110;
   Bool_t          HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET120;
   Bool_t          HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET130;
   Bool_t          HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET140;
   Bool_t          HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr;
   Bool_t          HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr;
   Bool_t          HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1;
   Bool_t          HLT_MediumChargedIsoPFTau200HighPtRelaxedIso_Trk50_eta2p1;
   Bool_t          HLT_MediumChargedIsoPFTau220HighPtRelaxedIso_Trk50_eta2p1;
   Bool_t          HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL;
   Bool_t          HLT_Rsq0p35;
   Bool_t          HLT_Rsq0p40;
   Bool_t          HLT_RsqMR300_Rsq0p09_MR200;
   Bool_t          HLT_RsqMR320_Rsq0p09_MR200;
   Bool_t          HLT_RsqMR300_Rsq0p09_MR200_4jet;
   Bool_t          HLT_RsqMR320_Rsq0p09_MR200_4jet;
   Bool_t          HLT_IsoMu27_MET90;
   Bool_t          HLT_DoubleTightChargedIsoPFTauHPS35_Trk1_eta2p1_Reg;
   Bool_t          HLT_DoubleMediumChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg;
   Bool_t          HLT_DoubleMediumChargedIsoPFTauHPS35_Trk1_eta2p1_Reg;
   Bool_t          HLT_DoubleTightChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg;
   Bool_t          HLT_DoubleMediumChargedIsoPFTauHPS40_Trk1_eta2p1_Reg;
   Bool_t          HLT_DoubleTightChargedIsoPFTauHPS40_Trk1_eta2p1_Reg;
   Bool_t          HLT_DoubleMediumChargedIsoPFTauHPS40_Trk1_TightID_eta2p1_Reg;
   Bool_t          HLT_DoubleTightChargedIsoPFTauHPS40_Trk1_TightID_eta2p1_Reg;
   Bool_t          HLT_VBF_DoubleLooseChargedIsoPFTauHPS20_Trk1_eta2p1;
   Bool_t          HLT_VBF_DoubleMediumChargedIsoPFTauHPS20_Trk1_eta2p1;
   Bool_t          HLT_VBF_DoubleTightChargedIsoPFTauHPS20_Trk1_eta2p1;
   Bool_t          HLT_Photon50_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3_PFMET50;
   Bool_t          HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3;
   Bool_t          HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ600DEta3;
   Bool_t          HLT_PFMET100_PFMHT100_IDTight_PFHT60;
   Bool_t          HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_PFHT60;
   Bool_t          HLT_PFMETTypeOne100_PFMHT100_IDTight_PFHT60;
   Bool_t          HLT_Mu18_Mu9_SameSign;
   Bool_t          HLT_Mu18_Mu9_SameSign_DZ;
   Bool_t          HLT_Mu18_Mu9;
   Bool_t          HLT_Mu18_Mu9_DZ;
   Bool_t          HLT_Mu20_Mu10_SameSign;
   Bool_t          HLT_Mu20_Mu10_SameSign_DZ;
   Bool_t          HLT_Mu20_Mu10;
   Bool_t          HLT_Mu20_Mu10_DZ;
   Bool_t          HLT_Mu23_Mu12_SameSign;
   Bool_t          HLT_Mu23_Mu12_SameSign_DZ;
   Bool_t          HLT_Mu23_Mu12;
   Bool_t          HLT_Mu23_Mu12_DZ;
   Bool_t          HLT_DoubleMu2_Jpsi_DoubleTrk1_Phi1p05;
   Bool_t          HLT_DoubleMu2_Jpsi_DoubleTkMu0_Phi;
   Bool_t          HLT_DoubleMu3_DCA_PFMET50_PFMHT60;
   Bool_t          HLT_TripleMu_5_3_3_Mass3p8_DCA;
   Bool_t          HLT_QuadPFJet98_83_71_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1;
   Bool_t          HLT_QuadPFJet103_88_75_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1;
   Bool_t          HLT_QuadPFJet111_90_80_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1;
   Bool_t          HLT_QuadPFJet98_83_71_15_PFBTagDeepCSV_1p3_VBF2;
   Bool_t          HLT_QuadPFJet103_88_75_15_PFBTagDeepCSV_1p3_VBF2;
   Bool_t          HLT_QuadPFJet105_88_76_15_PFBTagDeepCSV_1p3_VBF2;
   Bool_t          HLT_QuadPFJet111_90_80_15_PFBTagDeepCSV_1p3_VBF2;
   Bool_t          HLT_QuadPFJet98_83_71_15;
   Bool_t          HLT_QuadPFJet103_88_75_15;
   Bool_t          HLT_QuadPFJet105_88_76_15;
   Bool_t          HLT_QuadPFJet111_90_80_15;
   Bool_t          HLT_AK8PFJet330_TrimMass30_PFAK8BTagDeepCSV_p17;
   Bool_t          HLT_AK8PFJet330_TrimMass30_PFAK8BTagDeepCSV_p1;
   Bool_t          HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_p02;
   Bool_t          HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_np2;
   Bool_t          HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_np4;
   Bool_t          HLT_AK8PFJet330_PFAK8BTagCSV_p17;
   Bool_t          HLT_AK8DiPFJet300_200_TrimMass30_BTagCSV_p20;
   Bool_t          HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p087;
   Bool_t          HLT_AK8DiPFJet300_200_TrimMass30_BTagCSV_p087;
   Bool_t          HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20;
   Bool_t          HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20;
   Bool_t          HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20;
   Bool_t          HLT_Diphoton30_18_R9IdL_AND_HE_AND_IsoCaloId_NoPixelVeto_Mass55;
   Bool_t          HLT_Diphoton30_18_R9IdL_AND_HE_AND_IsoCaloId_NoPixelVeto;
   Bool_t          HLT_Mu12_IP6_part0;
   Bool_t          HLT_Mu12_IP6_part1;
   Bool_t          HLT_Mu12_IP6_part2;
   Bool_t          HLT_Mu12_IP6_part3;
   Bool_t          HLT_Mu12_IP6_part4;
   Bool_t          HLT_Mu9_IP5_part0;
   Bool_t          HLT_Mu9_IP5_part1;
   Bool_t          HLT_Mu9_IP5_part2;
   Bool_t          HLT_Mu9_IP5_part3;
   Bool_t          HLT_Mu9_IP5_part4;
   Bool_t          HLT_Mu7_IP4_part0;
   Bool_t          HLT_Mu7_IP4_part1;
   Bool_t          HLT_Mu7_IP4_part2;
   Bool_t          HLT_Mu7_IP4_part3;
   Bool_t          HLT_Mu7_IP4_part4;
   Bool_t          HLT_Mu9_IP4_part0;
   Bool_t          HLT_Mu9_IP4_part1;
   Bool_t          HLT_Mu9_IP4_part2;
   Bool_t          HLT_Mu9_IP4_part3;
   Bool_t          HLT_Mu9_IP4_part4;
   Bool_t          HLT_Mu8_IP5_part0;
   Bool_t          HLT_Mu8_IP5_part1;
   Bool_t          HLT_Mu8_IP5_part2;
   Bool_t          HLT_Mu8_IP5_part3;
   Bool_t          HLT_Mu8_IP5_part4;
   Bool_t          HLT_Mu8_IP6_part0;
   Bool_t          HLT_Mu8_IP6_part1;
   Bool_t          HLT_Mu8_IP6_part2;
   Bool_t          HLT_Mu8_IP6_part3;
   Bool_t          HLT_Mu8_IP6_part4;
   Bool_t          HLT_Mu9_IP6_part0;
   Bool_t          HLT_Mu9_IP6_part1;
   Bool_t          HLT_Mu9_IP6_part2;
   Bool_t          HLT_Mu9_IP6_part3;
   Bool_t          HLT_Mu9_IP6_part4;
   Bool_t          HLT_Mu8_IP3_part0;
   Bool_t          HLT_Mu8_IP3_part1;
   Bool_t          HLT_Mu8_IP3_part2;
   Bool_t          HLT_Mu8_IP3_part3;
   Bool_t          HLT_Mu8_IP3_part4;
   Bool_t          HLT_QuadPFJet105_88_76_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1;
   Bool_t          HLT_TrkMu6NoFiltersNoVtx;
   Bool_t          HLT_TrkMu16NoFiltersNoVtx;
   Bool_t          HLT_DoubleTrkMu_16_6_NoFiltersNoVtx;
   Bool_t          HLT_QuadPFJet70_50_40_30;
   Bool_t          HLT_QuadPFJet70_50_40_30_PFBTagParticleNet_2BTagSum0p65;
   Bool_t          HLT_QuadPFJet70_50_40_35_PFBTagParticleNet_2BTagSum0p65;
   Bool_t          HLT_QuadPFJet70_50_45_35_PFBTagParticleNet_2BTagSum0p65;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBTagParticleNet_2BTagSum0p65;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_QuadPFJet70_50_40_30;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_QuadPFJet70_50_40_30_PFBTagParticleNet_2BTagSum0p65;
   Bool_t          HLT_AK8PFJet230_SoftDropMass40;
   Bool_t          HLT_AK8PFJet230_SoftDropMass40_PFAK8ParticleNetBB0p35;
   Bool_t          HLT_AK8PFJet250_SoftDropMass40_PFAK8ParticleNetBB0p35;
   Bool_t          HLT_AK8PFJet275_SoftDropMass40_PFAK8ParticleNetBB0p35;
   Bool_t          HLT_AK8PFJet400_SoftDropMass40;
   Bool_t          HLT_AK8PFJet425_SoftDropMass40;
   Bool_t          HLT_AK8PFJet450_SoftDropMass40;
   Bool_t          HLT_AK8PFJet230_SoftDropMass40_PFAK8ParticleNetTauTau0p30;
   Bool_t          HLT_AK8PFJet250_SoftDropMass40_PFAK8ParticleNetTauTau0p30;
   Bool_t          HLT_AK8PFJet275_SoftDropMass40_PFAK8ParticleNetTauTau0p30;
   Bool_t          HLT_IsoMu50_AK8PFJet230_SoftDropMass40;
   Bool_t          HLT_IsoMu50_AK8PFJet230_SoftDropMass40_PFAK8ParticleNetBB0p35;
   Bool_t          HLT_Ele50_CaloIdVT_GsfTrkIdT_AK8PFJet230_SoftDropMass40;
   Bool_t          HLT_Ele50_CaloIdVT_GsfTrkIdT_AK8PFJet230_SoftDropMass40_PFAK8ParticleNetBB0p35;
   Bool_t          HLTriggerFinalPath;
   Bool_t          Flag_HBHENoiseFilter;
   Bool_t          Flag_HBHENoiseIsoFilter;
   Bool_t          Flag_CSCTightHaloFilter;
   Bool_t          Flag_CSCTightHaloTrkMuUnvetoFilter;
   Bool_t          Flag_CSCTightHalo2015Filter;
   Bool_t          Flag_globalTightHalo2016Filter;
   Bool_t          Flag_globalSuperTightHalo2016Filter;
   Bool_t          Flag_HcalStripHaloFilter;
   Bool_t          Flag_hcalLaserEventFilter;
   Bool_t          Flag_EcalDeadCellTriggerPrimitiveFilter;
   Bool_t          Flag_EcalDeadCellBoundaryEnergyFilter;
   Bool_t          Flag_ecalBadCalibFilter;
   Bool_t          Flag_goodVertices;
   Bool_t          Flag_eeBadScFilter;
   Bool_t          Flag_ecalLaserCorrFilter;
   Bool_t          Flag_trkPOGFilters;
   Bool_t          Flag_chargedHadronTrackResolutionFilter;
   Bool_t          Flag_muonBadTrackFilter;
   Bool_t          Flag_BadChargedCandidateFilter;
   Bool_t          Flag_BadPFMuonFilter;
   Bool_t          Flag_BadChargedCandidateSummer16Filter;
   Bool_t          Flag_BadPFMuonSummer16Filter;
   Bool_t          Flag_trkPOG_manystripclus53X;
   Bool_t          Flag_trkPOG_toomanystripclus53X;
   Bool_t          Flag_trkPOG_logErrorTooManyClusters;
   Bool_t          Flag_METFilters;
   Bool_t          L1Reco_step;
   Bool_t          L1_AlwaysTrue;
   Bool_t          L1_BPTX_AND_Ref1_VME;
   Bool_t          L1_BPTX_AND_Ref3_VME;
   Bool_t          L1_BPTX_AND_Ref4_VME;
   Bool_t          L1_BPTX_BeamGas_B1_VME;
   Bool_t          L1_BPTX_BeamGas_B2_VME;
   Bool_t          L1_BPTX_BeamGas_Ref1_VME;
   Bool_t          L1_BPTX_BeamGas_Ref2_VME;
   Bool_t          L1_BPTX_NotOR_VME;
   Bool_t          L1_BPTX_OR_Ref3_VME;
   Bool_t          L1_BPTX_OR_Ref4_VME;
   Bool_t          L1_BPTX_RefAND_VME;
   Bool_t          L1_BptxMinus;
   Bool_t          L1_BptxOR;
   Bool_t          L1_BptxPlus;
   Bool_t          L1_BptxXOR;
   Bool_t          L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142;
   Bool_t          L1_DoubleEG8er2p5_HTT260er;
   Bool_t          L1_DoubleEG8er2p5_HTT280er;
   Bool_t          L1_DoubleEG8er2p5_HTT300er;
   Bool_t          L1_DoubleEG8er2p5_HTT320er;
   Bool_t          L1_DoubleEG8er2p5_HTT340er;
   Bool_t          L1_DoubleEG_15_10_er2p5;
   Bool_t          L1_DoubleEG_20_10_er2p5;
   Bool_t          L1_DoubleEG_22_10_er2p5;
   Bool_t          L1_DoubleEG_25_12_er2p5;
   Bool_t          L1_DoubleEG_25_14_er2p5;
   Bool_t          L1_DoubleEG_27_14_er2p5;
   Bool_t          L1_DoubleEG_LooseIso20_10_er2p5;
   Bool_t          L1_DoubleEG_LooseIso22_10_er2p5;
   Bool_t          L1_DoubleEG_LooseIso22_12_er2p5;
   Bool_t          L1_DoubleEG_LooseIso25_12_er2p5;
   Bool_t          L1_DoubleIsoTau32er2p1;
   Bool_t          L1_DoubleIsoTau34er2p1;
   Bool_t          L1_DoubleIsoTau36er2p1;
   Bool_t          L1_DoubleJet100er2p3_dEta_Max1p6;
   Bool_t          L1_DoubleJet100er2p5;
   Bool_t          L1_DoubleJet112er2p3_dEta_Max1p6;
   Bool_t          L1_DoubleJet120er2p5;
   Bool_t          L1_DoubleJet150er2p5;
   Bool_t          L1_DoubleJet30er2p5_Mass_Min150_dEta_Max1p5;
   Bool_t          L1_DoubleJet30er2p5_Mass_Min200_dEta_Max1p5;
   Bool_t          L1_DoubleJet30er2p5_Mass_Min250_dEta_Max1p5;
   Bool_t          L1_DoubleJet30er2p5_Mass_Min300_dEta_Max1p5;
   Bool_t          L1_DoubleJet30er2p5_Mass_Min330_dEta_Max1p5;
   Bool_t          L1_DoubleJet30er2p5_Mass_Min360_dEta_Max1p5;
   Bool_t          L1_DoubleJet35_Mass_Min450_IsoTau45_RmOvlp;
   Bool_t          L1_DoubleJet40er2p5;
   Bool_t          L1_DoubleJet_100_30_DoubleJet30_Mass_Min620;
   Bool_t          L1_DoubleJet_110_35_DoubleJet35_Mass_Min620;
   Bool_t          L1_DoubleJet_115_40_DoubleJet40_Mass_Min620;
   Bool_t          L1_DoubleJet_115_40_DoubleJet40_Mass_Min620_Jet60TT28;
   Bool_t          L1_DoubleJet_120_45_DoubleJet45_Mass_Min620;
   Bool_t          L1_DoubleJet_120_45_DoubleJet45_Mass_Min620_Jet60TT28;
   Bool_t          L1_DoubleJet_80_30_Mass_Min420_DoubleMu0_SQ;
   Bool_t          L1_DoubleJet_80_30_Mass_Min420_IsoTau40_RmOvlp;
   Bool_t          L1_DoubleJet_80_30_Mass_Min420_Mu8;
   Bool_t          L1_DoubleJet_90_30_DoubleJet30_Mass_Min620;
   Bool_t          L1_DoubleLooseIsoEG22er2p1;
   Bool_t          L1_DoubleLooseIsoEG24er2p1;
   Bool_t          L1_DoubleMu0;
   Bool_t          L1_DoubleMu0_Mass_Min1;
   Bool_t          L1_DoubleMu0_OQ;
   Bool_t          L1_DoubleMu0_SQ;
   Bool_t          L1_DoubleMu0_SQ_OS;
   Bool_t          L1_DoubleMu0_dR_Max1p6_Jet90er2p5_dR_Max0p8;
   Bool_t          L1_DoubleMu0er1p4_SQ_OS_dR_Max1p4;
   Bool_t          L1_DoubleMu0er1p5_SQ;
   Bool_t          L1_DoubleMu0er1p5_SQ_OS;
   Bool_t          L1_DoubleMu0er1p5_SQ_OS_dR_Max1p4;
   Bool_t          L1_DoubleMu0er1p5_SQ_dR_Max1p4;
   Bool_t          L1_DoubleMu0er2p0_SQ_OS_dR_Max1p4;
   Bool_t          L1_DoubleMu0er2p0_SQ_dR_Max1p4;
   Bool_t          L1_DoubleMu10_SQ;
   Bool_t          L1_DoubleMu18er2p1;
   Bool_t          L1_DoubleMu3_OS_DoubleEG7p5Upsilon;
   Bool_t          L1_DoubleMu3_SQ_ETMHF50_HTT60er;
   Bool_t          L1_DoubleMu3_SQ_ETMHF50_Jet60er2p5;
   Bool_t          L1_DoubleMu3_SQ_ETMHF50_Jet60er2p5_OR_DoubleJet40er2p5;
   Bool_t          L1_DoubleMu3_SQ_ETMHF60_Jet60er2p5;
   Bool_t          L1_DoubleMu3_SQ_HTT220er;
   Bool_t          L1_DoubleMu3_SQ_HTT240er;
   Bool_t          L1_DoubleMu3_SQ_HTT260er;
   Bool_t          L1_DoubleMu3_dR_Max1p6_Jet90er2p5_dR_Max0p8;
   Bool_t          L1_DoubleMu4_SQ_EG9er2p5;
   Bool_t          L1_DoubleMu4_SQ_OS;
   Bool_t          L1_DoubleMu4_SQ_OS_dR_Max1p2;
   Bool_t          L1_DoubleMu4p5_SQ_OS;
   Bool_t          L1_DoubleMu4p5_SQ_OS_dR_Max1p2;
   Bool_t          L1_DoubleMu4p5er2p0_SQ_OS;
   Bool_t          L1_DoubleMu4p5er2p0_SQ_OS_Mass7to18;
   Bool_t          L1_DoubleMu5Upsilon_OS_DoubleEG3;
   Bool_t          L1_DoubleMu5_SQ_EG9er2p5;
   Bool_t          L1_DoubleMu9_SQ;
   Bool_t          L1_DoubleMu_12_5;
   Bool_t          L1_DoubleMu_15_5_SQ;
   Bool_t          L1_DoubleMu_15_7;
   Bool_t          L1_DoubleMu_15_7_Mass_Min1;
   Bool_t          L1_DoubleMu_15_7_SQ;
   Bool_t          L1_DoubleTau70er2p1;
   Bool_t          L1_ETM120;
   Bool_t          L1_ETM150;
   Bool_t          L1_ETMHF100;
   Bool_t          L1_ETMHF100_HTT60er;
   Bool_t          L1_ETMHF110;
   Bool_t          L1_ETMHF110_HTT60er;
   Bool_t          L1_ETMHF110_HTT60er_NotSecondBunchInTrain;
   Bool_t          L1_ETMHF120;
   Bool_t          L1_ETMHF120_HTT60er;
   Bool_t          L1_ETMHF120_NotSecondBunchInTrain;
   Bool_t          L1_ETMHF130;
   Bool_t          L1_ETMHF130_HTT60er;
   Bool_t          L1_ETMHF140;
   Bool_t          L1_ETMHF150;
   Bool_t          L1_ETMHF90_HTT60er;
   Bool_t          L1_ETT1200;
   Bool_t          L1_ETT1600;
   Bool_t          L1_ETT2000;
   Bool_t          L1_FirstBunchAfterTrain;
   Bool_t          L1_FirstBunchBeforeTrain;
   Bool_t          L1_FirstBunchInTrain;
   Bool_t          L1_FirstCollisionInOrbit;
   Bool_t          L1_FirstCollisionInTrain;
   Bool_t          L1_HCAL_LaserMon_Trig;
   Bool_t          L1_HCAL_LaserMon_Veto;
   Bool_t          L1_HTT120er;
   Bool_t          L1_HTT160er;
   Bool_t          L1_HTT200er;
   Bool_t          L1_HTT255er;
   Bool_t          L1_HTT280er;
   Bool_t          L1_HTT280er_QuadJet_70_55_40_35_er2p4;
   Bool_t          L1_HTT320er;
   Bool_t          L1_HTT320er_QuadJet_70_55_40_40_er2p4;
   Bool_t          L1_HTT320er_QuadJet_80_60_er2p1_45_40_er2p3;
   Bool_t          L1_HTT320er_QuadJet_80_60_er2p1_50_45_er2p3;
   Bool_t          L1_HTT360er;
   Bool_t          L1_HTT400er;
   Bool_t          L1_HTT450er;
   Bool_t          L1_IsoEG32er2p5_Mt40;
   Bool_t          L1_IsoEG32er2p5_Mt44;
   Bool_t          L1_IsoEG32er2p5_Mt48;
   Bool_t          L1_IsoTau40er2p1_ETMHF100;
   Bool_t          L1_IsoTau40er2p1_ETMHF110;
   Bool_t          L1_IsoTau40er2p1_ETMHF120;
   Bool_t          L1_IsoTau40er2p1_ETMHF90;
   Bool_t          L1_IsolatedBunch;
   Bool_t          L1_LastBunchInTrain;
   Bool_t          L1_LastCollisionInTrain;
   Bool_t          L1_LooseIsoEG22er2p1_IsoTau26er2p1_dR_Min0p3;
   Bool_t          L1_LooseIsoEG22er2p1_Tau70er2p1_dR_Min0p3;
   Bool_t          L1_LooseIsoEG24er2p1_HTT100er;
   Bool_t          L1_LooseIsoEG24er2p1_IsoTau27er2p1_dR_Min0p3;
   Bool_t          L1_LooseIsoEG26er2p1_HTT100er;
   Bool_t          L1_LooseIsoEG26er2p1_Jet34er2p5_dR_Min0p3;
   Bool_t          L1_LooseIsoEG28er2p1_HTT100er;
   Bool_t          L1_LooseIsoEG28er2p1_Jet34er2p5_dR_Min0p3;
   Bool_t          L1_LooseIsoEG30er2p1_HTT100er;
   Bool_t          L1_LooseIsoEG30er2p1_Jet34er2p5_dR_Min0p3;
   Bool_t          L1_MinimumBiasHF0_AND_BptxAND;
   Bool_t          L1_Mu10er2p3_Jet32er2p3_dR_Max0p4_DoubleJet32er2p3_dEta_Max1p6;
   Bool_t          L1_Mu12er2p3_Jet40er2p1_dR_Max0p4_DoubleJet40er2p1_dEta_Max1p6;
   Bool_t          L1_Mu12er2p3_Jet40er2p3_dR_Max0p4_DoubleJet40er2p3_dEta_Max1p6;
   Bool_t          L1_Mu18er2p1_Tau24er2p1;
   Bool_t          L1_Mu18er2p1_Tau26er2p1;
   Bool_t          L1_Mu20_EG10er2p5;
   Bool_t          L1_Mu22er2p1_IsoTau32er2p1;
   Bool_t          L1_Mu22er2p1_IsoTau34er2p1;
   Bool_t          L1_Mu22er2p1_IsoTau36er2p1;
   Bool_t          L1_Mu22er2p1_IsoTau40er2p1;
   Bool_t          L1_Mu22er2p1_Tau70er2p1;
   Bool_t          L1_Mu3_Jet120er2p5_dR_Max0p4;
   Bool_t          L1_Mu3_Jet120er2p5_dR_Max0p8;
   Bool_t          L1_Mu3_Jet16er2p5_dR_Max0p4;
   Bool_t          L1_Mu3_Jet30er2p5;
   Bool_t          L1_Mu3_Jet35er2p5_dR_Max0p4;
   Bool_t          L1_Mu3_Jet60er2p5_dR_Max0p4;
   Bool_t          L1_Mu3_Jet80er2p5_dR_Max0p4;
   Bool_t          L1_Mu3er1p5_Jet100er2p5_ETMHF40;
   Bool_t          L1_Mu3er1p5_Jet100er2p5_ETMHF50;
   Bool_t          L1_Mu5_EG23er2p5;
   Bool_t          L1_Mu5_LooseIsoEG20er2p5;
   Bool_t          L1_Mu6_DoubleEG10er2p5;
   Bool_t          L1_Mu6_DoubleEG12er2p5;
   Bool_t          L1_Mu6_DoubleEG15er2p5;
   Bool_t          L1_Mu6_DoubleEG17er2p5;
   Bool_t          L1_Mu6_HTT240er;
   Bool_t          L1_Mu6_HTT250er;
   Bool_t          L1_Mu7_EG23er2p5;
   Bool_t          L1_Mu7_LooseIsoEG20er2p5;
   Bool_t          L1_Mu7_LooseIsoEG23er2p5;
   Bool_t          L1_NotBptxOR;
   Bool_t          L1_QuadJet36er2p5_IsoTau52er2p1;
   Bool_t          L1_QuadJet60er2p5;
   Bool_t          L1_QuadJet_95_75_65_20_DoubleJet_75_65_er2p5_Jet20_FWD3p0;
   Bool_t          L1_QuadMu0;
   Bool_t          L1_QuadMu0_OQ;
   Bool_t          L1_QuadMu0_SQ;
   Bool_t          L1_SecondBunchInTrain;
   Bool_t          L1_SecondLastBunchInTrain;
   Bool_t          L1_SingleEG10er2p5;
   Bool_t          L1_SingleEG15er2p5;
   Bool_t          L1_SingleEG26er2p5;
   Bool_t          L1_SingleEG34er2p5;
   Bool_t          L1_SingleEG36er2p5;
   Bool_t          L1_SingleEG38er2p5;
   Bool_t          L1_SingleEG40er2p5;
   Bool_t          L1_SingleEG42er2p5;
   Bool_t          L1_SingleEG45er2p5;
   Bool_t          L1_SingleEG50;
   Bool_t          L1_SingleEG60;
   Bool_t          L1_SingleEG8er2p5;
   Bool_t          L1_SingleIsoEG24er1p5;
   Bool_t          L1_SingleIsoEG24er2p1;
   Bool_t          L1_SingleIsoEG26er1p5;
   Bool_t          L1_SingleIsoEG26er2p1;
   Bool_t          L1_SingleIsoEG26er2p5;
   Bool_t          L1_SingleIsoEG28er1p5;
   Bool_t          L1_SingleIsoEG28er2p1;
   Bool_t          L1_SingleIsoEG28er2p5;
   Bool_t          L1_SingleIsoEG30er2p1;
   Bool_t          L1_SingleIsoEG30er2p5;
   Bool_t          L1_SingleIsoEG32er2p1;
   Bool_t          L1_SingleIsoEG32er2p5;
   Bool_t          L1_SingleIsoEG34er2p5;
   Bool_t          L1_SingleJet10erHE;
   Bool_t          L1_SingleJet120;
   Bool_t          L1_SingleJet120_FWD3p0;
   Bool_t          L1_SingleJet120er2p5;
   Bool_t          L1_SingleJet12erHE;
   Bool_t          L1_SingleJet140er2p5;
   Bool_t          L1_SingleJet140er2p5_ETMHF80;
   Bool_t          L1_SingleJet140er2p5_ETMHF90;
   Bool_t          L1_SingleJet160er2p5;
   Bool_t          L1_SingleJet180;
   Bool_t          L1_SingleJet180er2p5;
   Bool_t          L1_SingleJet200;
   Bool_t          L1_SingleJet20er2p5_NotBptxOR;
   Bool_t          L1_SingleJet20er2p5_NotBptxOR_3BX;
   Bool_t          L1_SingleJet35;
   Bool_t          L1_SingleJet35_FWD3p0;
   Bool_t          L1_SingleJet35er2p5;
   Bool_t          L1_SingleJet43er2p5_NotBptxOR_3BX;
   Bool_t          L1_SingleJet46er2p5_NotBptxOR_3BX;
   Bool_t          L1_SingleJet60;
   Bool_t          L1_SingleJet60_FWD3p0;
   Bool_t          L1_SingleJet60er2p5;
   Bool_t          L1_SingleJet8erHE;
   Bool_t          L1_SingleJet90;
   Bool_t          L1_SingleJet90_FWD3p0;
   Bool_t          L1_SingleJet90er2p5;
   Bool_t          L1_SingleLooseIsoEG28er1p5;
   Bool_t          L1_SingleLooseIsoEG30er1p5;
   Bool_t          L1_SingleMu0_BMTF;
   Bool_t          L1_SingleMu0_DQ;
   Bool_t          L1_SingleMu0_EMTF;
   Bool_t          L1_SingleMu0_OMTF;
   Bool_t          L1_SingleMu10er1p5;
   Bool_t          L1_SingleMu12_DQ_BMTF;
   Bool_t          L1_SingleMu12_DQ_EMTF;
   Bool_t          L1_SingleMu12_DQ_OMTF;
   Bool_t          L1_SingleMu12er1p5;
   Bool_t          L1_SingleMu14er1p5;
   Bool_t          L1_SingleMu15_DQ;
   Bool_t          L1_SingleMu16er1p5;
   Bool_t          L1_SingleMu18;
   Bool_t          L1_SingleMu18er1p5;
   Bool_t          L1_SingleMu20;
   Bool_t          L1_SingleMu22;
   Bool_t          L1_SingleMu22_BMTF;
   Bool_t          L1_SingleMu22_EMTF;
   Bool_t          L1_SingleMu22_OMTF;
   Bool_t          L1_SingleMu25;
   Bool_t          L1_SingleMu3;
   Bool_t          L1_SingleMu5;
   Bool_t          L1_SingleMu6er1p5;
   Bool_t          L1_SingleMu7;
   Bool_t          L1_SingleMu7_DQ;
   Bool_t          L1_SingleMu7er1p5;
   Bool_t          L1_SingleMu8er1p5;
   Bool_t          L1_SingleMu9er1p5;
   Bool_t          L1_SingleMuCosmics;
   Bool_t          L1_SingleMuCosmics_BMTF;
   Bool_t          L1_SingleMuCosmics_EMTF;
   Bool_t          L1_SingleMuCosmics_OMTF;
   Bool_t          L1_SingleMuOpen;
   Bool_t          L1_SingleMuOpen_NotBptxOR;
   Bool_t          L1_SingleMuOpen_er1p1_NotBptxOR_3BX;
   Bool_t          L1_SingleMuOpen_er1p4_NotBptxOR_3BX;
   Bool_t          L1_SingleTau120er2p1;
   Bool_t          L1_SingleTau130er2p1;
   Bool_t          L1_TOTEM_1;
   Bool_t          L1_TOTEM_2;
   Bool_t          L1_TOTEM_3;
   Bool_t          L1_TOTEM_4;
   Bool_t          L1_TripleEG16er2p5;
   Bool_t          L1_TripleEG_16_12_8_er2p5;
   Bool_t          L1_TripleEG_16_15_8_er2p5;
   Bool_t          L1_TripleEG_18_17_8_er2p5;
   Bool_t          L1_TripleEG_18_18_12_er2p5;
   Bool_t          L1_TripleJet_100_80_70_DoubleJet_80_70_er2p5;
   Bool_t          L1_TripleJet_105_85_75_DoubleJet_85_75_er2p5;
   Bool_t          L1_TripleJet_95_75_65_DoubleJet_75_65_er2p5;
   Bool_t          L1_TripleMu0;
   Bool_t          L1_TripleMu0_OQ;
   Bool_t          L1_TripleMu0_SQ;
   Bool_t          L1_TripleMu3;
   Bool_t          L1_TripleMu3_SQ;
   Bool_t          L1_TripleMu_5SQ_3SQ_0OQ;
   Bool_t          L1_TripleMu_5SQ_3SQ_0OQ_DoubleMu_5_3_SQ_OS_Mass_Max9;
   Bool_t          L1_TripleMu_5SQ_3SQ_0_DoubleMu_5_3_SQ_OS_Mass_Max9;
   Bool_t          L1_TripleMu_5_3_3;
   Bool_t          L1_TripleMu_5_3_3_SQ;
   Bool_t          L1_TripleMu_5_3p5_2p5;
   Bool_t          L1_TripleMu_5_3p5_2p5_DoubleMu_5_2p5_OS_Mass_5to17;
   Bool_t          L1_TripleMu_5_3p5_2p5_OQ_DoubleMu_5_2p5_OQ_OS_Mass_5to17;
   Bool_t          L1_TripleMu_5_4_2p5_DoubleMu_5_2p5_OS_Mass_5to17;
   Bool_t          L1_TripleMu_5_5_3;
   Bool_t          L1_UnpairedBunchBptxMinus;
   Bool_t          L1_UnpairedBunchBptxPlus;
   Bool_t          L1_ZeroBias;
   Bool_t          L1_ZeroBias_copy;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_luminosityBlock;   //!
   TBranch        *b_event;   //!
   TBranch        *b_HTXS_Higgs_pt;   //!
   TBranch        *b_HTXS_Higgs_y;   //!
   TBranch        *b_HTXS_stage1_1_cat_pTjet25GeV;   //!
   TBranch        *b_HTXS_stage1_1_cat_pTjet30GeV;   //!
   TBranch        *b_HTXS_stage1_1_fine_cat_pTjet25GeV;   //!
   TBranch        *b_HTXS_stage1_1_fine_cat_pTjet30GeV;   //!
   TBranch        *b_HTXS_stage_0;   //!
   TBranch        *b_HTXS_stage_1_pTjet25;   //!
   TBranch        *b_HTXS_stage_1_pTjet30;   //!
   TBranch        *b_HTXS_njets25;   //!
   TBranch        *b_HTXS_njets30;   //!
   TBranch        *b_btagWeight_CSVV2;   //!
   TBranch        *b_btagWeight_DeepCSVB;   //!
   TBranch        *b_CaloMET_phi;   //!
   TBranch        *b_CaloMET_pt;   //!
   TBranch        *b_CaloMET_sumEt;   //!
   TBranch        *b_ChsMET_phi;   //!
   TBranch        *b_ChsMET_pt;   //!
   TBranch        *b_ChsMET_sumEt;   //!
   TBranch        *b_nCorrT1METJet;   //!
   TBranch        *b_CorrT1METJet_area;   //!
   TBranch        *b_CorrT1METJet_eta;   //!
   TBranch        *b_CorrT1METJet_muonSubtrFactor;   //!
   TBranch        *b_CorrT1METJet_phi;   //!
   TBranch        *b_CorrT1METJet_rawPt;   //!

   TBranch *b_nAK15Puppi; //!
   TBranch *b_AK15Puppi_ParticleNetMD_probQCD;   //!
   TBranch *b_AK15Puppi_ParticleNetMD_probXbb;   //!
   TBranch *b_AK15Puppi_ParticleNetMD_probXcc;   //!
   TBranch *b_AK15Puppi_ParticleNetMD_probXqq;   //!
   TBranch *b_AK15Puppi_area                 ;   //!
   TBranch *b_AK15Puppi_btagCSVV2            ;   //!
   TBranch *b_AK15Puppi_btagDeepB            ;   //!
   TBranch *b_AK15Puppi_btagJP               ;   //!
   TBranch *b_AK15Puppi_eta                  ;   //!
   TBranch *b_AK15Puppi_mass                 ;   //!
   TBranch *b_AK15Puppi_msoftdrop            ;   //!
   TBranch *b_AK15Puppi_phi                  ;   //!
   TBranch *b_AK15Puppi_pt                   ;   //!
   TBranch *b_AK15Puppi_rawFactor            ;   //!
   TBranch *b_AK15Puppi_tau1                 ;   //!
   TBranch *b_AK15Puppi_tau2                 ;   //!
   TBranch *b_AK15Puppi_tau3                 ;   //!
   TBranch *b_AK15Puppi_jetId                ;   //!
   TBranch *b_AK15Puppi_nBHadrons            ;   //!
   TBranch *b_AK15Puppi_nCHadrons            ;   //!
   TBranch *b_AK15Puppi_nPFConstituents      ;   //!
   TBranch *b_AK15Puppi_subJetIdx1           ;   //!
   TBranch *b_AK15Puppi_subJetIdx2           ;   //!
   TBranch *b_AK15Puppi_nPFCand              ;   //!
   TBranch        *b_nSubJet;   //!
   TBranch        *b_SubJet_area;   //!
   TBranch        *b_SubJet_btagCSVV2;   //!
   TBranch        *b_SubJet_btagDeepB;   //!
   TBranch        *b_SubJet_eta;   //!
   TBranch        *b_SubJet_mass;   //!
   TBranch        *b_SubJet_phi;   //!
   TBranch        *b_SubJet_pt;   //!
   TBranch        *b_SubJet_rawFactor;   //!
   TBranch        *b_SubJet_nBHadrons;   //!
   TBranch        *b_SubJet_nCHadrons;   //!
   TBranch        *b_nFatJet;   //!
   TBranch        *b_FatJet_ParticleNetMD_probQCDb;   //!
   TBranch        *b_FatJet_ParticleNetMD_probQCDbb;   //!
   TBranch        *b_FatJet_ParticleNetMD_probQCDc;   //!
   TBranch        *b_FatJet_ParticleNetMD_probQCDcc;   //!
   TBranch        *b_FatJet_ParticleNetMD_probQCDothers;   //!
   TBranch        *b_FatJet_ParticleNetMD_probXbb;   //!
   TBranch        *b_FatJet_ParticleNetMD_probXcc;   //!
   TBranch        *b_FatJet_ParticleNetMD_probXqq;   //!
   TBranch        *b_FatJet_particleNet_massCorr;   //!
   TBranch        *b_FatJet_particleNetWithMass_HbbvsQCD;
   TBranch        *b_FatJet_particleNetWithMass_HccvsQCD;
   TBranch        *b_FatJet_particleNetWithMass_QCD;
   TBranch        *b_FatJet_particleNet_QCD;
   TBranch        *b_FatJet_particleNet_QCD0HF;
   TBranch        *b_FatJet_particleNet_QCD1HF;
   TBranch        *b_FatJet_particleNet_QCD2HF;
   TBranch        *b_FatJet_particleNet_XbbVsQCD;
   TBranch        *b_FatJet_particleNet_XccVsQCD;
   TBranch        *b_FatJet_particleNet_XggVsQCD;
   TBranch        *b_FatJet_particleNet_XqqVsQCD;
   TBranch        *b_FatJet_deepTagMD_WvsQCD;   //!
   TBranch        *b_FatJet_deepTagMD_ZvsQCD;   //!
   TBranch        *b_FatJet_deepTag_WvsQCD;   //!
   TBranch        *b_FatJet_deepTag_ZvsQCD;   //!
   TBranch        *b_FatJet_LSmsoftdrop;   //!
   TBranch        *b_FatJet_LSn2b1;   //!
   TBranch        *b_FatJet_LSn3b1;   //!
   TBranch        *b_FatJet_LSpt;   //!
   TBranch        *b_FatJet_LSrawmsoftdrop;   //!
   TBranch        *b_FatJet_LSsubJet1btagDeepB;   //!
   TBranch        *b_FatJet_LSsubJet2btagDeepB;   //!
   TBranch        *b_FatJet_LStau1;   //!
   TBranch        *b_FatJet_LStau2;   //!
   TBranch        *b_FatJet_LStau3;   //!
   TBranch        *b_FatJet_LStau4;   //!
   TBranch        *b_FatJet_area;   //!
   TBranch        *b_FatJet_btagDDBvL;   //!
   TBranch        *b_FatJet_btagDDBvLV2;
   TBranch        *b_FatJet_btagDDCvBV2;   //!
   TBranch        *b_FatJet_btagDDCvLV2;   //!
   TBranch        *b_FatJet_btagHbb;   //!
   TBranch        *b_FatJet_btagDeepB;
   TBranch        *b_FatJet_dRLep;   //!
   TBranch        *b_FatJet_deepTagHbb;   //!
   TBranch        *b_FatJet_deepTagHcc;   //!
   TBranch        *b_FatJet_deepTagHqqqq;   //!
   TBranch        *b_FatJet_deepTagMDHbb;   //!
   TBranch        *b_FatJet_deepTagMDHcc;   //!
   TBranch        *b_FatJet_deepTagMDHqqqq;   //!
   TBranch        *b_FatJet_deepTagMDQCDbb;   //!
   TBranch        *b_FatJet_deepTagMDQCDcc;   //!
   TBranch        *b_FatJet_deepTagMDWcq;   //!
   TBranch        *b_FatJet_deepTagMDWqq;   //!
   TBranch        *b_FatJet_deepTagMDZbb;   //!
   TBranch        *b_FatJet_deepTagMDZcc;   //!
   TBranch        *b_FatJet_deepTagMDZqq;   //!
   TBranch        *b_FatJet_deepTagQCDbb;   //!
   TBranch        *b_FatJet_deepTagQCDcc;   //!
   TBranch        *b_FatJet_deepTagWcq;   //!
   TBranch        *b_FatJet_deepTagWqq;   //!
   TBranch        *b_FatJet_deepTagZbb;   //!
   TBranch        *b_FatJet_deepTagZcc;   //!
   TBranch        *b_FatJet_deepTagZqq;   //!
   TBranch        *b_FatJet_eta;   //!
   TBranch        *b_FatJet_lsf3;   //!
   TBranch        *b_FatJet_mass;   //!
   TBranch        *b_FatJet_msoftdrop;   //!
   TBranch        *b_FatJet_n2b1;   //!
   TBranch        *b_FatJet_n3b1;   //!
   TBranch        *b_FatJet_phi;   //!
   TBranch        *b_FatJet_pt;   //!
   TBranch        *b_FatJet_rawFactor;   //!
   TBranch        *b_FatJet_rawmsoftdrop;   //!
   TBranch        *b_FatJet_tau1;   //!
   TBranch        *b_FatJet_tau2;   //!
   TBranch        *b_FatJet_tau3;   //!
   TBranch        *b_FatJet_tau4;   //!
   TBranch        *b_FatJet_electronIdx3SJ;   //!
   TBranch        *b_FatJet_idLep;   //!
   TBranch        *b_FatJet_jetId;   //!
   TBranch        *b_FatJet_muonIdx3SJ;   //!
   TBranch        *b_FatJet_nBHadrons;   //!
   TBranch        *b_FatJet_nCHadrons;   //!
   TBranch        *b_FatJet_nConstituents;   //!
   TBranch        *b_FatJet_subJetIdx1;   //!
   TBranch        *b_FatJet_subJetIdx2;   //!
   TBranch        *b_FatJet_genJetAK8Idx; 

   TBranch        *b_nElectron;   //!
   TBranch        *b_Electron_deltaEtaSC;   //!
   TBranch        *b_Electron_dr03EcalRecHitSumEt;   //!
   TBranch        *b_Electron_dr03HcalDepth1TowerSumEt;   //!
   TBranch        *b_Electron_dr03TkSumPt;   //!
   TBranch        *b_Electron_dr03TkSumPtHEEP;   //!
   TBranch        *b_Electron_dxy;   //!
   TBranch        *b_Electron_dxyErr;   //!
   TBranch        *b_Electron_dz;   //!
   TBranch        *b_Electron_dzErr;   //!
   TBranch        *b_Electron_eCorr;   //!
   TBranch        *b_Electron_eInvMinusPInv;   //!
   TBranch        *b_Electron_energyErr;   //!
   TBranch        *b_Electron_eta;   //!
   TBranch        *b_Electron_hoe;   //!
   TBranch        *b_Electron_ip3d;   //!
   TBranch        *b_Electron_jetPtRelv2;   //!
   TBranch        *b_Electron_jetRelIso;   //!
   TBranch        *b_Electron_mass;   //!
   TBranch        *b_Electron_miniPFRelIso_all;   //!
   TBranch        *b_Electron_miniPFRelIso_chg;   //!
   TBranch        *b_Electron_mvaFall17V1Iso;   //!
   TBranch        *b_Electron_mvaNoIso;   //!
   TBranch        *b_Electron_mvaFall17V2Iso;   //!
   TBranch        *b_Electron_mvaFall17V1noIso;   //!
   TBranch        *b_Electron_mvaFall17V2noIso;   
   TBranch        *b_Electron_pfRelIso03_all;   //!
   TBranch        *b_Electron_pfRelIso03_chg;   //!
   TBranch        *b_Electron_phi;   //!
   TBranch        *b_Electron_pt;   //!
   TBranch        *b_Electron_r9;   //!
   TBranch        *b_Electron_sieie;   //!
   TBranch        *b_Electron_sip3d;   //!
   TBranch        *b_Electron_mvaTTH;   //!
   TBranch        *b_Electron_charge;   //!
   TBranch        *b_Electron_cutBased;   //!
   TBranch        *b_Electron_cutBased_Fall17_V1;   //!
   TBranch        *b_Electron_jetIdx;   //!
   TBranch        *b_Electron_pdgId;   //!
   TBranch        *b_Electron_photonIdx;   //!
   TBranch        *b_Electron_tightCharge;   //!
   TBranch        *b_Electron_vidNestedWPBitmap;   //!
   TBranch        *b_Electron_vidNestedWPBitmapHEEP;   //!
   TBranch        *b_Electron_convVeto;   //!
   TBranch        *b_Electron_cutBased_HEEP;   //!
   TBranch        *b_Electron_isPFcand;   //!
   TBranch        *b_Electron_lostHits;   //!
   TBranch        *b_Electron_mvaFall17V1Iso_WP80;   //!
   TBranch        *b_Electron_mvaFall17V1Iso_WP90;   //!
   TBranch        *b_Electron_mvaFall17V1Iso_WPL;   //!
   TBranch        *b_Electron_mvaIso;   //!
   TBranch        *b_Electron_mvaNoIso_WP90;   //!
   TBranch        *b_Electron_mvaNoIso_WP80;   //!
   TBranch        *b_Electron_mvaIso_WP80;   //!
   TBranch        *b_Electron_mvaIso_WP90;   //!
   TBranch        *b_Electron_mvaFall17V2Iso_WPL;   //!
   TBranch        *b_Electron_mvaFall17V1noIso_WP80;   //!
   TBranch        *b_Electron_mvaFall17V2noIso_WP80; 
   TBranch        *b_Electron_mvaFall17V2noIso_WP90;   //!
   TBranch        *b_Electron_mvaFall17V2noIso_WPL;   //!
   TBranch        *b_Electron_mvaFall17V1noIso_WPL;   //!
   TBranch        *b_Electron_seedGain;   //!
   TBranch        *b_nFsrPhoton;   //!
   TBranch        *b_FsrPhoton_dROverEt2;   //!
   TBranch        *b_FsrPhoton_eta;   //!
   TBranch        *b_FsrPhoton_phi;   //!
   TBranch        *b_FsrPhoton_pt;   //!
   TBranch        *b_FsrPhoton_relIso03;   //!
   TBranch        *b_FsrPhoton_muonIdx;   //!
   TBranch        *b_nGenJetAK8;   //!
   TBranch        *b_GenJetAK8_eta;   //!
   TBranch        *b_GenJetAK8_mass;   //!
   TBranch        *b_GenJetAK8_phi;   //!
   TBranch        *b_GenJetAK8_pt;   //!
   TBranch        *b_nGenJet;   //!
   TBranch        *b_GenJet_eta;   //!
   TBranch        *b_GenJet_mass;   //!
   TBranch        *b_GenJet_phi;   //!
   TBranch        *b_GenJet_pt;   //!
   TBranch        *b_nGenPart;   //!
   TBranch        *b_GenPart_eta;   //!
   TBranch        *b_GenPart_mass;   //!
   TBranch        *b_GenPart_phi;   //!
   TBranch        *b_GenPart_pt;   //!
   TBranch        *b_GenPart_genPartIdxMother;   //!
   TBranch        *b_GenPart_pdgId;   //!
   TBranch        *b_GenPart_status;   //!
   TBranch        *b_GenPart_statusFlags;   //!
   TBranch        *b_nSubGenJetAK8;   //!
   TBranch        *b_SubGenJetAK8_eta;   //!
   TBranch        *b_SubGenJetAK8_mass;   //!
   TBranch        *b_SubGenJetAK8_phi;   //!
   TBranch        *b_SubGenJetAK8_pt;   //!
   TBranch        *b_Generator_binvar;   //!
   TBranch        *b_Generator_scalePDF;   //!
   TBranch        *b_Generator_weight;   //!
   TBranch        *b_Generator_x1;   //!
   TBranch        *b_Generator_x2;   //!
   TBranch        *b_Generator_xpdf1;   //!
   TBranch        *b_Generator_xpdf2;   //!
   TBranch        *b_Generator_id1;   //!
   TBranch        *b_Generator_id2;   //!
   TBranch        *b_nGenVisTau;   //!
   TBranch        *b_GenVisTau_eta;   //!
   TBranch        *b_GenVisTau_mass;   //!
   TBranch        *b_GenVisTau_phi;   //!
   TBranch        *b_GenVisTau_pt;   //!
   TBranch        *b_GenVisTau_charge;   //!
   TBranch        *b_GenVisTau_genPartIdxMother;   //!
   TBranch        *b_GenVisTau_status;   //!
   TBranch        *b_genWeight;   //!
   TBranch        *b_LHEWeight_originalXWGTUP;   //!
   TBranch        *b_nLHEPdfWeight;   //!
   TBranch        *b_LHEPdfWeight;   //!
   TBranch        *b_nLHEReweightingWeight;   //!
   TBranch        *b_LHEReweightingWeight;   //!
   TBranch        *b_nLHEScaleWeight;   //!
   TBranch        *b_LHEScaleWeight;   //!
   TBranch        *b_nPSWeight;   //!
   TBranch        *b_PSWeight;   //!
   TBranch        *b_nIsoTrack;   //!
   TBranch        *b_IsoTrack_dxy;   //!
   TBranch        *b_IsoTrack_dz;   //!
   TBranch        *b_IsoTrack_eta;   //!
   TBranch        *b_IsoTrack_pfRelIso03_all;   //!
   TBranch        *b_IsoTrack_pfRelIso03_chg;   //!
   TBranch        *b_IsoTrack_phi;   //!
   TBranch        *b_IsoTrack_pt;   //!
   TBranch        *b_IsoTrack_miniPFRelIso_all;   //!
   TBranch        *b_IsoTrack_miniPFRelIso_chg;   //!
   TBranch        *b_IsoTrack_fromPV;   //!
   TBranch        *b_IsoTrack_pdgId;   //!
   TBranch        *b_IsoTrack_isHighPurityTrack;   //!
   TBranch        *b_IsoTrack_isPFcand;   //!
   TBranch        *b_IsoTrack_isFromLostTrack;   //!
   TBranch        *b_nJet;   //!
   TBranch        *b_Jet_area;   //!
   TBranch        *b_Jet_btagCMVA;   //!
   TBranch        *b_Jet_btagCSVV2;   //!
   TBranch        *b_Jet_btagDeepB;   //!
   TBranch        *b_Jet_btagDeepC;   //!
   TBranch        *b_Jet_PNetRegPtRawCorr;
   TBranch        *b_Jet_PNetRegPtRawCorrNeutrino;
   TBranch        *b_Jet_PNetRegPtRawRes;
   TBranch        *b_Jet_btagDeepFlavB;   //!
   TBranch        *b_Jet_btagDeepFlavCvB;   //!
   TBranch        *b_Jet_btagDeepFlavCvL;
   TBranch        *b_Jet_btagDeepFlavQG;
   TBranch        *b_Jet_btagPNetB;
   TBranch        *b_Jet_btagPNetCvB;
   TBranch        *b_Jet_btagPNetCvL;
   TBranch        *b_Jet_btagPNetQvG;
   TBranch        *b_Jet_btagPNetTauVJet;
   TBranch        *b_Jet_btagRobustParTAK4B;
   TBranch        *b_Jet_btagRobustParTAK4CvB;
   TBranch        *b_Jet_btagRobustParTAK4CvL;
   TBranch        *b_Jet_btagRobustParTAK4QG;
   TBranch        *b_Jet_chEmEF;   //!
   TBranch        *b_Jet_chHEF;   //!
   TBranch        *b_Jet_eta;   //!
   TBranch        *b_Jet_jercCHF;   //!
   TBranch        *b_Jet_jercCHPUF;   //!
   TBranch        *b_Jet_mass;   //!
   TBranch        *b_Jet_muEF;   //!
   TBranch        *b_Jet_muonSubtrFactor;   //!
   TBranch        *b_Jet_neEmEF;   //!
   TBranch        *b_Jet_neHEF;   //!
   TBranch        *b_Jet_phi;   //!
   TBranch        *b_Jet_pt;   //!
   TBranch        *b_Jet_qgl;   //!
   TBranch        *b_Jet_rawFactor;   //!
   TBranch        *b_Jet_bRegCorr;   //!
   TBranch        *b_Jet_bRegRes;   //!
   TBranch        *b_Jet_electronIdx1;   //!
   TBranch        *b_Jet_electronIdx2;   //!
   TBranch        *b_Jet_jetId;   //!
   TBranch        *b_Jet_muonIdx1;   //!
   TBranch        *b_Jet_muonIdx2;   //!
   TBranch        *b_Jet_partonFlavour;
   TBranch        *b_Jet_nConstituents;   //!
   TBranch        *b_Jet_nElectrons;   //!
   TBranch        *b_Jet_nMuons;   //!
   TBranch        *b_Jet_puId;   //!
   TBranch        *b_LHE_HT;   //!
   TBranch        *b_LHE_HTIncoming;   //!
   TBranch        *b_LHE_Vpt;   //!
   TBranch        *b_LHE_Njets;   //!
   TBranch        *b_LHE_Nb;   //!
   TBranch        *b_LHE_Nc;   //!
   TBranch        *b_LHE_Nuds;   //!
   TBranch        *b_LHE_Nglu;   //!
   TBranch        *b_LHE_NpNLO;   //!
   TBranch        *b_LHE_NpLO;   //!
   TBranch        *b_nLHEPart;   //!
   TBranch        *b_LHEPart_pt;   //!
   TBranch        *b_LHEPart_eta;   //!
   TBranch        *b_LHEPart_phi;   //!
   TBranch        *b_LHEPart_mass;   //!
   TBranch        *b_LHEPart_pdgId;   //!
   TBranch        *b_GenMET_phi;   //!
   TBranch        *b_GenMET_pt;   //!
   TBranch        *b_MET_MetUnclustEnUpDeltaX;   //!
   TBranch        *b_MET_MetUnclustEnUpDeltaY;   //!
   TBranch        *b_MET_covXX;   //!
   TBranch        *b_MET_covXY;   //!
   TBranch        *b_MET_covYY;   //!
   TBranch        *b_MET_phi;   //!
   TBranch        *b_MET_pt;   //!
   TBranch        *b_MET_significance;   //!
   TBranch        *b_MET_sumEt;   //!
   TBranch        *b_nMuon;   //!
   TBranch        *b_Muon_dxy;   //!
   TBranch        *b_Muon_dxyErr;   //!
   TBranch        *b_Muon_dz;   //!
   TBranch        *b_Muon_dzErr;   //!
   TBranch        *b_Muon_eta;   //!
   TBranch        *b_Muon_ip3d;   //!
   TBranch        *b_Muon_jetPtRelv2;   //!
   TBranch        *b_Muon_jetRelIso;   //!
   TBranch        *b_Muon_mass;   //!
   TBranch        *b_Muon_miniPFRelIso_all;   //!
   TBranch        *b_Muon_miniPFRelIso_chg;   //!
   TBranch        *b_Muon_pfRelIso03_all;   //!
   TBranch        *b_Muon_pfRelIso03_chg;   //!
   TBranch        *b_Muon_pfRelIso04_all;   //!
   TBranch        *b_Muon_phi;   //!
   TBranch        *b_Muon_pt;   //!
   TBranch        *b_Muon_ptErr;   //!
   TBranch        *b_Muon_segmentComp;   //!
   TBranch        *b_Muon_sip3d;   //!
   TBranch        *b_Muon_softMva;   //!
   TBranch        *b_Muon_tkRelIso;   //!
   TBranch        *b_Muon_tunepRelPt;   //!
   TBranch        *b_Muon_mvaLowPt;   //!
   TBranch        *b_Muon_mvaTTH;   //!
   TBranch        *b_Muon_charge;   //!
   TBranch        *b_Muon_jetIdx;   //!
   TBranch        *b_Muon_nStations;   //!
   TBranch        *b_Muon_nTrackerLayers;   //!
   TBranch        *b_Muon_pdgId;   //!
   TBranch        *b_Muon_tightCharge;   //!
   TBranch        *b_Muon_fsrPhotonIdx;   //!
   TBranch        *b_Muon_highPtId;   //!
   TBranch        *b_Muon_inTimeMuon;   //!
   TBranch        *b_Muon_isGlobal;   //!
   TBranch        *b_Muon_isPFcand;   //!
   TBranch        *b_Muon_isTracker;   //!
   TBranch        *b_Muon_looseId;   //!
   TBranch        *b_Muon_mediumId;   //!
   TBranch        *b_Muon_mediumPromptId;   //!
   TBranch        *b_Muon_miniIsoId;   //!
   TBranch        *b_Muon_multiIsoId;   //!
   TBranch        *b_Muon_mvaMuID;   //!
   TBranch        *b_Muon_pfIsoId;   //!
   TBranch        *b_Muon_softId;   //!
   TBranch        *b_Muon_softMvaId;   //!
   TBranch        *b_Muon_tightId;   //!
   TBranch        *b_Muon_tkIsoId;   //!
   TBranch        *b_Muon_triggerIdLoose;   //!
   TBranch        *b_nPhoton;   //!
   TBranch        *b_Photon_eCorr;   //!
   TBranch        *b_Photon_energyErr;   //!
   TBranch        *b_Photon_energyRaw;
   TBranch        *b_Photon_eta;   //!
   TBranch        *b_Photon_hoe;   //!
   TBranch        *b_Photon_mass;   //!
   TBranch        *b_Photon_mvaID;   //!
   TBranch        *b_Photon_mvaIDV1;   //!
   TBranch        *b_Photon_pfChargedIso;
   TBranch        *b_Photon_pfChargedIsoPFPV;
   TBranch        *b_Photon_pfChargedIsoWorstVtx;
   TBranch        *b_Photon_pfPhoIso03;
   TBranch        *b_Photon_pfRelIso03_all_quadratic;   //!
   TBranch        *b_Photon_pfRelIso03_chg_quadratic;   //!
   TBranch        *b_Photon_phi;   //!
   TBranch        *b_Photon_pt;   //!
   TBranch        *b_Photon_r9;   //!
   TBranch        *b_Photon_sieie;   //!
   TBranch        *b_Photon_charge;   //!
   TBranch        *b_Photon_cutBasedBitmap;   //!
   TBranch        *b_Photon_cutBasedV1Bitmap;   //!
   TBranch        *b_Photon_electronIdx;   //!
   TBranch        *b_Photon_jetIdx;   //!
   TBranch        *b_Photon_pdgId;   //!
   TBranch        *b_Photon_vidNestedWPBitmap;   //!
   TBranch        *b_Photon_electronVeto;   //!
   TBranch        *b_Photon_isScEtaEB;   //!
   TBranch        *b_Photon_isScEtaEE;   //!
   TBranch        *b_Photon_mvaID_WP80;   //!
   TBranch        *b_Photon_mvaID_WP90;   //!
   TBranch        *b_Photon_pixelSeed;   //!
   TBranch        *b_Photon_seedGain;   //!
   TBranch        *b_Photon_seediPhiOriY;
   TBranch        *b_Photon_seediEtaOriX;
   TBranch        *b_Photon_trkSumPtHollowConeDR03; //
   TBranch        *b_Photon_genPartIdx;

   TBranch        *b_Rho_fixedGridRhoAll;

   TBranch        *b_Pileup_nTrueInt;   //!
   TBranch        *b_Pileup_pudensity;   //!
   TBranch        *b_Pileup_gpudensity;   //!
   TBranch        *b_Pileup_nPU;   //!
   TBranch        *b_Pileup_sumEOOT;   //!
   TBranch        *b_Pileup_sumLOOT;   //!
   TBranch        *b_PuppiMET_phi;   //!
   TBranch        *b_PuppiMET_pt;   //!
   TBranch        *b_PuppiMET_sumEt;   //!
   TBranch        *b_RawMET_phi;   //!
   TBranch        *b_RawMET_pt;   //!
   TBranch        *b_RawMET_sumEt;   //!
   TBranch        *b_fixedGridRhoFastjetAll;   //!
   TBranch        *b_fixedGridRhoFastjetCentral;   //!
   TBranch        *b_fixedGridRhoFastjetCentralCalo;   //!
   TBranch        *b_fixedGridRhoFastjetCentralChargedPileUp;   //!
   TBranch        *b_fixedGridRhoFastjetCentralNeutral;   //!
   TBranch        *b_nGenDressedLepton;   //!
   TBranch        *b_GenDressedLepton_eta;   //!
   TBranch        *b_GenDressedLepton_mass;   //!
   TBranch        *b_GenDressedLepton_phi;   //!
   TBranch        *b_GenDressedLepton_pt;   //!
   TBranch        *b_GenDressedLepton_pdgId;   //!
   TBranch        *b_GenDressedLepton_hasTauAnc;   //!
   TBranch        *b_nSoftActivityJet;   //!
   TBranch        *b_SoftActivityJet_eta;   //!
   TBranch        *b_SoftActivityJet_phi;   //!
   TBranch        *b_SoftActivityJet_pt;   //!
   TBranch        *b_SoftActivityJetHT;   //!
   TBranch        *b_SoftActivityJetHT10;   //!
   TBranch        *b_SoftActivityJetHT2;   //!
   TBranch        *b_SoftActivityJetHT5;   //!
   TBranch        *b_SoftActivityJetNjets10;   //!
   TBranch        *b_SoftActivityJetNjets2;   //!
   TBranch        *b_SoftActivityJetNjets5;   //!
   TBranch        *b_nTau;   //!
   TBranch        *b_Tau_chargedIso;   //!
   TBranch        *b_Tau_dxy;   //!
   TBranch        *b_Tau_dz;   //!
   TBranch        *b_Tau_eta;   //!
   TBranch        *b_Tau_leadTkDeltaEta;   //!
   TBranch        *b_Tau_leadTkDeltaPhi;   //!
   TBranch        *b_Tau_leadTkPtOverTauPt;   //!
   TBranch        *b_Tau_mass;   //!
   TBranch        *b_Tau_neutralIso;   //!
   TBranch        *b_Tau_phi;   //!
   TBranch        *b_Tau_photonsOutsideSignalCone;   //!
   TBranch        *b_Tau_pt;   //!
   TBranch        *b_Tau_puCorr;   //!
   TBranch        *b_Tau_rawAntiEle;   //!
   TBranch        *b_Tau_rawAntiEle2018;   //!
   TBranch        *b_Tau_rawDeepTau2017v2p1VSe;   //!
   TBranch        *b_Tau_rawDeepTau2017v2p1VSjet;   //!
   TBranch        *b_Tau_rawDeepTau2017v2p1VSmu;   //!
   TBranch        *b_Tau_rawIso;   //!
   TBranch        *b_Tau_rawIsodR03;   //!
   TBranch        *b_Tau_rawMVAnewDM2017v2;   //!
   TBranch        *b_Tau_rawMVAoldDM;   //!
   TBranch        *b_Tau_rawMVAoldDM2017v1;   //!
   TBranch        *b_Tau_rawMVAoldDM2017v2;   //!
   TBranch        *b_Tau_rawMVAoldDMdR032017v2;   //!
   TBranch        *b_Tau_charge;   //!
   TBranch        *b_Tau_decayMode;   //!
   TBranch        *b_Tau_jetIdx;   //!
   TBranch        *b_Tau_rawAntiEleCat;   //!
   TBranch        *b_Tau_rawAntiEleCat2018;   //!
   TBranch        *b_Tau_idAntiEle;   //!
   TBranch        *b_Tau_idAntiEle2018;   //!
   TBranch        *b_Tau_idAntiMu;   //!
   TBranch        *b_Tau_idDecayMode;   //!
   TBranch        *b_Tau_idDecayModeNewDMs;   //!
   TBranch        *b_Tau_idDeepTau2017v2p1VSe;   //!
   TBranch        *b_Tau_idDeepTau2017v2p1VSjet;   //!
   TBranch        *b_Tau_idDeepTau2017v2p1VSmu;   //!
   TBranch        *b_Tau_idMVAnewDM2017v2;   //!
   TBranch        *b_Tau_idMVAoldDM;   //!
   TBranch        *b_Tau_idMVAoldDM2017v1;   //!
   TBranch        *b_Tau_idMVAoldDM2017v2;   //!
   TBranch        *b_Tau_idMVAoldDMdR032017v2;   //!
   TBranch        *b_TkMET_phi;   //!
   TBranch        *b_TkMET_pt;   //!
   TBranch        *b_TkMET_sumEt;   //!
   TBranch        *b_nTrigObj;   //!
   TBranch        *b_TrigObj_pt;   //!
   TBranch        *b_TrigObj_eta;   //!
   TBranch        *b_TrigObj_phi;   //!
   TBranch        *b_TrigObj_l1pt;   //!
   TBranch        *b_TrigObj_l1pt_2;   //!
   TBranch        *b_TrigObj_l2pt;   //!
   TBranch        *b_TrigObj_id;   //!
   TBranch        *b_TrigObj_l1iso;   //!
   TBranch        *b_TrigObj_l1charge;   //!
   TBranch        *b_TrigObj_filterBits;   //!
   TBranch        *b_genTtbarId;   //!
   TBranch        *b_nOtherPV;   //!
   TBranch        *b_OtherPV_z;   //!
   TBranch        *b_PV_ndof;   //!
   TBranch        *b_PV_x;   //!
   TBranch        *b_PV_y;   //!
   TBranch        *b_PV_z;   //!
   TBranch        *b_PV_chi2;   //!
   TBranch        *b_PV_score;   //!
   TBranch        *b_PV_npvs;   //!
   TBranch        *b_PV_npvsGood;   //!
   TBranch        *b_nSV;   //!
   TBranch        *b_SV_dlen;   //!
   TBranch        *b_SV_dlenSig;   //!
   TBranch        *b_SV_dxy;   //!
   TBranch        *b_SV_dxySig;   //!
   TBranch        *b_SV_pAngle;   //!
   TBranch        *b_Electron_genPartIdx;   //!
   TBranch        *b_Electron_genPartFlav;   //!
   TBranch        *b_GenJetAK8_partonFlavour;   //!
   TBranch        *b_GenJetAK8_hadronFlavour;   //!
   TBranch        *b_GenJet_partonFlavour;   //!
   TBranch        *b_GenJet_hadronFlavour;   //!
   TBranch        *b_Jet_genJetIdx;   //!
   TBranch        *b_Jet_hadronFlavour;   //!   //!
   TBranch        *b_Muon_genPartIdx;   //!
   TBranch        *b_Muon_genPartFlav;   //!  //!
   TBranch        *b_Photon_genPartFlav;   //!
   TBranch        *b_MET_fiducialGenPhi;   //!
   TBranch        *b_MET_fiducialGenPt;   //!
   TBranch        *b_Electron_cleanmask;   //!
   TBranch        *b_Jet_cleanmask;   //!
   TBranch        *b_Muon_cleanmask;   //!
   TBranch        *b_Photon_cleanmask;   //!
   TBranch        *b_Tau_cleanmask;   //!
   TBranch        *b_SV_chi2;   //!
   TBranch        *b_SV_eta;   //!
   TBranch        *b_SV_mass;   //!
   TBranch        *b_SV_ndof;   //!
   TBranch        *b_SV_phi;   //!
   TBranch        *b_SV_pt;   //!
   TBranch        *b_SV_x;   //!
   TBranch        *b_SV_y;   //!
   TBranch        *b_SV_z;   //!
   TBranch        *b_Tau_genPartIdx;   //!
   TBranch        *b_Tau_genPartFlav;   //!
   TBranch        *b_L1simulation_step;   //!
   TBranch        *b_HLTriggerFirstPath;   //!
   TBranch        *b_HLT_AK8PFJet360_TrimMass30;   //!
   TBranch        *b_HLT_AK8PFJet380_TrimMass30;   //!
   TBranch        *b_HLT_AK8PFJet400_TrimMass30;   //!
   TBranch        *b_HLT_AK8PFJet420_TrimMass30;   //!
   TBranch        *b_HLT_AK8PFJet380_SoftDropMass30;   //!
   TBranch        *b_HLT_AK8PFJet400_SoftDropMass30;   //!
   TBranch        *b_HLT_AK8PFJet425_SoftDropMass30;   //!
   TBranch        *b_HLT_AK8PFJet450_SoftDropMass30;   //!
   TBranch        *b_HLT_AK8DiPFJet250_250_SoftDropMass40;   //!
   TBranch        *b_HLT_AK8DiPFJet250_250_SoftDropMass50;   //!
   TBranch        *b_HLT_AK8DiPFJet260_260_SoftDropMass30;   //!
   TBranch        *b_HLT_AK8DiPFJet260_260_SoftDropMass40;   //!
   TBranch        *b_HLT_AK8DiPFJet270_270_SoftDropMass30;   //!
   TBranch        *b_HLT_AK8DiPFJet280_280_SoftDropMass30;   //!
   TBranch        *b_HLT_AK8DiPFJet290_290_SoftDropMass30;   //!
   TBranch        *b_HLT_AK8PFJet220_SoftDropMass40;   //!
   TBranch        *b_HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p50;   //!
   TBranch        *b_HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p53;   //!
   TBranch        *b_HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p55;   //!
   TBranch        *b_HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p60;   //!
   TBranch        *b_HLT_AK8PFJet230_SoftDropMass40_PNetBB0p06;   //!
   TBranch        *b_HLT_AK8PFJet230_SoftDropMass40_PNetBB0p10;   //!
   TBranch        *b_HLT_AK8PFJet230_SoftDropMass40_PNetTauTau0p03;   //!
   TBranch        *b_HLT_AK8PFJet230_SoftDropMass40_PNetTauTau0p05;   //!
   TBranch        *b_HLT_AK8PFJet250_SoftDropMass40_PNetBB0p06;   //!
   TBranch        *b_HLT_AK8PFJet250_SoftDropMass40_PNetBB0p10;   //!
   TBranch        *b_HLT_AK8PFJet250_SoftDropMass40_PNetTauTau0p03;   //!
   TBranch        *b_HLT_AK8PFJet250_SoftDropMass40_PNetTauTau0p05;   //!
   TBranch        *b_HLT_AK8PFJet275_SoftDropMass40_PNetBB0p06;   //!
   TBranch        *b_HLT_AK8PFJet275_SoftDropMass40_PNetBB0p10;   //!
   TBranch        *b_HLT_AK8PFJet275_SoftDropMass40_PNetTauTau0p03;   //!
   TBranch        *b_HLT_AK8PFJet275_SoftDropMass40_PNetTauTau0p05;   //!
   TBranch        *b_HLT_AK8PFJet400_MassSD30;   //!
   TBranch        *b_HLT_AK8PFJet420_MassSD30;   //!
   TBranch        *b_HLT_AK8PFJet450_MassSD30;   //!
   TBranch        *b_HLT_AK8DiPFJet250_250_MassSD30;   //!
   TBranch        *b_HLT_AK8DiPFJet250_250_MassSD50;   //!
   TBranch        *b_HLT_AK8DiPFJet260_260_MassSD30;   //!
   TBranch        *b_HLT_AK8DiPFJet270_270_MassSD30;   //!
   TBranch        *b_HLT_AK8PFHT750_TrimMass50;   //!
   TBranch        *b_HLT_AK8PFHT800_TrimMass50;   //!
   TBranch        *b_HLT_AK8PFHT850_TrimMass50;   //!
   TBranch        *b_HLT_AK8PFHT900_TrimMass50;   //!
   TBranch        *b_HLT_CaloJet500_NoJetID;   //!
   TBranch        *b_HLT_CaloJet550_NoJetID;   //!
   TBranch        *b_HLT_DoubleMu5_Upsilon_DoubleEle3_CaloIdL_TrackIdL;   //!
   TBranch        *b_HLT_DoubleMu3_DoubleEle7p5_CaloIdL_TrackIdL_Upsilon;   //!
   TBranch        *b_HLT_Trimuon5_3p5_2_Upsilon_Muon;   //!
   TBranch        *b_HLT_TrimuonOpen_5_3p5_2_Upsilon_Muon;   //!
   TBranch        *b_HLT_DoubleEle25_CaloIdL_MW;   //!
   TBranch        *b_HLT_DoubleEle27_CaloIdL_MW;   //!
   TBranch        *b_HLT_DoubleEle33_CaloIdL_MW;   //!
   TBranch        *b_HLT_DoubleEle24_eta2p1_WPTight_Gsf;   //!
   TBranch        *b_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_DZ_PFHT350;   //!
   TBranch        *b_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT350;   //!
   TBranch        *b_HLT_Ele27_Ele37_CaloIdL_MW;   //!
   TBranch        *b_HLT_Mu27_Ele37_CaloIdL_MW;   //!
   TBranch        *b_HLT_Mu37_Ele27_CaloIdL_MW;   //!
   TBranch        *b_HLT_Mu37_TkMu27;   //!
   TBranch        *b_HLT_DoubleMu4_3_Bs;   //!
   TBranch        *b_HLT_DoubleMu4_3_Jpsi;   //!
   TBranch        *b_HLT_DoubleMu4_JpsiTrk_Displaced;   //!
   TBranch        *b_HLT_DoubleMu4_LowMassNonResonantTrk_Displaced;   //!
   TBranch        *b_HLT_DoubleMu3_Trk_Tau3mu;   //!
   TBranch        *b_HLT_DoubleMu3_TkMu_DsTau3Mu;   //!
   TBranch        *b_HLT_DoubleMu4_PsiPrimeTrk_Displaced;   //!
   TBranch        *b_HLT_DoubleMu4_Mass3p8_DZ_PFHT350;   //!
   TBranch        *b_HLT_Mu3_PFJet40;   //!
   TBranch        *b_HLT_Mu7p5_L2Mu2_Jpsi;   //!
   TBranch        *b_HLT_Mu7p5_L2Mu2_Upsilon;   //!
   TBranch        *b_HLT_Mu7p5_Track2_Jpsi;   //!
   TBranch        *b_HLT_Mu7p5_Track3p5_Jpsi;   //!
   TBranch        *b_HLT_Mu7p5_Track7_Jpsi;   //!
   TBranch        *b_HLT_Mu7p5_Track2_Upsilon;   //!
   TBranch        *b_HLT_Mu7p5_Track3p5_Upsilon;   //!
   TBranch        *b_HLT_Mu7p5_Track7_Upsilon;   //!
   TBranch        *b_HLT_Mu3_L1SingleMu5orSingleMu7;   //!
   TBranch        *b_HLT_DoublePhoton33_CaloIdL;   //!
   TBranch        *b_HLT_DoublePhoton70;   //!
   TBranch        *b_HLT_DoublePhoton85;   //!
   TBranch        *b_HLT_Ele20_WPTight_Gsf;   //!
   TBranch        *b_HLT_Ele15_WPLoose_Gsf;   //!
   TBranch        *b_HLT_Ele17_WPLoose_Gsf;   //!
   TBranch        *b_HLT_Ele20_WPLoose_Gsf;   //!
   TBranch        *b_HLT_Ele20_eta2p1_WPLoose_Gsf;   //!
   TBranch        *b_HLT_DiEle27_WPTightCaloOnly_L1DoubleEG;   //!
   TBranch        *b_HLT_Ele27_WPTight_Gsf;   //!
   TBranch        *b_HLT_Ele28_WPTight_Gsf;   //!
   TBranch        *b_HLT_Ele30_WPTight_Gsf;   //!
   TBranch        *b_HLT_Ele32_WPTight_Gsf;   //!
   TBranch        *b_HLT_Ele35_WPTight_Gsf;   //!
   TBranch        *b_HLT_Ele35_WPTight_Gsf_L1EGMT;   //!
   TBranch        *b_HLT_Ele38_WPTight_Gsf;   //!
   TBranch        *b_HLT_Ele40_WPTight_Gsf;   //!
   TBranch        *b_HLT_Ele32_WPTight_Gsf_L1DoubleEG;   //!
   TBranch        *b_HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_CrossL1;   //!
   TBranch        *b_HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTauHPS30_eta2p1_CrossL1;   //!
   TBranch        *b_HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTauHPS30_eta2p1_CrossL1;   //!
   TBranch        *b_HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_TightID_CrossL1;   //!
   TBranch        *b_HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTauHPS30_eta2p1_TightID_CrossL1;   //!
   TBranch        *b_HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTauHPS30_eta2p1_TightID_CrossL1;   //!
   TBranch        *b_HLT_HT450_Beamspot;   //!
   TBranch        *b_HLT_HT300_Beamspot;   //!
   TBranch        *b_HLT_ZeroBias_Beamspot;   //!
   TBranch        *b_HLT_IsoMu20_eta2p1_LooseChargedIsoPFTauHPS27_eta2p1_CrossL1;   //!
   TBranch        *b_HLT_IsoMu20_eta2p1_MediumChargedIsoPFTauHPS27_eta2p1_CrossL1;   //!
   TBranch        *b_HLT_IsoMu20_eta2p1_TightChargedIsoPFTauHPS27_eta2p1_CrossL1;   //!
   TBranch        *b_HLT_IsoMu20_eta2p1_LooseChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1;   //!
   TBranch        *b_HLT_IsoMu20_eta2p1_MediumChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1;   //!
   TBranch        *b_HLT_IsoMu20_eta2p1_TightChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_TightChargedIsoPFTauHPS35_Trk1_eta2p1_Reg_CrossL1;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg_CrossL1;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_TightChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg_CrossL1;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTauHPS35_Trk1_eta2p1_Reg_CrossL1;   //!
   TBranch        *b_HLT_IsoMu27_LooseChargedIsoPFTauHPS20_Trk1_eta2p1_SingleL1;   //!
   TBranch        *b_HLT_IsoMu27_MediumChargedIsoPFTauHPS20_Trk1_eta2p1_SingleL1;   //!
   TBranch        *b_HLT_IsoMu27_TightChargedIsoPFTauHPS20_Trk1_eta2p1_SingleL1;   //!
   TBranch        *b_HLT_IsoMu20;   //!
   TBranch        *b_HLT_IsoMu24;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1;   //!
   TBranch        *b_HLT_IsoMu27;   //!
   TBranch        *b_HLT_IsoMu30;   //!
   TBranch        *b_HLT_UncorrectedJetE30_NoBPTX;   //!
   TBranch        *b_HLT_UncorrectedJetE30_NoBPTX3BX;   //!
   TBranch        *b_HLT_UncorrectedJetE60_NoBPTX3BX;   //!
   TBranch        *b_HLT_UncorrectedJetE70_NoBPTX3BX;   //!
   TBranch        *b_HLT_L1SingleMu18;   //!
   TBranch        *b_HLT_L1SingleMu25;   //!
   TBranch        *b_HLT_L2Mu10;   //!
   TBranch        *b_HLT_L2Mu10_NoVertex_NoBPTX3BX;   //!
   TBranch        *b_HLT_L2Mu10_NoVertex_NoBPTX;   //!
   TBranch        *b_HLT_L2Mu45_NoVertex_3Sta_NoBPTX3BX;   //!
   TBranch        *b_HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX;   //!
   TBranch        *b_HLT_L2Mu50;   //!
   TBranch        *b_HLT_L2Mu23NoVtx_2Cha;   //!
   TBranch        *b_HLT_L2Mu23NoVtx_2Cha_CosmicSeed;   //!
   TBranch        *b_HLT_DoubleL2Mu30NoVtx_2Cha_CosmicSeed_Eta2p4;   //!
   TBranch        *b_HLT_DoubleL2Mu30NoVtx_2Cha_Eta2p4;   //!
   TBranch        *b_HLT_DoubleL2Mu50;   //!
   TBranch        *b_HLT_DoubleL2Mu23NoVtx_2Cha_CosmicSeed;   //!
   TBranch        *b_HLT_DoubleL2Mu23NoVtx_2Cha_CosmicSeed_NoL2Matched;   //!
   TBranch        *b_HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed;   //!
   TBranch        *b_HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed_NoL2Matched;   //!
   TBranch        *b_HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed_Eta2p4;   //!
   TBranch        *b_HLT_DoubleL2Mu23NoVtx_2Cha;   //!
   TBranch        *b_HLT_DoubleL2Mu23NoVtx_2Cha_NoL2Matched;   //!
   TBranch        *b_HLT_DoubleL2Mu25NoVtx_2Cha;   //!
   TBranch        *b_HLT_DoubleL2Mu25NoVtx_2Cha_NoL2Matched;   //!
   TBranch        *b_HLT_DoubleL2Mu25NoVtx_2Cha_Eta2p4;   //!
   TBranch        *b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL;   //!
   TBranch        *b_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL;   //!
   TBranch        *b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ;   //!
   TBranch        *b_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ;   //!
   TBranch        *b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8;   //!
   TBranch        *b_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8;   //!
   TBranch        *b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8;   //!
   TBranch        *b_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8;   //!
   TBranch        *b_HLT_Mu25_TkMu0_Onia;   //!
   TBranch        *b_HLT_Mu30_TkMu0_Psi;   //!
   TBranch        *b_HLT_Mu30_TkMu0_Upsilon;   //!
   TBranch        *b_HLT_Mu20_TkMu0_Phi;   //!
   TBranch        *b_HLT_Mu25_TkMu0_Phi;   //!
   TBranch        *b_HLT_Mu12;   //!
   TBranch        *b_HLT_Mu15;   //!
   TBranch        *b_HLT_Mu20;   //!
   TBranch        *b_HLT_Mu27;   //!
   TBranch        *b_HLT_Mu50;   //!
   TBranch        *b_HLT_Mu55;   //!
   TBranch        *b_HLT_OldMu100;   //
   TBranch        *b_HLT_TkMu100;   //!
   TBranch        *b_HLT_DiPFJetAve40;   //!
   TBranch        *b_HLT_DiPFJetAve60;   //!
   TBranch        *b_HLT_DiPFJetAve80;   //!
   TBranch        *b_HLT_DiPFJetAve140;   //!
   TBranch        *b_HLT_DiPFJetAve200;   //!
   TBranch        *b_HLT_DiPFJetAve260;   //!
   TBranch        *b_HLT_DiPFJetAve320;   //!
   TBranch        *b_HLT_DiPFJetAve400;   //!
   TBranch        *b_HLT_DiPFJetAve500;   //!
   TBranch        *b_HLT_DiPFJetAve60_HFJEC;   //!
   TBranch        *b_HLT_DiPFJetAve80_HFJEC;   //!
   TBranch        *b_HLT_DiPFJetAve100_HFJEC;   //!
   TBranch        *b_HLT_DiPFJetAve160_HFJEC;   //!
   TBranch        *b_HLT_DiPFJetAve220_HFJEC;   //!
   TBranch        *b_HLT_DiPFJetAve300_HFJEC;   //!
   TBranch        *b_HLT_AK8PFJet15;   //!
   TBranch        *b_HLT_AK8PFJet25;   //!
   TBranch        *b_HLT_AK8PFJet40;   //!
   TBranch        *b_HLT_AK8PFJet60;   //!
   TBranch        *b_HLT_AK8PFJet80;   //!
   TBranch        *b_HLT_AK8PFJet140;   //!
   TBranch        *b_HLT_AK8PFJet200;   //!
   TBranch        *b_HLT_AK8PFJet260;   //!
   TBranch        *b_HLT_AK8PFJet320;   //!
   TBranch        *b_HLT_AK8PFJet400;   //!
   TBranch        *b_HLT_AK8PFJet450;   //!
   TBranch        *b_HLT_AK8PFJet500;   //!
   TBranch        *b_HLT_AK8PFJet550;   //!
   TBranch        *b_HLT_PFJet15;   //!
   TBranch        *b_HLT_PFJet25;   //!
   TBranch        *b_HLT_PFJet40;   //!
   TBranch        *b_HLT_PFJet60;   //!
   TBranch        *b_HLT_PFJet80;   //!
   TBranch        *b_HLT_PFJet140;   //!
   TBranch        *b_HLT_PFJet200;   //!
   TBranch        *b_HLT_PFJet260;   //!
   TBranch        *b_HLT_PFJet320;   //!
   TBranch        *b_HLT_PFJet400;   //!
   TBranch        *b_HLT_PFJet450;   //!
   TBranch        *b_HLT_PFJet500;   //!
   TBranch        *b_HLT_PFJet550;   //!
   TBranch        *b_HLT_PFJetFwd15;   //!
   TBranch        *b_HLT_PFJetFwd25;   //!
   TBranch        *b_HLT_PFJetFwd40;   //!
   TBranch        *b_HLT_PFJetFwd60;   //!
   TBranch        *b_HLT_PFJetFwd80;   //!
   TBranch        *b_HLT_PFJetFwd140;   //!
   TBranch        *b_HLT_PFJetFwd200;   //!
   TBranch        *b_HLT_PFJetFwd260;   //!
   TBranch        *b_HLT_PFJetFwd320;   //!
   TBranch        *b_HLT_PFJetFwd400;   //!
   TBranch        *b_HLT_PFJetFwd450;   //!
   TBranch        *b_HLT_PFJetFwd500;   //!
   TBranch        *b_HLT_AK8PFJetFwd15;   //!
   TBranch        *b_HLT_AK8PFJetFwd25;   //!
   TBranch        *b_HLT_AK8PFJetFwd40;   //!
   TBranch        *b_HLT_AK8PFJetFwd60;   //!
   TBranch        *b_HLT_AK8PFJetFwd80;   //!
   TBranch        *b_HLT_AK8PFJetFwd140;   //!
   TBranch        *b_HLT_AK8PFJetFwd200;   //!
   TBranch        *b_HLT_AK8PFJetFwd260;   //!
   TBranch        *b_HLT_AK8PFJetFwd320;   //!
   TBranch        *b_HLT_AK8PFJetFwd400;   //!
   TBranch        *b_HLT_AK8PFJetFwd450;   //!
   TBranch        *b_HLT_AK8PFJetFwd500;   //!
   TBranch        *b_HLT_PFHT180;   //!
   TBranch        *b_HLT_PFHT250;   //!
   TBranch        *b_HLT_PFHT370;   //!
   TBranch        *b_HLT_PFHT430;   //!
   TBranch        *b_HLT_PFHT510;   //!
   TBranch        *b_HLT_PFHT590;   //!
   TBranch        *b_HLT_PFHT680;   //!
   TBranch        *b_HLT_PFHT780;   //!
   TBranch        *b_HLT_PFHT890;   //!
   TBranch        *b_HLT_PFHT1050;   //!
   TBranch        *b_HLT_PFHT500_PFMET100_PFMHT100_IDTight;   //!
   TBranch        *b_HLT_PFHT500_PFMET110_PFMHT110_IDTight;   //!
   TBranch        *b_HLT_PFHT700_PFMET85_PFMHT85_IDTight;   //!
   TBranch        *b_HLT_PFHT700_PFMET95_PFMHT95_IDTight;   //!
   TBranch        *b_HLT_PFHT800_PFMET75_PFMHT75_IDTight;   //!
   TBranch        *b_HLT_PFHT800_PFMET85_PFMHT85_IDTight;   //!
   TBranch        *b_HLT_PFMET110_PFMHT110_IDTight;   //!
   TBranch        *b_HLT_PFMET120_PFMHT120_IDTight;   //!
   TBranch        *b_HLT_PFMET130_PFMHT130_IDTight;   //!
   TBranch        *b_HLT_PFMET140_PFMHT140_IDTight;   //!
   TBranch        *b_HLT_PFMET100_PFMHT100_IDTight_CaloBTagDeepCSV_3p1;   //!
   TBranch        *b_HLT_PFMET110_PFMHT110_IDTight_CaloBTagDeepCSV_3p1;   //!
   TBranch        *b_HLT_PFMET120_PFMHT120_IDTight_CaloBTagDeepCSV_3p1;   //!
   TBranch        *b_HLT_PFMET130_PFMHT130_IDTight_CaloBTagDeepCSV_3p1;   //!
   TBranch        *b_HLT_PFMET140_PFMHT140_IDTight_CaloBTagDeepCSV_3p1;   //!
   TBranch        *b_HLT_PFMET120_PFMHT120_IDTight_PFHT60;   //!
   TBranch        *b_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60;   //!
   TBranch        *b_HLT_PFMETTypeOne120_PFMHT120_IDTight_PFHT60;   //!
   TBranch        *b_HLT_PFMETTypeOne110_PFMHT110_IDTight;   //!
   TBranch        *b_HLT_PFMETTypeOne120_PFMHT120_IDTight;   //!
   TBranch        *b_HLT_PFMETTypeOne130_PFMHT130_IDTight;   //!
   TBranch        *b_HLT_PFMETTypeOne140_PFMHT140_IDTight;   //!
   TBranch        *b_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight;   //!
   TBranch        *b_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight;   //!
   TBranch        *b_HLT_PFMETNoMu130_PFMHTNoMu130_IDTight;   //!
   TBranch        *b_HLT_PFMETNoMu140_PFMHTNoMu140_IDTight;   //!
   TBranch        *b_HLT_MonoCentralPFJet80_PFMETNoMu110_PFMHTNoMu110_IDTight;   //!
   TBranch        *b_HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight;   //!
   TBranch        *b_HLT_MonoCentralPFJet80_PFMETNoMu130_PFMHTNoMu130_IDTight;   //!
   TBranch        *b_HLT_MonoCentralPFJet80_PFMETNoMu140_PFMHTNoMu140_IDTight;   //!
   TBranch        *b_HLT_L1ETMHadSeeds;   //!
   TBranch        *b_HLT_CaloMHT90;   //!
   TBranch        *b_HLT_CaloMET80_NotCleaned;   //!
   TBranch        *b_HLT_CaloMET90_NotCleaned;   //!
   TBranch        *b_HLT_CaloMET100_NotCleaned;   //!
   TBranch        *b_HLT_CaloMET110_NotCleaned;   //!
   TBranch        *b_HLT_CaloMET250_NotCleaned;   //!
   TBranch        *b_HLT_CaloMET70_HBHECleaned;   //!
   TBranch        *b_HLT_CaloMET80_HBHECleaned;   //!
   TBranch        *b_HLT_CaloMET90_HBHECleaned;   //!
   TBranch        *b_HLT_CaloMET100_HBHECleaned;   //!
   TBranch        *b_HLT_CaloMET250_HBHECleaned;   //!
   TBranch        *b_HLT_CaloMET300_HBHECleaned;   //!
   TBranch        *b_HLT_CaloMET350_HBHECleaned;   //!
   TBranch        *b_HLT_PFMET200_NotCleaned;   //!
   TBranch        *b_HLT_PFMET200_HBHECleaned;   //!
   TBranch        *b_HLT_PFMET250_HBHECleaned;   //!
   TBranch        *b_HLT_PFMET300_HBHECleaned;   //!
   TBranch        *b_HLT_PFMET200_HBHE_BeamHaloCleaned;   //!
   TBranch        *b_HLT_PFMETTypeOne200_HBHE_BeamHaloCleaned;   //!
   TBranch        *b_HLT_MET105_IsoTrk50;   //!
   TBranch        *b_HLT_MET120_IsoTrk50;   //!
   TBranch        *b_HLT_SingleJet30_Mu12_SinglePFJet40;   //!
   TBranch        *b_HLT_Mu12_DoublePFJets40_CaloBTagDeepCSV_p71;   //!
   TBranch        *b_HLT_Mu12_DoublePFJets100_CaloBTagDeepCSV_p71;   //!
   TBranch        *b_HLT_Mu12_DoublePFJets200_CaloBTagDeepCSV_p71;   //!
   TBranch        *b_HLT_Mu12_DoublePFJets350_CaloBTagDeepCSV_p71;   //!
   TBranch        *b_HLT_Mu12_DoublePFJets40MaxDeta1p6_DoubleCaloBTagDeepCSV_p71;   //!
   TBranch        *b_HLT_Mu12_DoublePFJets54MaxDeta1p6_DoubleCaloBTagDeepCSV_p71;   //!
   TBranch        *b_HLT_Mu12_DoublePFJets62MaxDeta1p6_DoubleCaloBTagDeepCSV_p71;   //!
   TBranch        *b_HLT_DoublePFJets40_CaloBTagDeepCSV_p71;   //!
   TBranch        *b_HLT_DoublePFJets100_CaloBTagDeepCSV_p71;   //!
   TBranch        *b_HLT_DoublePFJets200_CaloBTagDeepCSV_p71;   //!
   TBranch        *b_HLT_DoublePFJets350_CaloBTagDeepCSV_p71;   //!
   TBranch        *b_HLT_DoublePFJets116MaxDeta1p6_DoubleCaloBTagDeepCSV_p71;   //!
   TBranch        *b_HLT_DoublePFJets128MaxDeta1p6_DoubleCaloBTagDeepCSV_p71;   //!
   TBranch        *b_HLT_Photon300_NoHE;   //!
   TBranch        *b_HLT_Mu8_TrkIsoVVL;   //!
   TBranch        *b_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ;   //!
   TBranch        *b_HLT_Mu8_DiEle12_CaloIdL_TrackIdL;   //!
   TBranch        *b_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ;   //!
   TBranch        *b_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350;   //!
   TBranch        *b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ;   //!
   TBranch        *b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30;   //!
   TBranch        *b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_CaloDiJet30;   //!
   TBranch        *b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBtagDeepCSV_1p5;   //!
   TBranch        *b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_CaloDiJet30_CaloBtagDeepCSV_1p5;   //!
   TBranch        *b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL;   //!
   TBranch        *b_HLT_Mu17_TrkIsoVVL;   //!
   TBranch        *b_HLT_Mu19_TrkIsoVVL;   //!
   TBranch        *b_HLT_BTagMu_AK4DiJet20_Mu5;   //!
   TBranch        *b_HLT_BTagMu_AK4DiJet40_Mu5;   //!
   TBranch        *b_HLT_BTagMu_AK4DiJet70_Mu5;   //!
   TBranch        *b_HLT_BTagMu_AK4DiJet110_Mu5;   //!
   TBranch        *b_HLT_BTagMu_AK4DiJet170_Mu5;   //!
   TBranch        *b_HLT_BTagMu_AK4Jet300_Mu5;   //!
   TBranch        *b_HLT_BTagMu_AK8DiJet170_Mu5;   //!
   TBranch        *b_HLT_BTagMu_AK8Jet170_DoubleMu5;   //!
   TBranch        *b_HLT_BTagMu_AK8Jet300_Mu5;   //!
   TBranch        *b_HLT_BTagMu_AK4DiJet20_Mu5_noalgo;   //!
   TBranch        *b_HLT_BTagMu_AK4DiJet40_Mu5_noalgo;   //!
   TBranch        *b_HLT_BTagMu_AK4DiJet70_Mu5_noalgo;   //!
   TBranch        *b_HLT_BTagMu_AK4DiJet110_Mu5_noalgo;   //!
   TBranch        *b_HLT_BTagMu_AK4DiJet170_Mu5_noalgo;   //!
   TBranch        *b_HLT_BTagMu_AK4Jet300_Mu5_noalgo;   //!
   TBranch        *b_HLT_BTagMu_AK8DiJet170_Mu5_noalgo;   //!
   TBranch        *b_HLT_BTagMu_AK8Jet170_DoubleMu5_noalgo;   //!
   TBranch        *b_HLT_BTagMu_AK8Jet300_Mu5_noalgo;   //!
   TBranch        *b_HLT_Ele15_Ele8_CaloIdL_TrackIdL_IsoVL;   //!
   TBranch        *b_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;   //!
   TBranch        *b_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL;   //!
   TBranch        *b_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;   //!
   TBranch        *b_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL;   //!
   TBranch        *b_HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL;   //!
   TBranch        *b_HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ;   //!
   TBranch        *b_HLT_Mu12_DoublePhoton20;   //!
   TBranch        *b_HLT_TriplePhoton_20_20_20_CaloIdLV2;   //!
   TBranch        *b_HLT_TriplePhoton_20_20_20_CaloIdLV2_R9IdVL;   //!
   TBranch        *b_HLT_TriplePhoton_30_30_10_CaloIdLV2;   //!
   TBranch        *b_HLT_TriplePhoton_30_30_10_CaloIdLV2_R9IdVL;   //!
   TBranch        *b_HLT_TriplePhoton_35_35_5_CaloIdLV2_R9IdVL;   //!
   TBranch        *b_HLT_Photon20;   //!
   TBranch        *b_HLT_Photon33;   //!
   TBranch        *b_HLT_Photon50;   //!
   TBranch        *b_HLT_Photon75;   //!
   TBranch        *b_HLT_Photon90;   //!
   TBranch        *b_HLT_Photon120;   //!
   TBranch        *b_HLT_Photon150;   //!
   TBranch        *b_HLT_Photon175;   //!
   TBranch        *b_HLT_Photon200;   //!
   TBranch        *b_HLT_Photon100EB_TightID_TightIso;   //!
   TBranch        *b_HLT_Photon110EB_TightID_TightIso;   //!
   TBranch        *b_HLT_Photon120EB_TightID_TightIso;   //!
   TBranch        *b_HLT_Photon100EBHE10;   //!
   TBranch        *b_HLT_Photon100EEHE10;   //!
   TBranch        *b_HLT_Photon100EE_TightID_TightIso;   //!
   TBranch        *b_HLT_Photon50_R9Id90_HE10_IsoM;   //!
   TBranch        *b_HLT_Photon75_R9Id90_HE10_IsoM;   //!
   TBranch        *b_HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_CaloMJJ300_PFJetsMJJ400DEta3;   //!
   TBranch        *b_HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_CaloMJJ400_PFJetsMJJ600DEta3;   //!
   TBranch        *b_HLT_Photon90_R9Id90_HE10_IsoM;   //!
   TBranch        *b_HLT_Photon120_R9Id90_HE10_IsoM;   //!
   TBranch        *b_HLT_Photon165_R9Id90_HE10_IsoM;   //!
   TBranch        *b_HLT_Photon90_CaloIdL_PFHT700;   //!
   TBranch        *b_HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90;   //!
   TBranch        *b_HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95;   //!
   TBranch        *b_HLT_DiphotonMVA14p25_Mass90;   //!
   TBranch        *b_HLT_DiphotonMVA14p25_Tight_Mass90;   //!
   TBranch        *b_HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55;   //!
   TBranch        *b_HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55;   //!
   TBranch        *b_HLT_Photon35_TwoProngs35;   //!
   TBranch        *b_HLT_IsoMu24_TwoProngs35;   //!
   TBranch        *b_HLT_Dimuon0_Jpsi_L1_NoOS;   //!
   TBranch        *b_HLT_Dimuon0_Jpsi_NoVertexing_NoOS;   //!
   TBranch        *b_HLT_Dimuon0_Jpsi;   //!
   TBranch        *b_HLT_Dimuon0_Jpsi_NoVertexing;   //!
   TBranch        *b_HLT_Dimuon0_Jpsi_L1_4R_0er1p5R;   //!
   TBranch        *b_HLT_Dimuon0_Jpsi_NoVertexing_L1_4R_0er1p5R;   //!
   TBranch        *b_HLT_Dimuon0_Jpsi3p5_Muon2;   //!
   TBranch        *b_HLT_Dimuon0_Upsilon_L1_4p5;   //!
   TBranch        *b_HLT_Dimuon0_Upsilon_L1_5;   //!
   TBranch        *b_HLT_Dimuon0_Upsilon_L1_4p5NoOS;   //!
   TBranch        *b_HLT_Dimuon0_Upsilon_L1_4p5er2p0;   //!
   TBranch        *b_HLT_Dimuon0_Upsilon_L1_4p5er2p0M;   //!
   TBranch        *b_HLT_Dimuon0_Upsilon_NoVertexing;   //!
   TBranch        *b_HLT_Dimuon0_Upsilon_L1_5M;   //!
   TBranch        *b_HLT_Dimuon0_LowMass_L1_0er1p5R;   //!
   TBranch        *b_HLT_Dimuon0_LowMass_L1_0er1p5;   //!
   TBranch        *b_HLT_Dimuon0_LowMass;   //!
   TBranch        *b_HLT_Dimuon0_LowMass_L1_4;   //!
   TBranch        *b_HLT_Dimuon0_LowMass_L1_4R;   //!
   TBranch        *b_HLT_Dimuon0_LowMass_L1_TM530;   //!
   TBranch        *b_HLT_Dimuon0_Upsilon_Muon_L1_TM0;   //!
   TBranch        *b_HLT_Dimuon0_Upsilon_Muon_NoL1Mass;   //!
   TBranch        *b_HLT_TripleMu_5_3_3_Mass3p8_DZ;   //!
   TBranch        *b_HLT_TripleMu_10_5_5_DZ;   //!
   TBranch        *b_HLT_TripleMu_12_10_5;   //!
   TBranch        *b_HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15;   //!
   TBranch        *b_HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15_Charge1;   //!
   TBranch        *b_HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15;   //!
   TBranch        *b_HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15_Charge1;   //!
   TBranch        *b_HLT_DoubleMu3_DZ_PFMET50_PFMHT60;   //!
   TBranch        *b_HLT_DoubleMu3_DZ_PFMET70_PFMHT70;   //!
   TBranch        *b_HLT_DoubleMu3_DZ_PFMET90_PFMHT90;   //!
   TBranch        *b_HLT_DoubleMu3_Trk_Tau3mu_NoL1Mass;   //!
   TBranch        *b_HLT_DoubleMu4_Jpsi_Displaced;   //!
   TBranch        *b_HLT_DoubleMu4_Jpsi_NoVertexing;   //!
   TBranch        *b_HLT_DoubleMu4_JpsiTrkTrk_Displaced;   //!
   TBranch        *b_HLT_DoubleMu43NoFiltersNoVtx;   //!
   TBranch        *b_HLT_DoubleMu48NoFiltersNoVtx;   //!
   TBranch        *b_HLT_Mu43NoFiltersNoVtx_Photon43_CaloIdL;   //!
   TBranch        *b_HLT_Mu48NoFiltersNoVtx_Photon48_CaloIdL;   //!
   TBranch        *b_HLT_Mu38NoFiltersNoVtxDisplaced_Photon38_CaloIdL;   //!
   TBranch        *b_HLT_Mu43NoFiltersNoVtxDisplaced_Photon43_CaloIdL;   //!
   TBranch        *b_HLT_DoubleMu33NoFiltersNoVtxDisplaced;   //!
   TBranch        *b_HLT_DoubleMu40NoFiltersNoVtxDisplaced;   //!
   TBranch        *b_HLT_DoubleMu20_7_Mass0to30_L1_DM4;   //!
   TBranch        *b_HLT_DoubleMu20_7_Mass0to30_L1_DM4EG;   //!
   TBranch        *b_HLT_HT425;   //!
   TBranch        *b_HLT_HT430_DisplacedDijet40_DisplacedTrack;   //!
   TBranch        *b_HLT_HT500_DisplacedDijet40_DisplacedTrack;   //!
   TBranch        *b_HLT_HT430_DisplacedDijet60_DisplacedTrack;   //!
   TBranch        *b_HLT_HT400_DisplacedDijet40_DisplacedTrack;   //!
   TBranch        *b_HLT_HT650_DisplacedDijet60_Inclusive;   //!
   TBranch        *b_HLT_HT550_DisplacedDijet60_Inclusive;   //!
   TBranch        *b_HLT_DiJet110_35_Mjj650_PFMET110;   //!
   TBranch        *b_HLT_DiJet110_35_Mjj650_PFMET120;   //!
   TBranch        *b_HLT_DiJet110_35_Mjj650_PFMET130;   //!
   TBranch        *b_HLT_TripleJet110_35_35_Mjj650_PFMET110;   //!
   TBranch        *b_HLT_TripleJet110_35_35_Mjj650_PFMET120;   //!
   TBranch        *b_HLT_TripleJet110_35_35_Mjj650_PFMET130;   //!
   TBranch        *b_HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned;   //!
   TBranch        *b_HLT_Ele28_eta2p1_WPTight_Gsf_HT150;   //!
   TBranch        *b_HLT_Ele28_HighEta_SC20_Mass55;   //!
   TBranch        *b_HLT_DoubleMu20_7_Mass0to30_Photon23;   //!
   TBranch        *b_HLT_Ele15_IsoVVVL_PFHT450_CaloBTagDeepCSV_4p5;   //!
   TBranch        *b_HLT_Ele15_IsoVVVL_PFHT450_PFMET50;   //!
   TBranch        *b_HLT_Ele15_IsoVVVL_PFHT450;   //!
   TBranch        *b_HLT_Ele50_IsoVVVL_PFHT450;   //!
   TBranch        *b_HLT_Ele15_IsoVVVL_PFHT600;   //!
   TBranch        *b_HLT_Mu4_TrkIsoVVL_DiPFJet90_40_DEta3p5_MJJ750_HTT300_PFMETNoMu60;   //!
   TBranch        *b_HLT_Mu8_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT300_PFMETNoMu60;   //!
   TBranch        *b_HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60;   //!
   TBranch        *b_HLT_Mu15_IsoVVVL_PFHT450_CaloBTagDeepCSV_4p5;   //!
   TBranch        *b_HLT_Mu15_IsoVVVL_PFHT450_PFMET50;   //!
   TBranch        *b_HLT_Mu15_IsoVVVL_PFHT450;   //!
   TBranch        *b_HLT_Mu50_IsoVVVL_PFHT450;   //!
   TBranch        *b_HLT_Mu15_IsoVVVL_PFHT600;   //!
   TBranch        *b_HLT_Mu3er1p5_PFJet100er2p5_PFMET70_PFMHT70_IDTight;   //!
   TBranch        *b_HLT_Mu3er1p5_PFJet100er2p5_PFMET80_PFMHT80_IDTight;   //!
   TBranch        *b_HLT_Mu3er1p5_PFJet100er2p5_PFMET90_PFMHT90_IDTight;   //!
   TBranch        *b_HLT_Mu3er1p5_PFJet100er2p5_PFMET100_PFMHT100_IDTight;   //!
   TBranch        *b_HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu70_PFMHTNoMu70_IDTight;   //!
   TBranch        *b_HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu80_PFMHTNoMu80_IDTight;   //!
   TBranch        *b_HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu90_PFMHTNoMu90_IDTight;   //!
   TBranch        *b_HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu100_PFMHTNoMu100_IDTight;   //!
   TBranch        *b_HLT_Dimuon10_PsiPrime_Barrel_Seagulls;   //!
   TBranch        *b_HLT_Dimuon20_Jpsi_Barrel_Seagulls;   //!
   TBranch        *b_HLT_Dimuon12_Upsilon_y1p4;   //!
   TBranch        *b_HLT_Dimuon14_Phi_Barrel_Seagulls;   //!
   TBranch        *b_HLT_Dimuon18_PsiPrime;   //!
   TBranch        *b_HLT_Dimuon25_Jpsi;   //!
   TBranch        *b_HLT_Dimuon18_PsiPrime_noCorrL1;   //!
   TBranch        *b_HLT_Dimuon24_Upsilon_noCorrL1;   //!
   TBranch        *b_HLT_Dimuon24_Phi_noCorrL1;   //!
   TBranch        *b_HLT_Dimuon25_Jpsi_noCorrL1;   //!
   TBranch        *b_HLT_DiMu4_Ele9_CaloIdL_TrackIdL_DZ_Mass3p8;   //!
   TBranch        *b_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ;   //!
   TBranch        *b_HLT_DiMu9_Ele9_CaloIdL_TrackIdL;   //!
   TBranch        *b_HLT_DoubleIsoMu20_eta2p1;   //!
   TBranch        *b_HLT_TrkMu12_DoubleTrkMu5NoFiltersNoVtx;   //!
   TBranch        *b_HLT_TrkMu16_DoubleTrkMu6NoFiltersNoVtx;   //!
   TBranch        *b_HLT_TrkMu17_DoubleTrkMu8NoFiltersNoVtx;   //!
   TBranch        *b_HLT_Mu8;   //!
   TBranch        *b_HLT_Mu17;   //!
   TBranch        *b_HLT_Mu19;   //!
   TBranch        *b_HLT_Mu17_Photon30_IsoCaloId;   //!
   TBranch        *b_HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30;   //!
   TBranch        *b_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30;   //!
   TBranch        *b_HLT_Ele15_CaloIdL_TrackIdL_IsoVL_PFJet30;   //!
   TBranch        *b_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30;   //!
   TBranch        *b_HLT_Ele8_CaloIdM_TrackIdM_PFJet30;   //!
   TBranch        *b_HLT_Ele17_CaloIdM_TrackIdM_PFJet30;   //!
   TBranch        *b_HLT_Ele23_CaloIdM_TrackIdM_PFJet30;   //!
   TBranch        *b_HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165;   //!
   TBranch        *b_HLT_Ele115_CaloIdVT_GsfTrkIdT;   //!
   TBranch        *b_HLT_Ele135_CaloIdVT_GsfTrkIdT;   //!
   TBranch        *b_HLT_Ele145_CaloIdVT_GsfTrkIdT;   //!
   TBranch        *b_HLT_Ele200_CaloIdVT_GsfTrkIdT;   //!
   TBranch        *b_HLT_Ele250_CaloIdVT_GsfTrkIdT;   //!
   TBranch        *b_HLT_Ele300_CaloIdVT_GsfTrkIdT;   //!
   TBranch        *b_HLT_PFHT330PT30_QuadPFJet_75_60_45_40_TriplePFBTagDeepCSV_4p5;   //!
   TBranch        *b_HLT_PFHT330PT30_QuadPFJet_75_60_45_40;   //!
   TBranch        *b_HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94;   //!
   TBranch        *b_HLT_PFHT400_SixPFJet32;   //!
   TBranch        *b_HLT_PFHT450_SixPFJet36_PFBTagDeepCSV_1p59;   //!
   TBranch        *b_HLT_PFHT450_SixPFJet36;   //!
   TBranch        *b_HLT_PFHT350;   //!
   TBranch        *b_HLT_PFHT350MinPFJet15;   //!
   TBranch        *b_HLT_Photon60_R9Id90_CaloIdL_IsoL;   //!
   TBranch        *b_HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL;   //!
   TBranch        *b_HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL_PFHT350MinPFJet15;   //!
   TBranch        *b_HLT_ECALHT800;   //!
   TBranch        *b_HLT_DiSC30_18_EIso_AND_HE_Mass70;   //!
   TBranch        *b_HLT_Physics;   //!
   TBranch        *b_HLT_Physics_part0;   //!
   TBranch        *b_HLT_Physics_part1;   //!
   TBranch        *b_HLT_Physics_part2;   //!
   TBranch        *b_HLT_Physics_part3;   //!
   TBranch        *b_HLT_Physics_part4;   //!
   TBranch        *b_HLT_Physics_part5;   //!
   TBranch        *b_HLT_Physics_part6;   //!
   TBranch        *b_HLT_Physics_part7;   //!
   TBranch        *b_HLT_Random;   //!
   TBranch        *b_HLT_ZeroBias;   //!
   TBranch        *b_HLT_ZeroBias_Alignment;   //!
   TBranch        *b_HLT_ZeroBias_part0;   //!
   TBranch        *b_HLT_ZeroBias_part1;   //!
   TBranch        *b_HLT_ZeroBias_part2;   //!
   TBranch        *b_HLT_ZeroBias_part3;   //!
   TBranch        *b_HLT_ZeroBias_part4;   //!
   TBranch        *b_HLT_ZeroBias_part5;   //!
   TBranch        *b_HLT_ZeroBias_part6;   //!
   TBranch        *b_HLT_ZeroBias_part7;   //!
   TBranch        *b_HLT_AK4CaloJet30;   //!
   TBranch        *b_HLT_AK4CaloJet40;   //!
   TBranch        *b_HLT_AK4CaloJet50;   //!
   TBranch        *b_HLT_AK4CaloJet80;   //!
   TBranch        *b_HLT_AK4CaloJet100;   //!
   TBranch        *b_HLT_AK4CaloJet120;   //!
   TBranch        *b_HLT_AK4PFJet30;   //!
   TBranch        *b_HLT_AK4PFJet50;   //!
   TBranch        *b_HLT_AK4PFJet80;   //!
   TBranch        *b_HLT_AK4PFJet100;   //!
   TBranch        *b_HLT_AK4PFJet120;   //!
   TBranch        *b_HLT_SinglePhoton10_Eta3p1ForPPRef;   //!
   TBranch        *b_HLT_SinglePhoton20_Eta3p1ForPPRef;   //!
   TBranch        *b_HLT_SinglePhoton30_Eta3p1ForPPRef;   //!
   TBranch        *b_HLT_Photon20_HoverELoose;   //!
   TBranch        *b_HLT_Photon30_HoverELoose;   //!
   TBranch        *b_HLT_EcalCalibration;   //!
   TBranch        *b_HLT_HcalCalibration;   //!
   TBranch        *b_HLT_L1UnpairedBunchBptxMinus;   //!
   TBranch        *b_HLT_L1UnpairedBunchBptxPlus;   //!
   TBranch        *b_HLT_L1NotBptxOR;   //!
   TBranch        *b_HLT_L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142;   //!
   TBranch        *b_HLT_CDC_L2cosmic_5_er1p0;   //!
   TBranch        *b_HLT_CDC_L2cosmic_5p5_er1p0;   //!
   TBranch        *b_HLT_HcalNZS;   //!
   TBranch        *b_HLT_HcalPhiSym;   //!
   TBranch        *b_HLT_HcalIsolatedbunch;   //!
   TBranch        *b_HLT_IsoTrackHB;   //!
   TBranch        *b_HLT_IsoTrackHE;   //!
   TBranch        *b_HLT_ZeroBias_FirstCollisionAfterAbortGap;   //!
   TBranch        *b_HLT_ZeroBias_IsolatedBunches;   //!
   TBranch        *b_HLT_ZeroBias_FirstCollisionInTrain;   //!
   TBranch        *b_HLT_ZeroBias_LastCollisionInTrain;   //!
   TBranch        *b_HLT_ZeroBias_FirstBXAfterTrain;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr;   //!
   TBranch        *b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90;   //!
   TBranch        *b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100;   //!
   TBranch        *b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET110;   //!
   TBranch        *b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET120;   //!
   TBranch        *b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET130;   //!
   TBranch        *b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET140;   //!
   TBranch        *b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr;   //!
   TBranch        *b_HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr;   //!
   TBranch        *b_HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1;   //!
   TBranch        *b_HLT_MediumChargedIsoPFTau200HighPtRelaxedIso_Trk50_eta2p1;   //!
   TBranch        *b_HLT_MediumChargedIsoPFTau220HighPtRelaxedIso_Trk50_eta2p1;   //!
   TBranch        *b_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL;   //!
   TBranch        *b_HLT_Rsq0p35;   //!
   TBranch        *b_HLT_Rsq0p40;   //!
   TBranch        *b_HLT_RsqMR300_Rsq0p09_MR200;   //!
   TBranch        *b_HLT_RsqMR320_Rsq0p09_MR200;   //!
   TBranch        *b_HLT_RsqMR300_Rsq0p09_MR200_4jet;   //!
   TBranch        *b_HLT_RsqMR320_Rsq0p09_MR200_4jet;   //!
   TBranch        *b_HLT_IsoMu27_MET90;   //!
   TBranch        *b_HLT_DoubleTightChargedIsoPFTauHPS35_Trk1_eta2p1_Reg;   //!
   TBranch        *b_HLT_DoubleMediumChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg;   //!
   TBranch        *b_HLT_DoubleMediumChargedIsoPFTauHPS35_Trk1_eta2p1_Reg;   //!
   TBranch        *b_HLT_DoubleTightChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg;   //!
   TBranch        *b_HLT_DoubleMediumChargedIsoPFTauHPS40_Trk1_eta2p1_Reg;   //!
   TBranch        *b_HLT_DoubleTightChargedIsoPFTauHPS40_Trk1_eta2p1_Reg;   //!
   TBranch        *b_HLT_DoubleMediumChargedIsoPFTauHPS40_Trk1_TightID_eta2p1_Reg;   //!
   TBranch        *b_HLT_DoubleTightChargedIsoPFTauHPS40_Trk1_TightID_eta2p1_Reg;   //!
   TBranch        *b_HLT_VBF_DoubleLooseChargedIsoPFTauHPS20_Trk1_eta2p1;   //!
   TBranch        *b_HLT_VBF_DoubleMediumChargedIsoPFTauHPS20_Trk1_eta2p1;   //!
   TBranch        *b_HLT_VBF_DoubleTightChargedIsoPFTauHPS20_Trk1_eta2p1;   //!
   TBranch        *b_HLT_Photon50_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3_PFMET50;   //!
   TBranch        *b_HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3;   //!
   TBranch        *b_HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ600DEta3;   //!
   TBranch        *b_HLT_PFMET100_PFMHT100_IDTight_PFHT60;   //!
   TBranch        *b_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_PFHT60;   //!
   TBranch        *b_HLT_PFMETTypeOne100_PFMHT100_IDTight_PFHT60;   //!
   TBranch        *b_HLT_Mu18_Mu9_SameSign;   //!
   TBranch        *b_HLT_Mu18_Mu9_SameSign_DZ;   //!
   TBranch        *b_HLT_Mu18_Mu9;   //!
   TBranch        *b_HLT_Mu18_Mu9_DZ;   //!
   TBranch        *b_HLT_Mu20_Mu10_SameSign;   //!
   TBranch        *b_HLT_Mu20_Mu10_SameSign_DZ;   //!
   TBranch        *b_HLT_Mu20_Mu10;   //!
   TBranch        *b_HLT_Mu20_Mu10_DZ;   //!
   TBranch        *b_HLT_Mu23_Mu12_SameSign;   //!
   TBranch        *b_HLT_Mu23_Mu12_SameSign_DZ;   //!
   TBranch        *b_HLT_Mu23_Mu12;   //!
   TBranch        *b_HLT_Mu23_Mu12_DZ;   //!
   TBranch        *b_HLT_DoubleMu2_Jpsi_DoubleTrk1_Phi1p05;   //!
   TBranch        *b_HLT_DoubleMu2_Jpsi_DoubleTkMu0_Phi;   //!
   TBranch        *b_HLT_DoubleMu3_DCA_PFMET50_PFMHT60;   //!
   TBranch        *b_HLT_TripleMu_5_3_3_Mass3p8_DCA;   //!
   TBranch        *b_HLT_QuadPFJet98_83_71_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1;   //!
   TBranch        *b_HLT_QuadPFJet103_88_75_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1;   //!
   TBranch        *b_HLT_QuadPFJet111_90_80_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1;   //!
   TBranch        *b_HLT_QuadPFJet98_83_71_15_PFBTagDeepCSV_1p3_VBF2;   //!
   TBranch        *b_HLT_QuadPFJet103_88_75_15_PFBTagDeepCSV_1p3_VBF2;   //!
   TBranch        *b_HLT_QuadPFJet105_88_76_15_PFBTagDeepCSV_1p3_VBF2;   //!
   TBranch        *b_HLT_QuadPFJet111_90_80_15_PFBTagDeepCSV_1p3_VBF2;   //!
   TBranch        *b_HLT_QuadPFJet98_83_71_15;   //!
   TBranch        *b_HLT_QuadPFJet103_88_75_15;   //!
   TBranch        *b_HLT_QuadPFJet105_88_76_15;   //!
   TBranch        *b_HLT_QuadPFJet111_90_80_15;   //!
   TBranch        *b_HLT_AK8PFJet330_TrimMass30_PFAK8BTagDeepCSV_p17;   //!
   TBranch        *b_HLT_AK8PFJet330_TrimMass30_PFAK8BTagDeepCSV_p1;   //!
   TBranch        *b_HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_p02;   //!
   TBranch        *b_HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_np2;   //!
   TBranch        *b_HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_np4;   //!
   TBranch        *b_HLT_AK8PFJet330_PFAK8BTagCSV_p17;   //!
   TBranch        *b_HLT_AK8DiPFJet300_200_TrimMass30_BTagCSV_p20;   //!
   TBranch        *b_HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p087;   //!
   TBranch        *b_HLT_AK8DiPFJet300_200_TrimMass30_BTagCSV_p087;   //!
   TBranch        *b_HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20;   //!
   TBranch        *b_HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20;   //!
   TBranch        *b_HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20;   //!
   TBranch        *b_HLT_Diphoton30_18_R9IdL_AND_HE_AND_IsoCaloId_NoPixelVeto_Mass55;   //!
   TBranch        *b_HLT_Diphoton30_18_R9IdL_AND_HE_AND_IsoCaloId_NoPixelVeto;   //!
   TBranch        *b_HLT_Mu12_IP6_part0;   //!
   TBranch        *b_HLT_Mu12_IP6_part1;   //!
   TBranch        *b_HLT_Mu12_IP6_part2;   //!
   TBranch        *b_HLT_Mu12_IP6_part3;   //!
   TBranch        *b_HLT_Mu12_IP6_part4;   //!
   TBranch        *b_HLT_Mu9_IP5_part0;   //!
   TBranch        *b_HLT_Mu9_IP5_part1;   //!
   TBranch        *b_HLT_Mu9_IP5_part2;   //!
   TBranch        *b_HLT_Mu9_IP5_part3;   //!
   TBranch        *b_HLT_Mu9_IP5_part4;   //!
   TBranch        *b_HLT_Mu7_IP4_part0;   //!
   TBranch        *b_HLT_Mu7_IP4_part1;   //!
   TBranch        *b_HLT_Mu7_IP4_part2;   //!
   TBranch        *b_HLT_Mu7_IP4_part3;   //!
   TBranch        *b_HLT_Mu7_IP4_part4;   //!
   TBranch        *b_HLT_Mu9_IP4_part0;   //!
   TBranch        *b_HLT_Mu9_IP4_part1;   //!
   TBranch        *b_HLT_Mu9_IP4_part2;   //!
   TBranch        *b_HLT_Mu9_IP4_part3;   //!
   TBranch        *b_HLT_Mu9_IP4_part4;   //!
   TBranch        *b_HLT_Mu8_IP5_part0;   //!
   TBranch        *b_HLT_Mu8_IP5_part1;   //!
   TBranch        *b_HLT_Mu8_IP5_part2;   //!
   TBranch        *b_HLT_Mu8_IP5_part3;   //!
   TBranch        *b_HLT_Mu8_IP5_part4;   //!
   TBranch        *b_HLT_Mu8_IP6_part0;   //!
   TBranch        *b_HLT_Mu8_IP6_part1;   //!
   TBranch        *b_HLT_Mu8_IP6_part2;   //!
   TBranch        *b_HLT_Mu8_IP6_part3;   //!
   TBranch        *b_HLT_Mu8_IP6_part4;   //!
   TBranch        *b_HLT_Mu9_IP6_part0;   //!
   TBranch        *b_HLT_Mu9_IP6_part1;   //!
   TBranch        *b_HLT_Mu9_IP6_part2;   //!
   TBranch        *b_HLT_Mu9_IP6_part3;   //!
   TBranch        *b_HLT_Mu9_IP6_part4;   //!
   TBranch        *b_HLT_Mu8_IP3_part0;   //!
   TBranch        *b_HLT_Mu8_IP3_part1;   //!
   TBranch        *b_HLT_Mu8_IP3_part2;   //!
   TBranch        *b_HLT_Mu8_IP3_part3;   //!
   TBranch        *b_HLT_Mu8_IP3_part4;   //!
   TBranch        *b_HLT_QuadPFJet105_88_76_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1;   //!
   TBranch        *b_HLT_TrkMu6NoFiltersNoVtx;   //!
   TBranch        *b_HLT_TrkMu16NoFiltersNoVtx;   //!
   TBranch        *b_HLT_DoubleTrkMu_16_6_NoFiltersNoVtx;   //!
   TBranch        *b_HLT_QuadPFJet70_50_40_30;   //!
   TBranch        *b_HLT_QuadPFJet70_50_40_30_PFBTagParticleNet_2BTagSum0p65;   //!
   TBranch        *b_HLT_QuadPFJet70_50_40_35_PFBTagParticleNet_2BTagSum0p65;   //!
   TBranch        *b_HLT_QuadPFJet70_50_45_35_PFBTagParticleNet_2BTagSum0p65;   //!
   TBranch        *b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBTagParticleNet_2BTagSum0p65;   //!
   TBranch        *b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_QuadPFJet70_50_40_30;   //!
   TBranch        *b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_QuadPFJet70_50_40_30_PFBTagParticleNet_2BTagSum0p65;   //!
   TBranch        *b_HLT_AK8PFJet230_SoftDropMass40;   //!
   TBranch        *b_HLT_AK8PFJet230_SoftDropMass40_PFAK8ParticleNetBB0p35;   //!
   TBranch        *b_HLT_AK8PFJet250_SoftDropMass40_PFAK8ParticleNetBB0p35;   //!
   TBranch        *b_HLT_AK8PFJet275_SoftDropMass40_PFAK8ParticleNetBB0p35;   //!
   TBranch        *b_HLT_AK8PFJet400_SoftDropMass40;   //!
   TBranch        *b_HLT_AK8PFJet425_SoftDropMass40;   //!
   TBranch        *b_HLT_AK8PFJet450_SoftDropMass40;   //!
   TBranch        *b_HLT_AK8PFJet230_SoftDropMass40_PFAK8ParticleNetTauTau0p30;   //!
   TBranch        *b_HLT_AK8PFJet250_SoftDropMass40_PFAK8ParticleNetTauTau0p30;   //!
   TBranch        *b_HLT_AK8PFJet275_SoftDropMass40_PFAK8ParticleNetTauTau0p30;   //!
   TBranch        *b_HLT_IsoMu50_AK8PFJet230_SoftDropMass40;   //!
   TBranch        *b_HLT_IsoMu50_AK8PFJet230_SoftDropMass40_PFAK8ParticleNetBB0p35;   //!
   TBranch        *b_HLT_Ele50_CaloIdVT_GsfTrkIdT_AK8PFJet230_SoftDropMass40;   //!
   TBranch        *b_HLT_Ele50_CaloIdVT_GsfTrkIdT_AK8PFJet230_SoftDropMass40_PFAK8ParticleNetBB0p35;   //!
   TBranch        *b_HLTriggerFinalPath;   //!
   TBranch        *b_Flag_HBHENoiseFilter;   //!
   TBranch        *b_Flag_HBHENoiseIsoFilter;   //!
   TBranch        *b_Flag_CSCTightHaloFilter;   //!
   TBranch        *b_Flag_CSCTightHaloTrkMuUnvetoFilter;   //!
   TBranch        *b_Flag_CSCTightHalo2015Filter;   //!
   TBranch        *b_Flag_globalTightHalo2016Filter;   //!
   TBranch        *b_Flag_globalSuperTightHalo2016Filter;   //!
   TBranch        *b_Flag_HcalStripHaloFilter;   //!
   TBranch        *b_Flag_hcalLaserEventFilter;   //!
   TBranch        *b_Flag_EcalDeadCellTriggerPrimitiveFilter;   //!
   TBranch        *b_Flag_EcalDeadCellBoundaryEnergyFilter;   //!
   TBranch        *b_Flag_ecalBadCalibFilter;   //!
   TBranch        *b_Flag_goodVertices;   //!
   TBranch        *b_Flag_eeBadScFilter;   //!
   TBranch        *b_Flag_ecalLaserCorrFilter;   //!
   TBranch        *b_Flag_trkPOGFilters;   //!
   TBranch        *b_Flag_chargedHadronTrackResolutionFilter;   //!
   TBranch        *b_Flag_muonBadTrackFilter;   //!
   TBranch        *b_Flag_BadChargedCandidateFilter;   //!
   TBranch        *b_Flag_BadPFMuonFilter;   //!
   TBranch        *b_Flag_BadChargedCandidateSummer16Filter;   //!
   TBranch        *b_Flag_BadPFMuonSummer16Filter;   //!
   TBranch        *b_Flag_trkPOG_manystripclus53X;   //!
   TBranch        *b_Flag_trkPOG_toomanystripclus53X;   //!
   TBranch        *b_Flag_trkPOG_logErrorTooManyClusters;   //!
   TBranch        *b_Flag_METFilters;   //!
   TBranch        *b_L1Reco_step;   //!
   TBranch        *b_L1_AlwaysTrue;   //!
   TBranch        *b_L1_BPTX_AND_Ref1_VME;   //!
   TBranch        *b_L1_BPTX_AND_Ref3_VME;   //!
   TBranch        *b_L1_BPTX_AND_Ref4_VME;   //!
   TBranch        *b_L1_BPTX_BeamGas_B1_VME;   //!
   TBranch        *b_L1_BPTX_BeamGas_B2_VME;   //!
   TBranch        *b_L1_BPTX_BeamGas_Ref1_VME;   //!
   TBranch        *b_L1_BPTX_BeamGas_Ref2_VME;   //!
   TBranch        *b_L1_BPTX_NotOR_VME;   //!
   TBranch        *b_L1_BPTX_OR_Ref3_VME;   //!
   TBranch        *b_L1_BPTX_OR_Ref4_VME;   //!
   TBranch        *b_L1_BPTX_RefAND_VME;   //!
   TBranch        *b_L1_BptxMinus;   //!
   TBranch        *b_L1_BptxOR;   //!
   TBranch        *b_L1_BptxPlus;   //!
   TBranch        *b_L1_BptxXOR;   //!
   TBranch        *b_L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142;   //!
   TBranch        *b_L1_DoubleEG8er2p5_HTT260er;   //!
   TBranch        *b_L1_DoubleEG8er2p5_HTT280er;   //!
   TBranch        *b_L1_DoubleEG8er2p5_HTT300er;   //!
   TBranch        *b_L1_DoubleEG8er2p5_HTT320er;   //!
   TBranch        *b_L1_DoubleEG8er2p5_HTT340er;   //!
   TBranch        *b_L1_DoubleEG_15_10_er2p5;   //!
   TBranch        *b_L1_DoubleEG_20_10_er2p5;   //!
   TBranch        *b_L1_DoubleEG_22_10_er2p5;   //!
   TBranch        *b_L1_DoubleEG_25_12_er2p5;   //!
   TBranch        *b_L1_DoubleEG_25_14_er2p5;   //!
   TBranch        *b_L1_DoubleEG_27_14_er2p5;   //!
   TBranch        *b_L1_DoubleEG_LooseIso20_10_er2p5;   //!
   TBranch        *b_L1_DoubleEG_LooseIso22_10_er2p5;   //!
   TBranch        *b_L1_DoubleEG_LooseIso22_12_er2p5;   //!
   TBranch        *b_L1_DoubleEG_LooseIso25_12_er2p5;   //!
   TBranch        *b_L1_DoubleIsoTau32er2p1;   //!
   TBranch        *b_L1_DoubleIsoTau34er2p1;   //!
   TBranch        *b_L1_DoubleIsoTau36er2p1;   //!
   TBranch        *b_L1_DoubleJet100er2p3_dEta_Max1p6;   //!
   TBranch        *b_L1_DoubleJet100er2p5;   //!
   TBranch        *b_L1_DoubleJet112er2p3_dEta_Max1p6;   //!
   TBranch        *b_L1_DoubleJet120er2p5;   //!
   TBranch        *b_L1_DoubleJet150er2p5;   //!
   TBranch        *b_L1_DoubleJet30er2p5_Mass_Min150_dEta_Max1p5;   //!
   TBranch        *b_L1_DoubleJet30er2p5_Mass_Min200_dEta_Max1p5;   //!
   TBranch        *b_L1_DoubleJet30er2p5_Mass_Min250_dEta_Max1p5;   //!
   TBranch        *b_L1_DoubleJet30er2p5_Mass_Min300_dEta_Max1p5;   //!
   TBranch        *b_L1_DoubleJet30er2p5_Mass_Min330_dEta_Max1p5;   //!
   TBranch        *b_L1_DoubleJet30er2p5_Mass_Min360_dEta_Max1p5;   //!
   TBranch        *b_L1_DoubleJet35_Mass_Min450_IsoTau45_RmOvlp;   //!
   TBranch        *b_L1_DoubleJet40er2p5;   //!
   TBranch        *b_L1_DoubleJet_100_30_DoubleJet30_Mass_Min620;   //!
   TBranch        *b_L1_DoubleJet_110_35_DoubleJet35_Mass_Min620;   //!
   TBranch        *b_L1_DoubleJet_115_40_DoubleJet40_Mass_Min620;   //!
   TBranch        *b_L1_DoubleJet_115_40_DoubleJet40_Mass_Min620_Jet60TT28;   //!
   TBranch        *b_L1_DoubleJet_120_45_DoubleJet45_Mass_Min620;   //!
   TBranch        *b_L1_DoubleJet_120_45_DoubleJet45_Mass_Min620_Jet60TT28;   //!
   TBranch        *b_L1_DoubleJet_80_30_Mass_Min420_DoubleMu0_SQ;   //!
   TBranch        *b_L1_DoubleJet_80_30_Mass_Min420_IsoTau40_RmOvlp;   //!
   TBranch        *b_L1_DoubleJet_80_30_Mass_Min420_Mu8;   //!
   TBranch        *b_L1_DoubleJet_90_30_DoubleJet30_Mass_Min620;   //!
   TBranch        *b_L1_DoubleLooseIsoEG22er2p1;   //!
   TBranch        *b_L1_DoubleLooseIsoEG24er2p1;   //!
   TBranch        *b_L1_DoubleMu0;   //!
   TBranch        *b_L1_DoubleMu0_Mass_Min1;   //!
   TBranch        *b_L1_DoubleMu0_OQ;   //!
   TBranch        *b_L1_DoubleMu0_SQ;   //!
   TBranch        *b_L1_DoubleMu0_SQ_OS;   //!
   TBranch        *b_L1_DoubleMu0_dR_Max1p6_Jet90er2p5_dR_Max0p8;   //!
   TBranch        *b_L1_DoubleMu0er1p4_SQ_OS_dR_Max1p4;   //!
   TBranch        *b_L1_DoubleMu0er1p5_SQ;   //!
   TBranch        *b_L1_DoubleMu0er1p5_SQ_OS;   //!
   TBranch        *b_L1_DoubleMu0er1p5_SQ_OS_dR_Max1p4;   //!
   TBranch        *b_L1_DoubleMu0er1p5_SQ_dR_Max1p4;   //!
   TBranch        *b_L1_DoubleMu0er2p0_SQ_OS_dR_Max1p4;   //!
   TBranch        *b_L1_DoubleMu0er2p0_SQ_dR_Max1p4;   //!
   TBranch        *b_L1_DoubleMu10_SQ;   //!
   TBranch        *b_L1_DoubleMu18er2p1;   //!
   TBranch        *b_L1_DoubleMu3_OS_DoubleEG7p5Upsilon;   //!
   TBranch        *b_L1_DoubleMu3_SQ_ETMHF50_HTT60er;   //!
   TBranch        *b_L1_DoubleMu3_SQ_ETMHF50_Jet60er2p5;   //!
   TBranch        *b_L1_DoubleMu3_SQ_ETMHF50_Jet60er2p5_OR_DoubleJet40er2p5;   //!
   TBranch        *b_L1_DoubleMu3_SQ_ETMHF60_Jet60er2p5;   //!
   TBranch        *b_L1_DoubleMu3_SQ_HTT220er;   //!
   TBranch        *b_L1_DoubleMu3_SQ_HTT240er;   //!
   TBranch        *b_L1_DoubleMu3_SQ_HTT260er;   //!
   TBranch        *b_L1_DoubleMu3_dR_Max1p6_Jet90er2p5_dR_Max0p8;   //!
   TBranch        *b_L1_DoubleMu4_SQ_EG9er2p5;   //!
   TBranch        *b_L1_DoubleMu4_SQ_OS;   //!
   TBranch        *b_L1_DoubleMu4_SQ_OS_dR_Max1p2;   //!
   TBranch        *b_L1_DoubleMu4p5_SQ_OS;   //!
   TBranch        *b_L1_DoubleMu4p5_SQ_OS_dR_Max1p2;   //!
   TBranch        *b_L1_DoubleMu4p5er2p0_SQ_OS;   //!
   TBranch        *b_L1_DoubleMu4p5er2p0_SQ_OS_Mass7to18;   //!
   TBranch        *b_L1_DoubleMu5Upsilon_OS_DoubleEG3;   //!
   TBranch        *b_L1_DoubleMu5_SQ_EG9er2p5;   //!
   TBranch        *b_L1_DoubleMu9_SQ;   //!
   TBranch        *b_L1_DoubleMu_12_5;   //!
   TBranch        *b_L1_DoubleMu_15_5_SQ;   //!
   TBranch        *b_L1_DoubleMu_15_7;   //!
   TBranch        *b_L1_DoubleMu_15_7_Mass_Min1;   //!
   TBranch        *b_L1_DoubleMu_15_7_SQ;   //!
   TBranch        *b_L1_DoubleTau70er2p1;   //!
   TBranch        *b_L1_ETM120;   //!
   TBranch        *b_L1_ETM150;   //!
   TBranch        *b_L1_ETMHF100;   //!
   TBranch        *b_L1_ETMHF100_HTT60er;   //!
   TBranch        *b_L1_ETMHF110;   //!
   TBranch        *b_L1_ETMHF110_HTT60er;   //!
   TBranch        *b_L1_ETMHF110_HTT60er_NotSecondBunchInTrain;   //!
   TBranch        *b_L1_ETMHF120;   //!
   TBranch        *b_L1_ETMHF120_HTT60er;   //!
   TBranch        *b_L1_ETMHF120_NotSecondBunchInTrain;   //!
   TBranch        *b_L1_ETMHF130;   //!
   TBranch        *b_L1_ETMHF130_HTT60er;   //!
   TBranch        *b_L1_ETMHF140;   //!
   TBranch        *b_L1_ETMHF150;   //!
   TBranch        *b_L1_ETMHF90_HTT60er;   //!
   TBranch        *b_L1_ETT1200;   //!
   TBranch        *b_L1_ETT1600;   //!
   TBranch        *b_L1_ETT2000;   //!
   TBranch        *b_L1_FirstBunchAfterTrain;   //!
   TBranch        *b_L1_FirstBunchBeforeTrain;   //!
   TBranch        *b_L1_FirstBunchInTrain;   //!
   TBranch        *b_L1_FirstCollisionInOrbit;   //!
   TBranch        *b_L1_FirstCollisionInTrain;   //!
   TBranch        *b_L1_HCAL_LaserMon_Trig;   //!
   TBranch        *b_L1_HCAL_LaserMon_Veto;   //!
   TBranch        *b_L1_HTT120er;   //!
   TBranch        *b_L1_HTT160er;   //!
   TBranch        *b_L1_HTT200er;   //!
   TBranch        *b_L1_HTT255er;   //!
   TBranch        *b_L1_HTT280er;   //!
   TBranch        *b_L1_HTT280er_QuadJet_70_55_40_35_er2p4;   //!
   TBranch        *b_L1_HTT320er;   //!
   TBranch        *b_L1_HTT320er_QuadJet_70_55_40_40_er2p4;   //!
   TBranch        *b_L1_HTT320er_QuadJet_80_60_er2p1_45_40_er2p3;   //!
   TBranch        *b_L1_HTT320er_QuadJet_80_60_er2p1_50_45_er2p3;   //!
   TBranch        *b_L1_HTT360er;   //!
   TBranch        *b_L1_HTT400er;   //!
   TBranch        *b_L1_HTT450er;   //!
   TBranch        *b_L1_IsoEG32er2p5_Mt40;   //!
   TBranch        *b_L1_IsoEG32er2p5_Mt44;   //!
   TBranch        *b_L1_IsoEG32er2p5_Mt48;   //!
   TBranch        *b_L1_IsoTau40er2p1_ETMHF100;   //!
   TBranch        *b_L1_IsoTau40er2p1_ETMHF110;   //!
   TBranch        *b_L1_IsoTau40er2p1_ETMHF120;   //!
   TBranch        *b_L1_IsoTau40er2p1_ETMHF90;   //!
   TBranch        *b_L1_IsolatedBunch;   //!
   TBranch        *b_L1_LastBunchInTrain;   //!
   TBranch        *b_L1_LastCollisionInTrain;   //!
   TBranch        *b_L1_LooseIsoEG22er2p1_IsoTau26er2p1_dR_Min0p3;   //!
   TBranch        *b_L1_LooseIsoEG22er2p1_Tau70er2p1_dR_Min0p3;   //!
   TBranch        *b_L1_LooseIsoEG24er2p1_HTT100er;   //!
   TBranch        *b_L1_LooseIsoEG24er2p1_IsoTau27er2p1_dR_Min0p3;   //!
   TBranch        *b_L1_LooseIsoEG26er2p1_HTT100er;   //!
   TBranch        *b_L1_LooseIsoEG26er2p1_Jet34er2p5_dR_Min0p3;   //!
   TBranch        *b_L1_LooseIsoEG28er2p1_HTT100er;   //!
   TBranch        *b_L1_LooseIsoEG28er2p1_Jet34er2p5_dR_Min0p3;   //!
   TBranch        *b_L1_LooseIsoEG30er2p1_HTT100er;   //!
   TBranch        *b_L1_LooseIsoEG30er2p1_Jet34er2p5_dR_Min0p3;   //!
   TBranch        *b_L1_MinimumBiasHF0_AND_BptxAND;   //!
   TBranch        *b_L1_Mu10er2p3_Jet32er2p3_dR_Max0p4_DoubleJet32er2p3_dEta_Max1p6;   //!
   TBranch        *b_L1_Mu12er2p3_Jet40er2p1_dR_Max0p4_DoubleJet40er2p1_dEta_Max1p6;   //!
   TBranch        *b_L1_Mu12er2p3_Jet40er2p3_dR_Max0p4_DoubleJet40er2p3_dEta_Max1p6;   //!
   TBranch        *b_L1_Mu18er2p1_Tau24er2p1;   //!
   TBranch        *b_L1_Mu18er2p1_Tau26er2p1;   //!
   TBranch        *b_L1_Mu20_EG10er2p5;   //!
   TBranch        *b_L1_Mu22er2p1_IsoTau32er2p1;   //!
   TBranch        *b_L1_Mu22er2p1_IsoTau34er2p1;   //!
   TBranch        *b_L1_Mu22er2p1_IsoTau36er2p1;   //!
   TBranch        *b_L1_Mu22er2p1_IsoTau40er2p1;   //!
   TBranch        *b_L1_Mu22er2p1_Tau70er2p1;   //!
   TBranch        *b_L1_Mu3_Jet120er2p5_dR_Max0p4;   //!
   TBranch        *b_L1_Mu3_Jet120er2p5_dR_Max0p8;   //!
   TBranch        *b_L1_Mu3_Jet16er2p5_dR_Max0p4;   //!
   TBranch        *b_L1_Mu3_Jet30er2p5;   //!
   TBranch        *b_L1_Mu3_Jet35er2p5_dR_Max0p4;   //!
   TBranch        *b_L1_Mu3_Jet60er2p5_dR_Max0p4;   //!
   TBranch        *b_L1_Mu3_Jet80er2p5_dR_Max0p4;   //!
   TBranch        *b_L1_Mu3er1p5_Jet100er2p5_ETMHF40;   //!
   TBranch        *b_L1_Mu3er1p5_Jet100er2p5_ETMHF50;   //!
   TBranch        *b_L1_Mu5_EG23er2p5;   //!
   TBranch        *b_L1_Mu5_LooseIsoEG20er2p5;   //!
   TBranch        *b_L1_Mu6_DoubleEG10er2p5;   //!
   TBranch        *b_L1_Mu6_DoubleEG12er2p5;   //!
   TBranch        *b_L1_Mu6_DoubleEG15er2p5;   //!
   TBranch        *b_L1_Mu6_DoubleEG17er2p5;   //!
   TBranch        *b_L1_Mu6_HTT240er;   //!
   TBranch        *b_L1_Mu6_HTT250er;   //!
   TBranch        *b_L1_Mu7_EG23er2p5;   //!
   TBranch        *b_L1_Mu7_LooseIsoEG20er2p5;   //!
   TBranch        *b_L1_Mu7_LooseIsoEG23er2p5;   //!
   TBranch        *b_L1_NotBptxOR;   //!
   TBranch        *b_L1_QuadJet36er2p5_IsoTau52er2p1;   //!
   TBranch        *b_L1_QuadJet60er2p5;   //!
   TBranch        *b_L1_QuadJet_95_75_65_20_DoubleJet_75_65_er2p5_Jet20_FWD3p0;   //!
   TBranch        *b_L1_QuadMu0;   //!
   TBranch        *b_L1_QuadMu0_OQ;   //!
   TBranch        *b_L1_QuadMu0_SQ;   //!
   TBranch        *b_L1_SecondBunchInTrain;   //!
   TBranch        *b_L1_SecondLastBunchInTrain;   //!
   TBranch        *b_L1_SingleEG10er2p5;   //!
   TBranch        *b_L1_SingleEG15er2p5;   //!
   TBranch        *b_L1_SingleEG26er2p5;   //!
   TBranch        *b_L1_SingleEG34er2p5;   //!
   TBranch        *b_L1_SingleEG36er2p5;   //!
   TBranch        *b_L1_SingleEG38er2p5;   //!
   TBranch        *b_L1_SingleEG40er2p5;   //!
   TBranch        *b_L1_SingleEG42er2p5;   //!
   TBranch        *b_L1_SingleEG45er2p5;   //!
   TBranch        *b_L1_SingleEG50;   //!
   TBranch        *b_L1_SingleEG60;   //!
   TBranch        *b_L1_SingleEG8er2p5;   //!
   TBranch        *b_L1_SingleIsoEG24er1p5;   //!
   TBranch        *b_L1_SingleIsoEG24er2p1;   //!
   TBranch        *b_L1_SingleIsoEG26er1p5;   //!
   TBranch        *b_L1_SingleIsoEG26er2p1;   //!
   TBranch        *b_L1_SingleIsoEG26er2p5;   //!
   TBranch        *b_L1_SingleIsoEG28er1p5;   //!
   TBranch        *b_L1_SingleIsoEG28er2p1;   //!
   TBranch        *b_L1_SingleIsoEG28er2p5;   //!
   TBranch        *b_L1_SingleIsoEG30er2p1;   //!
   TBranch        *b_L1_SingleIsoEG30er2p5;   //!
   TBranch        *b_L1_SingleIsoEG32er2p1;   //!
   TBranch        *b_L1_SingleIsoEG32er2p5;   //!
   TBranch        *b_L1_SingleIsoEG34er2p5;   //!
   TBranch        *b_L1_SingleJet10erHE;   //!
   TBranch        *b_L1_SingleJet120;   //!
   TBranch        *b_L1_SingleJet120_FWD3p0;   //!
   TBranch        *b_L1_SingleJet120er2p5;   //!
   TBranch        *b_L1_SingleJet12erHE;   //!
   TBranch        *b_L1_SingleJet140er2p5;   //!
   TBranch        *b_L1_SingleJet140er2p5_ETMHF80;   //!
   TBranch        *b_L1_SingleJet140er2p5_ETMHF90;   //!
   TBranch        *b_L1_SingleJet160er2p5;   //!
   TBranch        *b_L1_SingleJet180;   //!
   TBranch        *b_L1_SingleJet180er2p5;   //!
   TBranch        *b_L1_SingleJet200;   //!
   TBranch        *b_L1_SingleJet20er2p5_NotBptxOR;   //!
   TBranch        *b_L1_SingleJet20er2p5_NotBptxOR_3BX;   //!
   TBranch        *b_L1_SingleJet35;   //!
   TBranch        *b_L1_SingleJet35_FWD3p0;   //!
   TBranch        *b_L1_SingleJet35er2p5;   //!
   TBranch        *b_L1_SingleJet43er2p5_NotBptxOR_3BX;   //!
   TBranch        *b_L1_SingleJet46er2p5_NotBptxOR_3BX;   //!
   TBranch        *b_L1_SingleJet60;   //!
   TBranch        *b_L1_SingleJet60_FWD3p0;   //!
   TBranch        *b_L1_SingleJet60er2p5;   //!
   TBranch        *b_L1_SingleJet8erHE;   //!
   TBranch        *b_L1_SingleJet90;   //!
   TBranch        *b_L1_SingleJet90_FWD3p0;   //!
   TBranch        *b_L1_SingleJet90er2p5;   //!
   TBranch        *b_L1_SingleLooseIsoEG28er1p5;   //!
   TBranch        *b_L1_SingleLooseIsoEG30er1p5;   //!
   TBranch        *b_L1_SingleMu0_BMTF;   //!
   TBranch        *b_L1_SingleMu0_DQ;   //!
   TBranch        *b_L1_SingleMu0_EMTF;   //!
   TBranch        *b_L1_SingleMu0_OMTF;   //!
   TBranch        *b_L1_SingleMu10er1p5;   //!
   TBranch        *b_L1_SingleMu12_DQ_BMTF;   //!
   TBranch        *b_L1_SingleMu12_DQ_EMTF;   //!
   TBranch        *b_L1_SingleMu12_DQ_OMTF;   //!
   TBranch        *b_L1_SingleMu12er1p5;   //!
   TBranch        *b_L1_SingleMu14er1p5;   //!
   TBranch        *b_L1_SingleMu15_DQ;   //!
   TBranch        *b_L1_SingleMu16er1p5;   //!
   TBranch        *b_L1_SingleMu18;   //!
   TBranch        *b_L1_SingleMu18er1p5;   //!
   TBranch        *b_L1_SingleMu20;   //!
   TBranch        *b_L1_SingleMu22;   //!
   TBranch        *b_L1_SingleMu22_BMTF;   //!
   TBranch        *b_L1_SingleMu22_EMTF;   //!
   TBranch        *b_L1_SingleMu22_OMTF;   //!
   TBranch        *b_L1_SingleMu25;   //!
   TBranch        *b_L1_SingleMu3;   //!
   TBranch        *b_L1_SingleMu5;   //!
   TBranch        *b_L1_SingleMu6er1p5;   //!
   TBranch        *b_L1_SingleMu7;   //!
   TBranch        *b_L1_SingleMu7_DQ;   //!
   TBranch        *b_L1_SingleMu7er1p5;   //!
   TBranch        *b_L1_SingleMu8er1p5;   //!
   TBranch        *b_L1_SingleMu9er1p5;   //!
   TBranch        *b_L1_SingleMuCosmics;   //!
   TBranch        *b_L1_SingleMuCosmics_BMTF;   //!
   TBranch        *b_L1_SingleMuCosmics_EMTF;   //!
   TBranch        *b_L1_SingleMuCosmics_OMTF;   //!
   TBranch        *b_L1_SingleMuOpen;   //!
   TBranch        *b_L1_SingleMuOpen_NotBptxOR;   //!
   TBranch        *b_L1_SingleMuOpen_er1p1_NotBptxOR_3BX;   //!
   TBranch        *b_L1_SingleMuOpen_er1p4_NotBptxOR_3BX;   //!
   TBranch        *b_L1_SingleTau120er2p1;   //!
   TBranch        *b_L1_SingleTau130er2p1;   //!
   TBranch        *b_L1_TOTEM_1;   //!
   TBranch        *b_L1_TOTEM_2;   //!
   TBranch        *b_L1_TOTEM_3;   //!
   TBranch        *b_L1_TOTEM_4;   //!
   TBranch        *b_L1_TripleEG16er2p5;   //!
   TBranch        *b_L1_TripleEG_16_12_8_er2p5;   //!
   TBranch        *b_L1_TripleEG_16_15_8_er2p5;   //!
   TBranch        *b_L1_TripleEG_18_17_8_er2p5;   //!
   TBranch        *b_L1_TripleEG_18_18_12_er2p5;   //!
   TBranch        *b_L1_TripleJet_100_80_70_DoubleJet_80_70_er2p5;   //!
   TBranch        *b_L1_TripleJet_105_85_75_DoubleJet_85_75_er2p5;   //!
   TBranch        *b_L1_TripleJet_95_75_65_DoubleJet_75_65_er2p5;   //!
   TBranch        *b_L1_TripleMu0;   //!
   TBranch        *b_L1_TripleMu0_OQ;   //!
   TBranch        *b_L1_TripleMu0_SQ;   //!
   TBranch        *b_L1_TripleMu3;   //!
   TBranch        *b_L1_TripleMu3_SQ;   //!
   TBranch        *b_L1_TripleMu_5SQ_3SQ_0OQ;   //!
   TBranch        *b_L1_TripleMu_5SQ_3SQ_0OQ_DoubleMu_5_3_SQ_OS_Mass_Max9;   //!
   TBranch        *b_L1_TripleMu_5SQ_3SQ_0_DoubleMu_5_3_SQ_OS_Mass_Max9;   //!
   TBranch        *b_L1_TripleMu_5_3_3;   //!
   TBranch        *b_L1_TripleMu_5_3_3_SQ;   //!
   TBranch        *b_L1_TripleMu_5_3p5_2p5;   //!
   TBranch        *b_L1_TripleMu_5_3p5_2p5_DoubleMu_5_2p5_OS_Mass_5to17;   //!
   TBranch        *b_L1_TripleMu_5_3p5_2p5_OQ_DoubleMu_5_2p5_OQ_OS_Mass_5to17;   //!
   TBranch        *b_L1_TripleMu_5_4_2p5_DoubleMu_5_2p5_OS_Mass_5to17;   //!
   TBranch        *b_L1_TripleMu_5_5_3;   //!
   TBranch        *b_L1_UnpairedBunchBptxMinus;   //!
   TBranch        *b_L1_UnpairedBunchBptxPlus;   //!
   TBranch        *b_L1_ZeroBias;   //!
   TBranch        *b_L1_ZeroBias_copy;   //!

   //declaration of tree_out only variables
   float h_gen_pt[2];
   float h_gen_eta[2];
   float h_gen_phi[2];

  //index to fatjets in the hh candidate
   unsigned int hh_fatjet_idx[2];

   bool  FatJet_Hmatch[100];
   int   FatJet_HgenIdx[100];
   float FatJet_HminDR[100];

   float hh_pt;
   float hh_eta;
   float hh_phi;
   float hh_mass;
   //
   float hh_gen_pt;
   float hh_gen_eta;
   float hh_gen_phi;
   float hh_gen_mass;

   //float h2_eta;
   //float h2_phi;

   Events(TTree *tree=0);
   virtual ~Events();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual void     CreateOutputTree();
   virtual void     ResetOutputTreeVariables();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   virtual void     DeleteHeap();
   virtual void     DeleteHeapFatJets();
   virtual void     DeleteHeapCorrT1METJet();
   virtual void     DeleteHeapSubJets();
   virtual void     DeleteHeapElectrons();
   virtual void     DeleteHeapFsrPhotons();
   virtual void     DeleteHeapGenVariables();
   virtual void     DeleteHeapPhotons();
   virtual void     DeleteHeapJets();
   virtual void     DeleteHeapMuons();
   virtual void     DeleteHeapTaus();
   virtual void     DeleteHeapIsoTracks();
   virtual void     DeleteHeapTriggerObject();
   virtual void     DeleteHeapSVandOtherPV();
   virtual void     DeleteHeapSoftActivityJet();
};

#endif

#ifdef Events_cxx
Events::Events(TTree *tree) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      std::cout<<"tree==0"<<"\n";
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/mnt/hadoop/store/group/phys_exotica/privateProduction/NANOAOD/v1/GluGluToHHTo4B_node_SM_TuneCP5_PSWeights_13TeV-madgraph-pythia8/v1_RunIIAutumn18MiniAOD-102X_v15-v1/200312_210339/0000/RunIIAutumn18NanoAODv5_BulkGravTohhTohWWhbb_1.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/mnt/hadoop/store/group/phys_exotica/privateProduction/NANOAOD/v1/GluGluToHHTo4B_node_SM_TuneCP5_PSWeights_13TeV-madgraph-pythia8/v1_RunIIAutumn18MiniAOD-102X_v15-v1/200312_210339/0000/RunIIAutumn18NanoAODv5_BulkGravTohhTohWWhbb_1.root");
      }
      f->GetObject("Events",tree);

   }
   std::cout<<"tree!=0"<<"\n";
   Init(tree);
}

Events::~Events()
{
  DeleteHeap();
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Events::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Events::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void Events::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   //std::cout << "Browse the content of the Chain " << fChain->Browse() << "\n";
   //std::cout << "Get number of trees " << fChain->GetNtrees()<<"\n";
   //std::cout << "Get number of Branches " << fChain->GetNbranches()<<"\n";
   //std::cout << "print list of Branches " << fChain->GetListOfBranches()<<"\n";
   fCurrent = -1;
   fChain->SetMakeClass(1);
   TRY_SET_BRANCH("run", &run, &b_run);
   TRY_SET_BRANCH("luminosityBlock", &luminosityBlock, &b_luminosityBlock);
   TRY_SET_BRANCH("event", &event, &b_event);
   TRY_SET_BRANCH("HTXS_Higgs_pt", &HTXS_Higgs_pt, &b_HTXS_Higgs_pt);
   TRY_SET_BRANCH("HTXS_Higgs_y", &HTXS_Higgs_y, &b_HTXS_Higgs_y);
   TRY_SET_BRANCH("HTXS_stage1_1_cat_pTjet25GeV", &HTXS_stage1_1_cat_pTjet25GeV, &b_HTXS_stage1_1_cat_pTjet25GeV);
   TRY_SET_BRANCH("HTXS_stage1_1_cat_pTjet30GeV", &HTXS_stage1_1_cat_pTjet30GeV, &b_HTXS_stage1_1_cat_pTjet30GeV);
   TRY_SET_BRANCH("HTXS_stage1_1_fine_cat_pTjet25GeV", &HTXS_stage1_1_fine_cat_pTjet25GeV, &b_HTXS_stage1_1_fine_cat_pTjet25GeV);
   TRY_SET_BRANCH("HTXS_stage1_1_fine_cat_pTjet30GeV", &HTXS_stage1_1_fine_cat_pTjet30GeV, &b_HTXS_stage1_1_fine_cat_pTjet30GeV);
   TRY_SET_BRANCH("HTXS_stage_0", &HTXS_stage_0, &b_HTXS_stage_0);
   TRY_SET_BRANCH("HTXS_stage_1_pTjet25", &HTXS_stage_1_pTjet25, &b_HTXS_stage_1_pTjet25);
   TRY_SET_BRANCH("HTXS_stage_1_pTjet30", &HTXS_stage_1_pTjet30, &b_HTXS_stage_1_pTjet30);
   TRY_SET_BRANCH("HTXS_njets25", &HTXS_njets25, &b_HTXS_njets25);
   TRY_SET_BRANCH("HTXS_njets30", &HTXS_njets30, &b_HTXS_njets30);
   TRY_SET_BRANCH("btagWeight_CSVV2", &btagWeight_CSVV2, &b_btagWeight_CSVV2);
   TRY_SET_BRANCH("btagWeight_DeepCSVB", &btagWeight_DeepCSVB, &b_btagWeight_DeepCSVB);
   TRY_SET_BRANCH("CaloMET_phi", &CaloMET_phi, &b_CaloMET_phi);
   TRY_SET_BRANCH("CaloMET_pt", &CaloMET_pt, &b_CaloMET_pt);
   TRY_SET_BRANCH("CaloMET_sumEt", &CaloMET_sumEt, &b_CaloMET_sumEt);
   TRY_SET_BRANCH("ChsMET_phi", &ChsMET_phi, &b_ChsMET_phi);
   TRY_SET_BRANCH("ChsMET_pt", &ChsMET_pt, &b_ChsMET_pt);
   TRY_SET_BRANCH("ChsMET_sumEt", &ChsMET_sumEt, &b_ChsMET_sumEt);
   TRY_SET_BRANCH("nCorrT1METJet", &nCorrT1METJet, &b_nCorrT1METJet);
   TRY_SET_BRANCH("CorrT1METJet_area", CorrT1METJet_area, &b_CorrT1METJet_area);
   TRY_SET_BRANCH("CorrT1METJet_eta", CorrT1METJet_eta, &b_CorrT1METJet_eta);
   TRY_SET_BRANCH("CorrT1METJet_muonSubtrFactor", CorrT1METJet_muonSubtrFactor, &b_CorrT1METJet_muonSubtrFactor);
   TRY_SET_BRANCH("CorrT1METJet_phi", CorrT1METJet_phi, &b_CorrT1METJet_phi);
   TRY_SET_BRANCH("CorrT1METJet_rawPt", CorrT1METJet_rawPt, &b_CorrT1METJet_rawPt);
   TRY_SET_BRANCH("nAK15Puppi", &nAK15Puppi ,&b_nAK15Puppi );
   TRY_SET_BRANCH("AK15Puppi_ParticleNetMD_probQCD", AK15Puppi_ParticleNetMD_probQCD,&b_AK15Puppi_ParticleNetMD_probQCD);
   TRY_SET_BRANCH("AK15Puppi_ParticleNetMD_probXbb", AK15Puppi_ParticleNetMD_probXbb,&b_AK15Puppi_ParticleNetMD_probXbb );
   TRY_SET_BRANCH("AK15Puppi_ParticleNetMD_probXcc", AK15Puppi_ParticleNetMD_probXcc,&b_AK15Puppi_ParticleNetMD_probXcc );
   TRY_SET_BRANCH("AK15Puppi_ParticleNetMD_probXqq", AK15Puppi_ParticleNetMD_probXqq,&b_AK15Puppi_ParticleNetMD_probXqq );
   TRY_SET_BRANCH("AK15Puppi_area", AK15Puppi_area,&b_AK15Puppi_area );              
   TRY_SET_BRANCH("AK15Puppi_btagCSVV2", AK15Puppi_btagCSVV2,&b_AK15Puppi_btagCSVV2 );          
   TRY_SET_BRANCH("AK15Puppi_btagDeepB", AK15Puppi_btagDeepB,&b_AK15Puppi_btagDeepB );           
   TRY_SET_BRANCH("AK15Puppi_btagJP", AK15Puppi_btagJP,&b_AK15Puppi_btagJP );             
   TRY_SET_BRANCH("AK15Puppi_eta", AK15Puppi_eta,&b_AK15Puppi_eta );              
   TRY_SET_BRANCH("AK15Puppi_mass", AK15Puppi_mass,&b_AK15Puppi_mass );               
   TRY_SET_BRANCH("AK15Puppi_msoftdrop", AK15Puppi_msoftdrop,&b_AK15Puppi_msoftdrop );           
   TRY_SET_BRANCH("AK15Puppi_phi", AK15Puppi_phi,&b_AK15Puppi_phi );               
   TRY_SET_BRANCH("AK15Puppi_pt", AK15Puppi_pt,&b_AK15Puppi_pt );                
   TRY_SET_BRANCH("AK15Puppi_rawFactor", AK15Puppi_rawFactor,&b_AK15Puppi_rawFactor );           
   TRY_SET_BRANCH("AK15Puppi_tau1", AK15Puppi_tau1,&b_AK15Puppi_tau1 );                
   TRY_SET_BRANCH("AK15Puppi_tau2", AK15Puppi_tau2,&b_AK15Puppi_tau2 );                
   TRY_SET_BRANCH("AK15Puppi_tau3", AK15Puppi_tau3,&b_AK15Puppi_tau3 );                
   TRY_SET_BRANCH("AK15Puppi_jetId", AK15Puppi_jetId,&b_AK15Puppi_jetId );               
   TRY_SET_BRANCH("AK15Puppi_nBHadrons", AK15Puppi_nBHadrons,&b_AK15Puppi_nBHadrons );          
   TRY_SET_BRANCH("AK15Puppi_nCHadrons", AK15Puppi_nCHadrons,&b_AK15Puppi_nCHadrons );          
   TRY_SET_BRANCH("AK15Puppi_nPFConstituents", AK15Puppi_nPFConstituents,&b_AK15Puppi_nPFConstituents );     
   TRY_SET_BRANCH("AK15Puppi_subJetIdx1", AK15Puppi_subJetIdx1,&b_AK15Puppi_subJetIdx1 );       
   TRY_SET_BRANCH("AK15Puppi_subJetIdx2", AK15Puppi_subJetIdx2,&b_AK15Puppi_subJetIdx2 );        
   TRY_SET_BRANCH("AK15Puppi_nPFCand", AK15Puppi_nPFCand,&b_AK15Puppi_nPFCand );
   TRY_SET_BRANCH("Rho_fixedGridRhoAll",&Rho_fixedGridRhoAll, &b_Rho_fixedGridRhoAll);
   TRY_SET_BRANCH("nSubJet", &nSubJet, &b_nSubJet);
   fChain->GetBranch("SubJet_area");
   TRY_SET_BRANCH("SubJet_area", SubJet_area, &b_SubJet_area);
   TRY_SET_BRANCH("SubJet_btagCSVV2", SubJet_btagCSVV2, &b_SubJet_btagCSVV2);
   TRY_SET_BRANCH("SubJet_btagDeepB", SubJet_btagDeepB, &b_SubJet_btagDeepB);
   TRY_SET_BRANCH("SubJet_eta", SubJet_eta, &b_SubJet_eta);
   TRY_SET_BRANCH("SubJet_mass", SubJet_mass, &b_SubJet_mass);
   TRY_SET_BRANCH("SubJet_phi", SubJet_phi, &b_SubJet_phi);
   TRY_SET_BRANCH("SubJet_pt", SubJet_pt, &b_SubJet_pt);
   TRY_SET_BRANCH("SubJet_rawFactor", SubJet_rawFactor, &b_SubJet_rawFactor);
   TRY_SET_BRANCH("SubJet_nBHadrons", SubJet_nBHadrons, &b_SubJet_nBHadrons);
   TRY_SET_BRANCH("SubJet_nCHadrons", SubJet_nCHadrons, &b_SubJet_nCHadrons);
   TRY_SET_BRANCH("nFatJet", &nFatJet, &b_nFatJet);
   TRY_SET_BRANCH("FatJet_ParticleNetMD_probQCDb", FatJet_ParticleNetMD_probQCDb, &b_FatJet_ParticleNetMD_probQCDb);
   TRY_SET_BRANCH("FatJet_ParticleNetMD_probQCDbb", FatJet_ParticleNetMD_probQCDbb, &b_FatJet_ParticleNetMD_probQCDbb);
   TRY_SET_BRANCH("FatJet_ParticleNetMD_probQCDc", FatJet_ParticleNetMD_probQCDc, &b_FatJet_ParticleNetMD_probQCDc);
   TRY_SET_BRANCH("FatJet_ParticleNetMD_probQCDcc", FatJet_ParticleNetMD_probQCDcc, &b_FatJet_ParticleNetMD_probQCDcc);
   TRY_SET_BRANCH("FatJet_ParticleNetMD_probQCDothers", FatJet_ParticleNetMD_probQCDothers, &b_FatJet_ParticleNetMD_probQCDothers);
   TRY_SET_BRANCH("FatJet_ParticleNetMD_probXbb", FatJet_ParticleNetMD_probXbb, &b_FatJet_ParticleNetMD_probXbb);
   TRY_SET_BRANCH("FatJet_ParticleNetMD_probXcc", FatJet_ParticleNetMD_probXcc, &b_FatJet_ParticleNetMD_probXcc);
   TRY_SET_BRANCH("FatJet_ParticleNetMD_probXqq", FatJet_ParticleNetMD_probXqq, &b_FatJet_ParticleNetMD_probXqq);
   TRY_SET_BRANCH("FatJet_particleNet_massCorr", FatJet_particleNet_massCorr, &b_FatJet_particleNet_massCorr);
   TRY_SET_BRANCH("FatJet_particleNetWithMass_HbbvsQCD", FatJet_particleNetWithMass_HbbvsQCD, &b_FatJet_particleNetWithMass_HbbvsQCD);
   TRY_SET_BRANCH("FatJet_particleNetWithMass_HccvsQCD", FatJet_particleNetWithMass_HccvsQCD, &b_FatJet_particleNetWithMass_HccvsQCD);
   TRY_SET_BRANCH("FatJet_particleNetWithMass_QCD", FatJet_particleNetWithMass_QCD, &b_FatJet_particleNetWithMass_QCD);
   TRY_SET_BRANCH("FatJet_particleNet_QCD", FatJet_particleNet_QCD, &b_FatJet_particleNet_QCD);
   TRY_SET_BRANCH("FatJet_particleNet_QCD0HF", FatJet_particleNet_QCD0HF, &b_FatJet_particleNet_QCD0HF);
   TRY_SET_BRANCH("FatJet_particleNet_QCD1HF", FatJet_particleNet_QCD1HF, &b_FatJet_particleNet_QCD1HF);
   TRY_SET_BRANCH("FatJet_particleNet_QCD2HF", FatJet_particleNet_QCD2HF, &b_FatJet_particleNet_QCD2HF);
   TRY_SET_BRANCH("FatJet_particleNet_XbbVsQCD", FatJet_particleNet_XbbVsQCD, &b_FatJet_particleNet_XbbVsQCD);
   TRY_SET_BRANCH("FatJet_particleNet_XccVsQCD", FatJet_particleNet_XccVsQCD, &b_FatJet_particleNet_XccVsQCD);
   TRY_SET_BRANCH("FatJet_particleNet_XggVsQCD", FatJet_particleNet_XggVsQCD, &b_FatJet_particleNet_XggVsQCD);
   TRY_SET_BRANCH("FatJet_particleNet_XqqVsQCD", FatJet_particleNet_XqqVsQCD, &b_FatJet_particleNet_XqqVsQCD);
   TRY_SET_BRANCH("FatJet_LSmsoftdrop", FatJet_LSmsoftdrop, &b_FatJet_LSmsoftdrop);
   TRY_SET_BRANCH("FatJet_LSn2b1", FatJet_LSn2b1, &b_FatJet_LSn2b1);
   TRY_SET_BRANCH("FatJet_LSn3b1", FatJet_LSn3b1, &b_FatJet_LSn3b1);
   TRY_SET_BRANCH("FatJet_LSpt", FatJet_LSpt, &b_FatJet_LSpt);
   TRY_SET_BRANCH("FatJet_LSrawmsoftdrop", FatJet_LSrawmsoftdrop, &b_FatJet_LSrawmsoftdrop);
   TRY_SET_BRANCH("FatJet_LSsubJet1btagDeepB", FatJet_LSsubJet1btagDeepB, &b_FatJet_LSsubJet1btagDeepB);
   TRY_SET_BRANCH("FatJet_LSsubJet2btagDeepB", FatJet_LSsubJet2btagDeepB, &b_FatJet_LSsubJet2btagDeepB);
   TRY_SET_BRANCH("FatJet_LStau1", FatJet_LStau1, &b_FatJet_LStau1);
   TRY_SET_BRANCH("FatJet_LStau2", FatJet_LStau2, &b_FatJet_LStau2);
   TRY_SET_BRANCH("FatJet_LStau3", FatJet_LStau3, &b_FatJet_LStau3);
   TRY_SET_BRANCH("FatJet_LStau4", FatJet_LStau4, &b_FatJet_LStau4);
   TRY_SET_BRANCH("FatJet_area", FatJet_area, &b_FatJet_area);
   TRY_SET_BRANCH("FatJet_btagDDBvL", FatJet_btagDDBvL, &b_FatJet_btagDDBvL);
   TRY_SET_BRANCH("FatJet_btagDDBvLV2", FatJet_btagDDBvLV2, &b_FatJet_btagDDBvLV2);
   TRY_SET_BRANCH("FatJet_btagDDCvBV2", FatJet_btagDDCvBV2, &b_FatJet_btagDDCvBV2);
   TRY_SET_BRANCH("FatJet_btagDDCvLV2", FatJet_btagDDCvLV2, &b_FatJet_btagDDCvLV2);
   TRY_SET_BRANCH("FatJet_btagHbb", FatJet_btagHbb, &b_FatJet_btagHbb);
   TRY_SET_BRANCH("FatJet_btagDeepB", FatJet_btagDeepB, &b_FatJet_btagDeepB);
   TRY_SET_BRANCH("FatJet_dRLep", FatJet_dRLep, &b_FatJet_dRLep);
   TRY_SET_BRANCH("FatJet_deepTagHbb", FatJet_deepTagHbb, &b_FatJet_deepTagHbb);
   TRY_SET_BRANCH("FatJet_deepTagHcc", FatJet_deepTagHcc, &b_FatJet_deepTagHcc);
   TRY_SET_BRANCH("FatJet_deepTagHqqqq", FatJet_deepTagHqqqq, &b_FatJet_deepTagHqqqq);
   TRY_SET_BRANCH("FatJet_deepTagMDHbb", FatJet_deepTagMDHbb, &b_FatJet_deepTagMDHbb);
   TRY_SET_BRANCH("FatJet_deepTagMDHcc", FatJet_deepTagMDHcc, &b_FatJet_deepTagMDHcc);
   TRY_SET_BRANCH("FatJet_deepTagMDHqqqq", FatJet_deepTagMDHqqqq, &b_FatJet_deepTagMDHqqqq);
   TRY_SET_BRANCH("FatJet_deepTagMDQCDbb", FatJet_deepTagMDQCDbb, &b_FatJet_deepTagMDQCDbb);
   TRY_SET_BRANCH("FatJet_deepTagMDQCDcc", FatJet_deepTagMDQCDcc, &b_FatJet_deepTagMDQCDcc);
   TRY_SET_BRANCH("FatJet_deepTagMDWcq", FatJet_deepTagMDWcq, &b_FatJet_deepTagMDWcq);
   TRY_SET_BRANCH("FatJet_deepTagMDWqq", FatJet_deepTagMDWqq, &b_FatJet_deepTagMDWqq);
   TRY_SET_BRANCH("FatJet_deepTagMDZbb", FatJet_deepTagMDZbb, &b_FatJet_deepTagMDZbb);
   TRY_SET_BRANCH("FatJet_deepTagMDZcc", FatJet_deepTagMDZcc, &b_FatJet_deepTagMDZcc);
   TRY_SET_BRANCH("FatJet_deepTagMDZqq", FatJet_deepTagMDZqq, &b_FatJet_deepTagMDZqq);
   TRY_SET_BRANCH("FatJet_deepTagQCDbb", FatJet_deepTagQCDbb, &b_FatJet_deepTagQCDbb);
   TRY_SET_BRANCH("FatJet_deepTagQCDcc", FatJet_deepTagQCDcc, &b_FatJet_deepTagQCDcc);
   TRY_SET_BRANCH("FatJet_deepTagWcq", FatJet_deepTagWcq, &b_FatJet_deepTagWcq);
   TRY_SET_BRANCH("FatJet_deepTagWqq", FatJet_deepTagWqq, &b_FatJet_deepTagWqq);
   TRY_SET_BRANCH("FatJet_deepTagZbb", FatJet_deepTagZbb, &b_FatJet_deepTagZbb);
   TRY_SET_BRANCH("FatJet_deepTagZcc", FatJet_deepTagZcc, &b_FatJet_deepTagZcc);
   TRY_SET_BRANCH("FatJet_deepTagZqq", FatJet_deepTagZqq, &b_FatJet_deepTagZqq);
   TRY_SET_BRANCH("FatJet_deepTagMD_WvsQCD", FatJet_deepTagMD_WvsQCD, &b_FatJet_deepTagMD_WvsQCD);
   TRY_SET_BRANCH("FatJet_deepTagMD_ZvsQCD", FatJet_deepTagMD_ZvsQCD, &b_FatJet_deepTagMD_ZvsQCD);
   TRY_SET_BRANCH("FatJet_deepTag_WvsQCD", FatJet_deepTag_WvsQCD, &b_FatJet_deepTag_WvsQCD);
   TRY_SET_BRANCH("FatJet_deepTag_ZvsQCD", FatJet_deepTag_ZvsQCD, &b_FatJet_deepTag_ZvsQCD);
   TRY_SET_BRANCH("FatJet_eta", FatJet_eta, &b_FatJet_eta);
   TRY_SET_BRANCH("FatJet_lsf3", FatJet_lsf3, &b_FatJet_lsf3);
   TRY_SET_BRANCH("FatJet_mass", FatJet_mass, &b_FatJet_mass);
   TRY_SET_BRANCH("FatJet_msoftdrop", FatJet_msoftdrop, &b_FatJet_msoftdrop);
   TRY_SET_BRANCH("FatJet_n2b1", FatJet_n2b1, &b_FatJet_n2b1);
   TRY_SET_BRANCH("FatJet_n3b1", FatJet_n3b1, &b_FatJet_n3b1);
   TRY_SET_BRANCH("FatJet_phi", FatJet_phi, &b_FatJet_phi);
   TRY_SET_BRANCH("FatJet_pt", FatJet_pt, &b_FatJet_pt);
   TRY_SET_BRANCH("FatJet_rawFactor", FatJet_rawFactor, &b_FatJet_rawFactor);
   TRY_SET_BRANCH("FatJet_rawmsoftdrop", FatJet_rawmsoftdrop, &b_FatJet_rawmsoftdrop);
   TRY_SET_BRANCH("FatJet_tau1", FatJet_tau1, &b_FatJet_tau1);
   TRY_SET_BRANCH("FatJet_tau2", FatJet_tau2, &b_FatJet_tau2);
   TRY_SET_BRANCH("FatJet_tau3", FatJet_tau3, &b_FatJet_tau3);
   TRY_SET_BRANCH("FatJet_tau4", FatJet_tau4, &b_FatJet_tau4);
   TRY_SET_BRANCH("FatJet_electronIdx3SJ", FatJet_electronIdx3SJ, &b_FatJet_electronIdx3SJ);
   TRY_SET_BRANCH("FatJet_idLep", FatJet_idLep, &b_FatJet_idLep);
   TRY_SET_BRANCH("FatJet_jetId", FatJet_jetId, &b_FatJet_jetId);
   TRY_SET_BRANCH("FatJet_muonIdx3SJ", FatJet_muonIdx3SJ, &b_FatJet_muonIdx3SJ);
   TRY_SET_BRANCH("FatJet_nBHadrons", FatJet_nBHadrons, &b_FatJet_nBHadrons);
   TRY_SET_BRANCH("FatJet_nCHadrons", FatJet_nCHadrons, &b_FatJet_nCHadrons);
   TRY_SET_BRANCH("FatJet_nConstituents", FatJet_nConstituents, &b_FatJet_nConstituents);
   TRY_SET_BRANCH("FatJet_subJetIdx1", FatJet_subJetIdx1, &b_FatJet_subJetIdx1);
   TRY_SET_BRANCH("FatJet_subJetIdx2", FatJet_subJetIdx2, &b_FatJet_subJetIdx2);
   TRY_SET_BRANCH("FatJet_genJetAK8Idx", FatJet_genJetAK8Idx, &b_FatJet_genJetAK8Idx);
   TRY_SET_BRANCH("nElectron", &nElectron, &b_nElectron);
   TRY_SET_BRANCH("Electron_deltaEtaSC", Electron_deltaEtaSC, &b_Electron_deltaEtaSC);
   TRY_SET_BRANCH("Electron_dr03EcalRecHitSumEt", Electron_dr03EcalRecHitSumEt, &b_Electron_dr03EcalRecHitSumEt);
   TRY_SET_BRANCH("Electron_dr03HcalDepth1TowerSumEt", Electron_dr03HcalDepth1TowerSumEt, &b_Electron_dr03HcalDepth1TowerSumEt);
   TRY_SET_BRANCH("Electron_dr03TkSumPt", Electron_dr03TkSumPt, &b_Electron_dr03TkSumPt);
   TRY_SET_BRANCH("Electron_dr03TkSumPtHEEP", Electron_dr03TkSumPtHEEP, &b_Electron_dr03TkSumPtHEEP);
   TRY_SET_BRANCH("Electron_dxy", Electron_dxy, &b_Electron_dxy);
   TRY_SET_BRANCH("Electron_dxyErr", Electron_dxyErr, &b_Electron_dxyErr);
   TRY_SET_BRANCH("Electron_dz", Electron_dz, &b_Electron_dz);
   TRY_SET_BRANCH("Electron_dzErr", Electron_dzErr, &b_Electron_dzErr);
   TRY_SET_BRANCH("Electron_eCorr", Electron_eCorr, &b_Electron_eCorr);
   TRY_SET_BRANCH("Electron_eInvMinusPInv", Electron_eInvMinusPInv, &b_Electron_eInvMinusPInv);
   TRY_SET_BRANCH("Electron_energyErr", Electron_energyErr, &b_Electron_energyErr);
   TRY_SET_BRANCH("Electron_eta", Electron_eta, &b_Electron_eta);
   TRY_SET_BRANCH("Electron_hoe", Electron_hoe, &b_Electron_hoe);
   TRY_SET_BRANCH("Electron_ip3d", Electron_ip3d, &b_Electron_ip3d);
   TRY_SET_BRANCH("Electron_jetPtRelv2", Electron_jetPtRelv2, &b_Electron_jetPtRelv2);
   TRY_SET_BRANCH("Electron_jetRelIso", Electron_jetRelIso, &b_Electron_jetRelIso);
   TRY_SET_BRANCH("Electron_mass", Electron_mass, &b_Electron_mass);
   TRY_SET_BRANCH("Electron_miniPFRelIso_all", Electron_miniPFRelIso_all, &b_Electron_miniPFRelIso_all);
   TRY_SET_BRANCH("Electron_miniPFRelIso_chg", Electron_miniPFRelIso_chg, &b_Electron_miniPFRelIso_chg);
   TRY_SET_BRANCH("Electron_mvaFall17V1Iso", Electron_mvaFall17V1Iso, &b_Electron_mvaFall17V1Iso);
   TRY_SET_BRANCH("Electron_mvaFall17V1noIso", Electron_mvaFall17V1noIso, &b_Electron_mvaFall17V1noIso);
   TRY_SET_BRANCH("Electron_mvaFall17V2Iso", Electron_mvaFall17V2Iso, &b_Electron_mvaFall17V2Iso);
   TRY_SET_BRANCH("Electron_mvaFall17V2noIso", Electron_mvaFall17V2noIso, &b_Electron_mvaFall17V2noIso);
   TRY_SET_BRANCH("Electron_pfRelIso03_all", Electron_pfRelIso03_all, &b_Electron_pfRelIso03_all);
   TRY_SET_BRANCH("Electron_pfRelIso03_chg", Electron_pfRelIso03_chg, &b_Electron_pfRelIso03_chg);
   TRY_SET_BRANCH("Electron_phi", Electron_phi, &b_Electron_phi);
   TRY_SET_BRANCH("Electron_pt", Electron_pt, &b_Electron_pt);
   TRY_SET_BRANCH("Electron_r9", Electron_r9, &b_Electron_r9);
   TRY_SET_BRANCH("Electron_sieie", Electron_sieie, &b_Electron_sieie);
   TRY_SET_BRANCH("Electron_sip3d", Electron_sip3d, &b_Electron_sip3d);
   TRY_SET_BRANCH("Electron_mvaTTH", Electron_mvaTTH, &b_Electron_mvaTTH);
   TRY_SET_BRANCH("Electron_charge", Electron_charge, &b_Electron_charge);
   TRY_SET_BRANCH("Electron_cutBased", Electron_cutBased, &b_Electron_cutBased);
   TRY_SET_BRANCH("Electron_cutBased_Fall17_V1", Electron_cutBased_Fall17_V1, &b_Electron_cutBased_Fall17_V1);
   TRY_SET_BRANCH("Electron_jetIdx", Electron_jetIdx, &b_Electron_jetIdx);
   TRY_SET_BRANCH("Electron_pdgId", Electron_pdgId, &b_Electron_pdgId);
   TRY_SET_BRANCH("Electron_photonIdx", Electron_photonIdx, &b_Electron_photonIdx);
   TRY_SET_BRANCH("Electron_tightCharge", Electron_tightCharge, &b_Electron_tightCharge);
   TRY_SET_BRANCH("Electron_vidNestedWPBitmap", Electron_vidNestedWPBitmap, &b_Electron_vidNestedWPBitmap);
   TRY_SET_BRANCH("Electron_vidNestedWPBitmapHEEP", Electron_vidNestedWPBitmapHEEP, &b_Electron_vidNestedWPBitmapHEEP);
   TRY_SET_BRANCH("Electron_convVeto", Electron_convVeto, &b_Electron_convVeto);
   TRY_SET_BRANCH("Electron_cutBased_HEEP", Electron_cutBased_HEEP, &b_Electron_cutBased_HEEP);
   TRY_SET_BRANCH("Electron_isPFcand", Electron_isPFcand, &b_Electron_isPFcand);
   TRY_SET_BRANCH("Electron_lostHits", Electron_lostHits, &b_Electron_lostHits);
   TRY_SET_BRANCH("Electron_mvaIso_WP80", Electron_mvaIso_WP80, &b_Electron_mvaIso_WP80);
   TRY_SET_BRANCH("Electron_mvaIso_WP90", Electron_mvaIso_WP90, &b_Electron_mvaIso_WP90);
   TRY_SET_BRANCH("Electron_mvaIso", Electron_mvaIso, &b_Electron_mvaIso);
   TRY_SET_BRANCH("Electron_mvaFall17V1noIso_WP80", Electron_mvaFall17V1noIso_WP80, &b_Electron_mvaFall17V1noIso_WP80);
   TRY_SET_BRANCH("Electron_mvaFall17V1noIso_WPL", Electron_mvaFall17V1noIso_WPL, &b_Electron_mvaFall17V1noIso_WPL);
   TRY_SET_BRANCH("Electron_mvaNoIso_WP80", Electron_mvaNoIso_WP80, &b_Electron_mvaNoIso_WP80);
   TRY_SET_BRANCH("Electron_mvaNoIso_WP90", Electron_mvaNoIso_WP90, &b_Electron_mvaNoIso_WP90);
   TRY_SET_BRANCH("Electron_mvaFall17V2Iso_WPL", Electron_mvaFall17V2Iso_WPL, &b_Electron_mvaFall17V2Iso_WPL);
   TRY_SET_BRANCH("Electron_mvaFall17V2noIso_WP80", Electron_mvaFall17V2noIso_WP80, &b_Electron_mvaFall17V2noIso_WP80);
   TRY_SET_BRANCH("Electron_mvaFall17V2noIso_WP90", Electron_mvaFall17V2noIso_WP90, &b_Electron_mvaFall17V2noIso_WP90);
   TRY_SET_BRANCH("Electron_mvaFall17V2noIso_WPL", Electron_mvaFall17V2noIso_WPL, &b_Electron_mvaFall17V2noIso_WPL);
   TRY_SET_BRANCH("Electron_seedGain", Electron_seedGain, &b_Electron_seedGain);
   TRY_SET_BRANCH("nFsrPhoton", &nFsrPhoton, &b_nFsrPhoton);
   TRY_SET_BRANCH("FsrPhoton_dROverEt2", FsrPhoton_dROverEt2, &b_FsrPhoton_dROverEt2);
   TRY_SET_BRANCH("FsrPhoton_eta", FsrPhoton_eta, &b_FsrPhoton_eta);
   TRY_SET_BRANCH("FsrPhoton_phi", FsrPhoton_phi, &b_FsrPhoton_phi);
   TRY_SET_BRANCH("FsrPhoton_pt", FsrPhoton_pt, &b_FsrPhoton_pt);
   TRY_SET_BRANCH("FsrPhoton_relIso03", FsrPhoton_relIso03, &b_FsrPhoton_relIso03);
   TRY_SET_BRANCH("FsrPhoton_muonIdx", FsrPhoton_muonIdx, &b_FsrPhoton_muonIdx);
   TRY_SET_BRANCH("nGenJetAK8", &nGenJetAK8, &b_nGenJetAK8);
   TRY_SET_BRANCH("GenJetAK8_eta", GenJetAK8_eta, &b_GenJetAK8_eta);
   TRY_SET_BRANCH("GenJetAK8_mass", GenJetAK8_mass, &b_GenJetAK8_mass);
   TRY_SET_BRANCH("GenJetAK8_phi", GenJetAK8_phi, &b_GenJetAK8_phi);
   TRY_SET_BRANCH("GenJetAK8_pt", GenJetAK8_pt, &b_GenJetAK8_pt);
   TRY_SET_BRANCH("nGenJet", &nGenJet, &b_nGenJet);
   TRY_SET_BRANCH("GenJet_eta", GenJet_eta, &b_GenJet_eta);
   TRY_SET_BRANCH("GenJet_mass", GenJet_mass, &b_GenJet_mass);
   TRY_SET_BRANCH("GenJet_phi", GenJet_phi, &b_GenJet_phi);
   TRY_SET_BRANCH("GenJet_pt", GenJet_pt, &b_GenJet_pt);
   TRY_SET_BRANCH("nGenPart", &nGenPart, &b_nGenPart);
   TRY_SET_BRANCH("GenPart_eta", GenPart_eta, &b_GenPart_eta);
   TRY_SET_BRANCH("GenPart_mass", GenPart_mass, &b_GenPart_mass);
   TRY_SET_BRANCH("GenPart_phi", GenPart_phi, &b_GenPart_phi);
   TRY_SET_BRANCH("GenPart_pt", GenPart_pt, &b_GenPart_pt);
   TRY_SET_BRANCH("GenPart_genPartIdxMother", GenPart_genPartIdxMother, &b_GenPart_genPartIdxMother);
   TRY_SET_BRANCH("GenPart_pdgId", GenPart_pdgId, &b_GenPart_pdgId);
   TRY_SET_BRANCH("GenPart_status", GenPart_status, &b_GenPart_status);
   TRY_SET_BRANCH("GenPart_statusFlags", GenPart_statusFlags, &b_GenPart_statusFlags);
   TRY_SET_BRANCH("nSubGenJetAK8", &nSubGenJetAK8, &b_nSubGenJetAK8);
   TRY_SET_BRANCH("SubGenJetAK8_eta", SubGenJetAK8_eta, &b_SubGenJetAK8_eta);
   TRY_SET_BRANCH("SubGenJetAK8_mass", SubGenJetAK8_mass, &b_SubGenJetAK8_mass);
   TRY_SET_BRANCH("SubGenJetAK8_phi", SubGenJetAK8_phi, &b_SubGenJetAK8_phi);
   TRY_SET_BRANCH("SubGenJetAK8_pt", SubGenJetAK8_pt, &b_SubGenJetAK8_pt);
   TRY_SET_BRANCH("Generator_binvar", &Generator_binvar, &b_Generator_binvar);
   TRY_SET_BRANCH("Generator_scalePDF", &Generator_scalePDF, &b_Generator_scalePDF);
   TRY_SET_BRANCH("Generator_weight", &Generator_weight, &b_Generator_weight);
   TRY_SET_BRANCH("Generator_x1", &Generator_x1, &b_Generator_x1);
   TRY_SET_BRANCH("Generator_x2", &Generator_x2, &b_Generator_x2);
   TRY_SET_BRANCH("Generator_xpdf1", &Generator_xpdf1, &b_Generator_xpdf1);
   TRY_SET_BRANCH("Generator_xpdf2", &Generator_xpdf2, &b_Generator_xpdf2);
   TRY_SET_BRANCH("Generator_id1", &Generator_id1, &b_Generator_id1);
   TRY_SET_BRANCH("Generator_id2", &Generator_id2, &b_Generator_id2);
   TRY_SET_BRANCH("nGenVisTau", &nGenVisTau, &b_nGenVisTau);
   TRY_SET_BRANCH("GenVisTau_eta", GenVisTau_eta, &b_GenVisTau_eta);
   TRY_SET_BRANCH("GenVisTau_mass", GenVisTau_mass, &b_GenVisTau_mass);
   TRY_SET_BRANCH("GenVisTau_phi", GenVisTau_phi, &b_GenVisTau_phi);
   TRY_SET_BRANCH("GenVisTau_pt", GenVisTau_pt, &b_GenVisTau_pt);
   TRY_SET_BRANCH("GenVisTau_charge", GenVisTau_charge, &b_GenVisTau_charge);
   TRY_SET_BRANCH("GenVisTau_genPartIdxMother", GenVisTau_genPartIdxMother, &b_GenVisTau_genPartIdxMother);
   TRY_SET_BRANCH("GenVisTau_status", GenVisTau_status, &b_GenVisTau_status);
   TRY_SET_BRANCH("genWeight", &genWeight, &b_genWeight);
   TRY_SET_BRANCH("LHEWeight_originalXWGTUP", &LHEWeight_originalXWGTUP, &b_LHEWeight_originalXWGTUP);
   TRY_SET_BRANCH("nLHEPdfWeight", &nLHEPdfWeight, &b_nLHEPdfWeight);
   TRY_SET_BRANCH("LHEPdfWeight", LHEPdfWeight, &b_LHEPdfWeight);
   TRY_SET_BRANCH("nLHEReweightingWeight", &nLHEReweightingWeight, &b_nLHEReweightingWeight);
   TRY_SET_BRANCH("LHEReweightingWeight", &LHEReweightingWeight, &b_LHEReweightingWeight);
   TRY_SET_BRANCH("nLHEScaleWeight", &nLHEScaleWeight, &b_nLHEScaleWeight);
   TRY_SET_BRANCH("LHEScaleWeight", LHEScaleWeight, &b_LHEScaleWeight);
   TRY_SET_BRANCH("nPSWeight", &nPSWeight, &b_nPSWeight);
   TRY_SET_BRANCH("PSWeight", PSWeight, &b_PSWeight);
   TRY_SET_BRANCH("nIsoTrack", &nIsoTrack, &b_nIsoTrack);
   TRY_SET_BRANCH("IsoTrack_dxy", IsoTrack_dxy, &b_IsoTrack_dxy);
   TRY_SET_BRANCH("IsoTrack_dz", IsoTrack_dz, &b_IsoTrack_dz);
   TRY_SET_BRANCH("IsoTrack_eta", IsoTrack_eta, &b_IsoTrack_eta);
   TRY_SET_BRANCH("IsoTrack_pfRelIso03_all", IsoTrack_pfRelIso03_all, &b_IsoTrack_pfRelIso03_all);
   TRY_SET_BRANCH("IsoTrack_pfRelIso03_chg", IsoTrack_pfRelIso03_chg, &b_IsoTrack_pfRelIso03_chg);
   TRY_SET_BRANCH("IsoTrack_phi", IsoTrack_phi, &b_IsoTrack_phi);
   TRY_SET_BRANCH("IsoTrack_pt", IsoTrack_pt, &b_IsoTrack_pt);
   TRY_SET_BRANCH("IsoTrack_miniPFRelIso_all", IsoTrack_miniPFRelIso_all, &b_IsoTrack_miniPFRelIso_all);
   TRY_SET_BRANCH("IsoTrack_miniPFRelIso_chg", IsoTrack_miniPFRelIso_chg, &b_IsoTrack_miniPFRelIso_chg);
   TRY_SET_BRANCH("IsoTrack_fromPV", IsoTrack_fromPV, &b_IsoTrack_fromPV);
   TRY_SET_BRANCH("IsoTrack_pdgId", IsoTrack_pdgId, &b_IsoTrack_pdgId);
   TRY_SET_BRANCH("IsoTrack_isHighPurityTrack", IsoTrack_isHighPurityTrack, &b_IsoTrack_isHighPurityTrack);
   TRY_SET_BRANCH("IsoTrack_isPFcand", IsoTrack_isPFcand, &b_IsoTrack_isPFcand);
   TRY_SET_BRANCH("IsoTrack_isFromLostTrack", IsoTrack_isFromLostTrack, &b_IsoTrack_isFromLostTrack);
   TRY_SET_BRANCH("nJet", &nJet, &b_nJet);
   TRY_SET_BRANCH("Jet_area", Jet_area, &b_Jet_area);
   TRY_SET_BRANCH("Jet_btagCMVA", Jet_btagCMVA, &b_Jet_btagCMVA);
   TRY_SET_BRANCH("Jet_btagCSVV2", Jet_btagCSVV2, &b_Jet_btagCSVV2);
   TRY_SET_BRANCH("Jet_btagDeepB", Jet_btagDeepB, &b_Jet_btagDeepB);
   TRY_SET_BRANCH("Jet_btagDeepC", Jet_btagDeepC, &b_Jet_btagDeepC);
   TRY_SET_BRANCH("Jet_btagDeepFlavB", Jet_btagDeepFlavB, &b_Jet_btagDeepFlavB);
   TRY_SET_BRANCH("Jet_btagDeepFlavCvB", Jet_btagDeepFlavCvB, &b_Jet_btagDeepFlavCvB);
   TRY_SET_BRANCH("Jet_btagDeepFlavCvL", Jet_btagDeepFlavCvL, &b_Jet_btagDeepFlavCvL);
   TRY_SET_BRANCH("Jet_btagDeepFlavQG", Jet_btagDeepFlavQG, &b_Jet_btagDeepFlavQG);
   TRY_SET_BRANCH("Jet_PNetRegPtRawRes",Jet_PNetRegPtRawRes, &b_Jet_PNetRegPtRawRes);
   TRY_SET_BRANCH("Jet_PNetRegPtRawCorr",Jet_PNetRegPtRawCorr, &b_Jet_PNetRegPtRawCorr);
   TRY_SET_BRANCH("Jet_btagPNetB", Jet_btagPNetB, &b_Jet_btagPNetB);
   TRY_SET_BRANCH("Jet_btagPNetCvB", Jet_btagPNetCvB, &b_Jet_btagPNetCvB);
   TRY_SET_BRANCH("Jet_btagPNetCvL", Jet_btagPNetCvL, &b_Jet_btagPNetCvL);
   TRY_SET_BRANCH("Jet_btagPNetQvG", Jet_btagPNetQvG, &b_Jet_btagPNetQvG);
   TRY_SET_BRANCH("Jet_btagPNetTauVJet", Jet_btagPNetTauVJet, &b_Jet_btagPNetTauVJet);
   TRY_SET_BRANCH("Jet_btagRobustParTAK4B", Jet_btagRobustParTAK4B, &b_Jet_btagRobustParTAK4B);
   TRY_SET_BRANCH("Jet_btagRobustParTAK4CvB", Jet_btagRobustParTAK4CvB, &b_Jet_btagRobustParTAK4CvB);
   TRY_SET_BRANCH("Jet_btagRobustParTAK4CvL", Jet_btagRobustParTAK4CvL, &b_Jet_btagRobustParTAK4CvL);
   TRY_SET_BRANCH("Jet_btagRobustParTAK4QG", Jet_btagRobustParTAK4QG, &b_Jet_btagRobustParTAK4QG);
   TRY_SET_BRANCH("Jet_chEmEF", Jet_chEmEF, &b_Jet_chEmEF);
   TRY_SET_BRANCH("Jet_chHEF", Jet_chHEF, &b_Jet_chHEF);
   TRY_SET_BRANCH("Jet_eta", Jet_eta, &b_Jet_eta);
   TRY_SET_BRANCH("Jet_jercCHF", Jet_jercCHF, &b_Jet_jercCHF);
   TRY_SET_BRANCH("Jet_jercCHPUF", Jet_jercCHPUF, &b_Jet_jercCHPUF);
   TRY_SET_BRANCH("Jet_mass", Jet_mass, &b_Jet_mass);
   TRY_SET_BRANCH("Jet_muEF", Jet_muEF, &b_Jet_muEF);
   TRY_SET_BRANCH("Jet_muonSubtrFactor", Jet_muonSubtrFactor, &b_Jet_muonSubtrFactor);
   TRY_SET_BRANCH("Jet_neEmEF", Jet_neEmEF, &b_Jet_neEmEF);
   TRY_SET_BRANCH("Jet_neHEF", Jet_neHEF, &b_Jet_neHEF);
   TRY_SET_BRANCH("Jet_phi", Jet_phi, &b_Jet_phi);
   TRY_SET_BRANCH("Jet_pt", Jet_pt, &b_Jet_pt);
   TRY_SET_BRANCH("Jet_qgl", Jet_qgl, &b_Jet_qgl);
   TRY_SET_BRANCH("Jet_rawFactor", Jet_rawFactor, &b_Jet_rawFactor);
   TRY_SET_BRANCH("Jet_bRegCorr", Jet_bRegCorr, &b_Jet_bRegCorr);
   TRY_SET_BRANCH("Jet_bRegRes", Jet_bRegRes, &b_Jet_bRegRes);
   TRY_SET_BRANCH("Jet_electronIdx1", Jet_electronIdx1, &b_Jet_electronIdx1);
   TRY_SET_BRANCH("Jet_electronIdx2", Jet_electronIdx2, &b_Jet_electronIdx2);
   TRY_SET_BRANCH("Jet_jetId", Jet_jetId, &b_Jet_jetId);
   TRY_SET_BRANCH("Jet_muonIdx1", Jet_muonIdx1, &b_Jet_muonIdx1);
   TRY_SET_BRANCH("Jet_muonIdx2", Jet_muonIdx2, &b_Jet_muonIdx2);
   TRY_SET_BRANCH("Jet_nConstituents", Jet_nConstituents, &b_Jet_nConstituents);
   TRY_SET_BRANCH("Jet_nElectrons", Jet_nElectrons, &b_Jet_nElectrons);
   TRY_SET_BRANCH("Jet_nMuons", Jet_nMuons, &b_Jet_nMuons);
   TRY_SET_BRANCH("Jet_puId", Jet_puId, &b_Jet_puId);
   TRY_SET_BRANCH("LHE_HT", &LHE_HT, &b_LHE_HT);
   TRY_SET_BRANCH("LHE_HTIncoming", &LHE_HTIncoming, &b_LHE_HTIncoming);
   TRY_SET_BRANCH("LHE_Vpt", &LHE_Vpt, &b_LHE_Vpt);
   TRY_SET_BRANCH("LHE_Njets", &LHE_Njets, &b_LHE_Njets);
   TRY_SET_BRANCH("LHE_Nb", &LHE_Nb, &b_LHE_Nb);
   TRY_SET_BRANCH("LHE_Nc", &LHE_Nc, &b_LHE_Nc);
   TRY_SET_BRANCH("LHE_Nuds", &LHE_Nuds, &b_LHE_Nuds);
   TRY_SET_BRANCH("LHE_Nglu", &LHE_Nglu, &b_LHE_Nglu);
   TRY_SET_BRANCH("LHE_NpNLO", &LHE_NpNLO, &b_LHE_NpNLO);
   TRY_SET_BRANCH("LHE_NpLO", &LHE_NpLO, &b_LHE_NpLO);
   TRY_SET_BRANCH("nLHEPart", &nLHEPart, &b_nLHEPart);
   TRY_SET_BRANCH("LHEPart_pt", LHEPart_pt, &b_LHEPart_pt);
   TRY_SET_BRANCH("LHEPart_eta", LHEPart_eta, &b_LHEPart_eta);
   TRY_SET_BRANCH("LHEPart_phi", LHEPart_phi, &b_LHEPart_phi);
   TRY_SET_BRANCH("LHEPart_mass", LHEPart_mass, &b_LHEPart_mass);
   TRY_SET_BRANCH("LHEPart_pdgId", LHEPart_pdgId, &b_LHEPart_pdgId);
   TRY_SET_BRANCH("GenMET_phi", &GenMET_phi, &b_GenMET_phi);
   TRY_SET_BRANCH("GenMET_pt", &GenMET_pt, &b_GenMET_pt);
   TRY_SET_BRANCH("MET_MetUnclustEnUpDeltaX", &MET_MetUnclustEnUpDeltaX, &b_MET_MetUnclustEnUpDeltaX);
   TRY_SET_BRANCH("MET_MetUnclustEnUpDeltaY", &MET_MetUnclustEnUpDeltaY, &b_MET_MetUnclustEnUpDeltaY);
   TRY_SET_BRANCH("MET_covXX", &MET_covXX, &b_MET_covXX);
   TRY_SET_BRANCH("MET_covXY", &MET_covXY, &b_MET_covXY);
   TRY_SET_BRANCH("MET_covYY", &MET_covYY, &b_MET_covYY);
   TRY_SET_BRANCH("MET_phi", &MET_phi, &b_MET_phi);
   TRY_SET_BRANCH("MET_pt", &MET_pt, &b_MET_pt);
   TRY_SET_BRANCH("MET_significance", &MET_significance, &b_MET_significance);
   TRY_SET_BRANCH("MET_sumEt", &MET_sumEt, &b_MET_sumEt);
   TRY_SET_BRANCH("nMuon", &nMuon, &b_nMuon);
   TRY_SET_BRANCH("Muon_dxy", Muon_dxy, &b_Muon_dxy);
   TRY_SET_BRANCH("Muon_dxyErr", Muon_dxyErr, &b_Muon_dxyErr);
   TRY_SET_BRANCH("Muon_dz", Muon_dz, &b_Muon_dz);
   TRY_SET_BRANCH("Muon_dzErr", Muon_dzErr, &b_Muon_dzErr);
   TRY_SET_BRANCH("Muon_eta", Muon_eta, &b_Muon_eta);
   TRY_SET_BRANCH("Muon_ip3d", Muon_ip3d, &b_Muon_ip3d);
   TRY_SET_BRANCH("Muon_jetPtRelv2", Muon_jetPtRelv2, &b_Muon_jetPtRelv2);
   TRY_SET_BRANCH("Muon_jetRelIso", Muon_jetRelIso, &b_Muon_jetRelIso);
   TRY_SET_BRANCH("Muon_mass", Muon_mass, &b_Muon_mass);
   TRY_SET_BRANCH("Muon_miniPFRelIso_all", Muon_miniPFRelIso_all, &b_Muon_miniPFRelIso_all);
   TRY_SET_BRANCH("Muon_miniPFRelIso_chg", Muon_miniPFRelIso_chg, &b_Muon_miniPFRelIso_chg);
   TRY_SET_BRANCH("Muon_pfRelIso03_all", Muon_pfRelIso03_all, &b_Muon_pfRelIso03_all);
   TRY_SET_BRANCH("Muon_pfRelIso03_chg", Muon_pfRelIso03_chg, &b_Muon_pfRelIso03_chg);
   TRY_SET_BRANCH("Muon_pfRelIso04_all", Muon_pfRelIso04_all, &b_Muon_pfRelIso04_all);
   TRY_SET_BRANCH("Muon_phi", Muon_phi, &b_Muon_phi);
   TRY_SET_BRANCH("Muon_pt", Muon_pt, &b_Muon_pt);
   TRY_SET_BRANCH("Muon_ptErr", Muon_ptErr, &b_Muon_ptErr);
   TRY_SET_BRANCH("Muon_segmentComp", Muon_segmentComp, &b_Muon_segmentComp);
   TRY_SET_BRANCH("Muon_sip3d", Muon_sip3d, &b_Muon_sip3d);
   TRY_SET_BRANCH("Muon_softMva", Muon_softMva, &b_Muon_softMva);
   TRY_SET_BRANCH("Muon_tkRelIso", Muon_tkRelIso, &b_Muon_tkRelIso);
   TRY_SET_BRANCH("Muon_tunepRelPt", Muon_tunepRelPt, &b_Muon_tunepRelPt);
   TRY_SET_BRANCH("Muon_mvaLowPt", Muon_mvaLowPt, &b_Muon_mvaLowPt);
   TRY_SET_BRANCH("Muon_mvaTTH", Muon_mvaTTH, &b_Muon_mvaTTH);
   TRY_SET_BRANCH("Muon_charge", Muon_charge, &b_Muon_charge);
   TRY_SET_BRANCH("Muon_jetIdx", Muon_jetIdx, &b_Muon_jetIdx);
   TRY_SET_BRANCH("Muon_nStations", Muon_nStations, &b_Muon_nStations);
   TRY_SET_BRANCH("Muon_nTrackerLayers", Muon_nTrackerLayers, &b_Muon_nTrackerLayers);
   TRY_SET_BRANCH("Muon_pdgId", Muon_pdgId, &b_Muon_pdgId);
   TRY_SET_BRANCH("Muon_tightCharge", Muon_tightCharge, &b_Muon_tightCharge);
   TRY_SET_BRANCH("Muon_fsrPhotonIdx", Muon_fsrPhotonIdx, &b_Muon_fsrPhotonIdx);
   TRY_SET_BRANCH("Muon_highPtId", Muon_highPtId, &b_Muon_highPtId);
   TRY_SET_BRANCH("Muon_inTimeMuon", Muon_inTimeMuon, &b_Muon_inTimeMuon);
   TRY_SET_BRANCH("Muon_isGlobal", Muon_isGlobal, &b_Muon_isGlobal);
   TRY_SET_BRANCH("Muon_isPFcand", Muon_isPFcand, &b_Muon_isPFcand);
   TRY_SET_BRANCH("Muon_isTracker", Muon_isTracker, &b_Muon_isTracker);
   TRY_SET_BRANCH("Muon_looseId", Muon_looseId, &b_Muon_looseId);
   TRY_SET_BRANCH("Muon_mediumId", Muon_mediumId, &b_Muon_mediumId);
   TRY_SET_BRANCH("Muon_mediumPromptId", Muon_mediumPromptId, &b_Muon_mediumPromptId);
   TRY_SET_BRANCH("Muon_miniIsoId", Muon_miniIsoId, &b_Muon_miniIsoId);
   TRY_SET_BRANCH("Muon_multiIsoId", Muon_multiIsoId, &b_Muon_multiIsoId);
   TRY_SET_BRANCH("Muon_mvaMuID", Muon_mvaMuID, &b_Muon_mvaMuID);
   TRY_SET_BRANCH("Muon_pfIsoId", Muon_pfIsoId, &b_Muon_pfIsoId);
   TRY_SET_BRANCH("Muon_softId", Muon_softId, &b_Muon_softId);
   TRY_SET_BRANCH("Muon_softMvaId", Muon_softMvaId, &b_Muon_softMvaId);
   TRY_SET_BRANCH("Muon_tightId", Muon_tightId, &b_Muon_tightId);
   TRY_SET_BRANCH("Muon_tkIsoId", Muon_tkIsoId, &b_Muon_tkIsoId);
   TRY_SET_BRANCH("Muon_triggerIdLoose", Muon_triggerIdLoose, &b_Muon_triggerIdLoose);
   TRY_SET_BRANCH("nPhoton", &nPhoton, &b_nPhoton);
   TRY_SET_BRANCH("Photon_eCorr", Photon_eCorr, &b_Photon_eCorr);
   TRY_SET_BRANCH("Photon_energyErr", Photon_energyErr, &b_Photon_energyErr);
   TRY_SET_BRANCH("Photon_energyRaw", Photon_energyRaw, &b_Photon_energyRaw);
   TRY_SET_BRANCH("Photon_eta", Photon_eta, &b_Photon_eta);
   TRY_SET_BRANCH("Photon_hoe", Photon_hoe, &b_Photon_hoe);
   TRY_SET_BRANCH("Photon_mass", Photon_mass, &b_Photon_mass);
   TRY_SET_BRANCH("Photon_mvaID", Photon_mvaID, &b_Photon_mvaID);
   TRY_SET_BRANCH("Photon_mvaIDV1", Photon_mvaIDV1, &b_Photon_mvaIDV1);
   TRY_SET_BRANCH("Photon_pfRelIso03_all_quadratic", Photon_pfRelIso03_all_quadratic, &b_Photon_pfRelIso03_all_quadratic);
   TRY_SET_BRANCH("Photon_pfRelIso03_chg_quadratic", Photon_pfRelIso03_chg_quadratic, &b_Photon_pfRelIso03_chg_quadratic);
   TRY_SET_BRANCH("Photon_pfPhoIso03", Photon_pfPhoIso03, &b_Photon_pfPhoIso03);
   TRY_SET_BRANCH("Photon_pfChargedIso", Photon_pfChargedIso, &b_Photon_pfChargedIso);
   TRY_SET_BRANCH("Photon_pfChargedIsoPFPV", Photon_pfChargedIsoPFPV, &b_Photon_pfChargedIsoPFPV);
   TRY_SET_BRANCH("Photon_pfChargedIsoWorstVtx", Photon_pfChargedIsoWorstVtx, &b_Photon_pfChargedIsoWorstVtx);
   TRY_SET_BRANCH("Photon_phi", Photon_phi, &b_Photon_phi);
   TRY_SET_BRANCH("Photon_pt", Photon_pt, &b_Photon_pt);
   TRY_SET_BRANCH("Photon_r9", Photon_r9, &b_Photon_r9);
   TRY_SET_BRANCH("Photon_sieie", Photon_sieie, &b_Photon_sieie);
   TRY_SET_BRANCH("Photon_charge", Photon_charge, &b_Photon_charge);
   TRY_SET_BRANCH("Photon_cutBasedBitmap", Photon_cutBasedBitmap, &b_Photon_cutBasedBitmap);
   TRY_SET_BRANCH("Photon_cutBasedV1Bitmap", Photon_cutBasedV1Bitmap, &b_Photon_cutBasedV1Bitmap);
   TRY_SET_BRANCH("Photon_electronIdx", Photon_electronIdx, &b_Photon_electronIdx);
   TRY_SET_BRANCH("Photon_jetIdx", Photon_jetIdx, &b_Photon_jetIdx);
   TRY_SET_BRANCH("Photon_pdgId", Photon_pdgId, &b_Photon_pdgId);
   TRY_SET_BRANCH("Photon_vidNestedWPBitmap", Photon_vidNestedWPBitmap, &b_Photon_vidNestedWPBitmap);
   TRY_SET_BRANCH("Photon_electronVeto", Photon_electronVeto, &b_Photon_electronVeto);
   TRY_SET_BRANCH("Photon_isScEtaEB", Photon_isScEtaEB, &b_Photon_isScEtaEB);
   TRY_SET_BRANCH("Photon_isScEtaEE", Photon_isScEtaEE, &b_Photon_isScEtaEE);
   TRY_SET_BRANCH("Photon_mvaID_WP80", Photon_mvaID_WP80, &b_Photon_mvaID_WP80);
   TRY_SET_BRANCH("Photon_mvaID_WP90", Photon_mvaID_WP90, &b_Photon_mvaID_WP90);
   TRY_SET_BRANCH("Photon_pixelSeed", Photon_pixelSeed, &b_Photon_pixelSeed);
   TRY_SET_BRANCH("Photon_seediEtaOriX", Photon_seediEtaOriX, &b_Photon_seediEtaOriX);
   TRY_SET_BRANCH("Photon_seediPhiOriY", Photon_seediPhiOriY, &b_Photon_seediPhiOriY);
   TRY_SET_BRANCH("Photon_seedGain", Photon_seedGain, &b_Photon_seedGain);
   TRY_SET_BRANCH("Photon_trkSumPtHollowConeDR03", Photon_trkSumPtHollowConeDR03, &b_Photon_trkSumPtHollowConeDR03);
   TRY_SET_BRANCH("Pileup_nTrueInt", &Pileup_nTrueInt, &b_Pileup_nTrueInt);
   TRY_SET_BRANCH("Pileup_pudensity", &Pileup_pudensity, &b_Pileup_pudensity);
   TRY_SET_BRANCH("Pileup_gpudensity", &Pileup_gpudensity, &b_Pileup_gpudensity);
   TRY_SET_BRANCH("Pileup_nPU", &Pileup_nPU, &b_Pileup_nPU);
   TRY_SET_BRANCH("Pileup_sumEOOT", &Pileup_sumEOOT, &b_Pileup_sumEOOT);
   TRY_SET_BRANCH("Pileup_sumLOOT", &Pileup_sumLOOT, &b_Pileup_sumLOOT);
   TRY_SET_BRANCH("PuppiMET_phi", &PuppiMET_phi, &b_PuppiMET_phi);
   TRY_SET_BRANCH("PuppiMET_pt", &PuppiMET_pt, &b_PuppiMET_pt);
   TRY_SET_BRANCH("PuppiMET_sumEt", &PuppiMET_sumEt, &b_PuppiMET_sumEt);
   TRY_SET_BRANCH("RawMET_phi", &RawMET_phi, &b_RawMET_phi);
   TRY_SET_BRANCH("RawMET_pt", &RawMET_pt, &b_RawMET_pt);
   TRY_SET_BRANCH("RawMET_sumEt", &RawMET_sumEt, &b_RawMET_sumEt);
   TRY_SET_BRANCH("Rho_fixedGridRhoFastjetAll", &fixedGridRhoFastjetAll, &b_fixedGridRhoFastjetAll);
   TRY_SET_BRANCH("Rho_fixedGridRhoFastjetCentral", &fixedGridRhoFastjetCentral, &b_fixedGridRhoFastjetCentral);
   TRY_SET_BRANCH("Rho_fixedGridRhoFastjetCentralCalo", &fixedGridRhoFastjetCentralCalo, &b_fixedGridRhoFastjetCentralCalo);
   TRY_SET_BRANCH("Rho_fixedGridRhoFastjetCentralChargedPileUp", &fixedGridRhoFastjetCentralChargedPileUp, &b_fixedGridRhoFastjetCentralChargedPileUp);
   TRY_SET_BRANCH("Rho_fixedGridRhoFastjetCentralNeutral", &fixedGridRhoFastjetCentralNeutral, &b_fixedGridRhoFastjetCentralNeutral);
   TRY_SET_BRANCH("nGenDressedLepton", &nGenDressedLepton, &b_nGenDressedLepton);
   TRY_SET_BRANCH("GenDressedLepton_eta", GenDressedLepton_eta, &b_GenDressedLepton_eta);
   TRY_SET_BRANCH("GenDressedLepton_mass", GenDressedLepton_mass, &b_GenDressedLepton_mass);
   TRY_SET_BRANCH("GenDressedLepton_phi", GenDressedLepton_phi, &b_GenDressedLepton_phi);
   TRY_SET_BRANCH("GenDressedLepton_pt", GenDressedLepton_pt, &b_GenDressedLepton_pt);
   TRY_SET_BRANCH("GenDressedLepton_pdgId", GenDressedLepton_pdgId, &b_GenDressedLepton_pdgId);
   TRY_SET_BRANCH("GenDressedLepton_hasTauAnc", GenDressedLepton_hasTauAnc, &b_GenDressedLepton_hasTauAnc);
   TRY_SET_BRANCH("nSoftActivityJet", &nSoftActivityJet, &b_nSoftActivityJet);
   TRY_SET_BRANCH("SoftActivityJet_eta", SoftActivityJet_eta, &b_SoftActivityJet_eta);
   TRY_SET_BRANCH("SoftActivityJet_phi", SoftActivityJet_phi, &b_SoftActivityJet_phi);
   TRY_SET_BRANCH("SoftActivityJet_pt", SoftActivityJet_pt, &b_SoftActivityJet_pt);
   TRY_SET_BRANCH("SoftActivityJetHT", &SoftActivityJetHT, &b_SoftActivityJetHT);
   TRY_SET_BRANCH("SoftActivityJetHT10", &SoftActivityJetHT10, &b_SoftActivityJetHT10);
   TRY_SET_BRANCH("SoftActivityJetHT2", &SoftActivityJetHT2, &b_SoftActivityJetHT2);
   TRY_SET_BRANCH("SoftActivityJetHT5", &SoftActivityJetHT5, &b_SoftActivityJetHT5);
   TRY_SET_BRANCH("SoftActivityJetNjets10", &SoftActivityJetNjets10, &b_SoftActivityJetNjets10);
   TRY_SET_BRANCH("SoftActivityJetNjets2", &SoftActivityJetNjets2, &b_SoftActivityJetNjets2);
   TRY_SET_BRANCH("SoftActivityJetNjets5", &SoftActivityJetNjets5, &b_SoftActivityJetNjets5);
   TRY_SET_BRANCH("nTau", &nTau, &b_nTau);
   TRY_SET_BRANCH("Tau_chargedIso", Tau_chargedIso, &b_Tau_chargedIso);
   TRY_SET_BRANCH("Tau_dxy", Tau_dxy, &b_Tau_dxy);
   TRY_SET_BRANCH("Tau_dz", Tau_dz, &b_Tau_dz);
   TRY_SET_BRANCH("Tau_eta", Tau_eta, &b_Tau_eta);
   TRY_SET_BRANCH("Tau_leadTkDeltaEta", Tau_leadTkDeltaEta, &b_Tau_leadTkDeltaEta);
   TRY_SET_BRANCH("Tau_leadTkDeltaPhi", Tau_leadTkDeltaPhi, &b_Tau_leadTkDeltaPhi);
   TRY_SET_BRANCH("Tau_leadTkPtOverTauPt", Tau_leadTkPtOverTauPt, &b_Tau_leadTkPtOverTauPt);
   TRY_SET_BRANCH("Tau_mass", Tau_mass, &b_Tau_mass);
   TRY_SET_BRANCH("Tau_neutralIso", Tau_neutralIso, &b_Tau_neutralIso);
   TRY_SET_BRANCH("Tau_phi", Tau_phi, &b_Tau_phi);
   TRY_SET_BRANCH("Tau_photonsOutsideSignalCone", Tau_photonsOutsideSignalCone, &b_Tau_photonsOutsideSignalCone);
   TRY_SET_BRANCH("Tau_pt", Tau_pt, &b_Tau_pt);
   TRY_SET_BRANCH("Tau_puCorr", Tau_puCorr, &b_Tau_puCorr);
   TRY_SET_BRANCH("Tau_rawAntiEle", Tau_rawAntiEle, &b_Tau_rawAntiEle);
   TRY_SET_BRANCH("Tau_rawAntiEle2018", Tau_rawAntiEle2018, &b_Tau_rawAntiEle2018);
   TRY_SET_BRANCH("Tau_rawDeepTau2017v2p1VSe", Tau_rawDeepTau2017v2p1VSe, &b_Tau_rawDeepTau2017v2p1VSe);
   TRY_SET_BRANCH("Tau_rawDeepTau2017v2p1VSjet", Tau_rawDeepTau2017v2p1VSjet, &b_Tau_rawDeepTau2017v2p1VSjet);
   TRY_SET_BRANCH("Tau_rawDeepTau2017v2p1VSmu", Tau_rawDeepTau2017v2p1VSmu, &b_Tau_rawDeepTau2017v2p1VSmu);
   TRY_SET_BRANCH("Tau_rawIso", Tau_rawIso, &b_Tau_rawIso);
   TRY_SET_BRANCH("Tau_rawIsodR03", Tau_rawIsodR03, &b_Tau_rawIsodR03);
   TRY_SET_BRANCH("Tau_rawMVAnewDM2017v2", Tau_rawMVAnewDM2017v2, &b_Tau_rawMVAnewDM2017v2);
   TRY_SET_BRANCH("Tau_rawMVAoldDM", Tau_rawMVAoldDM, &b_Tau_rawMVAoldDM);
   TRY_SET_BRANCH("Tau_rawMVAoldDM2017v1", Tau_rawMVAoldDM2017v1, &b_Tau_rawMVAoldDM2017v1);
   TRY_SET_BRANCH("Tau_rawMVAoldDM2017v2", Tau_rawMVAoldDM2017v2, &b_Tau_rawMVAoldDM2017v2);
   TRY_SET_BRANCH("Tau_rawMVAoldDMdR032017v2", Tau_rawMVAoldDMdR032017v2, &b_Tau_rawMVAoldDMdR032017v2);
   TRY_SET_BRANCH("Tau_charge", Tau_charge, &b_Tau_charge);
   TRY_SET_BRANCH("Tau_decayMode", Tau_decayMode, &b_Tau_decayMode);
   TRY_SET_BRANCH("Tau_jetIdx", Tau_jetIdx, &b_Tau_jetIdx);
   TRY_SET_BRANCH("Tau_rawAntiEleCat", Tau_rawAntiEleCat, &b_Tau_rawAntiEleCat);
   TRY_SET_BRANCH("Tau_rawAntiEleCat2018", Tau_rawAntiEleCat2018, &b_Tau_rawAntiEleCat2018);
   TRY_SET_BRANCH("Tau_idAntiEle", Tau_idAntiEle, &b_Tau_idAntiEle);
   TRY_SET_BRANCH("Tau_idAntiEle2018", Tau_idAntiEle2018, &b_Tau_idAntiEle2018);
   TRY_SET_BRANCH("Tau_idAntiMu", Tau_idAntiMu, &b_Tau_idAntiMu);
   TRY_SET_BRANCH("Tau_idDecayMode", Tau_idDecayMode, &b_Tau_idDecayMode);
   TRY_SET_BRANCH("Tau_idDecayModeNewDMs", Tau_idDecayModeNewDMs, &b_Tau_idDecayModeNewDMs);
   TRY_SET_BRANCH("Tau_idDeepTau2017v2p1VSe", Tau_idDeepTau2017v2p1VSe, &b_Tau_idDeepTau2017v2p1VSe);
   TRY_SET_BRANCH("Tau_idDeepTau2017v2p1VSjet", Tau_idDeepTau2017v2p1VSjet, &b_Tau_idDeepTau2017v2p1VSjet);
   TRY_SET_BRANCH("Tau_idDeepTau2017v2p1VSmu", Tau_idDeepTau2017v2p1VSmu, &b_Tau_idDeepTau2017v2p1VSmu);
   TRY_SET_BRANCH("Tau_idMVAnewDM2017v2", Tau_idMVAnewDM2017v2, &b_Tau_idMVAnewDM2017v2);
   TRY_SET_BRANCH("Tau_idMVAoldDM", Tau_idMVAoldDM, &b_Tau_idMVAoldDM);
   TRY_SET_BRANCH("Tau_idMVAoldDM2017v1", Tau_idMVAoldDM2017v1, &b_Tau_idMVAoldDM2017v1);
   TRY_SET_BRANCH("Tau_idMVAoldDM2017v2", Tau_idMVAoldDM2017v2, &b_Tau_idMVAoldDM2017v2);
   TRY_SET_BRANCH("Tau_idMVAoldDMdR032017v2", Tau_idMVAoldDMdR032017v2, &b_Tau_idMVAoldDMdR032017v2);
   TRY_SET_BRANCH("TkMET_phi", &TkMET_phi, &b_TkMET_phi);
   TRY_SET_BRANCH("TkMET_pt", &TkMET_pt, &b_TkMET_pt);
   TRY_SET_BRANCH("TkMET_sumEt", &TkMET_sumEt, &b_TkMET_sumEt);
   TRY_SET_BRANCH("nTrigObj", &nTrigObj, &b_nTrigObj);
   TRY_SET_BRANCH("TrigObj_pt", TrigObj_pt, &b_TrigObj_pt);
   TRY_SET_BRANCH("TrigObj_eta", TrigObj_eta, &b_TrigObj_eta);
   TRY_SET_BRANCH("TrigObj_phi", TrigObj_phi, &b_TrigObj_phi);
   TRY_SET_BRANCH("TrigObj_l1pt", TrigObj_l1pt, &b_TrigObj_l1pt);
   TRY_SET_BRANCH("TrigObj_l1pt_2", TrigObj_l1pt_2, &b_TrigObj_l1pt_2);
   TRY_SET_BRANCH("TrigObj_l2pt", TrigObj_l2pt, &b_TrigObj_l2pt);
   TRY_SET_BRANCH("TrigObj_id", TrigObj_id, &b_TrigObj_id);
   TRY_SET_BRANCH("TrigObj_l1iso", TrigObj_l1iso, &b_TrigObj_l1iso);
   TRY_SET_BRANCH("TrigObj_l1charge", TrigObj_l1charge, &b_TrigObj_l1charge);
   TRY_SET_BRANCH("TrigObj_filterBits", TrigObj_filterBits, &b_TrigObj_filterBits);
   TRY_SET_BRANCH("genTtbarId", &genTtbarId, &b_genTtbarId);
   TRY_SET_BRANCH("nOtherPV", &nOtherPV, &b_nOtherPV);
   TRY_SET_BRANCH("OtherPV_z", OtherPV_z, &b_OtherPV_z);
   TRY_SET_BRANCH("PV_ndof", &PV_ndof, &b_PV_ndof);
   TRY_SET_BRANCH("PV_x", &PV_x, &b_PV_x);
   TRY_SET_BRANCH("PV_y", &PV_y, &b_PV_y);
   TRY_SET_BRANCH("PV_z", &PV_z, &b_PV_z);
   TRY_SET_BRANCH("PV_chi2", &PV_chi2, &b_PV_chi2);
   TRY_SET_BRANCH("PV_score", &PV_score, &b_PV_score);
   TRY_SET_BRANCH("PV_npvs", &PV_npvs, &b_PV_npvs);
   TRY_SET_BRANCH("PV_npvsGood", &PV_npvsGood, &b_PV_npvsGood);
   TRY_SET_BRANCH("nSV", &nSV, &b_nSV);
   TRY_SET_BRANCH("SV_dlen", SV_dlen, &b_SV_dlen);
   TRY_SET_BRANCH("SV_dlenSig", SV_dlenSig, &b_SV_dlenSig);
   TRY_SET_BRANCH("SV_dxy", SV_dxy, &b_SV_dxy);
   TRY_SET_BRANCH("SV_dxySig", SV_dxySig, &b_SV_dxySig);
   TRY_SET_BRANCH("SV_pAngle", SV_pAngle, &b_SV_pAngle);
   TRY_SET_BRANCH("Electron_genPartIdx", Electron_genPartIdx, &b_Electron_genPartIdx);
   TRY_SET_BRANCH("Electron_genPartFlav", Electron_genPartFlav, &b_Electron_genPartFlav);
   TRY_SET_BRANCH("GenJetAK8_partonFlavour", GenJetAK8_partonFlavour, &b_GenJetAK8_partonFlavour);
   TRY_SET_BRANCH("GenJetAK8_hadronFlavour", GenJetAK8_hadronFlavour, &b_GenJetAK8_hadronFlavour);
   TRY_SET_BRANCH("GenJet_partonFlavour", GenJet_partonFlavour, &b_GenJet_partonFlavour);
   TRY_SET_BRANCH("GenJet_hadronFlavour", GenJet_hadronFlavour, &b_GenJet_hadronFlavour);
   TRY_SET_BRANCH("Jet_genJetIdx", Jet_genJetIdx, &b_Jet_genJetIdx);
   TRY_SET_BRANCH("Jet_hadronFlavour", Jet_hadronFlavour, &b_Jet_hadronFlavour);
   TRY_SET_BRANCH("Jet_partonFlavour", Jet_partonFlavour, &b_Jet_partonFlavour);
   TRY_SET_BRANCH("Muon_genPartIdx", Muon_genPartIdx, &b_Muon_genPartIdx);
   TRY_SET_BRANCH("Muon_genPartFlav", Muon_genPartFlav, &b_Muon_genPartFlav);
   TRY_SET_BRANCH("Photon_genPartIdx", Photon_genPartIdx, &b_Photon_genPartIdx);
   TRY_SET_BRANCH("Photon_genPartFlav", Photon_genPartFlav, &b_Photon_genPartFlav);
   TRY_SET_BRANCH("MET_fiducialGenPhi", &MET_fiducialGenPhi, &b_MET_fiducialGenPhi);
   TRY_SET_BRANCH("MET_fiducialGenPt", &MET_fiducialGenPt, &b_MET_fiducialGenPt);
   TRY_SET_BRANCH("Tau_genPartIdx", Tau_genPartIdx, &b_Tau_genPartIdx);
   TRY_SET_BRANCH("Tau_genPartFlav", Tau_genPartFlav, &b_Tau_genPartFlav);
   TRY_SET_BRANCH("L1simulation_step", &L1simulation_step, &b_L1simulation_step);
   TRY_SET_BRANCH("Electron_cleanmask", Electron_cleanmask, &b_Electron_cleanmask);
   TRY_SET_BRANCH("Jet_cleanmask", Jet_cleanmask, &b_Jet_cleanmask);
   TRY_SET_BRANCH("Muon_cleanmask", Muon_cleanmask, &b_Muon_cleanmask);
   TRY_SET_BRANCH("Photon_cleanmask", Photon_cleanmask, &b_Photon_cleanmask);
   TRY_SET_BRANCH("Tau_cleanmask", Tau_cleanmask, &b_Tau_cleanmask);
   TRY_SET_BRANCH("SV_chi2", SV_chi2, &b_SV_chi2);
   TRY_SET_BRANCH("SV_eta", SV_eta, &b_SV_eta);
   TRY_SET_BRANCH("SV_mass", SV_mass, &b_SV_mass);
   TRY_SET_BRANCH("SV_ndof", SV_ndof, &b_SV_ndof);
   TRY_SET_BRANCH("SV_phi", SV_phi, &b_SV_phi);
   TRY_SET_BRANCH("SV_pt", SV_pt, &b_SV_pt);
   TRY_SET_BRANCH("SV_x", SV_x, &b_SV_x);
   TRY_SET_BRANCH("SV_y", SV_y, &b_SV_y);
   TRY_SET_BRANCH("SV_z", SV_z, &b_SV_z);
   TRY_SET_BRANCH("HLTriggerFirstPath", &HLTriggerFirstPath, &b_HLTriggerFirstPath);
   TRY_SET_BRANCH("HLT_AK8PFJet360_TrimMass30", &HLT_AK8PFJet360_TrimMass30, &b_HLT_AK8PFJet360_TrimMass30);
   TRY_SET_BRANCH("HLT_AK8PFJet380_TrimMass30", &HLT_AK8PFJet380_TrimMass30, &b_HLT_AK8PFJet380_TrimMass30);
   TRY_SET_BRANCH("HLT_AK8PFJet400_TrimMass30", &HLT_AK8PFJet400_TrimMass30, &b_HLT_AK8PFJet400_TrimMass30);
   TRY_SET_BRANCH("HLT_AK8PFJet420_TrimMass30", &HLT_AK8PFJet420_TrimMass30, &b_HLT_AK8PFJet420_TrimMass30);
   TRY_SET_BRANCH("HLT_AK8PFJet380_SoftDropMass30", &HLT_AK8PFJet380_SoftDropMass30, &b_HLT_AK8PFJet380_SoftDropMass30);
   TRY_SET_BRANCH("HLT_AK8PFJet400_SoftDropMass30", &HLT_AK8PFJet400_SoftDropMass30, &b_HLT_AK8PFJet400_SoftDropMass30);
   TRY_SET_BRANCH("HLT_AK8PFJet425_SoftDropMass30", &HLT_AK8PFJet425_SoftDropMass30, &b_HLT_AK8PFJet425_SoftDropMass30);
   TRY_SET_BRANCH("HLT_AK8PFJet450_SoftDropMass30", &HLT_AK8PFJet450_SoftDropMass30, &b_HLT_AK8PFJet450_SoftDropMass30);
   TRY_SET_BRANCH("HLT_AK8DiPFJet250_250_SoftDropMass40", &HLT_AK8DiPFJet250_250_SoftDropMass40, &b_HLT_AK8DiPFJet250_250_SoftDropMass40);
   TRY_SET_BRANCH("HLT_AK8DiPFJet250_250_SoftDropMass50", &HLT_AK8DiPFJet250_250_SoftDropMass50, &b_HLT_AK8DiPFJet250_250_SoftDropMass50);
   TRY_SET_BRANCH("HLT_AK8DiPFJet260_260_SoftDropMass30", &HLT_AK8DiPFJet260_260_SoftDropMass30, &b_HLT_AK8DiPFJet260_260_SoftDropMass30);
   TRY_SET_BRANCH("HLT_AK8DiPFJet260_260_SoftDropMass40", &HLT_AK8DiPFJet260_260_SoftDropMass40, &b_HLT_AK8DiPFJet260_260_SoftDropMass40);
   TRY_SET_BRANCH("HLT_AK8DiPFJet270_270_SoftDropMass30", &HLT_AK8DiPFJet270_270_SoftDropMass30, &b_HLT_AK8DiPFJet270_270_SoftDropMass30);
   TRY_SET_BRANCH("HLT_AK8DiPFJet280_280_SoftDropMass30", &HLT_AK8DiPFJet280_280_SoftDropMass30, &b_HLT_AK8DiPFJet280_280_SoftDropMass30);
   TRY_SET_BRANCH("HLT_AK8DiPFJet290_290_SoftDropMass30", &HLT_AK8DiPFJet290_290_SoftDropMass30, &b_HLT_AK8DiPFJet290_290_SoftDropMass30);
   TRY_SET_BRANCH("HLT_AK8PFJet220_SoftDropMass40", &HLT_AK8PFJet220_SoftDropMass40, &b_HLT_AK8PFJet220_SoftDropMass40);
   TRY_SET_BRANCH("HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p50", &HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p50, &b_HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p50);
   TRY_SET_BRANCH("HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p53", &HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p53, &b_HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p53);
   TRY_SET_BRANCH("HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p55", &HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p55, &b_HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p55);
   TRY_SET_BRANCH("HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p60", &HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p60, &b_HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p60);
   TRY_SET_BRANCH("HLT_AK8PFJet230_SoftDropMass40", &HLT_AK8PFJet230_SoftDropMass40, &b_HLT_AK8PFJet230_SoftDropMass40);
   TRY_SET_BRANCH("HLT_AK8PFJet230_SoftDropMass40_PNetBB0p06", &HLT_AK8PFJet230_SoftDropMass40_PNetBB0p06, &b_HLT_AK8PFJet230_SoftDropMass40_PNetBB0p06);
   TRY_SET_BRANCH("HLT_AK8PFJet230_SoftDropMass40_PNetBB0p10", &HLT_AK8PFJet230_SoftDropMass40_PNetBB0p10, &b_HLT_AK8PFJet230_SoftDropMass40_PNetBB0p10);
   TRY_SET_BRANCH("HLT_AK8PFJet230_SoftDropMass40_PNetTauTau0p03", &HLT_AK8PFJet230_SoftDropMass40_PNetTauTau0p03, &b_HLT_AK8PFJet230_SoftDropMass40_PNetTauTau0p03);
   TRY_SET_BRANCH("HLT_AK8PFJet230_SoftDropMass40_PNetTauTau0p05", &HLT_AK8PFJet230_SoftDropMass40_PNetTauTau0p05, &b_HLT_AK8PFJet230_SoftDropMass40_PNetTauTau0p05);
   TRY_SET_BRANCH("HLT_AK8PFJet250_SoftDropMass40_PNetBB0p06", &HLT_AK8PFJet250_SoftDropMass40_PNetBB0p06, &b_HLT_AK8PFJet250_SoftDropMass40_PNetBB0p06);
   TRY_SET_BRANCH("HLT_AK8PFJet250_SoftDropMass40_PNetBB0p10", &HLT_AK8PFJet250_SoftDropMass40_PNetBB0p10, &b_HLT_AK8PFJet250_SoftDropMass40_PNetBB0p10);
   TRY_SET_BRANCH("HLT_AK8PFJet250_SoftDropMass40_PNetTauTau0p03", &HLT_AK8PFJet250_SoftDropMass40_PNetTauTau0p03, &b_HLT_AK8PFJet250_SoftDropMass40_PNetTauTau0p03);
   TRY_SET_BRANCH("HLT_AK8PFJet250_SoftDropMass40_PNetTauTau0p05", &HLT_AK8PFJet250_SoftDropMass40_PNetTauTau0p05, &b_HLT_AK8PFJet250_SoftDropMass40_PNetTauTau0p05);
   TRY_SET_BRANCH("HLT_AK8PFJet275_SoftDropMass40_PNetBB0p06", &HLT_AK8PFJet275_SoftDropMass40_PNetBB0p06, &b_HLT_AK8PFJet275_SoftDropMass40_PNetBB0p06);
   TRY_SET_BRANCH("HLT_AK8PFJet275_SoftDropMass40_PNetBB0p10", &HLT_AK8PFJet275_SoftDropMass40_PNetBB0p10, &b_HLT_AK8PFJet275_SoftDropMass40_PNetBB0p10);
   TRY_SET_BRANCH("HLT_AK8PFJet275_SoftDropMass40_PNetTauTau0p03", &HLT_AK8PFJet275_SoftDropMass40_PNetTauTau0p03, &b_HLT_AK8PFJet275_SoftDropMass40_PNetTauTau0p03);
   TRY_SET_BRANCH("HLT_AK8PFJet275_SoftDropMass40_PNetTauTau0p05", &HLT_AK8PFJet275_SoftDropMass40_PNetTauTau0p05, &b_HLT_AK8PFJet275_SoftDropMass40_PNetTauTau0p05);
   TRY_SET_BRANCH("HLT_AK8PFJet400_MassSD30", &HLT_AK8PFJet400_MassSD30, &b_HLT_AK8PFJet400_MassSD30);
   TRY_SET_BRANCH("HLT_AK8PFJet420_MassSD30", &HLT_AK8PFJet420_MassSD30, &b_HLT_AK8PFJet420_MassSD30);
   TRY_SET_BRANCH("HLT_AK8PFJet450_MassSD30", &HLT_AK8PFJet450_MassSD30, &b_HLT_AK8PFJet450_MassSD30);
   TRY_SET_BRANCH("HLT_AK8DiPFJet250_250_MassSD30", &HLT_AK8DiPFJet250_250_MassSD30, &b_HLT_AK8DiPFJet250_250_MassSD30);
   TRY_SET_BRANCH("HLT_AK8DiPFJet250_250_MassSD50", &HLT_AK8DiPFJet250_250_MassSD50, &b_HLT_AK8DiPFJet250_250_MassSD50);
   TRY_SET_BRANCH("HLT_AK8DiPFJet260_260_MassSD30", &HLT_AK8DiPFJet260_260_MassSD30, &b_HLT_AK8DiPFJet260_260_MassSD30);
   TRY_SET_BRANCH("HLT_AK8DiPFJet270_270_MassSD30", &HLT_AK8DiPFJet270_270_MassSD30, &b_HLT_AK8DiPFJet270_270_MassSD30);
   TRY_SET_BRANCH("HLT_AK8PFHT750_TrimMass50", &HLT_AK8PFHT750_TrimMass50, &b_HLT_AK8PFHT750_TrimMass50);
   TRY_SET_BRANCH("HLT_AK8PFHT800_TrimMass50", &HLT_AK8PFHT800_TrimMass50, &b_HLT_AK8PFHT800_TrimMass50);
   TRY_SET_BRANCH("HLT_AK8PFHT850_TrimMass50", &HLT_AK8PFHT850_TrimMass50, &b_HLT_AK8PFHT850_TrimMass50);
   TRY_SET_BRANCH("HLT_AK8PFHT900_TrimMass50", &HLT_AK8PFHT900_TrimMass50, &b_HLT_AK8PFHT900_TrimMass50);
   TRY_SET_BRANCH("HLT_CaloJet500_NoJetID", &HLT_CaloJet500_NoJetID, &b_HLT_CaloJet500_NoJetID);
   TRY_SET_BRANCH("HLT_CaloJet550_NoJetID", &HLT_CaloJet550_NoJetID, &b_HLT_CaloJet550_NoJetID);
   TRY_SET_BRANCH("HLT_DoubleMu5_Upsilon_DoubleEle3_CaloIdL_TrackIdL", &HLT_DoubleMu5_Upsilon_DoubleEle3_CaloIdL_TrackIdL, &b_HLT_DoubleMu5_Upsilon_DoubleEle3_CaloIdL_TrackIdL);
   TRY_SET_BRANCH("HLT_DoubleMu3_DoubleEle7p5_CaloIdL_TrackIdL_Upsilon", &HLT_DoubleMu3_DoubleEle7p5_CaloIdL_TrackIdL_Upsilon, &b_HLT_DoubleMu3_DoubleEle7p5_CaloIdL_TrackIdL_Upsilon);
   TRY_SET_BRANCH("HLT_Trimuon5_3p5_2_Upsilon_Muon", &HLT_Trimuon5_3p5_2_Upsilon_Muon, &b_HLT_Trimuon5_3p5_2_Upsilon_Muon);
   TRY_SET_BRANCH("HLT_TrimuonOpen_5_3p5_2_Upsilon_Muon", &HLT_TrimuonOpen_5_3p5_2_Upsilon_Muon, &b_HLT_TrimuonOpen_5_3p5_2_Upsilon_Muon);
   TRY_SET_BRANCH("HLT_DoubleEle25_CaloIdL_MW", &HLT_DoubleEle25_CaloIdL_MW, &b_HLT_DoubleEle25_CaloIdL_MW);
   TRY_SET_BRANCH("HLT_DoubleEle27_CaloIdL_MW", &HLT_DoubleEle27_CaloIdL_MW, &b_HLT_DoubleEle27_CaloIdL_MW);
   TRY_SET_BRANCH("HLT_DoubleEle33_CaloIdL_MW", &HLT_DoubleEle33_CaloIdL_MW, &b_HLT_DoubleEle33_CaloIdL_MW);
   TRY_SET_BRANCH("HLT_DoubleEle24_eta2p1_WPTight_Gsf", &HLT_DoubleEle24_eta2p1_WPTight_Gsf, &b_HLT_DoubleEle24_eta2p1_WPTight_Gsf);
   TRY_SET_BRANCH("HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_DZ_PFHT350", &HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_DZ_PFHT350, &b_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_DZ_PFHT350);
   TRY_SET_BRANCH("HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT350", &HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT350, &b_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT350);
   TRY_SET_BRANCH("HLT_Ele27_Ele37_CaloIdL_MW", &HLT_Ele27_Ele37_CaloIdL_MW, &b_HLT_Ele27_Ele37_CaloIdL_MW);
   TRY_SET_BRANCH("HLT_Mu27_Ele37_CaloIdL_MW", &HLT_Mu27_Ele37_CaloIdL_MW, &b_HLT_Mu27_Ele37_CaloIdL_MW);
   TRY_SET_BRANCH("HLT_Mu37_Ele27_CaloIdL_MW", &HLT_Mu37_Ele27_CaloIdL_MW, &b_HLT_Mu37_Ele27_CaloIdL_MW);
   TRY_SET_BRANCH("HLT_Mu37_TkMu27", &HLT_Mu37_TkMu27, &b_HLT_Mu37_TkMu27);
   TRY_SET_BRANCH("HLT_DoubleMu4_3_Bs", &HLT_DoubleMu4_3_Bs, &b_HLT_DoubleMu4_3_Bs);
   TRY_SET_BRANCH("HLT_DoubleMu4_3_Jpsi", &HLT_DoubleMu4_3_Jpsi, &b_HLT_DoubleMu4_3_Jpsi);
   TRY_SET_BRANCH("HLT_DoubleMu4_JpsiTrk_Displaced", &HLT_DoubleMu4_JpsiTrk_Displaced, &b_HLT_DoubleMu4_JpsiTrk_Displaced);
   TRY_SET_BRANCH("HLT_DoubleMu4_LowMassNonResonantTrk_Displaced", &HLT_DoubleMu4_LowMassNonResonantTrk_Displaced, &b_HLT_DoubleMu4_LowMassNonResonantTrk_Displaced);
   TRY_SET_BRANCH("HLT_DoubleMu3_Trk_Tau3mu", &HLT_DoubleMu3_Trk_Tau3mu, &b_HLT_DoubleMu3_Trk_Tau3mu);
   TRY_SET_BRANCH("HLT_DoubleMu3_TkMu_DsTau3Mu", &HLT_DoubleMu3_TkMu_DsTau3Mu, &b_HLT_DoubleMu3_TkMu_DsTau3Mu);
   TRY_SET_BRANCH("HLT_DoubleMu4_PsiPrimeTrk_Displaced", &HLT_DoubleMu4_PsiPrimeTrk_Displaced, &b_HLT_DoubleMu4_PsiPrimeTrk_Displaced);
   TRY_SET_BRANCH("HLT_DoubleMu4_Mass3p8_DZ_PFHT350", &HLT_DoubleMu4_Mass3p8_DZ_PFHT350, &b_HLT_DoubleMu4_Mass3p8_DZ_PFHT350);
   TRY_SET_BRANCH("HLT_Mu3_PFJet40", &HLT_Mu3_PFJet40, &b_HLT_Mu3_PFJet40);
   TRY_SET_BRANCH("HLT_Mu7p5_L2Mu2_Jpsi", &HLT_Mu7p5_L2Mu2_Jpsi, &b_HLT_Mu7p5_L2Mu2_Jpsi);
   TRY_SET_BRANCH("HLT_Mu7p5_L2Mu2_Upsilon", &HLT_Mu7p5_L2Mu2_Upsilon, &b_HLT_Mu7p5_L2Mu2_Upsilon);
   TRY_SET_BRANCH("HLT_Mu7p5_Track2_Jpsi", &HLT_Mu7p5_Track2_Jpsi, &b_HLT_Mu7p5_Track2_Jpsi);
   TRY_SET_BRANCH("HLT_Mu7p5_Track3p5_Jpsi", &HLT_Mu7p5_Track3p5_Jpsi, &b_HLT_Mu7p5_Track3p5_Jpsi);
   TRY_SET_BRANCH("HLT_Mu7p5_Track7_Jpsi", &HLT_Mu7p5_Track7_Jpsi, &b_HLT_Mu7p5_Track7_Jpsi);
   TRY_SET_BRANCH("HLT_Mu7p5_Track2_Upsilon", &HLT_Mu7p5_Track2_Upsilon, &b_HLT_Mu7p5_Track2_Upsilon);
   TRY_SET_BRANCH("HLT_Mu7p5_Track3p5_Upsilon", &HLT_Mu7p5_Track3p5_Upsilon, &b_HLT_Mu7p5_Track3p5_Upsilon);
   TRY_SET_BRANCH("HLT_Mu7p5_Track7_Upsilon", &HLT_Mu7p5_Track7_Upsilon, &b_HLT_Mu7p5_Track7_Upsilon);
   TRY_SET_BRANCH("HLT_Mu3_L1SingleMu5orSingleMu7", &HLT_Mu3_L1SingleMu5orSingleMu7, &b_HLT_Mu3_L1SingleMu5orSingleMu7);
   TRY_SET_BRANCH("HLT_DoublePhoton33_CaloIdL", &HLT_DoublePhoton33_CaloIdL, &b_HLT_DoublePhoton33_CaloIdL);
   TRY_SET_BRANCH("HLT_DoublePhoton70", &HLT_DoublePhoton70, &b_HLT_DoublePhoton70);
   TRY_SET_BRANCH("HLT_DoublePhoton85", &HLT_DoublePhoton85, &b_HLT_DoublePhoton85);
   TRY_SET_BRANCH("HLT_Ele20_WPTight_Gsf", &HLT_Ele20_WPTight_Gsf, &b_HLT_Ele20_WPTight_Gsf);
   TRY_SET_BRANCH("HLT_Ele15_WPLoose_Gsf", &HLT_Ele15_WPLoose_Gsf, &b_HLT_Ele15_WPLoose_Gsf);
   TRY_SET_BRANCH("HLT_Ele17_WPLoose_Gsf", &HLT_Ele17_WPLoose_Gsf, &b_HLT_Ele17_WPLoose_Gsf);
   TRY_SET_BRANCH("HLT_Ele20_WPLoose_Gsf", &HLT_Ele20_WPLoose_Gsf, &b_HLT_Ele20_WPLoose_Gsf);
   TRY_SET_BRANCH("HLT_Ele20_eta2p1_WPLoose_Gsf", &HLT_Ele20_eta2p1_WPLoose_Gsf, &b_HLT_Ele20_eta2p1_WPLoose_Gsf);
   TRY_SET_BRANCH("HLT_DiEle27_WPTightCaloOnly_L1DoubleEG", &HLT_DiEle27_WPTightCaloOnly_L1DoubleEG, &b_HLT_DiEle27_WPTightCaloOnly_L1DoubleEG);
   TRY_SET_BRANCH("HLT_Ele27_WPTight_Gsf", &HLT_Ele27_WPTight_Gsf, &b_HLT_Ele27_WPTight_Gsf);
   TRY_SET_BRANCH("HLT_Ele28_WPTight_Gsf", &HLT_Ele28_WPTight_Gsf, &b_HLT_Ele28_WPTight_Gsf);
   TRY_SET_BRANCH("HLT_Ele30_WPTight_Gsf", &HLT_Ele30_WPTight_Gsf, &b_HLT_Ele30_WPTight_Gsf);
   TRY_SET_BRANCH("HLT_Ele32_WPTight_Gsf", &HLT_Ele32_WPTight_Gsf, &b_HLT_Ele32_WPTight_Gsf);
   TRY_SET_BRANCH("HLT_Ele35_WPTight_Gsf", &HLT_Ele35_WPTight_Gsf, &b_HLT_Ele35_WPTight_Gsf);
   TRY_SET_BRANCH("HLT_Ele35_WPTight_Gsf_L1EGMT", &HLT_Ele35_WPTight_Gsf_L1EGMT, &b_HLT_Ele35_WPTight_Gsf_L1EGMT);
   TRY_SET_BRANCH("HLT_Ele38_WPTight_Gsf", &HLT_Ele38_WPTight_Gsf, &b_HLT_Ele38_WPTight_Gsf);
   TRY_SET_BRANCH("HLT_Ele40_WPTight_Gsf", &HLT_Ele40_WPTight_Gsf, &b_HLT_Ele40_WPTight_Gsf);
   TRY_SET_BRANCH("HLT_Ele32_WPTight_Gsf_L1DoubleEG", &HLT_Ele32_WPTight_Gsf_L1DoubleEG, &b_HLT_Ele32_WPTight_Gsf_L1DoubleEG);
   TRY_SET_BRANCH("HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_CrossL1", &HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_CrossL1, &b_HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_CrossL1);
   TRY_SET_BRANCH("HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTauHPS30_eta2p1_CrossL1", &HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTauHPS30_eta2p1_CrossL1, &b_HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTauHPS30_eta2p1_CrossL1);
   TRY_SET_BRANCH("HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTauHPS30_eta2p1_CrossL1", &HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTauHPS30_eta2p1_CrossL1, &b_HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTauHPS30_eta2p1_CrossL1);
   TRY_SET_BRANCH("HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_TightID_CrossL1", &HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_TightID_CrossL1, &b_HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_TightID_CrossL1);
   TRY_SET_BRANCH("HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTauHPS30_eta2p1_TightID_CrossL1", &HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTauHPS30_eta2p1_TightID_CrossL1, &b_HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTauHPS30_eta2p1_TightID_CrossL1);
   TRY_SET_BRANCH("HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTauHPS30_eta2p1_TightID_CrossL1", &HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTauHPS30_eta2p1_TightID_CrossL1, &b_HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTauHPS30_eta2p1_TightID_CrossL1);
   TRY_SET_BRANCH("HLT_HT450_Beamspot", &HLT_HT450_Beamspot, &b_HLT_HT450_Beamspot);
   TRY_SET_BRANCH("HLT_HT300_Beamspot", &HLT_HT300_Beamspot, &b_HLT_HT300_Beamspot);
   TRY_SET_BRANCH("HLT_ZeroBias_Beamspot", &HLT_ZeroBias_Beamspot, &b_HLT_ZeroBias_Beamspot);
   TRY_SET_BRANCH("HLT_IsoMu20_eta2p1_LooseChargedIsoPFTauHPS27_eta2p1_CrossL1", &HLT_IsoMu20_eta2p1_LooseChargedIsoPFTauHPS27_eta2p1_CrossL1, &b_HLT_IsoMu20_eta2p1_LooseChargedIsoPFTauHPS27_eta2p1_CrossL1);
   TRY_SET_BRANCH("HLT_IsoMu20_eta2p1_MediumChargedIsoPFTauHPS27_eta2p1_CrossL1", &HLT_IsoMu20_eta2p1_MediumChargedIsoPFTauHPS27_eta2p1_CrossL1, &b_HLT_IsoMu20_eta2p1_MediumChargedIsoPFTauHPS27_eta2p1_CrossL1);
   TRY_SET_BRANCH("HLT_IsoMu20_eta2p1_TightChargedIsoPFTauHPS27_eta2p1_CrossL1", &HLT_IsoMu20_eta2p1_TightChargedIsoPFTauHPS27_eta2p1_CrossL1, &b_HLT_IsoMu20_eta2p1_TightChargedIsoPFTauHPS27_eta2p1_CrossL1);
   TRY_SET_BRANCH("HLT_IsoMu20_eta2p1_LooseChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1", &HLT_IsoMu20_eta2p1_LooseChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1, &b_HLT_IsoMu20_eta2p1_LooseChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1);
   TRY_SET_BRANCH("HLT_IsoMu20_eta2p1_MediumChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1", &HLT_IsoMu20_eta2p1_MediumChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1, &b_HLT_IsoMu20_eta2p1_MediumChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1);
   TRY_SET_BRANCH("HLT_IsoMu20_eta2p1_TightChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1", &HLT_IsoMu20_eta2p1_TightChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1, &b_HLT_IsoMu20_eta2p1_TightChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1);
   TRY_SET_BRANCH("HLT_IsoMu24_eta2p1_TightChargedIsoPFTauHPS35_Trk1_eta2p1_Reg_CrossL1", &HLT_IsoMu24_eta2p1_TightChargedIsoPFTauHPS35_Trk1_eta2p1_Reg_CrossL1, &b_HLT_IsoMu24_eta2p1_TightChargedIsoPFTauHPS35_Trk1_eta2p1_Reg_CrossL1);
   TRY_SET_BRANCH("HLT_IsoMu24_eta2p1_MediumChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg_CrossL1", &HLT_IsoMu24_eta2p1_MediumChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg_CrossL1, &b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg_CrossL1);
   TRY_SET_BRANCH("HLT_IsoMu24_eta2p1_TightChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg_CrossL1", &HLT_IsoMu24_eta2p1_TightChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg_CrossL1, &b_HLT_IsoMu24_eta2p1_TightChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg_CrossL1);
   TRY_SET_BRANCH("HLT_IsoMu24_eta2p1_MediumChargedIsoPFTauHPS35_Trk1_eta2p1_Reg_CrossL1", &HLT_IsoMu24_eta2p1_MediumChargedIsoPFTauHPS35_Trk1_eta2p1_Reg_CrossL1, &b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTauHPS35_Trk1_eta2p1_Reg_CrossL1);
   TRY_SET_BRANCH("HLT_IsoMu27_LooseChargedIsoPFTauHPS20_Trk1_eta2p1_SingleL1", &HLT_IsoMu27_LooseChargedIsoPFTauHPS20_Trk1_eta2p1_SingleL1, &b_HLT_IsoMu27_LooseChargedIsoPFTauHPS20_Trk1_eta2p1_SingleL1);
   TRY_SET_BRANCH("HLT_IsoMu27_MediumChargedIsoPFTauHPS20_Trk1_eta2p1_SingleL1", &HLT_IsoMu27_MediumChargedIsoPFTauHPS20_Trk1_eta2p1_SingleL1, &b_HLT_IsoMu27_MediumChargedIsoPFTauHPS20_Trk1_eta2p1_SingleL1);
   TRY_SET_BRANCH("HLT_IsoMu27_TightChargedIsoPFTauHPS20_Trk1_eta2p1_SingleL1", &HLT_IsoMu27_TightChargedIsoPFTauHPS20_Trk1_eta2p1_SingleL1, &b_HLT_IsoMu27_TightChargedIsoPFTauHPS20_Trk1_eta2p1_SingleL1);
   TRY_SET_BRANCH("HLT_IsoMu20", &HLT_IsoMu20, &b_HLT_IsoMu20);
   TRY_SET_BRANCH("HLT_IsoMu24", &HLT_IsoMu24, &b_HLT_IsoMu24);
   TRY_SET_BRANCH("HLT_IsoMu24_eta2p1", &HLT_IsoMu24_eta2p1, &b_HLT_IsoMu24_eta2p1);
   TRY_SET_BRANCH("HLT_IsoMu27", &HLT_IsoMu27, &b_HLT_IsoMu27);
   TRY_SET_BRANCH("HLT_IsoMu30", &HLT_IsoMu30, &b_HLT_IsoMu30);
   TRY_SET_BRANCH("HLT_UncorrectedJetE30_NoBPTX", &HLT_UncorrectedJetE30_NoBPTX, &b_HLT_UncorrectedJetE30_NoBPTX);
   TRY_SET_BRANCH("HLT_UncorrectedJetE30_NoBPTX3BX", &HLT_UncorrectedJetE30_NoBPTX3BX, &b_HLT_UncorrectedJetE30_NoBPTX3BX);
   TRY_SET_BRANCH("HLT_UncorrectedJetE60_NoBPTX3BX", &HLT_UncorrectedJetE60_NoBPTX3BX, &b_HLT_UncorrectedJetE60_NoBPTX3BX);
   TRY_SET_BRANCH("HLT_UncorrectedJetE70_NoBPTX3BX", &HLT_UncorrectedJetE70_NoBPTX3BX, &b_HLT_UncorrectedJetE70_NoBPTX3BX);
   TRY_SET_BRANCH("HLT_L1SingleMu18", &HLT_L1SingleMu18, &b_HLT_L1SingleMu18);
   TRY_SET_BRANCH("HLT_L1SingleMu25", &HLT_L1SingleMu25, &b_HLT_L1SingleMu25);
   TRY_SET_BRANCH("HLT_L2Mu10", &HLT_L2Mu10, &b_HLT_L2Mu10);
   TRY_SET_BRANCH("HLT_L2Mu10_NoVertex_NoBPTX3BX", &HLT_L2Mu10_NoVertex_NoBPTX3BX, &b_HLT_L2Mu10_NoVertex_NoBPTX3BX);
   TRY_SET_BRANCH("HLT_L2Mu10_NoVertex_NoBPTX", &HLT_L2Mu10_NoVertex_NoBPTX, &b_HLT_L2Mu10_NoVertex_NoBPTX);
   TRY_SET_BRANCH("HLT_L2Mu45_NoVertex_3Sta_NoBPTX3BX", &HLT_L2Mu45_NoVertex_3Sta_NoBPTX3BX, &b_HLT_L2Mu45_NoVertex_3Sta_NoBPTX3BX);
   TRY_SET_BRANCH("HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX", &HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX, &b_HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX);
   TRY_SET_BRANCH("HLT_L2Mu50", &HLT_L2Mu50, &b_HLT_L2Mu50);
   TRY_SET_BRANCH("HLT_L2Mu23NoVtx_2Cha", &HLT_L2Mu23NoVtx_2Cha, &b_HLT_L2Mu23NoVtx_2Cha);
   TRY_SET_BRANCH("HLT_L2Mu23NoVtx_2Cha_CosmicSeed", &HLT_L2Mu23NoVtx_2Cha_CosmicSeed, &b_HLT_L2Mu23NoVtx_2Cha_CosmicSeed);
   TRY_SET_BRANCH("HLT_DoubleL2Mu30NoVtx_2Cha_CosmicSeed_Eta2p4", &HLT_DoubleL2Mu30NoVtx_2Cha_CosmicSeed_Eta2p4, &b_HLT_DoubleL2Mu30NoVtx_2Cha_CosmicSeed_Eta2p4);
   TRY_SET_BRANCH("HLT_DoubleL2Mu30NoVtx_2Cha_Eta2p4", &HLT_DoubleL2Mu30NoVtx_2Cha_Eta2p4, &b_HLT_DoubleL2Mu30NoVtx_2Cha_Eta2p4);
   TRY_SET_BRANCH("HLT_DoubleL2Mu50", &HLT_DoubleL2Mu50, &b_HLT_DoubleL2Mu50);
   TRY_SET_BRANCH("HLT_DoubleL2Mu23NoVtx_2Cha_CosmicSeed", &HLT_DoubleL2Mu23NoVtx_2Cha_CosmicSeed, &b_HLT_DoubleL2Mu23NoVtx_2Cha_CosmicSeed);
   TRY_SET_BRANCH("HLT_DoubleL2Mu23NoVtx_2Cha_CosmicSeed_NoL2Matched", &HLT_DoubleL2Mu23NoVtx_2Cha_CosmicSeed_NoL2Matched, &b_HLT_DoubleL2Mu23NoVtx_2Cha_CosmicSeed_NoL2Matched);
   TRY_SET_BRANCH("HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed", &HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed, &b_HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed);
   TRY_SET_BRANCH("HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed_NoL2Matched", &HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed_NoL2Matched, &b_HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed_NoL2Matched);
   TRY_SET_BRANCH("HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed_Eta2p4", &HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed_Eta2p4, &b_HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed_Eta2p4);
   TRY_SET_BRANCH("HLT_DoubleL2Mu23NoVtx_2Cha", &HLT_DoubleL2Mu23NoVtx_2Cha, &b_HLT_DoubleL2Mu23NoVtx_2Cha);
   TRY_SET_BRANCH("HLT_DoubleL2Mu23NoVtx_2Cha_NoL2Matched", &HLT_DoubleL2Mu23NoVtx_2Cha_NoL2Matched, &b_HLT_DoubleL2Mu23NoVtx_2Cha_NoL2Matched);
   TRY_SET_BRANCH("HLT_DoubleL2Mu25NoVtx_2Cha", &HLT_DoubleL2Mu25NoVtx_2Cha, &b_HLT_DoubleL2Mu25NoVtx_2Cha);
   TRY_SET_BRANCH("HLT_DoubleL2Mu25NoVtx_2Cha_NoL2Matched", &HLT_DoubleL2Mu25NoVtx_2Cha_NoL2Matched, &b_HLT_DoubleL2Mu25NoVtx_2Cha_NoL2Matched);
   TRY_SET_BRANCH("HLT_DoubleL2Mu25NoVtx_2Cha_Eta2p4", &HLT_DoubleL2Mu25NoVtx_2Cha_Eta2p4, &b_HLT_DoubleL2Mu25NoVtx_2Cha_Eta2p4);
   TRY_SET_BRANCH("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL", &HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL, &b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL);
   TRY_SET_BRANCH("HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL", &HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL, &b_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL);
   TRY_SET_BRANCH("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ", &HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ, &b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ);
   TRY_SET_BRANCH("HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ", &HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ, &b_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ);
   TRY_SET_BRANCH("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8", &HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8, &b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8);
   TRY_SET_BRANCH("HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8", &HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8, &b_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8);
   TRY_SET_BRANCH("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8", &HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8, &b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8);
   TRY_SET_BRANCH("HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8", &HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8, &b_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8);
   TRY_SET_BRANCH("HLT_Mu25_TkMu0_Onia", &HLT_Mu25_TkMu0_Onia, &b_HLT_Mu25_TkMu0_Onia);
   TRY_SET_BRANCH("HLT_Mu30_TkMu0_Psi", &HLT_Mu30_TkMu0_Psi, &b_HLT_Mu30_TkMu0_Psi);
   TRY_SET_BRANCH("HLT_Mu30_TkMu0_Upsilon", &HLT_Mu30_TkMu0_Upsilon, &b_HLT_Mu30_TkMu0_Upsilon);
   TRY_SET_BRANCH("HLT_Mu20_TkMu0_Phi", &HLT_Mu20_TkMu0_Phi, &b_HLT_Mu20_TkMu0_Phi);
   TRY_SET_BRANCH("HLT_Mu25_TkMu0_Phi", &HLT_Mu25_TkMu0_Phi, &b_HLT_Mu25_TkMu0_Phi);
   TRY_SET_BRANCH("HLT_Mu12", &HLT_Mu12, &b_HLT_Mu12);
   TRY_SET_BRANCH("HLT_Mu15", &HLT_Mu15, &b_HLT_Mu15);
   TRY_SET_BRANCH("HLT_Mu20", &HLT_Mu20, &b_HLT_Mu20);
   TRY_SET_BRANCH("HLT_Mu27", &HLT_Mu27, &b_HLT_Mu27);
   TRY_SET_BRANCH("HLT_Mu50", &HLT_Mu50, &b_HLT_Mu50);
   TRY_SET_BRANCH("HLT_Mu55", &HLT_Mu55, &b_HLT_Mu55);
   TRY_SET_BRANCH("HLT_OldMu100", &HLT_OldMu100, &b_HLT_OldMu100);
   TRY_SET_BRANCH("HLT_TkMu100", &HLT_TkMu100, &b_HLT_TkMu100);
   TRY_SET_BRANCH("HLT_DiPFJetAve40", &HLT_DiPFJetAve40, &b_HLT_DiPFJetAve40);
   TRY_SET_BRANCH("HLT_DiPFJetAve60", &HLT_DiPFJetAve60, &b_HLT_DiPFJetAve60);
   TRY_SET_BRANCH("HLT_DiPFJetAve80", &HLT_DiPFJetAve80, &b_HLT_DiPFJetAve80);
   TRY_SET_BRANCH("HLT_DiPFJetAve140", &HLT_DiPFJetAve140, &b_HLT_DiPFJetAve140);
   TRY_SET_BRANCH("HLT_DiPFJetAve200", &HLT_DiPFJetAve200, &b_HLT_DiPFJetAve200);
   TRY_SET_BRANCH("HLT_DiPFJetAve260", &HLT_DiPFJetAve260, &b_HLT_DiPFJetAve260);
   TRY_SET_BRANCH("HLT_DiPFJetAve320", &HLT_DiPFJetAve320, &b_HLT_DiPFJetAve320);
   TRY_SET_BRANCH("HLT_DiPFJetAve400", &HLT_DiPFJetAve400, &b_HLT_DiPFJetAve400);
   TRY_SET_BRANCH("HLT_DiPFJetAve500", &HLT_DiPFJetAve500, &b_HLT_DiPFJetAve500);
   TRY_SET_BRANCH("HLT_DiPFJetAve60_HFJEC", &HLT_DiPFJetAve60_HFJEC, &b_HLT_DiPFJetAve60_HFJEC);
   TRY_SET_BRANCH("HLT_DiPFJetAve80_HFJEC", &HLT_DiPFJetAve80_HFJEC, &b_HLT_DiPFJetAve80_HFJEC);
   TRY_SET_BRANCH("HLT_DiPFJetAve100_HFJEC", &HLT_DiPFJetAve100_HFJEC, &b_HLT_DiPFJetAve100_HFJEC);
   TRY_SET_BRANCH("HLT_DiPFJetAve160_HFJEC", &HLT_DiPFJetAve160_HFJEC, &b_HLT_DiPFJetAve160_HFJEC);
   TRY_SET_BRANCH("HLT_DiPFJetAve220_HFJEC", &HLT_DiPFJetAve220_HFJEC, &b_HLT_DiPFJetAve220_HFJEC);
   TRY_SET_BRANCH("HLT_DiPFJetAve300_HFJEC", &HLT_DiPFJetAve300_HFJEC, &b_HLT_DiPFJetAve300_HFJEC);
   TRY_SET_BRANCH("HLT_AK8PFJet15", &HLT_AK8PFJet15, &b_HLT_AK8PFJet15);
   TRY_SET_BRANCH("HLT_AK8PFJet25", &HLT_AK8PFJet25, &b_HLT_AK8PFJet25);
   TRY_SET_BRANCH("HLT_AK8PFJet40", &HLT_AK8PFJet40, &b_HLT_AK8PFJet40);
   TRY_SET_BRANCH("HLT_AK8PFJet60", &HLT_AK8PFJet60, &b_HLT_AK8PFJet60);
   TRY_SET_BRANCH("HLT_AK8PFJet80", &HLT_AK8PFJet80, &b_HLT_AK8PFJet80);
   TRY_SET_BRANCH("HLT_AK8PFJet140", &HLT_AK8PFJet140, &b_HLT_AK8PFJet140);
   TRY_SET_BRANCH("HLT_AK8PFJet200", &HLT_AK8PFJet200, &b_HLT_AK8PFJet200);
   TRY_SET_BRANCH("HLT_AK8PFJet260", &HLT_AK8PFJet260, &b_HLT_AK8PFJet260);
   TRY_SET_BRANCH("HLT_AK8PFJet320", &HLT_AK8PFJet320, &b_HLT_AK8PFJet320);
   TRY_SET_BRANCH("HLT_AK8PFJet400", &HLT_AK8PFJet400, &b_HLT_AK8PFJet400);
   TRY_SET_BRANCH("HLT_AK8PFJet450", &HLT_AK8PFJet450, &b_HLT_AK8PFJet450);
   TRY_SET_BRANCH("HLT_AK8PFJet500", &HLT_AK8PFJet500, &b_HLT_AK8PFJet500);
   TRY_SET_BRANCH("HLT_AK8PFJet550", &HLT_AK8PFJet550, &b_HLT_AK8PFJet550);
   TRY_SET_BRANCH("HLT_PFJet15", &HLT_PFJet15, &b_HLT_PFJet15);
   TRY_SET_BRANCH("HLT_PFJet25", &HLT_PFJet25, &b_HLT_PFJet25);
   TRY_SET_BRANCH("HLT_PFJet40", &HLT_PFJet40, &b_HLT_PFJet40);
   TRY_SET_BRANCH("HLT_PFJet60", &HLT_PFJet60, &b_HLT_PFJet60);
   TRY_SET_BRANCH("HLT_PFJet80", &HLT_PFJet80, &b_HLT_PFJet80);
   TRY_SET_BRANCH("HLT_PFJet140", &HLT_PFJet140, &b_HLT_PFJet140);
   TRY_SET_BRANCH("HLT_PFJet200", &HLT_PFJet200, &b_HLT_PFJet200);
   TRY_SET_BRANCH("HLT_PFJet260", &HLT_PFJet260, &b_HLT_PFJet260);
   TRY_SET_BRANCH("HLT_PFJet320", &HLT_PFJet320, &b_HLT_PFJet320);
   TRY_SET_BRANCH("HLT_PFJet400", &HLT_PFJet400, &b_HLT_PFJet400);
   TRY_SET_BRANCH("HLT_PFJet450", &HLT_PFJet450, &b_HLT_PFJet450);
   TRY_SET_BRANCH("HLT_PFJet500", &HLT_PFJet500, &b_HLT_PFJet500);
   TRY_SET_BRANCH("HLT_PFJet550", &HLT_PFJet550, &b_HLT_PFJet550);
   TRY_SET_BRANCH("HLT_PFJetFwd15", &HLT_PFJetFwd15, &b_HLT_PFJetFwd15);
   TRY_SET_BRANCH("HLT_PFJetFwd25", &HLT_PFJetFwd25, &b_HLT_PFJetFwd25);
   TRY_SET_BRANCH("HLT_PFJetFwd40", &HLT_PFJetFwd40, &b_HLT_PFJetFwd40);
   TRY_SET_BRANCH("HLT_PFJetFwd60", &HLT_PFJetFwd60, &b_HLT_PFJetFwd60);
   TRY_SET_BRANCH("HLT_PFJetFwd80", &HLT_PFJetFwd80, &b_HLT_PFJetFwd80);
   TRY_SET_BRANCH("HLT_PFJetFwd140", &HLT_PFJetFwd140, &b_HLT_PFJetFwd140);
   TRY_SET_BRANCH("HLT_PFJetFwd200", &HLT_PFJetFwd200, &b_HLT_PFJetFwd200);
   TRY_SET_BRANCH("HLT_PFJetFwd260", &HLT_PFJetFwd260, &b_HLT_PFJetFwd260);
   TRY_SET_BRANCH("HLT_PFJetFwd320", &HLT_PFJetFwd320, &b_HLT_PFJetFwd320);
   TRY_SET_BRANCH("HLT_PFJetFwd400", &HLT_PFJetFwd400, &b_HLT_PFJetFwd400);
   TRY_SET_BRANCH("HLT_PFJetFwd450", &HLT_PFJetFwd450, &b_HLT_PFJetFwd450);
   TRY_SET_BRANCH("HLT_PFJetFwd500", &HLT_PFJetFwd500, &b_HLT_PFJetFwd500);
   TRY_SET_BRANCH("HLT_AK8PFJetFwd15", &HLT_AK8PFJetFwd15, &b_HLT_AK8PFJetFwd15);
   TRY_SET_BRANCH("HLT_AK8PFJetFwd25", &HLT_AK8PFJetFwd25, &b_HLT_AK8PFJetFwd25);
   TRY_SET_BRANCH("HLT_AK8PFJetFwd40", &HLT_AK8PFJetFwd40, &b_HLT_AK8PFJetFwd40);
   TRY_SET_BRANCH("HLT_AK8PFJetFwd60", &HLT_AK8PFJetFwd60, &b_HLT_AK8PFJetFwd60);
   TRY_SET_BRANCH("HLT_AK8PFJetFwd80", &HLT_AK8PFJetFwd80, &b_HLT_AK8PFJetFwd80);
   TRY_SET_BRANCH("HLT_AK8PFJetFwd140", &HLT_AK8PFJetFwd140, &b_HLT_AK8PFJetFwd140);
   TRY_SET_BRANCH("HLT_AK8PFJetFwd200", &HLT_AK8PFJetFwd200, &b_HLT_AK8PFJetFwd200);
   TRY_SET_BRANCH("HLT_AK8PFJetFwd260", &HLT_AK8PFJetFwd260, &b_HLT_AK8PFJetFwd260);
   TRY_SET_BRANCH("HLT_AK8PFJetFwd320", &HLT_AK8PFJetFwd320, &b_HLT_AK8PFJetFwd320);
   TRY_SET_BRANCH("HLT_AK8PFJetFwd400", &HLT_AK8PFJetFwd400, &b_HLT_AK8PFJetFwd400);
   TRY_SET_BRANCH("HLT_AK8PFJetFwd450", &HLT_AK8PFJetFwd450, &b_HLT_AK8PFJetFwd450);
   TRY_SET_BRANCH("HLT_AK8PFJetFwd500", &HLT_AK8PFJetFwd500, &b_HLT_AK8PFJetFwd500);
   TRY_SET_BRANCH("HLT_PFHT180", &HLT_PFHT180, &b_HLT_PFHT180);
   TRY_SET_BRANCH("HLT_PFHT250", &HLT_PFHT250, &b_HLT_PFHT250);
   TRY_SET_BRANCH("HLT_PFHT370", &HLT_PFHT370, &b_HLT_PFHT370);
   TRY_SET_BRANCH("HLT_PFHT430", &HLT_PFHT430, &b_HLT_PFHT430);
   TRY_SET_BRANCH("HLT_PFHT510", &HLT_PFHT510, &b_HLT_PFHT510);
   TRY_SET_BRANCH("HLT_PFHT590", &HLT_PFHT590, &b_HLT_PFHT590);
   TRY_SET_BRANCH("HLT_PFHT680", &HLT_PFHT680, &b_HLT_PFHT680);
   TRY_SET_BRANCH("HLT_PFHT780", &HLT_PFHT780, &b_HLT_PFHT780);
   TRY_SET_BRANCH("HLT_PFHT890", &HLT_PFHT890, &b_HLT_PFHT890);
   TRY_SET_BRANCH("HLT_PFHT1050", &HLT_PFHT1050, &b_HLT_PFHT1050);
   TRY_SET_BRANCH("HLT_PFHT500_PFMET100_PFMHT100_IDTight", &HLT_PFHT500_PFMET100_PFMHT100_IDTight, &b_HLT_PFHT500_PFMET100_PFMHT100_IDTight);
   TRY_SET_BRANCH("HLT_PFHT500_PFMET110_PFMHT110_IDTight", &HLT_PFHT500_PFMET110_PFMHT110_IDTight, &b_HLT_PFHT500_PFMET110_PFMHT110_IDTight);
   TRY_SET_BRANCH("HLT_PFHT700_PFMET85_PFMHT85_IDTight", &HLT_PFHT700_PFMET85_PFMHT85_IDTight, &b_HLT_PFHT700_PFMET85_PFMHT85_IDTight);
   TRY_SET_BRANCH("HLT_PFHT700_PFMET95_PFMHT95_IDTight", &HLT_PFHT700_PFMET95_PFMHT95_IDTight, &b_HLT_PFHT700_PFMET95_PFMHT95_IDTight);
   TRY_SET_BRANCH("HLT_PFHT800_PFMET75_PFMHT75_IDTight", &HLT_PFHT800_PFMET75_PFMHT75_IDTight, &b_HLT_PFHT800_PFMET75_PFMHT75_IDTight);
   TRY_SET_BRANCH("HLT_PFHT800_PFMET85_PFMHT85_IDTight", &HLT_PFHT800_PFMET85_PFMHT85_IDTight, &b_HLT_PFHT800_PFMET85_PFMHT85_IDTight);
   TRY_SET_BRANCH("HLT_PFMET110_PFMHT110_IDTight", &HLT_PFMET110_PFMHT110_IDTight, &b_HLT_PFMET110_PFMHT110_IDTight);
   TRY_SET_BRANCH("HLT_PFMET120_PFMHT120_IDTight", &HLT_PFMET120_PFMHT120_IDTight, &b_HLT_PFMET120_PFMHT120_IDTight);
   TRY_SET_BRANCH("HLT_PFMET130_PFMHT130_IDTight", &HLT_PFMET130_PFMHT130_IDTight, &b_HLT_PFMET130_PFMHT130_IDTight);
   TRY_SET_BRANCH("HLT_PFMET140_PFMHT140_IDTight", &HLT_PFMET140_PFMHT140_IDTight, &b_HLT_PFMET140_PFMHT140_IDTight);
   TRY_SET_BRANCH("HLT_PFMET100_PFMHT100_IDTight_CaloBTagDeepCSV_3p1", &HLT_PFMET100_PFMHT100_IDTight_CaloBTagDeepCSV_3p1, &b_HLT_PFMET100_PFMHT100_IDTight_CaloBTagDeepCSV_3p1);
   TRY_SET_BRANCH("HLT_PFMET110_PFMHT110_IDTight_CaloBTagDeepCSV_3p1", &HLT_PFMET110_PFMHT110_IDTight_CaloBTagDeepCSV_3p1, &b_HLT_PFMET110_PFMHT110_IDTight_CaloBTagDeepCSV_3p1);
   TRY_SET_BRANCH("HLT_PFMET120_PFMHT120_IDTight_CaloBTagDeepCSV_3p1", &HLT_PFMET120_PFMHT120_IDTight_CaloBTagDeepCSV_3p1, &b_HLT_PFMET120_PFMHT120_IDTight_CaloBTagDeepCSV_3p1);
   TRY_SET_BRANCH("HLT_PFMET130_PFMHT130_IDTight_CaloBTagDeepCSV_3p1", &HLT_PFMET130_PFMHT130_IDTight_CaloBTagDeepCSV_3p1, &b_HLT_PFMET130_PFMHT130_IDTight_CaloBTagDeepCSV_3p1);
   TRY_SET_BRANCH("HLT_PFMET140_PFMHT140_IDTight_CaloBTagDeepCSV_3p1", &HLT_PFMET140_PFMHT140_IDTight_CaloBTagDeepCSV_3p1, &b_HLT_PFMET140_PFMHT140_IDTight_CaloBTagDeepCSV_3p1);
   TRY_SET_BRANCH("HLT_PFMET120_PFMHT120_IDTight_PFHT60", &HLT_PFMET120_PFMHT120_IDTight_PFHT60, &b_HLT_PFMET120_PFMHT120_IDTight_PFHT60);
   TRY_SET_BRANCH("HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60", &HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60, &b_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60);
   TRY_SET_BRANCH("HLT_PFMETTypeOne120_PFMHT120_IDTight_PFHT60", &HLT_PFMETTypeOne120_PFMHT120_IDTight_PFHT60, &b_HLT_PFMETTypeOne120_PFMHT120_IDTight_PFHT60);
   TRY_SET_BRANCH("HLT_PFMETTypeOne110_PFMHT110_IDTight", &HLT_PFMETTypeOne110_PFMHT110_IDTight, &b_HLT_PFMETTypeOne110_PFMHT110_IDTight);
   TRY_SET_BRANCH("HLT_PFMETTypeOne120_PFMHT120_IDTight", &HLT_PFMETTypeOne120_PFMHT120_IDTight, &b_HLT_PFMETTypeOne120_PFMHT120_IDTight);
   TRY_SET_BRANCH("HLT_PFMETTypeOne130_PFMHT130_IDTight", &HLT_PFMETTypeOne130_PFMHT130_IDTight, &b_HLT_PFMETTypeOne130_PFMHT130_IDTight);
   TRY_SET_BRANCH("HLT_PFMETTypeOne140_PFMHT140_IDTight", &HLT_PFMETTypeOne140_PFMHT140_IDTight, &b_HLT_PFMETTypeOne140_PFMHT140_IDTight);
   TRY_SET_BRANCH("HLT_PFMETNoMu110_PFMHTNoMu110_IDTight", &HLT_PFMETNoMu110_PFMHTNoMu110_IDTight, &b_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight);
   TRY_SET_BRANCH("HLT_PFMETNoMu120_PFMHTNoMu120_IDTight", &HLT_PFMETNoMu120_PFMHTNoMu120_IDTight, &b_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight);
   TRY_SET_BRANCH("HLT_PFMETNoMu130_PFMHTNoMu130_IDTight", &HLT_PFMETNoMu130_PFMHTNoMu130_IDTight, &b_HLT_PFMETNoMu130_PFMHTNoMu130_IDTight);
   TRY_SET_BRANCH("HLT_PFMETNoMu140_PFMHTNoMu140_IDTight", &HLT_PFMETNoMu140_PFMHTNoMu140_IDTight, &b_HLT_PFMETNoMu140_PFMHTNoMu140_IDTight);
   TRY_SET_BRANCH("HLT_MonoCentralPFJet80_PFMETNoMu110_PFMHTNoMu110_IDTight", &HLT_MonoCentralPFJet80_PFMETNoMu110_PFMHTNoMu110_IDTight, &b_HLT_MonoCentralPFJet80_PFMETNoMu110_PFMHTNoMu110_IDTight);
   TRY_SET_BRANCH("HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight", &HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight, &b_HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight);
   TRY_SET_BRANCH("HLT_MonoCentralPFJet80_PFMETNoMu130_PFMHTNoMu130_IDTight", &HLT_MonoCentralPFJet80_PFMETNoMu130_PFMHTNoMu130_IDTight, &b_HLT_MonoCentralPFJet80_PFMETNoMu130_PFMHTNoMu130_IDTight);
   TRY_SET_BRANCH("HLT_MonoCentralPFJet80_PFMETNoMu140_PFMHTNoMu140_IDTight", &HLT_MonoCentralPFJet80_PFMETNoMu140_PFMHTNoMu140_IDTight, &b_HLT_MonoCentralPFJet80_PFMETNoMu140_PFMHTNoMu140_IDTight);
   TRY_SET_BRANCH("HLT_L1ETMHadSeeds", &HLT_L1ETMHadSeeds, &b_HLT_L1ETMHadSeeds);
   TRY_SET_BRANCH("HLT_CaloMHT90", &HLT_CaloMHT90, &b_HLT_CaloMHT90);
   TRY_SET_BRANCH("HLT_CaloMET80_NotCleaned", &HLT_CaloMET80_NotCleaned, &b_HLT_CaloMET80_NotCleaned);
   TRY_SET_BRANCH("HLT_CaloMET90_NotCleaned", &HLT_CaloMET90_NotCleaned, &b_HLT_CaloMET90_NotCleaned);
   TRY_SET_BRANCH("HLT_CaloMET100_NotCleaned", &HLT_CaloMET100_NotCleaned, &b_HLT_CaloMET100_NotCleaned);
   TRY_SET_BRANCH("HLT_CaloMET110_NotCleaned", &HLT_CaloMET110_NotCleaned, &b_HLT_CaloMET110_NotCleaned);
   TRY_SET_BRANCH("HLT_CaloMET250_NotCleaned", &HLT_CaloMET250_NotCleaned, &b_HLT_CaloMET250_NotCleaned);
   TRY_SET_BRANCH("HLT_CaloMET70_HBHECleaned", &HLT_CaloMET70_HBHECleaned, &b_HLT_CaloMET70_HBHECleaned);
   TRY_SET_BRANCH("HLT_CaloMET80_HBHECleaned", &HLT_CaloMET80_HBHECleaned, &b_HLT_CaloMET80_HBHECleaned);
   TRY_SET_BRANCH("HLT_CaloMET90_HBHECleaned", &HLT_CaloMET90_HBHECleaned, &b_HLT_CaloMET90_HBHECleaned);
   TRY_SET_BRANCH("HLT_CaloMET100_HBHECleaned", &HLT_CaloMET100_HBHECleaned, &b_HLT_CaloMET100_HBHECleaned);
   TRY_SET_BRANCH("HLT_CaloMET250_HBHECleaned", &HLT_CaloMET250_HBHECleaned, &b_HLT_CaloMET250_HBHECleaned);
   TRY_SET_BRANCH("HLT_CaloMET300_HBHECleaned", &HLT_CaloMET300_HBHECleaned, &b_HLT_CaloMET300_HBHECleaned);
   TRY_SET_BRANCH("HLT_CaloMET350_HBHECleaned", &HLT_CaloMET350_HBHECleaned, &b_HLT_CaloMET350_HBHECleaned);
   TRY_SET_BRANCH("HLT_PFMET200_NotCleaned", &HLT_PFMET200_NotCleaned, &b_HLT_PFMET200_NotCleaned);
   TRY_SET_BRANCH("HLT_PFMET200_HBHECleaned", &HLT_PFMET200_HBHECleaned, &b_HLT_PFMET200_HBHECleaned);
   TRY_SET_BRANCH("HLT_PFMET250_HBHECleaned", &HLT_PFMET250_HBHECleaned, &b_HLT_PFMET250_HBHECleaned);
   TRY_SET_BRANCH("HLT_PFMET300_HBHECleaned", &HLT_PFMET300_HBHECleaned, &b_HLT_PFMET300_HBHECleaned);
   TRY_SET_BRANCH("HLT_PFMET200_HBHE_BeamHaloCleaned", &HLT_PFMET200_HBHE_BeamHaloCleaned, &b_HLT_PFMET200_HBHE_BeamHaloCleaned);
   TRY_SET_BRANCH("HLT_PFMETTypeOne200_HBHE_BeamHaloCleaned", &HLT_PFMETTypeOne200_HBHE_BeamHaloCleaned, &b_HLT_PFMETTypeOne200_HBHE_BeamHaloCleaned);
   TRY_SET_BRANCH("HLT_MET105_IsoTrk50", &HLT_MET105_IsoTrk50, &b_HLT_MET105_IsoTrk50);
   TRY_SET_BRANCH("HLT_MET120_IsoTrk50", &HLT_MET120_IsoTrk50, &b_HLT_MET120_IsoTrk50);
   TRY_SET_BRANCH("HLT_SingleJet30_Mu12_SinglePFJet40", &HLT_SingleJet30_Mu12_SinglePFJet40, &b_HLT_SingleJet30_Mu12_SinglePFJet40);
   TRY_SET_BRANCH("HLT_Mu12_DoublePFJets40_CaloBTagDeepCSV_p71", &HLT_Mu12_DoublePFJets40_CaloBTagDeepCSV_p71, &b_HLT_Mu12_DoublePFJets40_CaloBTagDeepCSV_p71);
   TRY_SET_BRANCH("HLT_Mu12_DoublePFJets100_CaloBTagDeepCSV_p71", &HLT_Mu12_DoublePFJets100_CaloBTagDeepCSV_p71, &b_HLT_Mu12_DoublePFJets100_CaloBTagDeepCSV_p71);
   TRY_SET_BRANCH("HLT_Mu12_DoublePFJets200_CaloBTagDeepCSV_p71", &HLT_Mu12_DoublePFJets200_CaloBTagDeepCSV_p71, &b_HLT_Mu12_DoublePFJets200_CaloBTagDeepCSV_p71);
   TRY_SET_BRANCH("HLT_Mu12_DoublePFJets350_CaloBTagDeepCSV_p71", &HLT_Mu12_DoublePFJets350_CaloBTagDeepCSV_p71, &b_HLT_Mu12_DoublePFJets350_CaloBTagDeepCSV_p71);
   TRY_SET_BRANCH("HLT_Mu12_DoublePFJets40MaxDeta1p6_DoubleCaloBTagDeepCSV_p71", &HLT_Mu12_DoublePFJets40MaxDeta1p6_DoubleCaloBTagDeepCSV_p71, &b_HLT_Mu12_DoublePFJets40MaxDeta1p6_DoubleCaloBTagDeepCSV_p71);
   TRY_SET_BRANCH("HLT_Mu12_DoublePFJets54MaxDeta1p6_DoubleCaloBTagDeepCSV_p71", &HLT_Mu12_DoublePFJets54MaxDeta1p6_DoubleCaloBTagDeepCSV_p71, &b_HLT_Mu12_DoublePFJets54MaxDeta1p6_DoubleCaloBTagDeepCSV_p71);
   TRY_SET_BRANCH("HLT_Mu12_DoublePFJets62MaxDeta1p6_DoubleCaloBTagDeepCSV_p71", &HLT_Mu12_DoublePFJets62MaxDeta1p6_DoubleCaloBTagDeepCSV_p71, &b_HLT_Mu12_DoublePFJets62MaxDeta1p6_DoubleCaloBTagDeepCSV_p71);
   TRY_SET_BRANCH("HLT_DoublePFJets40_CaloBTagDeepCSV_p71", &HLT_DoublePFJets40_CaloBTagDeepCSV_p71, &b_HLT_DoublePFJets40_CaloBTagDeepCSV_p71);
   TRY_SET_BRANCH("HLT_DoublePFJets100_CaloBTagDeepCSV_p71", &HLT_DoublePFJets100_CaloBTagDeepCSV_p71, &b_HLT_DoublePFJets100_CaloBTagDeepCSV_p71);
   TRY_SET_BRANCH("HLT_DoublePFJets200_CaloBTagDeepCSV_p71", &HLT_DoublePFJets200_CaloBTagDeepCSV_p71, &b_HLT_DoublePFJets200_CaloBTagDeepCSV_p71);
   TRY_SET_BRANCH("HLT_DoublePFJets350_CaloBTagDeepCSV_p71", &HLT_DoublePFJets350_CaloBTagDeepCSV_p71, &b_HLT_DoublePFJets350_CaloBTagDeepCSV_p71);
   TRY_SET_BRANCH("HLT_DoublePFJets116MaxDeta1p6_DoubleCaloBTagDeepCSV_p71", &HLT_DoublePFJets116MaxDeta1p6_DoubleCaloBTagDeepCSV_p71, &b_HLT_DoublePFJets116MaxDeta1p6_DoubleCaloBTagDeepCSV_p71);
   TRY_SET_BRANCH("HLT_DoublePFJets128MaxDeta1p6_DoubleCaloBTagDeepCSV_p71", &HLT_DoublePFJets128MaxDeta1p6_DoubleCaloBTagDeepCSV_p71, &b_HLT_DoublePFJets128MaxDeta1p6_DoubleCaloBTagDeepCSV_p71);
   TRY_SET_BRANCH("HLT_Photon300_NoHE", &HLT_Photon300_NoHE, &b_HLT_Photon300_NoHE);
   TRY_SET_BRANCH("HLT_Mu8_TrkIsoVVL", &HLT_Mu8_TrkIsoVVL, &b_HLT_Mu8_TrkIsoVVL);
   TRY_SET_BRANCH("HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ", &HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ, &b_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ);
   TRY_SET_BRANCH("HLT_Mu8_DiEle12_CaloIdL_TrackIdL", &HLT_Mu8_DiEle12_CaloIdL_TrackIdL, &b_HLT_Mu8_DiEle12_CaloIdL_TrackIdL);
   TRY_SET_BRANCH("HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ", &HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ, &b_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ);
   TRY_SET_BRANCH("HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350", &HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350, &b_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350);
   TRY_SET_BRANCH("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ", &HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ, &b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ);
   TRY_SET_BRANCH("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30", &HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30, &b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30);
   TRY_SET_BRANCH("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_CaloDiJet30", &HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_CaloDiJet30, &b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_CaloDiJet30);
   TRY_SET_BRANCH("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBtagDeepCSV_1p5", &HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBtagDeepCSV_1p5, &b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBtagDeepCSV_1p5);
   TRY_SET_BRANCH("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_CaloDiJet30_CaloBtagDeepCSV_1p5", &HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_CaloDiJet30_CaloBtagDeepCSV_1p5, &b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_CaloDiJet30_CaloBtagDeepCSV_1p5);
   TRY_SET_BRANCH("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL", &HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL, &b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL);
   TRY_SET_BRANCH("HLT_Mu17_TrkIsoVVL", &HLT_Mu17_TrkIsoVVL, &b_HLT_Mu17_TrkIsoVVL);
   TRY_SET_BRANCH("HLT_Mu19_TrkIsoVVL", &HLT_Mu19_TrkIsoVVL, &b_HLT_Mu19_TrkIsoVVL);
   TRY_SET_BRANCH("HLT_BTagMu_AK4DiJet20_Mu5", &HLT_BTagMu_AK4DiJet20_Mu5, &b_HLT_BTagMu_AK4DiJet20_Mu5);
   TRY_SET_BRANCH("HLT_BTagMu_AK4DiJet40_Mu5", &HLT_BTagMu_AK4DiJet40_Mu5, &b_HLT_BTagMu_AK4DiJet40_Mu5);
   TRY_SET_BRANCH("HLT_BTagMu_AK4DiJet70_Mu5", &HLT_BTagMu_AK4DiJet70_Mu5, &b_HLT_BTagMu_AK4DiJet70_Mu5);
   TRY_SET_BRANCH("HLT_BTagMu_AK4DiJet110_Mu5", &HLT_BTagMu_AK4DiJet110_Mu5, &b_HLT_BTagMu_AK4DiJet110_Mu5);
   TRY_SET_BRANCH("HLT_BTagMu_AK4DiJet170_Mu5", &HLT_BTagMu_AK4DiJet170_Mu5, &b_HLT_BTagMu_AK4DiJet170_Mu5);
   TRY_SET_BRANCH("HLT_BTagMu_AK4Jet300_Mu5", &HLT_BTagMu_AK4Jet300_Mu5, &b_HLT_BTagMu_AK4Jet300_Mu5);
   TRY_SET_BRANCH("HLT_BTagMu_AK8DiJet170_Mu5", &HLT_BTagMu_AK8DiJet170_Mu5, &b_HLT_BTagMu_AK8DiJet170_Mu5);
   TRY_SET_BRANCH("HLT_BTagMu_AK8Jet170_DoubleMu5", &HLT_BTagMu_AK8Jet170_DoubleMu5, &b_HLT_BTagMu_AK8Jet170_DoubleMu5);
   TRY_SET_BRANCH("HLT_BTagMu_AK8Jet300_Mu5", &HLT_BTagMu_AK8Jet300_Mu5, &b_HLT_BTagMu_AK8Jet300_Mu5);
   TRY_SET_BRANCH("HLT_BTagMu_AK4DiJet20_Mu5_noalgo", &HLT_BTagMu_AK4DiJet20_Mu5_noalgo, &b_HLT_BTagMu_AK4DiJet20_Mu5_noalgo);
   TRY_SET_BRANCH("HLT_BTagMu_AK4DiJet40_Mu5_noalgo", &HLT_BTagMu_AK4DiJet40_Mu5_noalgo, &b_HLT_BTagMu_AK4DiJet40_Mu5_noalgo);
   TRY_SET_BRANCH("HLT_BTagMu_AK4DiJet70_Mu5_noalgo", &HLT_BTagMu_AK4DiJet70_Mu5_noalgo, &b_HLT_BTagMu_AK4DiJet70_Mu5_noalgo);
   TRY_SET_BRANCH("HLT_BTagMu_AK4DiJet110_Mu5_noalgo", &HLT_BTagMu_AK4DiJet110_Mu5_noalgo, &b_HLT_BTagMu_AK4DiJet110_Mu5_noalgo);
   TRY_SET_BRANCH("HLT_BTagMu_AK4DiJet170_Mu5_noalgo", &HLT_BTagMu_AK4DiJet170_Mu5_noalgo, &b_HLT_BTagMu_AK4DiJet170_Mu5_noalgo);
   TRY_SET_BRANCH("HLT_BTagMu_AK4Jet300_Mu5_noalgo", &HLT_BTagMu_AK4Jet300_Mu5_noalgo, &b_HLT_BTagMu_AK4Jet300_Mu5_noalgo);
   TRY_SET_BRANCH("HLT_BTagMu_AK8DiJet170_Mu5_noalgo", &HLT_BTagMu_AK8DiJet170_Mu5_noalgo, &b_HLT_BTagMu_AK8DiJet170_Mu5_noalgo);
   TRY_SET_BRANCH("HLT_BTagMu_AK8Jet170_DoubleMu5_noalgo", &HLT_BTagMu_AK8Jet170_DoubleMu5_noalgo, &b_HLT_BTagMu_AK8Jet170_DoubleMu5_noalgo);
   TRY_SET_BRANCH("HLT_BTagMu_AK8Jet300_Mu5_noalgo", &HLT_BTagMu_AK8Jet300_Mu5_noalgo, &b_HLT_BTagMu_AK8Jet300_Mu5_noalgo);
   TRY_SET_BRANCH("HLT_Ele15_Ele8_CaloIdL_TrackIdL_IsoVL", &HLT_Ele15_Ele8_CaloIdL_TrackIdL_IsoVL, &b_HLT_Ele15_Ele8_CaloIdL_TrackIdL_IsoVL);
   TRY_SET_BRANCH("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ", &HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ, &b_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ);
   TRY_SET_BRANCH("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL", &HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL, &b_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL);
   TRY_SET_BRANCH("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ", &HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ, &b_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ);
   TRY_SET_BRANCH("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL", &HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL, &b_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL);
   TRY_SET_BRANCH("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL", &HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL, &b_HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL);
   TRY_SET_BRANCH("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ", &HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ, &b_HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ);
   TRY_SET_BRANCH("HLT_Mu12_DoublePhoton20", &HLT_Mu12_DoublePhoton20, &b_HLT_Mu12_DoublePhoton20);
   TRY_SET_BRANCH("HLT_TriplePhoton_20_20_20_CaloIdLV2", &HLT_TriplePhoton_20_20_20_CaloIdLV2, &b_HLT_TriplePhoton_20_20_20_CaloIdLV2);
   TRY_SET_BRANCH("HLT_TriplePhoton_20_20_20_CaloIdLV2_R9IdVL", &HLT_TriplePhoton_20_20_20_CaloIdLV2_R9IdVL, &b_HLT_TriplePhoton_20_20_20_CaloIdLV2_R9IdVL);
   TRY_SET_BRANCH("HLT_TriplePhoton_30_30_10_CaloIdLV2", &HLT_TriplePhoton_30_30_10_CaloIdLV2, &b_HLT_TriplePhoton_30_30_10_CaloIdLV2);
   TRY_SET_BRANCH("HLT_TriplePhoton_30_30_10_CaloIdLV2_R9IdVL", &HLT_TriplePhoton_30_30_10_CaloIdLV2_R9IdVL, &b_HLT_TriplePhoton_30_30_10_CaloIdLV2_R9IdVL);
   TRY_SET_BRANCH("HLT_TriplePhoton_35_35_5_CaloIdLV2_R9IdVL", &HLT_TriplePhoton_35_35_5_CaloIdLV2_R9IdVL, &b_HLT_TriplePhoton_35_35_5_CaloIdLV2_R9IdVL);
   TRY_SET_BRANCH("HLT_Photon20", &HLT_Photon20, &b_HLT_Photon20);
   TRY_SET_BRANCH("HLT_Photon33", &HLT_Photon33, &b_HLT_Photon33);
   TRY_SET_BRANCH("HLT_Photon50", &HLT_Photon50, &b_HLT_Photon50);
   TRY_SET_BRANCH("HLT_Photon75", &HLT_Photon75, &b_HLT_Photon75);
   TRY_SET_BRANCH("HLT_Photon90", &HLT_Photon90, &b_HLT_Photon90);
   TRY_SET_BRANCH("HLT_Photon120", &HLT_Photon120, &b_HLT_Photon120);
   TRY_SET_BRANCH("HLT_Photon150", &HLT_Photon150, &b_HLT_Photon150);
   TRY_SET_BRANCH("HLT_Photon175", &HLT_Photon175, &b_HLT_Photon175);
   TRY_SET_BRANCH("HLT_Photon200", &HLT_Photon200, &b_HLT_Photon200);
   TRY_SET_BRANCH("HLT_Photon100EB_TightID_TightIso", &HLT_Photon100EB_TightID_TightIso, &b_HLT_Photon100EB_TightID_TightIso);
   TRY_SET_BRANCH("HLT_Photon110EB_TightID_TightIso", &HLT_Photon110EB_TightID_TightIso, &b_HLT_Photon110EB_TightID_TightIso);
   TRY_SET_BRANCH("HLT_Photon120EB_TightID_TightIso", &HLT_Photon120EB_TightID_TightIso, &b_HLT_Photon120EB_TightID_TightIso);
   TRY_SET_BRANCH("HLT_Photon100EBHE10", &HLT_Photon100EBHE10, &b_HLT_Photon100EBHE10);
   TRY_SET_BRANCH("HLT_Photon100EEHE10", &HLT_Photon100EEHE10, &b_HLT_Photon100EEHE10);
   TRY_SET_BRANCH("HLT_Photon100EE_TightID_TightIso", &HLT_Photon100EE_TightID_TightIso, &b_HLT_Photon100EE_TightID_TightIso);
   TRY_SET_BRANCH("HLT_Photon50_R9Id90_HE10_IsoM", &HLT_Photon50_R9Id90_HE10_IsoM, &b_HLT_Photon50_R9Id90_HE10_IsoM);
   TRY_SET_BRANCH("HLT_Photon75_R9Id90_HE10_IsoM", &HLT_Photon75_R9Id90_HE10_IsoM, &b_HLT_Photon75_R9Id90_HE10_IsoM);
   TRY_SET_BRANCH("HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_CaloMJJ300_PFJetsMJJ400DEta3", &HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_CaloMJJ300_PFJetsMJJ400DEta3, &b_HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_CaloMJJ300_PFJetsMJJ400DEta3);
   TRY_SET_BRANCH("HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_CaloMJJ400_PFJetsMJJ600DEta3", &HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_CaloMJJ400_PFJetsMJJ600DEta3, &b_HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_CaloMJJ400_PFJetsMJJ600DEta3);
   TRY_SET_BRANCH("HLT_Photon90_R9Id90_HE10_IsoM", &HLT_Photon90_R9Id90_HE10_IsoM, &b_HLT_Photon90_R9Id90_HE10_IsoM);
   TRY_SET_BRANCH("HLT_Photon120_R9Id90_HE10_IsoM", &HLT_Photon120_R9Id90_HE10_IsoM, &b_HLT_Photon120_R9Id90_HE10_IsoM);
   TRY_SET_BRANCH("HLT_Photon165_R9Id90_HE10_IsoM", &HLT_Photon165_R9Id90_HE10_IsoM, &b_HLT_Photon165_R9Id90_HE10_IsoM);
   TRY_SET_BRANCH("HLT_Photon90_CaloIdL_PFHT700", &HLT_Photon90_CaloIdL_PFHT700, &b_HLT_Photon90_CaloIdL_PFHT700);
   TRY_SET_BRANCH("HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90", &HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90, &b_HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90);
   TRY_SET_BRANCH("HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95", &HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95, &b_HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95);
   TRY_SET_BRANCH("HLT_DiphotonMVA14p25_Mass90", &HLT_DiphotonMVA14p25_Mass90, &b_HLT_DiphotonMVA14p25_Mass90);
   TRY_SET_BRANCH("HLT_DiphotonMVA14p25_Tight_Mass90", &HLT_DiphotonMVA14p25_Tight_Mass90, &b_HLT_DiphotonMVA14p25_Tight_Mass90);
   TRY_SET_BRANCH("HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55", &HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55, &b_HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55);
   TRY_SET_BRANCH("HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55", &HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55, &b_HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55);
   TRY_SET_BRANCH("HLT_Photon35_TwoProngs35", &HLT_Photon35_TwoProngs35, &b_HLT_Photon35_TwoProngs35);
   TRY_SET_BRANCH("HLT_IsoMu24_TwoProngs35", &HLT_IsoMu24_TwoProngs35, &b_HLT_IsoMu24_TwoProngs35);
   TRY_SET_BRANCH("HLT_Dimuon0_Jpsi_L1_NoOS", &HLT_Dimuon0_Jpsi_L1_NoOS, &b_HLT_Dimuon0_Jpsi_L1_NoOS);
   TRY_SET_BRANCH("HLT_Dimuon0_Jpsi_NoVertexing_NoOS", &HLT_Dimuon0_Jpsi_NoVertexing_NoOS, &b_HLT_Dimuon0_Jpsi_NoVertexing_NoOS);
   TRY_SET_BRANCH("HLT_Dimuon0_Jpsi", &HLT_Dimuon0_Jpsi, &b_HLT_Dimuon0_Jpsi);
   TRY_SET_BRANCH("HLT_Dimuon0_Jpsi_NoVertexing", &HLT_Dimuon0_Jpsi_NoVertexing, &b_HLT_Dimuon0_Jpsi_NoVertexing);
   TRY_SET_BRANCH("HLT_Dimuon0_Jpsi_L1_4R_0er1p5R", &HLT_Dimuon0_Jpsi_L1_4R_0er1p5R, &b_HLT_Dimuon0_Jpsi_L1_4R_0er1p5R);
   TRY_SET_BRANCH("HLT_Dimuon0_Jpsi_NoVertexing_L1_4R_0er1p5R", &HLT_Dimuon0_Jpsi_NoVertexing_L1_4R_0er1p5R, &b_HLT_Dimuon0_Jpsi_NoVertexing_L1_4R_0er1p5R);
   TRY_SET_BRANCH("HLT_Dimuon0_Jpsi3p5_Muon2", &HLT_Dimuon0_Jpsi3p5_Muon2, &b_HLT_Dimuon0_Jpsi3p5_Muon2);
   TRY_SET_BRANCH("HLT_Dimuon0_Upsilon_L1_4p5", &HLT_Dimuon0_Upsilon_L1_4p5, &b_HLT_Dimuon0_Upsilon_L1_4p5);
   TRY_SET_BRANCH("HLT_Dimuon0_Upsilon_L1_5", &HLT_Dimuon0_Upsilon_L1_5, &b_HLT_Dimuon0_Upsilon_L1_5);
   TRY_SET_BRANCH("HLT_Dimuon0_Upsilon_L1_4p5NoOS", &HLT_Dimuon0_Upsilon_L1_4p5NoOS, &b_HLT_Dimuon0_Upsilon_L1_4p5NoOS);
   TRY_SET_BRANCH("HLT_Dimuon0_Upsilon_L1_4p5er2p0", &HLT_Dimuon0_Upsilon_L1_4p5er2p0, &b_HLT_Dimuon0_Upsilon_L1_4p5er2p0);
   TRY_SET_BRANCH("HLT_Dimuon0_Upsilon_L1_4p5er2p0M", &HLT_Dimuon0_Upsilon_L1_4p5er2p0M, &b_HLT_Dimuon0_Upsilon_L1_4p5er2p0M);
   TRY_SET_BRANCH("HLT_Dimuon0_Upsilon_NoVertexing", &HLT_Dimuon0_Upsilon_NoVertexing, &b_HLT_Dimuon0_Upsilon_NoVertexing);
   TRY_SET_BRANCH("HLT_Dimuon0_Upsilon_L1_5M", &HLT_Dimuon0_Upsilon_L1_5M, &b_HLT_Dimuon0_Upsilon_L1_5M);
   TRY_SET_BRANCH("HLT_Dimuon0_LowMass_L1_0er1p5R", &HLT_Dimuon0_LowMass_L1_0er1p5R, &b_HLT_Dimuon0_LowMass_L1_0er1p5R);
   TRY_SET_BRANCH("HLT_Dimuon0_LowMass_L1_0er1p5", &HLT_Dimuon0_LowMass_L1_0er1p5, &b_HLT_Dimuon0_LowMass_L1_0er1p5);
   TRY_SET_BRANCH("HLT_Dimuon0_LowMass", &HLT_Dimuon0_LowMass, &b_HLT_Dimuon0_LowMass);
   TRY_SET_BRANCH("HLT_Dimuon0_LowMass_L1_4", &HLT_Dimuon0_LowMass_L1_4, &b_HLT_Dimuon0_LowMass_L1_4);
   TRY_SET_BRANCH("HLT_Dimuon0_LowMass_L1_4R", &HLT_Dimuon0_LowMass_L1_4R, &b_HLT_Dimuon0_LowMass_L1_4R);
   TRY_SET_BRANCH("HLT_Dimuon0_LowMass_L1_TM530", &HLT_Dimuon0_LowMass_L1_TM530, &b_HLT_Dimuon0_LowMass_L1_TM530);
   TRY_SET_BRANCH("HLT_Dimuon0_Upsilon_Muon_L1_TM0", &HLT_Dimuon0_Upsilon_Muon_L1_TM0, &b_HLT_Dimuon0_Upsilon_Muon_L1_TM0);
   TRY_SET_BRANCH("HLT_Dimuon0_Upsilon_Muon_NoL1Mass", &HLT_Dimuon0_Upsilon_Muon_NoL1Mass, &b_HLT_Dimuon0_Upsilon_Muon_NoL1Mass);
   TRY_SET_BRANCH("HLT_TripleMu_5_3_3_Mass3p8_DZ", &HLT_TripleMu_5_3_3_Mass3p8_DZ, &b_HLT_TripleMu_5_3_3_Mass3p8_DZ);
   TRY_SET_BRANCH("HLT_TripleMu_10_5_5_DZ", &HLT_TripleMu_10_5_5_DZ, &b_HLT_TripleMu_10_5_5_DZ);
   TRY_SET_BRANCH("HLT_TripleMu_12_10_5", &HLT_TripleMu_12_10_5, &b_HLT_TripleMu_12_10_5);
   TRY_SET_BRANCH("HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15", &HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15, &b_HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15);
   TRY_SET_BRANCH("HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15_Charge1", &HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15_Charge1, &b_HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15_Charge1);
   TRY_SET_BRANCH("HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15", &HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15, &b_HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15);
   TRY_SET_BRANCH("HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15_Charge1", &HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15_Charge1, &b_HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15_Charge1);
   TRY_SET_BRANCH("HLT_DoubleMu3_DZ_PFMET50_PFMHT60", &HLT_DoubleMu3_DZ_PFMET50_PFMHT60, &b_HLT_DoubleMu3_DZ_PFMET50_PFMHT60);
   TRY_SET_BRANCH("HLT_DoubleMu3_DZ_PFMET70_PFMHT70", &HLT_DoubleMu3_DZ_PFMET70_PFMHT70, &b_HLT_DoubleMu3_DZ_PFMET70_PFMHT70);
   TRY_SET_BRANCH("HLT_DoubleMu3_DZ_PFMET90_PFMHT90", &HLT_DoubleMu3_DZ_PFMET90_PFMHT90, &b_HLT_DoubleMu3_DZ_PFMET90_PFMHT90);
   TRY_SET_BRANCH("HLT_DoubleMu3_Trk_Tau3mu_NoL1Mass", &HLT_DoubleMu3_Trk_Tau3mu_NoL1Mass, &b_HLT_DoubleMu3_Trk_Tau3mu_NoL1Mass);
   TRY_SET_BRANCH("HLT_DoubleMu4_Jpsi_Displaced", &HLT_DoubleMu4_Jpsi_Displaced, &b_HLT_DoubleMu4_Jpsi_Displaced);
   TRY_SET_BRANCH("HLT_DoubleMu4_Jpsi_NoVertexing", &HLT_DoubleMu4_Jpsi_NoVertexing, &b_HLT_DoubleMu4_Jpsi_NoVertexing);
   TRY_SET_BRANCH("HLT_DoubleMu4_JpsiTrkTrk_Displaced", &HLT_DoubleMu4_JpsiTrkTrk_Displaced, &b_HLT_DoubleMu4_JpsiTrkTrk_Displaced);
   TRY_SET_BRANCH("HLT_DoubleMu43NoFiltersNoVtx", &HLT_DoubleMu43NoFiltersNoVtx, &b_HLT_DoubleMu43NoFiltersNoVtx);
   TRY_SET_BRANCH("HLT_DoubleMu48NoFiltersNoVtx", &HLT_DoubleMu48NoFiltersNoVtx, &b_HLT_DoubleMu48NoFiltersNoVtx);
   TRY_SET_BRANCH("HLT_Mu43NoFiltersNoVtx_Photon43_CaloIdL", &HLT_Mu43NoFiltersNoVtx_Photon43_CaloIdL, &b_HLT_Mu43NoFiltersNoVtx_Photon43_CaloIdL);
   TRY_SET_BRANCH("HLT_Mu48NoFiltersNoVtx_Photon48_CaloIdL", &HLT_Mu48NoFiltersNoVtx_Photon48_CaloIdL, &b_HLT_Mu48NoFiltersNoVtx_Photon48_CaloIdL);
   TRY_SET_BRANCH("HLT_Mu38NoFiltersNoVtxDisplaced_Photon38_CaloIdL", &HLT_Mu38NoFiltersNoVtxDisplaced_Photon38_CaloIdL, &b_HLT_Mu38NoFiltersNoVtxDisplaced_Photon38_CaloIdL);
   TRY_SET_BRANCH("HLT_Mu43NoFiltersNoVtxDisplaced_Photon43_CaloIdL", &HLT_Mu43NoFiltersNoVtxDisplaced_Photon43_CaloIdL, &b_HLT_Mu43NoFiltersNoVtxDisplaced_Photon43_CaloIdL);
   TRY_SET_BRANCH("HLT_DoubleMu33NoFiltersNoVtxDisplaced", &HLT_DoubleMu33NoFiltersNoVtxDisplaced, &b_HLT_DoubleMu33NoFiltersNoVtxDisplaced);
   TRY_SET_BRANCH("HLT_DoubleMu40NoFiltersNoVtxDisplaced", &HLT_DoubleMu40NoFiltersNoVtxDisplaced, &b_HLT_DoubleMu40NoFiltersNoVtxDisplaced);
   TRY_SET_BRANCH("HLT_DoubleMu20_7_Mass0to30_L1_DM4", &HLT_DoubleMu20_7_Mass0to30_L1_DM4, &b_HLT_DoubleMu20_7_Mass0to30_L1_DM4);
   TRY_SET_BRANCH("HLT_DoubleMu20_7_Mass0to30_L1_DM4EG", &HLT_DoubleMu20_7_Mass0to30_L1_DM4EG, &b_HLT_DoubleMu20_7_Mass0to30_L1_DM4EG);
   TRY_SET_BRANCH("HLT_HT425", &HLT_HT425, &b_HLT_HT425);
   TRY_SET_BRANCH("HLT_HT430_DisplacedDijet40_DisplacedTrack", &HLT_HT430_DisplacedDijet40_DisplacedTrack, &b_HLT_HT430_DisplacedDijet40_DisplacedTrack);
   TRY_SET_BRANCH("HLT_HT500_DisplacedDijet40_DisplacedTrack", &HLT_HT500_DisplacedDijet40_DisplacedTrack, &b_HLT_HT500_DisplacedDijet40_DisplacedTrack);
   TRY_SET_BRANCH("HLT_HT430_DisplacedDijet60_DisplacedTrack", &HLT_HT430_DisplacedDijet60_DisplacedTrack, &b_HLT_HT430_DisplacedDijet60_DisplacedTrack);
   TRY_SET_BRANCH("HLT_HT400_DisplacedDijet40_DisplacedTrack", &HLT_HT400_DisplacedDijet40_DisplacedTrack, &b_HLT_HT400_DisplacedDijet40_DisplacedTrack);
   TRY_SET_BRANCH("HLT_HT650_DisplacedDijet60_Inclusive", &HLT_HT650_DisplacedDijet60_Inclusive, &b_HLT_HT650_DisplacedDijet60_Inclusive);
   TRY_SET_BRANCH("HLT_HT550_DisplacedDijet60_Inclusive", &HLT_HT550_DisplacedDijet60_Inclusive, &b_HLT_HT550_DisplacedDijet60_Inclusive);
   TRY_SET_BRANCH("HLT_DiJet110_35_Mjj650_PFMET110", &HLT_DiJet110_35_Mjj650_PFMET110, &b_HLT_DiJet110_35_Mjj650_PFMET110);
   TRY_SET_BRANCH("HLT_DiJet110_35_Mjj650_PFMET120", &HLT_DiJet110_35_Mjj650_PFMET120, &b_HLT_DiJet110_35_Mjj650_PFMET120);
   TRY_SET_BRANCH("HLT_DiJet110_35_Mjj650_PFMET130", &HLT_DiJet110_35_Mjj650_PFMET130, &b_HLT_DiJet110_35_Mjj650_PFMET130);
   TRY_SET_BRANCH("HLT_TripleJet110_35_35_Mjj650_PFMET110", &HLT_TripleJet110_35_35_Mjj650_PFMET110, &b_HLT_TripleJet110_35_35_Mjj650_PFMET110);
   TRY_SET_BRANCH("HLT_TripleJet110_35_35_Mjj650_PFMET120", &HLT_TripleJet110_35_35_Mjj650_PFMET120, &b_HLT_TripleJet110_35_35_Mjj650_PFMET120);
   TRY_SET_BRANCH("HLT_TripleJet110_35_35_Mjj650_PFMET130", &HLT_TripleJet110_35_35_Mjj650_PFMET130, &b_HLT_TripleJet110_35_35_Mjj650_PFMET130);
   TRY_SET_BRANCH("HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned", &HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned, &b_HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned);
   TRY_SET_BRANCH("HLT_Ele28_eta2p1_WPTight_Gsf_HT150", &HLT_Ele28_eta2p1_WPTight_Gsf_HT150, &b_HLT_Ele28_eta2p1_WPTight_Gsf_HT150);
   TRY_SET_BRANCH("HLT_Ele28_HighEta_SC20_Mass55", &HLT_Ele28_HighEta_SC20_Mass55, &b_HLT_Ele28_HighEta_SC20_Mass55);
   TRY_SET_BRANCH("HLT_DoubleMu20_7_Mass0to30_Photon23", &HLT_DoubleMu20_7_Mass0to30_Photon23, &b_HLT_DoubleMu20_7_Mass0to30_Photon23);
   TRY_SET_BRANCH("HLT_Ele15_IsoVVVL_PFHT450_CaloBTagDeepCSV_4p5", &HLT_Ele15_IsoVVVL_PFHT450_CaloBTagDeepCSV_4p5, &b_HLT_Ele15_IsoVVVL_PFHT450_CaloBTagDeepCSV_4p5);
   TRY_SET_BRANCH("HLT_Ele15_IsoVVVL_PFHT450_PFMET50", &HLT_Ele15_IsoVVVL_PFHT450_PFMET50, &b_HLT_Ele15_IsoVVVL_PFHT450_PFMET50);
   TRY_SET_BRANCH("HLT_Ele15_IsoVVVL_PFHT450", &HLT_Ele15_IsoVVVL_PFHT450, &b_HLT_Ele15_IsoVVVL_PFHT450);
   TRY_SET_BRANCH("HLT_Ele50_IsoVVVL_PFHT450", &HLT_Ele50_IsoVVVL_PFHT450, &b_HLT_Ele50_IsoVVVL_PFHT450);
   TRY_SET_BRANCH("HLT_Ele15_IsoVVVL_PFHT600", &HLT_Ele15_IsoVVVL_PFHT600, &b_HLT_Ele15_IsoVVVL_PFHT600);
   TRY_SET_BRANCH("HLT_Mu4_TrkIsoVVL_DiPFJet90_40_DEta3p5_MJJ750_HTT300_PFMETNoMu60", &HLT_Mu4_TrkIsoVVL_DiPFJet90_40_DEta3p5_MJJ750_HTT300_PFMETNoMu60, &b_HLT_Mu4_TrkIsoVVL_DiPFJet90_40_DEta3p5_MJJ750_HTT300_PFMETNoMu60);
   TRY_SET_BRANCH("HLT_Mu8_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT300_PFMETNoMu60", &HLT_Mu8_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT300_PFMETNoMu60, &b_HLT_Mu8_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT300_PFMETNoMu60);
   TRY_SET_BRANCH("HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60", &HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60, &b_HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60);
   TRY_SET_BRANCH("HLT_Mu15_IsoVVVL_PFHT450_CaloBTagDeepCSV_4p5", &HLT_Mu15_IsoVVVL_PFHT450_CaloBTagDeepCSV_4p5, &b_HLT_Mu15_IsoVVVL_PFHT450_CaloBTagDeepCSV_4p5);
   TRY_SET_BRANCH("HLT_Mu15_IsoVVVL_PFHT450_PFMET50", &HLT_Mu15_IsoVVVL_PFHT450_PFMET50, &b_HLT_Mu15_IsoVVVL_PFHT450_PFMET50);
   TRY_SET_BRANCH("HLT_Mu15_IsoVVVL_PFHT450", &HLT_Mu15_IsoVVVL_PFHT450, &b_HLT_Mu15_IsoVVVL_PFHT450);
   TRY_SET_BRANCH("HLT_Mu50_IsoVVVL_PFHT450", &HLT_Mu50_IsoVVVL_PFHT450, &b_HLT_Mu50_IsoVVVL_PFHT450);
   TRY_SET_BRANCH("HLT_Mu15_IsoVVVL_PFHT600", &HLT_Mu15_IsoVVVL_PFHT600, &b_HLT_Mu15_IsoVVVL_PFHT600);
   TRY_SET_BRANCH("HLT_Mu3er1p5_PFJet100er2p5_PFMET70_PFMHT70_IDTight", &HLT_Mu3er1p5_PFJet100er2p5_PFMET70_PFMHT70_IDTight, &b_HLT_Mu3er1p5_PFJet100er2p5_PFMET70_PFMHT70_IDTight);
   TRY_SET_BRANCH("HLT_Mu3er1p5_PFJet100er2p5_PFMET80_PFMHT80_IDTight", &HLT_Mu3er1p5_PFJet100er2p5_PFMET80_PFMHT80_IDTight, &b_HLT_Mu3er1p5_PFJet100er2p5_PFMET80_PFMHT80_IDTight);
   TRY_SET_BRANCH("HLT_Mu3er1p5_PFJet100er2p5_PFMET90_PFMHT90_IDTight", &HLT_Mu3er1p5_PFJet100er2p5_PFMET90_PFMHT90_IDTight, &b_HLT_Mu3er1p5_PFJet100er2p5_PFMET90_PFMHT90_IDTight);
   TRY_SET_BRANCH("HLT_Mu3er1p5_PFJet100er2p5_PFMET100_PFMHT100_IDTight", &HLT_Mu3er1p5_PFJet100er2p5_PFMET100_PFMHT100_IDTight, &b_HLT_Mu3er1p5_PFJet100er2p5_PFMET100_PFMHT100_IDTight);
   TRY_SET_BRANCH("HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu70_PFMHTNoMu70_IDTight", &HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu70_PFMHTNoMu70_IDTight, &b_HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu70_PFMHTNoMu70_IDTight);
   TRY_SET_BRANCH("HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu80_PFMHTNoMu80_IDTight", &HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu80_PFMHTNoMu80_IDTight, &b_HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu80_PFMHTNoMu80_IDTight);
   TRY_SET_BRANCH("HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu90_PFMHTNoMu90_IDTight", &HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu90_PFMHTNoMu90_IDTight, &b_HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu90_PFMHTNoMu90_IDTight);
   TRY_SET_BRANCH("HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu100_PFMHTNoMu100_IDTight", &HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu100_PFMHTNoMu100_IDTight, &b_HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu100_PFMHTNoMu100_IDTight);
   TRY_SET_BRANCH("HLT_Dimuon10_PsiPrime_Barrel_Seagulls", &HLT_Dimuon10_PsiPrime_Barrel_Seagulls, &b_HLT_Dimuon10_PsiPrime_Barrel_Seagulls);
   TRY_SET_BRANCH("HLT_Dimuon20_Jpsi_Barrel_Seagulls", &HLT_Dimuon20_Jpsi_Barrel_Seagulls, &b_HLT_Dimuon20_Jpsi_Barrel_Seagulls);
   TRY_SET_BRANCH("HLT_Dimuon12_Upsilon_y1p4", &HLT_Dimuon12_Upsilon_y1p4, &b_HLT_Dimuon12_Upsilon_y1p4);
   TRY_SET_BRANCH("HLT_Dimuon14_Phi_Barrel_Seagulls", &HLT_Dimuon14_Phi_Barrel_Seagulls, &b_HLT_Dimuon14_Phi_Barrel_Seagulls);
   TRY_SET_BRANCH("HLT_Dimuon18_PsiPrime", &HLT_Dimuon18_PsiPrime, &b_HLT_Dimuon18_PsiPrime);
   TRY_SET_BRANCH("HLT_Dimuon25_Jpsi", &HLT_Dimuon25_Jpsi, &b_HLT_Dimuon25_Jpsi);
   TRY_SET_BRANCH("HLT_Dimuon18_PsiPrime_noCorrL1", &HLT_Dimuon18_PsiPrime_noCorrL1, &b_HLT_Dimuon18_PsiPrime_noCorrL1);
   TRY_SET_BRANCH("HLT_Dimuon24_Upsilon_noCorrL1", &HLT_Dimuon24_Upsilon_noCorrL1, &b_HLT_Dimuon24_Upsilon_noCorrL1);
   TRY_SET_BRANCH("HLT_Dimuon24_Phi_noCorrL1", &HLT_Dimuon24_Phi_noCorrL1, &b_HLT_Dimuon24_Phi_noCorrL1);
   TRY_SET_BRANCH("HLT_Dimuon25_Jpsi_noCorrL1", &HLT_Dimuon25_Jpsi_noCorrL1, &b_HLT_Dimuon25_Jpsi_noCorrL1);
   TRY_SET_BRANCH("HLT_DiMu4_Ele9_CaloIdL_TrackIdL_DZ_Mass3p8", &HLT_DiMu4_Ele9_CaloIdL_TrackIdL_DZ_Mass3p8, &b_HLT_DiMu4_Ele9_CaloIdL_TrackIdL_DZ_Mass3p8);
   TRY_SET_BRANCH("HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ", &HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ, &b_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ);
   TRY_SET_BRANCH("HLT_DiMu9_Ele9_CaloIdL_TrackIdL", &HLT_DiMu9_Ele9_CaloIdL_TrackIdL, &b_HLT_DiMu9_Ele9_CaloIdL_TrackIdL);
   TRY_SET_BRANCH("HLT_DoubleIsoMu20_eta2p1", &HLT_DoubleIsoMu20_eta2p1, &b_HLT_DoubleIsoMu20_eta2p1);
   TRY_SET_BRANCH("HLT_TrkMu12_DoubleTrkMu5NoFiltersNoVtx", &HLT_TrkMu12_DoubleTrkMu5NoFiltersNoVtx, &b_HLT_TrkMu12_DoubleTrkMu5NoFiltersNoVtx);
   TRY_SET_BRANCH("HLT_TrkMu16_DoubleTrkMu6NoFiltersNoVtx", &HLT_TrkMu16_DoubleTrkMu6NoFiltersNoVtx, &b_HLT_TrkMu16_DoubleTrkMu6NoFiltersNoVtx);
   TRY_SET_BRANCH("HLT_TrkMu17_DoubleTrkMu8NoFiltersNoVtx", &HLT_TrkMu17_DoubleTrkMu8NoFiltersNoVtx, &b_HLT_TrkMu17_DoubleTrkMu8NoFiltersNoVtx);
   TRY_SET_BRANCH("HLT_Mu8", &HLT_Mu8, &b_HLT_Mu8);
   TRY_SET_BRANCH("HLT_Mu17", &HLT_Mu17, &b_HLT_Mu17);
   TRY_SET_BRANCH("HLT_Mu19", &HLT_Mu19, &b_HLT_Mu19);
   TRY_SET_BRANCH("HLT_Mu17_Photon30_IsoCaloId", &HLT_Mu17_Photon30_IsoCaloId, &b_HLT_Mu17_Photon30_IsoCaloId);
   TRY_SET_BRANCH("HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30", &HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30, &b_HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30);
   TRY_SET_BRANCH("HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30", &HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30, &b_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30);
   TRY_SET_BRANCH("HLT_Ele15_CaloIdL_TrackIdL_IsoVL_PFJet30", &HLT_Ele15_CaloIdL_TrackIdL_IsoVL_PFJet30, &b_HLT_Ele15_CaloIdL_TrackIdL_IsoVL_PFJet30);
   TRY_SET_BRANCH("HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30", &HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30, &b_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30);
   TRY_SET_BRANCH("HLT_Ele8_CaloIdM_TrackIdM_PFJet30", &HLT_Ele8_CaloIdM_TrackIdM_PFJet30, &b_HLT_Ele8_CaloIdM_TrackIdM_PFJet30);
   TRY_SET_BRANCH("HLT_Ele17_CaloIdM_TrackIdM_PFJet30", &HLT_Ele17_CaloIdM_TrackIdM_PFJet30, &b_HLT_Ele17_CaloIdM_TrackIdM_PFJet30);
   TRY_SET_BRANCH("HLT_Ele23_CaloIdM_TrackIdM_PFJet30", &HLT_Ele23_CaloIdM_TrackIdM_PFJet30, &b_HLT_Ele23_CaloIdM_TrackIdM_PFJet30);
   TRY_SET_BRANCH("HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165", &HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165, &b_HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165);
   TRY_SET_BRANCH("HLT_Ele115_CaloIdVT_GsfTrkIdT", &HLT_Ele115_CaloIdVT_GsfTrkIdT, &b_HLT_Ele115_CaloIdVT_GsfTrkIdT);
   TRY_SET_BRANCH("HLT_Ele135_CaloIdVT_GsfTrkIdT", &HLT_Ele135_CaloIdVT_GsfTrkIdT, &b_HLT_Ele135_CaloIdVT_GsfTrkIdT);
   TRY_SET_BRANCH("HLT_Ele145_CaloIdVT_GsfTrkIdT", &HLT_Ele145_CaloIdVT_GsfTrkIdT, &b_HLT_Ele145_CaloIdVT_GsfTrkIdT);
   TRY_SET_BRANCH("HLT_Ele200_CaloIdVT_GsfTrkIdT", &HLT_Ele200_CaloIdVT_GsfTrkIdT, &b_HLT_Ele200_CaloIdVT_GsfTrkIdT);
   TRY_SET_BRANCH("HLT_Ele250_CaloIdVT_GsfTrkIdT", &HLT_Ele250_CaloIdVT_GsfTrkIdT, &b_HLT_Ele250_CaloIdVT_GsfTrkIdT);
   TRY_SET_BRANCH("HLT_Ele300_CaloIdVT_GsfTrkIdT", &HLT_Ele300_CaloIdVT_GsfTrkIdT, &b_HLT_Ele300_CaloIdVT_GsfTrkIdT);
   TRY_SET_BRANCH("HLT_PFHT330PT30_QuadPFJet_75_60_45_40_TriplePFBTagDeepCSV_4p5", &HLT_PFHT330PT30_QuadPFJet_75_60_45_40_TriplePFBTagDeepCSV_4p5, &b_HLT_PFHT330PT30_QuadPFJet_75_60_45_40_TriplePFBTagDeepCSV_4p5);
   TRY_SET_BRANCH("HLT_PFHT330PT30_QuadPFJet_75_60_45_40", &HLT_PFHT330PT30_QuadPFJet_75_60_45_40, &b_HLT_PFHT330PT30_QuadPFJet_75_60_45_40);
   TRY_SET_BRANCH("HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94", &HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94, &b_HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94);
   TRY_SET_BRANCH("HLT_PFHT400_SixPFJet32", &HLT_PFHT400_SixPFJet32, &b_HLT_PFHT400_SixPFJet32);
   TRY_SET_BRANCH("HLT_PFHT450_SixPFJet36_PFBTagDeepCSV_1p59", &HLT_PFHT450_SixPFJet36_PFBTagDeepCSV_1p59, &b_HLT_PFHT450_SixPFJet36_PFBTagDeepCSV_1p59);
   TRY_SET_BRANCH("HLT_PFHT450_SixPFJet36", &HLT_PFHT450_SixPFJet36, &b_HLT_PFHT450_SixPFJet36);
   TRY_SET_BRANCH("HLT_PFHT350", &HLT_PFHT350, &b_HLT_PFHT350);
   TRY_SET_BRANCH("HLT_PFHT350MinPFJet15", &HLT_PFHT350MinPFJet15, &b_HLT_PFHT350MinPFJet15);
   TRY_SET_BRANCH("HLT_Photon60_R9Id90_CaloIdL_IsoL", &HLT_Photon60_R9Id90_CaloIdL_IsoL, &b_HLT_Photon60_R9Id90_CaloIdL_IsoL);
   TRY_SET_BRANCH("HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL", &HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL, &b_HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL);
   TRY_SET_BRANCH("HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL_PFHT350MinPFJet15", &HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL_PFHT350MinPFJet15, &b_HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL_PFHT350MinPFJet15);
   TRY_SET_BRANCH("HLT_ECALHT800", &HLT_ECALHT800, &b_HLT_ECALHT800);
   TRY_SET_BRANCH("HLT_DiSC30_18_EIso_AND_HE_Mass70", &HLT_DiSC30_18_EIso_AND_HE_Mass70, &b_HLT_DiSC30_18_EIso_AND_HE_Mass70);
   TRY_SET_BRANCH("HLT_Physics", &HLT_Physics, &b_HLT_Physics);
   TRY_SET_BRANCH("HLT_Physics_part0", &HLT_Physics_part0, &b_HLT_Physics_part0);
   TRY_SET_BRANCH("HLT_Physics_part1", &HLT_Physics_part1, &b_HLT_Physics_part1);
   TRY_SET_BRANCH("HLT_Physics_part2", &HLT_Physics_part2, &b_HLT_Physics_part2);
   TRY_SET_BRANCH("HLT_Physics_part3", &HLT_Physics_part3, &b_HLT_Physics_part3);
   TRY_SET_BRANCH("HLT_Physics_part4", &HLT_Physics_part4, &b_HLT_Physics_part4);
   TRY_SET_BRANCH("HLT_Physics_part5", &HLT_Physics_part5, &b_HLT_Physics_part5);
   TRY_SET_BRANCH("HLT_Physics_part6", &HLT_Physics_part6, &b_HLT_Physics_part6);
   TRY_SET_BRANCH("HLT_Physics_part7", &HLT_Physics_part7, &b_HLT_Physics_part7);
   TRY_SET_BRANCH("HLT_Random", &HLT_Random, &b_HLT_Random);
   TRY_SET_BRANCH("HLT_ZeroBias", &HLT_ZeroBias, &b_HLT_ZeroBias);
   TRY_SET_BRANCH("HLT_ZeroBias_Alignment", &HLT_ZeroBias_Alignment, &b_HLT_ZeroBias_Alignment);
   TRY_SET_BRANCH("HLT_ZeroBias_part0", &HLT_ZeroBias_part0, &b_HLT_ZeroBias_part0);
   TRY_SET_BRANCH("HLT_ZeroBias_part1", &HLT_ZeroBias_part1, &b_HLT_ZeroBias_part1);
   TRY_SET_BRANCH("HLT_ZeroBias_part2", &HLT_ZeroBias_part2, &b_HLT_ZeroBias_part2);
   TRY_SET_BRANCH("HLT_ZeroBias_part3", &HLT_ZeroBias_part3, &b_HLT_ZeroBias_part3);
   TRY_SET_BRANCH("HLT_ZeroBias_part4", &HLT_ZeroBias_part4, &b_HLT_ZeroBias_part4);
   TRY_SET_BRANCH("HLT_ZeroBias_part5", &HLT_ZeroBias_part5, &b_HLT_ZeroBias_part5);
   TRY_SET_BRANCH("HLT_ZeroBias_part6", &HLT_ZeroBias_part6, &b_HLT_ZeroBias_part6);
   TRY_SET_BRANCH("HLT_ZeroBias_part7", &HLT_ZeroBias_part7, &b_HLT_ZeroBias_part7);
   TRY_SET_BRANCH("HLT_AK4CaloJet30", &HLT_AK4CaloJet30, &b_HLT_AK4CaloJet30);
   TRY_SET_BRANCH("HLT_AK4CaloJet40", &HLT_AK4CaloJet40, &b_HLT_AK4CaloJet40);
   TRY_SET_BRANCH("HLT_AK4CaloJet50", &HLT_AK4CaloJet50, &b_HLT_AK4CaloJet50);
   TRY_SET_BRANCH("HLT_AK4CaloJet80", &HLT_AK4CaloJet80, &b_HLT_AK4CaloJet80);
   TRY_SET_BRANCH("HLT_AK4CaloJet100", &HLT_AK4CaloJet100, &b_HLT_AK4CaloJet100);
   TRY_SET_BRANCH("HLT_AK4CaloJet120", &HLT_AK4CaloJet120, &b_HLT_AK4CaloJet120);
   TRY_SET_BRANCH("HLT_AK4PFJet30", &HLT_AK4PFJet30, &b_HLT_AK4PFJet30);
   TRY_SET_BRANCH("HLT_AK4PFJet50", &HLT_AK4PFJet50, &b_HLT_AK4PFJet50);
   TRY_SET_BRANCH("HLT_AK4PFJet80", &HLT_AK4PFJet80, &b_HLT_AK4PFJet80);
   TRY_SET_BRANCH("HLT_AK4PFJet100", &HLT_AK4PFJet100, &b_HLT_AK4PFJet100);
   TRY_SET_BRANCH("HLT_AK4PFJet120", &HLT_AK4PFJet120, &b_HLT_AK4PFJet120);
   TRY_SET_BRANCH("HLT_SinglePhoton10_Eta3p1ForPPRef", &HLT_SinglePhoton10_Eta3p1ForPPRef, &b_HLT_SinglePhoton10_Eta3p1ForPPRef);
   TRY_SET_BRANCH("HLT_SinglePhoton20_Eta3p1ForPPRef", &HLT_SinglePhoton20_Eta3p1ForPPRef, &b_HLT_SinglePhoton20_Eta3p1ForPPRef);
   TRY_SET_BRANCH("HLT_SinglePhoton30_Eta3p1ForPPRef", &HLT_SinglePhoton30_Eta3p1ForPPRef, &b_HLT_SinglePhoton30_Eta3p1ForPPRef);
   TRY_SET_BRANCH("HLT_Photon20_HoverELoose", &HLT_Photon20_HoverELoose, &b_HLT_Photon20_HoverELoose);
   TRY_SET_BRANCH("HLT_Photon30_HoverELoose", &HLT_Photon30_HoverELoose, &b_HLT_Photon30_HoverELoose);
   TRY_SET_BRANCH("HLT_EcalCalibration", &HLT_EcalCalibration, &b_HLT_EcalCalibration);
   TRY_SET_BRANCH("HLT_HcalCalibration", &HLT_HcalCalibration, &b_HLT_HcalCalibration);
   TRY_SET_BRANCH("HLT_L1UnpairedBunchBptxMinus", &HLT_L1UnpairedBunchBptxMinus, &b_HLT_L1UnpairedBunchBptxMinus);
   TRY_SET_BRANCH("HLT_L1UnpairedBunchBptxPlus", &HLT_L1UnpairedBunchBptxPlus, &b_HLT_L1UnpairedBunchBptxPlus);
   TRY_SET_BRANCH("HLT_L1NotBptxOR", &HLT_L1NotBptxOR, &b_HLT_L1NotBptxOR);
   TRY_SET_BRANCH("HLT_L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142", &HLT_L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142, &b_HLT_L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142);
   TRY_SET_BRANCH("HLT_CDC_L2cosmic_5_er1p0", &HLT_CDC_L2cosmic_5_er1p0, &b_HLT_CDC_L2cosmic_5_er1p0);
   TRY_SET_BRANCH("HLT_CDC_L2cosmic_5p5_er1p0", &HLT_CDC_L2cosmic_5p5_er1p0, &b_HLT_CDC_L2cosmic_5p5_er1p0);
   TRY_SET_BRANCH("HLT_HcalNZS", &HLT_HcalNZS, &b_HLT_HcalNZS);
   TRY_SET_BRANCH("HLT_HcalPhiSym", &HLT_HcalPhiSym, &b_HLT_HcalPhiSym);
   TRY_SET_BRANCH("HLT_HcalIsolatedbunch", &HLT_HcalIsolatedbunch, &b_HLT_HcalIsolatedbunch);
   TRY_SET_BRANCH("HLT_IsoTrackHB", &HLT_IsoTrackHB, &b_HLT_IsoTrackHB);
   TRY_SET_BRANCH("HLT_IsoTrackHE", &HLT_IsoTrackHE, &b_HLT_IsoTrackHE);
   TRY_SET_BRANCH("HLT_ZeroBias_FirstCollisionAfterAbortGap", &HLT_ZeroBias_FirstCollisionAfterAbortGap, &b_HLT_ZeroBias_FirstCollisionAfterAbortGap);
   TRY_SET_BRANCH("HLT_ZeroBias_IsolatedBunches", &HLT_ZeroBias_IsolatedBunches, &b_HLT_ZeroBias_IsolatedBunches);
   TRY_SET_BRANCH("HLT_ZeroBias_FirstCollisionInTrain", &HLT_ZeroBias_FirstCollisionInTrain, &b_HLT_ZeroBias_FirstCollisionInTrain);
   TRY_SET_BRANCH("HLT_ZeroBias_LastCollisionInTrain", &HLT_ZeroBias_LastCollisionInTrain, &b_HLT_ZeroBias_LastCollisionInTrain);
   TRY_SET_BRANCH("HLT_ZeroBias_FirstBXAfterTrain", &HLT_ZeroBias_FirstBXAfterTrain, &b_HLT_ZeroBias_FirstBXAfterTrain);
   TRY_SET_BRANCH("HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr", &HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr, &b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr);
   TRY_SET_BRANCH("HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90", &HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90, &b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90);
   TRY_SET_BRANCH("HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100", &HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100, &b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100);
   TRY_SET_BRANCH("HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET110", &HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET110, &b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET110);
   TRY_SET_BRANCH("HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET120", &HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET120, &b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET120);
   TRY_SET_BRANCH("HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET130", &HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET130, &b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET130);
   TRY_SET_BRANCH("HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET140", &HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET140, &b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET140);
   TRY_SET_BRANCH("HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr", &HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr, &b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr);
   TRY_SET_BRANCH("HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr", &HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr, &b_HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr);
   TRY_SET_BRANCH("HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1", &HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1, &b_HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1);
   TRY_SET_BRANCH("HLT_MediumChargedIsoPFTau200HighPtRelaxedIso_Trk50_eta2p1", &HLT_MediumChargedIsoPFTau200HighPtRelaxedIso_Trk50_eta2p1, &b_HLT_MediumChargedIsoPFTau200HighPtRelaxedIso_Trk50_eta2p1);
   TRY_SET_BRANCH("HLT_MediumChargedIsoPFTau220HighPtRelaxedIso_Trk50_eta2p1", &HLT_MediumChargedIsoPFTau220HighPtRelaxedIso_Trk50_eta2p1, &b_HLT_MediumChargedIsoPFTau220HighPtRelaxedIso_Trk50_eta2p1);
   TRY_SET_BRANCH("HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL", &HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL, &b_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL);
   TRY_SET_BRANCH("HLT_Rsq0p35", &HLT_Rsq0p35, &b_HLT_Rsq0p35);
   TRY_SET_BRANCH("HLT_Rsq0p40", &HLT_Rsq0p40, &b_HLT_Rsq0p40);
   TRY_SET_BRANCH("HLT_RsqMR300_Rsq0p09_MR200", &HLT_RsqMR300_Rsq0p09_MR200, &b_HLT_RsqMR300_Rsq0p09_MR200);
   TRY_SET_BRANCH("HLT_RsqMR320_Rsq0p09_MR200", &HLT_RsqMR320_Rsq0p09_MR200, &b_HLT_RsqMR320_Rsq0p09_MR200);
   TRY_SET_BRANCH("HLT_RsqMR300_Rsq0p09_MR200_4jet", &HLT_RsqMR300_Rsq0p09_MR200_4jet, &b_HLT_RsqMR300_Rsq0p09_MR200_4jet);
   TRY_SET_BRANCH("HLT_RsqMR320_Rsq0p09_MR200_4jet", &HLT_RsqMR320_Rsq0p09_MR200_4jet, &b_HLT_RsqMR320_Rsq0p09_MR200_4jet);
   TRY_SET_BRANCH("HLT_IsoMu27_MET90", &HLT_IsoMu27_MET90, &b_HLT_IsoMu27_MET90);
   TRY_SET_BRANCH("HLT_DoubleTightChargedIsoPFTauHPS35_Trk1_eta2p1_Reg", &HLT_DoubleTightChargedIsoPFTauHPS35_Trk1_eta2p1_Reg, &b_HLT_DoubleTightChargedIsoPFTauHPS35_Trk1_eta2p1_Reg);
   TRY_SET_BRANCH("HLT_DoubleMediumChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg", &HLT_DoubleMediumChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg, &b_HLT_DoubleMediumChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg);
   TRY_SET_BRANCH("HLT_DoubleMediumChargedIsoPFTauHPS35_Trk1_eta2p1_Reg", &HLT_DoubleMediumChargedIsoPFTauHPS35_Trk1_eta2p1_Reg, &b_HLT_DoubleMediumChargedIsoPFTauHPS35_Trk1_eta2p1_Reg);
   TRY_SET_BRANCH("HLT_DoubleTightChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg", &HLT_DoubleTightChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg, &b_HLT_DoubleTightChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg);
   TRY_SET_BRANCH("HLT_DoubleMediumChargedIsoPFTauHPS40_Trk1_eta2p1_Reg", &HLT_DoubleMediumChargedIsoPFTauHPS40_Trk1_eta2p1_Reg, &b_HLT_DoubleMediumChargedIsoPFTauHPS40_Trk1_eta2p1_Reg);
   TRY_SET_BRANCH("HLT_DoubleTightChargedIsoPFTauHPS40_Trk1_eta2p1_Reg", &HLT_DoubleTightChargedIsoPFTauHPS40_Trk1_eta2p1_Reg, &b_HLT_DoubleTightChargedIsoPFTauHPS40_Trk1_eta2p1_Reg);
   TRY_SET_BRANCH("HLT_DoubleMediumChargedIsoPFTauHPS40_Trk1_TightID_eta2p1_Reg", &HLT_DoubleMediumChargedIsoPFTauHPS40_Trk1_TightID_eta2p1_Reg, &b_HLT_DoubleMediumChargedIsoPFTauHPS40_Trk1_TightID_eta2p1_Reg);
   TRY_SET_BRANCH("HLT_DoubleTightChargedIsoPFTauHPS40_Trk1_TightID_eta2p1_Reg", &HLT_DoubleTightChargedIsoPFTauHPS40_Trk1_TightID_eta2p1_Reg, &b_HLT_DoubleTightChargedIsoPFTauHPS40_Trk1_TightID_eta2p1_Reg);
   TRY_SET_BRANCH("HLT_VBF_DoubleLooseChargedIsoPFTauHPS20_Trk1_eta2p1", &HLT_VBF_DoubleLooseChargedIsoPFTauHPS20_Trk1_eta2p1, &b_HLT_VBF_DoubleLooseChargedIsoPFTauHPS20_Trk1_eta2p1);
   TRY_SET_BRANCH("HLT_VBF_DoubleMediumChargedIsoPFTauHPS20_Trk1_eta2p1", &HLT_VBF_DoubleMediumChargedIsoPFTauHPS20_Trk1_eta2p1, &b_HLT_VBF_DoubleMediumChargedIsoPFTauHPS20_Trk1_eta2p1);
   TRY_SET_BRANCH("HLT_VBF_DoubleTightChargedIsoPFTauHPS20_Trk1_eta2p1", &HLT_VBF_DoubleTightChargedIsoPFTauHPS20_Trk1_eta2p1, &b_HLT_VBF_DoubleTightChargedIsoPFTauHPS20_Trk1_eta2p1);
   TRY_SET_BRANCH("HLT_Photon50_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3_PFMET50", &HLT_Photon50_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3_PFMET50, &b_HLT_Photon50_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3_PFMET50);
   TRY_SET_BRANCH("HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3", &HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3, &b_HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3);
   TRY_SET_BRANCH("HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ600DEta3", &HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ600DEta3, &b_HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ600DEta3);
   TRY_SET_BRANCH("HLT_PFMET100_PFMHT100_IDTight_PFHT60", &HLT_PFMET100_PFMHT100_IDTight_PFHT60, &b_HLT_PFMET100_PFMHT100_IDTight_PFHT60);
   TRY_SET_BRANCH("HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_PFHT60", &HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_PFHT60, &b_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_PFHT60);
   TRY_SET_BRANCH("HLT_PFMETTypeOne100_PFMHT100_IDTight_PFHT60", &HLT_PFMETTypeOne100_PFMHT100_IDTight_PFHT60, &b_HLT_PFMETTypeOne100_PFMHT100_IDTight_PFHT60);
   TRY_SET_BRANCH("HLT_Mu18_Mu9_SameSign", &HLT_Mu18_Mu9_SameSign, &b_HLT_Mu18_Mu9_SameSign);
   TRY_SET_BRANCH("HLT_Mu18_Mu9_SameSign_DZ", &HLT_Mu18_Mu9_SameSign_DZ, &b_HLT_Mu18_Mu9_SameSign_DZ);
   TRY_SET_BRANCH("HLT_Mu18_Mu9", &HLT_Mu18_Mu9, &b_HLT_Mu18_Mu9);
   TRY_SET_BRANCH("HLT_Mu18_Mu9_DZ", &HLT_Mu18_Mu9_DZ, &b_HLT_Mu18_Mu9_DZ);
   TRY_SET_BRANCH("HLT_Mu20_Mu10_SameSign", &HLT_Mu20_Mu10_SameSign, &b_HLT_Mu20_Mu10_SameSign);
   TRY_SET_BRANCH("HLT_Mu20_Mu10_SameSign_DZ", &HLT_Mu20_Mu10_SameSign_DZ, &b_HLT_Mu20_Mu10_SameSign_DZ);
   TRY_SET_BRANCH("HLT_Mu20_Mu10", &HLT_Mu20_Mu10, &b_HLT_Mu20_Mu10);
   TRY_SET_BRANCH("HLT_Mu20_Mu10_DZ", &HLT_Mu20_Mu10_DZ, &b_HLT_Mu20_Mu10_DZ);
   TRY_SET_BRANCH("HLT_Mu23_Mu12_SameSign", &HLT_Mu23_Mu12_SameSign, &b_HLT_Mu23_Mu12_SameSign);
   TRY_SET_BRANCH("HLT_Mu23_Mu12_SameSign_DZ", &HLT_Mu23_Mu12_SameSign_DZ, &b_HLT_Mu23_Mu12_SameSign_DZ);
   TRY_SET_BRANCH("HLT_Mu23_Mu12", &HLT_Mu23_Mu12, &b_HLT_Mu23_Mu12);
   TRY_SET_BRANCH("HLT_Mu23_Mu12_DZ", &HLT_Mu23_Mu12_DZ, &b_HLT_Mu23_Mu12_DZ);
   TRY_SET_BRANCH("HLT_DoubleMu2_Jpsi_DoubleTrk1_Phi1p05", &HLT_DoubleMu2_Jpsi_DoubleTrk1_Phi1p05, &b_HLT_DoubleMu2_Jpsi_DoubleTrk1_Phi1p05);
   TRY_SET_BRANCH("HLT_DoubleMu2_Jpsi_DoubleTkMu0_Phi", &HLT_DoubleMu2_Jpsi_DoubleTkMu0_Phi, &b_HLT_DoubleMu2_Jpsi_DoubleTkMu0_Phi);
   TRY_SET_BRANCH("HLT_DoubleMu3_DCA_PFMET50_PFMHT60", &HLT_DoubleMu3_DCA_PFMET50_PFMHT60, &b_HLT_DoubleMu3_DCA_PFMET50_PFMHT60);
   TRY_SET_BRANCH("HLT_TripleMu_5_3_3_Mass3p8_DCA", &HLT_TripleMu_5_3_3_Mass3p8_DCA, &b_HLT_TripleMu_5_3_3_Mass3p8_DCA);
   TRY_SET_BRANCH("HLT_QuadPFJet98_83_71_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1", &HLT_QuadPFJet98_83_71_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1, &b_HLT_QuadPFJet98_83_71_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1);
   TRY_SET_BRANCH("HLT_QuadPFJet103_88_75_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1", &HLT_QuadPFJet103_88_75_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1, &b_HLT_QuadPFJet103_88_75_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1);
   TRY_SET_BRANCH("HLT_QuadPFJet111_90_80_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1", &HLT_QuadPFJet111_90_80_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1, &b_HLT_QuadPFJet111_90_80_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1);
   TRY_SET_BRANCH("HLT_QuadPFJet98_83_71_15_PFBTagDeepCSV_1p3_VBF2", &HLT_QuadPFJet98_83_71_15_PFBTagDeepCSV_1p3_VBF2, &b_HLT_QuadPFJet98_83_71_15_PFBTagDeepCSV_1p3_VBF2);
   TRY_SET_BRANCH("HLT_QuadPFJet103_88_75_15_PFBTagDeepCSV_1p3_VBF2", &HLT_QuadPFJet103_88_75_15_PFBTagDeepCSV_1p3_VBF2, &b_HLT_QuadPFJet103_88_75_15_PFBTagDeepCSV_1p3_VBF2);
   TRY_SET_BRANCH("HLT_QuadPFJet105_88_76_15_PFBTagDeepCSV_1p3_VBF2", &HLT_QuadPFJet105_88_76_15_PFBTagDeepCSV_1p3_VBF2, &b_HLT_QuadPFJet105_88_76_15_PFBTagDeepCSV_1p3_VBF2);
   TRY_SET_BRANCH("HLT_QuadPFJet111_90_80_15_PFBTagDeepCSV_1p3_VBF2", &HLT_QuadPFJet111_90_80_15_PFBTagDeepCSV_1p3_VBF2, &b_HLT_QuadPFJet111_90_80_15_PFBTagDeepCSV_1p3_VBF2);
   TRY_SET_BRANCH("HLT_QuadPFJet98_83_71_15", &HLT_QuadPFJet98_83_71_15, &b_HLT_QuadPFJet98_83_71_15);
   TRY_SET_BRANCH("HLT_QuadPFJet103_88_75_15", &HLT_QuadPFJet103_88_75_15, &b_HLT_QuadPFJet103_88_75_15);
   TRY_SET_BRANCH("HLT_QuadPFJet105_88_76_15", &HLT_QuadPFJet105_88_76_15, &b_HLT_QuadPFJet105_88_76_15);
   TRY_SET_BRANCH("HLT_QuadPFJet111_90_80_15", &HLT_QuadPFJet111_90_80_15, &b_HLT_QuadPFJet111_90_80_15);
   TRY_SET_BRANCH("HLT_AK8PFJet330_TrimMass30_PFAK8BTagDeepCSV_p17", &HLT_AK8PFJet330_TrimMass30_PFAK8BTagDeepCSV_p17, &b_HLT_AK8PFJet330_TrimMass30_PFAK8BTagDeepCSV_p17);
   TRY_SET_BRANCH("HLT_AK8PFJet330_TrimMass30_PFAK8BTagDeepCSV_p1", &HLT_AK8PFJet330_TrimMass30_PFAK8BTagDeepCSV_p1, &b_HLT_AK8PFJet330_TrimMass30_PFAK8BTagDeepCSV_p1);
   TRY_SET_BRANCH("HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_p02", &HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_p02, &b_HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_p02);
   TRY_SET_BRANCH("HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_np2", &HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_np2, &b_HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_np2);
   TRY_SET_BRANCH("HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_np4", &HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_np4, &b_HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_np4);
   TRY_SET_BRANCH("HLT_AK8PFJet330_PFAK8BTagCSV_p17", &HLT_AK8PFJet330_PFAK8BTagCSV_p17, &b_HLT_AK8PFJet330_PFAK8BTagCSV_p17);
   TRY_SET_BRANCH("HLT_AK8DiPFJet300_200_TrimMass30_BTagCSV_p20", &HLT_AK8DiPFJet300_200_TrimMass30_BTagCSV_p20, &b_HLT_AK8DiPFJet300_200_TrimMass30_BTagCSV_p20);
   TRY_SET_BRANCH("HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p087", &HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p087, &b_HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p087);
   TRY_SET_BRANCH("HLT_AK8DiPFJet300_200_TrimMass30_BTagCSV_p087", &HLT_AK8DiPFJet300_200_TrimMass30_BTagCSV_p087, &b_HLT_AK8DiPFJet300_200_TrimMass30_BTagCSV_p087);
   TRY_SET_BRANCH("HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20", &HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20, &b_HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20);
   TRY_SET_BRANCH("HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20", &HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20, &b_HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20);
   TRY_SET_BRANCH("HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20", &HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20, &b_HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20);
   TRY_SET_BRANCH("HLT_Diphoton30_18_R9IdL_AND_HE_AND_IsoCaloId_NoPixelVeto_Mass55", &HLT_Diphoton30_18_R9IdL_AND_HE_AND_IsoCaloId_NoPixelVeto_Mass55, &b_HLT_Diphoton30_18_R9IdL_AND_HE_AND_IsoCaloId_NoPixelVeto_Mass55);
   TRY_SET_BRANCH("HLT_Diphoton30_18_R9IdL_AND_HE_AND_IsoCaloId_NoPixelVeto", &HLT_Diphoton30_18_R9IdL_AND_HE_AND_IsoCaloId_NoPixelVeto, &b_HLT_Diphoton30_18_R9IdL_AND_HE_AND_IsoCaloId_NoPixelVeto);
   TRY_SET_BRANCH("HLT_Mu12_IP6_part0", &HLT_Mu12_IP6_part0, &b_HLT_Mu12_IP6_part0);
   TRY_SET_BRANCH("HLT_Mu12_IP6_part1", &HLT_Mu12_IP6_part1, &b_HLT_Mu12_IP6_part1);
   TRY_SET_BRANCH("HLT_Mu12_IP6_part2", &HLT_Mu12_IP6_part2, &b_HLT_Mu12_IP6_part2);
   TRY_SET_BRANCH("HLT_Mu12_IP6_part3", &HLT_Mu12_IP6_part3, &b_HLT_Mu12_IP6_part3);
   TRY_SET_BRANCH("HLT_Mu12_IP6_part4", &HLT_Mu12_IP6_part4, &b_HLT_Mu12_IP6_part4);
   TRY_SET_BRANCH("HLT_Mu9_IP5_part0", &HLT_Mu9_IP5_part0, &b_HLT_Mu9_IP5_part0);
   TRY_SET_BRANCH("HLT_Mu9_IP5_part1", &HLT_Mu9_IP5_part1, &b_HLT_Mu9_IP5_part1);
   TRY_SET_BRANCH("HLT_Mu9_IP5_part2", &HLT_Mu9_IP5_part2, &b_HLT_Mu9_IP5_part2);
   TRY_SET_BRANCH("HLT_Mu9_IP5_part3", &HLT_Mu9_IP5_part3, &b_HLT_Mu9_IP5_part3);
   TRY_SET_BRANCH("HLT_Mu9_IP5_part4", &HLT_Mu9_IP5_part4, &b_HLT_Mu9_IP5_part4);
   TRY_SET_BRANCH("HLT_Mu7_IP4_part0", &HLT_Mu7_IP4_part0, &b_HLT_Mu7_IP4_part0);
   TRY_SET_BRANCH("HLT_Mu7_IP4_part1", &HLT_Mu7_IP4_part1, &b_HLT_Mu7_IP4_part1);
   TRY_SET_BRANCH("HLT_Mu7_IP4_part2", &HLT_Mu7_IP4_part2, &b_HLT_Mu7_IP4_part2);
   TRY_SET_BRANCH("HLT_Mu7_IP4_part3", &HLT_Mu7_IP4_part3, &b_HLT_Mu7_IP4_part3);
   TRY_SET_BRANCH("HLT_Mu7_IP4_part4", &HLT_Mu7_IP4_part4, &b_HLT_Mu7_IP4_part4);
   TRY_SET_BRANCH("HLT_Mu9_IP4_part0", &HLT_Mu9_IP4_part0, &b_HLT_Mu9_IP4_part0);
   TRY_SET_BRANCH("HLT_Mu9_IP4_part1", &HLT_Mu9_IP4_part1, &b_HLT_Mu9_IP4_part1);
   TRY_SET_BRANCH("HLT_Mu9_IP4_part2", &HLT_Mu9_IP4_part2, &b_HLT_Mu9_IP4_part2);
   TRY_SET_BRANCH("HLT_Mu9_IP4_part3", &HLT_Mu9_IP4_part3, &b_HLT_Mu9_IP4_part3);
   TRY_SET_BRANCH("HLT_Mu9_IP4_part4", &HLT_Mu9_IP4_part4, &b_HLT_Mu9_IP4_part4);
   TRY_SET_BRANCH("HLT_Mu8_IP5_part0", &HLT_Mu8_IP5_part0, &b_HLT_Mu8_IP5_part0);
   TRY_SET_BRANCH("HLT_Mu8_IP5_part1", &HLT_Mu8_IP5_part1, &b_HLT_Mu8_IP5_part1);
   TRY_SET_BRANCH("HLT_Mu8_IP5_part2", &HLT_Mu8_IP5_part2, &b_HLT_Mu8_IP5_part2);
   TRY_SET_BRANCH("HLT_Mu8_IP5_part3", &HLT_Mu8_IP5_part3, &b_HLT_Mu8_IP5_part3);
   TRY_SET_BRANCH("HLT_Mu8_IP5_part4", &HLT_Mu8_IP5_part4, &b_HLT_Mu8_IP5_part4);
   TRY_SET_BRANCH("HLT_Mu8_IP6_part0", &HLT_Mu8_IP6_part0, &b_HLT_Mu8_IP6_part0);
   TRY_SET_BRANCH("HLT_Mu8_IP6_part1", &HLT_Mu8_IP6_part1, &b_HLT_Mu8_IP6_part1);
   TRY_SET_BRANCH("HLT_Mu8_IP6_part2", &HLT_Mu8_IP6_part2, &b_HLT_Mu8_IP6_part2);
   TRY_SET_BRANCH("HLT_Mu8_IP6_part3", &HLT_Mu8_IP6_part3, &b_HLT_Mu8_IP6_part3);
   TRY_SET_BRANCH("HLT_Mu8_IP6_part4", &HLT_Mu8_IP6_part4, &b_HLT_Mu8_IP6_part4);
   TRY_SET_BRANCH("HLT_Mu9_IP6_part0", &HLT_Mu9_IP6_part0, &b_HLT_Mu9_IP6_part0);
   TRY_SET_BRANCH("HLT_Mu9_IP6_part1", &HLT_Mu9_IP6_part1, &b_HLT_Mu9_IP6_part1);
   TRY_SET_BRANCH("HLT_Mu9_IP6_part2", &HLT_Mu9_IP6_part2, &b_HLT_Mu9_IP6_part2);
   TRY_SET_BRANCH("HLT_Mu9_IP6_part3", &HLT_Mu9_IP6_part3, &b_HLT_Mu9_IP6_part3);
   TRY_SET_BRANCH("HLT_Mu9_IP6_part4", &HLT_Mu9_IP6_part4, &b_HLT_Mu9_IP6_part4);
   TRY_SET_BRANCH("HLT_Mu8_IP3_part0", &HLT_Mu8_IP3_part0, &b_HLT_Mu8_IP3_part0);
   TRY_SET_BRANCH("HLT_Mu8_IP3_part1", &HLT_Mu8_IP3_part1, &b_HLT_Mu8_IP3_part1);
   TRY_SET_BRANCH("HLT_Mu8_IP3_part2", &HLT_Mu8_IP3_part2, &b_HLT_Mu8_IP3_part2);
   TRY_SET_BRANCH("HLT_Mu8_IP3_part3", &HLT_Mu8_IP3_part3, &b_HLT_Mu8_IP3_part3);
   TRY_SET_BRANCH("HLT_Mu8_IP3_part4", &HLT_Mu8_IP3_part4, &b_HLT_Mu8_IP3_part4);
   TRY_SET_BRANCH("HLT_QuadPFJet105_88_76_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1", &HLT_QuadPFJet105_88_76_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1, &b_HLT_QuadPFJet105_88_76_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1);
   TRY_SET_BRANCH("HLT_TrkMu6NoFiltersNoVtx", &HLT_TrkMu6NoFiltersNoVtx, &b_HLT_TrkMu6NoFiltersNoVtx);
   TRY_SET_BRANCH("HLT_TrkMu16NoFiltersNoVtx", &HLT_TrkMu16NoFiltersNoVtx, &b_HLT_TrkMu16NoFiltersNoVtx);
   TRY_SET_BRANCH("HLT_DoubleTrkMu_16_6_NoFiltersNoVtx", &HLT_DoubleTrkMu_16_6_NoFiltersNoVtx, &b_HLT_DoubleTrkMu_16_6_NoFiltersNoVtx);
   TRY_SET_BRANCH("HLT_QuadPFJet70_50_40_30", &HLT_QuadPFJet70_50_40_30, &b_HLT_QuadPFJet70_50_40_30);
   TRY_SET_BRANCH("HLT_QuadPFJet70_50_40_30_PFBTagParticleNet_2BTagSum0p65", &HLT_QuadPFJet70_50_40_30_PFBTagParticleNet_2BTagSum0p65, &b_HLT_QuadPFJet70_50_40_30_PFBTagParticleNet_2BTagSum0p65);
   TRY_SET_BRANCH("HLT_QuadPFJet70_50_40_35_PFBTagParticleNet_2BTagSum0p65", &HLT_QuadPFJet70_50_40_35_PFBTagParticleNet_2BTagSum0p65, &b_HLT_QuadPFJet70_50_40_35_PFBTagParticleNet_2BTagSum0p65);
   TRY_SET_BRANCH("HLT_QuadPFJet70_50_45_35_PFBTagParticleNet_2BTagSum0p65", &HLT_QuadPFJet70_50_45_35_PFBTagParticleNet_2BTagSum0p65, &b_HLT_QuadPFJet70_50_45_35_PFBTagParticleNet_2BTagSum0p65);
   TRY_SET_BRANCH("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBTagParticleNet_2BTagSum0p65", &HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBTagParticleNet_2BTagSum0p65, &b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBTagParticleNet_2BTagSum0p65);
   TRY_SET_BRANCH("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_QuadPFJet70_50_40_30", &HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_QuadPFJet70_50_40_30, &b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_QuadPFJet70_50_40_30);
   TRY_SET_BRANCH("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_QuadPFJet70_50_40_30_PFBTagParticleNet_2BTagSum0p65", &HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_QuadPFJet70_50_40_30_PFBTagParticleNet_2BTagSum0p65, &b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_QuadPFJet70_50_40_30_PFBTagParticleNet_2BTagSum0p65);
   TRY_SET_BRANCH("HLT_AK8PFJet230_SoftDropMass40", &HLT_AK8PFJet230_SoftDropMass40, &b_HLT_AK8PFJet230_SoftDropMass40);
   TRY_SET_BRANCH("HLT_AK8PFJet230_SoftDropMass40_PFAK8ParticleNetBB0p35", &HLT_AK8PFJet230_SoftDropMass40_PFAK8ParticleNetBB0p35, &b_HLT_AK8PFJet230_SoftDropMass40_PFAK8ParticleNetBB0p35);
   TRY_SET_BRANCH("HLT_AK8PFJet250_SoftDropMass40_PFAK8ParticleNetBB0p35", &HLT_AK8PFJet250_SoftDropMass40_PFAK8ParticleNetBB0p35, &b_HLT_AK8PFJet250_SoftDropMass40_PFAK8ParticleNetBB0p35);
   TRY_SET_BRANCH("HLT_AK8PFJet275_SoftDropMass40_PFAK8ParticleNetBB0p35", &HLT_AK8PFJet275_SoftDropMass40_PFAK8ParticleNetBB0p35, &b_HLT_AK8PFJet275_SoftDropMass40_PFAK8ParticleNetBB0p35);
   TRY_SET_BRANCH("HLT_AK8PFJet400_SoftDropMass40", &HLT_AK8PFJet400_SoftDropMass40, &b_HLT_AK8PFJet400_SoftDropMass40);
   TRY_SET_BRANCH("HLT_AK8PFJet425_SoftDropMass40", &HLT_AK8PFJet425_SoftDropMass40, &b_HLT_AK8PFJet425_SoftDropMass40);
   TRY_SET_BRANCH("HLT_AK8PFJet450_SoftDropMass40", &HLT_AK8PFJet450_SoftDropMass40, &b_HLT_AK8PFJet450_SoftDropMass40);
   TRY_SET_BRANCH("HLT_AK8PFJet230_SoftDropMass40_PFAK8ParticleNetTauTau0p30", &HLT_AK8PFJet230_SoftDropMass40_PFAK8ParticleNetTauTau0p30, &b_HLT_AK8PFJet230_SoftDropMass40_PFAK8ParticleNetTauTau0p30);
   TRY_SET_BRANCH("HLT_AK8PFJet250_SoftDropMass40_PFAK8ParticleNetTauTau0p30", &HLT_AK8PFJet250_SoftDropMass40_PFAK8ParticleNetTauTau0p30, &b_HLT_AK8PFJet250_SoftDropMass40_PFAK8ParticleNetTauTau0p30);
   TRY_SET_BRANCH("HLT_AK8PFJet275_SoftDropMass40_PFAK8ParticleNetTauTau0p30", &HLT_AK8PFJet275_SoftDropMass40_PFAK8ParticleNetTauTau0p30, &b_HLT_AK8PFJet275_SoftDropMass40_PFAK8ParticleNetTauTau0p30);
   TRY_SET_BRANCH("HLT_IsoMu50_AK8PFJet230_SoftDropMass40", &HLT_IsoMu50_AK8PFJet230_SoftDropMass40, &b_HLT_IsoMu50_AK8PFJet230_SoftDropMass40);
   TRY_SET_BRANCH("HLT_IsoMu50_AK8PFJet230_SoftDropMass40_PFAK8ParticleNetBB0p35", &HLT_IsoMu50_AK8PFJet230_SoftDropMass40_PFAK8ParticleNetBB0p35, &b_HLT_IsoMu50_AK8PFJet230_SoftDropMass40_PFAK8ParticleNetBB0p35);
   TRY_SET_BRANCH("HLT_Ele50_CaloIdVT_GsfTrkIdT_AK8PFJet230_SoftDropMass40", &HLT_Ele50_CaloIdVT_GsfTrkIdT_AK8PFJet230_SoftDropMass40, &b_HLT_Ele50_CaloIdVT_GsfTrkIdT_AK8PFJet230_SoftDropMass40);
   TRY_SET_BRANCH("HLT_Ele50_CaloIdVT_GsfTrkIdT_AK8PFJet230_SoftDropMass40_PFAK8ParticleNetBB0p35", &HLT_Ele50_CaloIdVT_GsfTrkIdT_AK8PFJet230_SoftDropMass40_PFAK8ParticleNetBB0p35, &b_HLT_Ele50_CaloIdVT_GsfTrkIdT_AK8PFJet230_SoftDropMass40_PFAK8ParticleNetBB0p35);
   TRY_SET_BRANCH("HLTriggerFinalPath", &HLTriggerFinalPath, &b_HLTriggerFinalPath);
   TRY_SET_BRANCH("Flag_HBHENoiseFilter", &Flag_HBHENoiseFilter, &b_Flag_HBHENoiseFilter);
   TRY_SET_BRANCH("Flag_HBHENoiseIsoFilter", &Flag_HBHENoiseIsoFilter, &b_Flag_HBHENoiseIsoFilter);
   TRY_SET_BRANCH("Flag_CSCTightHaloFilter", &Flag_CSCTightHaloFilter, &b_Flag_CSCTightHaloFilter);
   TRY_SET_BRANCH("Flag_CSCTightHaloTrkMuUnvetoFilter", &Flag_CSCTightHaloTrkMuUnvetoFilter, &b_Flag_CSCTightHaloTrkMuUnvetoFilter);
   TRY_SET_BRANCH("Flag_CSCTightHalo2015Filter", &Flag_CSCTightHalo2015Filter, &b_Flag_CSCTightHalo2015Filter);
   TRY_SET_BRANCH("Flag_globalTightHalo2016Filter", &Flag_globalTightHalo2016Filter, &b_Flag_globalTightHalo2016Filter);
   TRY_SET_BRANCH("Flag_globalSuperTightHalo2016Filter", &Flag_globalSuperTightHalo2016Filter, &b_Flag_globalSuperTightHalo2016Filter);
   TRY_SET_BRANCH("Flag_HcalStripHaloFilter", &Flag_HcalStripHaloFilter, &b_Flag_HcalStripHaloFilter);
   TRY_SET_BRANCH("Flag_hcalLaserEventFilter", &Flag_hcalLaserEventFilter, &b_Flag_hcalLaserEventFilter);
   TRY_SET_BRANCH("Flag_EcalDeadCellTriggerPrimitiveFilter", &Flag_EcalDeadCellTriggerPrimitiveFilter, &b_Flag_EcalDeadCellTriggerPrimitiveFilter);
   TRY_SET_BRANCH("Flag_EcalDeadCellBoundaryEnergyFilter", &Flag_EcalDeadCellBoundaryEnergyFilter, &b_Flag_EcalDeadCellBoundaryEnergyFilter);
   TRY_SET_BRANCH("Flag_ecalBadCalibFilter", &Flag_ecalBadCalibFilter, &b_Flag_ecalBadCalibFilter);
   TRY_SET_BRANCH("Flag_goodVertices", &Flag_goodVertices, &b_Flag_goodVertices);
   TRY_SET_BRANCH("Flag_eeBadScFilter", &Flag_eeBadScFilter, &b_Flag_eeBadScFilter);
   TRY_SET_BRANCH("Flag_ecalLaserCorrFilter", &Flag_ecalLaserCorrFilter, &b_Flag_ecalLaserCorrFilter);
   TRY_SET_BRANCH("Flag_trkPOGFilters", &Flag_trkPOGFilters, &b_Flag_trkPOGFilters);
   TRY_SET_BRANCH("Flag_chargedHadronTrackResolutionFilter", &Flag_chargedHadronTrackResolutionFilter, &b_Flag_chargedHadronTrackResolutionFilter);
   TRY_SET_BRANCH("Flag_muonBadTrackFilter", &Flag_muonBadTrackFilter, &b_Flag_muonBadTrackFilter);
   TRY_SET_BRANCH("Flag_BadChargedCandidateFilter", &Flag_BadChargedCandidateFilter, &b_Flag_BadChargedCandidateFilter);
   TRY_SET_BRANCH("Flag_BadPFMuonFilter", &Flag_BadPFMuonFilter, &b_Flag_BadPFMuonFilter);
   TRY_SET_BRANCH("Flag_BadChargedCandidateSummer16Filter", &Flag_BadChargedCandidateSummer16Filter, &b_Flag_BadChargedCandidateSummer16Filter);
   TRY_SET_BRANCH("Flag_BadPFMuonSummer16Filter", &Flag_BadPFMuonSummer16Filter, &b_Flag_BadPFMuonSummer16Filter);
   TRY_SET_BRANCH("Flag_trkPOG_manystripclus53X", &Flag_trkPOG_manystripclus53X, &b_Flag_trkPOG_manystripclus53X);
   TRY_SET_BRANCH("Flag_trkPOG_toomanystripclus53X", &Flag_trkPOG_toomanystripclus53X, &b_Flag_trkPOG_toomanystripclus53X);
   TRY_SET_BRANCH("Flag_trkPOG_logErrorTooManyClusters", &Flag_trkPOG_logErrorTooManyClusters, &b_Flag_trkPOG_logErrorTooManyClusters);
   TRY_SET_BRANCH("Flag_METFilters", &Flag_METFilters, &b_Flag_METFilters);
   TRY_SET_BRANCH("L1Reco_step", &L1Reco_step, &b_L1Reco_step);
   TRY_SET_BRANCH("L1_AlwaysTrue", &L1_AlwaysTrue, &b_L1_AlwaysTrue);
   TRY_SET_BRANCH("L1_BPTX_AND_Ref1_VME", &L1_BPTX_AND_Ref1_VME, &b_L1_BPTX_AND_Ref1_VME);
   TRY_SET_BRANCH("L1_BPTX_AND_Ref3_VME", &L1_BPTX_AND_Ref3_VME, &b_L1_BPTX_AND_Ref3_VME);
   TRY_SET_BRANCH("L1_BPTX_AND_Ref4_VME", &L1_BPTX_AND_Ref4_VME, &b_L1_BPTX_AND_Ref4_VME);
   TRY_SET_BRANCH("L1_BPTX_BeamGas_B1_VME", &L1_BPTX_BeamGas_B1_VME, &b_L1_BPTX_BeamGas_B1_VME);
   TRY_SET_BRANCH("L1_BPTX_BeamGas_B2_VME", &L1_BPTX_BeamGas_B2_VME, &b_L1_BPTX_BeamGas_B2_VME);
   TRY_SET_BRANCH("L1_BPTX_BeamGas_Ref1_VME", &L1_BPTX_BeamGas_Ref1_VME, &b_L1_BPTX_BeamGas_Ref1_VME);
   TRY_SET_BRANCH("L1_BPTX_BeamGas_Ref2_VME", &L1_BPTX_BeamGas_Ref2_VME, &b_L1_BPTX_BeamGas_Ref2_VME);
   TRY_SET_BRANCH("L1_BPTX_NotOR_VME", &L1_BPTX_NotOR_VME, &b_L1_BPTX_NotOR_VME);
   TRY_SET_BRANCH("L1_BPTX_OR_Ref3_VME", &L1_BPTX_OR_Ref3_VME, &b_L1_BPTX_OR_Ref3_VME);
   TRY_SET_BRANCH("L1_BPTX_OR_Ref4_VME", &L1_BPTX_OR_Ref4_VME, &b_L1_BPTX_OR_Ref4_VME);
   TRY_SET_BRANCH("L1_BPTX_RefAND_VME", &L1_BPTX_RefAND_VME, &b_L1_BPTX_RefAND_VME);
   TRY_SET_BRANCH("L1_BptxMinus", &L1_BptxMinus, &b_L1_BptxMinus);
   TRY_SET_BRANCH("L1_BptxOR", &L1_BptxOR, &b_L1_BptxOR);
   TRY_SET_BRANCH("L1_BptxPlus", &L1_BptxPlus, &b_L1_BptxPlus);
   TRY_SET_BRANCH("L1_BptxXOR", &L1_BptxXOR, &b_L1_BptxXOR);
   TRY_SET_BRANCH("L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142", &L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142, &b_L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142);
   TRY_SET_BRANCH("L1_DoubleEG8er2p5_HTT260er", &L1_DoubleEG8er2p5_HTT260er, &b_L1_DoubleEG8er2p5_HTT260er);
   TRY_SET_BRANCH("L1_DoubleEG8er2p5_HTT280er", &L1_DoubleEG8er2p5_HTT280er, &b_L1_DoubleEG8er2p5_HTT280er);
   TRY_SET_BRANCH("L1_DoubleEG8er2p5_HTT300er", &L1_DoubleEG8er2p5_HTT300er, &b_L1_DoubleEG8er2p5_HTT300er);
   TRY_SET_BRANCH("L1_DoubleEG8er2p5_HTT320er", &L1_DoubleEG8er2p5_HTT320er, &b_L1_DoubleEG8er2p5_HTT320er);
   TRY_SET_BRANCH("L1_DoubleEG8er2p5_HTT340er", &L1_DoubleEG8er2p5_HTT340er, &b_L1_DoubleEG8er2p5_HTT340er);
   TRY_SET_BRANCH("L1_DoubleEG_15_10_er2p5", &L1_DoubleEG_15_10_er2p5, &b_L1_DoubleEG_15_10_er2p5);
   TRY_SET_BRANCH("L1_DoubleEG_20_10_er2p5", &L1_DoubleEG_20_10_er2p5, &b_L1_DoubleEG_20_10_er2p5);
   TRY_SET_BRANCH("L1_DoubleEG_22_10_er2p5", &L1_DoubleEG_22_10_er2p5, &b_L1_DoubleEG_22_10_er2p5);
   TRY_SET_BRANCH("L1_DoubleEG_25_12_er2p5", &L1_DoubleEG_25_12_er2p5, &b_L1_DoubleEG_25_12_er2p5);
   TRY_SET_BRANCH("L1_DoubleEG_25_14_er2p5", &L1_DoubleEG_25_14_er2p5, &b_L1_DoubleEG_25_14_er2p5);
   TRY_SET_BRANCH("L1_DoubleEG_27_14_er2p5", &L1_DoubleEG_27_14_er2p5, &b_L1_DoubleEG_27_14_er2p5);
   TRY_SET_BRANCH("L1_DoubleEG_LooseIso20_10_er2p5", &L1_DoubleEG_LooseIso20_10_er2p5, &b_L1_DoubleEG_LooseIso20_10_er2p5);
   TRY_SET_BRANCH("L1_DoubleEG_LooseIso22_10_er2p5", &L1_DoubleEG_LooseIso22_10_er2p5, &b_L1_DoubleEG_LooseIso22_10_er2p5);
   TRY_SET_BRANCH("L1_DoubleEG_LooseIso22_12_er2p5", &L1_DoubleEG_LooseIso22_12_er2p5, &b_L1_DoubleEG_LooseIso22_12_er2p5);
   TRY_SET_BRANCH("L1_DoubleEG_LooseIso25_12_er2p5", &L1_DoubleEG_LooseIso25_12_er2p5, &b_L1_DoubleEG_LooseIso25_12_er2p5);
   TRY_SET_BRANCH("L1_DoubleIsoTau32er2p1", &L1_DoubleIsoTau32er2p1, &b_L1_DoubleIsoTau32er2p1);
   TRY_SET_BRANCH("L1_DoubleIsoTau34er2p1", &L1_DoubleIsoTau34er2p1, &b_L1_DoubleIsoTau34er2p1);
   TRY_SET_BRANCH("L1_DoubleIsoTau36er2p1", &L1_DoubleIsoTau36er2p1, &b_L1_DoubleIsoTau36er2p1);
   TRY_SET_BRANCH("L1_DoubleJet100er2p3_dEta_Max1p6", &L1_DoubleJet100er2p3_dEta_Max1p6, &b_L1_DoubleJet100er2p3_dEta_Max1p6);
   TRY_SET_BRANCH("L1_DoubleJet100er2p5", &L1_DoubleJet100er2p5, &b_L1_DoubleJet100er2p5);
   TRY_SET_BRANCH("L1_DoubleJet112er2p3_dEta_Max1p6", &L1_DoubleJet112er2p3_dEta_Max1p6, &b_L1_DoubleJet112er2p3_dEta_Max1p6);
   TRY_SET_BRANCH("L1_DoubleJet120er2p5", &L1_DoubleJet120er2p5, &b_L1_DoubleJet120er2p5);
   TRY_SET_BRANCH("L1_DoubleJet150er2p5", &L1_DoubleJet150er2p5, &b_L1_DoubleJet150er2p5);
   TRY_SET_BRANCH("L1_DoubleJet30er2p5_Mass_Min150_dEta_Max1p5", &L1_DoubleJet30er2p5_Mass_Min150_dEta_Max1p5, &b_L1_DoubleJet30er2p5_Mass_Min150_dEta_Max1p5);
   TRY_SET_BRANCH("L1_DoubleJet30er2p5_Mass_Min200_dEta_Max1p5", &L1_DoubleJet30er2p5_Mass_Min200_dEta_Max1p5, &b_L1_DoubleJet30er2p5_Mass_Min200_dEta_Max1p5);
   TRY_SET_BRANCH("L1_DoubleJet30er2p5_Mass_Min250_dEta_Max1p5", &L1_DoubleJet30er2p5_Mass_Min250_dEta_Max1p5, &b_L1_DoubleJet30er2p5_Mass_Min250_dEta_Max1p5);
   TRY_SET_BRANCH("L1_DoubleJet30er2p5_Mass_Min300_dEta_Max1p5", &L1_DoubleJet30er2p5_Mass_Min300_dEta_Max1p5, &b_L1_DoubleJet30er2p5_Mass_Min300_dEta_Max1p5);
   TRY_SET_BRANCH("L1_DoubleJet30er2p5_Mass_Min330_dEta_Max1p5", &L1_DoubleJet30er2p5_Mass_Min330_dEta_Max1p5, &b_L1_DoubleJet30er2p5_Mass_Min330_dEta_Max1p5);
   TRY_SET_BRANCH("L1_DoubleJet30er2p5_Mass_Min360_dEta_Max1p5", &L1_DoubleJet30er2p5_Mass_Min360_dEta_Max1p5, &b_L1_DoubleJet30er2p5_Mass_Min360_dEta_Max1p5);
   TRY_SET_BRANCH("L1_DoubleJet35_Mass_Min450_IsoTau45_RmOvlp", &L1_DoubleJet35_Mass_Min450_IsoTau45_RmOvlp, &b_L1_DoubleJet35_Mass_Min450_IsoTau45_RmOvlp);
   TRY_SET_BRANCH("L1_DoubleJet40er2p5", &L1_DoubleJet40er2p5, &b_L1_DoubleJet40er2p5);
   TRY_SET_BRANCH("L1_DoubleJet_100_30_DoubleJet30_Mass_Min620", &L1_DoubleJet_100_30_DoubleJet30_Mass_Min620, &b_L1_DoubleJet_100_30_DoubleJet30_Mass_Min620);
   TRY_SET_BRANCH("L1_DoubleJet_110_35_DoubleJet35_Mass_Min620", &L1_DoubleJet_110_35_DoubleJet35_Mass_Min620, &b_L1_DoubleJet_110_35_DoubleJet35_Mass_Min620);
   TRY_SET_BRANCH("L1_DoubleJet_115_40_DoubleJet40_Mass_Min620", &L1_DoubleJet_115_40_DoubleJet40_Mass_Min620, &b_L1_DoubleJet_115_40_DoubleJet40_Mass_Min620);
   TRY_SET_BRANCH("L1_DoubleJet_115_40_DoubleJet40_Mass_Min620_Jet60TT28", &L1_DoubleJet_115_40_DoubleJet40_Mass_Min620_Jet60TT28, &b_L1_DoubleJet_115_40_DoubleJet40_Mass_Min620_Jet60TT28);
   TRY_SET_BRANCH("L1_DoubleJet_120_45_DoubleJet45_Mass_Min620", &L1_DoubleJet_120_45_DoubleJet45_Mass_Min620, &b_L1_DoubleJet_120_45_DoubleJet45_Mass_Min620);
   TRY_SET_BRANCH("L1_DoubleJet_120_45_DoubleJet45_Mass_Min620_Jet60TT28", &L1_DoubleJet_120_45_DoubleJet45_Mass_Min620_Jet60TT28, &b_L1_DoubleJet_120_45_DoubleJet45_Mass_Min620_Jet60TT28);
   TRY_SET_BRANCH("L1_DoubleJet_80_30_Mass_Min420_DoubleMu0_SQ", &L1_DoubleJet_80_30_Mass_Min420_DoubleMu0_SQ, &b_L1_DoubleJet_80_30_Mass_Min420_DoubleMu0_SQ);
   TRY_SET_BRANCH("L1_DoubleJet_80_30_Mass_Min420_IsoTau40_RmOvlp", &L1_DoubleJet_80_30_Mass_Min420_IsoTau40_RmOvlp, &b_L1_DoubleJet_80_30_Mass_Min420_IsoTau40_RmOvlp);
   TRY_SET_BRANCH("L1_DoubleJet_80_30_Mass_Min420_Mu8", &L1_DoubleJet_80_30_Mass_Min420_Mu8, &b_L1_DoubleJet_80_30_Mass_Min420_Mu8);
   TRY_SET_BRANCH("L1_DoubleJet_90_30_DoubleJet30_Mass_Min620", &L1_DoubleJet_90_30_DoubleJet30_Mass_Min620, &b_L1_DoubleJet_90_30_DoubleJet30_Mass_Min620);
   TRY_SET_BRANCH("L1_DoubleLooseIsoEG22er2p1", &L1_DoubleLooseIsoEG22er2p1, &b_L1_DoubleLooseIsoEG22er2p1);
   TRY_SET_BRANCH("L1_DoubleLooseIsoEG24er2p1", &L1_DoubleLooseIsoEG24er2p1, &b_L1_DoubleLooseIsoEG24er2p1);
   TRY_SET_BRANCH("L1_DoubleMu0", &L1_DoubleMu0, &b_L1_DoubleMu0);
   TRY_SET_BRANCH("L1_DoubleMu0_Mass_Min1", &L1_DoubleMu0_Mass_Min1, &b_L1_DoubleMu0_Mass_Min1);
   TRY_SET_BRANCH("L1_DoubleMu0_OQ", &L1_DoubleMu0_OQ, &b_L1_DoubleMu0_OQ);
   TRY_SET_BRANCH("L1_DoubleMu0_SQ", &L1_DoubleMu0_SQ, &b_L1_DoubleMu0_SQ);
   TRY_SET_BRANCH("L1_DoubleMu0_SQ_OS", &L1_DoubleMu0_SQ_OS, &b_L1_DoubleMu0_SQ_OS);
   TRY_SET_BRANCH("L1_DoubleMu0_dR_Max1p6_Jet90er2p5_dR_Max0p8", &L1_DoubleMu0_dR_Max1p6_Jet90er2p5_dR_Max0p8, &b_L1_DoubleMu0_dR_Max1p6_Jet90er2p5_dR_Max0p8);
   TRY_SET_BRANCH("L1_DoubleMu0er1p4_SQ_OS_dR_Max1p4", &L1_DoubleMu0er1p4_SQ_OS_dR_Max1p4, &b_L1_DoubleMu0er1p4_SQ_OS_dR_Max1p4);
   TRY_SET_BRANCH("L1_DoubleMu0er1p5_SQ", &L1_DoubleMu0er1p5_SQ, &b_L1_DoubleMu0er1p5_SQ);
   TRY_SET_BRANCH("L1_DoubleMu0er1p5_SQ_OS", &L1_DoubleMu0er1p5_SQ_OS, &b_L1_DoubleMu0er1p5_SQ_OS);
   TRY_SET_BRANCH("L1_DoubleMu0er1p5_SQ_OS_dR_Max1p4", &L1_DoubleMu0er1p5_SQ_OS_dR_Max1p4, &b_L1_DoubleMu0er1p5_SQ_OS_dR_Max1p4);
   TRY_SET_BRANCH("L1_DoubleMu0er1p5_SQ_dR_Max1p4", &L1_DoubleMu0er1p5_SQ_dR_Max1p4, &b_L1_DoubleMu0er1p5_SQ_dR_Max1p4);
   TRY_SET_BRANCH("L1_DoubleMu0er2p0_SQ_OS_dR_Max1p4", &L1_DoubleMu0er2p0_SQ_OS_dR_Max1p4, &b_L1_DoubleMu0er2p0_SQ_OS_dR_Max1p4);
   TRY_SET_BRANCH("L1_DoubleMu0er2p0_SQ_dR_Max1p4", &L1_DoubleMu0er2p0_SQ_dR_Max1p4, &b_L1_DoubleMu0er2p0_SQ_dR_Max1p4);
   TRY_SET_BRANCH("L1_DoubleMu10_SQ", &L1_DoubleMu10_SQ, &b_L1_DoubleMu10_SQ);
   TRY_SET_BRANCH("L1_DoubleMu18er2p1", &L1_DoubleMu18er2p1, &b_L1_DoubleMu18er2p1);
   TRY_SET_BRANCH("L1_DoubleMu3_OS_DoubleEG7p5Upsilon", &L1_DoubleMu3_OS_DoubleEG7p5Upsilon, &b_L1_DoubleMu3_OS_DoubleEG7p5Upsilon);
   TRY_SET_BRANCH("L1_DoubleMu3_SQ_ETMHF50_HTT60er", &L1_DoubleMu3_SQ_ETMHF50_HTT60er, &b_L1_DoubleMu3_SQ_ETMHF50_HTT60er);
   TRY_SET_BRANCH("L1_DoubleMu3_SQ_ETMHF50_Jet60er2p5", &L1_DoubleMu3_SQ_ETMHF50_Jet60er2p5, &b_L1_DoubleMu3_SQ_ETMHF50_Jet60er2p5);
   TRY_SET_BRANCH("L1_DoubleMu3_SQ_ETMHF50_Jet60er2p5_OR_DoubleJet40er2p5", &L1_DoubleMu3_SQ_ETMHF50_Jet60er2p5_OR_DoubleJet40er2p5, &b_L1_DoubleMu3_SQ_ETMHF50_Jet60er2p5_OR_DoubleJet40er2p5);
   TRY_SET_BRANCH("L1_DoubleMu3_SQ_ETMHF60_Jet60er2p5", &L1_DoubleMu3_SQ_ETMHF60_Jet60er2p5, &b_L1_DoubleMu3_SQ_ETMHF60_Jet60er2p5);
   TRY_SET_BRANCH("L1_DoubleMu3_SQ_HTT220er", &L1_DoubleMu3_SQ_HTT220er, &b_L1_DoubleMu3_SQ_HTT220er);
   TRY_SET_BRANCH("L1_DoubleMu3_SQ_HTT240er", &L1_DoubleMu3_SQ_HTT240er, &b_L1_DoubleMu3_SQ_HTT240er);
   TRY_SET_BRANCH("L1_DoubleMu3_SQ_HTT260er", &L1_DoubleMu3_SQ_HTT260er, &b_L1_DoubleMu3_SQ_HTT260er);
   TRY_SET_BRANCH("L1_DoubleMu3_dR_Max1p6_Jet90er2p5_dR_Max0p8", &L1_DoubleMu3_dR_Max1p6_Jet90er2p5_dR_Max0p8, &b_L1_DoubleMu3_dR_Max1p6_Jet90er2p5_dR_Max0p8);
   TRY_SET_BRANCH("L1_DoubleMu4_SQ_EG9er2p5", &L1_DoubleMu4_SQ_EG9er2p5, &b_L1_DoubleMu4_SQ_EG9er2p5);
   TRY_SET_BRANCH("L1_DoubleMu4_SQ_OS", &L1_DoubleMu4_SQ_OS, &b_L1_DoubleMu4_SQ_OS);
   TRY_SET_BRANCH("L1_DoubleMu4_SQ_OS_dR_Max1p2", &L1_DoubleMu4_SQ_OS_dR_Max1p2, &b_L1_DoubleMu4_SQ_OS_dR_Max1p2);
   TRY_SET_BRANCH("L1_DoubleMu4p5_SQ_OS", &L1_DoubleMu4p5_SQ_OS, &b_L1_DoubleMu4p5_SQ_OS);
   TRY_SET_BRANCH("L1_DoubleMu4p5_SQ_OS_dR_Max1p2", &L1_DoubleMu4p5_SQ_OS_dR_Max1p2, &b_L1_DoubleMu4p5_SQ_OS_dR_Max1p2);
   TRY_SET_BRANCH("L1_DoubleMu4p5er2p0_SQ_OS", &L1_DoubleMu4p5er2p0_SQ_OS, &b_L1_DoubleMu4p5er2p0_SQ_OS);
   TRY_SET_BRANCH("L1_DoubleMu4p5er2p0_SQ_OS_Mass7to18", &L1_DoubleMu4p5er2p0_SQ_OS_Mass7to18, &b_L1_DoubleMu4p5er2p0_SQ_OS_Mass7to18);
   TRY_SET_BRANCH("L1_DoubleMu5Upsilon_OS_DoubleEG3", &L1_DoubleMu5Upsilon_OS_DoubleEG3, &b_L1_DoubleMu5Upsilon_OS_DoubleEG3);
   TRY_SET_BRANCH("L1_DoubleMu5_SQ_EG9er2p5", &L1_DoubleMu5_SQ_EG9er2p5, &b_L1_DoubleMu5_SQ_EG9er2p5);
   TRY_SET_BRANCH("L1_DoubleMu9_SQ", &L1_DoubleMu9_SQ, &b_L1_DoubleMu9_SQ);
   TRY_SET_BRANCH("L1_DoubleMu_12_5", &L1_DoubleMu_12_5, &b_L1_DoubleMu_12_5);
   TRY_SET_BRANCH("L1_DoubleMu_15_5_SQ", &L1_DoubleMu_15_5_SQ, &b_L1_DoubleMu_15_5_SQ);
   TRY_SET_BRANCH("L1_DoubleMu_15_7", &L1_DoubleMu_15_7, &b_L1_DoubleMu_15_7);
   TRY_SET_BRANCH("L1_DoubleMu_15_7_Mass_Min1", &L1_DoubleMu_15_7_Mass_Min1, &b_L1_DoubleMu_15_7_Mass_Min1);
   TRY_SET_BRANCH("L1_DoubleMu_15_7_SQ", &L1_DoubleMu_15_7_SQ, &b_L1_DoubleMu_15_7_SQ);
   TRY_SET_BRANCH("L1_DoubleTau70er2p1", &L1_DoubleTau70er2p1, &b_L1_DoubleTau70er2p1);
   TRY_SET_BRANCH("L1_ETM120", &L1_ETM120, &b_L1_ETM120);
   TRY_SET_BRANCH("L1_ETM150", &L1_ETM150, &b_L1_ETM150);
   TRY_SET_BRANCH("L1_ETMHF100", &L1_ETMHF100, &b_L1_ETMHF100);
   TRY_SET_BRANCH("L1_ETMHF100_HTT60er", &L1_ETMHF100_HTT60er, &b_L1_ETMHF100_HTT60er);
   TRY_SET_BRANCH("L1_ETMHF110", &L1_ETMHF110, &b_L1_ETMHF110);
   TRY_SET_BRANCH("L1_ETMHF110_HTT60er", &L1_ETMHF110_HTT60er, &b_L1_ETMHF110_HTT60er);
   TRY_SET_BRANCH("L1_ETMHF110_HTT60er_NotSecondBunchInTrain", &L1_ETMHF110_HTT60er_NotSecondBunchInTrain, &b_L1_ETMHF110_HTT60er_NotSecondBunchInTrain);
   TRY_SET_BRANCH("L1_ETMHF120", &L1_ETMHF120, &b_L1_ETMHF120);
   TRY_SET_BRANCH("L1_ETMHF120_HTT60er", &L1_ETMHF120_HTT60er, &b_L1_ETMHF120_HTT60er);
   TRY_SET_BRANCH("L1_ETMHF120_NotSecondBunchInTrain", &L1_ETMHF120_NotSecondBunchInTrain, &b_L1_ETMHF120_NotSecondBunchInTrain);
   TRY_SET_BRANCH("L1_ETMHF130", &L1_ETMHF130, &b_L1_ETMHF130);
   TRY_SET_BRANCH("L1_ETMHF130_HTT60er", &L1_ETMHF130_HTT60er, &b_L1_ETMHF130_HTT60er);
   TRY_SET_BRANCH("L1_ETMHF140", &L1_ETMHF140, &b_L1_ETMHF140);
   TRY_SET_BRANCH("L1_ETMHF150", &L1_ETMHF150, &b_L1_ETMHF150);
   TRY_SET_BRANCH("L1_ETMHF90_HTT60er", &L1_ETMHF90_HTT60er, &b_L1_ETMHF90_HTT60er);
   TRY_SET_BRANCH("L1_ETT1200", &L1_ETT1200, &b_L1_ETT1200);
   TRY_SET_BRANCH("L1_ETT1600", &L1_ETT1600, &b_L1_ETT1600);
   TRY_SET_BRANCH("L1_ETT2000", &L1_ETT2000, &b_L1_ETT2000);
   TRY_SET_BRANCH("L1_FirstBunchAfterTrain", &L1_FirstBunchAfterTrain, &b_L1_FirstBunchAfterTrain);
   TRY_SET_BRANCH("L1_FirstBunchBeforeTrain", &L1_FirstBunchBeforeTrain, &b_L1_FirstBunchBeforeTrain);
   TRY_SET_BRANCH("L1_FirstBunchInTrain", &L1_FirstBunchInTrain, &b_L1_FirstBunchInTrain);
   TRY_SET_BRANCH("L1_FirstCollisionInOrbit", &L1_FirstCollisionInOrbit, &b_L1_FirstCollisionInOrbit);
   TRY_SET_BRANCH("L1_FirstCollisionInTrain", &L1_FirstCollisionInTrain, &b_L1_FirstCollisionInTrain);
   TRY_SET_BRANCH("L1_HCAL_LaserMon_Trig", &L1_HCAL_LaserMon_Trig, &b_L1_HCAL_LaserMon_Trig);
   TRY_SET_BRANCH("L1_HCAL_LaserMon_Veto", &L1_HCAL_LaserMon_Veto, &b_L1_HCAL_LaserMon_Veto);
   TRY_SET_BRANCH("L1_HTT120er", &L1_HTT120er, &b_L1_HTT120er);
   TRY_SET_BRANCH("L1_HTT160er", &L1_HTT160er, &b_L1_HTT160er);
   TRY_SET_BRANCH("L1_HTT200er", &L1_HTT200er, &b_L1_HTT200er);
   TRY_SET_BRANCH("L1_HTT255er", &L1_HTT255er, &b_L1_HTT255er);
   TRY_SET_BRANCH("L1_HTT280er", &L1_HTT280er, &b_L1_HTT280er);
   TRY_SET_BRANCH("L1_HTT280er_QuadJet_70_55_40_35_er2p4", &L1_HTT280er_QuadJet_70_55_40_35_er2p4, &b_L1_HTT280er_QuadJet_70_55_40_35_er2p4);
   TRY_SET_BRANCH("L1_HTT320er", &L1_HTT320er, &b_L1_HTT320er);
   TRY_SET_BRANCH("L1_HTT320er_QuadJet_70_55_40_40_er2p4", &L1_HTT320er_QuadJet_70_55_40_40_er2p4, &b_L1_HTT320er_QuadJet_70_55_40_40_er2p4);
   TRY_SET_BRANCH("L1_HTT320er_QuadJet_80_60_er2p1_45_40_er2p3", &L1_HTT320er_QuadJet_80_60_er2p1_45_40_er2p3, &b_L1_HTT320er_QuadJet_80_60_er2p1_45_40_er2p3);
   TRY_SET_BRANCH("L1_HTT320er_QuadJet_80_60_er2p1_50_45_er2p3", &L1_HTT320er_QuadJet_80_60_er2p1_50_45_er2p3, &b_L1_HTT320er_QuadJet_80_60_er2p1_50_45_er2p3);
   TRY_SET_BRANCH("L1_HTT360er", &L1_HTT360er, &b_L1_HTT360er);
   TRY_SET_BRANCH("L1_HTT400er", &L1_HTT400er, &b_L1_HTT400er);
   TRY_SET_BRANCH("L1_HTT450er", &L1_HTT450er, &b_L1_HTT450er);
   TRY_SET_BRANCH("L1_IsoEG32er2p5_Mt40", &L1_IsoEG32er2p5_Mt40, &b_L1_IsoEG32er2p5_Mt40);
   TRY_SET_BRANCH("L1_IsoEG32er2p5_Mt44", &L1_IsoEG32er2p5_Mt44, &b_L1_IsoEG32er2p5_Mt44);
   TRY_SET_BRANCH("L1_IsoEG32er2p5_Mt48", &L1_IsoEG32er2p5_Mt48, &b_L1_IsoEG32er2p5_Mt48);
   TRY_SET_BRANCH("L1_IsoTau40er2p1_ETMHF100", &L1_IsoTau40er2p1_ETMHF100, &b_L1_IsoTau40er2p1_ETMHF100);
   TRY_SET_BRANCH("L1_IsoTau40er2p1_ETMHF110", &L1_IsoTau40er2p1_ETMHF110, &b_L1_IsoTau40er2p1_ETMHF110);
   TRY_SET_BRANCH("L1_IsoTau40er2p1_ETMHF120", &L1_IsoTau40er2p1_ETMHF120, &b_L1_IsoTau40er2p1_ETMHF120);
   TRY_SET_BRANCH("L1_IsoTau40er2p1_ETMHF90", &L1_IsoTau40er2p1_ETMHF90, &b_L1_IsoTau40er2p1_ETMHF90);
   TRY_SET_BRANCH("L1_IsolatedBunch", &L1_IsolatedBunch, &b_L1_IsolatedBunch);
   TRY_SET_BRANCH("L1_LastBunchInTrain", &L1_LastBunchInTrain, &b_L1_LastBunchInTrain);
   TRY_SET_BRANCH("L1_LastCollisionInTrain", &L1_LastCollisionInTrain, &b_L1_LastCollisionInTrain);
   TRY_SET_BRANCH("L1_LooseIsoEG22er2p1_IsoTau26er2p1_dR_Min0p3", &L1_LooseIsoEG22er2p1_IsoTau26er2p1_dR_Min0p3, &b_L1_LooseIsoEG22er2p1_IsoTau26er2p1_dR_Min0p3);
   TRY_SET_BRANCH("L1_LooseIsoEG22er2p1_Tau70er2p1_dR_Min0p3", &L1_LooseIsoEG22er2p1_Tau70er2p1_dR_Min0p3, &b_L1_LooseIsoEG22er2p1_Tau70er2p1_dR_Min0p3);
   TRY_SET_BRANCH("L1_LooseIsoEG24er2p1_HTT100er", &L1_LooseIsoEG24er2p1_HTT100er, &b_L1_LooseIsoEG24er2p1_HTT100er);
   TRY_SET_BRANCH("L1_LooseIsoEG24er2p1_IsoTau27er2p1_dR_Min0p3", &L1_LooseIsoEG24er2p1_IsoTau27er2p1_dR_Min0p3, &b_L1_LooseIsoEG24er2p1_IsoTau27er2p1_dR_Min0p3);
   TRY_SET_BRANCH("L1_LooseIsoEG26er2p1_HTT100er", &L1_LooseIsoEG26er2p1_HTT100er, &b_L1_LooseIsoEG26er2p1_HTT100er);
   TRY_SET_BRANCH("L1_LooseIsoEG26er2p1_Jet34er2p5_dR_Min0p3", &L1_LooseIsoEG26er2p1_Jet34er2p5_dR_Min0p3, &b_L1_LooseIsoEG26er2p1_Jet34er2p5_dR_Min0p3);
   TRY_SET_BRANCH("L1_LooseIsoEG28er2p1_HTT100er", &L1_LooseIsoEG28er2p1_HTT100er, &b_L1_LooseIsoEG28er2p1_HTT100er);
   TRY_SET_BRANCH("L1_LooseIsoEG28er2p1_Jet34er2p5_dR_Min0p3", &L1_LooseIsoEG28er2p1_Jet34er2p5_dR_Min0p3, &b_L1_LooseIsoEG28er2p1_Jet34er2p5_dR_Min0p3);
   TRY_SET_BRANCH("L1_LooseIsoEG30er2p1_HTT100er", &L1_LooseIsoEG30er2p1_HTT100er, &b_L1_LooseIsoEG30er2p1_HTT100er);
   TRY_SET_BRANCH("L1_LooseIsoEG30er2p1_Jet34er2p5_dR_Min0p3", &L1_LooseIsoEG30er2p1_Jet34er2p5_dR_Min0p3, &b_L1_LooseIsoEG30er2p1_Jet34er2p5_dR_Min0p3);
   TRY_SET_BRANCH("L1_MinimumBiasHF0_AND_BptxAND", &L1_MinimumBiasHF0_AND_BptxAND, &b_L1_MinimumBiasHF0_AND_BptxAND);
   TRY_SET_BRANCH("L1_Mu10er2p3_Jet32er2p3_dR_Max0p4_DoubleJet32er2p3_dEta_Max1p6", &L1_Mu10er2p3_Jet32er2p3_dR_Max0p4_DoubleJet32er2p3_dEta_Max1p6, &b_L1_Mu10er2p3_Jet32er2p3_dR_Max0p4_DoubleJet32er2p3_dEta_Max1p6);
   TRY_SET_BRANCH("L1_Mu12er2p3_Jet40er2p1_dR_Max0p4_DoubleJet40er2p1_dEta_Max1p6", &L1_Mu12er2p3_Jet40er2p1_dR_Max0p4_DoubleJet40er2p1_dEta_Max1p6, &b_L1_Mu12er2p3_Jet40er2p1_dR_Max0p4_DoubleJet40er2p1_dEta_Max1p6);
   TRY_SET_BRANCH("L1_Mu12er2p3_Jet40er2p3_dR_Max0p4_DoubleJet40er2p3_dEta_Max1p6", &L1_Mu12er2p3_Jet40er2p3_dR_Max0p4_DoubleJet40er2p3_dEta_Max1p6, &b_L1_Mu12er2p3_Jet40er2p3_dR_Max0p4_DoubleJet40er2p3_dEta_Max1p6);
   TRY_SET_BRANCH("L1_Mu18er2p1_Tau24er2p1", &L1_Mu18er2p1_Tau24er2p1, &b_L1_Mu18er2p1_Tau24er2p1);
   TRY_SET_BRANCH("L1_Mu18er2p1_Tau26er2p1", &L1_Mu18er2p1_Tau26er2p1, &b_L1_Mu18er2p1_Tau26er2p1);
   TRY_SET_BRANCH("L1_Mu20_EG10er2p5", &L1_Mu20_EG10er2p5, &b_L1_Mu20_EG10er2p5);
   TRY_SET_BRANCH("L1_Mu22er2p1_IsoTau32er2p1", &L1_Mu22er2p1_IsoTau32er2p1, &b_L1_Mu22er2p1_IsoTau32er2p1);
   TRY_SET_BRANCH("L1_Mu22er2p1_IsoTau34er2p1", &L1_Mu22er2p1_IsoTau34er2p1, &b_L1_Mu22er2p1_IsoTau34er2p1);
   TRY_SET_BRANCH("L1_Mu22er2p1_IsoTau36er2p1", &L1_Mu22er2p1_IsoTau36er2p1, &b_L1_Mu22er2p1_IsoTau36er2p1);
   TRY_SET_BRANCH("L1_Mu22er2p1_IsoTau40er2p1", &L1_Mu22er2p1_IsoTau40er2p1, &b_L1_Mu22er2p1_IsoTau40er2p1);
   TRY_SET_BRANCH("L1_Mu22er2p1_Tau70er2p1", &L1_Mu22er2p1_Tau70er2p1, &b_L1_Mu22er2p1_Tau70er2p1);
   TRY_SET_BRANCH("L1_Mu3_Jet120er2p5_dR_Max0p4", &L1_Mu3_Jet120er2p5_dR_Max0p4, &b_L1_Mu3_Jet120er2p5_dR_Max0p4);
   TRY_SET_BRANCH("L1_Mu3_Jet120er2p5_dR_Max0p8", &L1_Mu3_Jet120er2p5_dR_Max0p8, &b_L1_Mu3_Jet120er2p5_dR_Max0p8);
   TRY_SET_BRANCH("L1_Mu3_Jet16er2p5_dR_Max0p4", &L1_Mu3_Jet16er2p5_dR_Max0p4, &b_L1_Mu3_Jet16er2p5_dR_Max0p4);
   TRY_SET_BRANCH("L1_Mu3_Jet30er2p5", &L1_Mu3_Jet30er2p5, &b_L1_Mu3_Jet30er2p5);
   TRY_SET_BRANCH("L1_Mu3_Jet35er2p5_dR_Max0p4", &L1_Mu3_Jet35er2p5_dR_Max0p4, &b_L1_Mu3_Jet35er2p5_dR_Max0p4);
   TRY_SET_BRANCH("L1_Mu3_Jet60er2p5_dR_Max0p4", &L1_Mu3_Jet60er2p5_dR_Max0p4, &b_L1_Mu3_Jet60er2p5_dR_Max0p4);
   TRY_SET_BRANCH("L1_Mu3_Jet80er2p5_dR_Max0p4", &L1_Mu3_Jet80er2p5_dR_Max0p4, &b_L1_Mu3_Jet80er2p5_dR_Max0p4);
   TRY_SET_BRANCH("L1_Mu3er1p5_Jet100er2p5_ETMHF40", &L1_Mu3er1p5_Jet100er2p5_ETMHF40, &b_L1_Mu3er1p5_Jet100er2p5_ETMHF40);
   TRY_SET_BRANCH("L1_Mu3er1p5_Jet100er2p5_ETMHF50", &L1_Mu3er1p5_Jet100er2p5_ETMHF50, &b_L1_Mu3er1p5_Jet100er2p5_ETMHF50);
   TRY_SET_BRANCH("L1_Mu5_EG23er2p5", &L1_Mu5_EG23er2p5, &b_L1_Mu5_EG23er2p5);
   TRY_SET_BRANCH("L1_Mu5_LooseIsoEG20er2p5", &L1_Mu5_LooseIsoEG20er2p5, &b_L1_Mu5_LooseIsoEG20er2p5);
   TRY_SET_BRANCH("L1_Mu6_DoubleEG10er2p5", &L1_Mu6_DoubleEG10er2p5, &b_L1_Mu6_DoubleEG10er2p5);
   TRY_SET_BRANCH("L1_Mu6_DoubleEG12er2p5", &L1_Mu6_DoubleEG12er2p5, &b_L1_Mu6_DoubleEG12er2p5);
   TRY_SET_BRANCH("L1_Mu6_DoubleEG15er2p5", &L1_Mu6_DoubleEG15er2p5, &b_L1_Mu6_DoubleEG15er2p5);
   TRY_SET_BRANCH("L1_Mu6_DoubleEG17er2p5", &L1_Mu6_DoubleEG17er2p5, &b_L1_Mu6_DoubleEG17er2p5);
   TRY_SET_BRANCH("L1_Mu6_HTT240er", &L1_Mu6_HTT240er, &b_L1_Mu6_HTT240er);
   TRY_SET_BRANCH("L1_Mu6_HTT250er", &L1_Mu6_HTT250er, &b_L1_Mu6_HTT250er);
   TRY_SET_BRANCH("L1_Mu7_EG23er2p5", &L1_Mu7_EG23er2p5, &b_L1_Mu7_EG23er2p5);
   TRY_SET_BRANCH("L1_Mu7_LooseIsoEG20er2p5", &L1_Mu7_LooseIsoEG20er2p5, &b_L1_Mu7_LooseIsoEG20er2p5);
   TRY_SET_BRANCH("L1_Mu7_LooseIsoEG23er2p5", &L1_Mu7_LooseIsoEG23er2p5, &b_L1_Mu7_LooseIsoEG23er2p5);
   TRY_SET_BRANCH("L1_NotBptxOR", &L1_NotBptxOR, &b_L1_NotBptxOR);
   TRY_SET_BRANCH("L1_QuadJet36er2p5_IsoTau52er2p1", &L1_QuadJet36er2p5_IsoTau52er2p1, &b_L1_QuadJet36er2p5_IsoTau52er2p1);
   TRY_SET_BRANCH("L1_QuadJet60er2p5", &L1_QuadJet60er2p5, &b_L1_QuadJet60er2p5);
   TRY_SET_BRANCH("L1_QuadJet_95_75_65_20_DoubleJet_75_65_er2p5_Jet20_FWD3p0", &L1_QuadJet_95_75_65_20_DoubleJet_75_65_er2p5_Jet20_FWD3p0, &b_L1_QuadJet_95_75_65_20_DoubleJet_75_65_er2p5_Jet20_FWD3p0);
   TRY_SET_BRANCH("L1_QuadMu0", &L1_QuadMu0, &b_L1_QuadMu0);
   TRY_SET_BRANCH("L1_QuadMu0_OQ", &L1_QuadMu0_OQ, &b_L1_QuadMu0_OQ);
   TRY_SET_BRANCH("L1_QuadMu0_SQ", &L1_QuadMu0_SQ, &b_L1_QuadMu0_SQ);
   TRY_SET_BRANCH("L1_SecondBunchInTrain", &L1_SecondBunchInTrain, &b_L1_SecondBunchInTrain);
   TRY_SET_BRANCH("L1_SecondLastBunchInTrain", &L1_SecondLastBunchInTrain, &b_L1_SecondLastBunchInTrain);
   TRY_SET_BRANCH("L1_SingleEG10er2p5", &L1_SingleEG10er2p5, &b_L1_SingleEG10er2p5);
   TRY_SET_BRANCH("L1_SingleEG15er2p5", &L1_SingleEG15er2p5, &b_L1_SingleEG15er2p5);
   TRY_SET_BRANCH("L1_SingleEG26er2p5", &L1_SingleEG26er2p5, &b_L1_SingleEG26er2p5);
   TRY_SET_BRANCH("L1_SingleEG34er2p5", &L1_SingleEG34er2p5, &b_L1_SingleEG34er2p5);
   TRY_SET_BRANCH("L1_SingleEG36er2p5", &L1_SingleEG36er2p5, &b_L1_SingleEG36er2p5);
   TRY_SET_BRANCH("L1_SingleEG38er2p5", &L1_SingleEG38er2p5, &b_L1_SingleEG38er2p5);
   TRY_SET_BRANCH("L1_SingleEG40er2p5", &L1_SingleEG40er2p5, &b_L1_SingleEG40er2p5);
   TRY_SET_BRANCH("L1_SingleEG42er2p5", &L1_SingleEG42er2p5, &b_L1_SingleEG42er2p5);
   TRY_SET_BRANCH("L1_SingleEG45er2p5", &L1_SingleEG45er2p5, &b_L1_SingleEG45er2p5);
   TRY_SET_BRANCH("L1_SingleEG50", &L1_SingleEG50, &b_L1_SingleEG50);
   TRY_SET_BRANCH("L1_SingleEG60", &L1_SingleEG60, &b_L1_SingleEG60);
   TRY_SET_BRANCH("L1_SingleEG8er2p5", &L1_SingleEG8er2p5, &b_L1_SingleEG8er2p5);
   TRY_SET_BRANCH("L1_SingleIsoEG24er1p5", &L1_SingleIsoEG24er1p5, &b_L1_SingleIsoEG24er1p5);
   TRY_SET_BRANCH("L1_SingleIsoEG24er2p1", &L1_SingleIsoEG24er2p1, &b_L1_SingleIsoEG24er2p1);
   TRY_SET_BRANCH("L1_SingleIsoEG26er1p5", &L1_SingleIsoEG26er1p5, &b_L1_SingleIsoEG26er1p5);
   TRY_SET_BRANCH("L1_SingleIsoEG26er2p1", &L1_SingleIsoEG26er2p1, &b_L1_SingleIsoEG26er2p1);
   TRY_SET_BRANCH("L1_SingleIsoEG26er2p5", &L1_SingleIsoEG26er2p5, &b_L1_SingleIsoEG26er2p5);
   TRY_SET_BRANCH("L1_SingleIsoEG28er1p5", &L1_SingleIsoEG28er1p5, &b_L1_SingleIsoEG28er1p5);
   TRY_SET_BRANCH("L1_SingleIsoEG28er2p1", &L1_SingleIsoEG28er2p1, &b_L1_SingleIsoEG28er2p1);
   TRY_SET_BRANCH("L1_SingleIsoEG28er2p5", &L1_SingleIsoEG28er2p5, &b_L1_SingleIsoEG28er2p5);
   TRY_SET_BRANCH("L1_SingleIsoEG30er2p1", &L1_SingleIsoEG30er2p1, &b_L1_SingleIsoEG30er2p1);
   TRY_SET_BRANCH("L1_SingleIsoEG30er2p5", &L1_SingleIsoEG30er2p5, &b_L1_SingleIsoEG30er2p5);
   TRY_SET_BRANCH("L1_SingleIsoEG32er2p1", &L1_SingleIsoEG32er2p1, &b_L1_SingleIsoEG32er2p1);
   TRY_SET_BRANCH("L1_SingleIsoEG32er2p5", &L1_SingleIsoEG32er2p5, &b_L1_SingleIsoEG32er2p5);
   TRY_SET_BRANCH("L1_SingleIsoEG34er2p5", &L1_SingleIsoEG34er2p5, &b_L1_SingleIsoEG34er2p5);
   TRY_SET_BRANCH("L1_SingleJet10erHE", &L1_SingleJet10erHE, &b_L1_SingleJet10erHE);
   TRY_SET_BRANCH("L1_SingleJet120", &L1_SingleJet120, &b_L1_SingleJet120);
   TRY_SET_BRANCH("L1_SingleJet120_FWD3p0", &L1_SingleJet120_FWD3p0, &b_L1_SingleJet120_FWD3p0);
   TRY_SET_BRANCH("L1_SingleJet120er2p5", &L1_SingleJet120er2p5, &b_L1_SingleJet120er2p5);
   TRY_SET_BRANCH("L1_SingleJet12erHE", &L1_SingleJet12erHE, &b_L1_SingleJet12erHE);
   TRY_SET_BRANCH("L1_SingleJet140er2p5", &L1_SingleJet140er2p5, &b_L1_SingleJet140er2p5);
   TRY_SET_BRANCH("L1_SingleJet140er2p5_ETMHF80", &L1_SingleJet140er2p5_ETMHF80, &b_L1_SingleJet140er2p5_ETMHF80);
   TRY_SET_BRANCH("L1_SingleJet140er2p5_ETMHF90", &L1_SingleJet140er2p5_ETMHF90, &b_L1_SingleJet140er2p5_ETMHF90);
   TRY_SET_BRANCH("L1_SingleJet160er2p5", &L1_SingleJet160er2p5, &b_L1_SingleJet160er2p5);
   TRY_SET_BRANCH("L1_SingleJet180", &L1_SingleJet180, &b_L1_SingleJet180);
   TRY_SET_BRANCH("L1_SingleJet180er2p5", &L1_SingleJet180er2p5, &b_L1_SingleJet180er2p5);
   TRY_SET_BRANCH("L1_SingleJet200", &L1_SingleJet200, &b_L1_SingleJet200);
   TRY_SET_BRANCH("L1_SingleJet20er2p5_NotBptxOR", &L1_SingleJet20er2p5_NotBptxOR, &b_L1_SingleJet20er2p5_NotBptxOR);
   TRY_SET_BRANCH("L1_SingleJet20er2p5_NotBptxOR_3BX", &L1_SingleJet20er2p5_NotBptxOR_3BX, &b_L1_SingleJet20er2p5_NotBptxOR_3BX);
   TRY_SET_BRANCH("L1_SingleJet35", &L1_SingleJet35, &b_L1_SingleJet35);
   TRY_SET_BRANCH("L1_SingleJet35_FWD3p0", &L1_SingleJet35_FWD3p0, &b_L1_SingleJet35_FWD3p0);
   TRY_SET_BRANCH("L1_SingleJet35er2p5", &L1_SingleJet35er2p5, &b_L1_SingleJet35er2p5);
   TRY_SET_BRANCH("L1_SingleJet43er2p5_NotBptxOR_3BX", &L1_SingleJet43er2p5_NotBptxOR_3BX, &b_L1_SingleJet43er2p5_NotBptxOR_3BX);
   TRY_SET_BRANCH("L1_SingleJet46er2p5_NotBptxOR_3BX", &L1_SingleJet46er2p5_NotBptxOR_3BX, &b_L1_SingleJet46er2p5_NotBptxOR_3BX);
   TRY_SET_BRANCH("L1_SingleJet60", &L1_SingleJet60, &b_L1_SingleJet60);
   TRY_SET_BRANCH("L1_SingleJet60_FWD3p0", &L1_SingleJet60_FWD3p0, &b_L1_SingleJet60_FWD3p0);
   TRY_SET_BRANCH("L1_SingleJet60er2p5", &L1_SingleJet60er2p5, &b_L1_SingleJet60er2p5);
   TRY_SET_BRANCH("L1_SingleJet8erHE", &L1_SingleJet8erHE, &b_L1_SingleJet8erHE);
   TRY_SET_BRANCH("L1_SingleJet90", &L1_SingleJet90, &b_L1_SingleJet90);
   TRY_SET_BRANCH("L1_SingleJet90_FWD3p0", &L1_SingleJet90_FWD3p0, &b_L1_SingleJet90_FWD3p0);
   TRY_SET_BRANCH("L1_SingleJet90er2p5", &L1_SingleJet90er2p5, &b_L1_SingleJet90er2p5);
   TRY_SET_BRANCH("L1_SingleLooseIsoEG28er1p5", &L1_SingleLooseIsoEG28er1p5, &b_L1_SingleLooseIsoEG28er1p5);
   TRY_SET_BRANCH("L1_SingleLooseIsoEG30er1p5", &L1_SingleLooseIsoEG30er1p5, &b_L1_SingleLooseIsoEG30er1p5);
   TRY_SET_BRANCH("L1_SingleMu0_BMTF", &L1_SingleMu0_BMTF, &b_L1_SingleMu0_BMTF);
   TRY_SET_BRANCH("L1_SingleMu0_DQ", &L1_SingleMu0_DQ, &b_L1_SingleMu0_DQ);
   TRY_SET_BRANCH("L1_SingleMu0_EMTF", &L1_SingleMu0_EMTF, &b_L1_SingleMu0_EMTF);
   TRY_SET_BRANCH("L1_SingleMu0_OMTF", &L1_SingleMu0_OMTF, &b_L1_SingleMu0_OMTF);
   TRY_SET_BRANCH("L1_SingleMu10er1p5", &L1_SingleMu10er1p5, &b_L1_SingleMu10er1p5);
   TRY_SET_BRANCH("L1_SingleMu12_DQ_BMTF", &L1_SingleMu12_DQ_BMTF, &b_L1_SingleMu12_DQ_BMTF);
   TRY_SET_BRANCH("L1_SingleMu12_DQ_EMTF", &L1_SingleMu12_DQ_EMTF, &b_L1_SingleMu12_DQ_EMTF);
   TRY_SET_BRANCH("L1_SingleMu12_DQ_OMTF", &L1_SingleMu12_DQ_OMTF, &b_L1_SingleMu12_DQ_OMTF);
   TRY_SET_BRANCH("L1_SingleMu12er1p5", &L1_SingleMu12er1p5, &b_L1_SingleMu12er1p5);
   TRY_SET_BRANCH("L1_SingleMu14er1p5", &L1_SingleMu14er1p5, &b_L1_SingleMu14er1p5);
   TRY_SET_BRANCH("L1_SingleMu15_DQ", &L1_SingleMu15_DQ, &b_L1_SingleMu15_DQ);
   TRY_SET_BRANCH("L1_SingleMu16er1p5", &L1_SingleMu16er1p5, &b_L1_SingleMu16er1p5);
   TRY_SET_BRANCH("L1_SingleMu18", &L1_SingleMu18, &b_L1_SingleMu18);
   TRY_SET_BRANCH("L1_SingleMu18er1p5", &L1_SingleMu18er1p5, &b_L1_SingleMu18er1p5);
   TRY_SET_BRANCH("L1_SingleMu20", &L1_SingleMu20, &b_L1_SingleMu20);
   TRY_SET_BRANCH("L1_SingleMu22", &L1_SingleMu22, &b_L1_SingleMu22);
   TRY_SET_BRANCH("L1_SingleMu22_BMTF", &L1_SingleMu22_BMTF, &b_L1_SingleMu22_BMTF);
   TRY_SET_BRANCH("L1_SingleMu22_EMTF", &L1_SingleMu22_EMTF, &b_L1_SingleMu22_EMTF);
   TRY_SET_BRANCH("L1_SingleMu22_OMTF", &L1_SingleMu22_OMTF, &b_L1_SingleMu22_OMTF);
   TRY_SET_BRANCH("L1_SingleMu25", &L1_SingleMu25, &b_L1_SingleMu25);
   TRY_SET_BRANCH("L1_SingleMu3", &L1_SingleMu3, &b_L1_SingleMu3);
   TRY_SET_BRANCH("L1_SingleMu5", &L1_SingleMu5, &b_L1_SingleMu5);
   TRY_SET_BRANCH("L1_SingleMu6er1p5", &L1_SingleMu6er1p5, &b_L1_SingleMu6er1p5);
   TRY_SET_BRANCH("L1_SingleMu7", &L1_SingleMu7, &b_L1_SingleMu7);
   TRY_SET_BRANCH("L1_SingleMu7_DQ", &L1_SingleMu7_DQ, &b_L1_SingleMu7_DQ);
   TRY_SET_BRANCH("L1_SingleMu7er1p5", &L1_SingleMu7er1p5, &b_L1_SingleMu7er1p5);
   TRY_SET_BRANCH("L1_SingleMu8er1p5", &L1_SingleMu8er1p5, &b_L1_SingleMu8er1p5);
   TRY_SET_BRANCH("L1_SingleMu9er1p5", &L1_SingleMu9er1p5, &b_L1_SingleMu9er1p5);
   TRY_SET_BRANCH("L1_SingleMuCosmics", &L1_SingleMuCosmics, &b_L1_SingleMuCosmics);
   TRY_SET_BRANCH("L1_SingleMuCosmics_BMTF", &L1_SingleMuCosmics_BMTF, &b_L1_SingleMuCosmics_BMTF);
   TRY_SET_BRANCH("L1_SingleMuCosmics_EMTF", &L1_SingleMuCosmics_EMTF, &b_L1_SingleMuCosmics_EMTF);
   TRY_SET_BRANCH("L1_SingleMuCosmics_OMTF", &L1_SingleMuCosmics_OMTF, &b_L1_SingleMuCosmics_OMTF);
   TRY_SET_BRANCH("L1_SingleMuOpen", &L1_SingleMuOpen, &b_L1_SingleMuOpen);
   TRY_SET_BRANCH("L1_SingleMuOpen_NotBptxOR", &L1_SingleMuOpen_NotBptxOR, &b_L1_SingleMuOpen_NotBptxOR);
   TRY_SET_BRANCH("L1_SingleMuOpen_er1p1_NotBptxOR_3BX", &L1_SingleMuOpen_er1p1_NotBptxOR_3BX, &b_L1_SingleMuOpen_er1p1_NotBptxOR_3BX);
   TRY_SET_BRANCH("L1_SingleMuOpen_er1p4_NotBptxOR_3BX", &L1_SingleMuOpen_er1p4_NotBptxOR_3BX, &b_L1_SingleMuOpen_er1p4_NotBptxOR_3BX);
   TRY_SET_BRANCH("L1_SingleTau120er2p1", &L1_SingleTau120er2p1, &b_L1_SingleTau120er2p1);
   TRY_SET_BRANCH("L1_SingleTau130er2p1", &L1_SingleTau130er2p1, &b_L1_SingleTau130er2p1);
   TRY_SET_BRANCH("L1_TOTEM_1", &L1_TOTEM_1, &b_L1_TOTEM_1);
   TRY_SET_BRANCH("L1_TOTEM_2", &L1_TOTEM_2, &b_L1_TOTEM_2);
   TRY_SET_BRANCH("L1_TOTEM_3", &L1_TOTEM_3, &b_L1_TOTEM_3);
   TRY_SET_BRANCH("L1_TOTEM_4", &L1_TOTEM_4, &b_L1_TOTEM_4);
   TRY_SET_BRANCH("L1_TripleEG16er2p5", &L1_TripleEG16er2p5, &b_L1_TripleEG16er2p5);
   TRY_SET_BRANCH("L1_TripleEG_16_12_8_er2p5", &L1_TripleEG_16_12_8_er2p5, &b_L1_TripleEG_16_12_8_er2p5);
   TRY_SET_BRANCH("L1_TripleEG_16_15_8_er2p5", &L1_TripleEG_16_15_8_er2p5, &b_L1_TripleEG_16_15_8_er2p5);
   TRY_SET_BRANCH("L1_TripleEG_18_17_8_er2p5", &L1_TripleEG_18_17_8_er2p5, &b_L1_TripleEG_18_17_8_er2p5);
   TRY_SET_BRANCH("L1_TripleEG_18_18_12_er2p5", &L1_TripleEG_18_18_12_er2p5, &b_L1_TripleEG_18_18_12_er2p5);
   TRY_SET_BRANCH("L1_TripleJet_100_80_70_DoubleJet_80_70_er2p5", &L1_TripleJet_100_80_70_DoubleJet_80_70_er2p5, &b_L1_TripleJet_100_80_70_DoubleJet_80_70_er2p5);
   TRY_SET_BRANCH("L1_TripleJet_105_85_75_DoubleJet_85_75_er2p5", &L1_TripleJet_105_85_75_DoubleJet_85_75_er2p5, &b_L1_TripleJet_105_85_75_DoubleJet_85_75_er2p5);
   TRY_SET_BRANCH("L1_TripleJet_95_75_65_DoubleJet_75_65_er2p5", &L1_TripleJet_95_75_65_DoubleJet_75_65_er2p5, &b_L1_TripleJet_95_75_65_DoubleJet_75_65_er2p5);
   TRY_SET_BRANCH("L1_TripleMu0", &L1_TripleMu0, &b_L1_TripleMu0);
   TRY_SET_BRANCH("L1_TripleMu0_OQ", &L1_TripleMu0_OQ, &b_L1_TripleMu0_OQ);
   TRY_SET_BRANCH("L1_TripleMu0_SQ", &L1_TripleMu0_SQ, &b_L1_TripleMu0_SQ);
   TRY_SET_BRANCH("L1_TripleMu3", &L1_TripleMu3, &b_L1_TripleMu3);
   TRY_SET_BRANCH("L1_TripleMu3_SQ", &L1_TripleMu3_SQ, &b_L1_TripleMu3_SQ);
   TRY_SET_BRANCH("L1_TripleMu_5SQ_3SQ_0OQ", &L1_TripleMu_5SQ_3SQ_0OQ, &b_L1_TripleMu_5SQ_3SQ_0OQ);
   TRY_SET_BRANCH("L1_TripleMu_5SQ_3SQ_0OQ_DoubleMu_5_3_SQ_OS_Mass_Max9", &L1_TripleMu_5SQ_3SQ_0OQ_DoubleMu_5_3_SQ_OS_Mass_Max9, &b_L1_TripleMu_5SQ_3SQ_0OQ_DoubleMu_5_3_SQ_OS_Mass_Max9);
   TRY_SET_BRANCH("L1_TripleMu_5SQ_3SQ_0_DoubleMu_5_3_SQ_OS_Mass_Max9", &L1_TripleMu_5SQ_3SQ_0_DoubleMu_5_3_SQ_OS_Mass_Max9, &b_L1_TripleMu_5SQ_3SQ_0_DoubleMu_5_3_SQ_OS_Mass_Max9);
   TRY_SET_BRANCH("L1_TripleMu_5_3_3", &L1_TripleMu_5_3_3, &b_L1_TripleMu_5_3_3);
   TRY_SET_BRANCH("L1_TripleMu_5_3_3_SQ", &L1_TripleMu_5_3_3_SQ, &b_L1_TripleMu_5_3_3_SQ);
   TRY_SET_BRANCH("L1_TripleMu_5_3p5_2p5", &L1_TripleMu_5_3p5_2p5, &b_L1_TripleMu_5_3p5_2p5);
   TRY_SET_BRANCH("L1_TripleMu_5_3p5_2p5_DoubleMu_5_2p5_OS_Mass_5to17", &L1_TripleMu_5_3p5_2p5_DoubleMu_5_2p5_OS_Mass_5to17, &b_L1_TripleMu_5_3p5_2p5_DoubleMu_5_2p5_OS_Mass_5to17);
   TRY_SET_BRANCH("L1_TripleMu_5_3p5_2p5_OQ_DoubleMu_5_2p5_OQ_OS_Mass_5to17", &L1_TripleMu_5_3p5_2p5_OQ_DoubleMu_5_2p5_OQ_OS_Mass_5to17, &b_L1_TripleMu_5_3p5_2p5_OQ_DoubleMu_5_2p5_OQ_OS_Mass_5to17);
   TRY_SET_BRANCH("L1_TripleMu_5_4_2p5_DoubleMu_5_2p5_OS_Mass_5to17", &L1_TripleMu_5_4_2p5_DoubleMu_5_2p5_OS_Mass_5to17, &b_L1_TripleMu_5_4_2p5_DoubleMu_5_2p5_OS_Mass_5to17);
   TRY_SET_BRANCH("L1_TripleMu_5_5_3", &L1_TripleMu_5_5_3, &b_L1_TripleMu_5_5_3);
   TRY_SET_BRANCH("L1_UnpairedBunchBptxMinus", &L1_UnpairedBunchBptxMinus, &b_L1_UnpairedBunchBptxMinus);
   TRY_SET_BRANCH("L1_UnpairedBunchBptxPlus", &L1_UnpairedBunchBptxPlus, &b_L1_UnpairedBunchBptxPlus);
   TRY_SET_BRANCH("L1_ZeroBias", &L1_ZeroBias, &b_L1_ZeroBias);
   TRY_SET_BRANCH("L1_ZeroBias_copy", &L1_ZeroBias_copy, &b_L1_ZeroBias_copy);
   Notify();
}

Bool_t Events::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


void Events::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Events::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Events_cxx
