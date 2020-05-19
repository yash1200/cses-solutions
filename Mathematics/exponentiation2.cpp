#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
ll power(ll x,ll y,ll p){
	if(x==0&&y==0)
		return 1;
	ll res=1;
	x=x%p;
	if(x==0) return 0;
	while(y>0){
		if(y&1)
			res=(res*x)%p;
		y=y>>1;  
		x=(x*x)%p;
	}
	return res;
}
int main(){
	ll n;
	cin>>n;
	while(n--){
		ll a,b,c;
		cin>>a>>b>>c;
		ll d=power(b,c,mod-1);
		cout<<power(a,d,mod)<<endl;
	}
	return 0;
}