#pragma once
#include "Group.h"

class Iterator
{
	Group group;
	int index;
public:
	Iterator(Group group);
	void next();
	void first();
	bool isDone() const;
	Student currentItem() const;
};
