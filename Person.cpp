// Assignment: 4 Person.cpp
// Author: Eve Meir Hackmon , ID: 209295914

#include "Person.h"

Person::Person (const char* name , long id) {
    Name = new char  [strlen(name)+1]; // Dynamically allocate memory for Name
    strcpy(Name , name); // Copy the name to the allocated memory
    ID = id; // Assign the ID
}

Person::Person(Person &input) {
    Name = new char  [strlen(input.Name)+1]; // Dynamically allocate memory for Name
    strcpy(Name , input.Name);
    ID = input.ID; // Copy the ID from the input object
}

Person::~Person() {
    delete [] Name; // Deallocate the memory for Name
}

long Person::getID () const  {
    return ID; // Return the ID

}


void Person::printObject () {
    if (strlen(typeid(*this).name()) > 9) // Check if the type name is longer than 10 characters
        std::cout << " type: " << typeid(*this).name()+2 << std::endl;  // Print the type name without the unnecessary characters
    else
        std::cout << " type: " << typeid(*this).name()+1 << std::endl; // Print the type name without the unnecessary character
    std::cout << " Name: " << Name << std::endl; // Print the Name
    std::cout << " ID: " << ID << std::endl; // Print the ID
}
