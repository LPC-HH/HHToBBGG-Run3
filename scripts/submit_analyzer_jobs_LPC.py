#!/usr/bin/python

import os
import datetime
import time
import subprocess
import glob
import sys
from collections import OrderedDict

option = 0
label = "option"+str(option)

analysis = "ZeeAnalyzer"
outputfile = "ZeeAnalysisNtuple" + "_" + label

#analysis = "HHTo2B2GNtupler"
#outputfile = "HHTo2B2GNtuple" + "_" + label

#analysis = "JetHTTriggerNtupler"
#outputfile = "JetHTTriggerNtuple" + "_" + label

#analysis = "MakeMCPileupDistribution"
#outputfile = "MCPileupDistribution" + "_" + label

cmsswReleaseVersion = "CMSSW_14_0_7"



outputDirectoryBase = "/store/group/lpcdihiggsboost/nparekh/analyzer/"+analysis+"/"+label+"/"
filesPerJob = 1

datasetList = OrderedDict()

"""
#2022 ntuples

datasetList["nano/run3/2022/Run2022B-22Sep2023-v2.list"] = [1, 1, "2022", "", 1]
datasetList["nano/run3/2022/Run2022C-22Sep2023-v1.list"] = [1, 1, "2022", "", 1]
datasetList["nano/run3/2022/Run2022D-22Sep2023-v1.list"] = [1, 1, "2022", "", 1]
datasetList["nano/run3/2022/Run2022E-22Sep2023-v1.list"] = [1, 1, "2022", "", 1]
datasetList["nano/run3/2022/Run2022F-22Sep2023-v1.list"] = [1, 1, "2022", "", 1]
datasetList["nano/run3/2022/Run2022G-22Sep2023-v2.list"] = [1, 1, "2022", "", 1]

datasetList['nano/run3/2022/ggHHTo2B2G_cHHH_1_PrivProd.list'] = [2, 1, "2022", "", 1]
datasetList['nano/run3/2022/GG-Box-3Jets_MGG-0to40_13p6TeV_sherpa_2022.list'] = [2, 1, "2022", "", 1]
datasetList['nano/run3/2022/GG-Box-3Jets_MGG-40to80_13p6TeV_sherpa_2022.list'] = [2, 1, "2022", "", 1]
datasetList['nano/run3/2022/GG-Box-3Jets_MGG-80_13p6TeV_sherpa_2022.list'] = [2, 1, "2022", "", 1]
datasetList['nano/run3/2022/GG-Box-3Jets_MGG-0to40_13p6TeV_sherpa_2022EE.list'] = [2, 1, "2022", "", 1]
datasetList['nano/run3/2022/GG-Box-3Jets_MGG-40to80_13p6TeV_sherpa_2022EE.list'] = [2, 1, "2022", "", 1]
datasetList['nano/run3/2022/GG-Box-3Jets_MGG-80_13p6TeV_sherpa_2022EE.list'] = [2, 1, "2022", "", 1]
datasetList['nano/run3/2022/GJet_PT-10to40_DoubleEMEnriched_TuneCP5_13p6TeV_pythia8_2022.list']=[2,1,"2022","",1]
datasetList['nano/run3/2022/GJet_PT-10to40_DoubleEMEnriched_TuneCP5_13p6TeV_pythia8_2022EE.list']=[2,1,"2022","",1]
datasetList['nano/run3/2022/GJet_PT-40_DoubleEMEnriched_TuneCP5_13p6TeV_pythia8_2022.list']=[2,1,"2022","",1]
datasetList['nano/run3/2022/GJet_PT-40_DoubleEMEnriched_TuneCP5_13p6TeV_pythia8_2022EE.list']=[2,1,"2022","",1]
datasetList['nano/run3/2022/GJet_PT-20to40_DoubleEMEnriched_MGG-80_TuneCP5_13p6TeV_pythia8_2022.list']=[2,1,"2022","",1]
datasetList['nano/run3/2022/GJet_PT-20to40_DoubleEMEnriched_MGG-80_TuneCP5_13p6TeV_pythia8_2022EE.list']=[2,1,"2022","",1]
datasetList['nano/run3/2022/GJet_PT-40_DoubleEMEnriched_MGG-80_TuneCP5_13p6TeV_pythia8_2022.list']=[2,1,"2022","",1]
datasetList['nano/run3/2022/GJet_PT-40_DoubleEMEnriched_MGG-80_TuneCP5_13p6TeV_pythia8_2022EE.list']=[2,1,"2022","",1]

datasetList['nano/run3/2022/GluGluHtoGG_M-120_TuneCP5_13p6TeV_amcatnloFXFX-pythia8_2022EE.list']=[2,1,"2022","",1]
datasetList['nano/run3/2022/GluGluHtoGG_M-125_TuneCP5_13p6TeV_amcatnloFXFX-pythia8_2022EE.list']=[2,1,"2022","",1]
datasetList['nano/run3/2022/GluGluHtoGG_M-130_TuneCP5_13p6TeV_amcatnloFXFX-pythia8_2022EE.list']=[2,1,"2022","",1]
datasetList['nano/run3/2022/GluGluHtoGG_M-125_TuneCP5_13p6TeV_amcatnloFXFX-pythia8_2022.list']=[2,1,"2022","",1]

datasetList['nano/run3/2022/VBFHtoGG_M-120_TuneCP5_13p6TeV_amcatnlo-pythia8_2022EE.list']=[2,1,"2022","",1]
datasetList['nano/run3/2022/VBFHtoGG_M-125_TuneCP5_13p6TeV_amcatnlo-pythia8_2022EE.list']=[2,1,"2022","",1]
datasetList['nano/run3/2022/VBFHtoGG_M-130_TuneCP5_13p6TeV_amcatnlo-pythia8_2022EE.list']=[2,1,"2022","",1]
datasetList['nano/run3/2022/VBFHtoGG_M-125_TuneCP5_13p6TeV_amcatnlo-pythia8_2022.list']=[2,1,"2022","",1]

datasetList['nano/run3/2022/VHtoGG_M-120_TuneCP5_13p6TeV_amcatnloFXFX-madspin-pythia8_2022EE.list']=[2,1,"2022","",1]
datasetList['nano/run3/2022/VHtoGG_M-125_TuneCP5_13p6TeV_amcatnloFXFX-madspin-pythia8_2022EE.list']=[2,1,"2022","",1]
datasetList['nano/run3/2022/VHtoGG_M-130_TuneCP5_13p6TeV_amcatnloFXFX-madspin-pythia8_2022EE.list']=[2,1,"2022","",1]
datasetList['nano/run3/2022/VHtoGG_M-125_TuneCP5_13p6TeV_amcatnloFXFX-madspin-pythia8_2022.list']=[2,1,"2022","",1]

datasetList['nano/run3/2022/ttHtoGG_M-120_TuneCP5_13p6TeV_amcatnloFXFX-madspin-pythia8_2022EE.list']=[2,1,"2022","",1]
datasetList['nano/run3/2022/ttHtoGG_M-125_TuneCP5_13p6TeV_amcatnloFXFX-madspin-pythia8_2022EE.list']=[2,1,"2022","",1]
datasetList['nano/run3/2022/ttHtoGG_M-130_TuneCP5_13p6TeV_amcatnloFXFX-madspin-pythia8_2022EE.list']=[2,1,"2022","",1]
datasetList['nano/run3/2022/ttHtoGG_M-125_TuneCP5_13p6TeV_amcatnloFXFX-madspin-pythia8_2022.list']=[2,1,"2022","",1]

datasetList['nano/run3/2022/GluGlutoHHto2B2G_kl-1p00_kt-1p00_c2-0p00_TuneCP5_13p6TeV_powheg-pythia8_2022EE.list']=[2,1,"2022","",1]
datasetList['nano/run3/2022/GluGlutoHHto2B2G_kl-1p00_kt-1p00_c2-0p00_TuneCP5_13p6TeV_powheg-pythia8_2022.list']=[2,1,"2022","",1]



datasetList['nano/run3/2022/QCD_PT-30to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13p6TeV_pythia8_2022.list']=[2,1,"2022","",1]
datasetList['nano/run3/2022/QCD_PT-30to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13p6TeV_pythia8_2022EE.list']=[2,1,"2022","",1]
datasetList['nano/run3/2022/QCD_PT-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13p6TeV_pythia8_2022.list']=[2,1,"2022","",1]
datasetList['nano/run3/2022/QCD_PT-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13p6TeV_pythia8_2022EE.list']=[2,1,"2022","",1]

########################################################
#2023 ntuples
########################################################
datasetList['nano/run3/2023/EGamma_2023C_v1.list'] = [1, 1, "2023", "", 1]
datasetList['nano/run3/2023/EGamma_2023C_v2.list'] = [1, 1, "2023", "", 1]
datasetList['nano/run3/2023/EGamma_2023C_v3.list'] = [1, 1, "2023", "", 1]
datasetList['nano/run3/2023/EGamma_2023C_v4.list'] = [1, 1, "2023", "", 1]

"""
datasetList['nano/run3/2023/DYto2E_MLL-50to120_TuneCP5_13p6TeV_powheg-pythia8_2023.list'] = [2, 1, "2023", "", 1]
"""
datasetList["nano/run3/2023/GluGlutoHHto2B2G_kl-1p00_kt-1p00_c2-0p00_TuneCP5_13p6TeV_powheg-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/GluGlutoHHto2B2G_kl-0p00_kt-1p00_c2-0p00_TuneCP5_13p6TeV_powheg-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/GluGlutoHHto2B2G_kl-5p00_kt-1p00_c2-0p00_TuneCP5_13p6TeV_powheg-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/GluGlutoHHto2B2G_kl-2p45_kt-1p00_c2-0p00_LHEweights_TuneCP5_13p6TeV_powheg-pythia.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/VBFHHto2B2G_CV_1_C2V_0_C3_1_TuneCP5_13p6TeV_madgraph-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/VBFHHto2B2G_CV_1p74_C2V_1p37_C3_14p4_TuneCP5_13p6TeV_madgraph-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/VBFHHto2B2G_CV_1_C2V_1_C3_1_TuneCP5_13p6TeV_madgraph-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/VBFHHto2B2G_CV_m0p758_C2V_1p44_C3_m19p3_TuneCP5_13p6TeV_madgraph-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/VBFHHto2B2G_CV_m0p012_C2V_0p030_C3_10p2_TuneCP5_13p6TeV_madgraph-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/VBFHHto2B2G_CV_m0p962_C2V_0p959_C3_m1p43_TuneCP5_13p6TeV_madgraph-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/VBFHHto2B2G_CV_m1p60_C2V_2p72_C3_m1p36_TuneCP5_13p6TeV_madgraph-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/VBFHHto2B2G_CV_m1p21_C2V_1p94_C3_m0p94_TuneCP5_13p6TeV_madgraph-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/VBFHHto2B2G_CV_m1p83_C2V_3p57_C3_m3p39_TuneCP5_13p6TeV_madgraph-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/VBFHHto2B2G_CV_m2p12_C2V_3p87_C3_m5p96_TuneCP5_13p6TeV_madgraph-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/GluGluHtoGG_M-125_TuneCP5_13p6TeV_amcatnloFXFX-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/VHto2G_M-125_TuneCP5_13p6TeV_amcatnloFxFx-madspin-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/VBFHto2G_M-125_TuneCP5_13p6TeV_amcatnlo-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/ttHtoGG_M-125_TuneCP5_13p6TeV_amcatnloFXFX-madspin-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/BBHto2G_M-125_TuneCP5_13p6TeV_powheg-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/WminusH_Hto2G_Wto2Q_M-125_TuneCP5_13p6TeV_powheg-minlo-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/WplusH_Hto2G_Wto2Q_M-125_TuneCP5_13p6TeV_powheg-minlo-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/WminusH_Hto2G_WtoLNu_M-125_TuneCP5_13p6TeV_powheg-minlo-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/WplusH_Hto2G_WtoLNu_M-125_TuneCP5_13p6TeV_powheg-minlo-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/ZH_Hto2G_Zto2Nu_M-125_TuneCP5_13p6TeV_powheg-minlo-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/ZH_Hto2G_Zto2L_M-125_TuneCP5_13p6TeV_powheg-minlo-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/ZH_Hto2G_Zto2Q_M-125_TuneCP5_13p6TeV_powheg-minlo-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/ggZH_Hto2G_Zto2L_M-125_TuneCP5_13p6TeV_powheg-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/ggZH_Hto2G_Zto2Q_M-125_TuneCP5_13p6TeV_powheg-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/ggZH_Hto2G_Zto2Nu_M-125_TuneCP5_13p6TeV_powheg-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/GG-Box-3Jets_MGG-0to40_13p6TeV_sherpa.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/GG-Box-3Jets_MGG-80_13p6TeV_sherpa.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/GG-Box-3Jets_MGG-40to80_13p6TeV_sherpa.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/GJet_PT-40_DoubleEMEnriched_TuneCP5_13p6TeV_pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/GJet_PT-10to40_DoubleEMEnriched_TuneCP5_13p6TeV_pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/GJet_PT-20to40_DoubleEMEnriched_MGG-80_TuneCP5_13p6TeV_pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/GJet_PT-20_DoubleEMEnriched_MGG-40to80_TuneCP5_13p6TeV_pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/GJet_PT-40_DoubleEMEnriched_MGG-80_TuneCP5_13p6TeV_pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/QCD_PT-30toInf_DoubleEMEnriched_MGG-40to80_TuneCP5_13p6TeV_pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/QCD_PT-30to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13p6TeV_pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/QCD_PT-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13p6TeV_pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/TJGG_TuneCP5_13p6TeV_amcatnlo-madspin-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/TTG-1Jets_PTG-10to100_TuneCP5_13p6TeV_amcatnloFXFXold-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/TTG-1Jets_PTG-100to200_TuneCP5_13p6TeV_amcatnloFXFXold-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/TTG-1Jets_PTG-200_TuneCP5_13p6TeV_amcatnloFXFXold-pythia8.list"] = [2, 1, "2023", "", 1]
datasetList["nano/run3/2023/TTGG_TuneCP5_13p6TeV_madgraph-madspin-pythia8.list"] = [2, 1, "2023", "", 1]


########################################################
#2023BPix ntuples
########################################################
datasetList['nano/run3/2023/EGamma_2023D_v1.list'] = [1, 1, "2023BPix", "", 1]
datasetList['nano/run3/2023/EGamma_2023D_v2.list'] = [1, 1, "2023BPix", "", 1]

"""
datasetList["nano/run3/2023BPix/DYto2E_MLL-50to120_TuneCP5_13p6TeV_powheg-pythia8_2023BPix.list"] = [2, 1, "2023BPix", "", 1]
"""
datasetList["nano/run3/2023BPix/BBHto2G_M-125_TuneCP5_13p6TeV_powheg-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/GG-Box-3Jets_MGG-0to40_13p6TeV_sherpa.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/GG-Box-3Jets_MGG-40to80_13p6TeV_sherpa.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/GG-Box-3Jets_MGG-80_13p6TeV_sherpa.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/GJet_PT-10to40_DoubleEMEnriched_TuneCP5_13p6TeV_pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/GJet_PT-20_DoubleEMEnriched_MGG-40to80_TuneCP5_13p6TeV_pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/GJet_PT-20to40_DoubleEMEnriched_MGG-80_TuneCP5_13p6TeV_pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/GJet_PT-40_DoubleEMEnriched_MGG-80_TuneCP5_13p6TeV_pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/GJet_PT-40_DoubleEMEnriched_TuneCP5_13p6TeV_pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/GluGluHToGG_M-125_TuneCP5_13p6TeV_powheg-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/GluGluHtoGG_M-125_TuneCP5_13p6TeV_amcatnloFXFX-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/GluGlutoHHto2B2G_kl-0p00_kt-1p00_c2-0p00_TuneCP5_13p6TeV_powheg-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/GluGlutoHHto2B2G_kl-1p00_kt-1p00_c2-0p00_TuneCP5_13p6TeV_powheg-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/GluGlutoHHto2B2G_kl-2p45_kt-1p00_c2-0p00_LHEweights_TuneCP5_13p6TeV_powheg-pythia.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/GluGlutoHHto2B2G_kl-5p00_kt-1p00_c2-0p00_TuneCP5_13p6TeV_powheg-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/QCD_PT-30to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13p6TeV_pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/QCD_PT-30toInf_DoubleEMEnriched_MGG-40to80_TuneCP5_13p6TeV_pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/QCD_PT-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13p6TeV_pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/TJGG_TuneCP5_13p6TeV_amcatnlo-madspin-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/TTG-1Jets_PTG-100to200_TuneCP5_13p6TeV_amcatnloFXFXold-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/TTG-1Jets_PTG-10to100_TuneCP5_13p6TeV_amcatnloFXFXold-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/TTG-1Jets_PTG-200_TuneCP5_13p6TeV_amcatnloFXFXold-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/TTGG_TuneCP5_13p6TeV_madgraph-madspin-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/VBFHHto2B2G_CV_1_C2V_0_C3_1_TuneCP5_13p6TeV_madgraph-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/VBFHHto2B2G_CV_1_C2V_1_C3_1_TuneCP5_13p6TeV_madgraph-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/VBFHHto2B2G_CV_1p74_C2V_1p37_C3_14p4_TuneCP5_13p6TeV_madgraph-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/VBFHHto2B2G_CV_m0p012_C2V_0p030_C3_10p2_TuneCP5_13p6TeV_madgraph-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/VBFHHto2B2G_CV_m0p758_C2V_1p44_C3_m19p3_TuneCP5_13p6TeV_madgraph-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/VBFHHto2B2G_CV_m0p962_C2V_0p959_C3_m1p43_TuneCP5_13p6TeV_madgraph-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/VBFHHto2B2G_CV_m1p21_C2V_1p94_C3_m0p94_TuneCP5_13p6TeV_madgraph-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/VBFHHto2B2G_CV_m1p60_C2V_2p72_C3_m1p36_TuneCP5_13p6TeV_madgraph-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/VBFHHto2B2G_CV_m1p83_C2V_3p57_C3_m3p39_TuneCP5_13p6TeV_madgraph-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/VBFHHto2B2G_CV_m2p12_C2V_3p87_C3_m5p96_TuneCP5_13p6TeV_madgraph-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/VBFHto2G_M-125_TuneCP5_13p6TeV_amcatnlo-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/VHto2G_M-125_TuneCP5_13p6TeV_amcatnloFxFx-madspin-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/WminusH_Hto2G_Wto2Q_M-125_TuneCP5_13p6TeV_powheg-minlo-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/WminusH_Hto2G_WtoLNu_M-125_TuneCP5_13p6TeV_powheg-minlo-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/WplusH_Hto2G_Wto2Q_M-125_TuneCP5_13p6TeV_powheg-minlo-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/WplusH_Hto2G_WtoLNu_M-125_TuneCP5_13p6TeV_powheg-minlo-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/ZH_Hto2G_Zto2L_M-125_TuneCP5_13p6TeV_powheg-minlo-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/ZH_Hto2G_Zto2Nu_M-125_TuneCP5_13p6TeV_powheg-minlo-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/ZH_Hto2G_Zto2Q_M-125_TuneCP5_13p6TeV_powheg-minlo-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/ggZH_Hto2G_Zto2L_M-125_TuneCP5_13p6TeV_powheg-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/ggZH_Hto2G_Zto2Nu_M-125_TuneCP5_13p6TeV_powheg-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/ggZH_Hto2G_Zto2Q_M-125_TuneCP5_13p6TeV_powheg-pythia8.list"] = [2, 1, "2023BPix", "", 1]
datasetList["nano/run3/2023BPix/ttHtoGG_M-125_TuneCP5_13p6TeV_amcatnloFXFX-madspin-pythia8.list"] = [2, 1, "2023BPix", "", 1]

########################################################
#2024 ntuples
########################################################

datasetList["nano/run3/2024/EGamma_2024B.list"] = [1, 1, "2024", "", 1]
datasetList["nano/run3/2024/EGamma_2024C.list"] = [1, 1, "2024", "", 1]
datasetList["nano/run3/2024/EGamma_2024D.list"] = [1, 1, "2024", "", 1]
datasetList["nano/run3/2024/EGamma_2024E-v1.list"] = [1, 1, "2024", "", 1]
datasetList["nano/run3/2024/EGamma_2024E-v2.list"] = [1, 1, "2024", "", 1]
datasetList["nano/run3/2024/EGamma_2024F.list"] = [1, 1, "2024", "", 1]
datasetList["nano/run3/2024/EGamma_2024G.list"] = [1, 1, "2024", "", 1]
datasetList["nano/run3/2024/EGamma_2024H.list"] = [1, 1, "2024", "", 1]
"""
datasetList["nano/run3/2024/DYto2E_Bin-MLL-50to120_TuneCP5_13p6TeV_powheg-pythia8.list"] = [2, 1, "2024", "", 1]
datasetList["nano/run3/2024/DYto2E_Bin-MLL-120to200_TuneCP5_13p6TeV_powheg-pythia8.list"] = [2, 1, "2024", "", 1]
datasetList["nano/run3/2024/DYto2E_Bin-MLL-200to400_TuneCP5_13p6TeV_powheg-pythia8.list"] = [2, 1, "2024", "", 1]
datasetList["nano/run3/2024/DYto2E_Bin-MLL-400to800_TuneCP5_13p6TeV_powheg-pythia8.list"] = [2, 1, "2024", "", 1]
datasetList["nano/run3/2024/DYto2E_Bin-MLL-800to1500_TuneCP5_13p6TeV_powheg-pythia8.list"] = [2, 1, "2024", "", 1]
datasetList["nano/run3/2024/DYto2E_Bin-MLL-1500to2500_TuneCP5_13p6TeV_powheg-pythia8.list"] = [2, 1, "2024", "", 1]
datasetList["nano/run3/2024/DYto2E_Bin-MLL-2500to4000_TuneCP5_13p6TeV_powheg-pythia8.list"] = [2, 1, "2024", "", 1]
datasetList["nano/run3/2024/DYto2E_Bin-MLL-4000to6000_TuneCP5_13p6TeV_powheg-pythia8.list"] = [2, 1, "2024", "", 1]
datasetList["nano/run3/2024/DYto2E_Bin-MLL-6000_TuneCP5_13p6TeV_powheg-pythia8.list"] = [2, 1, "2024", "", 1]

