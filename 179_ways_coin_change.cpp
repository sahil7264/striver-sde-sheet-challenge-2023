long long dp[10][2001];
long long  solve(int value,int *coins,int i,int n){
    if(value==0) return 1;
    if(value<0) return 0;
    //DP State : dp[i]-> ways to make coin of value i 
    if(dp[i][value]!= -1) return dp[i][value];
    long long ans = 0;
    for(int j=i;j<n;j++){
        ans+=solve(value-coins[j],coins,j,n);
    }
    return dp[i][value] = ans;
}
long countWaysToMakeChange(int *denominations, int n, int value,int i=0)
{
    for(int j=0;j<n;j++){
       for(int i=0;i<=value;i++){
           dp[j][i]=-1;
       }
    }
    return solve(value,denominations,0,n);
}