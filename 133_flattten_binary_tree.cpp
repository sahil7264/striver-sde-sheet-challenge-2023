#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

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
TreeNode<int>* solve(TreeNode<int>* &root){
  
  TreeNode<int>* left = root->left;
  TreeNode<int>* right = root->right;
  TreeNode<int>* tmp = root;
  if(left!=NULL){
      root->right = solve(left);
      while(root->right!=NULL) root=root->right;
  }
  if(right!=NULL){
      root->right = solve(right);
  }
    root->left = NULL;
  return tmp;
}
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    return solve(root);
}