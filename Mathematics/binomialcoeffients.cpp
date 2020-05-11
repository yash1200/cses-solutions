#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
ll power(ll x,ll y,ll m){
    if (y == 0)
        return 1;
    ll p = power(x, y/2, m) % m;
    p = (p * p) % m;
    return (y%2 == 0)? p : (x * p) % m;
}
int main(){
	ll fact[1000002]={1};
	for(int i=1;i<=1000001;i++)
		fact[i]=(fact[i-1]*i)%mod;
	int n;
	cin>>n;
	while(n--){
		int a,b;
		ll ans=1;
		cin>>a>>b;
		ll x=(power(fact[b],mod-2,mod)*power(fact[a-b],mod-2,mod))%mod;
		cout<<(fact[a]*x)%mod<<endl;
	}
	return 0;
}