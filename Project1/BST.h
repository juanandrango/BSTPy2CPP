#ifndef BST_H
#define BST_H

#include "MinBSTNode.h"

// A binary search tree
template<class node_t> class BST {
public: 
	node_t* rootPtr;
	BST() : rootPtr(nullptr) {}
	node_t* find(BSTNode_key_t newKey) { return static_cast<node_t*>(rootPtr->find(newKey)); }
	node_t* find_min() { return rootPtr->find_min(); }
	
	// This function creates dynamic allocated nodes of the type node_t
	// DeleteBSTNode function is the only function that will take care 
	// of their deletion!
	node_t* insert(BSTNode_key_t newKey) {
		node_t* node = new node_t( *(static_cast<node_t*>(nullptr)), newKey);
		if (rootPtr == nullptr)
			rootPtr = node;		
		else  
			rootPtr->insert(node);
		return node;
	}

	// Handle Garbage collection for Dynamic allocated nodes!
	// We delete the dynamic allocated object and return an stack 
	// allocated object what will get deleted after it leaves the 
	// scope of the caller!
	node_t deleteBSTNode(BSTNode_key_t newKey) {
		node_t* node = find(newKey);
		if (node == nullptr) 
			return *(static_cast<node_t*>(nullptr));
		if (node == rootPtr) {
			node_t pseudoroot( *(static_cast<node_t*>(nullptr)), 0);	
			pseudoroot.leftChildPtr = rootPtr;
			rootPtr->parentPtr = &pseudoroot;
			node_t* deleted = static_cast<node_t*>(rootPtr->my_delete());
			rootPtr = static_cast<node_t*>(pseudoroot.leftChildPtr);
			if (rootPtr != nullptr)
				rootPtr->parentPtr = nullptr;
			node_t newDeleted(*deleted);
			delete deleted;
			return newDeleted;
		} else {
			node_t newDeleted(*(static_cast<node_t*>(node->my_delete())));
			delete node->my_delete();
			return newDeleted;
		}
	}

	// Returns the node that contains the next larger 
	// (the successor) key in the BST in relation to 
	// the node with key k
	node_t* next_larger(BSTNode_key_t newKey) {
		node_t* node = find(newKey);
		if (node != nullptr)
			node = node->next_larger();
		return node;
	}
	
	// Checks the BST representation invariant
	void check_ri() {
		try {
			if (rootPtr != nullptr) {
				if (rootPtr->parentPtr != nullptr) 
					throw(std::string("BST RI violated by the root node's parent Pointer"));
				rootPtr->check_ri();
			}	
		} catch (std::string msg) {
			std::cout << msg << std::endl;
		}
	}
};

// Overload of the << operator to print a representation of a BST in 
// the standard output!
template<class node_t>
std::ostream& operator<<(std::ostream& os, BST<node_t>& tree) {
	if (tree.rootPtr == nullptr)
		return os << "<empty tree>";
	return os << *(tree.rootPtr);
}

#endif