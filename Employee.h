// Assignment: 4 Employee.h
// Author: Eve Meir Hackmon , ID: 209295914

#ifndef PROJECT_4__EMPLOYEE_DATABASE_EMPLOYEE_H
#define PROJECT_4__EMPLOYEE_DATABASE_EMPLOYEE_H
#include "Person.h"
#include "Customer.h"
// This class inherits virtual from Person because the Customer class also inherits from Person and the CustomerEmployee class inherits from both
class Employee : virtual public Person {
private:
    float salary; // Variable to store the salary of the employee
public:
    explicit Employee (const char* name = nullptr , long id = 0 , float inputSalary = 0); // Constructor with default arguments
    Employee(Employee &input); // Copy constructor
    virtual ~Employee(); // Destructor
    float getSalary () const; // Getter method for salary
    void setSalary (float newSalary) ; // Setter method for salary
    virtual void printObject(); // Overrides the base class's printObject() method
};


#endif //PROJECT_4__EMPLOYEE_DATABASE_EMPLOYEE_H
