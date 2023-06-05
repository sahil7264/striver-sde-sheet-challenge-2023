#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define s string

/*------------------------------------------*/
/*    Author : Sahil Shile                  */
/*    Walchand College of Engineering, Sangli*/
/*--------------------------------------------*/
long long maxSubarraySum(int arr[], int n)
{ // kadanes algorhithm
    long long int maxi = 0;
    long long int x = 0;
    for (int i = 0; i < n; i++)
    {
        x += arr[i];
        maxi = max(maxi, x);
        if (x < 0)
            x = 0;
    }
    return maxi;
}
int main(){

return 0;
}