/*
 * functionstocomplete.cpp
 *
 *  Created on: Sep 10, 2017
 *      Author: James Baron
 */

//============================================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "array_functions.h"
//============================================================================
using namespace std;
//============================================================================
//	stuff you will need
//============================================================================
//TODO define a structure to track words and number of times they occur
struct data{
	string word;
	int counter;
	void reset(){
		word = "";
		counter = 0;
	}
};
//TODO add a global array of entry structs (global to this file)
data storage[100];
//TODO add variable to keep track of next available slot in array
int storageIterator = 0;
int size = 0;
//TODO define all functions in header file
void clearArray(){
	for(int i = 0;i<size;i++){
		storage[i].reset();
			}
	storageIterator = 0;
	size = 0;
}

int getArraySize(){
return size;
}

std::string getArrayWordAt(int i){
return storage[i].word;
}

int getArrayWord_NumbOccur_At(int i){
return storage[i].counter;
}

bool processFile(std::fstream &myfstream){
	if(!myfstream.is_open()){
		return false;
	}
	std::string myString;
	while(!myfstream.eof()){
	getline(myfstream,myString);
	processLine(myString);

	}
return true;
}

void processLine(std::string &myString){
	string token;
	stringstream ss(myString);
	while(getline(ss, token, ' ')){

		processToken(token);

	}
}

void processToken(std::string &token){
	bool flag = false;
	if(!(token == " "|| token.size() == 0)){
	for(int i = 0;i<token.size();i++){
		//int uppercaseChar = toupper(token[i]);
		int uppercaseChar = (token[i]);
				if (uppercaseChar < (int)'a'|| uppercaseChar > (int)'z') {

					flag = true;
					break;
				}


	}
if(!flag){
	if(size == 0){
		storage[0].word= token;
		storage[0].counter= 1;
		size++;
		storageIterator++;
	}else{
		for(int i = 0;i<size;i++){
			if(token == storage[i].word){
				storage[i].counter++;
				flag = true;
				break;
			}
		}
		if(!flag){
		storage[size].word = token;
		storage[size].counter++;
		size++;
		storageIterator++;
		}
	}
}
	}
}


bool openFile(std::fstream& myfile, const std::string& myFileName,
		std::ios_base::openmode mode /*= std::ios_base::in*/){
try{
	myfile.open(myFileName,mode);
}
catch(exception& e){
	return false;
}
return true;
}

void closeFile(std::fstream& myfile){
myfile.close();
}

int writeArraytoFile(const std::string &outputfilename){
return 0;
}

void sortArray(constants::sortOrder so){

}
//TODO look in utilities.h for useful functions, particularly strip_unwanted_chars!

