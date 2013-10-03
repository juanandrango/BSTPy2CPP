BST From Python to C++
======================

The motivation of this project is showing the many differences among
Python programs and C++ programs. 

The python code files were taken from the MIT Introduction to Algorithms 
Leture6 and all the logic implemented in C++ comes from the python files.

We clearly identify python as the favorite language for prototyping and 
getting things done faster and with zero intuition on performance, yet 
providing a super fast prototype nonetheless.

The C++ implementation is bigger, more complex (i.e. number of files, 
memory management, pointers !!!) and it takes longer to get it right even 
after the logic has been provided!. The one reason why one would want to 
use C++ for a prototype such as a BST or a AVL, is because we can prove that
for large inputs C++ easily outruns the python implementation!

Improvements to this project will focus on improving both Python and C++ code
to the point of "ideal" runtime for an input of size n, and compare them
against each other!

The code provided by MIT resources is pretty fine tune, however, C++ gives you
more room for improvements since it allows you to walk closer to the metal!

To Understand what a Binary Search Tree is, I suggest going over the free online
course provided by MIT (URL found in the credits below)

```
Demaine, Erik, and Srinivas Devadas. 6.006 Introduction to Algorithms, Fall 2011. 
(MIT OpenCourseWare: Massachusetts Institute of Technology), 
http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/
6-006-introduction-to-algorithms-fall-2011 (Accessed 3 Oct, 2013). 
License: Creative Commons BY-NC-SA
```

This directory contains implementations of different Binary Search Trees
(BSTs), in particular vanilla (unbalanced) BSTs and AVL (balanced) trees.

1. Vanilla BSTs.

   Support for ASCII art and random testing.

2. AVL tree (balanced).

   Extends on BST. Supports insert and delete while maintaining balance.  
   Also supports ASCII art and random teting.

USAGE
-----
```
Project1.exe <number-of-random-items | item item item ...>
```

Either Provide a n integer to insert n random generated keys OR
provide a list of integers.

EXAMPLES
--------

Project1.exe 1 2 3 4

```
<empty tree>
-------------------------------------------------------
***** Unbalanced (1) ******
1
/\

***** Balancend (1) *******
1
/\

-------------------------------------------------------


-------------------------------------------------------
***** Unbalanced (2) ******
1
/\
 2
 /\

***** Balancend (2) *******
1
/\
 2
 /\

-------------------------------------------------------


-------------------------------------------------------
***** Unbalanced (3) ******
1
/\
 2
 /\
  3
  /\

***** Balancend (3) *******
  2
 / \
1  3
/\ /\

------------------------------------------------------

-------------------------------------------------------
***** Unbalanced (4) ******
1
/\
 2
 /\
  3
  /\
   4
   /\

***** Balancend (4) *******
  2
 / \
1  3
/\ /\
    4
    /\

-------------------------------------------------------

```
