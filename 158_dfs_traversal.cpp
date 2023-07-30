vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<int>vis(V,-1);
    vector<int>adj[V];
    for(auto it :edges){
      adj[it[0]].push_back(it[1]);
      adj[it[1]].push_back(it[0]);
    }
    vector<vector<int>>ans;
    for(int i=0;i<V;i++){
 
      if(vis[i]== -1){
          vector<int>v;
          vis[i]=1;
          stack<int>st;
          st.push(i);
          while(!st.empty()){
              int fr = st.top();
              v.push_back(fr);
              st.pop();
              for(auto it : adj[fr]){
                  if(vis[it]== -1){
                      vis[it]=1;
                      st.push(it);
                  }
              }
          }
        sort(v.begin(), v.end());
        ans.push_back(v);
      }
    }
    vector<vector<int>>fin;
    // fin.push_back({ans.size()});
    for(auto it :ans){
      fin.push_back(it);
    }
    return fin;
}