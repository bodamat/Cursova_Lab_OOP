#include <string>
#include <iostream>

using namespace std;

struct STBirthday {
	int day;
	int month;
	int year;
};

#pragma once
class Person
{

private:
	string surname;
	string name;
	string fatherName;
	char sex;

protected:
	STBirthday birthday;
	
public:

	Person();
	Person(string surname, string name, string father_name, STBirthday birthday, char sex)
		: surname(surname),
		  name(name),
		  fatherName(father_name),
		  birthday(birthday),
		  sex(sex)
	{
	}

	Person(const Person &other);
	virtual ~Person();

	// Sets

	void set_surname(string surname);
	void set_name(string name);
	void set_father_name(string father_name);
	void set_birthday(STBirthday birthday);
	void set_sex(char sex);
	
	// Gets

	string get_surname() const;
	string get_name() const;
	string get_father_name() const;
	virtual STBirthday get_birthday() const; // Virtual і пізнє зв'язування
	int get_birthday_day() const;
	int get_birthday_month() const;
	int get_birthday_year() const;
	char get_sex() const;

	// Operators

	void operator()(string surname, string name, string father_name);
	void operator()(STBirthday birthday);
	void operator()(char sex);
	void operator = (const Person &person);
	friend ostream& operator << (ostream &out, const Person& person);
	friend istream& operator >> (istream &in, Person &person);
	
};

