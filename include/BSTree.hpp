#pragma once
#include<iostream>
#include "BSNode.hpp"

template <class T>
class BSTree
{
	BSNode<T>* _root;

public:

	BSTree() : _root(nullptr) {}
	
	BSTree(T rootVal)
	{
		this->_root = new BSNode<T>(rootVal);
	}

	BSTree(const BSTree<T>& other)
	{
		this->_root = nullptr;
		if (other.getRoot() != nullptr)
			tempCopyTree(other._root, *this);
	}

	void tempCopyTree(BSNode<T>* other, BSTree<T>& current)
	{
		if (other == nullptr)
			return;
		current.insertValue(other->getData());
		tempCopyTree(other->getLeft(), current);
		tempCopyTree(other->getRight(), current);
	}

	BSTree<T>& operator=(const BSTree<T>& other)
	{
		if (this != &other)
		{
			this->_root = nullptr;
			if (other.getRoot() != nullptr)
				tempCopyTree(other._root, *this);
		}
		return *this;
	}


	void insertValue(T val)
	{
		this->_root = insertNode(this->_root, val);
	}
	
	BSNode<T>* insertNode(BSNode<T>* root, T val)
	{
		if (root == nullptr)
			return new BSNode<T>(val);
		else if (val > root->getData())
			root->setRight(insertNode(root->getRight(), val));
		else if (val <= root->getData())
			root->setLeft(insertNode(root->getLeft(), val));
		return root;
	}

	BSNode<T>* search(BSNode<T>* root, T val)
	{
		if (root == nullptr)
			return nullptr;
		else if (val > root->getData())
			search(root->getRight(), val);
		else if (val < root->getData())
			search(root->getLeft(), val);
		else if (val == root->getData())
			return root;
	}

	BSNode<T>* getRoot() const
	{
		return this->_root;
	}

	void setRoot(BSNode<T>* newRoot)
	{
		this->_root = newRoot;
	}


	void printTreeTempPreOrder(const BSNode<T>* nodeTree) const
	{
		if (nodeTree == nullptr)
			return;
		std::cout << nodeTree->getData() << " ";
		printTreeTempPreOrder(nodeTree->getLeft());
		printTreeTempPreOrder(nodeTree->getRight());
	}

	void printTreeTempInOrder(const BSNode<T>* nodeTree) const
	{
		if (nodeTree == nullptr)
			return;
		printTreeTempInOrder(nodeTree->getLeft());
		std::cout << nodeTree->getData() << " ";
		printTreeTempInOrder(nodeTree->getRight());
	}


	void printTreeTempPostOrder(const BSNode<T>* nodeTree) const
	{
		if (nodeTree == nullptr)
			return;
		printTreeTempPostOrder(nodeTree->getLeft());
		printTreeTempPostOrder(nodeTree->getRight());
		std::cout << nodeTree->getData() << " ";
	}


	void DestroyRecursive(BSNode<T>* node)
	{
		if (node)
		{
			DestroyRecursive(node->getLeft());
			DestroyRecursive(node->getRight());
			delete node;
		}
	}
	
	~BSTree()
	{
		DestroyRecursive(this->_root);
	}
};