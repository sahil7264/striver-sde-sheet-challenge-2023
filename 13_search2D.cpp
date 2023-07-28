bool searchMatrix(vector<vector<int>>& mat, int target) {
          int low = 0;
       int n=mat.size();
       int m=mat[0].size();
       int high =m*n-1;
    //    O(log(m*n)) TC 
       int mid = low - (low-high)/2;
       while(low <= high)
       {
           int row = mid/m;
           int col = mid%m;
           if(mat[row][col] == target) return true;
           if(mat[row][col] < target) low = mid+1;
           else high=mid-1;
           mid = low - (low-high)/2;
       }
       return false; 
}