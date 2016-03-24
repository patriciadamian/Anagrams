/*
 * DynamicVector.h
 *
 *  Created on: May 24, 2015
 *      Author: Patri
 */

#ifndef DYNAMICVECTOR_H_
#define DYNAMICVECTOR_H_

#include <stdlib.h>
#include <iostream>
#include "Pair.h"
#include "Map.h"
#include <string>
using namespace std;

/*
 * Representation 1: dynamic vector
 */


class DynamicVector:public Map<int,string>{
public:
	Pair<int,string>* elems;

	DynamicVector();
	void insert(int key,string value);
	void removeByPos(int pos);
	void updateByPos(int pos, int key, string value);
	int getSize();
	bool isEmpty();
	DynamicVector* findByK(int key);
	DynamicVector& operator = (const DynamicVector &ot);

	virtual ~DynamicVector();

private:
	int capacity ;
	int size;
	void resize(int nrElems);


};

void test_dynVector();




#endif /* DYNAMICVECTOR_H_ */
