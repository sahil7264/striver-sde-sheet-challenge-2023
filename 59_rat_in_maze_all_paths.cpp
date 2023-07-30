#include <bits/stdc++.h> 
vector<int> convert(vector<vector<int>>&vis,int n){
  vector<int>v;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      // cout<<vis[i][j]<<" ";
      v.push_back(vis[i][j]);
    }
    // cout<<endl;
  }
  return v;
}
void solve(vector<vector<int>>&ans,vector<vector<int>>&maze,vector<vector<int>>&vis,int i,int j
,int n){
  if(i== n-1 && j== n-1){
    ans.push_back(convert(vis,n));
    return;
  }
  int x[4]={1,0,-1,0};
  int y[4]={0,1,0,-1};
  for(int p=0;p<4 ;p++){
    int nx = x[p] + i;
    int ny = y[p] + j;
    if(nx>=0 && ny>=0 && nx<n && ny<n){
      if(vis[nx][ny]== 0 && maze[nx][ny]==1){
        vis[nx][ny]=1;
        solve(ans,maze,vis,nx,ny,n);
        vis[nx][ny]=0;
      }
    }
  }
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  vector<vector<int>>ans;
  if(maze[0][0]==0) return ans;
  vector<vector<int>>vis(n,vector<int>(n,0));
  vis[0][0]=1;
  solve(ans,maze,vis,0,0,n);
  return ans;
}