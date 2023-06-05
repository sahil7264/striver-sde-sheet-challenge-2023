#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define s string

/*------------------------------------------*/
/*    Author : Sahil Shile                  */
/*    Walchand College of Engineering, Sangli*/
/*--------------------------------------------*/
void sort012(int *arr, int n)
{
    //   Write your code here
    // Dutch national algorhithm
    int low = 0;
    int mid = 0;
    ;
    int high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
int main(){

return 0;
}