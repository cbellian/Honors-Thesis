#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Peak{
    int chromNum;
    long int chromStart;
    long int chromEnd;
};

bool readBedGraph(std::string fielname, std::vector <Peak> &vecOfPeaks); // pass by ref so that return isnt needed because vec is normally passed by value