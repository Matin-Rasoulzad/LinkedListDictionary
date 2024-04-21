//
// Created by Matin on 4/11/2024.
//

#ifndef LINKEDLISTDICTIONARY_NODEPROCESS_H
#define LINKEDLISTDICTIONARY_NODEPROCESS_H
#include "NODE.h"
#include <iostream>

using namespace std;
class NodeProcess {
public:
    void addNode(std::string word, std::string synonym);
    void showList();
    void searchNode(string word);
    void searchNode(int word);
    void deleteNode(string word);
    void editNode(string word);
    bool isEmpty();
    void exportNodes();
    void importNodes();
    static void sortNodes();
};
#endif //LINKEDLISTDICTIONARY_NODEPROCESS_H
