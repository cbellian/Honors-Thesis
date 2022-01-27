#include "EnhancerID.hpp"

int main(int argc, char * argv[]){
    if(argc != 3){
        std::cout << "Please use ./EnhancerID one.bebGraph two.bedGraph\n";
    }
    std::vector <Peak> vecOfPeaks;
    bool readFile1Output = readBedGraph(argv[1],vecOfPeaks); // vec passed by ref
    if(!readFile1Output){
        std::cout << "one.bedGraph failed to open\n";
    }
    bool readFile2Output = readBedGraph(argv[2],vecOfPeaks); // vec passed by ref
    if(!readFile2Output){
        std::cout << "two.bedGraph failed to open\n";
    }
    std::vector <Peak> overlappedPeaks;
}