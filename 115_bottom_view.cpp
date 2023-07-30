#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){

    if(root==NULL) return {};
    queue<pair<BinaryTreeNode<int>*,int>>dq;
    dq.push({root, 0});
    map<int,int>mpp;
    while(!dq.empty()){
        BinaryTreeNode<int> *tmp = dq.front().first;
        int level = dq.front().second;
        mpp[level]=tmp->data;
        dq.pop();
        if(tmp->left!=NULL) dq.push({tmp->left,level-1});
        if(tmp->right!=NULL) dq.push({tmp->right,level+1});
    }
    vector<int>v;
    for(auto it :mpp) v.push_back(it.second);
    return v; 
}
