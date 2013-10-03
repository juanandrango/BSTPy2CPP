#ifndef AVL_H
#define AVL_H

#include "AVLNode.h"
#include "BST.h"

// AVL binary search tree implementation.
// Supports insert, delete, find, find_min, 
// next_larger each in O(lg n) time.
class AVL : public BST<AVLNode> {
public:
	void left_rotate(AVLNode* node);
	void right_rotate(AVLNode* node);
	void rebalance(AVLNode* node);
	
	// Inserts a node with key k into the subtree rooted at 
	// this node. This AVL version guarantees the balance 
	// property: h = O(lg n)
	AVLNode* insert(BSTNode_key_t k);

	// Deletes and returns a node with key k if it exists 
	// from the BST. This AVL version guarantees the balance 
	// property: h = O(lg n)
	AVLNode deleteBSTNode(BSTNode_key_t k);
};

void update_height(AVLNode* node);
int height(AVLNode* node);

#endif