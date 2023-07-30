#include <bits/stdc++.h> 
int dp[400][400];
int f(int i,int j,vector<int>&arr){
    if(i==j) return 0;
    int ans  = 1e9;
    if(dp[i][j]!= -1) return dp[i][j];
    for(int k=i;k<=j-1;k++){
        int steps = arr[i-1]*arr[k]*arr[j]+f(i,k,arr)+f(k+1,j,arr);
        ans = min(steps,ans);
    }
    return dp[i][j] = ans;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    memset(dp,-1,sizeof(dp));
    return f(1,N-1,arr);
}