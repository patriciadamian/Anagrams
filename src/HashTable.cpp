/*
 * HashTable.cpp
 *
 *  Created on: Jun 4, 2015
 *      Author: Patri
 */

#include "HashTable.h"
#include <assert.h>

//initialize the hash table
HashTable::HashTable() {
	HashSize = 50;
	for (int i = 0; i < this->HashSize - 1; i++) {
		HashT[i] = new HashVector();
	}
}

//add a new element <key,value> in the hash table
void HashTable::insert(int key, string value) {
	int pos = this->hashFunction(key);
	HashT[pos]->add(key, value);
}

int HashTable::getSize() {
	return this->HashSize;
}

HashVector* HashTable::findByK(int k) {
	int index = this->hashFunction(k);
	return HashT[index];
}

bool HashTable::isEmpty() {
	int ok = 0;
	for (int i = 0; i < this->HashSize; i++) {
		int pos = this->hashFunction(i);
		HashVector* v = this->HashT[pos];
		if (v->size != 0) {
			ok = 1;
		}

	}
	if (ok == 0) {
		return true;
	} else {
		return false;
	}
}

/*
 * I found the following algorithm provides a very good statistical distribution.
 * Each input bit affects each output bit with about 50% probability.
 * There are no collisions (each input results in a different output).
 * The algorithm is fast except if the CPU doesn't have a built-in integer multiplication unit.
 * C code, assuming int is 32 bit.
 */
int HashTable::hashFunction(int x) {
	x = ((x >> 16) ^ x) * 0x45d9f3b;
	x = ((x >> 16) ^ x) * 0x45d9f3b;
	x = ((x >> 16) ^ x);
	return x % 50;
}
/*
 * The magic number was calculated using a special multi-threaded test program that ran for many hours,
 * which calculates the avalanche effect (the number of output bits that change if a single input bit is changed;
 *  should be nearly 16 on average), independence of output bit changes (output bits should not depend on each other),
 *  and the probability of a change in each output bit if any input bit is changed.
 *  The calculated values are better than the 32-bit finalizer used by MurmurHash,
 * and nearly as good (not quite) as when using AES.
 */



HashTable::~HashTable() {
	for (int i = 0; i < this->HashSize - 1; i++) {
		delete (HashT[i]);
	}
}

void test_hash(){
	HashTable t;
	HashVector* witk=new HashVector() ;
	t.insert(1,"ndsm");
	t.insert(1,"fsdknf");
	assert(t.isEmpty()==false);
	witk=t.findByK(1);
	assert(witk->getSize()==2);
}

