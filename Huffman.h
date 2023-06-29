#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>
#include <iostream>
#include <bitset>
#include <map>

std::map<std::string, std::bitset<8>> Huffman(std::map<int, std::string> Symbols);
    
#endif