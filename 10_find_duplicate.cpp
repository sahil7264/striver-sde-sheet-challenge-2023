#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
   vector<int>nums=arr;
	  int slow = nums[0];
         int fast = nums[0];
         do {
           slow = nums[slow];
           fast = nums[nums[fast]];
         } while (slow != fast);
         fast = nums[0];
         while (slow != fast) {
           slow = nums[slow];
           fast = nums[fast];
         }
         return slow;
}
