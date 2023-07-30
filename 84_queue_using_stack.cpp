#include <stack>
class Queue {
    // Define the data members(if any) here.
    stack<int>st;
    int last ;
    public:
    Queue() {
         last = -1;
        // Initialize your data structure here.
    }
    void enQueue(int val) {
        // Implement the enqueue() function.
        if(last== -1) last = val;
        st.push(val);
    }

    int deQueue() {
        if(last==-1) return -1;
        vector<int>v;
        while(st.size()!=1){
           v.push_back(st.top());
           st.pop();
        }
        int as  = st.top();
        st.pop();
        last = v.size()!=0 ? v[v.size()-1] : -1;
        for(int i=v.size()-1;i>=0;i--) st.push(v[i]);
        return as;
    }

    int peek() {
        return last;
        // Implement the peek() function here.
    }

    bool isEmpty() {
        if(last== -1) return true;
        return false;
        // Implement the isEmpty() function here.
    }
};