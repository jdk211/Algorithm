#pragma once
#include "cNode.h"

template<typename T>
class cQueue
{
private:
	cNode<T>* front;
	cNode<T>* rear;

public:
	cQueue() 
	{
		front = new cNode<T>();
		rear = new cNode<T>();
		front->next = NULL;
		rear->next = NULL;
	}
	~cQueue() {}

	void enqueue(T _data)
	{
		cNode<T>* newNode = new cNode<T>(_data);

		if (front->next == NULL) 
		{
			front->next = newNode;
			rear->next = newNode;
			return;
		}

		rear->next->next = newNode;
		rear->next = newNode;
	}

	T dequeue()
	{
		//if (front->next == NULL) return exit(1);
		T tmpData = front->next->data;

		cNode<T>* tmpNode = front->next->next;
		delete(front->next);
		front->next = tmpNode;

		return tmpData;
	}
};

