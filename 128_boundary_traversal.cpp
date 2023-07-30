#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int>* node){
  if(node->left == NULL && node->right==NULL){
    return true;
  }
  return false;
}

void addLeftBound(TreeNode<int> * root, vector<int>& ans){
  root = root->left;
  while(root){
    if(!isLeaf(root)) ans.push_back(root->data);
    if(root->left) root = root->left;
    else root = root->right;
  }
}

 
void addRightBound(TreeNode<int> * root, vector<int>& ans){
  root = root->right;
  stack<int> stk;
  while(root){
    if(!isLeaf(root)) stk.push(root->data);
    if(root->right) root = root->right;
    else root = root->left;
  }
  while(!stk.empty()){
    ans.push_back(stk.top());
    stk.pop();
  }
}
void addLeaves(TreeNode<int> * root, vector<int>& ans){
  if(root==NULL){
    return;
  }
  if(isLeaf(root)){
    ans.push_back(root->data); //just store leaf nodes
    return;
  }
  addLeaves(root->left,ans);
  addLeaves(root->right,ans);
}
 
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write yor code here.
    vector<int>ans;
     if(root==NULL) return ans;
     if(!isLeaf(root)) ans.push_back(root->data); 
     addLeftBound(root,ans);
     addLeaves(root,ans);
     addRightBound(root,ans);
}
