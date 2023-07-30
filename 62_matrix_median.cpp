int find_middle(vector<int>&arr,int x){
    int low = 0;
    int high = arr.size()-1;
    int mid  =(low+high)/2;
    while(low <= high){
       if(x >= arr[mid]){
           low  = mid+1;
       }
       else{
           high  =mid-1;
       }
        mid = (low+high)/2;
    }
    return low;
}
int getMedian(vector<vector<int>> &matrix)
{
  //Binary Search
   int low = 1;
   int high = 1e9;
   int n =matrix.size();
   int m =matrix[0].size();
   int want = (n*m)/2;
   int mid = (low+high)/2;
   while(low <= high){
       int sum =0;
       for (int i = 0; i < matrix.size(); i++) {
        sum+=  find_middle(matrix[i],mid);
       }

       if(sum <= want){
         low = mid+1;
       }
       else{
          high = mid-1;
       }
       mid = (low+high)/2;
   }
   return low;
}