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
    void setAddress(NODE* Address);
    void setTail();
    void setHead();

    // Getters
    string getWord();
    string getSynonym();
    NODE* getAddress();

private:
    string word;
    string synonym;
    NODE *nextNode;
};

#endif //LINKEDLISTDICTIONARY_NODE_H
