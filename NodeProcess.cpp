#include "NodeProcess.h"
#include "NODE.h"
#include <iostream>

NODE *headerNode;

void NodeProcess::addNode(string word, string synonym) {
    NODE *incrementor;
    NODE *newNode = new NODE;

    if (headerNode == nullptr) {
        headerNode = new NODE;
        headerNode->setWord(word);
        headerNode->setSynonym(synonym);
        headerNode->setTail();
        cout << "First" << endl;
    } else {
        incrementor = headerNode;
        while (incrementor->getNextAddress() != nullptr) {
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
    if (isEmpty()) {
        cout << "Database is empty.Please insert the words" << endl;
        return;
    }
    NODE *incrementor = headerNode;

    for (int i = 1; incrementor != nullptr; ++i) {
        std::cout << "Word[" << i << "] : " << incrementor->getWord() << " := " << incrementor->getSynonym()
                  << std::endl;
        incrementor = incrementor->getNextAddress();
    }
}

void NodeProcess::searchNode(int word) {
    if (isEmpty()) {
        cout << "Database is empty.Please insert the words" << endl;
        return;
    }
    NODE *incrementor = headerNode;
    for (int i = 1; i < word; i++) {
        if (incrementor->getNextAddress() != nullptr) {
            if (i == word)break;
            incrementor = incrementor->getNextAddress();
        } else {
            cout << "Index out of bound. Not a valid word NO." << endl;
            return;
        }
    }
    cout << "Word[" << word << "] : " << incrementor->getWord() << " := " << incrementor->getSynonym() << endl;
}

void NodeProcess::searchNode(string word) {
    if (isEmpty()) {
        cout << "Database is empty.Please insert the words" << endl;
        return;
    }
    NODE *incrementor = headerNode;

    int index = 1;
    while (incrementor->getWord() != word && incrementor->getSynonym() != word) {
        index++;
        if (incrementor->getNextAddress() != nullptr) {
            incrementor = incrementor->getNextAddress();
        } else {
            cout << "Word or synonym not found. Not a valid word or synonym." << endl;
            return;
        }
    }
    cout << "Word[" << index << "] : " << incrementor->getWord() << " := " << incrementor->getSynonym() << endl;
}

void NodeProcess::deleteNode(string word) {

}

bool NodeProcess::isEmpty() {
    if (headerNode == nullptr) return true;
    else return false;
}
