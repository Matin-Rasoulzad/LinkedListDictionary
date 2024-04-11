//
// Created by Matin on 4/11/2024.
//

#ifndef LINKEDLISTDICTIONARY_NODE_H
#define LINKEDLISTDICTIONARY_NODE_H

#include <string>
using namespace std;
class NODE {
public:
    // Setters
    void setWord(string word);
    void setSynonym(string synonym);
    void setNextAddress(NODE* Address);
    void setTail();

    // Getters
    string getWord();
    string getSynonym();
    NODE* getNextAddress();

private:
    string word;
    string synonym;
    NODE *nextNode = nullptr;
};

#endif //LINKEDLISTDICTIONARY_NODE_H
