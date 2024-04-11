#include "NODE.h"
using namespace std;

void NODE::setWord(string word) {
    this->word = word;
}

void NODE::setSynonym(string synonym) {
    this->synonym = synonym;
}

void NODE::setAddress(NODE* Address) {
    this->nextNode = Address;
}

void NODE::setTail() {
    nextNode = NULL;
}

void NODE::setHead() {
    nextNode = NULL;
}

std::string NODE::getWord() {
    return this->word;
}

std::string NODE::getSynonym() {
    return this->synonym;
}

NODE* NODE::getAddress() {
    return this->nextNode;
}