void mark(vector<vector<int>>&v,int i,int j,int n){
    //marking row
    for(int p=0;p<n;p++){
       v[p][j]= -1;
       v[i][p]= -1;
    }
    int i1=i;
    int i2=i;
    for(int p=j;p<n;p++){
        if(i1 < n) v[i1][p]= -1;
        if(i2 >= 0) v[i2][p]= -1;
        i1++;
        i2--;
    }
    i1=i;
    i2=i;
    for(int p=j;p>=0;p--){
        if(i1 < n) v[i1][p]= -1;
        if(i2 >= 0) v[i2][p]= -1;
        i1++;
        i2--;
    }
    v[i][j]=1;
    return;
}
void copy(vector<vector<int>>&ans ,vector<vector<int>>&v){
    vector<int>tmp;
    for(auto it : v){
        for(auto p : it){
            if(p==1) tmp.push_back(p);
            else tmp.push_back(0);
        }
    }
    ans.push_back(tmp);
}
void debug(vector<vector<int>>v){
    for(auto it : v){
        for(auto p : it){
           cout<<p<<" ";
        }
        cout<<endl;
    }
}
void solve(vector<vector<int>>&ans ,vector<vector<int>>&v,int n,int j,int cnt){
    if(j==n){
        copy(ans,v);
        return;
    }
    for(int i=0;i<n;i++){
        if(v[i][j]==0){
            cnt++;
            vector<vector<int>>prev=v;
            mark(v,i,j,n);
            solve(ans,v,n,j+1,cnt);
            v=prev;
        }
    }
}
vector<vector<int>> solveNQueens(int n) {
    // Write your code here. 
    vector<vector<int>>v(n,vector<int>(n,0));
    vector<vector<int>>ans;
    solve(ans,v,n,0,0);
    // mark(v,0,0,4);
    // debug(v);
    
    return ans;
}