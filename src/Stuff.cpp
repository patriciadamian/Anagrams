/*
 * Stuff.cpp
 *
 *  Created on: Jun 5, 2015
 *      Author: Patri
 */

#include "Stuff.h"
#include "DynamicVector.h"
#include <iostream>
#include <algorithm>
#include <string.h>
#include <fstream>
#include <vector>
#include <cstring>
#include <stdlib.h>

void Stuff::VectorLoad() {
	ifstream in(this->filename.c_str());
	char line[30];
	char* p;
	while (in.getline(line, 30)) {
		p = strtok(line, " ");
		string w(p);
		int key = w.length();
		dyn_vect->insert(key, w);
	}
	in.close();
}

void Stuff::HashLoad() {
	ifstream in(this->filename.c_str());
	char line[30];
	char* p;
	while (in.getline(line, 30)) {
		p = strtok(line, " ");
		string w(p);
		int key = w.length();
		hash_t->insert(key, w);
	}
	in.close();
}

int Stuff::getNoWords() {
	return dyn_vect->getSize();
}
void Stuff::FindVector(string word) {
	int key = word.length();
	int ok = 0;
	string mywordS = sortedWord(word);
	DynamicVector* sameK = new DynamicVector();
	sameK = dyn_vect->findByK(key);
	if (sameK->getSize() == 0) {
		ok = 1;
	} else {
		ok = 0;
		cout
				<< "-----------------------------------------------------------------"
				<< endl;
		cout << "Anagrams are :\n";
		for (int i = 0; i < sameK->getSize(); i++) {
			Pair<int, string> p;
			p = sameK->elems[i];
			string dictWord = p.getValue();
			string dictWordS = sortedWord(dictWord);
			if (dictWordS.compare(mywordS) == 0) {
				if (word.compare(dictWord) != 0) {
					cout << dictWord;
					cout << "\n";
					ok = 1;
				}
			}
		}
		if (ok == 0) {
			cout << "There are no anagrams.\n";
		}
	}

	cout << "-----------------------------------------------------------------"
			<< endl;
}

void Stuff::FindHash(string word) {
	int ok = 0;
	int key = word.length();
	string mywordS = sortedWord(word);
	HashVector* sameK = new HashVector();
	sameK = this->hash_t->findByK(key);
	cout << "-----------------------------------------------------------------"
			<< endl;
	cout << "Anagrams are:\n";
	for (int i = 0; i < sameK->getSize(); i++) {
		Pair<int, string> p;
		p = sameK->getPos(i);
		string dictWord = p.getValue();
		string dictWordS = sortedWord(dictWord);
		if (dictWordS.compare(mywordS) == 0) {
			if (word.compare(dictWord) != 0) {
				cout << dictWord;
				cout << "\n";
				ok = 1;
			}
		}
	}
	if (ok == 0) {
		cout << "There are no anagrams.\n";
	}
	cout << "-----------------------------------------------------------------"
			<< endl;
}

string sortedWord(string word) {
	string ot_word;
	ot_word = word;
	sort(ot_word.begin(), ot_word.end()); //sort alphabetically
	return ot_word;
}

void test_stuff() {
	Stuff* s = new Stuff("testdata");
	s->VectorLoad();
	//assert(s->getNoWords()==6);
	delete s;
}
