#include <iostream>
#include "BSTree.hpp"
#include "BSNode.hpp"


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

	std::cout << "Tree 1: " << std::endl;
	std::cout << "PreOrder: "; tree.printTreeTempPreOrder(tree.getRoot()); std::cout << std::endl;
	std::cout << "InOrder: "; tree.printTreeTempInOrder(tree.getRoot()); std::cout << std::endl;
	std::cout << "PostOrder: "; tree.printTreeTempPostOrder(tree.getRoot()); std::cout << std::endl;

	BSNode<int>* t2 = tree.search(tree.getRoot(), 1);
	(t2 == nullptr) ? std::cout << "There is not element like this in the BST!" << std::endl : 
		std::cout << "The element: " << t2->getData() << ", is exist!" << std::endl;
	std::cout << std::endl;

	BSTree<int> tree2(tree);
	BSTree<int> tree3 = tree2; //tree3.operator=(tree2);
	
	tree2.insertValue(2222);
	tree3.insertValue(3333);

	std::cout << "Tree 2: " << std::endl;
	std::cout << "PreOrder: "; tree2.printTreeTempPreOrder(tree2.getRoot()); std::cout << std::endl;
	std::cout << "InOrder: "; tree2.printTreeTempInOrder(tree2.getRoot()); std::cout << std::endl;
	std::cout << "PostOrder: "; tree2.printTreeTempPostOrder(tree2.getRoot()); std::cout << std::endl;
	

	std::cout << "\nTree3:\nInOrder: ";
	tree3.printTreeTempInOrder(tree3.getRoot());
	std::cout << std::endl;

	return 0;
}