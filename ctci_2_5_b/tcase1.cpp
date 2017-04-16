#include "cppunit/TestAssert.h"
#include <vector>
#include <string>
#include <chrono>
#include "../solution.h"

using namespace std;

void printNode(Node* list)
{
	if(list!=NULL){
		printNode(list->Next);
		cout << list->Number;
	}
}


Node* makeList(int n)
{
	Node * list = (Node*) malloc(sizeof(Node));
	Node * tmp = list;
	int t = n;

	while(t > 10){
	   int t1  = t / 10;
	   tmp->Number = t - t1*10;
	   t = t1;
	   tmp = tmp->Next = (Node*)malloc (sizeof(Node));
	}
 	
	tmp->Number = t;
	tmp->Next = NULL;

	return list;
}



void verifySolution()
{
    Node* n1 = makeList(34435);
    Node* n2 = makeList(244);
    Node* sum = NULL;

    auto start = std::chrono::steady_clock::now();
    
    addNumbers(n1,n2,&sum);
    

    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    std::cout << std::endl;


    // CPPUNIT_ASSERT(Factorial(s.length()) == list.size());
    
    cout << "Microseconds: " << std::chrono::duration <double,std::micro> (diff).count() << " us" << std::endl;
    cout << "Sum: " << endl;
    printNode(n1);
    cout << " + ";
    printNode(n2);
    cout << endl;
    printNode(sum);
}




