#pragma once
#include "Person.h"

struct STMarkFromLesson
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
	STMarkFromLesson *lessonsMark;

public:
	Student();
	Student(string surname, string name, string fatherName, STBirthday birthday, char sex, string vnz, string faculty,
	        int course, string group, string id, int lessons_count, STMarkFromLesson* lessons_mark);
	Student(const Person& other, string vnz, string faculty, int course, string group, string id, int lessons_count,
	        STMarkFromLesson* lessons_mark);

	~Student();
	
	// Sets

	void set_vnz(string vnz);
	void set_faculty(string faculty);
	void set_course(int course);
	void set_group(string group);
	void set_id(string id);
	void set_lessons_count(int lessons_count);
	void set_lessons_mark(const STMarkFromLesson *lessons_mark, int size);
	
	// Gets

	STBirthday get_birthday() const override; // Override функції і пізнє зв'язування
	string get_vnz() const;
	string get_faculty() const;
	int get_course() const;
	string get_group() const;
	virtual string get_id() const;
	int get_lessons_count() const;
	STMarkFromLesson* get_lessons_mark() const;

	// Operators

	void operator()(const Person &person);
	void operator()(string vnz, string faculty, int course, string group);
	void operator()(int lessons_count, STMarkFromLesson *lessons_mark);
	void operator=(const Student &student);
	friend ostream& operator << (ostream &out, const Student &student);
	friend istream& operator >> (istream &in, Student &student);
};
