#include "NodeProcess.h"
#include "NODE.h"
#include <iostream>
#include <fstream>
#include "vector"
#include "string"

NODE *headerNode; // Global variable for the header node of the linked list

// Function to add a new node to the linked list
void NodeProcess::addNode(string word, string synonym) {
    NODE *incrementor;
    NODE *newNode = new NODE;

    // If the linked list is empty, create the header node
    if (headerNode == nullptr) {
        headerNode = new NODE;
        headerNode->setWord(word);
        headerNode->setSynonym(synonym);
        headerNode->setTail();
    } else {
        // Traverse the linked list to find the last node
        incrementor = headerNode;
        while (incrementor->getNextAddress() != nullptr) {
            incrementor = incrementor->getNextAddress();
        }
        // Create a new node and set its word and synonym
        newNode->setSynonym(synonym);
        newNode->setWord(word);
        // Set the new node as the tail of the linked list
        newNode->setTail();
        // Connect the last node to the new node
        incrementor->setNextAddress(newNode);
    }
}

// Function to display the contents of the linked list
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

// Function to search for a node by its word number
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

// Function to search for a node by its word or synonym
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

// Function to edit a node's word or synonym
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

// Function to delete a node by its word or synonym
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

// Function to check if the linked list is empty
bool NodeProcess::isEmpty() {
    if (headerNode == nullptr) return true;
    else return false;
}

// Function to export the contents of the linked list to a CSV file
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

// Function to import nodes from a CSV file
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
        while (getline(file, countStr, ',') && getline(file, word, ',') && getline(file, synonym, '\n')) {
            addNode(word, synonym);
        }
        file.close();
        showList();
    }
}

void NodeProcess::sortNodes() {
    if (headerNode == nullptr || headerNode->getNextAddress() == nullptr) {
        // If the list is empty or has only one node, it's already sorted
        return;
    }

    NODE *current = headerNode;
    NODE *next = headerNode->getNextAddress();
    bool swapped;
    do {
        swapped = false;
        while (next != nullptr) {
            if (current->getWord() > next->getWord()) {
                // Swap the nodes
                string tempWord = current->getWord();
                string tempSynonym = current->getSynonym();
                current->setWord(next->getWord());
                current->setSynonym(next->getSynonym());
                next->setWord(tempWord);
                next->setSynonym(tempSynonym);
                swapped = true;
            }
            current = next;
            next = next->getNextAddress();
        }
        // Move the pointer back to the beginning of the list for the next iteration
        current = headerNode;
        next = headerNode->getNextAddress();
    } while (swapped);
}
