#include <bits/stdc++.h> 
void debug(vector<int>v){
    for(int  i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
vector<int> merge(vector<int>&v1,vector<int>&v2){
    if(v1.size()==0) return v2;
    if(v2.size()==0) return v1;
    int  i=0;
    int  j=0;
    int n1 = v1.size();
    int n2 = v2.size();
    // cout<<minLen<<" "<<maxLen<<endl;
    vector<int>ans;
    while((i < n1) && (j < n2)){
        if(v1[i] < v2[j]){
            ans.push_back(v1[i]);
            i++;
        }
        else if(v1[i]>v2[j]){
            ans.push_back(v2[j]);
            j++;
        }
        else{
            ans.push_back(v1[i]);
            ans.push_back(v2[j]);
            i++;
            j++;
        }
    } 
    // cout<<i<<" "<<j<<endl;
    if(i!=n1){
      while (i < n1) {
        ans.push_back(v1[i]);
        i++;
      }
    }
    if(j!=n2){
      while (j < n2) {
        ans.push_back(v2[j]);
        j++;
      }
    }
    // debug(ans);
    return ans;
}

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    // vector<int>v;
    // for(int i=0;i<k;i++){
    //    v=merge(v,kArrays[i]);
    //   //  debug(v);
    // }
    // vector<int>ans;
    // for(int i=0;i<v.size();i++){
    //   ans.push_back(v[i]);
    // }
    // sort(ans.begin(),ans.end());
    // return ans;


    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<k;i++){
      for(int j=0;j<kArrays[i].size();j++){
        pq.push(kArrays[i][j]);
      }
    }

    vector<int>ans;
    while(!pq.empty()){
      ans.push_back(pq.top());
      pq.pop();
    }
    return ans;
}
