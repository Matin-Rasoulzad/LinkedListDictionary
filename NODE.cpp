#include "NODE.h"
using namespace std;
// Sets the word stored in the node
void NODE::setWord(string word) {
    this->word = word;
}

// Sets the synonym of the word stored in the node
void NODE::setSynonym(string synonym) {
    this->synonym = synonym;
}

// Sets the next node in the linked list
void NODE::setNextAddress(NODE* Address) {
    this->nextNode = Address;
}

// Sets the next node to null, indicating the end of the list
void NODE::setTail() {
    nextNode = NULL;
}

// Returns the word stored in the node
string NODE::getWord() {
    return this->word;
}

// Returns the synonym of the word stored in the node
string NODE::getSynonym() {
    return this->synonym;
}

// Returns the next node in the linked list
NODE* NODE::getNextAddress() {
    return this->nextNode;
}