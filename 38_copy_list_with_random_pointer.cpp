#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    LinkedListNode<int>* ans = NULL;
    LinkedListNode<int>* ansHead = NULL;
    LinkedListNode<int>* tmp = head;

    while(tmp!=NULL){
      if (ans == NULL) {
        ans = new LinkedListNode<int>(tmp->data);
        ansHead = ans;
      }
      else{
        ans -> next = new LinkedListNode<int>(tmp->data);
        ans = ans -> next;
      }
        tmp=tmp->next;
    }
    tmp=head;
    ans=ansHead;
    while(tmp!=NULL){
        ans->random=tmp->random;
        ans=ans->next;
        tmp=tmp->next;
    }
    return ansHead;
}
