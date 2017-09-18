#pragma once
#include "ITEM.h"

template <typename T>
class cNode
{
public:
	T data;
	cNode* next;

public:
	cNode() { next = NULL; }
	~cNode() {}

	cNode(T _data, cNode* _next = NULL)
		: data(_data), next(_next)
	{

	}
};

