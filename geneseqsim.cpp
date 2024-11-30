/***************************************************************
  Student Name: Ari Palanjian
  File Name: geneseqsim.cpp
  Project 5

  Defines the member functions of class GeneSeqSim
***************************************************************/

#include "geneseqsim.hpp"
#include <fstream>
#include <iostream>
#include <string.h>
#include "lcs.hpp"
#include <cmath>

GeneSeqSim::GeneSeqSim(const char* fileTwoStrings, const char* fileMultiStrings, bool debug){
    this->fileTwoStrings = fileTwoStrings;
    this->fileMultiStrings = fileMultiStrings;
    this->debug = debug;
}

void GeneSeqSim::printM(int m, int n, char** arr){
    std::cout << "   ";
    for(int i = 0; i < n; i++){
        std::cout << "0" << i+1 << " ";
    }
    std::cout << "\n";
    for(int i = 0; i < m; i++){
        std::cout << "0" << i+1 << "  ";
        for(int j = 0; j < n; j++){
            std::cout << arr[i][j] << "  ";
        }
        std::cout << "\n";
    }
}

void GeneSeqSim::runPart1(){
    std::ifstream f1(fileTwoStrings);
    std::string s1;
    std::string s2;
    f1 >> s1;
    f1 >> s2;
    f1.close();

    if (debug){
        LCS test1("aaabaaa","aabbaca");
        test1.advBasic();
        test1.printC();
        std::cout << test1.getLCSConly(7,7) << "\n";
    } 
    LCS part1(s1,s2);
    part1.advBasic();
    std::cout << "String 1(" << s1.size() << "): \n\t" << s1 
        << "\n\nString 2(" << s2.size() << "): \n\t" << s2 << "\n\n";
    std::cout << "Longest Common Subsequence(" << part1.getMax() << "):\n\t";
    std::cout << part1.getLCSConly(s1.size()+1,s2.size()+1) << std::endl;
}

void GeneSeqSim::runPart2(){
    std::string s1;
    std::string s2;

    std::ifstream f2(fileMultiStrings);


    std::string tmp;
    //Get String count from file
    std::getline(f2, tmp);
    int count = std::stoi(tmp);
    int firstStrLoc = f2.tellg();//Location of first string after count

    if (debug){
        //Display strings in file using random access
        for(int i = 0; i < count; i++){
            f2.seekg(0, std::ios::cur);
            std::cout << i+1 << ": byte location: " << f2.tellg();
            std::getline(f2, tmp);
            std::cout << ", value: " << tmp << "\n";
        }
        //Reset flags and change current position to location of the first string
        f2.clear();
    }

    //Similarity matrix
    char** similarity = new char*[count];

    for(int i = 0; i < count; i++){
        //Initialize and populate 2d array with '-'s
        similarity[i] = new char[count];
        for(int j = 0; j < count; j++){
            similarity[i][j] = '-';
        }
    }

    //Loop through n-1 comparisons
    for(int i = 0; i < count - 1; i++){        
        f2.seekg(firstStrLoc, std::ios::beg);
        std::getline(f2, s1);
        firstStrLoc = f2.tellg();//change location to next string for next loop comparisons
        for (int j = i + 1; j < count; j++){
            //Compare to rest of strings other than itself and previously compared strings
            if(f2.tellg() != -1){       
                f2.seekg(0, std::ios::cur);
                std::getline(f2,s2);
                LCS part2(s1,s2);
                
                if (debug)
                    std::cout << "[" << i+1 << "][" << j+1 << "] ";
                
                similarity[i][j] = calculateSimilarity(s1,s2,part2.spaceSaving());
            }
        }

        f2.clear();
    }

    printM(count, count, similarity);
    //close and delete
    for(int i = 0; i < count; i++){
        delete[] similarity[i];
    }
    delete [] similarity;

    f2.close();

}

char GeneSeqSim::calculateSimilarity(std::string s1, std::string s2, int lenLCS){
    std::string longer, shorter;
    if (s1.size() > s2.size()){
        longer = s1;
        shorter = s2;
    } else {
        longer = s2;
        shorter = s1;
    }

    char val;    
    double strLenComp = 1.0 - (shorter.size() * 1.0 /longer.size());
    double lcsComp = 1.0 - ( lenLCS * 1.0 / shorter.size());
    
    if( strLenComp <= .1 && lcsComp <= .1 ) {        
        val = 'H';
    } else if (strLenComp <= .2 && lcsComp <= .2 ) {
        val = 'M';
    } else if (strLenComp <= .4 && lcsComp <= .5 ) {
        val = 'L';
    } else {
        val = 'D';
    }

    if (debug){
        std::cout << "longer: " << longer.size() << ", shorter: " << shorter.size() << ", len LCS: " << lenLCS;
        std::cout << " strLenComp: " << strLenComp << ", lcsComp: " << lcsComp;
        std::cout << ", val: " << val  << "\n";
    }

    return val;
}

void GeneSeqSim::run(){
    std::cout << "Part1:\n";
    runPart1();
    std::cout << "\nPart2:\n";
    runPart2();    
}