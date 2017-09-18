#pragma once
//Single Linked List
#include "cNode.h"

template <typename T>
class cSLL
{
private:
	cNode<T>* Head;

public:
	cSLL() { Head = new cNode<T>(); }
	~cSLL() {}

	void insert_list(T data)
	{
		cNode<T>* newNode = new cNode<T>(data);

		if (Head->next == NULL)
		{
			Head->next = newNode;
			return;
		}

		cNode<T>* tmpNode = Head;
		while (tmpNode->next != NULL)
		{
			tmpNode = tmpNode->next;
		}

		tmpNode->next = newNode;
	}

	void clear()
	{
		if (Head->next == NULL) return;
		cNode<T>* tmpNode = Head->next;
		cNode<T>* d = NULL;
		while (tmpNode->next != NULL)
		{
			d = tmpNode->next;
			delete(tmpNode);
			tmpNode = d;
		}

		Head->next = NULL;
	}

	void reverse()
	{
		cNode<T>* tmpNode = Head->next;
		cNode<T>* q = NULL;
		cNode<T>* r;

		while (tmpNode != NULL)
		{
			r = q;
			q = tmpNode;
			tmpNode = q->next;
			q->next = r;
		}

		Head->next = q;
	}

	void delete_data(T data)
	{
		if (Head->next == NULL) return;

		cNode<T>* tmpNode = Head;
		while (tmpNode->next != NULL)
		{
			if (tmpNode->next->data == data)
			{
				cNode<T>* nextNode = tmpNode->next->next;
				delete(tmpNode->next);
				tmpNode->next = nextNode;

				return;
			}
			tmpNode = tmpNode->next;
		}
	}

	void delete_index(int index)
	{
		if (Head->next == NULL) return;

		//배열과 같이 0부터 시작한다면 ?
		cNode<T>* tmpNode = Head;
		for (int i = -1; i <= index; i++)
		{
			if ((index - 1) == i) 
			{
				cNode<T>* nextNode = tmpNode->next->next;
				delete(tmpNode->next);
				tmpNode->next = nextNode;

				return;
			}
			else tmpNode = tmpNode->next;
		}
	}

	void delete_first()
	{
		if (Head->next == NULL) return;

		cNode<T>* tmpNode = Head->next->next;
		delete(Head->next);
		Head->next = tmpNode;
	}

	void delete_last()
	{
		if (Head->next == NULL) return;

		cNode<T>* tmpNode = Head;
		while (tmpNode->next->next != NULL)
		{
			tmpNode = tmpNode->next;
		}

		delete(tmpNode->next->next);
		tmpNode->next = NULL;
	}

	cNode<T>* search(T data)
	{
		cNode<T>* tmpNode = Head;
		while (tmpNode->next != NULL)
		{
			tmpNode = tmpNode->next;
			if (tmpNode->data == data)
			{
				return tmpNode;
			}
		}

		cout << "찾으시는 자료가 없습니다." << endl;
		return NULL;
	}

	void display()
	{
		cNode<T>* tmpNode = Head;
		while (tmpNode->next != NULL)
		{
			tmpNode = tmpNode->next;
			cout << tmpNode->data << " -> ";
		}
		cout << endl;
	}
};

