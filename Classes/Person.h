#pragma once
#include <iostream>

using namespace std;

struct STBirthday { // Structure of person birthday
	int day;
	int month;
	int year;
};

class Person
{

private:
	string surname;
	string name;
	string fatherName;
	char sex;

protected: // editable in inherited classes
	STBirthday birthday;
	
public:

	Person(); // constructor without parameters
	Person(string surname, string name, string father_name, STBirthday birthday, char sex) // constructor with parameters
		: surname(surname),
		  name(name),
		  fatherName(father_name),
		  birthday(birthday),
		  sex(sex)
	{
	}

	Person(const Person &other); //copy constructor
	virtual ~Person(); // destructor

	// All setters

	void set_surname(string surname);
	void set_name(string name);
	void set_father_name(string father_name);
	void set_birthday(STBirthday birthday);
	void set_sex(char sex);
	
	// All getters

	string get_surname() const;
	string get_name() const;
	string get_father_name() const;
	virtual STBirthday get_birthday() const; // Virtual function and late binding
	int get_birthday_day() const;
	int get_birthday_month() const;
	int get_birthday_year() const;
	char get_sex() const;

	// All overload operators

	void operator()(string surname, string name, string father_name); // operator for change surname, name and father name
	void operator()(STBirthday birthday); // operator for change birthday
	void operator()(char sex); // operator for change sex
	void operator = (const Person &person); // operator for copy data from another person
	friend ostream& operator << (ostream &out, const Person& person); // operator for display person
	friend istream& operator >> (istream &in, Person &person); // operator for enter data to person
	
};

