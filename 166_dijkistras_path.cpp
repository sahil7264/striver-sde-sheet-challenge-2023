#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.

    vector<pair<int,int>>adj[vertices];
    for(int i=0;i<edges;i++){
      adj[vec[i][0]].push_back({vec[i][1], vec[i][2]});
      adj[vec[i][1]].push_back({vec[i][0], vec[i][2]});
    }
    priority_queue<pair<int,int>>pq;
    pq.push({0,0});
    vector<int>dist(vertices,INT_MAX);
    dist[0]=0;
    while(!pq.empty()){
        int node = pq.top().first;
        int dis = pq.top().second;
        pq.pop();
        for(auto it :adj[node]){
            int newNode  =it.first;
            int d =it.second;
            if(newNode!=node && (dis+d) < dist[newNode]){
                dist[newNode] = d+dis;
                pq.push({newNode, d + dis});
            }
        }
    }
    return dist;
}