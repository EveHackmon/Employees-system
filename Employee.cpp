// Assignment: 4 Employee.cpp
// Author: Eve Meir Hackmon , ID: 209295914

#include "Employee.h"

Employee::Employee(const char* name , long id , float inputSalary) : Person(name , id) , salary(inputSalary) {}// Initialize the employee's name, ID, and salary

Employee::Employee(Employee &input) : Person(input) , salary(input.salary) {} // Copy the employee's name, ID, and salary from the input object

Employee::~Employee() {}  // Destructor: no dynamic memory to deallocate

float Employee::getSalary () const {
    return salary;
} // Return the salary of the employee

void Employee::setSalary (float newSalary)  { // Update the salary only if the new salary is positive
    if (newSalary > 0)
        salary = newSalary;
} // Update the salary only if the new salary is positive

void Employee::printObject() {
    Person::printObject(); // Call the base class's printObject() method
    std::cout << " Salary: " << salary << "$ " << std::endl;

} //print the object details
