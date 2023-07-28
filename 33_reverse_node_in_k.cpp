#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };
*****************************************************************/
int lengthOfLinkedList(Node* head) {
    int length = 0;
    while(head != NULL) {
        ++length;
        head = head->next;
    }
    return length;
}
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
    //EFF
    if(head == NULL||head->next == NULL) return head;
    int length = lengthOfLinkedList(head);
    Node* dummyHead = new Node(0);
    dummyHead->next = head;
    
    Node* pre = dummyHead;
    Node* cur;
    Node* nex;
    int i=0;
    while(length >= 0) {
        cur = pre->next;
        nex = cur->next;
        for(int i=1;i<b[i];i++) {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        length -= b[i];
        i++;
    }
    return dummyHead->next;

}