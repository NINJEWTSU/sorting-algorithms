//============================================================================
// Name        : sorting.cpp
// Author      : me sam
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <sstream>

#include "BubbleSort.cpp"

using namespace std;

//***structs here***
struct Data{
	int* dataset;
	int dataset_size;
};


//***prototypes here***
void displayMenu(); //displays the main menu
bool handleInput(); //handles main menu input

void bubbleSortSelection(); //performs bubble sort option

Data* dataSetCreation(); //handles dataset creation
void dataSetCreationMenu(); //displays menu for creating a dataset
Data* randomDatasetSelection(); //handles creating a random dataset

int* createRandomDataset(int); //creates and populates a dataset with random values
void displayDataset(int*, int); //displays a dataset
void deleteData(Data*); //deletes the Data struct

/*
 * basic sort assumptions:
 * -dataset can be randomly generated or hand designed, and is not of a static size.
 * --empty datasets are valid
 * ---dataset will not be larger than 1000 elements
 * -dataset consists solely of ints
 * --dataset values range from -1000 to +1000
 * -dataset will come in the format of an int*
 * -dataset produced by algorithm will be a new int*, old pre-sort arrangement will still exist
 */


/*
 * NEW ALGORITHM INSTRUCTIONS
 * increase NUMBER_OF_ALGORITHMS by 1
 * add new algorithm to displayMenu()
 * create a void newAlgorithmSelection() function that calls datasetCreation and then calls NewAlgorithm class
 */


const int NUMBER_OF_ALGORITHMS = 1; //change this when adding a new algorithm
const int NUMBER_OF_ELEMENTS_PER_LINE = 10;

int main() { //performs main loop

	bool quit = false;
	while(!quit) {
		displayMenu();
		quit = handleInput();
	}
	return 0;
}

void displayMenu(){ //displays the main menu
	cout << endl <<
			"___Sorting Algorithm Menu___" << endl <<
			"1. Bubblesort Algorithm" << endl <<

			(NUMBER_OF_ALGORITHMS+1) << ". Exit Program" << endl <<
			"Type selection: ";
}

bool handleInput(){ //handles main menu input
	bool temp_quit = false;
	int input;

	string inputstring;
	getline(cin,inputstring);
	stringstream(inputstring) >> input;
	switch (input){
	case 1:
		bubbleSortSelection();
		break;

	case (NUMBER_OF_ALGORITHMS+1):
		cout << "thanks for using this program!" << endl;
		temp_quit = true;
		break;
	default:
		cout << "you did not select a number on the menu. you selected: " << input << endl;
	}

	return temp_quit;
}

void bubbleSortSelection(){ //performs bubble sort option
	Data* data = dataSetCreation();
	cout << "this hasn't actually been made yet. sorry!" << endl;
	deleteData(data);
}

Data* dataSetCreation() { //handles dataset creation
	int creation_input;
	Data* data;

	dataSetCreationMenu();
	string inputstring;
	getline(cin,inputstring);
	stringstream(inputstring) >> creation_input;

	switch(creation_input){
	case 1: //IMPORTANT REMINDER: uncomment the break after this is implemented
		cout << "sorry, this hasn't been implemented yet, you're being taken to random creation instead" << endl;
		//break;
	case 2:
		data = randomDatasetSelection();

		break;
	default:
		cout << "you did not choose a valid option. an empty set is being created instead." << endl;
		data = new Data;
		data->dataset = NULL;
		data->dataset_size = 0;
	}

	return data;
}

void dataSetCreationMenu(){ //displays menu for creating a dataset
	cout << endl <<
			"Would you like to hand-craft a dataset, or create one randomly?" << endl <<
			"1. hand-craft" << endl <<
			"2. random creation" << endl <<

			"Input selection here: ";

}

Data* randomDatasetSelection(){ //handles creating a random dataset
	Data* data = new Data;
	int dataset_size;
	int*dataset = NULL;
	cout << "please input dataset size (0-1000): ";

	bool invalid_input = false; //input validation
	do {
		string inputstring;
		getline(cin,inputstring);
		stringstream(inputstring) >> dataset_size;

		if(dataset_size > 1000 || dataset_size < 0){
			cout << "sorry, that value is invalid. please input a value between 0 and 1000: ";
			invalid_input = true;
		}
	} while(invalid_input); //end input validation


	dataset = createRandomDataset(dataset_size);


	cout << "Would you like to see the dataset?" << endl <<
			"1. yes" << endl <<
			"2. no" << endl;
	int view_dataset_input;
	invalid_input = false; //input validation
	do {
		string inputstring;
		getline(cin,inputstring);
		stringstream(inputstring) >> view_dataset_input;

		if(view_dataset_input > 2 || view_dataset_input < 1){
			cout << "sorry, that value is invalid. please input either 1 or 2: ";
			invalid_input = true;
		}
	} while(invalid_input); //end input validation
	displayDataset(dataset, dataset_size);

	data->dataset = dataset;
	data->dataset_size = dataset_size;
	return data;
}

int* createRandomDataset(int size) { //creates and populates a dataset with random values

	int* random_dataset = new int[size];

	for(int count = 0; count < size; count++){
		random_dataset[count] = (rand() % 2001) - 1000;
	}

	return random_dataset;
}

void displayDataset(int* dataset, int dataset_size){ //displays a dataset
	if(dataset_size == 0){
		cout << "this dataset is empty." << endl;
	}
	else {
		for(int count = 0; count < dataset_size; count++){
			cout << "[" << dataset[count] << "]" << " ";
			if(count % NUMBER_OF_ELEMENTS_PER_LINE == 0 && count != 0){
				cout << endl;
			}
		}
		cout << endl;
	}
}

void deleteData(Data* data) {//deletes the Data struct
	delete data->dataset;
	delete data;
}
