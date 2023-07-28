#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{   
    vector<int>v(26,-1);
    int cnt = 0;
    int l = 0;
    int r = 0;
    while(r<input.size()){
        if(v[input[r]-'a']!= -1) l=max(l,v[input[r]-'a']+1);
        cnt=max(r-l+1,cnt);
        v[input[r]-'a']=r;
        r++;
    }
    return cnt;
}