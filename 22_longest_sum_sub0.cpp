#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
  unordered_map<int,int>mpp;
        int sum=0;
        int maxi=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==0){
                maxi=i+1;//no need to compare because , it already is an 
            }
            else{
               if(mpp.find(sum)==mpp.end()){
                   mpp[sum]=i;
               }
               else{
                   maxi=max(maxi,i-mpp[sum]);
               }
            }
        }
        return maxi;
}