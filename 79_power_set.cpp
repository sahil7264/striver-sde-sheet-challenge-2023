#include <bits/stdc++.h> 
void solve(vector<vector<int>>&ans,vector<int>&tmp,int i,vector<int>&v,int n){
    if(i==n){
        ans.push_back(tmp);
        return ;
    }
    tmp.push_back(v[i]);
    solve(ans,tmp,i+1,v,n);
    tmp.pop_back();
    solve(ans,tmp,i+1,v,n);
}
vector<vector<int>> pwset(vector<int>v)
{
    vector<vector<int>>ans;
    vector<int>tmp;
    solve(ans,tmp,0,v,v.size());
    return ans;
}