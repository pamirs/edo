#include <string>

using namespace std;



bool isOneOrZeroEditsAway(string s1, string s2)
{
    // insert/remove/replace 
    
    if (!s1.compare(s2)){
        return true;
    }
    
    //check for insert
    if ( s1.length() + 1 == s2.length())
        for (int i = 0; i < s2.length(); i++)
        {
            string tmp = s2;
            tmp.remove(i);
            if(!s1.compare(tmpS1))
            {
                return true;
            }
        }

    //check for remove
    if ( s1.length() == s2.length() + 1)
        for (int i = 0; i < s1.length(); i++)
        {
            string tmp = s1;
            tmp.remove(i);
            if(!s2.compare(tmp))
            {
                return true;
            }
        }

    //check for replace
    if(s1.length() == s2.length())
        for (int i = 0; i < s1.length(); i++)
        {
            string tmp1 = s1;
            string tmp2 = s2;
            if (!tmp1.erase(i,1).compare(tmp2.erase(i,1))){
                return true;
            }

        }

    return false;

}


bool checkRemove(string s1, string s2)
{
    if ( s1.length() + 1 == s2.length())
        for (int i = 0; i < s2.length(); i++)
        {
            string tmp = s2;
            tmp.remove(i);
            if(!s1.compare(tmp))
            {
                return true;
            }
        }
    return false;
}


bool isOneOrZeroEditsAway2(string s1, string s2)
{
    // insert/remove/replace 
    
    if (!s1.compare(s2)){
        return true;
    }
    
    //check for insert
    if(checkRemove(s2,s1)){
        return true;
    }

    //check for remove
    if(checkRemove(s1,s2)){
        return true;
    }

    //check for replace
    if(s1.length() == s2.length())
    {
        int mismatchCount = 0;
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] != s2[i] && ++mismatchCount > 1){
                return false;
            }
        }
        return true;
    }

    return false;
}
