#pragma once
// ���� ���� ����Ʈ
#include"cDNode.h"
template<typename T>
class cDLL
{
private:
	cDNode<T>* Head;

private:
	void init()
	{
		Head = new cDNode<T>();
		Head->left = Head;
		Head->right = Head;
	}

public:
	cDLL() { init(); }
	~cDLL() {}

	void insert_last(T data) // �������� ����
	{
		cDNode<T>* newNode = new cDNode<T>(data);
		
		newNode->right = Head;
		newNode->left = Head->left;
		Head->left->right = newNode;
		Head->left = newNode;
	}

	void insert_first(T data) // �������� ����
	{
		cDNode<T>* newNode = new cDNode<T>(data);

		newNode->left = Head;
		newNode->right = Head->right;
		Head->right->left = newNode;
		Head->right = newNode;
	}

	void delete_last()
	{
		if (Head->left == Head && Head->right == Head) return;

		cDNode<T>* tmpNode = Head->left;
		Head->left = Head->left->left;
		Head->left->right = Head;

		delete(tmpNode);
	}

	void display()
	{
		cDNode<T>* tmpNode = Head->right;

		while (tmpNode != Head)
		{
			cout << tmpNode->data << " -> ";
			tmpNode = tmpNode->right;
		}
		cout << endl;
	}
};

