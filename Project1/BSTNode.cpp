#include "BSTNode.h"

BSTNode::BSTNode(BSTNode& parent, BSTNode_key_t  newKey) {
	key = newKey;
	parentPtr = &parent;
	leftChildPtr = nullptr;
	rightChildPtr = nullptr;
}

NodeStr_S BSTNode::str() const {
	std::string label = std::to_string(key);
	NodeStr_S leftStr, rightStr;
	int middle, pos, width;
	std::vector<std::string> lines;
	if (leftChildPtr != nullptr) leftStr = leftChildPtr->str();
	if (rightChildPtr != nullptr) rightStr = rightChildPtr->str();
	middle = std::max(rightStr.pos + leftStr.width - leftStr.pos + 1, (int)label.length());
	middle = std::max(middle, 2);
	pos = leftStr.pos + middle / 2;
	width = leftStr.pos + middle + rightStr.width - rightStr.pos;
	while (leftStr.lines.size() < rightStr.lines.size())
		leftStr.lines.push_back(std::string(leftStr.width, ' '));
	while (rightStr.lines.size() < leftStr.lines.size()) 			
		rightStr.lines.push_back(std::string(rightStr.width, ' '));

	if (middle - (int)label.length() % 2 == 1 
		&& parentPtr != nullptr
		&& this == parentPtr->leftChildPtr
		&& (int)label.length() < middle)
		label.append(".");
		
	//Center!
	int filling = middle - label.length();
	label = std::string(filling/2, '.') + label + std::string(filling - filling/2, '.');

	if (label.at(0) == '.') label = std::string(" ") + label.substr(1, label.length() - 1);
	if (label.at(label.length() - 1) == '.') label = label.substr(0, label.length() - 1) + std::string(" ");

	lines.push_back(std::string(leftStr.pos, ' ') + label + std::string(rightStr.width - rightStr.pos, ' '));
	lines.push_back(std::string(leftStr.pos, ' ') + std::string("/") + std::string(middle - 2, ' ') + std::string("\\") + std::string(rightStr.width - rightStr.pos, ' '));

	for (int i = 0 ; i < (int)leftStr.lines.size() && i < (int)rightStr.lines.size() ; i++) {
		lines.push_back(leftStr.lines.at(i) + std::string(width - leftStr.width - rightStr.width, ' ') + rightStr.lines.at(i));
	}

	return NodeStr_S(pos, width, lines);
}

BSTNode::BSTNode(const BSTNode& node) {
	key = node.key;
	parentPtr = node.parentPtr;
	leftChildPtr = node.leftChildPtr;
	rightChildPtr = node.rightChildPtr;
}

BSTNode* BSTNode::find(BSTNode_key_t newKey) {
	if (key == newKey) return this;
	else if (newKey < key) {
		if (leftChildPtr == nullptr) return nullptr;
		else return leftChildPtr->find(newKey);
	} else {
		if (rightChildPtr == nullptr) return nullptr;
		else return rightChildPtr->find(newKey);
	}
}

BSTNode* BSTNode::find_min() {
	BSTNode* current = this;
	while (leftChildPtr != nullptr) current = current->leftChildPtr;
	return current;
}

BSTNode* BSTNode::next_larger() {
	if (rightChildPtr != nullptr) return rightChildPtr->find_min();
	BSTNode* current = this;
	while (current->parentPtr != nullptr 
		&& current == current->parentPtr->rightChildPtr)
		current = current->parentPtr;
	return current->parentPtr;
}

void BSTNode::insert(BSTNode* nodePtr) {
	if (nodePtr == nullptr) return;
	if (nodePtr->key < key) {
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

BSTNode* BSTNode::my_delete() {
	if (leftChildPtr == nullptr || rightChildPtr == nullptr) {
		if (this == parentPtr->leftChildPtr) {
			if (leftChildPtr == nullptr) parentPtr->leftChildPtr = leftChildPtr;
			else parentPtr->leftChildPtr = rightChildPtr;
			if (parentPtr->leftChildPtr != nullptr)
				parentPtr->leftChildPtr->parentPtr = parentPtr;
		} else {
			if (rightChildPtr == nullptr) parentPtr->rightChildPtr = rightChildPtr;
			else parentPtr->rightChildPtr = leftChildPtr;
			if (parentPtr->rightChildPtr != nullptr)
				parentPtr->rightChildPtr->parentPtr = parentPtr;
		}
		return this;
	} else {
		BSTNode* s = next_larger();
		BSTNode_key_t tempKey = key;
		key = s->key;
		s->key = tempKey;
		return s->my_delete();
	}
}

void BSTNode::check_ri() {
	try {
		if (leftChildPtr != nullptr) {
			if (leftChildPtr->key > key)	
				throw std::string("BST RI violated by a left node key");	
			if (leftChildPtr->parentPtr != this)
				throw std::string("BST RI violated by a left node parent pointer");
			leftChildPtr->check_ri();
		}
		if (rightChildPtr != nullptr) {
			if (rightChildPtr->key < key)
				throw std::string("BST RI violated by a right node key");
			if (rightChildPtr->parentPtr != this)
				throw std::string("BST RI violated by a right node parent pointer");
			rightChildPtr->check_ri();
		}
	} catch (std::string msg) {
		std::cout << msg << std::endl;
	}
}

// Overload of the << operator to print a node of type node_t
std::ostream& operator<<(std::ostream& os, BSTNode& node) {
	for (int i = 0 ; i < (int)node.str().lines.size() ; i++) 
		os << node.str().lines.at(i) << "\n";
	return os;
}