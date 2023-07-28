#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{      Node<int>* l1=first;
       Node<int>* l2=second;
       if(l1 == NULL) return l2; 
        if(l2 == NULL) return l1;
        if(l1->data > l2->data) swap(l1,l2);
        Node<int>* res = l1;
        //1 2 3 
        // 4 5 6
        //We are trying to keep l1 head value < l2 head value
        while(l1 != NULL && l2 != NULL) {
 
            Node<int>* temp = NULL;
            while(l1 != NULL && l1->data <= l2->data) {//tarversing l1
                temp = l1;
                l1 = l1->next;
            }
            temp->next = l2;//pointing to head of l2
            swap(l1,l2);// keep l1 < l2 
        }
        return res;
}
