#include "s.h"
#include <set>
#include <deque>


void getAllSubsets(std::set<int> s, std::deque<std::set<int>> &subsets)
{
    std::set<int>::iterator it;

    if (s.empty()){
        return;
    }
    for (it=s.begin(); it!=s.end(); ++it){
        subsets.emplace_back(s.begin(), std::next(it,1));
    }
    
    it = s.begin();

    getAllSubsets(std::set<int>(std::next(it,1), s.end()), subsets);
}


