#include <string>
#include <iostream>
#include <bitset>
#include <map>
#include <vector>

struct node {
    std::bitset<1> code;
    std::string Symbol;
    node* left;
    node* right;
};

struct node* NewNode(std::bitset<1> code) {
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
 
    // Assign data to this node
    node->code = code;
 
    // Initialize left and
    // right children as NULL
    node->left = NULL;
    node->right = NULL;
    return (node);
}


std::map<std::string, std::bitset<8>> Huffman(std::map<int, std::string> Symbols) {
    std::map<std::string, std::bitset<8>> Encoded;
    int index = Symbols.size();

    std::vector<node*> vector;

    return Encoded;
}