#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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
int cnt=0;
int kthSmallest(TreeNode<int> *root, int k)
{
    int count = 0;
 
    int ksmall = INT_MIN;
    TreeNode<int> *curr = root;
 
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            count++;
            if (count==k)
                ksmall = curr->data;
            curr = curr->right;
        }
        else
        {
            TreeNode<int> *pre = curr->left;
            while (pre->right != NULL && pre->right != curr)
                pre = pre->right;
            if (pre->right==NULL)
            {
                pre->right = curr;
                curr = curr->left;
            }
            else
            {
                pre->right = NULL;
 
                count++;
                if (count==k)
                    ksmall = curr->data;

                curr = curr->right;
            }
        }
    }
    return ksmall;
}