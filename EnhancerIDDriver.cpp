#include "EnhancerID.hpp"
#include <algorithm>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout << "Please use ./EnhancerID one.bebGraph two.bedGraph \n";
        return -1;
    } // checks for correct number of file input
    std::vector<Peak> vecOfPeaksOne;
    bool peakOne = readBedGraph(argv[1], vecOfPeaksOne); // vec passed by ref, uses bool to identify succesful read
    if(!peakOne){
        std::cout << "Failed to open bedgraph." << std::endl;
    }
    char input;
    long int lociTarget = 0;
    int range = 0;
    std::string chromLoci;
    std::vector<Peak> vecAtLoci;
    do{
        std::cout << "Enter region of interest" << std::endl;
        std::cin >> lociTarget;
        std::cout << "Enter chrom name" << std::endl;
        std::cin >> chromLoci;
        std::cout << "Enter search range" << std::endl;
        std::cin >> range;
        for(auto i = 0; i < vecOfPeaksOne.size(); i++){
            if(chromLoci == vecOfPeaksOne.at(i).chromNum){
                if(searchWithinRange(vecOfPeaksOne.at(i),range,lociTarget)){
                    Peak tempPeak;
                    tempPeak.chromNum = chromLoci;
                    tempPeak.chromStart = vecOfPeaksOne.at(i).chromStart;
                    tempPeak.chromEnd = vecOfPeaksOne.at(i).chromEnd;
                    vecAtLoci.push_back(tempPeak);
                }
            }
        }
        writeToFile(vecAtLoci);

    }while (input != 'q');
    return 0;
}
