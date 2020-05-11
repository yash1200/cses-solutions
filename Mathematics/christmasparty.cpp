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
int main(){
	ll fact[1000002]={1};
	for(int i=1;i<1000002;i++)
		fact[i]=(fact[i-1]*i)%mod;
	int n;
	cin>>n;
	ll ans=1;
	for(int i=1;i<=n;i++)
		if(i%2==0)
			ans=(ans+power(fact[i],mod-2))%mod;
		else
			ans=(ans-power(fact[i],mod-2)+mod)%mod;
	cout<<(ans*fact[n])%mod<<endl;
	return 0;
}