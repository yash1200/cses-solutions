#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
pair<int,int> bfs(int a,int n){
	int dis[n],i,in,max=-1;
	memset(dis,-1,sizeof(dis));
	dis[a]=0;
	queue<int> q;
	q.push(a);
	while(!q.empty()){
		int b=q.front();
		q.pop();
		for(int i:v[b]){
			if(dis[i]==-1){
				q.push(i);
				dis[i]=dis[b]+1;
			}
		}
	}
	for(i=0;i<n;i++)
		if(dis[i]>max)
			max=dis[i],in=i;
	return {in,max};
}
int main(){
	int n,x,a;
	cin>>n;
	v.resize(n);
	for(int i=1;i<n;i++){
		cin>>x>>a;
		v[x-1].push_back(a-1);
		v[a-1].push_back(x-1);
	}
	pair<int,int> t1,t2;
	t1=bfs(0,n);
	t2=bfs(t1.first,n);
	cout<<t2.second<<endl;
	return 0;
}