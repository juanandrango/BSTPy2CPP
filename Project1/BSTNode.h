#ifndef BSTNODE_H
#define BSTNODE_H

#include <vector>
#include <string> 
#include <iostream>

typedef int BSTNode_key_t;

struct NodeStr_S {
	int pos;
	int width;
	std::vector<std::string> lines;
	NodeStr_S(int nPos = 0, int nWidth = 0, std::vector<std::string> nLines = std::vector<std::string>()) :
		pos(nPos), width(nWidth), lines(nLines) {}
	NodeStr_S& operator =(const NodeStr_S& nodeStr) {
		pos = nodeStr.pos;
		width = nodeStr.width;
		lines = nodeStr.lines;
		return *this;
	}
};

// A Node in the vanilla BST tree
class BSTNode {
public:

	BSTNode_key_t key;
	BSTNode* parentPtr;
	BSTNode* leftChildPtr;
	BSTNode* rightChildPtr;

	// Creates a Node
	BSTNode(BSTNode& parent, BSTNode_key_t  newKey);

	// Creates the struct NodeStr_S setting the lines vector to have
	// all the necessary strings to print out a cool node representation
	// in ascii
	NodeStr_S str() const;

	// This is required because I will be placing it in a vector
	// for my BST class! (Not found in python!)
	BSTNode(const BSTNode& node);

	// Finds and returns the node with key newKey from the 
	// subtree rooted at this node
	BSTNode* find(BSTNode_key_t newKey);

	// Finds the node with the minimum key in the subtree 
	// rooted at this node
	BSTNode* find_min();

	//Returns the node with the next larger key (the successor) in the BST
	BSTNode* next_larger();

	//Inserts a node into the subtree rooted at this node
	void insert(BSTNode* nodePtr);
	
	// Deletes and returns this node from the BST
	// Keyword delete not allowed in C++
	BSTNode* my_delete();

	// Checks the BST representation invariant around this node
	void check_ri();
};

std::ostream& operator<<(std::ostream& os, BSTNode& node);


#endif