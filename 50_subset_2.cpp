#include <bits/stdc++.h>


void solve(set<vector<int>>&v,int n,vector<int>&arr,int i,vector<int>&tmp){
    if(i==n){
        sort(tmp.begin(),tmp.end());
        v.insert(tmp);
        return;
    }
    tmp.push_back(arr[i]);
    solve(v,n,arr,i+1,tmp);
    tmp.pop_back();
    solve(v,n,arr,i+1,tmp);
} 
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    sort(arr.begin(),arr.end());
    set<vector<int>>v;
    vector<vector<int>>ans;
    vector<int>tmp;
    solve(v,n,arr,0,tmp);
    for(auto it :v){
        ans.push_back(it);
    }
    return ans;
}