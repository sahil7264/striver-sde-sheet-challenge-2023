/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

*****************************************************************/
Node* reverse(Node* &head){
    Node* prev=NULL;
    Node* curr=head;
    while(curr!=NULL){
        Node* forw=curr->next;
        curr->next=prev;
        prev=curr;
        curr=curr->next;
    }
    return prev;
}
int findIntersection(Node *firstHead, Node *secondHead)
{
    Node* head1=reverse(firstHead);
    Node* head2=reverse(secondHead);

    while(head->next!=head2->next){
        head1=head1->next;
        head2=head2->next;
    }
    return head1->data;
}