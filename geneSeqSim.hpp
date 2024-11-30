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