/*
 * Stuff.h
 *
 *  Created on: Jun 5, 2015
 *      Author: Patri
 */

#ifndef STUFF_H_
#define STUFF_H_

#include "DynamicVector.h"
#include "HashTable.h"
#include <string>
#include <fstream>
#include <cstring>
#include <stdlib.h>
//using namespace std;

/*
 * Stuff containts 2 different ways of loading data corresponding to the vector (VectorLoad),
 * respectively hash table with vector(HashLoad) representations
 */
class Stuff {
private:
	string filename;
	DynamicVector* dyn_vect;
	HashTable* hash_t;
public:
	/*
	 * The ideea is that the key for every word is actually it's length.
	 * The program will sort the letters alphabetically of all the words having the length equal to the length of the given word
	 * and compare the results.
	 */
	Stuff(string file_Name) {
		this->filename = file_Name;
		dyn_vect = new DynamicVector();
		hash_t = new HashTable();
		}

	//Loads the words in a dynamic vector
	void VectorLoad();
	//Loads the words in a Hash Table
	void HashLoad();
	//Returns the number of the words
	int getNoWords();

	void FindVector(string word);

	void FindHash(string word);


	virtual ~Stuff() {
		delete hash_t;
		delete dyn_vect;
	}
};

string sortedWord(string word);

void test_stuff();

#endif /* STUFF_H_ */
