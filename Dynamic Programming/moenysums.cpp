#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,count=0;
	cin>>n;
	int v[n];
	vector<bool> dp(n*1000+1);
	for(int i=0;i<n;i++)
		cin>>v[i];
	for(int x:v){
		for(int i=dp.size()-1;i>0;i--)
			if(dp[i])
				dp[i+x]=1;
		dp[x]=1;
	}
	for(int i=0;i<dp.size();i++)
		if(dp[i])
			count++;
	cout<<count<<endl;
	for(int i=0;i<dp.size();i++)
		if(dp[i])
			cout<<i<<" ";
	cout<<endl;
	return 0;
}