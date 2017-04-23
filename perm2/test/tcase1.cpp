#include "cppunit/TestAssert.h"
#include <vector>
#include <string>
#include <chrono>

using namespace std;

vector<string> perm(string s);

inline int Factorial(int x) {
  return (x == 1 ? x : x * Factorial(x - 1));
}

void printList(vector<string> list)
{
	for (auto &&i : list){
		cout << i << endl;
	}
}

void verifySolution()
{
    vector<string> list;
    string s = "abcdef"; 

    auto start = std::chrono::steady_clock::now();
    
    list = perm(s);
    
    CPPUNIT_ASSERT(Factorial(s.length()) == list.size());

    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    std::cout << std::endl;

    printList(list);
    cout << "Microseconds: " << std::chrono::duration <double,std::micro> (diff).count() << " us" << std::endl;
    cout << "Number of permutations: " << list.size() << endl;
}




