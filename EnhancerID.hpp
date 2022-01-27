#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Peak{
    int chromNum;
    long int chromStart;
    long int chromEnd;
};


bool readBedGraph(std::string filename, std::vector <Peak> &vecOfPeaks); // pass by ref so that return isnt needed because vec is normally passed by value

bool sortByChrom(const long int& in1, const long int& in2); // func to pass into std::sort() to sort by chrom num, smallest to largest

void identifyOverlap(std::vector <Peak> &file1, std::vector <Peak> &file2, std::vector <Peak> &overlapVec);