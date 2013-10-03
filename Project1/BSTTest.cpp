#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

#include "BST.h"

using namespace std;

//MinBST can be implemented by simply changing the node_t to MinBSTNode!
template<class node_t>
void test(int argc, char *argv[]){
	srand(time(0));
	std::vector<BSTNode_key_t> items;
	if (argc == 1) {
		std::cout << "Usage: " << argv[0] << "<number-of-random-items | item item item ...>" << std::endl; 
		return;
	}
	else if (argc == 2) {
		for (int i = 0 ; i < stoi(argv[1]) ; i++)
			items.push_back(rand() % 100);
	} else if (argc > 2) {
		for (int i = 1 ; i < argc ; i++)
			items.push_back(stoi(argv[i]));
	}

	BST<node_t> tree;
	cout << tree << endl;
	for (int i = 0 ; i < (int)items.size() ; i++) {
		tree.insert(items.at(i));
		cout << tree << endl;
	}
}

int main(int argc, char *argv[]) {

	test<BSTNode>(argc, argv);
	test<MinBSTNode>(argc, argv);

	return 0;
}