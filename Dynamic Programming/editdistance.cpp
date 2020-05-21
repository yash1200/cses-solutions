#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a,b;
	cin>>a>>b;
	int la=a.length(),lb=b.length();
	int dp[la+1][lb+1];
	for(int i=0;i<=la;i++)
		for(int j=0;j<=lb;j++)
			if(i==0)
				dp[i][j]=j;
			else if(j==0)
				dp[i][j]=i;
			else if(a[i-1]==b[j-1])
				dp[i][j]=dp[i-1][j-1];
			else
				dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
	cout<<dp[la][lb]<<endl;
	return 0;
}