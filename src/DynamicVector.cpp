/*
 * DynamicVector.cpp
 *
 *  Created on: Jun 4, 2015
 *      Author: Patri
 */

#include "DynamicVector.h"
#include <assert.h>
#include <string.h>
#include "Map.h"

DynamicVector::DynamicVector() {

	capacity = 1000;
	elems = new Pair<int, string> [capacity];
	size = 0;

}

void DynamicVector::insert(int key, string value) {
    //Inserts an element in the vector on the last position
	resize(size + 1);
	Pair<int, string> p(key, value);
	elems[size] = p;
	size++;
}

void DynamicVector::removeByPos(int pos){
	int i = 0;
	for (i = pos; i < size; i++){
		elems[i] = elems[i+1];
	}
	size--;

}

void DynamicVector::updateByPos(int pos, int key, string value){
//	if (pos < size ){
//		elems[pos].getKey() = key;
//		elems[pos].getValue() = value;
//	}else{}
}

int DynamicVector::getSize() {
	return size;
}

bool DynamicVector::isEmpty() {
	if (size == 0) {
		return true;
	} else {
		return false;
	}
}

DynamicVector* DynamicVector::findByK(int key) {
	DynamicVector* sameK = new DynamicVector();		//Find elements with the same key (the key is actually the length of the word)
	for (int i = 0; i < this->getSize(); i++) {
		Pair<int, string> p;
		p = elems[i];
		if (p.getKey() == key) {
			sameK->insert(p.getKey(), p.getValue());
		}
	}
	return sameK;
}

DynamicVector& DynamicVector::operator =(const DynamicVector &ot) {
	if (this == &ot) {
		return *this;
	}
											//Free the memory
	delete this->elems;

	this->elems = new Pair<int, string> [ot.capacity];
	for (int i = 0; i < ot.size; i++) {
		this->elems[i] = ot.elems[i];
	}
	this->capacity = ot.capacity;
	this->size = ot.size;
	return *this;
}

void DynamicVector::resize(int nrElems) {
	if (capacity >= nrElems) {
		return; 							//There is enough space to store the elements
	}
											//Need more space for the elements
	Pair<int, string> *aux = elems;
											//Create space for more elements
	capacity = capacity * 2;
	elems = new Pair<int, string> [capacity];
											//Copy the elements
	for (int i = 0; i < size; i++) {
		elems[i] = aux[i];
	}
											//Free the memory
	delete[] aux;
}

DynamicVector::~DynamicVector() {
	delete[] elems;
}

void test_dynVector(){
	DynamicVector v;
	assert(v.getSize()==0);
	assert(v.isEmpty()==true);
	v.insert(1,"car");
	assert(v.isEmpty()==false);
	assert(v.getSize()==1);
	DynamicVector* withk= new DynamicVector();
	v.insert(2,"rac");
	v.insert(2,"car");
	withk=v.findByK(2);
	assert(withk->getSize()==2);
	delete withk;
}
