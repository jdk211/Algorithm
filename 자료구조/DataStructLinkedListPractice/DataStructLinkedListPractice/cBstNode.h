#pragma once

template <typename T>
class cBstNode
{
public:
	T data;
	cBstNode<T>* pLChild;
	cBstNode<T>* pRChild;

public:
	cBstNode() {}
	~cBstNode() {}

	cBstNode(T _data)
		: data(_data)
		, pLChild(NULL)
		, pRChild(NULL)
	{}

	void insert(T n)
	{
		if (n < data)
		{
			if (pLChild)
				pLChild->insert(n);
			else
				pLChild = new cBstNode(n);
		}
		else if(n > data)
		{
			if (pRChild)
				pRChild->insert(n);
			else
				pRChild = new cBstNode(n);
		}
	}

	void print()
	{
		if (pLChild)
		{
			pLChild->print();
		}

		cout << data << " -> ";

		if (pRChild)
		{
			pRChild->print();
		}
	}

	cBstNode<T>* delete_data(int n, cBstNode<T>** ppThis)
	{
		if (n < data)
		{
			if (pLChild == NULL) return NULL;
			else pLChild->delete_data(n, &pLChild);
		}
		else if (n > data)
		{
			if (pRChild == NULL) return NULL;
			else pRChild->delete_data(n, &pRChild);
		}
		else
		{
			if (pLChild == NULL && pLChild == NULL)
			{
				*ppThis = NULL;
				return this;
			}
			else if (pLChild != NULL && pRChild == NULL)
			{
				*ppThis = pLChild;
				return this;
			}
			else if (pLChild == NULL && pRChild != NULL)
			{
				*ppThis = pRChild;
				return this;
			}
			else
			{
				cBstNode<T>* pMinRightNode = pRChild->GetMinNode();
				data = pMinRightNode->data;
				return pRChild->delete_data(data, &pRChild);
			}
		}

		return NULL;
	}

	cBstNode<T>* GetMinNode()
	{
		if (pLChild)
		{
			return pLChild->GetMinNode();
		}

		return this;
	}
};

