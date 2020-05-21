#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string s;
	cin>>n;
	vector<vector<ll>> v(n,vector<ll>(n,0)),dp(n,vector<ll>(n,0));
	for(int i=0;i<n;i++){
		cin>>s;
		for(int j=0;j<n;j++)
			if(s[j]=='*')
				v[i][j]=1;
	}
	dp[0][0]=1-v[0][0];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(v[i][j]==0){
				if(i>0)
					dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
				if(j>0)
					dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
			}
	cout<<dp[n-1][n-1]<<endl;
	return 0;
}