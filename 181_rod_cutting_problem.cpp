
//dp array , dp[i][partLength]={maxSum to cut partLegth when you are at index i}
int dp[101];
int solve(vector<int>&price,int currLen){
	int maxi = price[currLen-1];
	if(dp[currLen]!= -1) return dp[currLen];
	for(int i=0;i< currLen-1;i++){
       maxi = max(maxi,solve(price,currLen-i-1)+solve(price,i+1));
	}
	return dp[currLen]=maxi;
}
int cutRod(vector<int> &price, int n)
{
	for(int i=0;i<=n;i++) dp[i]= -1;
	return solve(price,n);
}
