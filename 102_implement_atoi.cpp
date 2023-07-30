#include <bits/stdc++.h> 
int atoi(string str) {
    // Write your code here.
    if(str.size()==0) return 0;
    bool neg = false;
    int cnt = 0;
    long long int n= 0;
    for(int i=str.size()-1;i>=0;i--){
       if(str[i]=='-') neg =true;
       if(str[i]>='0' && str[i]<='9'){
           n+=((str[i]-'0')*pow(10,cnt));
           cnt++;
       }
    }
    return neg ? -n : n;
}