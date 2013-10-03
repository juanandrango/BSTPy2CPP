#ifndef MINBSTNODE_H
#define MINBSTNODE_H

#include "BSTNode.h"

// A BSTNode which is augmented to keep track of the node with the 
// minimum key in the subtree rooted at this node
class MinBSTNode : public BSTNode {
public:
	MinBSTNode* minPtr;

	MinBSTNode(MinBSTNode& parent, BSTNode_key_t  newKey);

	// This is required because I will be placing it in a vector
	// for my BST class! (Not found in python!); Notice here I need
	// to explicitly call on the copy constructor from my base class
	// BSTNode since such class doesn't have a default constructor!
	MinBSTNode(const MinBSTNode& node);

	// Finds the node with the minimum key in the subtree rooted 
	// at this node. Unlike BSTNode, this returns the minimun in 
	// constant time O(1)
	MinBSTNode* find_min() { return minPtr; }

	// Inserts a node into the subtree rooted at this node
	void insert(MinBSTNode* nodePtr);

	//Lots of extra casting!
	MinBSTNode* my_delete();
};

#endif