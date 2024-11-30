/***************************************************************
  Student Name: Ari Palanjian
  File Name: geneseqsim.hpp
  Project 5

  Defines the class GeneSeqSim which is the driver program
    to run part 1, which calculates and reconstructs the 
    longest common subsequence between two strings, and part 2,
    which creates a similarity table by finding the lcs for n
    strings. 
***************************************************************/
#ifndef GENESEQSIM_HPP
#define GENESEQSIM_HPP

#include <string>

class GeneSeqSim{
    bool debug;
    const char* fileTwoStrings;
    const char* fileMultiStrings;

    void runPart1();
    void runPart2();
    char calculateSimilarity(std::string s1, std::string s2, int lenLCS);
    void printM(int m, int n, char** arr);
public:
    GeneSeqSim(const char* fileTwoStrings, const char* fileMultiStrings, bool debug);

    void run();

};

#endif