﻿#include "Group.h"
// #include <vector>

// ------------------------------------ Constructors and Destructor --------------------------------------

Group::Group() // constructor without parameters
{
	name = "Group name";
	studentsArray = {};
}

Group::Group(string name, int student_count, Student* student_array): name(name), studentsCount(student_count)
// constructor with parameters
{
	set_student_array(student_array, student_count);
}

Group::~Group() // destructor
{
	// delete[] studentArray;
}

// ------------------------------------ All setters ---------------------------------------------------

void Group::set_student_count(int student_count)
{
	studentsCount = student_count;
}

void Group::set_student_array(Student* student_array, int student_count)
{
	// delete[] studentArray;
	studentsArray = new Student[student_count];

	for (int i = 0; i < student_count; i++)
	{
		studentsArray[i] = student_array[i];
	}
}

// ------------------------------------- All getters --------------------------------------------------

string Group::get_name() const
{
	return name;
}

int Group::get_student_count() const
{
	return studentsCount;
}

Student* Group::get_student_array() const
{
	return studentsArray;
}

int Group::get_bad_students_count() const
{
	return badStudentsCount;
}

// ----------------------------- Get all students, who have bad marks ------------------------------------------
Student* Group::getStudentListWithBadMarks()
{
	// vector<Student> studentsList;
	Student* studentsList = new Student[studentsCount];
	badStudentsCount = 0;

	for (int i = 0; i < studentsCount; i++)
	{
		for (int j = 0; j < studentsArray[i].get_lessons_count(); j++)
		{
			if (studentsArray[i].get_lessons_mark()[j].mark <= maxBadMark)
			{
				// studentsList.push_back(studentsArray[i]);
				studentsList[badStudentsCount] = studentsArray[i];
				badStudentsCount++;
				break;
			}
		}
	}

	if (badStudentsCount > 0)
	{
		// return &studentsList[0];
		return studentsList;
	}

	return {};
}

// ------------------------------------- Display group ----------------------------------------------
std::ostream& operator<<(std::ostream& os, const Group& group)
{
	return os
		<< "Group name: " << group.name << endl
		<< "Student count in group: " << group.studentsCount << endl
		<< "Max bad mark: " << group.maxBadMark << endl;
}
