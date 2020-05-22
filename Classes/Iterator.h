#pragma once
#include "Group.h"

class Iterator
{
private:
	Group group;
public:
	int index;
	Iterator(Group group);
	void next();
	void first();
	bool isDone() const;
	Student currentItem() const;
};
