#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pll;
#define max LONG_MAX
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m,a,b,w,i,id;
	cin>>n>>m;
	vector<vector<pll>> v(n);
	for(int i=0;i<m;i++){
		cin>>a>>b>>w;
		v[a-1].push_back({b-1,w});
	}
	priority_queue<pll,vector<pll>,greater<pll>> q;
	q.push({0,0});
	vector<ll> d(n,max);
	d[0]=0;
	while(!q.empty()){
		i=q.top().second;
		id=q.top().first;
		q.pop();
		if(id>d[i])
			continue;
		for(pll x:v[i]){
			a=x.first;
			b=x.second;
			if(d[i]+b<d[a]){
				d[a]=d[i]+b;
				q.push({d[a],a});
			}
		}
	}
	for(ll x:d)
		cout<<x<<" ";
	cout<<endl;
	return 0;
}