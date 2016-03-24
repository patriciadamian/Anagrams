/*
 * UI.h
 *
 *  Created on: Jun 5, 2015
 *      Author: Patri
 */

#ifndef UI_H_
#define UI_H_

#include "Stuff.h"
class UI {
private:
	Stuff* s;
public:
	UI(Stuff* stuff) {
		this->s = stuff;
	}
	void prinMenu();
	void run();

	virtual ~UI();
};

#endif /* UI_H_ */
