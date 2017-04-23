#include <cstddef>
#include <unordered_map>
struct TreeNode{
    TreeNode(int val) : value(val), left(nullptr), right(nullptr)
    {
    }
    int value;
    TreeNode* left;
    TreeNode* right;
};


int findNumPaths(std::unordered_map<int,int> numPaths, TreeNode* root, int sum);
