# C++ Binary Search Tree | University Assessment

This was the final assessment in my Algorithms and Data Structures unit. I received a High Distinction.
Below is the Assignment context and tasks that were required.

# Context
The tasks below aim to examine your ability to implement various data structures and adapt them to suit custom-made classes.
Task 1 populates three different data structures and compares their search times against each other. In theory, a binary search tree should be able to output perform a linked list for searching on large data sets, and a balanced binary search tree even more so. But is this true in all circumstances? Is there a clear winner? Binary search trees are quite quick to search through if you are looking for a particular node. These patterns are branched out to solve all sorts of problems, from storing data in a map with easy retrievals, to organising 3D elements in a game to render only those on screen at the time.
Task 2 asks you to delve into a more complicated aspect of object-oriented programming, polymorphism. To show this level of understanding, you will need to implement a class hierarchy and max heap data structure to house 10 or more employees, sorted with highest salary on the top. Polymorphism allows you to conveniently group similar but different objects together, amongst other benefits. Heap is a different type of binary search tree that is more focused on keeping either the smallest or largest elements at the top of each branch. Using this, you can prioritise which data is worked with first. Polymorphism can be used in any situation where there is a group of similar but still distinctly different datatypes. For example, it can be used to manage a user interface system where all text boxes, buttons, drop down lists, etc., are very different controls but still live under the idea of a user control. Being able to generalise your datatypes enough to group them will create shorter and easier code to test in the long run.

# Task 1
### Step 1
Implement a binary search tree with integer-based nodes.
### Step 2
Extend your BST by making a sub class of AVL or red-black tree utilising inheritance.
### Step 3
Include list in your main source file. Now insert 150,000 random numbers into a list, a BST, and a balanced BST (AVL or red-black tree). Make sure the same numbers are inserted into each.
Reference the pseudocode below for guidance:
- Initialise list numbers
- Initialise BST bst
- Initialise BalancedBST bbst
- For num 1 to 150000
  - Set R to random number
  - Insert R into numbers
  - Insert R into bst
  - Insert R into bbst
  
### Step 4
Present the user with a simple menu:  
Select an option:  
1) Search for a number all data structures  
2) Exit  
Enter in option (1–2):

If the user selects 1, the user is asked to input a number. This number is searched for in the list,
binary search tree, and balanced binary search tree, recording how long it takes in milliseconds to do
each. If the number is found in the structures, display the time taken to find it in each structure. If
not, let the user know that the number could not be found in any of them and still show the time to
complete the search on each structure.

# Task 2
This task's goal is to explore the uses of a max heap with polymorphic data. You will implement a
system to store different types of employees and retrieve the highest paid from the top.
### Step 1
Implement the employee class hierarchy below, taking advantage of inheritance:  
[Class Hierarchy](https://i.imgur.com/DHWyDkd.png)  
Janitor, Programmer and CEO all inherit from Employee class. Build appropriate constructors,
getters, and setters to help set and retrieve their attributes.
### Step 2
Override OutputJobDescription() in each of the sub classes to output information about what
they do. Programmer should also output bugsFixed and bugsCreated. CEO should also output their
projected annualBonus.
### Step 3
Implement a max heap structure that stores Employee pointers (for polymorphism, we need a
pointer of the base type). Use employees’ salaries to help sort them into the structure with biggest
salary on top and the lowest on the bottom.
### Step 4
Instantiate at least 10 different Employee type objects (a mix of Employee,Janitor, Programmer,
CEO types) and insert them into the max heap.
### Step 5
Write a loop that retrieves the Employee pointer from the top of the max heap. Call that employee’s
OutputJobDescription() and OutputEarning() methods. Then remove the top employee from
the max heap structure. Repeat until the heap is empty.
The program should output to the screen the employees’ details in order of highest paid to lowest
