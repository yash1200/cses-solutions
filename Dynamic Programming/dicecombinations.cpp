#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
ll getAns(int n){
	int x[6]={1,2,4,8,16,32};
	if(n<=6) return x[n-1];
	ll dp[n+1]={0};
	dp[1]=1,dp[2]=2,dp[3]=4,dp[4]=8,dp[5]=16,dp[6]=32;
	for(int i=7;i<=n;i++)
		dp[i]=(dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4]+dp[i-5]+dp[i-6])%mod;
	return dp[n];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	cout<<getAns(n)<<endl;
	return 0;
}