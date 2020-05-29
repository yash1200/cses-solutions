#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<vector<int>> v;
vector<int> c,vis;
bool dfs(int i,int t){
	vis[i]=1;
	c[i]=t;
	for(int a:v[i])
		if(!vis[a]){
			if(!dfs(a,t^1))
				return false;
		}else if(c[i]==c[a])
			return false;
	return true;
}
int main(){
	bool flag=true;
	int n,m,a,b;
	cin>>n>>m;
	v.resize(n);
	c.resize(n);
	vis.resize(n);
	for(int i=0;i<m;i++){
		cin>>a>>b;
		v[a-1].push_back(b-1);
		v[b-1].push_back(a-1);
	}
	for(int i=0;i<n;i++)
		if(!vis[i])
			flag&=dfs(i,0);
	if(flag)
		for(int i:c)
			cout<<i+1<<" ";
	else
		cout<<"IMPOSSIBLE\n";
	return 0;
}