#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	string str,s;
	cin>>str>>s;
	ll m=str.length(),n=s.length();
	if(m<n){
		cout<<0<<endl;
		return 0;
	}
	ll next[n+1]={0},count=0;
	for(int i=1;i<n;i++){
		int j=next[i+1];
		while(j>0&&s[j]!=s[i])
			j=next[j];
		if(j>0||s[j]==s[i])
			next[i+1]=j+1;
	}
	for(int i=0,j=0;i<m;i++)
		if(str[i]==s[j]){
			if(++j==n)
				count++;
		}else if(j>0){
			j=next[j];
			i--;
		}
	cout<<count<<endl;
	return 0;
}