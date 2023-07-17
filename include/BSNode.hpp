#pragma once
template <class T>
class BSNode
{
	T _data;
	BSNode<T>* _left;
	BSNode<T>* _right;

public:
	BSNode(T data);
	BSNode(const BSNode<T>& other);
	~BSNode();
	BSNode<T>& operator=(const BSNode<T>& other);
	bool isLeaf();
	T getData() const;
	BSNode<T>* getLeft() const;
	BSNode<T>* getRight() const;
	void setData(T);
	void setLeft(BSNode<T>*);
	void setRight(BSNode<T>*);
};