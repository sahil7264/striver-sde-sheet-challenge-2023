#include <bits/stdc++.h> 
bool sortcol(const vector<int>& v1,const vector<int>& v2) { 
     return v1[1] < v2[1]; 
} 
int jobScheduling(vector<vector<int>> &jobs)
{   
    int n =jobs.size();
    bool ans[n+1]={false};
    int fin=0;
    ans[0]=true;
    sort(jobs.begin(),jobs.end(),sortcol);
    int i = n-1;
    while(i>=0){
        int time = jobs[i][0];
        int p = -1;
        for( p=time;p>=0;p--){
           if(!ans[p]){
               ans[p]=true;
               break;
           }
        }
        if(p>=0) fin+=jobs[i][1];
        i--;
    }
    return fin;
}
