#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int>v;
    queue<pair<TreeNode<int>*,int>>dq;
    dq.push({root,0});
    map<int,vector<int>>mpp;
    while(!dq.empty()){
        TreeNode<int>*t = dq.front().first;
        int level = dq.front().second;
        dq.pop();
        mpp[level].push_back(t->data);
        if(t->left!=NULL) dq.push({t->left,level-1});
        if(t->right!=NULL) dq.push({t->right,level+1});
    }
    for(auto it :mpp){
        for(auto ele: it.second){
            v.push_back(ele);
        }
    }
    return v;
}