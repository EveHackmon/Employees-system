// Assignment: 4 Customer.cpp
// Author: Eve Meir Hackmon , ID: 209295914

#include "Customer.h"
// Initialize the customer's name, ID, payment history, and size
Customer::Customer (const char* name , long id ) : Person(name , id) , PayList(nullptr) , Size(0) {}

Customer::Customer (Customer &input) : Person(input)  {
    Size = input.Size; // Copy the size of the payment history from the input object
    PayList = new float [Size]; // Create a new payment history array of the same size
    for (int i=0 ; i < Size ; i++) {
        PayList[i] = input.PayList[i]; // Copy each element of the payment history array from the input object
    }
}
// Deallocate the memory for the payment history array
Customer::~Customer() {
    delete [] PayList;
}
// Return the payment history array
float* Customer::getPayList () const {
    return PayList;
}
int Customer::getSize () const {
    return Size;
}

void Customer::printObject() {
    Person::printObject(); // Call the base class's printObject() method
    std::cout << " Payment History: ";
    for (int i=0 ; i < Size ; i++) { // Print the payment history with dollar signs and separators
        std::cout << PayList[i];
        if (i == Size-1)
            std::cout << "$ . " << std::endl;
        else
            std::cout << "$ , ";
    }
    std::cout << '\n';
}

void Customer::buy (const float &Bill){
    if (Bill > 0)
    {
        float* temp;
        temp = new float [Size]; // Create a temporary array to store the current payment history
        for (int i=0 ; i < Size ; i++)
        {
            temp[i] = PayList[i]; // Copy the elements of the current payment history to the temporary array
        }
        ++Size; // Increase the size of the payment history by 1
        delete [] PayList; // Deallocate the memory for the current payment history array
        PayList = new float [Size]; // Create a new payment history array with the updated size
        for (int i=0 ; i < Size ; i++) // Copy the elements from the temporary array to the new payment history array
        {
            PayList[i] = temp[i];
        }
        PayList[Size-1]=Bill; // Add the new payment to the end of the payment history
        delete [] temp; // Deallocate the memory for the temporary array
    }
}
