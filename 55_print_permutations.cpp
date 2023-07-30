#include <bits/stdc++.h> 
void find(string &s,int i,vector<string>&ans){
    if(i==s.size()){
       ans.push_back(s);
       return;
    }
    for(int j= i;j<s.size();j++){
        swap(s[i],s[j]);
        find(s,i+1,ans);
        swap(s[i],s[j]);
    }
}
vector<string> findPermutations(string &s) {

   vector<string>ans;
   find(s,0,ans);
   sort(ans.begin(),ans.end());
   return ans;
}