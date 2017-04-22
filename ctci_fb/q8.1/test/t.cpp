
#include "../s.h"
#include <iostream>

using namespace std;

void verifySolution()
{
    
    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(5);
    root->right->right->left = new TreeNode(3);
    root->right->right->right = new TreeNode(2);
    root->right->right->right->right = new TreeNode(1);


    root->right->left->left = new TreeNode(2);
    root->right->left->right = new TreeNode(1);
    root->right->left->right->left = new TreeNode(1);
    root->right->left->right->right = new TreeNode(2);

    cout << "Number of paths (3->(5,1->(2->(2,1->(1,2))))):  " << findNumPaths(root, 8) << endl;

}

