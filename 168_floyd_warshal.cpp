int INF = 1e9;
int floydWarshall(int V, int m, int src, int dest, vector<vector<int>> &edges) {
    if(src==dest) return 0;
    vector<vector<int>>dist(V,vector<int>(V,INF));
    for(int i=0;i<m;i++){
        dist[edges[i][0]-1][edges[i][1]-1] = edges[i][2];
    }
    // for (int i = 0; i < V; i++) {
    //     for (int j = 0; j < V; j++) {
    //         if (dist[i][j] == INF)
    //             cout << "INF"
    //                  << " ";
    //         else
    //             cout << dist[i][j] << "   ";
    //     }
    //     cout << endl;
    // }
    int i, j, k;
    for (k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++) {
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j < V; j++) {
                // If vertex k is on the shortest path from
                // i to j, then update the value of
                // dist[i][j]
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != INF
                        && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    //  for (int i = 0; i < V; i++) {
    //     for (int j = 0; j < V; j++) {
    //         if (dist[i][j] == INF)
    //             cout << "INF"
    //                  << " ";
    //         else
    //             cout << dist[i][j] << "   ";
    //     }
    //     cout << endl;
    // }
    return dist[src-1][dest-1];
}