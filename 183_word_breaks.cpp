#include <bits/stdc++.h> 
int dp[101];
bool solve(vector<string>&arr,int n,string &target,int j,set<string>&st){
    if(j==target.size()) return 1;
    string tp = "";
    if(dp[j]!= -1) return dp[j];
    for(int i=j;i<target.size();i++){
       tp+=target[i];
       if(st.find(tp)!=st.end()){
           if(solve(arr,n,target,i+1,st)) return dp[j] = 1;
       } 
    }
    return dp[j] = 0;
}
bool wordBreak(vector < string > & arr, int n, string & target) {
    set<string>st;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++) st.insert(arr[i]);
    return solve(arr,n,target,0,st);
}