/*
 * Map.h
 *
 *  Created on: Jun 4, 2015
 *      Author: Patri
 */

#ifndef MAP_H_
#define MAP_H_

#include "Pair.h"
template<typename Key,typename Value>

/****************************************************************************************************************\
* Map class
\****************************************************************************************************************/


class Map {
public:
	/*
	 * Default constructor for Map
	 */
	//Map();
	/*
	 * Insert the pair <key, value> into the map
	 */
	virtual void insert(Key k,Value v)=0;
	/*
	 * Gets the size of the map
	 */
	virtual int getSize()=0 ;
	/*
	 * Finds all the pairs having the key k
	 */
	virtual void* findByK(Key k)=0;
	/*
	 * Returns true if the map is empty and false otherwise
	 */
	virtual bool isEmpty()=0;
	/*
	 * Virtual destructor for Map
	*/
	//virtual ~Map();

};


#endif /* MAP_H_ */


