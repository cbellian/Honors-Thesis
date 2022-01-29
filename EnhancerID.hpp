#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Peak{
    int chromNum;
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

void identifyOverlap(std::vector <Peak> &file1, std::vector <Peak> &file2, std::vector <Peak> &overlapVec); // identify where the input files overlap, including overhangs

bool readTranscriptBed(std::string filename, std::vector <Transcript> &vecOfTranscripts);