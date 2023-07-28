#include <bits/stdc++.h> 
void make_subset(int i ,vector<int>num,int sum,int n,vector<int>&ans){
  if (i == n) {
    ans.push_back(sum);
    return;
  }
    make_subset(i+1,num,sum+num[i],n,ans);
    make_subset(i+1,num,sum,n,ans);
}
vector<int> subsetSum(vector<int> &num)
{
   vector<int>v;
   make_subset(0,num,0,num.size(),v);
   sort(v.begin(),v.end());
   return v;
}