
#include <iostream>
#include <string>

using namespace std;

bool isPerm(string s1, string s2)
{
    int lookup[256]={0};
       
    if(s1.size() != s2.size())
        return false;

    
    for(int i=0; i<s1.size(); i++)
        lookup[s1.at(i)]++;

    for(int j=0; j<s2.size(); j++)
        if( lookup[s2.at(j)]-- == 0)
            return false;

    return true;

}   
