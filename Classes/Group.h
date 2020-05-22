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
	Student *studentsArray;
	Group();
	Group(string name, int student_count, Student* student_array);

	~Group();

	// Sets
	
	void set_student_count(int student_count);
	void set_student_array(Student* student_array, int student_count);

	// Gets

	string get_name() const;
	int get_student_count() const;
	Student* get_student_array() const;
	int get_bad_students_count() const;

	Student* getStudentListWithBadMarks();

	friend std::ostream& operator<<(std::ostream& os, const Group& group);
};
