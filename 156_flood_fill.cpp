#include <bits/stdc++.h>

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{   
  
    vector<vector<int>>vis(image.size(),vector<int>(image[0].size(),0));
    queue<pair<int,int>>dq;
    dq.push({x,y});
    int currCol = image[x][y];
    image[x][y]=newColor;
    vis[x][y]=1;
    int dx[4]={0,1,-1,0};
    int dy[4]={1,0,0,-1};

    while(!dq.empty()){
        int a = dq.front().first;
        int b = dq.front().second;
        dq.pop();

        for(int i=0;i<4;i++){
            int na=a+dx[i];
            int nb=b+dy[i];
            if(na>=0 && nb>=0 && na<image.size() && nb<image[0].size()){
                if(vis[na][nb]== 0 && image[na][nb]==currCol){
                    image[na][nb]=newColor;
                    vis[na][nb]=1;
                    dq.push({na,nb});
                }
            }
        }
    }
    return image;
}