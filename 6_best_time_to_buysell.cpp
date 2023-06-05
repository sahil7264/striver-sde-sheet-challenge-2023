#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define s string

/*------------------------------------------*/
/*    Author : Sahil Shile                  */
/*    Walchand College of Engineering, Sangli*/
/*--------------------------------------------*/
int maximumProfit(vector<int> &prices)
{
    // Write your code here.
    int n = prices.size();
    int temp = 0;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (temp >= prices[i])
            ans = max(ans, temp - prices[i]);
        temp = max(temp, prices[i]);
    }
    return ans;
}
int main(){

return 0;
}