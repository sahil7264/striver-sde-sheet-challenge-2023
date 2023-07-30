#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

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

bool validateBST(BinaryTreeNode<int> *root,int min=INT_MIN,int max=INT_MAX) {
    // Write your code here
      if (root == NULL)
    {

        return true;
    }

    if (root->data >= min && root->data <= max)
    {

        bool left = validateBST(root->left, min, root->data);

        bool right = validateBST(root->right, root->data, max);

        return left && right;
    }

    else
    {

        return false;
    }
}