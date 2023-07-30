#include <bits/stdc++.h> 
/************************************************************
    Following is the TreeNode class structure
    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getLeftView(TreeNode<int> *root)
{
    if(root==NULL) return {};
    map<int,int>mpp;
    queue<pair<TreeNode<int>*,int>>dq;
    dq.push({root, 1});
    while(!dq.empty()){
        TreeNode<int> *tmp = dq.front().first;
        int level = dq.front().second;
        if(!mpp[level]) mpp[level] = tmp->data; 
        dq.pop();
        if(tmp->left!=NULL) dq.push({tmp->left,level+1});
        if(tmp->right!=NULL) dq.push({tmp->right,level+1});
    }
    vector<int>v;
    for(auto it :mpp) v.push_back(it.second);
    return v;
}