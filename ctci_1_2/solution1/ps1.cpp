#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPerm(string s1, string s2)
{
    if (s1.size() != s2.size())
        return false;

    sort(s1.begin(), s1.end());

    sort(s2.begin(), s2.end());


    if(s1.compare(s2) == 0)
        return true;
    else
        return false;
    
}
