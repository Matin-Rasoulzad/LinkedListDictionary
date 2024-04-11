#include <iostream>
#include "NODE.h"

using namespace std;

int main() {
    cout << "Welcome to Custom LinkedList Dictionary" << endl;

    while (true) {
        int userChoice;
        cout << endl;
        cout << "1. Add a word & synonym" << endl;
        cout << "2. Delete the word" << endl;
        cout << "3. Delete the synonym" << endl;
        cout << "4. Search by word or synonym" << endl;
        cout << "5. Import data from file" << endl;
        cout << "6. Export data to file" << endl;
        cout << "7. Exit" << endl;
        cin >> userChoice;

        switch (userChoice) {
            case 1: //Add a word & synonym

                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            default:
                cout << "Please Enter a valid choice!" << endl;
                break;
        }
    }
    return 0;
}
