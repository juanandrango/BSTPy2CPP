#include "AVL.h"

void AVL::left_rotate(AVLNode* node) {
	AVLNode* localNodePtr = static_cast<AVLNode*>(node->rightChildPtr);
	localNodePtr->parentPtr = static_cast<AVLNode*>(node->parentPtr);
	if (localNodePtr->parentPtr == nullptr) rootPtr = localNodePtr;
	else {
		if (static_cast<AVLNode*>(localNodePtr->parentPtr->leftChildPtr)
			== static_cast<AVLNode*>(node))
			localNodePtr->parentPtr->leftChildPtr = localNodePtr;
		else if (static_cast<AVLNode*>(localNodePtr->parentPtr->rightChildPtr)
			== static_cast<AVLNode*>(node))
			localNodePtr->parentPtr->rightChildPtr = localNodePtr;
	}
	node->rightChildPtr = localNodePtr->leftChildPtr;
	if (node->rightChildPtr != nullptr)
		node->rightChildPtr->parentPtr = node;
	localNodePtr->leftChildPtr = node;
	node->parentPtr = localNodePtr;
	update_height(node);
	update_height(localNodePtr);
}

void AVL::right_rotate(AVLNode* node) {
		AVLNode* localNodePtr = static_cast<AVLNode*>(node->leftChildPtr);
	localNodePtr->parentPtr = static_cast<AVLNode*>(node->parentPtr);
	if (localNodePtr->parentPtr == nullptr) rootPtr = localNodePtr;
	else {
		if (static_cast<AVLNode*>(localNodePtr->parentPtr->leftChildPtr)
			== static_cast<AVLNode*>(node))
			localNodePtr->parentPtr->leftChildPtr = localNodePtr;
		else if (static_cast<AVLNode*>(localNodePtr->parentPtr->rightChildPtr)
			== static_cast<AVLNode*>(node))
			localNodePtr->parentPtr->rightChildPtr = localNodePtr;
	}
	node->leftChildPtr = localNodePtr->rightChildPtr;
	if (node->leftChildPtr != nullptr)
		node->leftChildPtr->parentPtr = node;
	localNodePtr->rightChildPtr = node;
	node->parentPtr = localNodePtr;
	update_height(node);
	update_height(localNodePtr);
}

void AVL::rebalance(AVLNode* node) {
	while ( node != nullptr) {
		update_height(node);
		if (height(static_cast<AVLNode*>(node->leftChildPtr))
			>= 2 + height (static_cast<AVLNode*>(node->rightChildPtr))) {
				if (height(static_cast<AVLNode*>(node->leftChildPtr->leftChildPtr))
					>= height(static_cast<AVLNode*>(node->leftChildPtr->rightChildPtr)))
					right_rotate(node);
				else {
					left_rotate(static_cast<AVLNode*>(node->leftChildPtr));
					right_rotate(node);
				}
		} else if (height(static_cast<AVLNode*>(node->rightChildPtr))
			>= 2 + height(static_cast<AVLNode*>(node->leftChildPtr))) {
				if (height(static_cast<AVLNode*>(node->rightChildPtr->rightChildPtr))
					>= height(static_cast<AVLNode*>(node->rightChildPtr->leftChildPtr)))
					left_rotate(node);
				else {
					right_rotate(static_cast<AVLNode*>(node->rightChildPtr));
					left_rotate(node);
				}
		}
		node = static_cast<AVLNode*>(node->parentPtr);
	}
}

AVLNode* AVL::insert(BSTNode_key_t newKey) {
	AVLNode* node = static_cast<AVLNode*>(BST::insert(newKey));
	rebalance(node);
	return node;
}

AVLNode AVL::deleteBSTNode(BSTNode_key_t k) {
	BSTNode node = BST::deleteBSTNode(k);
	//rebalance(static_cast<AVLNode*>(node.parentPtr));
	return *(static_cast<AVLNode*>(nullptr));
}

void update_height(AVLNode* node) {
	if (node == nullptr) return;
	node->height = std::max(height(static_cast<AVLNode*>(node->leftChildPtr)),
		height(static_cast<AVLNode*>(node->rightChildPtr))) + 1;
}

int height(AVLNode* node) {
	if (node != nullptr) return node->height;
	return -1;
}