#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ios_base::sync_with_stdio(0); 
    cin.tie(0);
	ll n,x,count=0,a;
	cin>>n>>x;
	vector<ll> v(n+1),b;
	map<ll,vector<ll>> m;
	m[0].push_back(0);
	for(int j=0;j<n;j++){
		cin>>a;
		v[j+1]=v[j]+a;
		m[v[j+1]].push_back(j+1);
	}
	for(int i=1;i<=n;i++){
		vector<ll> &b=m[v[i]-x];
		count+=lower_bound(b.begin(),b.end(),i)-b.begin();
	}
	cout<<count<<endl;
	return 0;
}