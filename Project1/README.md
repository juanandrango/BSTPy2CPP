BST From Python to C++
======================

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
