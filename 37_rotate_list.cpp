/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */
int length(Node* head){
     Node* tmp = head;
     int cnt=0;
     while(tmp!=NULL){
          cnt++;
          tmp=tmp->next;
     }
     return cnt;
}
Node *rotate(Node *head, int k) {
     // Write your code here.
     int n  = length(head);
     k%=n;
     Node* tmp=head;
     if(k==0) return head;

     int x = 0;
     Node* prev=NULL;
     Node* curr=tmp;
     while(x < n-k){
        prev=curr;
        curr=curr->next;
        x++;
     }
     Node* ans = curr;
     while(curr->next!=NULL){
          curr=curr->next;
     }
     prev->next=NULL;
     curr->next=tmp;
     return ans;
}