/*
 * DynVectMap.h
 *
 *  Created on: Jun 4, 2015
 *      Author: Patri
 */

#ifndef HASHVECTOR_H_
#define HASHVECTOR_H_

#include "Pair.h"
/*
 * Representation 2: hashtable, collision resolution through chaining with vector
 */

class HashVector {
	friend class HashTable;
private:
	int capacity;
	int size;
	Pair<int, string>* pairs;
public:
	HashVector& operator =(const HashVector &ot) {
		if (this == &ot) {
			return *this;
		}
		delete this->pairs;

		this->pairs = new Pair<int, string> [ot.capacity];
		for (int i = 0; i < ot.size; i++) {
			this->pairs[i] = ot.pairs[i];
		}
		this->capacity = ot.capacity;
		this->size = ot.size;
		return *this;
	}

	void resizeH(int nrPairs) {
		if (capacity >= nrPairs) {
			return; //There is enough space to store the elements
		}
		//Is needed more space for the elements
		Pair<int, string> *temp = pairs;
		//double the space
		capacity = capacity * 2;
		pairs = new Pair<int, string> [capacity];
		//copy the elems
		for (int i = 0; i < size; i++) {
			pairs[i] = temp[i];
		}
		//free the memory
		delete[] temp;
	}

	HashVector() {
		capacity = 50;
		pairs = new Pair<int, string> [capacity];
		size = 0;
	}

	void add(int key, string value) {
		this->resizeH(size + 1);
		Pair<int, string> p(key, value);
		pairs[size] = p;
		size++;
	}

	int getSize() {
		return size;
	}

	Pair<int, string> getPos(int pos) {
		return pairs[pos];
	}

	virtual ~HashVector() {
		delete[] pairs;
	}

};

#endif /* DYNVECTMAP_H_ */
