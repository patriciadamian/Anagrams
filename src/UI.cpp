/*
 * UI.cpp
 *
 *  Created on: Jun 5, 2015
 *      Author: Patri
 */

#include "UI.h"

UI::~UI() {
	// TODO Auto-generated destructor stub
}

void UI::prinMenu() {
	cout << "================================================================="
			<< endl;
	cout << "1 - Find anagrams (Representation 1 - dynamic vector)" << endl;
	cout << "2 - Find anagrams (Representation 2 - hash table with vector)"
			<< endl;
	cout << "0 - Exit" << endl;
	cout << "================================================================="
			<< endl;

}
void UI::run() {
	s->VectorLoad();
	s->HashLoad();
	while (1) {
		this->prinMenu();
		cout << "\nPlease enter the command:\n";
		int cmd;
		cin >> cmd;
		string word;
		switch (cmd) {
		case 0:
			cout << "The program will exit.Bye Bye...:\n";
			exit(0);
			break;

		case 1:
			cout << "Please enter the word:\n";
			cin >> word;
			//u->LoadArray();
			s->FindVector(word);
			break;

		case 2:
			cout << "Please enter the word:\n";
			cin >> word;
			// u->LoadHash();
			s->FindHash(word);
			break;
		}
	}
}

