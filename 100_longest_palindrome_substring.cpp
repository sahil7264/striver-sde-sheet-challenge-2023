#include <vector>
string longestPalinSubstring(string str)
{
    int n = str.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++) dp[i][i]=1;
    pair<int,int>p={0,0};
    int diff = 0;
    for(int x=1;x<n;x++){
        int j = x;
        int i = 0;
        while(i<n && j<n){
            if(j-i==1){
                if(str[i]==str[j]){
                    dp[i][j]=1;
                    if(j-i+1 > diff){
                        // cout<<i<<" "<<j<<endl;
                        diff = j-i+1;
                        p = {i,j};
                    }
                }
            }
            else{
                if(str[i]==str[j]){
                    if(dp[i+1][j-1]==1){
                        dp[i][j]=1;
                        if(j-i+1 > diff){
                        // cout<<i<<" "<<j<<endl;
                        diff = j-i+1;
                        p = {i,j};
                       }
                    }
                }
            }
            j++;
            i++;
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    string ans="";
    for(int i =p.first;i<=p.second;i++) ans+=str[i];
    return ans;
}