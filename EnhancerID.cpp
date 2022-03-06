#include "EnhancerID.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
 
 bool readLampreyBroadPeak(std::vector<Peak> &lampreyPeak1, std::string fileName){
     std::ifstream in1;
     in1.open(fileName);
     if(in1.fail()){
         std::cout << "Failed to open file" << std::endl;
         return false;
     }
     std::string line;
     while(getline(in1,line)){
         std::stringstream sep(line);
         std::string chromName, start, end;
         getline(sep,chromName,'\t');
         getline(sep,start,'\t');
         getline(sep,end,'\t');
         Peak temp;
         temp.chromNum = chromName;
         temp.chromStart = stol(start);
         temp.chromEnd = stol(end);
         lampreyPeak1.push_back(temp);
     }
     return true;
 }

bool readLampreyExonData(std::vector<Peak> &exonPeak, std::string fileName){
    std::ifstream in1;
    in1.open(fileName);
    if(in1.fail()){
        std::cout << "Failed to open exon file" << std::endl;
        return false;
    }
    std::string line;
    while(getline(in1,line)){
        std::stringstream sep(line);
        std::string chromName, start, end;
        getline(sep,chromName,'\t');
        getline(sep,start,'\t');
        getline(sep,end,'\t');
        Peak temp;
        temp.chromNum = chromName;
        temp.chromStart = stol(start);
        temp.chromEnd = stol(end);
        exonPeak.push_back(temp);
    }
    return true;
}

bool searchPeaksbyGeneLoci(std::vector<Peak> &lampreyPeak1, std::vector<Peak> &foundPeaks, std::string chromName, long int loc, int distance){
    int lowerbound = loc - distance;
    if(lowerbound < 0){
        lowerbound = 0;
    }
    int upperbound = loc + distance;
    for(int i = 0; i < lampreyPeak1.size();i++){
        if(lampreyPeak1.at(i).chromNum == chromName){
            if(lampreyPeak1.at(i).chromStart >= lowerbound && lampreyPeak1.at(i).chromEnd <= upperbound){
                Peak temp;
                temp.chromNum = chromName;
                temp.chromStart = lampreyPeak1.at(i).chromStart;
                temp.chromEnd = lampreyPeak1.at(i).chromEnd;
                foundPeaks.push_back(temp);
            }
        }
    }
    if(foundPeaks.empty()){
        return false;
    }
    return true;
}

bool searchExonsbyGeneLoci(std::vector<Peak> &exonPeak, std::vector<Peak> &foundExons, std::string chromName, long int loc, int distance){
     int lowerbound = loc - distance;
    if(lowerbound < 0){
        lowerbound = 0;
    }
    int upperbound = loc + distance;
    for(int i = 0; i < exonPeak.size();i++){
        if(exonPeak.at(i).chromNum == chromName){
            if(exonPeak.at(i).chromStart >= lowerbound && exonPeak.at(i).chromEnd <= upperbound){
                Peak temp;
                temp.chromNum = chromName;
                temp.chromStart = exonPeak.at(i).chromStart;
                temp.chromEnd = exonPeak.at(i).chromEnd;
                foundExons.push_back(temp);
            }
        }
    }
    if(foundExons.empty()){
        return false;
    }
    std::cout << foundExons.size() << " :number of exons found" << std::endl;
    return true;
}

bool compareFoundPeaks(std::vector<Peak> &LampPeak1, std::vector<Peak> &LampPeak2, std::vector<Peak> &sharedPeaks){
    for(int i = 0;i < LampPeak1.size();i++){
        for(int j = 0;j < LampPeak2.size();j++){
            if(LampPeak1.at(i).chromStart >= LampPeak2.at(j).chromStart && LampPeak1.at(i).chromStart <= LampPeak2.at(j).chromEnd){
                Peak temp;
                temp.chromNum = LampPeak2.at(j).chromNum;
                temp.chromStart = LampPeak2.at(j).chromStart;
                if(LampPeak1.at(i).chromEnd >= LampPeak2.at(j).chromEnd){
                    temp.chromEnd = LampPeak1.at(i).chromEnd;
                }
                else{
                    temp.chromEnd = LampPeak2.at(j).chromEnd;
                }
                sharedPeaks.push_back(temp);
            }
            if(LampPeak2.at(j).chromStart >= LampPeak1.at(i).chromStart && LampPeak2.at(j).chromStart <= LampPeak1.at(i).chromEnd){
                Peak temp;
                temp.chromNum = LampPeak1.at(i).chromNum;
                temp.chromStart = LampPeak1.at(i).chromStart;
                if(LampPeak2.at(j).chromEnd >= LampPeak1.at(i).chromEnd){
                    temp.chromEnd = LampPeak2.at(j).chromEnd;
                }
                else{
                    temp.chromEnd = LampPeak1.at(i).chromEnd;
                }
                sharedPeaks.push_back(temp);
            }
        }
    }
    if(sharedPeaks.empty()){
        return false;
    }
    return true;
}

