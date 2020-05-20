#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,x,min1;
	cin>>n>>x;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	int dp[x+1]={0};
	for(int i=1;i<=x;i++){
		dp[i]=1e9;
		for(int j=0;j<n;j++)
			if(i-v[j]>=0)
				dp[i]=min(dp[i],dp[i-v[j]]+1);
	}
	dp[x]=max(dp[x],-1);
	if(dp[x]==1e9)
		cout<<-1<<endl;
	else
		cout<<dp[x]<<endl;
	return 0;
}