#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<string> v;
vector<vector<int>> vis;
void dfs(int i,int j){
	if(vis[i][j]==1)
		return;
	vis[i][j]=1;
	if(i>0)
		dfs(i-1,j);
	if(i<v.size()-1)
		dfs(i+1,j);
	if(j>0)
		dfs(i,j-1);
	if(j<v[0].size()-1)
		dfs(i,j+1);
}
int main(){
	int n,m,count=0;
	cin>>n>>m;
	v.resize(n);
	vis=vector<vector<int>>(n,vector<int>(m,0));
	for(int i=0;i<n;i++){
		cin>>v[i];
		for(int j=0;j<m;j++)
			if(v[i][j]=='#')
				vis[i][j]=1;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(v[i][j]!='#')
				if(!vis[i][j]){
					dfs(i,j);
					count++;
				}
	cout<<count<<endl;
	return 0;
}