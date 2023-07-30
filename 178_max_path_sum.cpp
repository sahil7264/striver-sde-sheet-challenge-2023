#include <bits/stdc++.h>
int dp[101][101];
int find_min(vector<vector<int>>&grid,int i,int j,int n,int m){
   
    if(i==n-1 && j==m-1) return grid[i][j];
    if(i>=n || j>=m) return 1e8;
    if(dp[i][j]!= -1) return dp[i][j];
    int btm = grid[i][j] + find_min(grid,i+1,j,n,m);
    int rgt = grid[i][j] + find_min(grid,i,j+1,n,m);
    // cout<<i<<" "<<j<<" "<<btm<<" "<<rgt<<endl;
    return dp[i][j] = min(btm,rgt);
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i][j]= -1;
        }
    }
    int x=find_min(grid,0,0,n,m);
    // for(int i=0;i<n;i++){
    //   for (int j = 0; j < m; j++) {
    //     cout << dp[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    return x;
}