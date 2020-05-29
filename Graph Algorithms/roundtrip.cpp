#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<vector<int>> v;
vector<int> c,vis,ans;
bool dfs(int i,int t){
	vis[i]=1;
	ans.push_back(i);
	for(int a:v[i]){
		if(vis[a]&&a!=i&&t!=a){
			ans.push_back(a);
			return true;
		}
		if(!vis[a]&&dfs(a,i))
			return true;
	}
	ans.pop_back();
	return false;
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
		if(!vis[i]){
			ans.clear();
			if(dfs(i,-1)){
				int j=0;
				a=ans.back();
				while(ans[j]!=a)
					j++;
				cout<<ans.size()-j<<endl;
				for(;j<ans.size();j++)
					cout<<ans[j]+1<<" ";
				cout<<endl;
				return 0;
			}
		}
		cout<<"IMPOSSIBLE\n";
	return 0;
}