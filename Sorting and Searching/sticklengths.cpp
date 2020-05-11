#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ll n,sum=0;
	cin>>n;
	vector<ll> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	sort(v.begin(),v.end());
	ll x=v[n/2];
	for(int i=0;i<n;i++)
		sum+=abs(v[i]-x);
	cout<<sum<<endl;
	return 0;
}