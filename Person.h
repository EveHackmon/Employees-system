// Assignment: 4 Person.h
// Author: Eve Meir Hackmon , ID: 209295914

#ifndef PROJECT_4__EMPLOYEE_DATABASE_PERSON_H
#define PROJECT_4__EMPLOYEE_DATABASE_PERSON_H
#include <iostream>
#include <cstring>

class Person {
private:
    char* Name; // Pointer to store the name of the person
    long ID; // Variable to store the ID of the person
public:
    explicit Person (const char* name = nullptr , long id = 0); //Constructor
    Person(Person &input); // Copy constructor
    virtual ~Person(); // Destructor
    long getID () const ; // Getter method for ID
    virtual void printObject () = 0; // Pure virtual function to print object details

};


#endif //PROJECT_4__EMPLOYEE_DATABASE_PERSON_H
