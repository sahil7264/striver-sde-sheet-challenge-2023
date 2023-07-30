#include <bits/stdc++.h> 
int maximumProduct(vector<int> &nums, int n)
{
	// Write your code here
    //kadanes algo
	 int prod1 = nums[0],prod2 = nums[0],result = nums[0];
    for(int i=1;i<n;i++) {
        int temp = max({nums[i],prod1*nums[i],prod2*nums[i]});
        prod2 = min({nums[i],prod1*nums[i],prod2*nums[i]});
        prod1 = temp;
        
        result = max(result,prod1);
    }
    
    return result;
}
