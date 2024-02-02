#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
using namespace std;

struct old_and_new {
	int old_value, new_value;
};

/*
	Find the index of a value in the array. Returns the index of the first instance of the value to be found.
	@ param int-array-pointer given_array: The array being searched through
	@ param int quarry: The value being looked for
	@ returns index of the first instance of the value found OR -1 if the value is nowhere in the array.
*/
int find_index_of_value(int*& given_array, int quarry);

/*
	A function that can modify the value of an integer when called with the index of the integer in
	the array and return the new value and old value back to the user.

	@ param int-array-pointer given_array: The array which contains the value being replaced.
	@ param int quarry_index: The index of the value we want to be replaced.
	@ param int size: The number of elements in the given array.
	@ param int replacement_value: The value we want to replace one of the array's values with.
	@ return old_and_new struct containing what the replaced value used to be and what we replaced it with.
*/
old_and_new replace_value_at_index(int*& given_array, int quarry_index, int size, int replacement_value);

/*
	A function that adds a new integer to the end of the array
	@ param int-array-pointer given_array: The array that is having an extra value appended to it. This function accepts a by-reference pointer to the array.
	@ param int size: The size of the array being modified. This is by_reference because the size of the array will be incremented.
	@ param int new_value: The value of the integer we wish to append to the array.
*/
void append_to_array(int*& given_array, int& size, int new_value);

/*
	A function which intakes an index of an array and removes the integer altogether.
	@ param int-array-pointer given_array: The array of integers which is having a value at a given index removed. By-reference because it gets modified by this function.
	@ param int size: The size of the array that is going to have an integer removed. By-reference because it is going to be decreased by one.
	@ param int index_to_remove: The integer at this index will be removed from the array.
*/
void remove_at_index(int*& given_array, int& size, int index_to_remove);