CMSSW_BASE_DIR = os.getenv('CMSSW_BASE')
Analyzer_DIR = CMSSW_BASE_DIR+"/src/HHToBBGG-Run3/"
print(Analyzer_DIR)
#create directory for condor jobs

for listfile in datasetList.keys():

    datasetName = listfile.replace(".list","")
    print ("Preparing analyzer workflow for dataset :" + datasetName + "\n")
    if not os.path.exists(Analyzer_DIR+"/list/" + listfile):
        print ("listfile: " + listfile + " does not exist. skipping.")
        continue

    outputDirectory = outputDirectoryBase + datasetName + "/"
    tmpListFile = open(Analyzer_DIR + "/list/" + listfile,"r")

    year = datasetList[listfile][2]
    sampleName = datasetList[listfile][3]
    numberOfJobsPerFile = datasetList[listfile][4]

    #####################################
    #Job Splitting
    #####################################
    isData = "no"
    if (datasetList[listfile][0] == 1): 
        isData = "yes"
    filesPerJob = datasetList[listfile][1]
    tmpJobFileCount = 0
    nJobs = numberOfJobsPerFile

    if os.path.exists(Analyzer_DIR+"/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/" + "input_list_" + str(nJobs) + ".txt"):
        print ("Warning: condor directory " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + " is not empty. Skipping.")
        continue
        
    #create condor directories
    os.system("mkdir -p " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName )
    os.system("mkdir -p " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/log/")
    os.system("mkdir -p " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/out/")
    os.system("mkdir -p " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/err/")

    tmpOutputListFile = open( Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/" + "input_list_" + str(nJobs/numberOfJobsPerFile) + ".txt","w")
    for line in tmpListFile:
                
        #open list file for new job
        if tmpJobFileCount >= filesPerJob:
            tmpOutputListFile.close()
            tmpJobFileCount = 0
            nJobs = nJobs + numberOfJobsPerFile
            tmpOutputListFile = open( Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/" + "input_list_" + str(nJobs/numberOfJobsPerFile) + ".txt","w")
          
        #write input file into job list file
        tmpOutputListFile.write(line)
        tmpJobFileCount += 1

    tmpOutputListFile.close()    
    os.system("cd " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/; tar czf input_list.tgz input_list_*.txt")

    ###################################################
    #Copy code tarball, run script, and executable
    ###################################################
    #os.system("cd " + Analyzer_DIR + "; tar vczf " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/code.tgz " + " include/ src/ app/ Makefile" )
    os.system("cp " + Analyzer_DIR + "/scripts/run_job_LPC.sh " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/")
    os.system("cp " + Analyzer_DIR + "Run" + analysis + " " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/")
    os.system("mkdir -p " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/")
    os.system("cp " + Analyzer_DIR + "/data/JetHTTriggerEfficiency_2016" + ".root " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/")
    os.system("cp " + Analyzer_DIR + "/data/JetHTTriggerEfficiency_2017" + ".root " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/")
    os.system("cp " + Analyzer_DIR + "/data/JetHTTriggerEfficiency_2018" + ".root " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/")
    #os.system("cp " + Analyzer_DIR + "/data/JetHTTriggerEfficiency_" + year + ".root " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/")
    os.system("cp " + Analyzer_DIR + "/data/JetHTTriggerEfficiency_Summer16.root " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/")
    os.system("cp " + Analyzer_DIR + "/data/JetHTTriggerEfficiency_Fall17.root " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/")
    os.system("cp " + Analyzer_DIR + "/data/JetHTTriggerEfficiency_Fall18.root " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/")

    os.system("cp " + Analyzer_DIR + "/Run3_2022_2023_Golden.json " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/")
    os.system("cp " + Analyzer_DIR + "/Run3_2024_Golden.json " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/")

    os.system("mkdir -p " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/PileupWeights/")
    os.system("cp " + Analyzer_DIR + "/data/PileupWeights/PileupWeights.root " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/PileupWeights/")

    os.system("cp " + Analyzer_DIR + "/data/PileupWeights/PileupReweight_Summer22.root " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/PileupWeights/")
    os.system("cp " + Analyzer_DIR + "/data/PileupWeights/PileupReweight_Summer22EE.root " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/PileupWeights/")
    os.system("cp " + Analyzer_DIR + "/data/PileupWeights/PileupReweight_Summer23.root " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/PileupWeights/")
    os.system("cp " + Analyzer_DIR + "/data/PileupWeights/PileupReweight_Summer23BPix.root " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/PileupWeights/")

    os.system("mkdir -p " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/JEC/Summer16_07Aug2017_V11_MC/")
    os.system("cp " + Analyzer_DIR + "/data/JEC/Summer16_07Aug2017_V11_MC/Summer16_07Aug2017_V11_MC_Uncertainty_AK8PFPuppi.txt " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/JEC/Summer16_07Aug2017_V11_MC/")
    os.system("mkdir -p " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/JEC/Fall17_17Nov2017_V32_MC/")
    os.system("cp " + Analyzer_DIR + "/data/JEC/Fall17_17Nov2017_V32_MC/Fall17_17Nov2017_V32_MC_Uncertainty_AK8PFPuppi.txt " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/JEC/Fall17_17Nov2017_V32_MC/")
    os.system("mkdir -p " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/JEC/Autumn18_V19_MC/")
    os.system("cp " + Analyzer_DIR + "/data/JEC/Autumn18_V19_MC/Autumn18_V19_MC_Uncertainty_AK8PFPuppi.txt " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/JEC/Autumn18_V19_MC/")
    os.system("mkdir -p " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/JEC/Summer22_22Sep2023_RunCD_V2_DATA/")
    os.system("cp " + Analyzer_DIR + "/data/JEC/Summer22_22Sep2023_RunCD_V2_DATA/Summer22_22Sep2023_RunCD_V2_DATA_L1FastJet_AK4PFchs.txt " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/JEC/Summer22_22Sep2023_RunCD_V2_DATA/")    


    #####################################
    #Create Condor JDL file
    #####################################
    tmpCondorJDLFile = open(Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/task.jdl","w+")
    tmpCondorJDLFileTemplate = """
Universe  = vanilla
Executable = ./run_job_LPC.sh
"""
    tmpCondorJDLFile.write(tmpCondorJDLFileTemplate)
    tmpCondorJDLFile.write("Arguments = " + analysis + " " + str(isData) + " " + str(option) + " " + "$(I) " + str(numberOfJobsPerFile) + " " + outputfile + " " + outputDirectory + " " + cmsswReleaseVersion + " " + year + " " + sampleName + "\n")

    tmpCondorJDLFileTemplate = """
Log = log/job.$(Cluster).$(Process).log
Output = out/job.$(Cluster).$(Process).out
Error = err/job.$(Cluster).$(Process).err
x509userproxy = $ENV(X509_USER_PROXY)
"""
    tmpCondorJDLFile.write(tmpCondorJDLFileTemplate)
    tmpCondorJDLFile.write(
        "transfer_input_files = " 
        + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/run_job_LPC.sh, " 
        + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/input_list.tgz, " 
        + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/Run" + analysis + ", "
        #+ Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/code.tgz, " 
        + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/JetHTTriggerEfficiency_2016" + ".root, "
        + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/JetHTTriggerEfficiency_2017" + ".root, "
        + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/JetHTTriggerEfficiency_2018" + ".root, "
        + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/Run3_2022_2023_Golden.json, "  # json file
        + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/Run3_2024_Golden.json, "
        + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/JetHTTriggerEfficiency_Summer16.root, " 
        + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/JetHTTriggerEfficiency_Fall17.root, " 
        + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/JetHTTriggerEfficiency_Fall18.root, " 
        + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/PileupWeights/PileupWeights.root, "
        + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/PileupWeights/PileupReweight_Summer22.root, "
        + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/PileupWeights/PileupReweight_Summer22EE.root, "
        + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/PileupWeights/PileupReweight_Summer23.root, "
        + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/PileupWeights/PileupReweight_Summer23BPix.root, "
        + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/JEC/Summer16_07Aug2017_V11_MC/Summer16_07Aug2017_V11_MC_Uncertainty_AK8PFPuppi.txt, " 
        + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/JEC/Fall17_17Nov2017_V32_MC/Fall17_17Nov2017_V32_MC_Uncertainty_AK8PFPuppi.txt, "
        + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/JEC/Summer22_22Sep2023_RunCD_V2_DATA/Summer22_22Sep2023_RunCD_V2_DATA_L1FastJet_AK4PFchs.txt, " + Analyzer_DIR + "/condor/analyzer_" + analysis + "_" + label + "/" + datasetName + "/HHToBBGG-Run3/data/JEC/Autumn18_V19_MC/Autumn18_V19_MC_Uncertainty_AK8PFPuppi.txt " + "\n"
    )

    tmpCondorJDLFileTemplate = """
should_transfer_files = YES
when_to_transfer_output = ON_EXIT

# Resources request
"""
    tmpCondorJDLFile.write(tmpCondorJDLFileTemplate)
    tmpCondorJDLFile.write("RequestMemory = 6000 \n")

    tmpCondorJDLFileTemplate = """

# Jobs selection
Queue I from (
"""

    tmpCondorJDLFile.write(tmpCondorJDLFileTemplate)
    for i in range(1,nJobs+1):
        tmpCondorJDLFile.write(str(i)+"\n")
    tmpCondorJDLFile.write(")\n")
    tmpCondorJDLFile.close()