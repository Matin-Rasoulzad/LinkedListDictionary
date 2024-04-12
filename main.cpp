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
        cout << "2. Delete the word or synonym" << endl;
        cout << "3. Edit typo the word or synonym" << endl;
        cout << "4. Search by word or synonym" << endl;
        cout << "5. Display all of the database" << endl;
        cout << "6. Import data from file" << endl;
        cout << "7. Export data to file" << endl;
        cout << "8. Exit" << endl;
        try {
            cin >> userChoice;
            if (userChoice < 1 || userChoice > 8) {
                throw invalid_argument("Invalid choice");
            }
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
            continue;
        }

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
                cout << "Please enter the word: ";
                cin >> word;
                processor.deleteNode(word);
                break;
            case 3:
                cout << "Please enter the word: ";
                cin >> word;
                processor.editNode(word);
                break;
            case 4:
                cout << "Please enter the word or its NO.: ";
                cin >> word;
                try {
                    //Check if word is NO. or string
                    processor.searchNode(stoi(word));
                } catch (const std::invalid_argument& e) {
                    processor.searchNode(word);
                }
                break;
            case 5:
                processor.showList();
                break;
            case 6:
                processor.importNodes();
                break;
            case 7:
                processor.exportNodes();
                break;
            case 8:
                char choice;
                cout << "Do you want to save your progress? (y/n):\n";
                cin >> choice;
                if(tolower(choice)=='y'){
                    processor.exportNodes();
                    exit(0);
                }
                else{
                    exit(0);
                }
                break;
            default:
                cout << "Please Enter a valid choice!" << endl;
                break;
        }
    }
}