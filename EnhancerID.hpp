#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Peak{
    int chromNum;
    long int chromStart;
    long int chromEnd;
};

struct chromSorted : public Peak{
    std::vector<Peak> vecOfPeaksInChrom;
};

bool readBedGraph(std::string filename, std::vector <Peak> &vecOfPeaks); // pass by ref so that return isnt needed because vec is normally passed by value

void identifyOverlap(std::vector <Peak> &file1, std::vector <Peak> &file2, std::vector <Peak> &overlapVec);