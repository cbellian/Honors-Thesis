#ifndef ENHANCERID_HPP
#define ENHANCERID_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/tuple/tuple.hpp>

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

bool sortByChrom(const long int& in1, const long int& in2); // func to pass into std::sort() to sort by chrom num, smallest to largest

void identifyOverlap(std::vector <long int> &file1, std::vector <long int> &file2, std::vector <Peak> &overlapVec,std::string &name); // identify where the input files overlap, including overhangs

bool readTranscriptBed(std::string filename, std::vector <Transcript> &vecOfTranscripts);

void writeToFile(std::vector <Peak> &vecOfPeaks);

bool chromNameSearch(std::string &name, std::vector<std::string> &index, int &location);

void chromDecomposition(std::vector<Peak> &vecOfPeaksOne, std::vector<long int> &vecSep1, std::string &chromName, std::vector<std::string> chromIndex, int &location);

#endif
