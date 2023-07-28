#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
      vector<vector<int>>v;
        sort(intervals.begin(),intervals.end());
        int mini= intervals[0][0];
        int maxi= intervals[0][1];
        for(int i=1;i< intervals.size();i++){
            if(intervals[i][0] <=maxi){
                mini=(intervals[i-1][0],mini);
                maxi=max(maxi,intervals[i][1]);
            }
            else{
                v.push_back({mini,maxi});
                mini=intervals[i][0];
                maxi=intervals[i][1];
            }
        }
         v.push_back({mini,maxi});
         return v;
        // TC : O(N)
}
