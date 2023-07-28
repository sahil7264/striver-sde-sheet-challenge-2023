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

Node *firstNode(Node *head)
{   
     if(head==NULL) return NULL;
     if(head->next==NULL) return NULL;
     if(head->next==head) return head;
     
     Node *slow_p = head;
     Node *fast_p = head;
    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            break;
        }
    }
    if(fast_p==NULL || fast_p->next==NULL) return NULL;
    fast_p = head;
    while(fast_p!=slow_p){
        fast_p=fast_p->next;
        slow_p=slow_p->next;
    }
    return fast_p;
}