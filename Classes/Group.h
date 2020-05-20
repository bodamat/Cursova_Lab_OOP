#pragma once
#include <ostream>

#include "Student.h"

class Group
{
private:
	int studentCount = 0;
	Student *studentArray;
	int maxBadMark = 3;


	
public:
	Group();
	Group(int student_count, Student* student_array);

	~Group();

	// Sets
	
	void set_student_count(int student_count);
	void set_student_array(Student* student_array, int student_count);

	// Gets
	
	int get_student_count() const;
	Student* get_student_array() const;

	Student* studentListWithBadMarks(const Student &students);

	friend std::ostream& operator<<(std::ostream& os, const Group& obj);
};
