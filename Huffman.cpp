#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

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

std::map<std::string, std::string> Huffman(std::map<std::string, int> Symbols) {

    std::vector<node> Queue;
    std::map<std::string, int>::iterator it;
    std::map<std::string, int> Buff = Symbols;
    for(int i = 0; i < Symbols.size(); i++) {
        int frequency = 0;
        std::string symbol;
        for(it = Buff.begin(); it != Buff.end(); it++) {
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

    node* Nodes = new node[Queue.size()*Queue.size()]; 
    int Nodes_counter = 0;
    while(!Queue.empty()) {
        Queue.at(0).code = '0';
        Queue.at(1).code = '1';
        node a = node(Queue.at(0).symbol + Queue.at(1).symbol, 
                      Queue.at(0).frequency + Queue.at(1).frequency);

        Nodes[Nodes_counter] = Queue.at(0); a.left = &Nodes[Nodes_counter];
        Nodes_counter ++;
        Nodes[Nodes_counter] = Queue.at(1); a.right = &Nodes[Nodes_counter];
        Nodes_counter ++;
        Queue.erase(Queue.begin(), Queue.begin() + 2);
        for(int i = 0; i < Queue.size(); i++) {

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

    std::map<std::string, std::string> ReturnMap;
    for(it = Symbols.begin(); it != Symbols.end(); it++) {
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
        ReturnMap[it->first] = code;
    }
    delete[] Nodes;

    return ReturnMap;
}