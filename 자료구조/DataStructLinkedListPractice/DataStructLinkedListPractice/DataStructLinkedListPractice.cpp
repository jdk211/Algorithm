// DataStructLinkedListPractice.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
// 자료구조 List 공부
// 단순 연결, 원형 연결, 이중 연결 

#include "stdafx.h"
#include "cSLL.h"
#include "cCLL.h"
#include "cDLL.h"
#include "cStack.h"
#include "cQueue.h"
#include "ITEM.h" // 전역 struct를 가짐

#include <iostream>

using namespace std;

void sll();
void cll();
void dll();
void stack();
void queue();

// 미로탈출 함수
void escape();
void escape_print(char miro[][6]);
void escape_Calc(char miro[][6], int row, int col, cStack<element>* routeStack, cStack<element>* backStack);
bool block_search(char miro[][6], int row, int col);
//

int main()
{
	//sll();
	//cll();
	//dll();
	//stack();
	//escape();
	//queue();



    return 0;
}

void sll()
{
	cSLL<int> *SLL = new cSLL<int>();

	SLL->insert_list(1);
	SLL->insert_list(2);
	SLL->insert_list(3);
	SLL->insert_list(4);
	SLL->insert_list(5);

	//SLL->delete_data(1);
	//SLL->delete_index(0);
	//SLL->delete_first();
	//SLL->delete_last();
	//SLL->reverse();
	//SLL->clear();

	SLL->display();

	//cNode<int> *tmpdata = SLL->search(3);
	//cout << tmpdata->data << endl;
}

void cll()
{
	cCLL<int>* cll = new cCLL<int>();

	cll->insert_list(1);
	cll->insert_list(2);
	cll->insert_list(3);
	cll->insert_list(4);
	cll->insert_list(5);
	cll->insert_first(0);
	cll->delete_first();
	cll->delete_last();

	cll->display();
}

void dll()
{
	cDLL<int>* dll = new cDLL<int>();

	dll->insert_last(0);
	dll->insert_last(1);
	dll->insert_last(2);
	dll->insert_last(3);
	dll->insert_first(4);
	dll->delete_last();

	dll->display();
}

void stack()
{
	cStack<int>* stack = new cStack<int>();
	
	stack->push(1);
	stack->push(2);
	stack->push(3);
	stack->push(5);

	cout << stack->pop() << endl;
	cout << stack->pop() << endl;
}

void queue()
{
	cQueue<int>* queue = new cQueue<int>();
	queue->enqueue(1);
	queue->enqueue(2);
	queue->enqueue(3);

	cout << queue->dequeue() << endl;
	cout << queue->dequeue() << endl;
	cout << queue->dequeue() << endl;
}

// 미로탈출 알고리즘
#pragma region escape_cave

void escape()
{
	char miro[6][6] =
	{
		{ '1', '1', '1', '1', '1', '1' },
		{ 'e', '0', '0', '0', '0', '1' },
		{ '1', '0', '1', '1', '1', '1' },
		{ '1', '0', '0', '0', '1', '1' },
		{ '1', '0', '1', '0', '0', '3' },
		{ '1', '1', '1', '1', '1', '1' },
	};

	// 입구{1, 0}, 출구{4, 5}, 현 위치{1, 0}
	element entry = { 1, 0 };
	element exit = { 4, 5 };
	element cur = { 1, 0 };

	cStack<element>* routeStack = new cStack<element>();
	cStack<element>* backStack = new cStack<element>();		//다시 뒤로 돌아가는 길을 가진다.

	int dumy = 0;

	while (cur.r != exit.r || cur.c != exit.c)
	{
		escape_print(miro);
		cin >> dumy;
		system("cls");

		int r = cur.r;
		int c = cur.c;

		escape_Calc(miro, r - 1, c, routeStack, backStack);	//위
		escape_Calc(miro, r + 1, c, routeStack, backStack);	//아래
		escape_Calc(miro, r, c + 1, routeStack, backStack);	//왼쪽
		escape_Calc(miro, r, c - 1, routeStack, backStack);	//오른쪽

		if (routeStack->isEmpty()) return;
		else
		{
			if (cur.r == entry.r && cur.c == entry.c)
				miro[cur.r][cur.c] = '4';
			else
			{
				miro[cur.r][cur.c] = '.';
				backStack->push(cur);
			}

			if (block_search(miro, r, c) && (cur.r != exit.r && cur.c != exit.c))
			{
				while (!backStack->isEmpty())
				{
					cout << "back " << endl;
					miro[cur.r][cur.c] = '.';

					cur = backStack->pop();

					miro[cur.r][cur.c] = 'e';

					escape_print(miro);
					cin >> dumy;
					system("cls");
				}
				miro[cur.r][cur.c] = '.';
			}

			cur = routeStack->pop();

			miro[cur.r][cur.c] = 'e';
		}
	}

	escape_print(miro);
	cout << "탈출 성공" << endl;
}

void escape_print(char miro[][6])
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << miro[i][j] << " ";
		}
		cout << endl;
	}
}

void escape_Calc(char miro[][6], int row, int col, cStack<element>* routeStack, cStack<element>* backStack)
{
	if (row < 0 || col < 0) return;
	else if (miro[row][col] == '0' || miro[row][col] == '3')
	{
		element tmpElement;
		tmpElement.r = row;
		tmpElement.c = col;

		routeStack->push(tmpElement);
	}
}

bool block_search(char miro[][6], int row, int col)
{
	if (row == 0 || col == 0) return false;

	if (miro[row + 1][col] != '0' &&
		miro[row - 1][col] != '0' &&
		miro[row][col + 1] != '0' &&
		miro[row][col - 1] != '0')
		return true;

	return false;
}

#pragma endregion
