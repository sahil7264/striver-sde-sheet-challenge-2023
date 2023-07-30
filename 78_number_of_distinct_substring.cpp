#include <bits/stdc++.h>
int distinctSubstring(string &word) {
    set<string>st;
    int n= word.size();
    for(int i=0;i<n;i++){
        string s = "";
        s+=word[i];
        st.insert(s);
        for(int j=i+1;j<n;j++){
           s+=word[j];
           st.insert(s);
        }
    }
    return st.size();
}
