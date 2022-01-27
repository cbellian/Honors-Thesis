#include <iostream>
#include <fstream>
#include <string>

struct Peak{
    int chromNum;
    long int chromStart;
    long int chromEnd;
};

int readBedGraph(std::string fielname,Peak arrayOfPeaks[],int length);