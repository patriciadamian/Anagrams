/*
 * HashTable.h
 *
 *  Created on: Jun 4, 2015
 *      Author: Patri
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include "Map.h"
#include <string.h>
#include "HashVector.h"

class HashTable : public Map<int,string>{
	friend class HashVector;
private:
	int HashSize;
	HashVector* HashT[50];
public:
	HashTable();


	bool isEmpty();
	/*
	 * Returns the position for the hash vector at that position in Hash table
	 */
	int hashFunction(int key);

	void insert(int k,string e);
	int getSize();
	/*
	 * Finds the position using HashFunction and return a pointer to the hash vector containing the words having that key
	 */
	HashVector* findByK(int key);

	virtual ~HashTable();
};

void test_hash();



#endif /* HASHTABLE_H_ */
