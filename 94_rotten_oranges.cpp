#include <queue>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    vector<vector<int>>vis(n,vector<int>(m,0));
    int x[4] = {0,1,0,-1};
    int y[4] = {1,0,-1,0};

    queue<pair<pair<int,int>,int>>dq;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                dq.push({{i,j},0});
            }
        }
    }
    int ans = 0;
    while(!dq.empty()){
        int ox = dq.front().first.first;
        int oy = dq.front().first.second;
        int l = dq.front().second;
        // cout<<ox<<" "<<oy<<" "<<l<<endl;
        ans = max(ans,l);
        dq.pop();
        for(int p = 0;p < 4;p++){
            int nx = x[p] + ox;
            int ny = y[p] + oy;

            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(vis[nx][ny]==0 && grid[nx][ny]==1){
                    // cout<<nx<<" "<<ny<<endl;
                    vis[nx][ny]=1;
                    grid[nx][ny]=2;
                    dq.push({{nx,ny},l+1});
                }
            }
        }
    }
    //cheak whether all rotten

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            // cout<<grid[i][j]<<" ";
            if(grid[i][j]==1) return -1;
        }
    }
    return ans;
}