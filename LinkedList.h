// Assignment: 4 LinkedList.h - - employee dattaBase
// Author: Eve Meir Hackmon , ID: 209295914

#ifndef PROJECT_2_LINKEDLIST_H
#define PROJECT_2_LINKEDLIST_H

#include "Person.h"
#include "Customer.h"
#include "Employee.h"
#include "CustomerEmployee.h"

//this class creat a linked list of nodes that the key for each node is MyNumber object
class LinkedList {
private:
    class Node {  //node is a private class in linked list
    private:
        Node* next; //mark the address of the next node in the list
        Person* person; //the key of the node
    public:
        Node() : next(nullptr) , person(nullptr) {} //default constructor restart the fields with null
        Node (Person* person1) { // check the typeid of the input and dynamic cast the field person to the same typeid and copy
            if (person1 == nullptr)
                person = nullptr;
            else if (typeid(*person1) == typeid(Customer))
                person = dynamic_cast<Customer*>(person1); //dynamic cast to customer*

            else if (typeid(*person1) == typeid(Employee))
                person = dynamic_cast<Employee*>(person1); //dynamic cast to Employee*

            else if (typeid(*person1) == typeid(CustomerEmployee)) {
                person = dynamic_cast<CustomerEmployee*>(person1); //dynamic cast to CustomerEmployee*
            }
            next = nullptr; //next is null
        }
        //this constructor get a MyNumber pointer to push to the list
        Node (const Node& node) { // copy constructor
            if (node.person != nullptr)
            { // check the typeid of the input and dynamic cast the field person to the same typeid and copy
                if (typeid(*node.person) == typeid(Employee))
                    person = dynamic_cast<Employee*>(&(*node.person));

                else if (typeid(*node.person) == typeid(Customer))
                    person = dynamic_cast<Customer*>(&(*node.person));

                else if (typeid(*node.person) == typeid(CustomerEmployee))
                    person = dynamic_cast<CustomerEmployee*>(&(*node.person));
            }
            else
                person = nullptr;
            if (node.next != nullptr)
                next = new Node (*(node.next)); //copy the next
            else
                next = nullptr; //next is null
        }

        ~Node () {
            delete person;
        }
        Person* getPerson () const {return person;}
        Node* getNext () const {return next;}

        friend LinkedList;
    };
    Node* head; //the head of the list is a node pointer
public:
    LinkedList (); //default constructor
    LinkedList (const LinkedList& list); //copy constructor
    ~LinkedList(); //destructor

    Node* getListHead () const {return head;} //getHead func
    void setListHead (const Node* node) {head = head->next;} //setHead func
    bool idSearch(long id) const; //this func get id and return true if it exists in the list
    float AverageSalary () const; //this func return the average salary in the list
    void updateSalary (long id , float newSalary) const; //this function set the salary of a employee
    void updateShopHistory (long id , float bill) const; // //this function update a shopping history of a customer
    LinkedList& operator=(const LinkedList& list); //operator =delete the prev list and put a new values
    const LinkedList & operator+=(Person& person1); //+= operator add Nodes to the list by order
    friend std::ostream& operator<<(std::ostream& os , const LinkedList& list); //use to print lists
};


#endif //PROJECT_2_LINKEDLIST_H
