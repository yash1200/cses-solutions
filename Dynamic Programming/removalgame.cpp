#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,sum=0;
	cin>>n;
	vector<int> v(n);
	vector<vector<ll>> dp(n,vector<ll>(n));
	for(int i=0;i<n;i++)
		cin>>v[i],sum+=v[i];
	for(int i=n-1;i>=0;i--)
		for(int j=i;j<n;j++)
			if(i==j)
				dp[i][j]=v[i];
			else
				dp[i][j]=max(v[i]-dp[i+1][j],v[j]-dp[i][j-1]);
	cout<<(sum+dp[0][n-1])/2<<endl;
	return 0;
}