#include "EnhancerID.hpp"
#include <algorithm>

int main(int argc, char *argv[])
{
    std::vector<Peak> LampreyBroadPeak1;
    std::vector<Peak> LampreyBroadPeak2;
    std::vector<Peak> exonPeak;
    std::string fileName1 = argv[1];
    std::string fileName2 = argv[2];
    std::string exonFile = argv[3];
    bool read = readLampreyBroadPeak(LampreyBroadPeak1,fileName1);
    if(!read){
        std::cout << "Failed to read file 1" << std::endl;
        return -1;
    }
    bool read2 = readLampreyBroadPeak(LampreyBroadPeak2,fileName2);
    if(!read2){
        std::cout << "Failed to read file 2" << std::endl;
    }
    bool exon = readLampreyExonData(exonPeak,exonFile);
    if(!exon){
        std::cout << "Failed to read exon file" << std::endl;
    }
    std::string chromNametoSearch;
    long int chromPostoSearch = 0;
    int distance = 0;
    std::cout << "Enter Chromosome Location i.e. PIZI01000001.1" << std::endl;
    std::cin >> chromNametoSearch;
    std:: cout << "Enter Location of Center of Gene of Interest i.e. 5779269" << std::endl;
    std::cin >> chromPostoSearch;
    std::cout << "Enter the distance to search i.e. 500000 for 500,000 bp" << std::endl;
    std::cin >> distance;
    std::vector<Peak> foundPeaks1;
    std::vector<Peak> foundPeaks2;
    std::vector<Peak> foundExons;
    bool found = searchPeaksbyGeneLoci(LampreyBroadPeak1,foundPeaks1,chromNametoSearch,chromPostoSearch,distance);
    if(!found){
        std::cout << "Could not find any file 1 peaks within " << distance << " of " << chromPostoSearch << " on " << chromNametoSearch << std::endl;
    }
    bool found2 = searchPeaksbyGeneLoci(LampreyBroadPeak2,foundPeaks2,chromNametoSearch,chromPostoSearch,distance);
    if(!found2){
        std::cout << "Could not find any file 2 peaks within " << distance << " of " << chromPostoSearch << " on " << chromNametoSearch << std::endl; 
    }
    bool exonFound = searchExonsbyGeneLoci(exonPeak,foundExons,chromNametoSearch,chromPostoSearch,distance);
    if(!exonFound){
        std::cout << "Could not find any exon peaks within " << distance << " of " << chromPostoSearch << " on " << chromNametoSearch << std::endl;
    }
    std::vector<Peak> sharedPeaks;
    bool overlap = compareFoundPeaks(foundPeaks1,foundPeaks2,sharedPeaks);
    if(!overlap){
        std::cout << "No Overlap found between files" << std::endl;
    }
    
    std::string outputFileName = "output.bed";
    writeToFile(sharedPeaks,outputFileName);
    return 0;
}
