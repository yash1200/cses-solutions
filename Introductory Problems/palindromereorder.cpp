#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	string str;
	cin>>str;
	map<char,ll> m;
	for(char c:str)
		m[c]++;
	int count=0;
	for(auto itr=m.begin();itr!=m.end();++itr)
		if(itr->second%2==1)
			count++;
	if(count>1){
		cout<<"NO SOLUTION\n";
		return 0;
	}
	string str1="",str2="",str3="";
	for(auto itr=m.begin();itr!=m.end();++itr){
		if(itr->second%2==0){
			str1+=string(itr->second/2,itr->first);
			str2=string(itr->second/2,itr->first)+str2;
		}else
			str3=string(itr->second,itr->first);
	}
	cout<<str1+str3+str2<<endl;
	return 0;
}