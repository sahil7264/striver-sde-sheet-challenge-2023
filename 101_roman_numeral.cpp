void store(map<char,int>&mpp){
    mpp['I']=1;
    mpp['V']=5;
    mpp['X']=10;
    mpp['L']=50;
    mpp['C']=100;
    mpp['D']=500;
    mpp['M']=1000;
}
int romanToInt(string s) {
    // Write your code here
      map<char,int>mpp;
        store(mpp);

        int i=s.size();
        int maxi=INT_MIN;
        int n=0;
        while(i--){
            if(maxi<=mpp[s[i]]){
                maxi=mpp[s[i]];
                n+=mpp[s[i]];
            }
            else{
               n-=mpp[s[i]];
            }
        }
        return n;
}