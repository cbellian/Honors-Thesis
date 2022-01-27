#include "EnhancerID.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

int readBedGraph(std::string fileName, Peak arrayOfPeaks[],int length){
    std::ifstream bedIn;
    bedIn.open(fileName);
    if(bedIn.fail()){
        return -1;
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
        arrayOfPeaks[index].chromNum = stoi(chromNum);
        arrayOfPeaks[index].chromStart = stoi(chromStart);
        arrayOfPeaks[index].chromEnd = stoi(chromEnd);
    }

}