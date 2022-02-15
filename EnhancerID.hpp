#ifndef ENHANCERID_HPP
#define ENHANCERID_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Peak{
    std::string chromNum;
    long int chromStart;
    long int chromEnd;
};


struct Transcript{
    int chromNum;
    long int chromStart;
    long int chromEnd;
    std::string accesion;
};

bool readBedGraph(std::string filename, std::vector <Peak> &vecOfPeaks); // pass by ref so that return isnt needed because vec is normally passed by value

void identifyOverlap(std::vector <Peak> &file1, std::vector <Peak> &file2, std::vector <Peak> &overlapVec); // identify where the input files overlap, including overhangs

bool readTranscriptBed(std::string filename, std::vector <Transcript> &vecOfTranscripts);

void writeToFile(std::vector <Peak> &vecOfPeaks);

void chromNameSearch(std::string &name, std::vector<std::string> &index);

void chromDecomposition(std::vector<Peak> &vecOfPeaksOne,std::string &index,std::vector<Peak> &returnedPeaks);

bool compareByStart(const Peak &peak1, const Peak &peak2);

#endif
