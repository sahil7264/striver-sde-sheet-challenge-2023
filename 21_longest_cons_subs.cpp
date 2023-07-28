#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    vector<int>nums=arr;
      if(nums.size()==1) return 1;
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int ans = 0;
        int cnt = 0;
        for(int i=0;i< nums.size()-1;i++){
            if(nums[i]==nums[i+1]-1) cnt++;
            else if(nums[i]==nums[i+1]) continue;
            else{
                ans = max(cnt+1,ans);
                cnt=0;
            }
        }
        ans = max(cnt+1,ans);
        return ans;
}