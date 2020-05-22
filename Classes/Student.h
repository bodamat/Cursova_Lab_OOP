#pragma once
#include "Person.h"

struct STMarkFromLesson // structure for lessons array with lessons name and mark from it
{
	string lesson;
	int mark;
};

class Student : public Person
{
private:
	string VNZ;
	string faculty;
	int course;
	string group;
	string ID;
	int lessonsCount;
	STMarkFromLesson* lessonsMark;

public:
	Student(); // constructor without parameters
	Student(string surname, string name, string fatherName, STBirthday birthday, char sex, string vnz, string faculty,
	        int course, string group, string id, int lessons_count, STMarkFromLesson* lessons_mark);
	// constructor with parameters
	Student(const Person& other, string vnz, string faculty, int course, string group, string id, int lessons_count,
	        STMarkFromLesson* lessons_mark); // constructor with parameters and another person

	~Student(); // destructor

	// All setters

	void set_vnz(string vnz);
	void set_faculty(string faculty);
	void set_course(int course);
	void set_group(string group);
	void set_id(string id);
	void set_lessons_count(int lessons_count);
	void set_lessons_mark(const STMarkFromLesson* lessons_mark, int size);

	// All getters

	STBirthday get_birthday() const override; // Override function and late binding
	string get_vnz() const;
	string get_faculty() const;
	int get_course() const;
	string get_group() const;
	string get_id() const;
	int get_lessons_count() const;
	STMarkFromLesson* get_lessons_mark() const;

	// All operators

	void operator()(const Person& person); // copy data from person
	void operator()(string vnz, string faculty, int course, string group); // Change vnz, faculty, course and group
	void operator()(int lessons_count, STMarkFromLesson* lessons_mark); // change lessons count and lessons array 
	void operator=(const Student& student); // copy data from another student
	friend ostream& operator <<(ostream& out, const Student& student); // display student
	friend istream& operator >>(istream& in, Student& student); // enter data to student
};
