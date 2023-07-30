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
TreeNode<int> *solver(vector<int> &preorder, vector<int> &inorder, int size,
    int &preIndex, int start, int end,
    unordered_map<int, int> &mp) {
  if (preIndex >= size || start > end) {
    return NULL;
  }

  int element = preorder[preIndex++];
  int pos = mp[element];
  TreeNode<int> *root = new TreeNode<int>(element);
  root->left = solver(preorder, inorder, size, preIndex, start, pos - 1, mp);
  root->right = solver(preorder, inorder, size, preIndex, pos + 1, end, mp);
  return root;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder) {
  int size = preorder.size();
  int preIndex = 0;
  int start = 0;
  int end = size - 1;
  unordered_map<int, int> mp;
  for (int i = 0; i < size; i++) {
    mp[inorder[i]] = i;
  }
  TreeNode<int> *root = solver(preorder, inorder, size, preIndex, start, end, mp);
  return root;
}