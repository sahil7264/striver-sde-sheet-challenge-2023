#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
   map<int,int>mpp;
   for(int i=0;i<k;i++) mpp[arr[i]]++;
   int j= k;
   int i =0;
   int n = arr.size();
      vector<int>v;
   int x = mpp.size();
    v.push_back(x);
   while(j<n){  
       mpp[arr[i]]--;
       mpp[arr[j]]++;
       if(mpp[arr[i]]==0) mpp.erase(mpp.find(arr[i]));
       int x = mpp.size();
       v.push_back(x);
       i++;
       j++;
   }
   return v;
}
