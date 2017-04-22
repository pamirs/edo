#include <cstddef>
#include "s.h"
#include <iostream>
#include <unordered_map>

using namespace std;

int searchPaths(unordered_map<int,int>& numPaths, TreeNode* node, int runningSum, int finalSum)
{
    int c = 0;
    if(node == NULL){
        return 0;
    }

    runningSum = runningSum + node->value;
    int x = runningSum - finalSum;

    if (numPaths.find(runningSum) == numPaths.end()){
        numPaths[runningSum] = 1;
    }else{
        numPaths[runningSum]++;
    }

    if (numPaths.find(x) != numPaths.end()){
        c = numPaths[x];
    }

    c += searchPaths(numPaths,node->left, runningSum, finalSum);
    c += searchPaths(numPaths,node->right, runningSum, finalSum);

    numPaths[runningSum]--;
    
    return c;
}


int findNumPaths(TreeNode* root, int sum)
{
    unordered_map<int,int> numPaths;
    if(root == NULL){
        return 0;
    }

    numPaths[0] = 1;
    return searchPaths(numPaths, root, 0, sum);
}
