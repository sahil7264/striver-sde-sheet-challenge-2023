#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
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

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
     TreeNode<int>* curr = root;
    TreeNode<int>* Klargest = NULL;
    int count = 0;
    while (curr != NULL) {
        if (curr->right == NULL) {
            if (++count == k)
                Klargest = curr;
            curr = curr->left;
        }
        else {
            TreeNode<int>* succ = curr->right;
            while (succ->left != NULL && succ->left != curr)
                succ = succ->left;
            if (succ->left == NULL) {
                succ->left = curr;
                curr = curr->right;
            }
            else {
                succ->left = NULL;
                if (++count == k)
                    Klargest = curr;
                curr = curr->left;
            }
        }
    }
    if(Klargest==NULL) return -1;
    return Klargest->data;
}
