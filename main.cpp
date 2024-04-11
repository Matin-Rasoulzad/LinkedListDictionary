#include <iostream>
#include "NodeProcess.h"

using namespace std;

int main() {
    cout << "Welcome to Custom LinkedList Dictionary" << endl;
    string word;
    string synonym;

    while (true) {
        int userChoice;
        cout << endl;
        cout << "1. Add a word & synonym" << endl;
        cout << "2. Delete the word" << endl;
        cout << "3. Delete the synonym" << endl;
        cout << "4. Search by word or synonym" << endl;
        cout << "5. Display all of the database" << endl;
        cout << "6. Import data from file" << endl;
        cout << "7. Export data to file" << endl;
        cout << "8. Exit" << endl;
        cin >> userChoice;

        switch (userChoice) {
            NodeProcess processor;
            case 1: //Add a word & synonym
                cout << "Please enter a word: ";
                cin >> word;
                cout << "Please enter the synonym: ";
                cin >> synonym;
                processor.addNode(word,synonym);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                processor.showList();
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            default:
                cout << "Please Enter a valid choice!" << endl;
                break;
        }
    }
    return 0;
}
