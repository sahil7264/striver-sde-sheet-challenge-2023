int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
     //Optimized aproach
   sort(at,at+n);
   sort(dt,dt+n);
   int cnt=1;
   int maxi=1;
   int ind = 0;
   for(int i=1;i<n;i++){
       if(at[i]>dt[ind]){
         cnt--;
         i--;
         ind++;
       }
       else{
           cnt++;
       }
       maxi=max(cnt,maxi);
   }
  return maxi;
}