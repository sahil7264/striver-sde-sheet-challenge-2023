#include <bits/stdc++.h>

string reverseString(string &s)
{
 vector<string>v;
    string rf="";
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
        if(!rf.empty()) v.push_back(rf);
        rf="";
        }
        else{
            rf+=s[i];
        }
    }
    if(!rf.empty())v.push_back(rf);
    string ans="";
    for(int i=v.size()-1;i>=0;i--){
    ans+=v[i];
    ans+=" ";
    }
    ans.pop_back();
    return ans;
}
