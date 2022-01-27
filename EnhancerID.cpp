#include <EnhancerID.hpp>
#include <fstream>
#include <string>
#include <iostream>

int readBedGraph(std::string fileName, Peak arrayOfPeaks[],int length){
    ifstream bedIn;
    bedIn.open(fileName);
    if(bedIn.fail()){
        return -1;
    }
    std::string line;
    while(getline(bedIn,line)){

    }

}