#include <bits/stdc++.h> 
int dp[1000][1001];
bool solve(int n,vector<int>&arr,int target,int i){
    if(target==0) return true;
    if(target<0) return false;
    if(i==n) return false;
    if(dp[i][target]!= -1) return dp[i][target]==1?true:false;
    bool ans = solve(n,arr,target-arr[i],i+1) | solve(n,arr,target,i+1);
    dp[i][target] = ans?1:0;
    return ans;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    for(int i=0;i<n;i++){
        for(int j=0;j<=k;j++) dp[i][j]=-1;
    }
    return solve(n,arr,k,0);
}