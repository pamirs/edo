#ifndef SOLUTION_H
#define SOLUTION_H
#include <stdlib.h>
struct Node
{
	Node* Next;
	int Number;

	Node() : Next(NULL), Number(0)
	{
	}
};



void addNumbers(Node* n1, Node* n2, Node** sum);
#endif
