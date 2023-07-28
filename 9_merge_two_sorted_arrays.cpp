#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
	int start=0;
     int end=0;
     vector<int>v;
     while(start<m && end <n){
         if(arr1[start]<arr2[end]){
             v.push_back(arr1[start]);
             start++;
         }
         else if(arr1[start]>arr2[end]){
             v.push_back(arr2[end]);
             end++;
         }
         else{
             v.push_back(arr1[start]);
             v.push_back(arr2[end]);
             start++;
             end++;
         }
     }
     for(int i=start;i<m;i++) v.push_back(arr1[i]);
     for(int i=end;i<n;i++) v.push_back(arr2[i]);
     return v;
}