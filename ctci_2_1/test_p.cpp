#include "cppunit/TestAssert.h"
#include <string>
#include <chrono>

struct Node{
	int d;
	Node* next;
};

void remDuplicates (Node** list); 

void checkValueCount(int value, Node *list)
{
	 Node *tmp = list;
	 int count = 0;
	 while(tmp!=NULL){
		if( value == tmp->d){
			CPPUNIT_ASSERT(count++ == 0);
		}
		
		tmp = tmp->next;
	 }
}

void verifySolution()
{
	Node*list = new Node();
	Node *tmp = list;
	tmp->d = 3;
	tmp->next = new Node();
	tmp = tmp->next;
	tmp->d = 5;
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
    
	 remDuplicates(&list);

    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    std::cout << std::endl;
    std::cout << "Microseconds: " << std::chrono::duration <double,std::micro> (diff).count() << " us" << std::endl;

checkValueCount(3,list);
checkValueCount(5,list);
checkValueCount(4,list);
}




