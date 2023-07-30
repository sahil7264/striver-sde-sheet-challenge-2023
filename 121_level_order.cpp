#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    if(root==NULL) return {};
    //  Write your code here.
    queue<BinaryTreeNode<int>*>dq;
	vector<int>v;
    dq.push(root);
    while(!dq.empty()){
        BinaryTreeNode<int>*t = dq.front();
        dq.pop();
		v.push_back(t->val);
        if(t->left!=NULL) dq.push(t->left);
        if(t->right!=NULL) dq.push(t->right);
    }
    return v;
}