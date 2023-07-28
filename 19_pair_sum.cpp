#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   unordered_map<int,int>mpp;
   vector<vector<int>>v;
   for(auto it : arr){
      if(mpp[s-it]){
         int cnt = mpp[s-it];
         while(cnt--){
           v.push_back({it, s - it});
         }
      }
      mpp[it]++;
   }
   for(int i=0;i<v.size();i++){
      if(v[i][0] > v[i][1]) swap(v[i][0],v[i][1]);
   }
   sort(v.begin(),v.end());
   return v;
}