#include <bits/stdc++.h>
    void helper(int i,string &s,unordered_set<string>&st,vector<string> &words_used,vector<vector<string>>&ans){
        if(i >= s.size()){
            ans.push_back(words_used);
            return;
        }
        string cur="";
        for(int j=i;j<s.size();++j){
            cur.push_back(s[j]);
            if(st.find(cur) != st.end()){
                words_used.push_back(cur);
                helper(j+1,s,st,words_used,ans);
                words_used.pop_back();
            }
        }
    }
    
    vector<string> wordBreak(string &s, vector<string>& dict) {
        int n=s.size();
        vector<vector<string>>ans;
        unordered_set<string>st;
        for(auto i:dict)
            st.insert(i);
        vector<string>words_used;
        helper(0,s,st,words_used,ans);
        for(int i=0;i<ans.size();++i){
            string cur;
            for(int j=0;j<ans[i].size();++j){
                cur += ans[i][j];
                cur += " ";
            }
            cur.pop_back();
            words_used.push_back(cur);
        }
        return words_used;
    }