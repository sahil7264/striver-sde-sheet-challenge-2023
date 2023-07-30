class Stack {
	// Define the data members.
   vector<int>v;
   int n =0;
   public:
    Stack() {
        v.clear();;
        n =0;
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return n;
        // Implement the getSize() function.
    }

    bool isEmpty() {
        if(n==0) return true;
        return false;
    }

    void push(int element) {
        v.push_back(element);
        n++;
    }
    int pop() {
       if(n==0) return -1;
       v.pop_back();
       n--;
       return v[n];
    }

    int top() {
       if(n==0) return -1;
       return v[n-1];
    }
};