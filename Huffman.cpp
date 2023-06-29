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

struct node_list {

    node* Nodes;
    int append_index;

    void append(node a) {
        Nodes[append_index] = a;
        append_index += 1;
    }
    node GetLast() {       
        return Nodes[append_index - 1];
    }
    node* GetLastPointer() {
        node* pointer = &Nodes[append_index - 1];
        return pointer;
    }
    node_list(int size) {
        append_index = 0;
        Nodes = new node[size];
        node empty = node("", 0);
        for(int i = 0; i < size; i++) {
            Nodes[i] = empty;
        }    
    }
};

std::map<std::string, std::string> Huffman(std::map<std::string, int> Symbols) {

    int list_size = 2*Symbols.size() - 1;
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

    node_list Nodes = node_list(list_size);

    while(!Queue.empty()) {
        Queue.at(0).code = '0';
        Queue.at(1).code = '1';
        node a = node(Queue.at(0).symbol + Queue.at(1).symbol, 
                      Queue.at(0).frequency + Queue.at(1).frequency);
        Nodes.append(Queue.at(0)); 
        a.left = Nodes.GetLastPointer();
        Nodes.append(Queue.at(1));
        a.right = Nodes.GetLastPointer();
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
            Nodes.append(a);
            break;
        }
    }

    std::map<std::string, std::string> ReturnMap;
    for(it = Symbols.begin(); it != Symbols.end(); it++) {
        node a = Nodes.GetLast();
        std::string code = "";
        while(a.left != NULL) {
            if(a.left->symbol.find(it->first) != std::string::npos) {
                code += a.left->code;
                a = *a.left;                
            }
            else {
                code += a.right->code;
                a = *a.right;
            }
        }
        ReturnMap[it->first] = code;
    }
    delete[] Nodes.Nodes;

    return ReturnMap;
}