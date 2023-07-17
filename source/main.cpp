#include <iostream>
#include "BSTree.hpp"
#include "BSNode.hpp"
#include "BSTree.cpp"
#include "BSNode.cpp"

int main()
{
	BSTree<int> tree;
	tree.insertValue(9);
	tree.insertValue(1);
	tree.insertValue(8);
	tree.insertValue(45);
	tree.insertValue(6);
	tree.insertValue(23);
	tree.insertValue(2);
	tree.insertValue(12);
	tree.insertValue(10);

	std::cout << "Tree: ";
	tree.printTreeTemp(tree.getRoot()); std::cout << std::endl;
	BSNode<int>* t2 = tree.search(tree.getRoot(), 1);
	(t2 == nullptr) ? std::cout << "There is not element like this in the BST!" << std::endl : 
		std::cout << "The element: " << t2->getData() << ", is exist!" << std::endl;
	std::cout << std::endl;

	BSTree<int> tree2(tree);
	BSTree<int> tree3 = tree2;
	
	tree2.insertValue(2222);
	tree3.insertValue(3333);

	std::cout << "Tree2: ";
	tree2.printTreeTemp(tree2.getRoot());
	std::cout << std::endl;
	
	std::cout << "Tree3: ";
	tree3.printTreeTemp(tree3.getRoot());
	std::cout << std::endl;

	return 0;
}