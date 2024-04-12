#include "NodeProcess.h"
#include "NODE.h"
#include <iostream>
#include <fstream>
#include "ctime"
#include "vector"
#include "string"

NODE *headerNode;

void NodeProcess::addNode(string word, string synonym) {
    NODE *incrementor;
    NODE *newNode = new NODE;

    if (headerNode == nullptr) {
        headerNode = new NODE;
        headerNode->setWord(word);
        headerNode->setSynonym(synonym);
        headerNode->setTail();
    } else {
        incrementor = headerNode;
        while (incrementor->getNextAddress() != nullptr) {
            incrementor = incrementor->getNextAddress();
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
void NodeProcess::editNode(string word) {
    if (isEmpty()) {
        cout << "Database is empty.Please insert the words" << endl;
        return;
    }
    NODE *incrementor = headerNode;

    int index = 1;
    while (incrementor != nullptr && incrementor->getWord() != word && incrementor->getSynonym() != word) {
        index++;
        incrementor = incrementor->getNextAddress();
    }

    if (incrementor == nullptr) {
        cout << "Word or synonym not found. Not a valid word or synonym." << endl;
        return;
    }

    cout << "Word[" << index << "] : " << incrementor->getWord() << " := " << incrementor->getSynonym() << endl;
    string userWord;
    if (incrementor->getWord() == word) {
        cout << "Please enter the new word: ";
        cin >> userWord;
        incrementor->setWord(userWord);
    } else {
        cout << "Please enter the new synonym: ";
        cin >> userWord;
        incrementor->setSynonym(userWord);
    }
}

void NodeProcess::deleteNode(string word) {
    if (isEmpty()) {
        cout << "Database is empty. Please insert the words" << endl;
        return;
    }
    NODE *incrementor = headerNode;
    NODE *incrementor_pre = nullptr;

    while (incrementor != nullptr && incrementor->getWord() != word && incrementor->getSynonym() != word) {
        incrementor_pre = incrementor;
        incrementor = incrementor->getNextAddress();
    }

    if (incrementor == nullptr) {
        cout << "Word or synonym not found. Not a valid word or synonym." << endl;
        return;
    }

    // If node to be deleted is the head node
    if (incrementor_pre == nullptr) {
        headerNode = incrementor->getNextAddress();
    } else {
        incrementor_pre->setNextAddress(incrementor->getNextAddress());
    }

    delete incrementor;
    cout << "Node deleted successfully." << endl;
}

bool NodeProcess::isEmpty() {
    if (headerNode == nullptr) return true;
    else return false;
}

void NodeProcess::exportNodes() {
    if (isEmpty()) {
        cout << "Database is empty.Please insert the words" << endl;
        return;
    }
    ofstream file("Words_DataBase.csv");
    NODE *incrementor = headerNode;

    for (int i = 1; incrementor != nullptr; ++i) {
        file << i << "," << incrementor->getWord() << "," << incrementor->getSynonym()
             << endl;
        incrementor = incrementor->getNextAddress();
    }
    cout << "Exported successfully.\nFile location is:  " << "Words_DataBase.csv" << endl;
    file.close();
}

void NodeProcess::importNodes() {
    headerNode = nullptr;
    string fileName;
    cout << "Please enter your filename(Type \"default\" for default program save):\n";
    cin >> fileName;

    ifstream file;
    if (fileName == "default") {
        file.open("Words_DataBase.csv");
    } else {
        file.open(fileName);
    }
    if (file.fail()) {
        cerr << "There was an error opening the file.\n";
    } else {
        cout << "File opened successfully.\n";
        if (file.peek() == std::ifstream::traits_type::eof()) {
            cout << "File is empty." << endl;
            return;
        }
        string word;
        string countStr;
        string synonym;
        while (file.good()) {
            getline(file, countStr, ',');
            getline(file, word, ',');
            getline(file, synonym, '\n');
            addNode(word, synonym);
        }
        file.close();
        showList();
    }

}
