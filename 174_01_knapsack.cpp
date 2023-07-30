#include <bits/stdc++.h>
int dp[1000][1001];
int solve(int w,int n,vector<int>&weights,vector<int>&vals,int i){
	if(i==n) return 0;
	int take = 0;
	if(dp[i][w]!= -1) return dp[i][w];
	if(weights[i] <= w) take = vals[i] + solve(w-weights[i],n,weights,vals,i+1);
	int ntake = solve(w,n,weights,vals,i+1);
	return dp[i][w] = max(take,ntake); 
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	memset(dp,-1,sizeof(dp));
	return solve(w,n,weights,values,0);
}