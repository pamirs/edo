#include "cppunit/TestAssert.h"
#include <vector>
#include <string>
#include <chrono>
#include "../solution.h"

using namespace std;

void printNode(Node* list)
{
	if(list!=NULL){
		cout << list->Number;
		printNode(list->Next);
	}
}


Node* makeList(int n, int d)
{
	Node * list = new Node();
	Node * tmp = list;


        if(n < 10){
             list->Number = n;
             list->Next = NULL;
        }else{
             list->Number = n/d;  
             list->Next = makeList( n % d, d / 10);
        }
         
	return list;
}



void verifySolution()
{
    Node* n1 = makeList(344,100);
    Node* n2 = makeList(244,100);
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




