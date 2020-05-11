#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
map<ll,ll> m;
ll fib(ll n){
	if(m.count(n))
		return m[n];
	ll k=n/2;
	if(n%2==0)
		return m[n]=(fib(k)*fib(k)+fib(k-1)*fib(k-1))%mod;
	else
		return m[n]=(fib(k)*fib(k+1)+fib(k-1)*fib(k))%mod;
}
int main(){
	ll n;
	cin>>n;
	m[0]=m[1]=1;
	if(n==0){
		cout<<0<<endl;
		return 0;
	}
	cout<<fib(n-1)<<endl;
	return 0;
}