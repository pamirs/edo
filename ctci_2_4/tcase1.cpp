#include "cppunit/TestAssert.h"
#include <string>
#include <chrono>

struct Node{
	int d;
	Node* next;
};

int partitionList (Node** list, int val); 

void checkPartition(int value, Node *list)
{
	Node *tmp = list;
	int count = 0;
	while(tmp!=NULL && tmp->d < value){
		tmp = tmp->next;
	}
	while(tmp!=NULL){
		CPPUNIT_ASSERT(tmp->d>=value);
		tmp = tmp->next;
	}
}

void printList(Node *list)
{
Node* tmp = list;
std::cout << "List:" << std::endl;
while(tmp!=NULL){
	std::cout << tmp->d << " "; 
	tmp=tmp->next;
}
std::cout << "\n\n";
}

void verifySolution()
{
	Node*list = new Node();
	Node *tmp = list;
	tmp->d = 3;
	tmp->next = new Node();
	tmp = tmp->next;
	tmp->d = 6;
	tmp->next = new Node();
	tmp = tmp->next;
	tmp->d = 3;
	tmp->next = new Node();
	tmp = tmp->next;
	tmp->d = 4;
	tmp->next = new Node();
	tmp = tmp->next;
	tmp->d = 5;
	tmp->next = new Node();
	tmp = tmp->next;
	tmp->d = 3;
	tmp->next = NULL;

    auto start = std::chrono::steady_clock::now();
    
	partitionList(&list, 5);
	printList(list);
	partitionList(&list, 4);
	printList(list);
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    std::cout << std::endl;
    std::cout << "Microseconds: " << std::chrono::duration <double,std::micro> (diff).count() << " us" << std::endl;

	checkPartition(4,list);
}




