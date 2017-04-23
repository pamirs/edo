#include <vector>
#include <string>
#include "../s.h"
#include <iostream>

using namespace std;

void verifySolution()
{
    string s = "12345";

    vector<string> perms = getAllPerms(s);
    
    int len = perms.size();
    for(int i = 0; i < len; i++){
        cout << perms[i] << endl;
    
    }
}

