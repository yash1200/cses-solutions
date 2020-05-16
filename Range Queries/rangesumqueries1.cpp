#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	int n,q,a,b;
	cin>>n>>q;
	vector<ll> ar(n),v(n+1,0);
	for(int i=0;i<n;i++)
		cin>>ar[i];
	for(int i=0;i<n;i++)
		v[i+1]=v[i]+ar[i];
	while(q--){
		cin>>a>>b;
		cout<<v[b]-v[a-1]<<endl;
	}
	return 0;
}