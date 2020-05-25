#include<bits/stdc++.h>
using namespace std;
int main(){
	string a;
	cin>>a;
	long long n=a.length(),t=1,p=0,s=0,x=5,m=1000000009;
	for(int i=0;i<n-1;i++){
		p=(p*x+a[i])%m;
		s=(s+a[n-i-1]*t)%m;
		if(p==s)
			cout<<i+1<<" ";
		t=(t*x)%m;
	}
	cout<<endl;
	return 0;
}