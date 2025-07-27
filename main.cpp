// Assignment: 4 main.cpp
// Author: Eve Meir Hackmon , ID: 209295914

#include <iostream>
#include <array>
#include "LinkedList.h"
#include "Employee.h"
#include "Customer.h"
#include "CustomerEmployee.h"

#define BUFFER 30
using namespace std;
enum { Add_Person = '1' , Add_Shop_History = '2' , Salary_Update = '3' , Average_Salary = '4' , Print_ALL_Datta = '5' , Exit = '6' };
enum { Add_Customer = '1' , Add_Employee = '2' , Add_CustomerEmployee = '3' };
void addPerson (LinkedList &list); // Function declaration
//Main function
int main() {
    LinkedList List; //linked list of users
    long ID; //ID temp
    float number; //used as a temp to purchase or a new salary
    char option; //user option
    bool flag = false; //false while using program

    cout << " WELCOME \n";
    while (!flag) {
        cout << " Menu: \n" //print to user the menu
                " 1. Add user to the list \n"
                " 2. Add number amount to shopping history \n"
                " 3. Update employee salary \n"
                " 4. Print Average Salary \n"
                " 5. Print all datta \n"
                " 6. Exit \n" << endl;
        cin >> option;
        switch (option)
        {
            case Add_Person: //in this case the user can add client or employees to the list
                addPerson(List);
                break;
            case Add_Shop_History: //in this case the user can add a purchase to the shopping history of a client
                cout << " Enter customer ID " << endl; //ask for customer ID
                cin >> ID;
                cout << " Enter purchase amount " << endl; //ask for the amount of the buy
                cin >> number;
                if (ID < 10000000 || !List.idSearch(ID)) //check the ID
                    cout << " Error, customer was not found " << endl;
                else //Update the history in LinkedList method
                    List.updateShopHistory(ID , number);
                break;

            case Salary_Update: //in this case the user can update a employee salary
                cout << " Enter Employee ID " << endl;  //ask for customer ID
                cin >> ID;
                cout << " Enter new salary " << endl; //ask for the new salary
                cin >> number;
                if ( ID < 10000000 || !List.idSearch(ID)) //check the ID
                    cout << " Error, customer was not found " << endl;
                else //Update the Employee salary in LinkedList method
                    List.updateSalary(ID , number);
                break;

            case Average_Salary: //this case will print the average salary of employees
                    cout << " Average salary is: " << List.AverageSalary()  << "$ " << endl;
                break;

            case Print_ALL_Datta: //this case prints all datta
                    cout << List;
                break;

            case Exit: //exit case
                cout << " See you next time " << endl;
                flag = true;
                break;

            default:
                cout << " Option is not exist! " << endl;
                break;
        }
    }
    return 0;
}

void addPerson (LinkedList &list) {
    char option; //option of the user
    char buffer[BUFFER]; //buffer
    long id; //temp ID
    float salary; //salary
    cout << " Which user would you like to add? \n" //asking each kind of person the user want to add
            " 1. Add Customer \n"
            " 2. Add Employee \n"
            " 3. Add CustomerEmployee " << endl;
    cin >> option; //get the option
    switch (option) {
        case Add_Customer: //in this case the user add a customer
            while (getchar()!='\n');
            cout << " Enter customer name " << endl; //ask for a customer name
            cin.getline(buffer , BUFFER);
            cout << " Enter ID " << endl; //ask for a customer ID
            cin >> id;
            Customer* x;
            x = new Customer(buffer , id); //creat a new Customer object
            list+= *x; //add to the list
            break;

        case Add_Employee: //in this case the user add an Employee
            while (getchar()!='\n');
            cout << " Enter Employee name " << endl; //ask for an employee name
            cin.getline(buffer , BUFFER);
            cout << " Enter ID " << endl; //ask for a customer ID
            cin >> id;
            cout << " Enter salary " << endl; //ask for the employee salary
            cin >> salary;
            Employee* y;
            y = new Employee(buffer , id , salary); //creat a new Employee object
            list+= *y; //add to the list
            break;

        case Add_CustomerEmployee: //in this case the user add an CustomerEmployee
            while (getchar()!='\n');
            cout << " Enter Customer Employee name " << endl; //ask for an CustomerEmployee name
            cin.getline(buffer , BUFFER);
            cout << " Enter ID " << endl; //ask for a CustomerEmployee ID
            cin >> id;
            cout << " Enter salary " << endl; //ask for a CustomerEmployee salary
            cin >> salary;
            Employee* z;
            z = new CustomerEmployee(buffer , id , salary);  //creat a new CustomerEmployee object
            list += *z; //add to the list
            break;
        default: //default message
            cout << " Option is not exist! " << endl;
            break;
    }
}
//This function returns by reference the sum of employees and customers in the linked list
std::array<int, 2> find_types (LinkedList &list , int size) {
    std::array<int, 2> arr = {0, 0};
    int employeeCounter = 0 , customerCounter = 0;
    LinkedList tempList = list;
    while (tempList.getListHead() != nullptr) {
        if (typeid(tempList.getListHead()->getPerson()) == typeid(Customer))
            ++customerCounter;
        if (typeid(tempList.getListHead()->getPerson()) == typeid(Employee))
            ++employeeCounter;
        if (typeid(tempList.getListHead()->getPerson()) == typeid(CustomerEmployee)) {
            ++customerCounter;
            ++employeeCounter;
        }
        tempList.setListHead(tempList.getListHead()->getNext());
    }
    arr[0]=employeeCounter;
    arr[1]=customerCounter;
    return arr;
}

/*
    /////////////////CHECK//////////////////
    Customer eve ("Eve" , 209295914 );
    List+=eve;
    List.updateShopHistory(209295914 , 10);
    List.updateShopHistory(209295914 , 100);
    List.updateShopHistory(209295914 , 1000);

    Employee romi ("romi" , 123456789 , 10000);
    List+=romi;
    List.updateSalary(123456789 , 100000);

    CustomerEmployee shir ("Mami Hackmon" , 987654321 , 15000);
    List+=shir;
    List.updateShopHistory(987654321 , 10);
    List.updateShopHistory(987654321 , 100);
    List.updateShopHistory(987654321 , 1000);

    CustomerEmployee eti ("eti" , 32358434 , 15000);
    List+=eti;
    List.updateShopHistory(32358434 , 1500);
    List.updateShopHistory(32358434 , 2000);
    List.updateShopHistory(32358434 , 10);



    //////////////////////////
    */