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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int tot=(n*(n+1))/2;
	if(tot%2==1){
		cout<<0<<endl;
		return 0;
	}
	tot/=2;
	int dp[tot+1]={0};
	dp[0]=1;
	for(int i=0;i<=n;i++)
		for(int j=tot;j>=1;j--)
			if(j>=i)
				dp[j]=(dp[j]+dp[j-i])%mod;
	cout<<(dp[tot]*power(2,mod-2,mod))%mod<<endl;
	return 0;
}