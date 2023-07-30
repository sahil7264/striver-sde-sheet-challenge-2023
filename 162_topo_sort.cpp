#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<int>adj[v];
    vector<int>indegree(v);
    for(int i=0;i<edges.size();i++){
        int num1 = edges[i][1];
        int num2 = edges[i][0];
        indegree[num1]++;
        adj[num2].push_back(num1);
    }
    queue<int>dq;
    for(int i=0;i<v;i++){
       if(indegree[i]==0){
        //    ans.push_back(node);
           dq.push(i);
       }
    }
    
    vector<int>ans;
    while(!dq.empty()){
        int node = dq.front();
        dq.pop();
        ans.push_back(node);
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                dq.push(it);
            }
        }
    }
    return ans;
}