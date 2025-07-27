// Assignment: 4 Customer.h
// Author: Eve Meir Hackmon , ID: 209295914

#ifndef PROJECT_4__EMPLOYEE_DATABASE_CUSTOMER_H
#define PROJECT_4__EMPLOYEE_DATABASE_CUSTOMER_H
#include "Person.h"

class Customer : virtual public Person {
private:
float* PayList; // Pointer to an array to store payment history
int Size; // Size of the payment history array
public:
    Customer (const char* name = nullptr , long id = 0 ); // Constructor with default arguments
    Customer (Customer &input); // Copy constructor
    virtual ~Customer(); // Destructor
    float* getPayList () const; // Getter method for payment history
    int getSize () const; // Getter method for size of payment history
    virtual void printObject() ; // Overrides the base class's printObject() method
    virtual void buy (const float &Bill); // Method to update payment history
};



#endif //PROJECT_4__EMPLOYEE_DATABASE_CUSTOMER_H
