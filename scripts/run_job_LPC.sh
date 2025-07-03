#!/bin/bash

#######################
#debugging purposes
#######################
voms-proxy-info --all
ls -l

############################
#define input parameters
############################
analysisType=$1
isData=$2
option=$3
jobnumber=$4
nJobsPerFile=$5
outputfile=$6
outputDirectory=$7
cmsswReleaseVersion=$8
year=$9
sampleName=$10

###############################################
#calculate filenumber and jobIndex
###############################################
filenumber=$(((($jobnumber-1)/$nJobsPerFile)+1))
jobIndex=$((($jobnumber-1)%$nJobsPerFile))

############################
#define exec and setup cmssw
############################
workDir=`pwd`
executable=Run${analysisType}
source /cvmfs/cms.cern.ch/cmsset_default.sh
export SCRAM_ARCH=el9_amd64_gcc12
#export SCRAM_ARCH=el8_aarch64_gcc11
#tar -zxvf cms_setup.tar.gz
scramv1 project CMSSW $cmsswReleaseVersion

#########################################
#copy input list and exec to cmssw folder
########################################
#cp code.tgz $cmsswReleaseVersion/src/
cp $executable $cmsswReleaseVersion/src/
cp input_list.tgz $cmsswReleaseVersion/src/
mkdir -p $cmsswReleaseVersion/src/HHToBBGG-Run3/data/PileupWeights/

cp JetHTTriggerEfficiency_2016.root $cmsswReleaseVersion/src/HHToBBGG-Run3/data/
cp JetHTTriggerEfficiency_2017.root $cmsswReleaseVersion/src/HHToBBGG-Run3/data/
cp JetHTTriggerEfficiency_2018.root $cmsswReleaseVersion/src/HHToBBGG-Run3/data/
cp JetHTTriggerEfficiency_Summer16.root $cmsswReleaseVersion/src/HHToBBGG-Run3/data/
cp JetHTTriggerEfficiency_Fall17.root $cmsswReleaseVersion/src/HHToBBGG-Run3/data/
cp JetHTTriggerEfficiency_Fall18.root $cmsswReleaseVersion/src/HHToBBGG-Run3/data/
cp PileupWeights.root $cmsswReleaseVersion/src/HHToBBGG-Run3/data/PileupWeights/
cp PileupReweight_Summer22.root $cmsswReleaseVersion/src/HHToBBGG-Run3/data/PileupWeights/
cp PileupReweight_Summer22EE.root $cmsswReleaseVersion/src/HHToBBGG-Run3/data/PileupWeights/
cp PileupReweight_Summer23.root $cmsswReleaseVersion/src/HHToBBGG-Run3/data/PileupWeights/
cp PileupReweight_Summer23BPix.root $cmsswReleaseVersion/src/HHToBBGG-Run3/data/PileupWeights/
cp Run3_2022_2023_Golden.json $cmsswReleaseVersion/src/HHToBBGG-Run3/data/
cp Run3_2024_Golden.json $cmsswReleaseVersion/src/HHToBBGG-Run3/data/
mkdir -p $cmsswReleaseVersion/src/HHToBBGG-Run3/data/JEC/Summer16_07Aug2017_V11_MC/
cp Summer16_07Aug2017_V11_MC_Uncertainty_AK8PFPuppi.txt $cmsswReleaseVersion/src/HHToBBGG-Run3/data/JEC/Summer16_07Aug2017_V11_MC/
mkdir -p $cmsswReleaseVersion/src/HHToBBGG-Run3/data/JEC/Fall17_17Nov2017_V32_MC/
cp Fall17_17Nov2017_V32_MC_Uncertainty_AK8PFPuppi.txt $cmsswReleaseVersion/src/HHToBBGG-Run3/data/JEC/Fall17_17Nov2017_V32_MC/
mkdir -p $cmsswReleaseVersion/src/HHToBBGG-Run3/data/JEC/Autumn18_V19_MC/
cp Autumn18_V19_MC_Uncertainty_AK8PFPuppi.txt $cmsswReleaseVersion/src/HHToBBGG-Run3/data/JEC/Autumn18_V19_MC/
mkdir -p $cmsswReleaseVersion/src/HHToBBGG-Run3/data/JEC/Summer22_22Sep2023_RunCD_V2_DATA/
cp Summer22_22Sep2023_RunCD_V2_DATA_L1FastJet_AK4PFchs.txt $cmsswReleaseVersion/src/HHToBBGG-Run3/data/JEC/Summer22_22Sep2023_RunCD_V2_DATA/



###########################
#get cmssw environment
###########################
cd $cmsswReleaseVersion/src/
eval `scram runtime -sh`
tar vxzf input_list.tgz
#tar vxzf code.tgz
#make clean
#make
ls -l

###################################
#copy input files ahead of time
###################################
inputfilelist=input_list_${filenumber}.0.txt
mkdir inputs/
for i in `cat $inputfilelist`
do
echo "Copying Input File: " $i
xrdcp $i ./inputs/
done
ls inputs/* > tmp_input_list.txt 


###########################
#run executable
###########################
echo "Executing Analysis executable:"
echo "./${executable} tmp_input_list.txt --outputFile=${outputfile}_${filenumber}_Part${jobIndex}Of${nJobsPerFile}.root --optionNumber=${option} --isData=${isData} --year=${year} --pileupWeightName=${sampleName} --numberOfJobs=${nJobsPerFile} --jobIndex=${jobIndex}"
./${executable} tmp_input_list.txt --outputFile=${outputfile}_${filenumber}_Part${jobIndex}Of${nJobsPerFile}.root --optionNumber=${option} --isData=${isData} --year=${year} --pileupWeightName=${sampleName} --numberOfJobs=${nJobsPerFile} --jobIndex=${jobIndex}

ls -l
##########################################################
#copy outputfile to /eos space -- define in submitter code
##########################################################
#eosmkdir -p ${outputDirectory}
xrdfs root://cmseos.fnal.gov mkdir -p /store/user/nparekh/my_output_dir
xrdcp -f ${outputfile}_${filenumber}_Part${jobIndex}Of${nJobsPerFile}.root root://cmseos.fnal.gov/${outputDirectory}/${outputfile}_${filenumber}_Part${jobIndex}Of${nJobsPerFile}.root  
rm ${outputfile}_${filenumber}_Part${jobIndex}Of${nJobsPerFile}.root
rm inputs -rv 

cd -
