#include "s.h"

using std::vector;
using std::string;

vector<string> getAllPerms(string s)
{
    vector<string> perms;

    int len = s.length();

    if(len == 0){
        return vector<string>();
    }

    for(int i = 0; i < len; i++){
        perms.emplace_back(s.substr(0,i + 1));
    }

    vector<string> tmp = getAllPerms(s.substr(1,len-1));

    perms.insert(perms.end(), tmp.begin(), tmp.end());

    return perms;
}

