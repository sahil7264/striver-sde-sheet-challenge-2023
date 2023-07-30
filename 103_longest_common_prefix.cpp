string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string str = "";
    for(int i=0;i<n;i++){
        if(str=="" || str.size()>arr.size()) str = arr[i];
    }
    string ans = "";
    int x =str.size();
    for(int i=0;i<x;i++){
        string fp =str.substr(0,i+1);
        for(int j=0;j<n;j++){
            // cout<<fp<<" "<<arr[j].substr(0,i+1)<<endl;
            if(fp!=arr[j].substr(0,i+1)) return ans;
        }
        ans+=str[i];
    }
    return ans;
}


