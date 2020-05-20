#include "Group.h"
#include <vector>

Group::Group()
{
	studentCount = 0;
	studentArray = {};
}

Group::Group(int student_count, Student* student_array): studentCount(student_count)
{
	set_student_array(student_array, student_count);
}

Group::~Group()
{
	// delete[] studentArray;
}

// Sets

void Group::set_student_count(int student_count)
{
	studentCount = student_count;
}

void Group::set_student_array(Student* student_array, int student_count)
{
	// delete[] studentArray;
	studentArray = new Student[student_count];

	for (int i = 0; i < student_count; i++)
	{
		studentArray[i] = student_array[i];
	}
}

// Gets

int Group::get_student_count() const
{
	return studentCount;
}

Student* Group::get_student_array() const
{
	return studentArray;
}

Student* Group::studentListWithBadMarks(const Student& students)
{
	vector<Student> studentList;

	return studentList;
}

std::ostream& operator<<(std::ostream& os, const Group& obj)
{
	return os
        << "Student count in group: " << obj.studentCount << endl
        << "Max bad mark: " << obj.maxBadMark << endl;
}
