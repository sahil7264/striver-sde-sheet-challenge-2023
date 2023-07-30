#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
  long long int dfs(TreeNode<int>* root,long long int &ans){
        if(!root){
            return 0;
        }
        long long int  lMax=dfs(root->left,ans);
        long long int  rMax=dfs(root->right,ans);
        ans=max(ans,root->val+lMax+rMax);
        return root->val+max(lMax,rMax);
    }
long long int findMaxSumPath(TreeNode<int> *root)
{
    if(root==NULL) return -1;
    if(root->left==NULL) return -1;
    if(root->right==NULL) return -1;
    long long int  ans=INT_MIN;
        dfs(root,ans);
        return ans;
}