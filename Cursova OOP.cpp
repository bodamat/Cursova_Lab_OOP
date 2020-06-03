#include <iostream>
#include <iterator>


#include "Classes/Group.h"
#include "Classes/Iterator.h"
#include "Classes/Person.h"
#include "Classes/Student.h"

using namespace std;

void displayPersonBirthday(Person* person) // Function to demonstrate late binding
{
	STBirthday birthday;
	birthday = person->get_birthday();

	cout << birthday.day << endl;
}

int main()
{
	// ----------------------------- Person ------------------------------------------------

	// Initialize Person
	Person person1("Matviiv", "Bohdan", "Romanovych", {14, 9, 2001}, 'm');
	Person person2(person1); // Initialize person with copy constructor
	Person person3;
	Person person4;
	
	person2("Procak", "Roman", "Batkovych"); // Change some data in person with overload operator () in class
	person3 = person2; // move all data from person2 to person3 with overload operator = in class
	person3({5, 5, 2002});

	cout << "Enter Data for person 4: " << endl;
	cin >> person4; // Enter data in person with overload operator >> in class
	cout << endl;

	cout << "Person 4:" << endl;
	cout << person4 << endl; // Display person with overload operator << in class

	// ----------------------------- Student ------------------------------------------------

	STMarkFromLesson* lessonsmarks = new STMarkFromLesson[2]; // Array with marks for student1
	lessonsmarks[0].lesson = "mathematics"; // add values to each element in structure
	lessonsmarks[0].mark = 3;
	lessonsmarks[1].lesson = "OOP";
	lessonsmarks[1].mark = 5;

	STMarkFromLesson* lessonsmarks2 = new STMarkFromLesson[1]; // Array with marks for student2
	lessonsmarks2[0] = {"mathematics", 5}; // Add values to structure with operators {}

	Student* studentArray = new Student[2]; // Array with students
	studentArray[0] = Student(person1, "College", "PZ", 3, "33-PZ", "25647856", 2, lessonsmarks);
	// initialize student1 with constructor
	studentArray[1] = Student(person3, "College", "PZ", 3, "33-PZ", "25647856", 1, lessonsmarks2);

	// Demonstrate late binding
	cout << "Demonstrate late binding:" << endl;
	cout << "Birthday day from person: ";
	displayPersonBirthday(&person1); // Get Person birthday
	cout << "Birthday day from student: ";
	displayPersonBirthday(&studentArray[1]); // Get Student birthday
	cout << endl;

	// ----------------------------- Group ------------------------------------------------

	Group group("33-PZ", 2, studentArray); // initialize group with constructor

	Student* badStudents; // array with students, who have bad marks
	badStudents = group.getStudentListWithBadMarks(); // get students, who have bad marks from group 

	cout << "All student, who have bad marks: " << endl;
	for (int i = 0; i < group.get_bad_students_count(); i++) // Display all students, who have bad marks
	{
		cout << "Student " << i + 1 << ": " << endl;
		cout << badStudents[i] << endl;
	}

	// ----------------------------- Iterator ------------------------------------------------

	Iterator iterator(group); // Create iterator and add group to it

	cout << "All student what displayed with iterator: " << endl;
	while (!iterator.isDone()) // Display all students in group from iterator
	{
		cout << "Student " << iterator.index + 1 << ": " << endl;
		cout << iterator.currentItem() << endl;
		iterator.next();
	}

	// Delete all dynamic arrays
	delete[] lessonsmarks;
	delete[] lessonsmarks2;
	delete[] studentArray;

	// ----------------------------- End All Program ------------------------------------------------

	return 0;
}
