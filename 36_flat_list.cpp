/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
Node* mergeNode(Node* head1,Node* head2){
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    Node* res = new Node(0);
    Node* tmp=res;
    while(head1!=NULL  && head2!=NULL){
        if(head1->data > head2->data){
          tmp->child = new Node(head2->data);
          tmp=tmp->child;
          head2=head2->child;
        }
        else if(head1->data < head2->data){
          tmp->child = new Node(head1->data);
          tmp=tmp->child;
          head1=head1->child;
        }
        else{
          tmp->child = new Node(head1->data);
          tmp=tmp->child;
          tmp->child= new Node(head2->data);
          tmp=tmp->child;
          head1=head1->child;
          head2=head2->child;
        }
    }
    while(head1!=NULL){
        tmp->child = new Node(head1->data);
        tmp=tmp->child;
        head1=head1->child;
    }
    while(head2!=NULL){
        tmp->child = new Node(head2->data);
        tmp=tmp->child;
        head2=head2->child;
    }
    return res->child;
}
Node* solve(Node* root){
    if(root==NULL) return root;
    return mergeNode(root,solve(root->next));
}
Node* flattenLinkedList(Node* head) 
{
    if(head=NULL) return NULL;
	  return solve(head);
}
