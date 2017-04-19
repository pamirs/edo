#include <cstddef>
#include "s.h"
#include <iostream>

using namespace std;

int searchPaths(TreeNode* node, int runningSum, int finalSum)
{
    int c = 0;
    if(node == NULL){
        return 0;
    }

    runningSum = runningSum + node->value;
   
    if(runningSum == finalSum){
        c += 1;
    }

    c += searchPaths(node->left, runningSum, finalSum);
    c += searchPaths(node->right, runningSum, finalSum);
    
    return c;
}


int findNumPaths(TreeNode* root, int sum)
{
    int count = 0;

    if(root == NULL){
        return 0;
    }


    count += searchPaths(root, 0, sum);

    count += findNumPaths(root->left, sum);
    count += findNumPaths(root->right, sum);

    return count;
}
