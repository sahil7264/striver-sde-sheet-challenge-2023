#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/
void solve(vector<vector<int>>&ans,BinaryTreeNode<int>* root){
    if(root==NULL) return;
    ans[1].push_back(root->data);
    solve(ans,root->left);
    ans[0].push_back(root->data);
    solve(ans,root->right);
    ans[2].push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>>ans(3);
    solve(ans,root);
    return ans;
}