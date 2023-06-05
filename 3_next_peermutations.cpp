#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define s string

/*------------------------------------------*/
/*    Author : Sahil Shile                  */
/*    Walchand College of Engineering, Sangli*/
/*--------------------------------------------*/

vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    vector<int> nums = permutation;
    int ind = -1;
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            ind = i;
            break;
        }
    }
    if (ind == -1)
    {
        reverse(nums.begin(), nums.end());
        return nums;
    }
    int smallInd = -1;
    int smallest = INT_MAX;
    for (int i = ind + 1; i < nums.size(); i++)
    {
        if (smallest >= nums[i] && nums[i] > nums[ind])
        {
            smallest = nums[i];
            smallInd = i;
        }
    }
    swap(nums[ind], nums[smallInd]);
    reverse(nums.begin() + ind + 1, nums.begin() + nums.size());
    return nums;
}
int main()
{

    return 0;
}