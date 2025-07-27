// Assignment: 4 CustomerEmployee.cpp
// Author: Eve Meir Hackmon , ID: 209295914

#include "CustomerEmployee.h"
// Initialize the customer employee's name, ID, salary, and payment history
CustomerEmployee::CustomerEmployee(const char* name , long id , float inputSalary) : Person(name , id) , Employee(name , id , inputSalary)  , Customer(name , id) {}
// Copy the customer employee's name, ID, salary, and payment history from the input object
CustomerEmployee::CustomerEmployee(CustomerEmployee &input)  : Person(input), Employee(input), Customer(input) {}
// Destructor: no dynamic memory to deallocate
CustomerEmployee::~CustomerEmployee() {}

void CustomerEmployee::printObject() {
    Employee::printObject(); // Call the base class's printObject() method
    std::cout << " Payment History: ";
    for (int i=0 ; i < getSize() ; i++) { // Print the payment history with dollar signs and separators
        std::cout << getPayList()[i];
        if (i == getSize()-1)
            std::cout << "$ . " << std::endl;
        else
            std::cout << "$ , ";
    }
    std::cout << '\n';
}
// Apply a 10% discount and call the buy() method of the Customer class
void CustomerEmployee::buy (const float &Bill) {
    if (Bill > 0)
        Customer::buy(Bill * EMPLOYEE_DISCOUNT);
}

