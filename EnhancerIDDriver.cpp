#include "EnhancerID.hpp"
#include <algorithm>
#include <thread>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout << "Please use ./EnhancerID one.bebGraph two.bedGraph \n";
        return -1;
    } // checks for correct number of file input
    std::vector<Peak> vecOfPeaksOne;
    std::vector<Peak> vecOfPeaksTwo;
    bool peakOne = readBedGraph(argv[1], vecOfPeaksOne); // vec passed by ref, uses bool to identify succesful read
    bool peakTwo = readBedGraph(argv[2], vecOfPeaksTwo); // vec passed by ref, uses bool to identify succesful read
    if(!peakOne)
    {
        std::cout <<"one failed\n";
    }
    if(!peakTwo)
    {
        std::cout <<"two failed\n";
    }
    // std::vector<Transcript> vecOfTranscripts;
    // bool readTranscriptOutput = readTranscriptBed(argv[3], vecOfTranscripts);
    // if (!readTranscriptOutput)
    // {
    //     std::cout << "refseq.bed failed to open\n";
    //     return -3;
    // }
    std::vector<std::string> indexOfChromName;
    std::string tempChromName;
    for(auto i = 0; i < vecOfPeaksOne.size();i++){
        tempChromName = vecOfPeaksOne.at(i).chromNum;
        chromNameSearch(tempChromName,indexOfChromName);
    }
    for(auto i = 0; i < vecOfPeaksTwo.size(); i++){
        tempChromName = vecOfPeaksTwo.at(i).chromNum;
        chromNameSearch(tempChromName,indexOfChromName);
    }
    // good through here
    std::vector<Peak> singleChromPeaksOne;
    std::vector<Peak> singleChromPeaksTwo;
    std::string nameOfChrom;
    for(auto i = 0; i < indexOfChromName.size();i++){
        nameOfChrom = indexOfChromName.at(i);
        std::vector<Peak> overlappedPeak;
        chromDecomposition(vecOfPeaksOne,nameOfChrom,singleChromPeaksOne);
        chromDecomposition(vecOfPeaksTwo,nameOfChrom,singleChromPeaksTwo);
        std::sort(vecOfPeaksOne.begin(),vecOfPeaksOne.end(),compareByStart);
        std::sort(vecOfPeaksTwo.begin(),vecOfPeaksTwo.end(),compareByStart);
        identifyOverlap(singleChromPeaksOne,singleChromPeaksTwo,overlappedPeak);
        writeToFile(overlappedPeak);
    }
    // char input;
    // do{
    //     std::cout << "Menu\n";
    //     std::cout << "R: Refseq accesion number to be center of search\n";
    //     std::cout << "L: Location as to be searched from\n";
    //     std::cout << "Q: Quit\n";
    //     static std::string in_string;
    //     getline(std::cin, in_string);
    //     input = in_string[0];
    //     tolower(input);
    //     switch(input){
    //         default:{
    //             std::cout << "Invalid Input\n";
    //         }break;
    //         case 'r':{
    //             std::cout << "Enter the accesion number of interest.\n";
    //             static std::string accesionString;
    //             getline(std::cin, accesionString);
    //         }break;
    //         case 'l':{
    //             std::cout << "Enter chromosome number.\n";
    //             static std::string chromNumString, bpNumString;
    //             getline(std::cin,chromNumString);
    //             std::cout << "Enter the location on the chromosome.\n";
    //             getline(std::cin,bpNumString);
    //             int chromNum, bpNum;
    //             chromNum = stoi(chromNumString);
    //             bpNum = stoi(bpNumString);
    //         }
    //     }
    // }while (input != 'q');
    return 0;
}
