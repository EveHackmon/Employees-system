// Assignment: 4 CustomerEmployee.h
// Author: Eve Meir Hackmon , ID: 209295914

#ifndef PROJECT_4__EMPLOYEE_DATABASE_CUSTOMEREMPLOYEE_H
#define PROJECT_4__EMPLOYEE_DATABASE_CUSTOMEREMPLOYEE_H
#include "Customer.h"
#include "Employee.h"
#define EMPLOYEE_DISCOUNT 0.9
//This class inherits from the Customer and Employee classes
class CustomerEmployee : public Employee , public Customer {
public:
    explicit CustomerEmployee (const char* name = nullptr , long id = 0 , float inputSalary = 0); // Constructor with default arguments
    CustomerEmployee(CustomerEmployee &input); // Copy constructor
    ~CustomerEmployee(); // Destructor
    virtual void printObject(); // Overrides the base class's printObject() method
    virtual void buy (const float &Bill); // Overrides the base class's buy() method
};


#endif //PROJECT_4__EMPLOYEE_DATABASE_CUSTOMEREMPLOYEE_H
