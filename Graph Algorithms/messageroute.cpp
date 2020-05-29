#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	int n,m,a,b;
	cin>>n>>m;
	vector<vector<int>> v(n);
	vector<int> vis(n),ans;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		v[a-1].push_back(b-1);
		v[b-1].push_back(a-1);
	}
	queue<int> q;
	q.push(0);
	vis[0]=-1;
	while(!q.empty()){
		a=q.front();
		q.pop();
		if(a==n-1)
			break;
		for(int b:v[a])
			if(!vis[b])
				vis[b]=a+1,q.push(b);
	}
	if(!vis[n-1]){
		cout<<"IMPOSSIBLE\n";
		return 0;
	}
	a=n;
	while(a>0){
		ans.push_back(a);
		a=vis[a-1];
	}
	cout<<ans.size()<<endl;
	for(int i=ans.size()-1;i>=0;i--)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}