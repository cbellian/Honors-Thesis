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

bool readLampreyBroadPeak(std::vector<Peak> &lampreyPeak1, std::string fileName);

bool readLampreyExonData(std::vector<Peak> &exonPeak, std::string fileName);

bool searchPeaksbyGeneLoci(std::vector<Peak> &lampreyPeak1, std::vector<Peak> &foundPeaks, std::string chromName, long int loc, int distance);

bool searchExonsbyGeneLoci(std::vector<Peak> &exonPeak, std::vector<Peak> &foundExons, std::string chromName, long int loc, int distance);

bool compareFoundPeaks(std::vector<Peak> &LampPeak1, std::vector<Peak> &LampPeak2, std::vector<Peak> &sharedPeaks);

void writeToFile(std::vector<Peak> &sharedPeaks, std::string fileName);

#endif
