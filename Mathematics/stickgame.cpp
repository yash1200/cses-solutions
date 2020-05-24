#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin>>n>>k;
	vector<int> v(k),dp(n+1,0);
	for(int i=0;i<k;i++)
		cin>>v[i],dp[v[i]]=1;
	sort(v.begin(),v.end());
	for(int i=1;i<=n;i++){
		if(dp[i]==1)
			continue;
		bool flag=false;
		for(int j=0;j<k;j++){
			if(i>v[j]&&dp[i-v[j]]==0)
				flag=true;
		}
		if(flag)
			dp[i]=1;
		else
			dp[i]=0;
	}
	for(int x=1;x<=n;x++)
		if(dp[x]==0)
			cout<<'L';
		else
			cout<<'W';
	cout<<endl;
	return 0;
}