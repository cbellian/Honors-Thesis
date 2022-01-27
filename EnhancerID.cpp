#include "EnhancerID.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

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
    return true;
}