#include "cppunit/TestAssert.h"
#include <string>
#include <chrono>

extern bool isPerm(std::string  str1, std::string  str2);


void verifySolution()
{
    CPPUNIT_ASSERT(isPerm(std::string("sdfhgfgdfsgsdfgdsfg"),std::string("sdfhgdfgdfsgfdsgdfsgdfs"))  == false);
    CPPUNIT_ASSERT(isPerm(std::string("abcdef"),std::string("dcabef"))  == true);
    CPPUNIT_ASSERT(isPerm(std::string("abcdef"),std::string("abcdeh")) == false);
    CPPUNIT_ASSERT(isPerm(std::string("$5^^jdfsg:"),std::string("$5^^jdfsg"))  == false);
    CPPUNIT_ASSERT(isPerm(std::string("      "),std::string("sdfhgf"))  == false);
    
    
    std::string str="abcdefgh";
    std::string str2;

    for(int j=0; j<10000; j++)
        str2.append(str);

    auto start = std::chrono::steady_clock::now();
    
    for(int i =0; i< 1000; i++){
        CPPUNIT_ASSERT(isPerm(str2,str2)  == true);
    }

    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    std::cout << std::endl;
    std::cout << "Microseconds: " << std::chrono::duration <double,std::micro> (diff).count() << " us" << std::endl;



}




