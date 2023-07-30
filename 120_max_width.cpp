#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int getMaxWidth(TreeNode<int> *root)
{
    if(root==NULL) return 0;
    vector<int>v;
    queue<pair<TreeNode<int>*,int>>dq;
    dq.push({root,1});
    map<int,int>mpp;
    int maxi = 1;
    while(!dq.empty()){
        TreeNode<int>*t = dq.front().first;
        int level = dq.front().second;
        dq.pop();
        mpp[level]++;
        if(t->left!=NULL) dq.push({t->left,level+1});
        if(t->right!=NULL) dq.push({t->right,level+1});
    }
    for(auto it : mpp) maxi= max(maxi,it.second);
    return maxi;
}