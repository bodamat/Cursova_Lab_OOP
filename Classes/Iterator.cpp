#include "Iterator.h"

Iterator::Iterator(Group group) // constructor
{
	this->group = group;
	index = 0;
}

void Iterator::next() // next index
{
	index++;
}

void Iterator::first() // set to first index
{
	index = 0;
}

bool Iterator::isDone() const // is the last index?
{
	return index == group.get_student_count();
}

Student Iterator::currentItem() const // get current value from array
{
	return group.studentsArray[index];
}
