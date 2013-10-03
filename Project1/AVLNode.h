#ifndef AVLNODE_H
#define AVLNODE_H

#include "BSTNode.h"

// The node type to be used in an AVL tree
// This node has an extra property called height, which 
// is used by an AVL tree to balance it
class AVLNode : public BSTNode {
public:
	int height;
	AVLNode(AVLNode& parent, BSTNode_key_t newkey) : BSTNode(parent, newkey), height(1) {}
	AVLNode(const AVLNode& node) : BSTNode(node), height(node.height) {}
};

#endif
