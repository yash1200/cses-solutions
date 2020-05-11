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
	ll n,ans=0,m,k,x;
	cin>>n;
	ll sq=(ll)sqrt(n);
	for(int i=1;i<=sq;i++)
		ans=(ans+((n/i)*i)%mod)%mod;
	for(int i=1;i<=n/(sq+1);i++){
		m=n/i;
		k=n/(i+1);
		m=m%mod;
		k=k%mod;
		x=((m*(m+1))%mod-(k*(k+1))%mod+mod)%mod;
		x=(x*i)%mod;
		ans=(ans+(x*power(2,mod-2))%mod)%mod;
	}
	cout<<ans<<endl;
	return 0;
}