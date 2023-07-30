#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/


vector<int> pathInATree(TreeNode<int> *root, int x)
{
    queue<pair<TreeNode<int>*,vector<int>>>dq;
	vector<int>v;
    dq.push({root,v});
    while(!dq.empty()){
        TreeNode<int>*t = dq.front().first;
		vector<int>ans = dq.front().second;
        dq.pop();
        ans.push_back(t->data);
		if(t->data==x) return ans;
        if(t->left!=NULL) dq.push({t->left,ans});
        if(t->right!=NULL)
          dq.push({t->right, ans});
    }
}
