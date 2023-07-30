#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *root, int input){
     if (root == NULL)
        return -1;
    if (root->data == input)
        return root->data;
    if (root->data < input)
        return findCeil(root->right, input);
    int ceil = findCeil(root->left, input);
    return (ceil >= input) ? ceil : root->data;
}