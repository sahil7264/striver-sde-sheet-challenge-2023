int longestSubSeg(vector<int> &arr , int n, int k){
    // 1 1 1 1 0 0 0 1 1 1 1 1 0 0 0 1 1 0 0 1 1 1 1  k=2 
   int i = 0, j = 0, countZeros = 0, ans = 0;
        
        while(j < n){
            if(arr[j] == 0){
                countZeros++;
            }
            while(countZeros > k){
                
                if(arr[i] == 0){
                    
                    countZeros--;      
                }
                
                i++;
            }
            
            ans=max(ans, j-i + 1);
            
            j++;
            
        }
        return ans;
}