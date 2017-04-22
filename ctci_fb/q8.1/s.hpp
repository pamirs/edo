#include <cstddef>

struct TreeNode{
    TreeNode(int val) : value(val), left(nullptr), right(nullptr)
    {
    }
    int value;
    TreeNode* left;
    TreeNode* right;
};


int findNumPaths(TreeNode* root, int sum);
