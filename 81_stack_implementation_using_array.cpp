#include <bits/stdc++.h> 
// Stack class.
class Stack {
    
public:
    int start;
    int *v;
    int Capacity;
    Stack(int capacity) {
        // Write your code here.
        v = new int[capacity];
        start= -1;
        Capacity=capacity;
    }

    void push(int num) {
        // Write your code here.
        if(start== Capacity-1) return;
        start++;
        v[start]=num;
    }

    int pop() 
    {
      if(start== -1) return -1;
      start--;
      return v[start+1];
    }
    
    int top() {
        if(start== -1) return -1;
        return v[start];
        // Write your code here.
    }
    
    int isEmpty() {
        if(start== -1) return 1;
        return 0;
        // Write your code here.
    }
    
    int isFull() {
        if(start== Capacity-1) return 1;
        return 0;
        // Write your code here.
    }
    
};