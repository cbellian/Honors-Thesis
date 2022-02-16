#include "EnhancerID.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
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


// read transcript file which includes accesion num
// bool readTranscriptBed(std::string filename, std::vector <Transcript> &vecOfTranscripts){
//     std::ifstream bedIn;
//     bedIn.open(filename);
//     if(bedIn.fail()){
//         return false;
//     }
//     std::string line;
//     int index = 0;
//     while(getline(bedIn,line)){
//         std::stringstream linestream(line);
//         std::string chromNum;
//         std::string chromStart;
//         std::string chromEnd;
//         std::string accesionString;
//         getline(linestream,chromNum,',');
//         getline(linestream,chromStart,',');
//         getline(linestream,chromEnd,',');
//         getline(linestream,accesionString,',');
//         getline(linestream,line,'\n');
//         Transcript tempTranscript;
//         tempTranscript.chromNum = stoi(chromNum);
//         tempTranscript.chromStart = stol(chromStart);
//         tempTranscript.chromEnd = stol(chromEnd);
//         tempTranscript.accesion = accesionString;
//         vecOfTranscripts.push_back(tempTranscript);
//     }
//     bedIn.close();
//     return true;
// }

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

bool searchWithinRange(Peak &peak, int range, long int loci){
    long int val = 0;
    if(loci - range < 0){
        val = 0;
    }
    else{
        val = (loci-range);
    }
    return(val <= peak.chromStart && peak.chromStart <= val);
}

bool compareByStart(const Peak &peak1, const Peak &peak2){
    return peak1.chromStart < peak2.chromStart;
}

bool compareByEnd(const Peak &peak1, const Peak &peak2){
    return peak1.chromEnd < peak2.chromEnd;
}
