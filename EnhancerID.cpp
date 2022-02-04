#include "EnhancerID.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <thread>
#include <boost/tuple/tuple.hpp>
#include <algorithm>

// read in file
bool readBedGraph(std::string fileName, std::vector<Peak>&vecOfPeaks){
    std::ifstream bedIn;
    bedIn.open(fileName);
    if(bedIn.fail()){
        return false;
    }
    std::string line;
    while(getline(bedIn,line, '\n')){
        std::stringstream linestream(line);
        std::string chromNum;
        std::string chromStart;
        std::string chromEnd;
        getline(linestream,chromNum,'\t');
        getline(linestream,chromStart,'\t');
        getline(linestream,chromEnd,'\t');
        Peak tempPeak;
        tempPeak.chromNum = chromNum;
        tempPeak.chromStart = stol(chromStart);
        tempPeak.chromEnd = stol(chromEnd);
        vecOfPeaks.push_back(tempPeak);
        linestream.clear(); // necessary to avoid out of range in vec
    }
    bedIn.close();
    return true;
}

// predicate for sorting algo
bool sortByChrom(const Peak& in1, const Peak& in2){
    return in1.chromNum < in2.chromNum;
}

// can this be made more efficient? will be computationally expensive
void identifyOverlap(std::vector<long int> &peakfile1, std::vector<long int> &peakfile2,std::vector<Peak> &overlappedPeaks){
    Peak tempPeak;
    for(int i = 0; i < peakfile1.size()-2; i+=2){
        for(int j = 0; j < peakfile2.size()-2; j+=2){
            if(peakfile1.at(i) >= peakfile2.at(j) && peakfile1.at(i) <= peakfile2.at(j+1)){
                tempPeak.chromStart = peakfile2.at(j);
                tempPeak.chromEnd = std::max(peakfile1.at(i+1),peakfile2.at(j+1));
                tempPeak.chromNum = "chr1";
                overlappedPeaks.push_back(tempPeak);
            }
        }
    }
}


// read transcript file which includes accesion num
bool readTranscriptBed(std::string filename, std::vector <Transcript> &vecOfTranscripts){
    std::ifstream bedIn;
    bedIn.open(filename);
    if(bedIn.fail()){
        return false;
    }
    std::string line;
    int index = 0;
    while(getline(bedIn,line)){
        std::stringstream linestream(line);
        std::string chromNum;
        std::string chromStart;
        std::string chromEnd;
        std::string accesionString;
        getline(linestream,chromNum,',');
        getline(linestream,chromStart,',');
        getline(linestream,chromEnd,',');
        getline(linestream,accesionString,',');
        getline(linestream,line,'\n');
        Transcript tempTranscript;
        tempTranscript.chromNum = stoi(chromNum);
        tempTranscript.chromStart = stol(chromStart);
        tempTranscript.chromEnd = stol(chromEnd);
        tempTranscript.accesion = accesionString;
        vecOfTranscripts.push_back(tempTranscript);
    }
    bedIn.close();
    return true;
}

void sepByChromNum(std::vector <Peak> &vecOfPeaks,std::vector<long int> &chromLoc, std::string &chromName){
    for(int i = 0; i < vecOfPeaks.size(); i++){
        if(vecOfPeaks.at(i).chromNum == chromName){
            chromLoc.push_back(vecOfPeaks.at(i).chromStart);
            chromLoc.push_back(vecOfPeaks.at(i).chromEnd);
        }
    }
}

void writeToFile(std::vector <Peak> &vecOfPeaks){
    std::ofstream out1;
    out1.open("output.bed");
    for(int i = 0; i < vecOfPeaks.size(); i++){
        out1 << vecOfPeaks.at(i).chromNum << '\t' << vecOfPeaks.at(i).chromStart << '\t' << vecOfPeaks.at(i).chromEnd << '\n';
    }
}