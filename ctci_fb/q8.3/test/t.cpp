#include <set>
#include <deque>
#include "../s.h"
#include <iostream>

using namespace std;

void verifySolution()
{
    int a[]={1,2,3,4,5};

    set<int> s(a, a+5);

    deque<set<int>> subsets;
    getAllSubsets(s,subsets);
    
    while(!subsets.empty()){
        set<int> & s1 = subsets.front();
        for (auto it=s1.begin(); it!=s1.end(); ++it){
            cout << *it << " ";
        }
        cout << endl;
        subsets.pop_front();
    }
}

