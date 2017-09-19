#pragma once
#include "cBstNode.h"

template <typename T>
class cBST
{
private:
	cBstNode<T>* pRoot;

public:
	cBST() { pRoot = NULL; }
	~cBST() {}

	void insert(T n)
	{
		if (pRoot)
			pRoot->insert(n);
		else
			pRoot = new cBstNode<T>(n);
	}

	void print()
	{
		pRoot->print();
	}

	void delete_data(T n)
	{
		if (pRoot)
		{
		   cBstNode<T>* tmpNode = pRoot->delete_data(n, &pRoot);
		   if (tmpNode) delete tmpNode;
		}
	}
};

