int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
  	int cnt  =0;
	for(int i =0;i< n-1;i++){
          if (arr[i] != arr[i + 1]) {
            cnt++;
            arr.push_back(arr[i]);
          }
    }
	arr.push_back(arr[n-1]);
  // cout<<arr.size()<<endl;
	arr.erase(arr.begin(),arr.begin()+n);
	return cnt+1;
}