#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	
	public:
		
	  stack<int> s;
    int minEle;
		minStack() 
		{ 
		}
		void push(int x)
		{
        if (s.empty()) {
            minEle = x;
            s.push(x);
            return;
        }
        else if (x < minEle) {
            s.push(2 * x - minEle);
            minEle = x;
        }
        else
            s.push(x);
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			   if (s.empty()) {
            return -1;
        }
        int t = s.top();
        s.pop();
         int x;
        if (t < minEle) {
           x=minEle;
            minEle = 2 * minEle - t;
        }
        else{
          x =t;
        }
        
        return x;    
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			 if (s.empty())  return -1;
 
        int t = s.top(); 
        return (t < minEle) ? minEle:t;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
		 if (s.empty()) return -1;
     return minEle;
		}
};