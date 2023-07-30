#include <bits/stdc++.h> 
string solve(string s){
	int cnt =0;
	s+='#';
	string str = "";
	for(int i=0;i< s.size()-1;i++){
		if(s[i]==s[i+1]) cnt++;
		else{
			str+=(cnt+'1');
			str+=s[i];
			cnt=0;
		}
	}
	return str;
}
string writeAsYouSpeak(int n) 
{
	// Write your code here.	
	vector<string>v(30);
	v[0]="1";
	for(int i=1;i<30;i++){
	   v[i] = solve(v[i-1]);
	}
	// for(int i=0;i<30;i++){
	// 	cout<<v[i]<<" ";
	// }
	return v[n-1];
}