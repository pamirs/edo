#include <cppunit/TestCase.h>
#include <cppunit/ui/text/TestRunner.h>

extern void verifySolution();

class MyTestCase : public CppUnit::TestCase { 
public: 
  MyTestCase( std::string name ) : CppUnit::TestCase( name ) {}
  
  void runTest() {
    verifySolution();
  }

};


int main( int argc, char **argv)
{
    MyTestCase * test = new MyTestCase("Test");

   // test->runTest();


    CppUnit::TextUi::TestRunner runner;
    runner.addTest( test);
    runner.run();
}

 
