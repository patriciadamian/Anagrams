/*
 * Map.h
 *
 *  Created on: May 24, 2015
 *      Author: Patri
 */

#ifndef PAIR_H_
#define PAIR_H_

#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
using namespace std;

/****************************************************************************************************************\
* Pair class
\****************************************************************************************************************/

template<typename Key, typename Value>
class Pair {
private:
	Key key;
	Value value;
public:
	/*
	 * default constructor
	 */
	Pair();
	/*
	 * explicit constructor
	 */
	Pair(Key k, Value v);
	/*
	 * getters
	*/
	Key getKey();
	Value getValue();
	/*
	 * setters
	*/
	void setKey(Key key);
	void setValue(Value value);
	/*
	 * default destructor
	 */
	~Pair();

};

template<typename Key, typename Value>
Pair<Key, Value>::Pair() {
}

template<typename Key, typename Value>
Pair<Key, Value>::Pair(Key k, Value v) {
	this->key = k;
	this->value = v;
}

template<typename Key, typename Value>
Key Pair<Key, Value>::getKey() {
	return this->key;
}

template<typename Key, typename Value>
Value Pair<Key, Value>::getValue() {
	return this->value;
}

template<typename Key, typename Value>
void Pair<Key, Value>::setKey(Key k) {
	this->key = k;
}

template<typename Key, typename Value>
void Pair<Key, Value>::setValue(Value v) {
	this->value = v;
}

template<typename Key, typename Value>
Pair<Key, Value>::~Pair() {
}

#endif /* PAIR_H_ */
