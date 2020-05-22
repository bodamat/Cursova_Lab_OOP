#include "Student.h"

// --------------------- Constructors and Destructor -------------------------

Student::Student() // constructor without parameters
{
	VNZ = "VNZ";
	faculty = "Faculty";
	group = "Group";
	ID = "ID";
	course = 0;
	lessonsCount = 0;
	lessonsMark = {};
}

Student::Student(string surname, string name, string fatherName, STBirthday birthday, char sex, string vnz,
                 string faculty, int course, string group, string id, int lessons_count,
                 STMarkFromLesson* lessons_mark) : Person(surname, name, fatherName, birthday, sex) // constructor with parameters
{
	set_vnz(vnz);
	set_faculty(faculty);
	set_course(course);
	set_group(group);
	set_id(id);
	set_lessons_count(lessons_count);

	set_lessons_mark(lessons_mark, lessons_count);
}

Student::Student(const Person& other, string vnz, string faculty, int course, string group, string id,
                 int lessons_count, STMarkFromLesson* lessons_mark): Person(other) // constructor with parameters and another person
{
	set_vnz(vnz);
	set_faculty(faculty);
	set_course(course);
	set_group(group);
	set_id(id);
	set_lessons_count(lessons_count);

	set_lessons_mark(lessons_mark, lessons_count);
}

Student::~Student() // destructor
{
	delete[] this->lessonsMark;
}

// ------------------------------------ All setters -------------------------------------------

void Student::set_vnz(string vnz)
{
	VNZ = vnz;
}

void Student::set_faculty(string faculty)
{
	this->faculty = faculty;
}

void Student::set_course(int course)
{
	this->course = course;
}

void Student::set_group(string group)
{
	this->group = group;
}

void Student::set_id(string id)
{
	ID = id;
}

void Student::set_lessons_count(int lessons_count)
{
	lessonsCount = lessons_count;
}

void Student::set_lessons_mark(const STMarkFromLesson* lessons_mark, int size)
{
	// delete[] lessonsMark;

	lessonsMark = new STMarkFromLesson[size];

	for (int i = 0; i < size; i++)
	{
		lessonsMark[i].lesson = lessons_mark[i].lesson;
		lessonsMark[i].mark = lessons_mark[i].mark;
	}
}

// ------------------------------------- All getters --------------------------------------------------

STBirthday Student::get_birthday() const
{
	return this->birthday;
}

string Student::get_vnz() const
{
	return VNZ;
}

string Student::get_faculty() const
{
	return faculty;
}

int Student::get_course() const
{
	return course;
}

string Student::get_group() const
{
	return group;
}

string Student::get_id() const
{
	return ID;
}

int Student::get_lessons_count() const
{
	return lessonsCount;
}

STMarkFromLesson* Student::get_lessons_mark() const
{
	return lessonsMark;
}

// ----------------------------------------- All overload operators -----------------------------------------

void Student::operator()(const Person& person) // copy data from person
{
	this->set_surname(person.get_surname());
	this->set_name(person.get_name());
	this->set_father_name(person.get_father_name());
	this->set_birthday(person.get_birthday());
	this->set_sex(person.get_sex());
}

void Student::operator()(string vnz, string faculty, int course, string group) // Change vnz, faculty, course and group
{
	set_vnz(vnz);
	set_faculty(faculty);
	set_course(course);
	set_group(group);
}

void Student::operator()(int lessons_count, STMarkFromLesson* lessons_mark) // change lessons count and lessons array 
{
	set_lessons_count(lessons_count);

	set_lessons_mark(lessons_mark, lessons_count);
}

void Student::operator=(const Student& student) // copy data from another student
{
	this->set_surname(student.get_surname());
	this->set_name(student.get_name());
	this->set_father_name(student.get_father_name());
	this->set_birthday(student.get_birthday());
	this->set_sex(student.get_sex());
	set_vnz(student.VNZ);
	set_faculty(student.faculty);
	set_course(student.course);
	set_group(student.group);
	set_id(student.ID);
	set_lessons_count(student.lessonsCount);
	set_lessons_mark(student.lessonsMark, student.lessonsCount);
}

ostream& operator<<(ostream& out, const Student& student) // display student
{
	Person* person = new Person;
	person->set_surname(student.get_surname());
	person->set_name(student.get_name());
	person->set_father_name(student.get_father_name());
	person->set_birthday(student.get_birthday());
	person->set_sex(student.get_sex());

	out << "ID: " << student.ID << endl;
	out << *person;

	out << "VNZ: " << student.VNZ << endl;
	out << "Faculty: " << student.faculty << endl;
	out << "Course: " << student.course << endl;
	out << "Group: " << student.group << endl;

	out << "Marks from lessons: " << endl;
	for (int i = 0; i < student.lessonsCount; i++)
	{
		out << student.lessonsMark[i].lesson << " - " << student.lessonsMark[i].mark << endl;
	}

	delete person;

	return out;
}

istream& operator>>(istream& in, Student& student) // enter data to student
{
	Person* person = new Person;

	cout << "Enter Student ID: ";
	in >> student.ID;

	in >> *person;
	student(*person);

	cout << "Enter VNZ: ";
	in >> student.VNZ;

	cout << "Enter Faculty: ";
	in >> student.faculty;

	cout << "Enter Course: ";
	in >> student.course;

	cout << "Enter Group: ";
	in >> student.group;

	cout << "Enter Lessons count: ";
	in >> student.lessonsCount;

	delete[] student.lessonsMark;
	student.lessonsMark = new STMarkFromLesson[student.lessonsCount];

	for (int i = 0; i < student.lessonsCount; i++)
	{
		cout << "Lesson " << i + 1 << ": " << endl;
		cout << "Enter Lesson name: ";
		in >> student.lessonsMark[i].lesson;
		cout << "Enter Lesson mark: ";
		in >> student.lessonsMark[i].mark;
	}

	delete person;

	return in;
}
