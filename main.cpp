#include "Assignment_1.h"

int main() {
	//Variables
	int array_size = 100;
	int* int_array = new int[array_size];
	old_and_new oan;
	int user_input1;
	int user_input2;
	int indent_counter = 0;
	
	// Attempt to open A1input.txt
	fstream inFile;
	inFile.open("A1input.txt");
	if (!inFile.is_open()) {
		cout << "Input file invalid.";
	}

	// Fill Array
	for (int i = 0; i < 100; i++) {
		inFile >> int_array[i];
	}

	// Showing off the first function
	cout << "Guess what, bro! You can find the index of any value you want! Isn't that AWESOME!?" << endl;
	cout << "You get to do this five whole times! Try not to have *too much* fun!" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "Enter index: (" << i + 1 << ") ";
		cin >> user_input1;
		cout << user_input1 << " is at index " << find_index_of_value(int_array, user_input1) << "!!!" << endl;
	}

	// Showing off the second function
	cout << endl << "This is so much fun!!! That was CRAZY! My eyes have been opened." << endl;
	cout << "You know what's more fun than putting in a number and getting back a number that's one higher than it? Changing things." << endl;
	cout << "Just by giving an index, and then a value, you can replace whatever's at that index with whatever value you gave. We're living in the FUTURE, man." << endl;
	for (int i = 0; i < 5; i++) {
		cout << "Enter index: (" << i + 1 << ") ";
		cin >> user_input1;
		cout << "Enter replacement value: ";
		cin >> user_input2;
		replace_value_at_index(int_array, user_input1, array_size, user_input2);
	}

	// Showing off the third function
	cout << endl << "Do not feel bad for the array. It is not worth compassion." << endl;
	cout << "To properly torture the array, we must first get its hopes up." << endl;
	cout << "Let's append some stuff to its tail end!" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "Enter new value: (" << i + 1 << ") ";
		cin >> user_input1;
		append_to_array(int_array, array_size, user_input1);
	}

	// Showing off the final function
	cout << endl << "We have gotten its hopes up. We have made it crave life. We have inflicted attachment upon it." << endl;
	cout << "Return its essence to nothingness, as a reminder of where we all must go." << endl;
	for (int i = 0; i < 5; i++) {
		cout << "Choose index to eliminate (" << i + 1 << ") ";
		cin >> user_input1;
		remove_at_index(int_array, array_size, user_input1);
	}

	cout << endl << "Your work is completed. The array has learned that all it clings to is impermanent and mutable." << endl;
	cout << "Behold: Its mangled, suffering form:" << endl << endl;

	// Print array
	for (int i = 0; i < array_size; i++) {
		cout << int_array[i] << " ";
		indent_counter++;

		if (indent_counter == 10) {
			cout << endl;
			indent_counter = 0;
		}
	}

	// Close file
	inFile.close();
}