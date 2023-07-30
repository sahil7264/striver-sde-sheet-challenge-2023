#include <bits/stdc++.h> 

bool isPossible(vector<int>a, int n, int cows, int minDist) {
      int cntCows = 1;
      int lastPlacedCow = a[0];
      for (int i = 1; i < n; i++) {
        if (a[i] - lastPlacedCow >= minDist) {
          cntCows++;
          lastPlacedCow = a[i];
        }
      }
      if (cntCows >= cows) return true;
      return false;
}
int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
	sort(positions.begin(),positions.end());
	int low = 1, high =positions[n - 1] - positions[0];
    while (low <= high) {
        int mid = low - (low-high)/2;

        if (isPossible(positions, n, c, mid)) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
    }
	return high;
}