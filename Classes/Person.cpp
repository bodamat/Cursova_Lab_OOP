#include "Person.h"

Person::Person()
{
	surname = "Surname";
	name = " Name";
	fatherName = "Father name";
	birthday = {};
	sex = 'm';
}

Person::Person(const Person &other)
{
	this->surname = other.surname;
	this->name = other.name;
	this->fatherName = other.fatherName;
	this->birthday = other.birthday;
	this->sex = other.sex;
}

Person::~Person()
{
	// std::cout << "Person Destructor " << this << endl;
}

// Sets

void Person::set_surname(string surname)
{
	this->surname = surname;
}

void Person::set_name(string name)
{
	this->name = name;
}

void Person::set_father_name(string father_name)
{
	fatherName = father_name;
}

void Person::set_birthday(STBirthday birthday)
{
	this->birthday = birthday;
}

void Person::set_sex(char sex)
{
	this->sex = sex;
}

// Gets

string Person::get_surname() const
{
	return surname;
}

string Person::get_name() const
{
	return name;
}

string Person::get_father_name() const
{
	return fatherName;
}

STBirthday Person::get_birthday() const
{
	return birthday;
}

int Person::get_birthday_day() const
{
	return birthday.day;
}

int Person::get_birthday_month() const
{
	return birthday.month;
}

int Person::get_birthday_year() const
{
	return birthday.year;
}

char Person::get_sex() const
{
	return sex;
}

// Operators

void Person::operator()(string surname, string name, string father_name)
{
	this->surname = surname;
	this->name = name;
	this->fatherName = father_name;
}

void Person::operator()(STBirthday birthday)
{
	this->birthday = birthday;
}

void Person::operator()(char sex)
{
	this->sex = sex;
}

void Person::operator=(const Person& person)
{
	this->surname = person.surname;
	this->name = person.name;
	this->fatherName = person.fatherName;
	this->birthday = person.birthday;
	this->sex = person.sex;
}

ostream& operator << (ostream& out, const Person& person)
{
	out << "Surname: " << person.surname << endl;
	out << "Name: " << person.name << endl;
	out << "Father name: " << person.fatherName << endl;
	out << "Birthday: " << person.get_birthday_day() << " " << person.get_birthday_month() << " " << person.get_birthday_year() << endl;
	out << "Sex: " << person.sex << endl;
	
	return out;
}

istream& operator >> (istream &in, Person &person)
{
	cout << "Enter Surname: "; 
	in >> person.surname;
	
	cout << "Enter Name: "; 
	in >> person.name;
	
	cout << "Enter Father name: "; 
	in >> person.fatherName;
	
	cout << "Enter Birthday day: "; 
	in >> person.birthday.day;
	cout << "Enter Birthday month: "; 
	in >> person.birthday.month;
	cout << "Enter Birthday year: "; 
	in >> person.birthday.year;
	
	cout << "Enter Sex: "; 
	in >> person.sex;
	
	return in;
}

