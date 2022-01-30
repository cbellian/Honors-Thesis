#include "EnhancerID.hpp"
#include <algorithm>
#include <thread>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout << "Please use ./EnhancerID one.bebGraph two.bedGraph refseq.bed integer distance to be searched \n";
    } // checks for correct number of file input
    std::vector<Peak> vecOfPeaksOne;
    std::vector<Peak> vecOfPeaksTwo;
    std::thread t1(readBedGraph, argv[1], std::ref(vecOfPeaksOne)); // vec passed by ref, uses bool to identify succesful read
    std::thread t2(readBedGraph, argv[2], std::ref(vecOfPeaksTwo)); // vec passed by ref, uses bool to identify succesful read
    std::vector<Transcript> vecOfTranscripts;
    // bool readTranscriptOutput = readTranscriptBed(argv[3], vecOfTranscripts);
    // if (!readTranscriptOutput)
    // {
    //     std::cout << "refseq.bed failed to open\n";
    //     return -3;
    // }
    // std::sort(vecOfPeaksOne.begin(), vecOfPeaksOne.end(),sortByChrom); // sort algo by chrom num
    // std::sort(vecOfPeaksTwo.begin(), vecOfPeaksTwo.end(), sortByChrom); // sort algo by chrom num
    std::vector<Peak> overlappedPeaks;
    t1.join();
    t2.join();
    identifyOverlap(vecOfPeaksOne, vecOfPeaksTwo, overlappedPeaks); // void func, all passed by ref, edits passed by ref overlapped peak vec
    char input;
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