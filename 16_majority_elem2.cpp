#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    vector<int>nums=arr;
      int n =nums.size();
    int elem1=INT_MIN;
    int elem2=INT_MIN;
    int cnt1=0;
    int cnt2=0;
    for(int i=0;i<nums.size();i++){
        if(cnt1==0 && elem2!=nums[i]){
            cnt1=1;
            elem1=nums[i];
        }
        else if(cnt2==0 && elem1!=nums[i]){
            cnt2=1;
            elem2=nums[i];
        }
        else if(elem1==nums[i]) cnt1++;
        else if(elem2==nums[i]) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }
    vector<int>v;
    cnt1=0;
    cnt2=0;
    for(int i=0;i<nums.size();i++){
       if(nums[i]==elem1) cnt1++;
       if(nums[i]==elem2) cnt2++;
    }
    if(cnt1 > n/3) v.push_back(elem1);
    if(cnt2 > n/3) v.push_back(elem2);
    return v;

}