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
#include "constants.h"
#include "array_functions.h"
#include "utilities.h"

//============================================================================
using namespace std;
using namespace constants;
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
data storage[1000];
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
	if(myString == ""){
		return false;
	}
	processLine(myString);

	}
return true;
}
void strip_unwanted_chars();
void processLine(std::string &myString){
	string token;
	stringstream ss(myString);
	while(getline(ss, token, ' ')){
		strip_unwanted_chars(token);
		processToken(token);

	}
}

void processToken(std::string &token){
	bool flag = false;
	if(!(token == " "|| token.size() == 0)){
		//strip_unwanted_chars();
	for(int i = 0;i<token.size();i++){
		token[i] = (int)tolower(token[i]);
						if (token[i] < (int)'a'|| token[i] > (int)'z') {
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


bool openFile(fstream& myfile, const std::string& myFileName,
		std::ios_base::openmode mode){
try{
	myfile.open(myFileName.c_str(),mode);
	if(myfile.fail()){
		return false;
	}
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
	ofstream myfile;
	myfile.open(outputfilename.c_str());
	//bool worked = false;
	if(!myfile.is_open()){
		return FAIL_FILE_DID_NOT_OPEN;
	}
	if(size == 0){
		return FAIL_NO_ARRAY_DATA;
	}
	for(int i = 0;i<size;i++){
		/*myfile<<storage[i].word<< " ";
		myfile<<storage[i].counter<<endl;*/
		//worked = true;
		myfile<<storage[i].word + " " + intToString(storage[i].counter) + "/n";
	}

return SUCCESS;
}
void swap(int left, int right){
	data tmp;
	tmp = storage[left];
	storage[left] = storage[right];
	storage[right] = tmp;

}
void sortArray(constants::sortOrder so){
bool swapped = true;
while(swapped){
	swapped = false;
	for(int i = 0;i<size-1;i++){
		if(storage[i].word> storage[i+1].word){
			swap(i,i+1);
			swapped = true;
		}
	}
}
}
//TODO look in utilities.h for useful functions, particularly strip_unwanted_chars!

