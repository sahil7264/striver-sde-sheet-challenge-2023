/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

bool solve(BinaryTreeNode<int>* root1,BinaryTreeNode<int>*root2){
    if(root1==NULL && root2==NULL) return true;
    if(root1==NULL) return false;
    if(root2==NULL) return false;
    if(root1->data!=root2->data) return false;
    return solve(root1->left,root2->right);
}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    return solve(root,root);
}