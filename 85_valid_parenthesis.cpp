bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char>st;
    for(int i=0;i<expression.size();i++){
      //  cout<<st.size()<<" "<<expression[i]<<endl;
        if (expression[i] == '[' || expression[i] == '{' || 
        expression[i] == '(') {
          st.push(expression[i]);
        }
         else {
          if (expression[i] == '}') {
            bool ans = false;
            while (!st.empty()) {
                 if(st.top()=='{'){
                    st.pop();
                    ans = true;
                    break;
                }
                st.pop();
            }
            if(!ans) return false;
          }
          else if (expression[i] == ')') {
            bool ans = false;
            while (!st.empty()) {
                if(st.top()=='('){
                    st.pop();
                    ans = true;
                    break;
                }
                st.pop();
            }
            if(!ans) return false;
          }
          else{
            bool ans = false;
            while (!st.empty()) {
                 if(st.top()=='['){
                    st.pop();
                    ans = true;
                    break;
                }
                st.pop();
            }
            if(!ans) return false;
          }
        }
    }
        if(!st.empty()) return false;
        return true;
}