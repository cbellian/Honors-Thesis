#include "EnhancerID.hpp"
#include <algorithm>

int main(int argc, char * argv[]){
    if(argc != 5){
        std::cout << "Please use ./EnhancerID one.bebGraph two.bedGraph refseq.bed integer distance to be searched \n";
    } // checks for correct number of file input
    std::vector <Peak> vecOfPeaksOne;
    std::vector <Peak> vecOfPeaksTwo;
    bool readFile1Output = readBedGraph(argv[1],vecOfPeaksOne); // vec passed by ref, uses bool to identify succesful read
    if(!readFile1Output){
        std::cout << "one.bedGraph failed to open\n";
        return -1;
    }
    bool readFile2Output = readBedGraph(argv[2],vecOfPeaksTwo); // vec passed by ref, uses bool to identify succesful read
    if(!readFile2Output){
        std::cout << "two.bedGraph failed to open\n";
        return -2;
    }
    std::vector <Peak> vecOfTranscripts;
    bool readTranscriptOutput = readBedGraph(argv[3],vecOfTranscripts);
    if(!readTranscriptOutput){
        std::cout << "refseq.bed failed to open\n";
        return -3;
    }
    std::string bounds = argv[4];
    int boundsOfSearch = stoi(bounds);
    std::sort(vecOfPeaksOne.begin(), vecOfPeaksOne.end(),sortByChrom); // sort algo by chrom num
    std::sort(vecOfPeaksTwo.begin(), vecOfPeaksTwo.end(), sortByChrom); // sort algo by chrom num
    std::vector <Peak> overlappedPeaks;
    identifyOverlap(vecOfPeaksOne,vecOfPeaksTwo,overlappedPeaks); // void func, all passed by ref, edits passed by ref overlapped peak vec
    return 0;
}