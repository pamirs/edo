#include "cppunit/TestAssert.h"
#include <string>
#include <chrono>



void verifySolution()
{
    auto start = std::chrono::steady_clock::now();
   
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    std::cout << std::endl;
    std::cout << "Microseconds: " << std::chrono::duration <double,std::micro> (diff).count() << " us" << std::endl;

}




