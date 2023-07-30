#include <bits/stdc++.h> 
class Queue {
private :
 queue<int>dq;
public:
    Queue() {
        // Implement the Constructor
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return dq.empty();
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        dq.push(data);
    }

    int dequeue() {
        // Implement the dequeue() function
        if(dq.empty()) return -1;
        int x = dq.front();
        dq.pop();
       return x ;
    }

    int front() {
        // Implement the front() function
        if(dq.empty()) return -1;
        return dq.front();
    }
};