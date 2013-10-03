#include "MinBSTNode.h"

MinBSTNode::MinBSTNode(MinBSTNode& parent, BSTNode_key_t  newKey) : 
	BSTNode(parent, newKey) {
		minPtr = this;
}

MinBSTNode::MinBSTNode(const MinBSTNode& node) : BSTNode(node) {
	key = node.key;
	parentPtr = node.parentPtr;
	leftChildPtr = node.leftChildPtr;
	rightChildPtr = node.rightChildPtr;
	minPtr = node.minPtr;
}

void MinBSTNode::insert(MinBSTNode* nodePtr) {
	if (nodePtr == nullptr) return;
	if (nodePtr->key < key) {
		if (nodePtr->key < minPtr->key) minPtr = nodePtr;
		if (leftChildPtr == nullptr) {
			nodePtr->parentPtr = this;
			leftChildPtr = nodePtr;
		} else leftChildPtr->insert(nodePtr);
	} else {
		if (rightChildPtr == nullptr) {
			nodePtr->parentPtr = this;
			rightChildPtr = nodePtr;
		} else rightChildPtr->insert(nodePtr);
	}
}

MinBSTNode* MinBSTNode::my_delete() {
	if (leftChildPtr == nullptr || rightChildPtr == nullptr) {
		if (this == parentPtr->leftChildPtr) {
			if (leftChildPtr == nullptr) parentPtr->leftChildPtr = leftChildPtr;
			else parentPtr->leftChildPtr = rightChildPtr;
			if (parentPtr->leftChildPtr != nullptr) {
				parentPtr->leftChildPtr->parentPtr = parentPtr;
				static_cast<MinBSTNode*>(parentPtr)->minPtr = static_cast<MinBSTNode*>(parentPtr->leftChildPtr)->minPtr;
			} else static_cast<MinBSTNode*>(parentPtr)->minPtr = static_cast<MinBSTNode*>(parentPtr);
			MinBSTNode* c =  static_cast<MinBSTNode*>(parentPtr);
			while (c->parentPtr != nullptr && c == c->parentPtr->leftChildPtr) {
				static_cast<MinBSTNode*>(c->parentPtr)->minPtr = c->minPtr;
				c = static_cast<MinBSTNode*>(c->parentPtr);
			}
		} else {
			if (rightChildPtr == nullptr) parentPtr->rightChildPtr = rightChildPtr;
			else parentPtr->rightChildPtr = leftChildPtr;
			if (parentPtr->rightChildPtr != nullptr)
				parentPtr->rightChildPtr->parentPtr = parentPtr;
		}
		return this;
	} else {
		//Need casting!
		MinBSTNode* s = static_cast<MinBSTNode*>(next_larger());
		BSTNode_key_t tempKey = key;
		key = s->key;
		s->key = tempKey;
		return s->my_delete();
	}
}