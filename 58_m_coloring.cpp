#include <bits/stdc++.h> 
string graphColoring(vector<vector<int>> &mat, int m) {
    int n =mat.size();
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1)
            {
                adj[i].push_back(j);
            }
        }
    }
    vector<int> vis(n, -1);
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {   
        if (vis[i] == -1)
        {  
            queue<pair<int, int>> dq;
            dq.push({i, 0});
            vis[i] = 0;
            int oter = 2;
            while (!dq.empty())
            {
                int v = dq.front().first;
                int col = dq.front().second;
                // cout << v << " " << col << endl;
                dq.pop();
                set<int> st;
                for (auto it : adj[v])
                {
                    if (vis[it] == -1)
                    {
                        if (col == 1)
                        {
                            vis[it] = 0;
                            dq.push({it, 0});
                        }
                        else
                        {
                            vis[it] = 1;
                            dq.push({it,1});
                        }
                    }
                    else
                    {
                        st.insert(vis[it]);
                    }
                }
                int f = st.size();
                if (f > 2)
                {
                    vis[v] = oter;
                    oter++;
                }
                maxi = max(f, maxi);
            }
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << vis[i] << " ";
    // }
    if (maxi >= 1)
        maxi++;
    // cout << maxi << endl;
    if (maxi <= m)
        return "YES";
     return "NO";
    return " ";    // return " ";
}