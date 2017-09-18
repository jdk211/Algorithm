#pragma once
#include"cNode.h"

template <typename T>
class cCLL
{
private:
	cNode<T> * Head;

public:
	cCLL() { Head = new cNode<T>(); }
	~cCLL() {}

	void insert_first(T data)
	{
		cNode<T> * newNode = new cNode<T>(data);

		if (Head->next == NULL)
		{
			Head->next = newNode;
			newNode->next = newNode;
			return;
		}

		newNode->next = Head->next->next;
		Head->next->next = newNode;
	}
	
	void insert_list(T data) //last
	{
		cNode<T> * newNode = new cNode<T>(data);

		if (Head->next == NULL)
		{
			Head->next = newNode;
			newNode->next = newNode;
			return;
		}

		newNode->next = Head->next->next;
		Head->next->next = newNode;
		Head->next = newNode;
	}

	void delete_first()
	{
		if (Head->next == NULL) return;

		cNode<T>* tmpNode = NULL;
		tmpNode = Head->next->next->next;
		delete(Head->next->next);
		Head->next->next = tmpNode;
	}

	void delete_last()
	{
		if (Head->next == NULL) return;

		cNode<T>* tmpNode = Head->next->next; //ù��°
		while (tmpNode->next != Head->next)
		{
			tmpNode = tmpNode->next;
		}

		tmpNode->next = tmpNode->next->next; //������� ���� �ּ� �Ѱ��ֱ�

		delete(Head->next); //����
		
		Head->next = tmpNode; //����� ��ġ ����
	}

	void display()
	{
		if (Head->next == NULL) return;

		cNode<T>* tmpNode = Head->next->next;

		while (Head->next != tmpNode)
		{
			cout << tmpNode->data << " -> ";
			tmpNode = tmpNode->next;
		}
		cout << tmpNode->data << endl;
	}
};

