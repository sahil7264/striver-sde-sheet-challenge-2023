#include <bits/stdc++.h> 
void sort_stack(stack<int>&st){
   if(st.empty()) return;
   int num = st.top();
   st.pop();
   sort_stack(st);
   vector<int>v;
   while(!st.empty()){
	   if(st.top() <= num){
		   st.push(num);
		   for(int i = v.size()-1;i>=0;i--){
	         st.push(v[i]);
            }
		   return;
	   }
	   v.push_back(st.top());
	   st.pop();
   }
   st.push(num);
    for(int i = v.size()-1;i>=0;i--){
	   st.push(v[i]);
   }
   return;
}
void sortStack(stack<int> &stack)
{
	// Write your code here
	sort_stack(stack);
}