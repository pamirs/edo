
#include <deque>
#include <list>
#include <string>

using namespace std;

struct TreeNode{
    string name;
    int    depth;
    TreeNode* children[2]; 
};

struct LinkListNode
{
    TreeNode* node;
    LinkListNode* next;
};

deque<list<TreeNode*>> createListsFromTree(TreeNode* tree)
{
    deque<list<TreeNode*>> lists;
    list<TreeNode*> * current;
    list<TreeNode*> * parent;

    lists.push_back(list<TreeNode*>());
    current = &lists.back();
    if(tree){
        current->push_back(tree);
    }   

    while(!current.empty()){
        parent = current;
        lists.push_back(list<TreeNode*>());
        current = &lists.back();

        for(auto it = parent.begin(); it!=parent.end(); ++it){
            if(*it.children[0]){
                current->push_back(*it.children[0]);
            }
            if(*it.children[0]){
                current->push_back(*it.children[0]);
            }
        }
    }

    return lists;
}





int createListsFromTree(TreeNode* tree, LinkedListNode** lists)
{
    //breadth-first
    deque<TreeNode*> q;
    int max_depth = 0; 
    tree->depth = 0;
    q.push_back(tree);

    while(!q.empty()){
        
        TreeNode* n = q.front();
        q.pop();

        if(n->depth + 1 > max_depth){
            max_depth = n->depth + 1;
        }

        LinkedListNode* node = lists[n->depth];
        LinkedListNode* prev = NULL;

        while(node!=NULL)
        {
            prev  = node;
            head = head->next;
        }
        
        node = new LinkedListNode();
        node->node = n;
        node->next = NULL;

        if(!prev){
           lists[n->depth] = node; 
        }

        if (n.children[0]){
            n.children[0]->depth = n.depth + 1;
            q.push_back(n.children[0]);
        }

        if(n.children[1]){
            n.children[1]->depth = n.depth + 1;
            q.push_back(n.children[1]);
        }
    }
    return max_depth;
}
