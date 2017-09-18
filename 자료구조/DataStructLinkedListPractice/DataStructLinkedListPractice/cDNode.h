#pragma once
// 이중 연결 노드
template <typename T>
class cDNode
{
public:
	T data;
	cDNode<T>* left;
	cDNode<T>* right;

public:
	cDNode() { left = NULL; right = NULL; }
	~cDNode() {}

	cDNode(T _data)
		: data(_data)
	{
	}
};

