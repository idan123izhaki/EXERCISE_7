#include "BSnode.hpp"

template <class T>
BSNode<T>::BSNode(T data) : _data(data), _left(nullptr), _right(nullptr) {}

template <class T>
BSNode<T>::BSNode(const BSNode<T>& other)
{
	this->_data = other._data;
	this->_left = other._left;
	this->_right = other._right;
}

template <class T>
BSNode<T>::~BSNode(){}

template<class T>
BSNode<T>& BSNode<T>::operator=(const BSNode<T>& other)
{
	this->_data = other._data;
	this->_left = other._left;
	this->_right = other._right;
	return *this;
}

template<class T>
bool BSNode<T>::isLeaf()
{
	return !(this->_left || this->_right);
}

template <class T>
T BSNode<T>::getData() const
{
	return this->_data; 
}

template <class T>
BSNode<T>* BSNode<T>::getLeft() const
{
	return this->_left;
}

template <class T>
BSNode<T>* BSNode<T>::getRight() const
{
	return this->_right;
}

template <class T>
void BSNode<T>::setData(T data)
{
	this->_data = data;
}

template <class T>
void BSNode<T>::setLeft(BSNode<T>* newLeft)
{
	this->_left = newLeft;
}

template <class T>
void BSNode<T>::setRight(BSNode<T>* newRight)
{
	this->_right = newRight;
}