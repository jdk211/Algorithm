#pragma once
#include "cNode.h"
#include "ITEM.h"

template <typename T>
class cStack
{
private:
	cNode<T>* Top;

public:
	cStack() { Top = new cNode<T>(); }
	~cStack() {}

	bool isEmpty()
	{
		return (Top->next == NULL);
	}

	void push(T data)
	{
		cNode<T>* newNode = new cNode<T>(data);

		newNode->next = Top->next;
		Top->next = newNode;
	}

	T pop()
	{
		if (isEmpty()) exit(1);

		cNode<T>* tmp = Top->next;
		T item = Top->next->data;

		Top->next = tmp->next;

		delete(tmp);

		return item;
	}
};

