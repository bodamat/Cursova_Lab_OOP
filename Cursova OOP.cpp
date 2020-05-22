#include <iostream>

#include "Classes/Group.h"
#include "Classes/Iterator.h"
#include "Classes/Person.h"
#include "Classes/Student.h"

using namespace std;

int main()
{
    Person person1("Matviiv", "Bohdan", "Romanovych", {14, 9, 2001}, 'm');
    
    
    STMarkFromLesson *lessonsmarks = new STMarkFromLesson[2];
    lessonsmarks[0].lesson = "mathematics";
    lessonsmarks[1].lesson = "OOP";
    lessonsmarks[0].mark = 3;
    lessonsmarks[1].mark = 5;

    STMarkFromLesson *lessonsmarks2 = new STMarkFromLesson[1];
    lessonsmarks2[0] = {"mathematics", 3};

    Student *studentArray = new Student[2];
    studentArray[0] = Student(person1, "College", "PZ", 3, "33-PZ", "25647856", 2, lessonsmarks);
    studentArray[1] = Student(person1, "College", "PZ", 3, "33-PZ", "25647856", 1, lessonsmarks2);

    Group group("33-PZ", 2, studentArray);
    
    delete[] lessonsmarks;
    delete[] lessonsmarks2;
    delete[] studentArray;
    
    Student *badStudents;
    badStudents = group.getStudentListWithBadMarks();
    
    for (int i = 0; i < group.get_bad_students_count(); i++)
    {
        cout << badStudents[i] << endl;
    }
    
    Iterator iterator(group);
    
    while (!iterator.isDone())
    {
        cout << iterator.currentItem() << endl;
        iterator.next();
    }
    
    return 0;
}
