#include <bits/stdc++.h> 
int find(int i,int j,int m,int n, vector<vector<int>>&v){
    if(i== n-1 && j== m-1) return 1;
    if(i> n-1 || j> m-1) return 0;
    if(v[i][j]!= -1) return v[i][j];
    return v[i][j]=find(i+1,j,m,n,v)+find(i,j+1,m,n,v);
}
int uniquePaths(int m, int n) {
	// Write your code here.
	  vector<vector<int>>visited(n,vector<int>(m,-1));
       return find(0,0,m,n,visited);
}