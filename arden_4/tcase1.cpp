#include "cppunit/TestAssert.h"
#include <string>
#include <chrono>
#include <vector>

using namespace std;
int findMissingInteger(vector<int>,vector<int>);

void verifySolution()
{
vector<int> a={1, 2, 3, 4, 5, 6, 7, 8};
vector<int> b={5, 7, 8, 1 ,3, 4, 6};

std::cout << findMissingInteger(a,b) << std::endl;



auto start = std::chrono::steady_clock::now();
    
	
	auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    std::cout << std::endl;
    std::cout << "Microseconds: " << std::chrono::duration <double,std::micro> (diff).count() << " us" << std::endl;

}




