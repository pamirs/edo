#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findMissingInteger(vector<int> full, vector<int>partial)
{
    unordered_map<int,int>::iterator it;
    unordered_map<int,int> lookup;

    for(int i=0;i<partial.size();i++){
        lookup[partial[i]]=1;
    }

    for(int i = 0; i < full.size(); i++){
        it = lookup.find(full[i]);

        if(it == lookup.end()){
            return full[i];
        }
    }

    return -1;
}



