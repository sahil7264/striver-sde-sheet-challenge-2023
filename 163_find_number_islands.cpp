#include <queue>
void dfs(int i, int j, vector<vector<int>> &visited,
  int **&grid,int n,int m) {
  queue<pair<int, int>> q;
  q.push({i, j});
  int dx[3]={-1,0,1};
  int dy[3]={-1,0,1};
  visited[i][j] = 1;
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        int nx = dx[i]+x;
        int ny = dy[j]+y;
        if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1 && visited[nx][ny]==0){
          visited[nx][ny]=1;
          q.push({nx,ny});
        }
      }
    }
  }
}
int getTotalIslands(int **grid, int n, int m) {
  int cnt = 0;
  vector<vector<int>> visited(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 1 && visited[i][j]==0) {
        // cout<<i<<" "<<j<<endl; 
        dfs(i, j, visited, grid,n,m);
        cnt++;
      }
    }
  }
  return cnt;
}
#include <queue>
void dfs(int i, int j, vector<vector<int>> &visited,
  int **&grid,int n,int m) {
  queue<pair<int, int>> q;
  q.push({i, j});
  int dx[3]={-1,0,1};
  int dy[3]={-1,0,1};
  visited[i][j] = 1;
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        int nx = dx[i]+x;
        int ny = dy[j]+y;
        if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1 && visited[nx][ny]==0){
          visited[nx][ny]=1;
          q.push({nx,ny});
        }
      }
    }
  }
}
int getTotalIslands(int **grid, int n, int m) {
  int cnt = 0;
  vector<vector<int>> visited(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 1 && visited[i][j]==0) {
        // cout<<i<<" "<<j<<endl; 
        dfs(i, j, visited, grid,n,m);
        cnt++;
      }
    }
  }
  return cnt;
}
