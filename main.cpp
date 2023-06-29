#include "Huffman.h"
#include <string>
#include <map>
#include <iostream>

struct node {
    char code;
    std::string symbol;
    int frequency;
    node* left;
    node* right;

    node(std::string symboll, int frequencyy) {
        code = '0';
        symbol = symboll;
        frequency = frequencyy;
        left = NULL;
        right = NULL;
    }
    node() {};
};


int main() {

    std::map<std::string, int> Symbols;
    std::map<std::string, std::string> Encoded;
    Symbols["C"] = 2;
    Symbols["B"] = 6;
    Symbols["E"] = 7;
    Symbols["_"] = 10;
    Symbols["D"] = 10;
    Symbols["A"] = 11;

    Encoded = Huffman(Symbols);

    std::cout << "C: " << Encoded["C"] << std::endl;
    std::cout << "B: " << Encoded["B"] << std::endl;
    std::cout << "E: " << Encoded["E"] << std::endl;
    std::cout << "_: " << Encoded["_"] << std::endl;
    std::cout << "D: " << Encoded["D"] << std::endl;
    std::cout << "A: " << Encoded["A"] << std::endl;

    return 0;
}