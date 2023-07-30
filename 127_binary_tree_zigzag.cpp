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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int>v;
    if (!root) return v;
    stack<BinaryTreeNode<int>*> currentlevel;
    stack<BinaryTreeNode<int>*> nextlevel;
    currentlevel.push(root);
    bool lefttoright = true;
    while (!currentlevel.empty()) {
        BinaryTreeNode<int>* temp = currentlevel.top();
        currentlevel.pop();
        if (temp) {
            v.push_back(temp->data);
            if (lefttoright) {
                if (temp->left)
                    nextlevel.push(temp->left);
                if (temp->right)
                    nextlevel.push(temp->right);
            }
            else {
                if (temp->right)
                    nextlevel.push(temp->right);
                if (temp->left)
                    nextlevel.push(temp->left);
            }
        }
 
        if (currentlevel.empty()) {
            lefttoright = !lefttoright;
            swap(currentlevel, nextlevel);
        }
    }
    return v;
}
