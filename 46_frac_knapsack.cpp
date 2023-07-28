#include <bits/stdc++.h> 
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
   priority_queue<pair<double,int>>pq;
   for(int i=0;i<n;i++){
       pq.push({(double)items[i].second / (double)items[i].first,i});
   } 
   double ans  = 0;
   while(w>0 && !pq.empty()){
      int x = pq.top().second;
      // cout<<w<<endl;
      if(w >= items[x].first){
         w-=items[x].first;
         ans+=items[x].second;
      }
      else{
          int tp = items[x].second*w;
          ans+= (double)tp/(double)items[x].first;
                    w = 0;
      }
      pq.pop();
   }
   return ans;
}