/*
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
*/

Node* removeKthNode(Node* head, int K)
{  
  //1 2 3 4 5 6 7 8 K=2 
  //travese fast from head to 3
  //travrese both till fast->next = NULL
  //slow = 7 fast =8

  Node * start = new Node();
  start -> next = head;
  Node* fast = start;
  Node* slow = start;      
  for(int i = 1; i <= K; ++i)
      fast = fast->next;
  while (fast->next != NULL) {
    fast = fast->next;
    slow = slow->next;
  }

  slow->next = slow->next->next;
  return start->next;
}