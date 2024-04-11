#include "NodeProcess.h"
#include "NODE.h"
#include <iostream>

NODE *headerNode;

void NodeProcess::addNode(string word, string synonym) {
    NODE* incrementor;
    NODE* newNode = new NODE;

    if (headerNode == nullptr) {
        headerNode = new NODE;
        headerNode->setWord(word);
        headerNode->setSynonym(synonym);
        headerNode->setTail();
        cout << "First" << endl;
    }
    else {
        incrementor = headerNode;
        while (incrementor->getNextAddress()!= nullptr){
            incrementor = incrementor->getNextAddress();
            cout << "Ah" << endl;
        }
        newNode->setSynonym(synonym);
        newNode->setWord(word);
        newNode->setTail();
        incrementor->setNextAddress(newNode);
    }
}

void NodeProcess::showList() {
    NODE* incrementor = headerNode;

    for (int i = 1; incrementor != nullptr; ++i) {
        std::cout << "Word[" << i << "] : " << incrementor->getWord() << " := " << incrementor->getSynonym() << std::endl;
        incrementor = incrementor->getNextAddress();
    }
}