bool sharedPeaksDist(std::vector<Peak> &sharedPeaks, std::vector<long int> &distVec, long int loc){
    long int value = 0;
    for(int i = 0; i < sharedPeaks.size(); i++){
        if(sharedPeaks.at(i).chromStart < loc){
            value = sharedPeaks.at(i).chromStart;
        }
        else{
            value = sharedPeaks.at(i).chromEnd;
        }
        long int distance = abs(value - loc);
        distVec.push_back(distance);
    }
    if(distVec.empty()){
        std::cout << "Empty distance Vector" << std::endl;
        return false;
    }
    return true;
}

void writeToFile(std::vector<Peak> &sharedPeaks, std::string fileName){
    std::ofstream out1;
    out1.open(fileName);
    for(int i = 0;i < sharedPeaks.size();i++){
        out1 << sharedPeaks.at(i).chromNum << '\t' << sharedPeaks.at(i).chromStart << '\t' << sharedPeaks.at(i).chromEnd << '\n';
    }
}
void writeToFileDist(std::vector<long int> &distvec, std::string filename){
    std::ofstream out1;
    out1.open(filename);
    for(int i = 0; i < distvec.size();i++){
        out1 << distvec.at(i) << '\n';
    }
}

bool searchPeaksbyGeneLociStartandFin(std::vector<Peak> &lampreyPeak1, std::vector<Peak> &foundPeaks, std::string chromName, int startLoc, int endLoc, int distanceFront, int endDistance){
    int lowerbound = startLoc - distanceFront;
    if(lowerbound < 0){
        lowerbound = 0;
    }
    int upperbound = endLoc + endDistance;
    for(int i = 0; i < lampreyPeak1.size();i++){
        if(lampreyPeak1.at(i).chromNum == chromName){
            if(lampreyPeak1.at(i).chromStart >= lowerbound && lampreyPeak1.at(i).chromEnd <= upperbound){
                Peak temp;
                temp.chromNum = chromName;
                temp.chromStart = lampreyPeak1.at(i).chromStart;
                temp.chromEnd = lampreyPeak1.at(i).chromEnd;
                foundPeaks.push_back(temp);
            }
        }
    }
    if(foundPeaks.empty()){
        return false;
    }
    return true;
}

bool unoverlapFoundPeaks(std::vector<Peak> &LampPeak1, std::vector<Peak> &LampPeak2, std::vector<Peak> &sharedPeaks)
{
    Peak temp;
    for(int i = 0;i < LampPeak1.size();i++)
    {
        for(int j = 0;j < LampPeak2.size();j++)
        {
            if(LampPeak1.at(i).chromStart < LampPeak2.at(j).chromStart && LampPeak1.at(i).chromEnd < LampPeak2.at(j).chromStart)
            {
                temp.chromNum = LampPeak1.at(i).chromNum;
                temp.chromStart = LampPeak1.at(i).chromStart;
                temp.chromEnd = LampPeak1.at(i).chromEnd;
                sharedPeaks.push_back(temp);
            }
            if(LampPeak2.at(j).chromStart < LampPeak1.at(i).chromStart && LampPeak2.at(j).chromEnd < LampPeak1.at(i).chromStart)
            {
                temp.chromNum = LampPeak2.at(j).chromNum;
                temp.chromStart = LampPeak2.at(j).chromStart;
                temp.chromEnd = LampPeak2.at(j).chromEnd;
                sharedPeaks.push_back(temp);
            }
        }
    }
    if(sharedPeaks.empty())
    {
        return false;
    }
    return true;
}
