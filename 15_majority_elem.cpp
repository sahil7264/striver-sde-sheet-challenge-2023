#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	 int curr=arr[0];
       int cnt=1;
       for(int i=0;i<n;i++){
           if(curr==arr[i]){
               cnt++;
           }
           else{
               cnt--;
               if(cnt<=0){
               curr=arr[i];
               cnt=1;
               }
           }
       }
	   cnt =0;
	   for(int i=0;i<n;i++){
		   if(curr==arr[i]) cnt++;
	   }
	   if(cnt > n/2) return curr;
       return -1;
}