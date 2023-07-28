#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	vector<vector<int>>v;
	set<vector<int>>st;
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++){
		if(i>0 && arr[i]==arr[i-1]) continue;
		int need = K-arr[i];
	    int j = i+1;
		int k = n-1;
            while (j < k) {
				// cout<<i<<" "<<j<<" "<<k<<endl;/
              if(need > arr[j]+arr[k]) {
                j++;
			  }  
			  else if(need < arr[j]+arr[k]){
                k--;
			  }
			  else{
				st.insert({arr[i],arr[j],arr[k]});
                j++;
				k--;
			  }
            //   while (arr[j] == arr[j - 1] && j<k) j++;
            //   while (arr[k] == arr[k + 1] && j<k) k--;
            }
    }
	for(auto it : st){
		v.push_back(it);
	}
	return v;	
}