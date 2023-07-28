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

bool detectCycle(Node *head)
{  
   
   Node* slow=NULL;
   Node* fast=head;
   while(fast!=NULL){
       if(slow==fast) return true;
       if (slow == NULL) {
         slow = head;
       } else {
         slow = slow->next;
       }
       fast=fast->next;
       if(fast==NULL) return false;
       fast=fast->next;
   }
   return false;
}