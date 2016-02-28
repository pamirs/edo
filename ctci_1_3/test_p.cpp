#include "cppunit/TestAssert.h"
#include <string>
#include <chrono>

std::string & urlify (std::string & str, int l);


void verifySolution()
{
    std::string str = "  s  fds sds          ";

    auto start = std::chrono::steady_clock::now();
    
    CPPUNIT_ASSERT(!strcmp(urlify(str, 12).c_str(), "%20%20s%20%20fds%20sds"));
	
    std::cout << str;   
 
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    std::cout << std::endl;
    std::cout << "Microseconds: " << std::chrono::duration <double,std::micro> (diff).count() << " us" << std::endl;

}




