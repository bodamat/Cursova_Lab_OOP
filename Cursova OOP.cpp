#include <iostream>

#include "Classes/Group.h"
#include "Classes/Person.h"
#include "Classes/Student.h"

using namespace std;

int main()
{
    Person person1("Matviiv", "Bohdan", "Romanovych", {14, 9, 2001}, 'm');
    
    STMarkFromLesson *lessonsmarks = new STMarkFromLesson[2];
    lessonsmarks[0].lesson = "mathematics";
    lessonsmarks[1].lesson = "OOP";
    lessonsmarks[0].mark = lessonsmarks[1].mark = 5;

    Student *studentArray = new Student[2];
    studentArray[0] = Student(person1, "College", "PZ", 3, "33-PZ", "25647856", 2, lessonsmarks);
    studentArray[1] = Student(person1, "College", "PZ", 3, "33-PZ", "25647856", 2, lessonsmarks);

    delete[] lessonsmarks;

    Group group(2, studentArray);

    delete[] studentArray;

    cout << group << endl;
    
    return 0;
}
