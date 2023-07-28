#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{  
   //LIKE 0 sum
   int xori=0;
   int cnt = 0;
   unordered_map<int,int>mpp;
   mpp[0]=1;
   for(int i=0;i<arr.size();i++){
       xori=xori^arr[i];
       cnt+=mpp[x^xori];
       mpp[xori]++;
   }
   return cnt;
}