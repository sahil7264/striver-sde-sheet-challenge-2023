#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    int repeating = -1, missing = -1;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == i) cnt++;
        }

        if (cnt == 2) repeating = i;
        else if (cnt == 0) missing = i;

        if (repeating != -1 && missing != -1)
            break;
    }
    return {missing,repeating};
	
}
