#pragma once
template <class T>
class BSNode
{
	T _data;
	BSNode<T>* _left;
	BSNode<T>* _right;

public:
	BSNode(T data) : _data(data), _left(nullptr), _right(nullptr) {}
	BSNode(const BSNode<T>& other)
	{
		this->_data = other._data;
		this->_left = other._left;
		this->_right = other._right;
	}

	BSNode<T>& operator=(const BSNode<T>& other)
	{
		this->_data = other._data;
		this->_left = other._left;
		this->_right = other._right;
		return *this;
	}

	bool isLeaf()
	{
		return !(this->_left || this->_right);
	}

	T getData() const
	{
		return this->_data;
	}

	BSNode<T>* getLeft() const
	{
		return this->_left;
	}


	BSNode<T>* getRight() const
	{
		return this->_right;
	}

	void setData(T data)
	{
		this->_data = data;
	}

	void setLeft(BSNode<T>* newLeft)
	{
		this->_left = newLeft;
	}

	void setRight(BSNode<T>* newRight)
	{
		this->_right = newRight;
	}
};