// Include necessary libraries
#include <iostream> // For input/output operations
#include "NodeProcess.h" // For NodeProcess class

// Using namespace to avoid writing std:: before every function
using namespace std;

// Main function where the program starts
int main() {
    // Welcome message
    cout << "Welcome to Custom LinkedList Dictionary" << endl;

    // Initialize variables
    string word;
    string synonym;

    // Infinite loop to keep the program running until user chooses to exit
    while (true) {
        // Display menu options
        int userChoice;
        cout << endl;
        cout << "1. Add a word & synonym" << endl;
        cout << "2. Delete the word or synonym" << endl;
        cout << "3. Edit typo the word or synonym" << endl;
        cout << "4. Search by word or synonym" << endl;
        cout << "5. Display all of of the database" << endl;
        cout << "6. Import data from file" << endl;
        cout << "7. Export data to file" << endl;
        cout << "8. Sort by alphabet order" << endl;
        cout << "9. Exit" << endl;

        // Get user input and validate the choice
        try {
            cin >> userChoice;
            if (userChoice < 1 || userChoice > 9) {
                throw invalid_argument("Invalid choice");
            }
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
            continue;
        }

        // Switch case to execute the corresponding function based on user choice
        switch (userChoice) {
            // Initialize NodeProcess object
            NodeProcess processor;

            // Case 1: Add a word & synonym
            case 1:
                cout << "Please enter a word: ";
                cin >> word;
                cout << "Please enter the synonym: ";
                cin >> synonym;
                processor.addNode(word,synonym);
                break;

                // Case 2: Delete the word or synonym
            case 2:
                cout << "Please enter the word: ";
                cin >> word;
                processor.deleteNode(word);
                break;

                // Case 3: Edit typo the word or synonym
            case 3:
                cout << "Please enter the word: ";
                cin >> word;
                processor.editNode(word);
                break;

                // Case 4: Search by word or synonym
            case 4:
                cout << "Please enter the word or its NO.: ";
                cin >> word;
                try {
                    // Check if word is NO. or string
                    processor.searchNode(stoi(word));
                } catch (const std::invalid_argument& e) {
                    processor.searchNode(word);
                }
                break;

                // Case 5: Display all the database
            case 5:
                processor.showList();
                break;

                // Case 6: Import data from file
            case 6:
                processor.importNodes();
                break;

                // Case 7: Export data to file
            case 7:
                processor.exportNodes();
                break;
            case 8:
                NodeProcess::sortNodes();
                cout << "Sorting by alphabet done successfully." << endl;
                break;
                // Case 9: Exit
            case 9:
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

                // Default case for invalid choices
            default:
                cout << "Please Enter a valid choice!" << endl;
                break;
        }
    }
}