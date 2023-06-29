//#include "Huffman.h"
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <bitset>
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
    std::map<std::string, int>::iterator it;

    Symbols["C"] = 2;
    Symbols["B"] = 6;
    Symbols["E"] = 7;
    Symbols["_"] = 10;
    Symbols["D"] = 10;
    Symbols["A"] = 11;

    std::vector<node> Queue;
    
    std::map<std::string, int> Buff = Symbols;
    int frequency; 
    std::string symbol;
    for(int i = 0; i < Symbols.size(); i++) {
        frequency = 0;
        for(it = Buff.begin(); it != Buff.end(); it++) {
            std::cout << "siema" << std::endl;
            if(it->second > frequency) {
                symbol = it->first;
                frequency = it->second;
            }
        }
        node a = node(symbol, frequency);
        Queue.push_back(a);
        Buff.erase(symbol);
    }
    reverse(Queue.begin(), Queue.end());
    for(int i = 0; i < Queue.size(); i++) {
        std::cout << Queue.at(i).symbol << " " << Queue.at(i).code << " " << Queue.at(i).frequency << std::endl;
    }
    int size2 = Queue.size()*Queue.size();
    node* Nodes = new node[size2]; 
    int Nodes_counter = 0;
    while(!Queue.empty()) {
        Queue.at(0).code = '0';
        Queue.at(1).code = '1';
        node a = node(Queue.at(0).symbol + Queue.at(1).symbol, Queue.at(0).frequency + Queue.at(1).frequency);
        Nodes[Nodes_counter] = Queue.at(0);
        a.left = &Nodes[Nodes_counter];
        Nodes_counter ++;
        Nodes[Nodes_counter] = Queue.at(1);
        a.right = &Nodes[Nodes_counter];
        Nodes_counter ++;
        Queue.erase(Queue.begin(), Queue.begin() + 2);
        for(int i = 0; i < Queue.size(); i++) {
            //std::cout << Queue.at(i).symbol << std::endl;
            if(a.frequency < Queue.at(i).frequency) {
                Queue.insert(Queue.begin() + i, a);
                break;
            }
            if(i == Queue.size() - 1) {
                Queue.push_back(a);
                break;
            }
        }
        if(Queue.size() == 0) {
            Nodes[Nodes_counter] = a;
            Nodes_counter++;
            break;
        }
    }
    for(it = Symbols.begin(); it != Symbols.end(); it++) {
        std::cout << it->first << " ";
        node a = Nodes[Nodes_counter - 1];
        std::string code = "";
        int i = 0;
        while(a.left != NULL) {
            if(a.left->symbol.find(it->first) != std::string::npos) {
                code += a.left->code;
                a = *a.left;                
            }
            else {
                code += a.right->code;
                a = *a.right;
            }
            i++;
        }
        std::cout << code << std::endl; 
    }
    delete[] Nodes;
    return 0;
}