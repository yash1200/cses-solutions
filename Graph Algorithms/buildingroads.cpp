#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<vector<int>> v;
vector<int> vis,ans;
void dfs(int a){
	vis[a]=1;
	for(int i=0;i<v[a].size();i++)
		if(!vis[v[a][i]])
			dfs(v[a][i]);
}
int main(){
	int n,m,a,b;
	cin>>n>>m;
	v.resize(n);
	vis.resize(n);
	for(int i=0;i<m;i++){
		cin>>a>>b;
		v[a-1].push_back(b-1);
		v[b-1].push_back(a-1);
	}
	for(int i=0;i<n;i++)
		if(!vis[i])
			dfs(i),ans.push_back(i+1);
	cout<<ans.size()-1<<endl;
	for(int i=0;i<ans.size()-1;i++)
		cout<<ans[i]<<" "<<ans[i+1]<<endl;
	return 0;
}