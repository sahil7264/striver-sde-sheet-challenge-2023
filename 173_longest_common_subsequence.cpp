int dp[1000][1000];
int solve(string s1,string s2,int i,int j){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i] == s2[j])
        return dp[i][j] = 1 + solve(s1,s2,i-1,j-1);
    return dp[i][j] = 0 + max(solve(s1,s2,i,j-1),solve
       (s1,s2,i-1,j));
}
int lcs(string s, string t)
{
	//Write your code here
	memset(dp,-1,sizeof(dp));
	return solve(s,t,s.size()-1,t.size()-1);
}