#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,x;
	cin>>n>>x;
	int h[n]={0},s[n]={0},dp[x+1]={0};
	for(int i=0;i<n;i++)
		cin>>h[i];
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int i=0;i<n;i++)
		for(int j=x;j>=1;j--)
			if(h[i]<=j)
			dp[j]=max(dp[j],dp[j-h[i]]+s[i]);
	cout<<dp[x]<<endl;
	return 0;
}