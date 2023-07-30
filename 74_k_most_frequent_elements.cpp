#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    priority_queue<pair<int,int>>pq;
    map<int,int>mpp;
    for(int i=0;i<n;i++) mpp[arr[i]]++;

    for(auto it : mpp){
        pq.push({it.second,it.first});
    }
    vector<int>v;
    while(k--){
        pair<int,int>p  = pq.top();
        v.push_back(p.second);
        pq.pop();
    }
    sort(v.begin(),v.end());
    return v;
}