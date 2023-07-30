/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
#include <stack>
#include <set>
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& post, vector<int>& in) 
{
     int n = in.size();
    stack<TreeNode<int>*> st;
    set<TreeNode<int>*> s;
    int postIndex = n - 1;
    TreeNode<int>* root = NULL;
 
    for (int p = n - 1, i = n - 1; p >= 0;) {
        TreeNode<int>* node = NULL;
        do {
            node = new TreeNode<int>(post[p]);
            if (root == NULL) {
                root = node;
            }
            if (st.size() > 0) {
                if (s.find(st.top()) != s.end()) {
                    s.erase(st.top());
                    st.top()->left = node;
                    st.pop();
                }
                else {
                    st.top()->right = node;
                }
            }
            st.push(node);
        } while (post[p--] != in[i] && p >= 0);
 
        node = NULL;
        while (st.size() > 0 && i >= 0
               && st.top()->data == in[i]) {
            node = st.top();
            st.pop();
            i--;
        }
        if (node != NULL) {
            s.insert(node);
            st.push(node);
        }
    }
    return root;
}
