#pragma once
#include <ostream>

#include "Student.h"

class Group
{
private:
	string name = "";
	int studentsCount = 0;
	int maxBadMark = 3;
	int badStudentsCount = 0;

public:
	Student* studentsArray; // array with objects Student
	
	Group(); // constructor without parameters
	Group(string name, int student_count, Student* student_array); // constructor with parameters

	~Group(); // destructor

	// All setters

	void set_student_count(int student_count);
	void set_student_array(Student* student_array, int student_count);

	// All getters

	string get_name() const;
	int get_student_count() const;
	Student* get_student_array() const;
	int get_bad_students_count() const;

	// Get all students, who have bad marks
	Student* getStudentListWithBadMarks(); 

	// display group
	friend std::ostream& operator<<(std::ostream& os, const Group& group);
};
