#pragma once
#include "Group.h"

class Iterator
{
private:
	Group group;
public:
	int index; // array index
	
	Iterator(Group group); // constructor
	void next(); // next index
	void first(); // set to first index
	bool isDone() const; // is the last index?
	Student currentItem() const; // get current value from array
};
