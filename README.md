# Student-Management-system-Project-Data-structure-

## Overview

The Student Management System is a C program that provides functionality to manage student records efficiently. It allows users to insert new students, find and update student data, list students in lexicographic order, search students by city, list students by class, delete students, and save all student data to a file. The program utilizes a binary search tree (BST) data structure for efficient data storage and retrieval.

## Getting Started

### Features

Insert Student: Add a new student to the system.
Find and Update Student: Search for a student by ID and update their data.
List Students in Lexicographic Order: Display all students in lexicographic order of their names.
Search Students by City: Find students from a specific city and list them in lexicographic order.
List Students by Class: List students by their class ID in lexicographic order.
Delete Student: Remove a student from the system by ID.
Save Students to File: Save all student data to a file.
Exit: Quit the program.
Data Structure
The program uses a binary search tree (BST) to efficiently store and manage student records. Each node in the BST represents a student, and students are sorted by their IDs.

### Usage

1. Insert a Student
Select option 1 to insert a new student. Enter the student's details, including ID, name, address (city), class ID, and date of enrollment.

2. Find and Update a Student
Choose option 2 to search for a student by their ID. If found, you can update the student's name, address, class ID, and date of enrollment.

3. List Students in Lexicographic Order
Option 3 lists all students in lexicographic order of their names.

4. Search Students by City
Option 4 allows you to search for students from a specific city. Enter the city name, and the program will list all matching students in lexicographic order.

5. List Students by Class
Option 5 lists students by their class ID in lexicographic order.

6. Delete a Student
Select option 6 to delete a student by their ID. The program will remove the student from the system.

7. Save All Students to File
Choose option 7 to save all student records to a file named "students.data.txt."

8. Exit
To exit the program, select option 8.

### Compilation

Use the following command to compile the program:

```bash
gcc main.c -o student_management
Running the Program
After compiling, run the program with this command:
Copy code
./student_management

