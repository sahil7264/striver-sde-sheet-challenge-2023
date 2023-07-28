bool comp(pair<int,int>a,pair<int,int>b){
    return a.first < b.first;
}
#include <bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
       int n =start.size();
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
        v.push_back({finish[i],start[i]});
    }
    sort(v.begin(),v.end());
    int cnt = 1;
    int ref = v[0].first;
    for(int i=1;i<n;i++){
        if(ref <= v[i].second){
            ref= v[i].first;
            cnt++;
        }
    }
    return cnt;
}