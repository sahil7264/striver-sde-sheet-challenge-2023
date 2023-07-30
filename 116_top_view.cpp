#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
     if(root==NULL) return {};
    queue<pair<TreeNode<int>*,int>>dq;
    dq.push({root, 0});
    map<int,int>mpp;
    while(!dq.empty()){
        TreeNode<int> *tmp = dq.front().first;
        int level = dq.front().second;
        if(!mpp[level]) mpp[level]=tmp->val;
        dq.pop();
        if(tmp->left!=NULL) dq.push({tmp->left,level-1});
        if(tmp->right!=NULL) dq.push({tmp->right,level+1});
    }
    vector<int>v;
    for(auto it :mpp) v.push_back(it.second);
    return v; 
}