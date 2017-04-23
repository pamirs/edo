#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<string> perm(std::string s, string prefix);

vector<string> perm(std::string s){
    return perm(s, string());
}


vector<string> perm(string s, string prefix)
{
    vector<string> ret;
    if (s.length() == 0){
        return ret;
    }
    if ((int)s.length() == 1){
        ret.push_back(prefix + s);
        return ret;
    }

    string tmp ;
    for(int i=0; i < (int)s.length(); i++){
        tmp = s;
        vector<string> v = perm(tmp.erase(i,1), prefix + s.at(i));
        ret.insert(ret.end(), v.begin(), v.end());
    }

    return ret;
}



