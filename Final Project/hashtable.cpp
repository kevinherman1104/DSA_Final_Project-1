#include <iostream>
#include <conio.h>
#include <cctype>
#include "hashtableheader.h"

using namespace std;

// Make a user interface to ask user what to do with the hashtable.
int main() {
	// Declare a new hashtable for the user to work on.
	HashTable hashtable;
	
	// Declare an integer which gets the user's choice.
	int choice;
	
	// Declare a bool which checks if the user's input is valid.
	bool valid;
	
	// Display the interface as long as the user is still using the program.
	while(true) {	
		// Display the interface as long as the user inputs choice out of menu, alphabets or nothing.
		do {
			system("cls");
			
			cout << "1. Add" << endl;
			cout << "2. Get" << endl;
			cout << "3. Update" << endl;
			cout << "4. Remove" << endl;
			cout << "5. Exit" << endl;
			
			cout << "Input choice: ";
			cin >> choice;
			
			if (choice < 1 || choice > 5 || cin.fail()) {
		        cout << "Please pick one of the choices above." << endl;
				
				getch();
		        
				cin.clear();
		        cin.ignore();
		        
				valid = false;
		    } else {
		        valid = true;
		    }
		} while(!valid);
		
		// If the user wants to add a new key-value pair, 
		if(choice == 1) {
			// Declare an integer which gets the user's desired key.
			int key;
			// Declare a string which gets the user's desired value.
			string value;
			
			// Check if the hashtable is full.
			// If it is not full, ask the user to input the desired key.
			// Otherwise, print an error message.
			if(!hashtable.full()) {
				// Ask the user to input the desired key.
				cout << "Input key to add: ";
				cin >> key;
				
				// Check if user enters an invalid input for the key.
				// If user enters a non-numeric input for the key, print an error message and clear the input state.
				// Otherwise, check if the user's desired key exists in the hashtable.
				if(cin.fail()) {
					// Print an error message.
					cout << "Key must be numeric!" << endl;
					
					// Clear the input state.
					cin.clear();
		        	cin.ignore();
				} else {
					// Check if the user's desired key exists in the hashtable.
					// If it does not exist, ask the user to input the desired value, add the key and value depending on the hash into the hashtable, then print a success message.
					// Otherwise, print an error message.
					if(hashtable.unique(key)) {
						// Ask the user to input the desired value.
						cout << "Input value to add: ";
						cin >> value;
						
						// Add the key and value depending on the hash into the hashtable.
						hashtable.add(key, value);
						
						// Print a success message.
						cout << "Key and value has been added." << endl;
					} else {
						// Print an error message if the user's desired key exists in the hashtable.
						cout << "Key must be unique!" << endl;
					}
				}
			} else {
				// Print an error message if the hashtable is full.
				cout << "Hash table is full!" << endl;
			}
			
			getch();
		}
		// If the user wants to get the value from a pair,
		else if(choice == 2) {
			// Declare an integer which gets the user's desired key.
			int key;
			
			// Ask the user to input the desired key.
			cout << "Input key to get value: ";
			cin >> key;
			
			// Check if user enters an invalid input for the key.
			// If user enters a non-numeric input for the key, print an error message and clear the input state.
			// Otherwise, print the value of the key.
			if(cin.fail()) {
				// Print an error message.
				cout << "Key must be numeric!" << endl;
				
				// Clear the input state.
				cin.clear();
				cin.ignore();
			} else {
				// If the key exists, the program will print the value of the key.
				// Otherwise, the program will print an empty string for the value.
				cout << "Value of key " << key << ": " << hashtable.get(key) << endl;
			}
			
			getch();
		}
		// If the user wants to update the value of a pair,
		else if(choice == 3) {
			// Declare an integer which gets the user's desired key.
			int key;
			// Declare a string which gets the user's desired value.
			string value;
			
			// Ask the user to input the desired key.
			cout << "Input key to update: ";
			cin >> key;
			
			// Check if user enters an invalid input for the key.
			// If user enters a blank input for the key, print an error message and clear the input state.
			// Otherwise, ask the user to input the new value, then print the update status.
			if(cin.fail()) {
				// Print an error message.
				cout << "Key must be numeric!" << endl;
				
				// Clear the input state.
				cin.clear();
				cin.ignore();
			} else {
				// Ask the user to input the new value.
				cout << "Input value to update: ";
				cin >> value;
				
				// Print the update status.
				// If the value update succeeds, the program will print 1.
				// Otherwise, the program will print 0.
				cout << "Update status: " << hashtable.update(key, value) << endl;
			}
			
			getch();
		}
		// If the user wants to remove a key-value pair,
		else if(choice == 4) {
			// Declare an integer which gets the user's desired key.
			int key;
			
			// Ask the user to input the desired key.
			cout << "Input key to remove: ";
			cin >> key;
			
			// Check if user enters an invalid input for the key.
			// If user enters a blank input for the key, print an error message and clear the input state.
			// Otherwise, print the remove status.
			if(cin.fail()) {
				// Print an error message.
				cout << "Key must be numeric!" << endl;
				
				// Clear the input state.
				cin.clear();
				cin.ignore();
			} else {
				// Print the remove status.
				// If the pair removal succeeds, the program will print 1.
				// Otherwise, the program will print 0.
				cout << "Remove status: " << hashtable.remove(key) << endl;
			}
			
			getch();
		}
		// If the user wants to exit from the program,
		else if(choice == 5) {
			// Break from the infinite loop which then terminates the program.
			break;
		}
	}
	
	return 0;
}
