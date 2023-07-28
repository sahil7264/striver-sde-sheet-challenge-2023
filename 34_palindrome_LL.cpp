#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
LinkedListNode<int>* reverse(LinkedListNode<int>* &head){
    LinkedListNode<int>* prev=NULL;
    LinkedListNode<int>* curr=head;
    while(curr!=NULL){
        LinkedListNode<int>* forw=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forw;
    }
    return prev;
}
bool isPalindrome(LinkedListNode<int> *head) {
    if(head==NULL) return true;
    if(head->next==NULL) return true;

    LinkedListNode<int>* head1=NULL;
    LinkedListNode<int>* head2=NULL;
    LinkedListNode<int>* tmp=head;

    while(tmp!=NULL){
      if (head1 == NULL) {
        head1 = new LinkedListNode<int>(tmp->data);
        head2=head1;
      } else {
        head1->next=new LinkedListNode<int>(tmp->data);
        head1=head1->next;
      }
        tmp=tmp->next;
    }
    head = reverse(head);

    while(head!=NULL){
        // cout<<head2->data <<" "<<head->data<<endl;
        if(head->data!=head2->data) return false;
        head=head->next;
        head2=head2->next;
    }
    return true;
}