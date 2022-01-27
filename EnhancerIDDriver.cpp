#include "EnhancerID.hpp"
#include <algorithm>

int main(int argc, char * argv[]){
    if(argc != 3){
        std::cout << "Please use ./EnhancerID one.bebGraph two.bedGraph\n";
    }
    std::vector <Peak> vecOfPeaksOne;
    std::vector <Peak> vecOfPeaksTwo;
    bool readFile1Output = readBedGraph(argv[1],vecOfPeaksOne); // vec passed by ref
    if(!readFile1Output){
        std::cout << "one.bedGraph failed to open\n";
    }
    bool readFile2Output = readBedGraph(argv[2],vecOfPeaksTwo); // vec passed by ref
    if(!readFile2Output){
        std::cout << "two.bedGraph failed to open\n";
    }
    std::sort(vecOfPeaksOne.begin(), vecOfPeaksOne.end(),sortByChrom);
    std::vector <Peak> overlappedPeaks;
}