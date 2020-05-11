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
	string str;
	cin>>str;
	int n=str.length();
	ll ans=fact[n];
	map<char,int> m;
	for(char ch:str)
		m[ch]++;
	for(auto itr=m.begin();itr!=m.end();++itr){
		ans=(ans*power(fact[itr->second],mod-2,mod))%mod;
	}
	cout<<ans<<endl;
	return 0;
}