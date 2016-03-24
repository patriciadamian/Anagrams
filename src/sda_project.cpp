//============================================================================
// Name        : sda_project.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <vector>
#include "DynamicVector.h"
#include "Map.h"
#include "Stuff.h"
#include "UI.h"
#include "HashTable.h"

int main() {
	//test_dynVector();
	//test_hash();
	//test_stuff();
	Stuff* s = new Stuff("words");
	UI* u = new UI(s);
	u->run();
	return 0;
}
