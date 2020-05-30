#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pll;
#define max 100000000000000
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m,q,a,b,w;
	cin>>n>>m>>q;
	vector<vector<ll>> d(n,vector<ll>(n,max));
	for(int i=0;i<m;i++){
		cin>>a>>b>>w;
		d[a-1][b-1]=min(d[a-1][b-1],w);
		d[b-1][a-1]=min(d[a-1][b-1],w);
		d[a-1][a-1]=0;
		d[b-1][b-1]=0;
	}
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				if(d[i][k]==max||d[k][j]==max)
					continue;
				if(d[i][j]>d[i][k]+d[k][j])
					d[i][j]=d[i][k]+d[k][j];
			}
	while(q--){
		cin>>a>>b;
		if(d[a-1][b-1]==max)
			cout<<-1<<endl;
		else
			cout<<d[a-1][b-1]<<endl;
	}
	return 0;
}