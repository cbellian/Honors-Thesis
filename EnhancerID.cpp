#include "EnhancerID.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <thread>
#include <algorithm>

// read in file
bool readBedGraph(std::string fileName, std::vector<Peak>&vecOfPeaks){
    std::ifstream bedIn;
    bedIn.open(fileName);
    if(bedIn.fail()){
        return false;
    }
    std::string line;
    std::string chromNum;
    std::string chromStart;
    std::string chromEnd;
    Peak tempPeak;
    while(bedIn >> line){
        if(bedIn.eof()){
            bedIn.close();
            return true;
        }
        if(line.substr(0,3) == "chr"){
            chromNum = line;
            bedIn >> line;
            chromStart = line;
            bedIn >> line;
            chromEnd = line;
            tempPeak.chromNum = chromNum;
            tempPeak.chromStart = stol(chromStart);
            tempPeak.chromEnd = stol(chromEnd);
            vecOfPeaks.push_back(tempPeak);
        }
        line.clear(); // necessary to avoid out of range in vec
    }
    bedIn.close();
    return true;
}


// can this be made more efficient? will be computationally expensive
void identifyOverlap(std::vector<Peak> &peakfile1, std::vector<Peak> &peakfile2,std::vector<Peak> &overlappedPeaks){
    Peak tempPeak;
    for(auto i = 0; i < peakfile1.size(); i++){
        auto lower = std::lower_bound(peakfile2.begin(),peakfile2.end(),peakfile1.at(i),compareByStart);
        long int upper = 0;
        if(lower == peakfile2.end()){
            return;
        }
        if((*lower).chromEnd > peakfile1.at(i).chromEnd){
            upper = (*lower).chromEnd;
        }
        else{
            upper = peakfile1.at(i).chromEnd;
        }
        tempPeak.chromStart = peakfile1.at(i).chromStart;
        tempPeak.chromEnd = upper;
        tempPeak.chromNum = peakfile1.at(i).chromNum;
        overlappedPeaks.push_back(tempPeak);
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

void writeToFile(std::vector <Peak> &vecOfPeaks){
    std::ofstream out1;
    out1.open("output.bed",std::ios_base::app);
    if(out1.fail()){
        std::cout << "Failed to open output file.\n";
        return;
    }
    for(int i = 0; i < vecOfPeaks.size(); i++){
        out1 << vecOfPeaks.at(i).chromNum << '\t' << vecOfPeaks.at(i).chromStart << '\t' << vecOfPeaks.at(i).chromEnd << std::endl;
    }
}

void chromNameSearch(std::string &name,std::vector<std::string> &index){
    if(index.size()==0){
        index.push_back(name);
    }
    for(auto i = 0; i < index.size();i++){
        if(name != index.at(i)){
            index.push_back(name);
            return;
        }
    }
}

void chromDecomposition(std::vector<Peak> &vecOfPeaks, std::string &indexName, std::vector<Peak> &returnedPeaks){
    for(auto i = 0; i< vecOfPeaks.size();i++){
        if(vecOfPeaks.at(i).chromNum == indexName){
            returnedPeaks.push_back(vecOfPeaks.at(i));
        }
    }
}

bool compareByStart(const Peak &peak1, const Peak &peak2){
    return peak1.chromStart < peak2.chromStart;
}