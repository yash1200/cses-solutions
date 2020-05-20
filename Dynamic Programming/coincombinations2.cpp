#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,x;
	cin>>n>>x;
	vector<int> v(n);
	int dp[x+1]={0};
	for(int i=0;i<n;i++)
		cin>>v[i];
	dp[0]=1;
	for(int j=0;j<n;j++)
		for(int i=1;i<=x;i++)
			if(i-v[j]>=0)
				dp[i]=(dp[i]+dp[i-v[j]])%mod;
	cout<<dp[x]<<endl;
	return 0;
}