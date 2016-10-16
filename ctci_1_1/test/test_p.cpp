#include "cppunit/TestAssert.h"
#include <string>
#include <chrono>

extern bool isUnique(const std::string & str);


void verifySolution()
{
    CPPUNIT_ASSERT(isUnique(std::string("sdfhgf"))  == false);
    CPPUNIT_ASSERT(isUnique(std::string("abcdef"))  == true);
    CPPUNIT_ASSERT(isUnique(std::string("aaaaaaaa")) == false);
    CPPUNIT_ASSERT(isUnique(std::string("$5^^jdfsg:"))  == false);
    CPPUNIT_ASSERT(isUnique(std::string("      "))  == false);
    
    
    CPPUNIT_ASSERT(isUnique(std::string("asd jbv ert"))  == false);

    auto start = std::chrono::steady_clock::now();
   
    CPPUNIT_ASSERT(isUnique(std::string("1234567890 sdfgpo"))  == true);

    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    std::cout << std::endl;
    std::cout << "Microseconds: " << std::chrono::duration <double,std::micro> (diff).count() << " us" << std::endl;



}




