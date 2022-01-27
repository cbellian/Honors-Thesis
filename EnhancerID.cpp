#include "EnhancerID.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

// read in file
bool readBedGraph(std::string fileName, std::vector<Peak>&vecOfPeaks){
    std::ifstream bedIn;
    bedIn.open(fileName);
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
        getline(linestream,chromNum,',');
        getline(linestream,chromStart,',');
        getline(linestream,chromEnd,',');
        getline(linestream,line,'\n');
        Peak tempPeak;
        tempPeak.chromNum = stoi(chromNum);
        tempPeak.chromStart = stol(chromStart);
        tempPeak.chromEnd = stol(chromEnd);
        vecOfPeaks.push_back(tempPeak);
    }
    bedIn.close();
    return true;
}

// predicate for sorting algo
bool sortByChrom(const Peak& in1, const Peak& in2){
    return in1.chromNum < in2.chromNum;
}

// can this be made more efficient? will be computationally expensive
void identifyOverlap(std::vector<Peak> &peakfile1, std::vector<Peak> &peakfile2,std::vector<Peak> &overlappedPeaks){
    for(int i = 0; i < peakfile1.size(); i++){
        for(int j = 0; j < peakfile2.size(); j++){
            if(peakfile1.at(i).chromNum == peakfile2.at(j).chromNum){
                if(peakfile1.at(i).chromStart >= peakfile2.at(j).chromStart && peakfile1.at(i).chromStart <= peakfile2.at(j).chromEnd){
                    overlappedPeaks.push_back(peakfile1.at(i));
                }
                else if(peakfile2.at(j).chromStart >= peakfile1.at(i).chromStart && peakfile2.at(j).chromStart <= peakfile1.at(i).chromEnd){
                    overlappedPeaks.push_back(peakfile2.at(j));
                }
            }
        }
    }
}