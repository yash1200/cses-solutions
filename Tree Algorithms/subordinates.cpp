#include<bits/stdc++.h>
using namespace std;
vector<int> c;
vector<vector<int>> v;
void dfs(int x){
	c[x]++;
	for(int a:v[x]){
		if(!c[a])
			dfs(a);
		c[x]+=c[a];
	}
}
int main(){
	int n,x;
	cin>>n;
	c.resize(n);
	v.resize(n);
	for(int i=1;i<n;i++){
		cin>>x;
		v[x-1].push_back(i);
	}
	for(int i=0;i<n;i++)
		if(!c[i])
			dfs(i);
	for(int a:c)
		cout<<a-1<<" ";
	cout<<endl;
	return 0;
}