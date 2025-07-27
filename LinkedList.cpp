// Assignment: 4 LinkedList.cpp - employee dattaBase
// Author: Eve Meir Hackmon , ID: 209295914

#include "LinkedList.h"

//default constructor put null in head
LinkedList::LinkedList() {
    head = nullptr;
}
//copy constructor
LinkedList::LinkedList (const LinkedList& list) {
    if (list.head == nullptr) { //check if the input list is empty
        head = nullptr; //head=null
    } else { //else copy the values
        head = new Node(*(list.head)); //copy the input head value
        Node* myCurrent = head; //creat a node pointer to run on my list and copy the nodes
        Node* inputCurrent = list.head; //creat a node pointer to run on the input list and copy the nodes
        while (inputCurrent->next != nullptr) { //run on the input list until the next node is null
            inputCurrent = inputCurrent->next; //promotes the input current
            myCurrent->next= (new Node(*(inputCurrent)));// //copy the address of the input current value to my current
            myCurrent = myCurrent->next; //promotes my current
        }
    }
}
//destructor
LinkedList::~LinkedList() {
    Node* current = head; //current to run on the list
    while (current != nullptr) //until current = null
    {
        Node* next = current->next; //creat a new node pointer to delete every node. put the next node value
        delete current; //delete current
        current = next; //promotes current
    }
}
//operator =delete the prev list and put a new values
LinkedList& LinkedList::operator=(const LinkedList& list) {
    if (this == &list) { //check if try to copy my list
        return *this;//return without change
    }
    Node* current = head;
    while (current != nullptr) {// delete existing memory
        Node* next = current->next;
        delete current;
        current = next;
    }
    if (list.head == nullptr) { //copy the new list exactly like the copy constructor
        head = nullptr;
    } else {
        head = new Node(*(list.head));
        Node* currentNew = head;
        Node* currentOld = list.head;
        while (currentOld->next != nullptr) {
            currentOld = currentOld->next;
            currentNew->next = new Node(*(currentOld));
            currentNew = currentNew->next;
        }
    }

    return *this; //return the list after change
}
//+= operator add Nodes to the list by order
const LinkedList& LinkedList::operator+=(Person& person1) {
    //if (dynamic_cast <Circle*> (person1))
    if (head == nullptr) //if my list is empty
    {
        head = new Node(&person1); //add node to the list with the input value
        return *this;
    }
    else {
        Node *current = head; //current to run on the list until find the place to put the new node
        Node *newNum = new Node(&person1); //creat the new node
        while (current->next != nullptr) //if the input is smaller than the head
            current = current->next;

        current->next = newNum;
        return *this;//return the list
    }
}
//ostream function to print the list
std::ostream& operator<<(std::ostream& os , const LinkedList& list) {
    LinkedList::Node* current = list.head; //current to run on the list
    while (current != nullptr) { //until null
        current->getPerson()->printObject();//print the numbers
        std::cout << '\n';
        current = current->getNext(); //promote current
    }
    return os; //return os
}

bool LinkedList::idSearch(long id) const {
    Node* current = head; // Start at the head of the linked list
    while (current != nullptr) // Iterate until the end of the linked list
    {
        if (current->person->getID() == id) // ID found, return true
        {
            return true;
        }
        current = current->next; // Move to the next nod
    }
    return false; // ID not found, return false
}

void LinkedList::updateShopHistory (long id , float bill) const {
    bool flag = false; // Flag to track if the customer is found
    Node* current = head; // Start at the head of the linked list
    if (bill > 0) // Check if the bill amount is positive
    {
        while (current != nullptr) // Iterate until the end of the linked list
        {
            if (current->person->getID() == id) // Check if the current node's person ID matches the given ID
            {
                if (typeid(*current->person) == typeid(Customer)) // Check if the current person is of type Customer
                {
                    dynamic_cast<Customer *>(current->person)->buy(bill); // Update the shop history of the Customer
                    flag = true;
                }

                if (typeid(*current->person) == typeid(CustomerEmployee)) // Check if the current person is of type CustomerEmployee
                {
                    dynamic_cast<CustomerEmployee *>(current->person)->buy(bill); // Update the shop history of the CustomerEmployee
                    flag = true;
                }
            }
            current = current->next; // Move to the next node
        }
    }
    if (!flag)
        std::cout << " The Customer is not in the system " << std::endl;
}

void LinkedList::updateSalary (long id , float newSalary) const {
    bool flag = false; // Flag to track if the employee is found
    Node *current = head; // Start at the head of the linked list
    if (newSalary > 0) // Check if the new salary is positive
    {
        while (current != nullptr) // Iterate until the end of the linked list
        {
            if (current->person->getID() == id) // Check if the current node's person ID matches the given ID
            {
                if (typeid(*current->person) == typeid(Employee)) // Check if the current person is of type Employee
                {
                    dynamic_cast<Employee *>(current->person)->setSalary(
                            newSalary); // Update the salary of the Employee
                    flag = true;
                }
                if (typeid(*current->person) ==
                    typeid(CustomerEmployee)) // Check if the current person is of type CustomerEmployee
                {
                    dynamic_cast<CustomerEmployee *>(current->person)->setSalary(
                            newSalary);  // Update the salary of the CustomerEmployee
                    flag = true;
                }

                current = current->next; // Move to the next node
            }
        }
        if (!flag)
            std::cout << " The employee is not in the system " << std::endl;
    }
}

    float LinkedList::AverageSalary() const {
        float sum = 0; // Variable to store the sum of salaries
        int employeeCounter = 0; // Counter to keep track of the number of employees
        Node *current = head; // Start at the head of the linked list
        while (current != nullptr) { // Iterate until the end of the linked list
            if (typeid(*current->person) == typeid(Employee)) // Check if the current person is of type Employee
            {
                sum += dynamic_cast<Employee *>(current->person)->getSalary(); // Add the salary of the Employee to the sum
                ++employeeCounter; // Increment the employee counter
            }
            else if (typeid(*current->person) == typeid(CustomerEmployee)) // Check if the current person is of type CustomerEmployee
            {
                sum += dynamic_cast<CustomerEmployee *>(current->person)->getSalary(); // Add the salary of the CustomerEmployee to the sum
                ++employeeCounter; // Increment the employee counter
            }
            current = current->next; // Move to the next node
        }
        if (employeeCounter > 0)
            return sum / employeeCounter; // Calculate and return the average salary
        else
            return 0; // No employees found, return 0
    }


