#include "cppunit/TestAssert.h"
#include <string>
#include <chrono>
#include "mstack.hpp"

using namespace ctci;

void verifySolution()
{
StackWithMin<int> stack;

stack.push(5);
CPPUNIT_ASSERT(stack.top() == 5);
CPPUNIT_ASSERT(stack.min() == 5);
stack.push(4);
CPPUNIT_ASSERT(stack.top() == 4);
CPPUNIT_ASSERT(stack.min() == 4);
stack.push(5);
CPPUNIT_ASSERT(stack.top() == 5);
CPPUNIT_ASSERT(stack.min() == 4);
stack.push(2);
CPPUNIT_ASSERT(stack.top() == 2);
CPPUNIT_ASSERT(stack.min() == 2);
stack.pop();
CPPUNIT_ASSERT(stack.top() == 5);
CPPUNIT_ASSERT(stack.min() == 4);
stack.push(3);
CPPUNIT_ASSERT(stack.top() == 3);
CPPUNIT_ASSERT(stack.min() == 3);
stack.push(4);
CPPUNIT_ASSERT(stack.top() == 4);
CPPUNIT_ASSERT(stack.min() == 3);
stack.push(1);
CPPUNIT_ASSERT(stack.top() == 1);
CPPUNIT_ASSERT(stack.min() == 1);
stack.pop();
CPPUNIT_ASSERT(stack.top() == 4);
CPPUNIT_ASSERT(stack.min() == 3);
stack.pop();
CPPUNIT_ASSERT(stack.top() == 3);
CPPUNIT_ASSERT(stack.min() == 3);
stack.pop();
CPPUNIT_ASSERT(stack.top() == 5);
CPPUNIT_ASSERT(stack.min() == 4);
stack.pop();
CPPUNIT_ASSERT(stack.top() == 4);
CPPUNIT_ASSERT(stack.min() == 4);
stack.pop();
CPPUNIT_ASSERT(stack.top() == 5);
CPPUNIT_ASSERT(stack.min() == 5);
stack.push(2);
stack.push(3);
stack.push(2);
stack.push(3);
CPPUNIT_ASSERT(stack.top() == 3);
CPPUNIT_ASSERT(stack.min() == 2);
stack.pop();
CPPUNIT_ASSERT(stack.top() == 2);
CPPUNIT_ASSERT(stack.min() == 2);
stack.pop();
CPPUNIT_ASSERT(stack.top() == 3);
CPPUNIT_ASSERT(stack.min() == 2);
stack.pop();
CPPUNIT_ASSERT(stack.top() == 2);
CPPUNIT_ASSERT(stack.min() == 2);
stack.pop();
CPPUNIT_ASSERT(stack.top() == 5);
CPPUNIT_ASSERT(stack.min() == 5);

auto start = std::chrono::steady_clock::now();
    
	
	auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    std::cout << std::endl;
    std::cout << "Microseconds: " << std::chrono::duration <double,std::micro> (diff).count() << " us" << std::endl;

}




