#include "Iterator.h"

Iterator::Iterator(Group group)
{
	this->group = group;
	index = 0;
}

void Iterator::next()
{
	index++;
}

void Iterator::first()
{
	index = 0;
}

bool Iterator::isDone() const
{
	return index == group.get_student_count();
}

Student Iterator::currentItem() const
{
	return group.studentsArray[index];
}
