#include "Assignment_1.h"

/*
	Find the index of a value in the array. Returns the index of the first instance of the value to be found.
	@ param int-array-pointer given_array: The array being searched through
	@ param int quarry: The value being looked for
	@ returns index of the first instance of the value found OR -1 if the value is nowhere in the array.
*/
int find_index_of_value(int*& given_array, int quarry) {
	try {
		for (int i = 0; i < 100; i++) {
			if (given_array[i] == quarry) {
				return i;
			}
		}
		throw exception();
	}
	catch (const exception& e) {
		cout << "The value you're looking for is somewhere, perhaps, but nowhere in this array." << endl;
		return -1;
	}
}

/*
	A function that can modify the value of an integer when called with the index of the integer in
	the array and return the new value and old value back to the user.

	@ param int-array-pointer given_array: The array which contains the value being replaced.
	@ param int quarry_index: The index of the value we want to be replaced.
	@ param int size: The number of elements in the given array.
	@ param int replacement_value: The value we want to replace one of the array's values with.
	@ return old_and_new struct containing what the replaced value used to be and what we replaced it with.
*/
old_and_new replace_value_at_index(int*& given_array, int quarry_index, int size, int replacement_value) {
	try {
		// Check to make sure that an out-of-bounds index has not been provided
		if (quarry_index < 0 || quarry_index >= size) {
			throw out_of_range("The given index is not in the array.");
		}

		// Store old value at quarry_index and the new value in an old_and_new object called "array_oan"
		old_and_new array_oan;
		array_oan.old_value = given_array[quarry_index];
		array_oan.new_value = replacement_value;

		// Replace the value at the given index and return the old_and_new structure.
		given_array[quarry_index] = replacement_value;
		return array_oan;
	}
	catch (const exception& e) {
		cout << "Exception caught with replace_value_at_index function: " << e.what() << endl;
	}
}

/*
	A function that adds a new integer to the end of the array
	@ param int-array-pointer given_array: The array that is having an extra value appended to it. This function accepts a by-reference pointer to the array.
	@ param int size: The size of the array being modified. This is by_reference because the size of the array will be incremented.
	@ param int new_value: The value of the integer we wish to append to the array.
*/
void append_to_array(int*& given_array, int& size, int new_value) {
	try {
		// Create a new, larger array
		int new_size = size + 1;
		int* new_array = new int[new_size];

		// Copy old array to new array
		for (int i = 0; i < size; i++) {
			new_array[i] = given_array[i];
		}

		// Add new value to the end of the new array
		new_array[new_size - 1] = new_value;

		// Update the by-reference variables so the change is real
		delete[] given_array;
		given_array = new_array;
		size = new_size;
	}
	catch (const exception& e) {
		cout << "Error occurred with function append_to_array: " << e.what() << endl;
	}
}

/*
	A function which intakes an index of an array and removes the integer altogether.
	@ param int-array-pointer given_array: The array of integers which is having a value at a given index removed. By-reference because it gets modified by this function.
	@ param int size: The size of the array that is going to have an integer removed. By-reference because it is going to be decreased by one.
	@ param int index_to_remove: The integer at this index will be removed from the array.
*/
void remove_at_index(int*& given_array, int& size, int index_to_remove) {
	try {
		// Make sure a valid index has been given.
		if (index_to_remove < 0 || index_to_remove >= size) {
			throw out_of_range("The given index value is not within the array's range.");
		}

		// Copy all elements starting at index_to_remove + 1 one to the left
		for (int i = index_to_remove; i < size; i++) {
			given_array[i] = given_array[i + 1];
		}

		// Create new array with a new size
		int new_size = size - 1;
		int* new_array = new int[new_size];

		// Copy all of the original array's values to the new array except for the last value, which has been doubled by the previous loop
		for (int i = 0; i < new_size; i++) {
			new_array[i] = given_array[i];
		}

		// Modify the referenced values to make the change real
		delete[] given_array;
		size = new_size;
		given_array = new_array;
	}
	catch (const exception& e) {
		cout << "Problem with remove_at_index function: " << e.what() << endl;
	}
}