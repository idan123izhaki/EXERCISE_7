#include "BSTree.hpp"

template <class T>
BSTree<T>::BSTree() :
    _root(nullptr) {}


template <class T>
BSTree<T>::BSTree(T rootVal)
{
	this->_root = new BSNode<T>(rootVal);
}

template <class T>
BSTree<T>::BSTree(const BSTree<T>& other)
{
    this->_root = nullptr;
    if (other.getRoot() != nullptr)
        tempCopyTree(other._root, *this);
}


template <class T>
BSTree<T>& BSTree<T>::operator=(const BSTree<T>& other)
{
    if (this != &other)
    {
        this->_root = nullptr;
        if (other.getRoot() != nullptr)
            tempCopyTree(other._root, *this);
    }
    return *this;
}

template<class T>
void BSTree<T>::tempCopyTree(BSNode<T>* other, BSTree<T>& current)
{
    if (other == nullptr)
        return;
    current.insertValue(other->getData());
    tempCopyTree(other->getLeft(), current);
    tempCopyTree(other->getRight(), current);
}


template<class T>
void BSTree<T>::insertValue(T val)
{
    this->_root = insertNode(this->_root, val);
}


template<class T>
BSNode<T>* BSTree<T>::insertNode(BSNode<T>* root, T val)
{
    if (root == nullptr)
        return new BSNode<T>(val);
    else if (val > root->getData())
        root->setRight(insertNode(root->getRight(), val));
    else if (val <= root->getData())
        root->setLeft(insertNode(root->getLeft(), val));
    return root;
}

template<class T>
BSNode<T>* BSTree<T>::search(BSNode<T>* root, T val)
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

template <class T>
BSNode<T>* BSTree<T>::getRoot() const
{
	return this->_root;
}

template <class T>
void BSTree<T>::setRoot(BSNode<T>* newRoot)
{
	this->_root = newRoot;
}

template<class T>
BSTree<T>::~BSTree()
{
    DestroyRecursive(this->_root);
}

template<class T>
void BSTree<T>::DestroyRecursive(BSNode<T>* node)
{
    if (node)
    {
        DestroyRecursive(node->getLeft());
        DestroyRecursive(node->getRight());
        delete node;
    }
}

template<class T>
void BSTree<T>::printTreeTempInOrder(const BSNode<T>* nodeTree) const
{
    if (nodeTree == nullptr)
        return;
    printTreeTempInOrder(nodeTree->getLeft());
    std::cout << nodeTree->getData() << " ";
    printTreeTempInOrder(nodeTree->getRight());
}

template<class T>
void BSTree<T>::printTreeTempPreOrder(const BSNode<T>* nodeTree) const
{
    if (nodeTree == nullptr)
        return;
    std::cout << nodeTree->getData() << " ";
    printTreeTempPreOrder(nodeTree->getLeft());
    printTreeTempPreOrder(nodeTree->getRight());
}

template<class T>
void BSTree<T>::printTreeTempPostOrder(const BSNode<T>* nodeTree) const
{
    if (nodeTree == nullptr)
        return;
    printTreeTempPostOrder(nodeTree->getLeft());
    printTreeTempPostOrder(nodeTree->getRight());
    std::cout << nodeTree->getData() << " ";
}