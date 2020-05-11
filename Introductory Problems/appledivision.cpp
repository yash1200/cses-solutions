#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n,m,sum,total;
vector<ll> a;
void cal(ll i,ll s){
	if(i==n){
		ll x=s,y=total-s;
		m=min(abs(x-y),m);
		return;
	}
	cal(i+1,s);
	cal(i+1,s+a[i]);
}
int main(){
	cin>>n;
	vector<ll> ar(n);
	for(int i=0;i<n;i++)
		cin>>ar[i],total+=ar[i];
	a=ar;
	m=total;
	cal(0,0);
	cout<<m<<endl;
	return 0;
}