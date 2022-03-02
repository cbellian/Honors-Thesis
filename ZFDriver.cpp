#include "EnhancerID.hpp"

int main(int argc,char* argv[]){
    std::cout << "Enter first file name/path\n";
    std::string firstFileName, secondFileName,chromName,strGeneStart,strGeneEnd,frontDist,endDist;
    getline(std::cin, firstFileName);
    std::cout << "Enter second file name/path\n";
    getline(std::cin,secondFileName);
    std::cout << "Enter chromosome name/num i.e chr1\n";
    getline(std::cin,chromName);
    std::cout << "Enter location of start of gene\n";
    getline(std::cin,strGeneStart);
    std::cout << "Enter location of end of gene\n";
    getline(std::cin,strGeneEnd);
    std::cout << "Enter distance to search from start of gene\n";
    getline(std::cin,frontDist);
    std::cout << "Enter distance to search from end of gene\n";
    getline(std::cin,endDist);
    int GeneStart = stoi(strGeneStart);
    int GeneEnd = stoi(strGeneEnd);
    int fDistance = stoi(frontDist);
    int eDistance = stoi(endDist);
    std::cout << "converted input\n";
    std::vector <Peak> ZFPeak1;
    std::vector <Peak> ZFPeak2;
    std::vector <Peak> foundPeak1;
    std::vector <Peak> foundPeak2;
    std::vector <Peak> OverlappedPeaks;
    bool peak1 = readLampreyBroadPeak(ZFPeak1,firstFileName);
    if(!peak1){
        std::cout << "Failed to open file 1\n";
        return -1;
    }
    std::cout << "Read file 1\n";
    bool peak2 = readLampreyBroadPeak(ZFPeak2,secondFileName);
    if(!peak2){
        std::cout << "Failed to open file 2\n";
        return -1;
    }
    std::cout << "Read file 2\n";
    bool overlap1 = searchPeaksbyGeneLociStartandFin(ZFPeak1,foundPeak1,chromName,GeneStart,GeneEnd,fDistance,eDistance);
    if(!overlap1){
        std::cout << "Failed to find peaks in file 1 on chromosome " << chromName << std::endl;
        return -2;
    }
    bool overlap2 =  searchPeaksbyGeneLociStartandFin(ZFPeak2,foundPeak2,chromName,GeneStart,GeneEnd,fDistance,eDistance);
    if(!overlap2){
        std::cout << "Failed to find peaks in file 2 on chromosome " << chromName << std::endl;
        return -2;
    }
    bool compare = compareFoundPeaks(foundPeak1,foundPeak2,OverlappedPeaks);
    if(!compare){
        std::cout << "Could not find any overlapping peaks\n";
        return -3;
    }
    std::cout << "Enter filename to write to: \n";
    std::string fileOut;
    getline(std::cin,fileOut);
    writeToFile(OverlappedPeaks,fileOut);
    return 0;
}