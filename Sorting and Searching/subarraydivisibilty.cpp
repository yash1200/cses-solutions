#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ios_base::sync_with_stdio(0); 
    cin.tie(0);
	ll n,count=0,a;
	cin>>n;
	vector<ll> v(n+1);
	vector<vector<ll>> m(n);
	m[0].push_back(0);
	for(int j=0;j<n;j++){
		cin>>a;
		v[j+1]=(v[j]+a+n)%n;
		if(v[j+1]<0)
			v[j+1]+=n;
		m[v[j+1]].push_back(j+1);
	}
	for(int i=1;i<=n;i++){
		a=(v[i]-n)%n;
		if(a<0)
			a+=n;
		count+=lower_bound(m[a].begin(),m[a].end(),i)-m[a].begin();
	}
	cout<<count<<endl;
	return 0;
}