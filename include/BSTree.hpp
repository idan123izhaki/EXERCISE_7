#pragma once
#include<iostream>
#include "BSNode.hpp"

template <class T>
class BSTree
{
	BSNode<T>* _root;

public:
	BSTree();
	BSTree(T rootVal);
	BSTree(const BSTree<T>& other);
	void tempCopyTree(BSNode<T>*, BSTree<T>&);
	BSTree<T>& operator=(const BSTree<T>& other);
	void insertValue(T val);
	BSNode<T>* insertNode(BSNode<T>* tree, T);
	BSNode<T>* search(BSNode<T>* root, T val);
	BSNode<T>* getRoot() const;
	void setRoot(BSNode<T>*);
	void printTreeTempInOrder(const BSNode<T>*) const;
	void printTreeTempPreOrder(const BSNode<T>*) const;
	void printTreeTempPostOrder(const BSNode<T>*) const;
	void DestroyRecursive(BSNode<T>*);
	~BSTree();
};