#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
ll power(ll x,ll y){
    if (y == 0) 
        return 1; 
    ll p = power(x, y/2) % mod; 
    p = (p * p) % mod;
    return (y%2 == 0)? p : (x * p) % mod;
}
ll fact(ll n){
	ll ans=1;
	for(int i=1;i<=n;i++)
		ans=(ans*i)%mod;
	return ans;
}
int main(){
	int n,m;
	cin>>n>>m;
	ll x=(fact(m)*fact(n-1))%mod;
	x=power(x,mod-2);
	cout<<(fact(n+m-1)*x)%mod<<endl;
	return 0;
}