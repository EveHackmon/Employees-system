# Employees System

A C++ project for managing employees and customers.  
The system allows you to add users (Employee, Customer, CustomerEmployee), update shopping history, update salaries, print average salary, and display all data.

## Features

- Add users of different types (Customer, Employee, CustomerEmployee)
- Update shopping history for customers
- Update salary for employees
- Print average salary of employees
- Print all data in the system

## Project Structure

- `main.cpp` — Main file, contains the menu logic and main functions
- `LinkedList.h/cpp` — Implementation of a linked list for users
- `Employee.h/cpp` — Employee class
- `Customer.h/cpp` — Customer class
- `CustomerEmployee.h/cpp` — CustomerEmployee class

## How to Run

1. Make sure all source files are in the same folder.
2. Compile the project using g++:
    g++ *.cpp -o main.exe
3. Run the program:
    ./main.exe

## Example Usage

After running, you will see an interactive menu:
```
WELCOME
Menu:
 1. Add user to the list
 2. Add number amount to shopping history
 3. Update employee salary
 4. Print Average Salary
 5. Print all datta
 6. Exit
```
Choose the desired option and follow the instructions.

---

**Author:**  
Eve Meir Hackmon  
ID: 209295914
