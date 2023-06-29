#define N 5

//#include "Huffman.h"
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <bitset>
#include <iostream>

struct node {
    std::bitset<1> code;
    char symbol[N];
    int frequency;
    node* left;
    node* right;
};

void copy_chars(const char in[N], char out[N]) {
    for(int i = 0; i < N; i++) out[i] = in[i];
}

struct node* NewNode(char symbol[5], std::bitset<1> code, int frequency) {
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
 
    // Assign data to this node
    node->code = code;
    copy_chars(symbol, node->symbol);
    node->frequency = frequency;
    // Initialize left and
    // right children as NULL
    node->left = NULL;
    node->right = NULL;
    return (node);
}


int main() {

    std::map<char[N], int> Symbols;
    std::map<char[N], int>::iterator it;

    Symbols["A000"] = 1;
    Symbols["B000"] = 4;
    Symbols["C000"] = 3;
    Symbols["D000"] = 2;
    std::vector<node*> Nodes;
    std::vector<node*> Queue;
    
    std::map<char[N], int> Buff = Symbols;
    int frequency; 
    char symbol[5] = "1111";
    for(int i = 0; i < Symbols.size(); i++) {
        frequency = 0;
        for(it = Buff.begin(); it != Buff.end(); it++) {
            std::cout << "siema" << std::endl;
            if(it->second > frequency) {
                copy_chars(it->first, symbol);
                frequency = it->second;
            }
        }
        Queue.push_back(NewNode(symbol, 0b0, frequency));
        Buff.erase(symbol);
    }
    reverse(Queue.begin(), Queue.end());

    for(int i = 0; i < Queue.size(); i++) {
        std::cout << Queue.at(i)->symbol << Queue.at(i)->code << " " << Queue.at(i)->frequency << std::endl;
    }

    return 0;
}