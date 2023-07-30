#include <queue>
int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
  // Write your code here.
  vector<int> topo;
  vector<int> in(n, 0);
  vector<int> adj[n];
  for (auto it : edges) {
    in[it.second-1]++;
    adj[it.first-1].push_back(it.second-1);
  }
  queue<int> dq;
  for (int i = 0; i < n; i++)
    if (in[i] == 0)
      dq.push(i);

  while (!dq.empty()) {
    int node = dq.front();
    topo.push_back(node);
    dq.pop();
    for (auto it : adj[node]) {
      if (it != node) {
        in[it]--;
        if(in[it]==0) dq.push(it);
       }
      }
    }
    // for(int i=0;i<)
    return topo.size()!=n;
  }