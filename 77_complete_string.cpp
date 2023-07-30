#include <bits/stdc++.h>

string f(map<string,int>&mpp,string ref=""){
   string ans = ref;
   for(char ch='a';ch<='z';ch++){
       //take this
       ref+=ch;
       if(mpp[ref]){
           string x = f(mpp,ref);
           if(x.size()>ans.size()) ans = x;
       }
       ref.pop_back();
   }
//    cout<<ans<<endl;
   return ans;
}
string completeString(int n, vector<string> &a){
    // Write your code here.
    map<string,int>mpp;
    for(int i=0;i<n;i++){
        mpp[a[i]]++;
    }
    // cout<<f(mpp)<<endl;
    return f(mpp)=="" ? "None" : f(mpp);
}